using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using NotePad;

namespace NotePad
{
    public partial class FindForm : Form
    {

        int index = 0;
        int indexUp = 0;
        Boolean found = false;
        Boolean foundUp = false;
        


        public FindForm()
        {
            InitializeComponent();
            
        }



        private void buttonFindNext_Click(object sender, EventArgs e)
        {
            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            if (radioButtonDown.Checked)
            {
                for (; index <= form1.richTextBox1.Text.Length - textBoxContent.Text.Length; index++)
                {
                    form1.richTextBox1.Select(index, textBoxContent.Text.Length);
                    if (index == form1.richTextBox1.Text.Length - textBoxContent.Text.Length)
                    {
                        if (!found)
                        {
                            MessageBox.Show("找不到该字符串！");
                            break;
                        }
                        index = -1;
                    }
                    if (!checkBoxCase.Checked)
                    {
                        if (form1.richTextBox1.SelectedText.ToLower().Equals(textBoxContent.Text.ToLower()))
                        {
                            form1.richTextBox1.Focus();
                            found = true;
                            index++;
                            break;
                        }
                    }
                    if (form1.richTextBox1.SelectedText.Equals(textBoxContent.Text))
                    {
                        form1.richTextBox1.Focus();
                        index++;
                        break;
                    }
                }
            }
            else
            {
                for (; indexUp >= textBoxContent.Text.Length; indexUp--)
                {
                    form1.richTextBox1.Select(indexUp - textBoxContent.Text.Length, textBoxContent.Text.Length);
                    if (indexUp == textBoxContent.Text.Length)
                    {
                        if (!foundUp)
                        {
                            MessageBox.Show("找不到该字符串！");
                            break;
                        }
                        indexUp = form1.richTextBox1.Text.Length + 1;
                    }
                    if (!checkBoxCase.Checked)
                    {
                        if (form1.richTextBox1.SelectedText.ToLower().Equals(textBoxContent.Text.ToLower()))
                        {
                            form1.richTextBox1.Focus();
                            foundUp = true;
                            indexUp--;
                            break;
                        }
                    }
                    if (form1.richTextBox1.SelectedText.Equals(textBoxContent.Text))
                    {
                        form1.richTextBox1.Focus();
                        foundUp = true;
                        indexUp--;
                        break;
                    }
                }
            }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void textBoxContent_TextChanged(object sender, EventArgs e)
        {
            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            index = 0;
            indexUp = form1.richTextBox1.Text.Length;
//            System.Console.WriteLine(indexUp);
            found = false;
            foundUp = false;
        }
    }
}
