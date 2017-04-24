using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Printing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using NotePad;


namespace NotePad
{


    public partial class NotePad : Form
    {


        public bool isChange=false;   
        string filename="";
        SaveFileDialog saveNotePad = new SaveFileDialog();
        bool isSave = false;

        public NotePad()
        {
            InitializeComponent();
      //      saveNotePad= new NotePad();
            
           
        }
        private void NotePad_Load(object sender, EventArgs e)
        {
            isSave = true;
            isChange = false;
            this.Text = "无标题 - 记事本";            
            撤销ToolStripMenuItem.Enabled = false;
            复制ToolStripMenuItem.Enabled = false;
            剪切ToolStripMenuItem.Enabled = false;
            删除ToolStripMenuItem.Enabled = false;
            转到ToolStripMenuItem.Enabled = false;
            状态栏ToolStripMenuItem.Enabled = false;
            if (Clipboard.GetDataObject()==null)
            {
                粘贴ToolStripMenuItem.Enabled = false;
            }
            else
            {
                粘贴ToolStripMenuItem.Enabled = true;
            }
            if (richTextBox1.Text == "")
            {
                查找ToolStripMenuItem.Enabled = false;
                查找下一个ToolStripMenuItem.Enabled = false;

            }
        }
        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            isChange = true;
            isSave = false;
            if (richTextBox1.Text != "")
            {
                查找ToolStripMenuItem.Enabled = true;
                查找下一个ToolStripMenuItem.Enabled = true;
                转到ToolStripMenuItem.Enabled = true;
            }
        }


