namespace NotePad
{
    partial class ReplaceForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonFindNext = new System.Windows.Forms.Button();
            this.buttonReplace = new System.Windows.Forms.Button();
            this.buttonReplaceAll = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxFindContent = new System.Windows.Forms.TextBox();
            this.textBoxReplaceText = new System.Windows.Forms.TextBox();
            this.checkBoxCase = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // buttonFindNext
            // 
            this.buttonFindNext.Location = new System.Drawing.Point(277, 12);
            this.buttonFindNext.Name = "buttonFindNext";
            this.buttonFindNext.Size = new System.Drawing.Size(92, 23);
            this.buttonFindNext.TabIndex = 0;
            this.buttonFindNext.Text = "查找下一个(&F)";
            this.buttonFindNext.UseVisualStyleBackColor = true;
            this.buttonFindNext.Click += new System.EventHandler(this.buttonFindNext_Click);
            // 
            // buttonReplace
            // 
            this.buttonReplace.Location = new System.Drawing.Point(277, 41);
            this.buttonReplace.Name = "buttonReplace";
            this.buttonReplace.Size = new System.Drawing.Size(92, 23);
            this.buttonReplace.TabIndex = 1;
            this.buttonReplace.Text = "替换(&R)";
            this.buttonReplace.UseVisualStyleBackColor = true;
            this.buttonReplace.Click += new System.EventHandler(this.buttonReplace_Click);
            // 
            // buttonReplaceAll
            // 
            this.buttonReplaceAll.Location = new System.Drawing.Point(277, 70);
            this.buttonReplaceAll.Name = "buttonReplaceAll";
            this.buttonReplaceAll.Size = new System.Drawing.Size(92, 23);
            this.buttonReplaceAll.TabIndex = 2;
            this.buttonReplaceAll.Text = "全部替换(&A)";
            this.buttonReplaceAll.UseVisualStyleBackColor = true;
            this.buttonReplaceAll.Click += new System.EventHandler(this.buttonReplaceAll_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(277, 99);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(92, 23);
            this.buttonCancel.TabIndex = 3;
            this.buttonCancel.Text = "取消";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 26);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(83, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "查找内容(&N)：";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 12);
            this.label2.TabIndex = 5;
            this.label2.Text = "替换为(&P)：";
            // 
            // textBoxFindContent
            // 
            this.textBoxFindContent.Location = new System.Drawing.Point(91, 20);
            this.textBoxFindContent.Name = "textBoxFindContent";
            this.textBoxFindContent.Size = new System.Drawing.Size(180, 21);
            this.textBoxFindContent.TabIndex = 6;
            this.textBoxFindContent.TextChanged += new System.EventHandler(this.textBoxFindContent_TextChanged);
            // 
            // textBoxReplaceText
            // 
            this.textBoxReplaceText.Location = new System.Drawing.Point(91, 55);
            this.textBoxReplaceText.Name = "textBoxReplaceText";
            this.textBoxReplaceText.Size = new System.Drawing.Size(180, 21);
            this.textBoxReplaceText.TabIndex = 7;

            // 
            // checkBoxCase
            // 
            this.checkBoxCase.AutoSize = true;
            this.checkBoxCase.Location = new System.Drawing.Point(14, 99);
            this.checkBoxCase.Name = "checkBoxCase";
            this.checkBoxCase.Size = new System.Drawing.Size(84, 16);
            this.checkBoxCase.TabIndex = 8;
            this.checkBoxCase.Text = "区分大小写";
            this.checkBoxCase.UseVisualStyleBackColor = true;
            // 
            // ReplaceForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(381, 146);
            this.Controls.Add(this.checkBoxCase);
            this.Controls.Add(this.textBoxReplaceText);
            this.Controls.Add(this.textBoxFindContent);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonReplaceAll);
            this.Controls.Add(this.buttonReplace);
            this.Controls.Add(this.buttonFindNext);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "ReplaceForm";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "替换";
            this.TopMost = true;
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonFindNext;
        private System.Windows.Forms.Button buttonReplace;
        private System.Windows.Forms.Button buttonReplaceAll;
        private System.Windows.Forms.Button buttonCancel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxFindContent;
        private System.Windows.Forms.TextBox textBoxReplaceText;
        private System.Windows.Forms.CheckBox checkBoxCase;
    }
}