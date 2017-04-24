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
    public partial class GoForm : Form
    {
        public GoForm()
        {
            InitializeComponent();
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonGo_Click(object sender, EventArgs e)
        {
            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            int selstart = 0;
            int rowNum = 0;
            int newRowNum = 0;
            int.TryParse(textBoxRowNo.Text.ToString(), out newRowNum);
            foreach (char ch in form1.richTextBox1.Text)
            {
                if (ch == '\n')
                {
                    selstart += form1.richTextBox1.Lines[rowNum].Length;
                    selstart++;
                    rowNum++;
                }
                if (rowNum + 1 == newRowNum)
                {
                    break;
                }
            }
            form1.richTextBox1.SelectionStart = selstart;
            this.Close();
        }

        private void GoForm_Load(object sender, EventArgs e)
        {
            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            form1.Enabled = false;
        }

        private void timerGetFocus_Tick(object sender, EventArgs e)
        {         
            this.Activate();
            this.Focus();
            timerGetFocus.Stop();        
        }

        private void GoForm_Deactivate(object sender, EventArgs e)
        {
            timerGetFocus.Start();
        }

        private void GoForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            NotePad form1 = (NotePad)Application.OpenForms["NotePad"];
            form1.Enabled = true;
        }
    }
}
