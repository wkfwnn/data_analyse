using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace BmpTobytesTool
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.StartPosition = FormStartPosition.CenterScreen;
        }

        public enum ColorType
        {
            SINGLE,
            DOUBLE,
            TRUECOLOR
        };

        public enum MatrixType
        {
            RG,
            RGGR
        };

        /// <summary>
        /// 总的像素bit位点阵，一定是8的倍数
        /// </summary>
        /// <param name="content">每页的字模数据</param>
        /// <param name="colorType"></param>
        /// <param name="matrixType"></param>
        /// <returns></returns>
        public List<byte> ToBytes(Bitmap content, ColorType colorType, MatrixType matrixType)
        {
            List<byte> result = new List<byte>();

            int height = content.Height;
            int width = content.Width;

            if (colorType == ColorType.SINGLE)         // 单色
            {
                for (int y = 0; y < height; y++)
                {
                    for (int x = 0; x < width; x += 8)
                    {
                        byte bits = 0x00;
                        for (int i = 0; i < 8; i++)
                        {
                            Color rgb = content.GetPixel(x + i, y);
                            int r = rgb.R;
                            int g = rgb.G;
                            bool flag = r >= 127 | g >= 127;
                            bits += (byte)((flag ? 0 : 1) << (7 - i));
                        }
                        result.Add(bits);
                    }
                }
            }
            else if (colorType == ColorType.DOUBLE)    // 双色
            {
                for (int y = 0; y < height; y++)
                {
                    for (int x = 0; x < width; x += 8)
                    {
                        byte Rbits = 0x00;
                        byte Gbits = 0x00;
                        for (int i = 0; i < 8; i++)
                        {
                            Color rgb = content.GetPixel(x + i, y);
                            int r = rgb.R;
                            int g = rgb.G;
                            Rbits += (byte)((r >= 127 ? 0 : 1) << (7 - i));
                            Gbits += (byte)((g >= 127 ? 0 : 1) << (7 - i));
                        }
                        if (matrixType == MatrixType.RG)//r+g
                        {
                            result.Add(Rbits);
                            result.Add(Gbits);
                        }
                        else//g+r,r+g的屏幕反过来就是g+r
                        {
                            result.Add(Gbits);
                            result.Add(Rbits);
                        }
                    }
                }
            }
            else   //全彩
            {
                for (int y = 0; y < height; y++)//遍历每列
                {
                    for (int x = 0; x < width; x++)//遍历每行
                    {
                        Color rgb = content.GetPixel(x, y);
                        int r = rgb.R;//红色像素值
                        int g = rgb.G;//绿色像素值
                        int b = rgb.B;//蓝色像素值

                        //按照协议，RGB565模式对像素值编码，红色取高5位，绿色取高6位，蓝色取高5位，低位舍弃,从而一个像素需要用两个字节表示
                        int data1 = ((r >> 3) << 11) & 0xF800;//红色
                        int data2 = ((g >> 2) << 5) & 0x07E0;//绿色
                        int data3 = (b >> 3) & 0x001F;//蓝色
                        byte[] dbytes = System.BitConverter.GetBytes(data1 + data2 + data3);
                        result.Add(dbytes[0]);
                        result.Add(dbytes[1]);
                    }
                }
            }

            return result;
        }

        private void btnOpenFile_Click(object sender, EventArgs e)
        {
            rchBmpBytes.Clear();

            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "(*.bmp)|*.bmp";
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                tbBmpFileName.Text = fileDialog.FileName;
            }

            Bitmap _Bitmap = (Bitmap)Image.FromFile(tbBmpFileName.Text);
            ColorType colorType;
            switch (comboBox1.SelectedIndex)
            {
                case 0:
                    colorType = ColorType.SINGLE;
                    break;
                case 1:
                    colorType = ColorType.DOUBLE;
                    break;
                case 2:
                    colorType = ColorType.TRUECOLOR;
                    break;
                default:
                    colorType = ColorType.SINGLE;
                    break;
            }
            List<byte> byteData = ToBytes(_Bitmap, colorType, MatrixType.RG);
            foreach (var b in byteData)
            {
                string h = Convert.ToString(b, 16).ToUpper();
                if ((byte)b < 16)
                {
                    h = "0" + h;
                }
                //if (h == "FF")
                //{
                //    h = "00";
                //}
                rchBmpBytes.Text += h + " ";
            }
        }

        private void rchBmpBytes_TextChanged(object sender, EventArgs e)
        {
            rchBmpBytes.SelectionStart = rchBmpBytes.Text.Length;
            rchBmpBytes.ScrollToCaret();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.comboBox1.SelectedIndex = 0;
        }
    }
}
