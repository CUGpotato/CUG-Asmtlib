using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace NotePad
{
    public partial class ReplaceForm : Form
    {
        int index = 0;
        Boolean found = false;

        public ReplaceForm()
        {
            InitializeComponent();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonFindNext_Click(object sender, EventArgs e)
        {
            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            for (; index <= form1.richTextBox1.Text.Length - textBoxFindContent.Text.Length; index++)
            {
                form1.richTextBox1.Select(index, textBoxFindContent.Text.Length);
                if (index == form1.richTextBox1.Text.Length - textBoxFindContent.Text.Length)
                {
                    if (!found)
                    {
                        MessageBox.Show("未找到该字符串！");
                        break;
                    }
                    index = -1;
                }
                if (!checkBoxCase.Checked)
                {
                    if (form1.richTextBox1.SelectedText.ToLower().Equals(textBoxFindContent.Text.ToLower()))
                    {
                        form1.richTextBox1.Focus();
                        index++;
                        break;
                    }
                }
                if (form1.richTextBox1.SelectedText.Equals(textBoxFindContent.Text))
                {
                    form1.richTextBox1.Focus();
                    index++;
                    break;
                }
            }
        }

        private void buttonReplace_Click(object sender, EventArgs e)
        {
            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            for (; index <= form1.richTextBox1.Text.Length - textBoxFindContent.Text.Length; index++)
            {
                form1.richTextBox1.Select(index, textBoxFindContent.Text.Length);
                if (!checkBoxCase.Checked)
                {
                    if (form1.richTextBox1.SelectedText.ToLower().Equals(textBoxFindContent.Text.ToLower()))
                    {
                        form1.richTextBox1.SelectedText = textBoxReplaceText.Text;
                        form1.richTextBox1.Focus();
                        index++;
                        break;
                    }
                }
                if (form1.richTextBox1.SelectedText.Equals(textBoxFindContent.Text))
                {
                    form1.richTextBox1.SelectedText = textBoxReplaceText.Text;
                    form1.richTextBox1.Focus();
                    index++;
                    break;
                }
            }
        }

        private void textBoxFindContent_TextChanged(object sender, EventArgs e)
        {

            index = 0;
            found = false;
        }

        

        private void buttonReplaceAll_Click(object sender, EventArgs e)
        {

            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            form1.richTextBox1.Text = form1.richTextBox1.Text.Replace(textBoxFindContent.Text, textBoxReplaceText.Text);
        }


    }
}