        private void 新建ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Text != "")
            {
                System.Console.WriteLine("isSave:" + isSave.ToString() + " isChanged:" + isChange.ToString());
                if (isSave == false)
                {
                    DialogResult dialog;
                    dialog = MessageBox.Show("内容已更改,是否保存?", "保存提示",
                        MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);

                    switch (dialog)
                    {
                        case DialogResult.Yes:
                            {
                                saveNotePad.FileName = "";
                                saveNotePad.Filter = "文本文档(*.txt)|*.txt";
                                saveNotePad.Title = "保存";
                                if (saveNotePad.ShowDialog() == DialogResult.OK)
                                {                                    
                                   
                                    //获取将要保存的文件名,并将其中的文件获取并保存  
                                    richTextBox1.SaveFile(saveNotePad.FileName, RichTextBoxStreamType.PlainText);
                                    //保存完毕,调用打开文件方法                                  
                                    filename = saveNotePad.FileName + ".txt";
                                    this.Text = "无标题 - 记事本";
                                    richTextBox1.Clear();
                                }
                                else if (saveNotePad.ShowDialog() == DialogResult.No)
                                {
                                    richTextBox1.Clear();
                                }                                 
                            }
                            break;
                        case DialogResult.No:
                            {
                                richTextBox1.Clear(); 
                            } 
                            break;
                    }
                }
                else
                {
                    richTextBox1.Clear(); 
                }
            }
            
        }


        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {

            OpenFileDialog openNotePad=new OpenFileDialog();            
            openNotePad.Filter = "文本文档(*.txt)|*.txt|所有文件|*.*";
            if (openNotePad.ShowDialog() == DialogResult.OK)
            {
                StreamReader sr = new StreamReader(openNotePad.FileName, Encoding.Default);
                richTextBox1.Text = sr.ReadToEnd();
                sr.Close();
            }
            filename = openNotePad.FileName;
            this.Text = Path.GetFileName(openNotePad.FileName) + " - 记事本";
            isSave = true;  
        }


       


        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveNotePad=new SaveFileDialog();
            if (filename == "")
            {
                isSave = false;               
                saveNotePad.Filter = "文本文档(*.txt)|*.txt";
                saveNotePad.Title = "保存";
                if (saveNotePad.ShowDialog() == DialogResult.OK)
                {
                    richTextBox1.SaveFile(saveNotePad.FileName, RichTextBoxStreamType.PlainText);
                    filename = saveNotePad.FileName;
                    this.Text = "无标题 - 记事本";
                    richTextBox1.Clear();
                }
                else
                {
                    richTextBox1.SaveFile(filename, RichTextBoxStreamType.PlainText);
                }
            }
            isSave = true;  
        }

        private void 另存为ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveNotePad= new SaveFileDialog();
            saveNotePad.FileName = "*.txt";
            saveNotePad.Filter = "文本文档(*.txt)|*.txt";
            saveNotePad.Title = "保存";
            if (saveNotePad.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.SaveFile(saveNotePad.FileName, RichTextBoxStreamType.PlainText);
                filename = saveNotePad.FileName;
                this.Text = "无标题 - 记事本";
                richTextBox1.Clear();
            }
            isSave = true;   
        }

        private void 页面设置ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PageSetupDialog pageSetupDialog = new PageSetupDialog();
            PrintDocument printDocument = new PrintDocument();
            pageSetupDialog.Document = printDocument;
            pageSetupDialog.ShowDialog();  
        }

        private void 打印ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PrintDialog printNotePad = new PrintDialog();
            PrintDocument printDocument = new PrintDocument();
            printNotePad.Document = printDocument;
            printNotePad.ShowDialog();
        }
        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.Text != "")
            {
                if (isSave == false)
                {
                    DialogResult result = MessageBox.Show("内容已更改,是否保存?", "保存提示", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Warning);
                    if (result == DialogResult.Yes)
                    {
                        保存ToolStripMenuItem_Click(sender, e);
                    }
                    else if (result == DialogResult.No)
                    {
                        this.Close();
                    }
                    else if (result == DialogResult.Cancel)
                    {
                    }
                }
            }
            else
                this.Close();
             
        }
        private void 撤销ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Cursor = Cursors.WaitCursor;
            richTextBox1.Undo();
            this.Cursor = Cursors.Default;  
        }
        private void 剪切ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Cursor = Cursors.WaitCursor;
            string strTemp = richTextBox1.SelectedText;
            if (strTemp.Equals(""))
                return;
            Clipboard.Clear();
            richTextBox1.Cut();
            this.Cursor = Cursors.Default; 
        }
        private void 复制ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Cursor = Cursors.WaitCursor;
            string strTemp = richTextBox1.SelectedText;   //获取RichTextBox中选中的文字   
            if (strTemp.Equals(""))     //Equals 方法确定两个对象是否相等  
                return;
            Clipboard.Clear();//清除原有剪切板中内容    
            Clipboard.SetText(strTemp);//将文字添加到剪切板中，还添加Object类型数据                  
            this.Cursor = Cursors.Default;
        }

        private void 粘贴ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Paste();
        }

        private void 删除ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.SelectedText = "";
        }

        private void 查找ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FindForm findForm = new FindForm();
            findForm.ShowDialog();


        }

        private void 查找下一个ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new FindForm().Show();
        }

        private void 替换ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new ReplaceForm().Show();
            
        }

        private void 转到ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            GoForm goForm = new GoForm();
            goForm.Show();
        }

        private void 全选ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Focus();//设置定位到当前活动的RichTextBox,这一句很重要,否则它不能正确执行   
            richTextBox1.SelectAll();  
        }

        private void 时间日期ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string Time;
            Time = (System.DateTime.Now).ToString();
            richTextBox1.Text = Time; 
        }


        private void 自动换行ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (自动换行ToolStripMenuItem.Checked)
            {
                自动换行ToolStripMenuItem.Checked = false;
                richTextBox1.WordWrap = false;
            }
            else
            {
                自动换行ToolStripMenuItem.Checked = true;
                richTextBox1.WordWrap = true;
            }  
        }

        private void 字体ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FontDialog fontDialog = new FontDialog();
            String font=richTextBox1.Font.Name;
            float temp=richTextBox1.Font.Size;
            if (fontDialog.ShowDialog() == DialogResult.OK)
            {
                font = fontDialog.Font.Name;
                temp = fontDialog.Font.Size;

            }
            richTextBox1.Font = new Font(font, temp);
        }

        private void 状态栏ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 查看帮助HToolStripMenuItem_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("winhlp32");
        }

        private void 关于记事本AToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new AboutForm().Show();
        }

        
      

        

       

     
        

        

        



        

        

    }
}
