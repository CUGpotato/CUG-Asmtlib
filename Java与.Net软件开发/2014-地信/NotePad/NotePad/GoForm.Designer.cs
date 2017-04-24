namespace NotePad
{
    partial class GoForm
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
            this.components = new System.ComponentModel.Container();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.buttonGo = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.textBoxRowNo = new System.Windows.Forms.TextBox();
            this.timerGetFocus = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // buttonCancel
            // 
            this.buttonCancel.Location = new System.Drawing.Point(164, 55);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(73, 23);
            this.buttonCancel.TabIndex = 0;
            this.buttonCancel.Text = "取消";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // buttonGo
            // 
            this.buttonGo.Location = new System.Drawing.Point(68, 55);
            this.buttonGo.Name = "buttonGo";
            this.buttonGo.Size = new System.Drawing.Size(73, 23);
            this.buttonGo.TabIndex = 1;
            this.buttonGo.Text = "转到";
            this.buttonGo.UseVisualStyleBackColor = true;
            this.buttonGo.Click += new System.EventHandler(this.buttonGo_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(59, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "行号(&L)：";
            // 
            // textBoxRowNo
            // 
            this.textBoxRowNo.Location = new System.Drawing.Point(14, 28);
            this.textBoxRowNo.Name = "textBoxRowNo";
            this.textBoxRowNo.Size = new System.Drawing.Size(223, 21);
            this.textBoxRowNo.TabIndex = 3;
            this.textBoxRowNo.Text = "1";
            // 
            // timerGetFocus
            // 
            this.timerGetFocus.Tick += new System.EventHandler(this.timerGetFocus_Tick);
            // 
            // GoForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(249, 90);
            this.Controls.Add(this.textBoxRowNo);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonGo);
            this.Controls.Add(this.buttonCancel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "GoForm";
            this.ShowIcon = false;
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "转到";
            this.Deactivate += new System.EventHandler(this.GoForm_Deactivate);
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.GoForm_FormClosing);
            this.Load += new System.EventHandler(this.GoForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonCancel;
        private System.Windows.Forms.Button buttonGo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBoxRowNo;
        private System.Windows.Forms.Timer timerGetFocus;
    }
}