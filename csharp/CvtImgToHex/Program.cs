using System;
using System.IO;

namespace CvtImgToHex
{
    class Program
    {
		static void Main(string[] args)
		{
			if (args.Length > 0)
			{
				FileInfo file = new FileInfo(args[0]);
				if ((file.Attributes & FileAttributes.Directory) != FileAttributes.Directory)
				{
					if (file.Exists)
					{
						pic2Txt(file);
					}
				}
				else if ((file.Attributes & FileAttributes.Directory) == FileAttributes.Directory)
				{
					FileInfo[] tempList = file.Directory.GetFiles();
					if (tempList.Length > 0)
					{
						Console.WriteLine("该目录下文件个数：" + tempList.Length);
					}

					for (int i = 0; i < tempList.Length; i++)
					{
						if ((tempList[i].Attributes & FileAttributes.Directory) != FileAttributes.Directory)
						{
							Console.WriteLine("文件：" + tempList[i]);
						}
						if ((tempList[i].Attributes & FileAttributes.Directory) == FileAttributes.Directory)
						{
							Console.WriteLine("文件夹：" + tempList[i]);
						}
					}

					for (int i = 0; i < tempList.Length; i++)
					{
						if ((tempList[i].Attributes & FileAttributes.Directory) != FileAttributes.Directory)
						{
							pic2Txt(tempList[i]);
						}
					}

					if (tempList.Length > 0)
					{
						Console.WriteLine("全部图片转换完成\n");
					}
				}

			}
			else
			{
				Console.WriteLine("本程序可以把指定目录下的全部图片或者指定的一张图片转换成十六进制的C源文件表示");
				Console.WriteLine("目前支持png，bmp，jpeg，jpg");
			}

		}

		static private void pic2Txt(FileInfo file)
		{
			String ext = file.Name.Substring(file.Name.LastIndexOf(".") + 1);
			if (ext.Equals("png") || ext.Equals("bmp") || ext.Equals("jpeg") || ext.Equals("jpg"))
			{
				try
				{
					String fileNameData = file.Name.Substring(0, file.Name.LastIndexOf("."));

					if (fileNameData.Contains("_bkg"))
					{
						fileNameData = fileNameData.Replace("_bkg", "");
					}
					fileNameData = fileNameData + "_data";

					FileStream fis = new FileStream(file.Name, FileMode.Open, FileAccess.Read);

					int imgLength = (int)fis.Length;

					byte[] imgBuff = new byte[imgLength];

					fis.Read(imgBuff, 0, imgLength);

					byte2HexStr(".", file.Name, fileNameData, imgBuff);

					fis.Close();

				}
				catch (Exception e)
				{
					Console.WriteLine(e.StackTrace.ToString());
				}
			}
		}

		static private void byte2HexStr(String filePatch, String fileName, String fileNameData, byte[] b)
		{
			String hs = "\t";
			String stmp = "";
			StreamWriter fwriter = null;
			try
			{
				fwriter = new StreamWriter(filePatch + "/" + fileName + ".c");
				fwriter.Write("static const unsigned char " + fileNameData + "[] = {\n");
				for (int n = 0; n < b.Length; n++)
				{
					//Console.Out.WriteLine(n + "/" + b.Length + "\r");

					// 输出格式
					stmp = (b[n] & 0XFF).ToString("X4");

					if (stmp.Length == 1)
					{
						hs = hs + "0x0" + stmp;
					}
					else
					{
						hs = hs + "0x" + stmp;
					}

					if (n == b.Length - 1)
					{
						hs += "\n";
					}
					else if (n != 0 && (n + 1) % 4 == 0)
					{
						hs += ",\n\t";
					}
					else
					{
						hs += ", ";
					}
					fwriter.Write(hs);

					hs = "";
				}

				fwriter.Write("};");
			}
			catch (IOException ex)
			{
				Console.WriteLine(ex.StackTrace.ToString());
			}
			finally
			{
				try
				{
					fwriter.Flush();
					fwriter.Close();
					Console.Out.WriteLine(filePatch + "/" + fileName + ".c 保存完成\n");
				}
				catch (IOException ex)
				{
					Console.WriteLine(ex.StackTrace.ToString());
				}
			}
		}

		static private void writeBytesToImage(string path, byte[] imgBytes)
        {
			System.IO.File.WriteAllBytes(path, imgBytes);
		}
	}
}
