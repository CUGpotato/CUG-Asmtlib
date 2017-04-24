namespace WeatherQuery
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_Search = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cb_Province = new System.Windows.Forms.ComboBox();
            this.cb_City = new System.Windows.Forms.ComboBox();
            this.lab_Weather = new System.Windows.Forms.Label();
            this.lab_Nav = new System.Windows.Forms.Label();
            this.lab_Detail = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btn_Search
            // 
            this.btn_Search.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.btn_Search.Location = new System.Drawing.Point(453, 28);
            this.btn_Search.Name = "btn_Search";
            this.btn_Search.Size = new System.Drawing.Size(75, 23);
            this.btn_Search.TabIndex = 2;
            this.btn_Search.Text = "查询";
            this.btn_Search.UseVisualStyleBackColor = true;
            this.btn_Search.Click += new System.EventHandler(this.btn_Search_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.Location = new System.Drawing.Point(238, 33);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 14);
            this.label2.TabIndex = 3;
            this.label2.Text = "查找城市：";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(32, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 14);
            this.label1.TabIndex = 0;
            this.label1.Text = "查找省份：";
            // 
            // cb_Province
            // 
            this.cb_Province.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.cb_Province.FormattingEnabled = true;
            this.cb_Province.Location = new System.Drawing.Point(114, 29);
            this.cb_Province.Name = "cb_Province";
            this.cb_Province.Size = new System.Drawing.Size(83, 22);
            this.cb_Province.TabIndex = 5;
            this.cb_Province.Text = "选择省份";
            this.cb_Province.SelectedIndexChanged += new System.EventHandler(this.cb_Province_SelectedIndexChanged);
            // 
            // cb_City
            // 
            this.cb_City.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.cb_City.FormattingEnabled = true;
            this.cb_City.Location = new System.Drawing.Point(321, 28);
            this.cb_City.Name = "cb_City";
            this.cb_City.Size = new System.Drawing.Size(86, 22);
            this.cb_City.TabIndex = 6;
            this.cb_City.Text = "选择城市";
            // 
            // lab_Weather
            // 
            this.lab_Weather.AutoSize = true;
            this.lab_Weather.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lab_Weather.Location = new System.Drawing.Point(10, 18);
            this.lab_Weather.Name = "lab_Weather";
            this.lab_Weather.Size = new System.Drawing.Size(63, 14);
            this.lab_Weather.TabIndex = 8;
            this.lab_Weather.Text = "暂无数据";
            // 
            // lab_Nav
            // 
            this.lab_Nav.AutoSize = true;
            this.lab_Nav.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lab_Nav.Location = new System.Drawing.Point(45, 91);
            this.lab_Nav.Name = "lab_Nav";
            this.lab_Nav.Size = new System.Drawing.Size(70, 14);
            this.lab_Nav.TabIndex = 12;
            this.lab_Nav.Text = "         ";
            // 
            // lab_Detail
            // 
            this.lab_Detail.AutoSize = true;
            this.lab_Detail.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.lab_Detail.Location = new System.Drawing.Point(45, 107);
            this.lab_Detail.Name = "lab_Detail";
            this.lab_Detail.Size = new System.Drawing.Size(70, 14);
            this.lab_Detail.TabIndex = 13;
            this.lab_Detail.Text = "         ";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lab_Weather);
            this.groupBox1.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.groupBox1.Location = new System.Drawing.Point(35, 57);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(650, 150);
            this.groupBox1.TabIndex = 14;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "天气";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(724, 230);
            this.Controls.Add(this.lab_Detail);
            this.Controls.Add(this.lab_Nav);
            this.Controls.Add(this.cb_City);
            this.Controls.Add(this.cb_Province);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.btn_Search);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "天气查询";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_Search;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cb_Province;
        private System.Windows.Forms.ComboBox cb_City;
        private System.Windows.Forms.Label lab_Weather;
        private System.Windows.Forms.Label lab_Nav;
        private System.Windows.Forms.Label lab_Detail;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}

