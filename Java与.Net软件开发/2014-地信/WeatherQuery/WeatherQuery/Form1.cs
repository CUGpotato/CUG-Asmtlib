using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WeatherQuery.ServiceWeather;
using WeatherQuery.WeatherWeb;

namespace WeatherQuery
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        WeatherWeb.WeatherWebService weather = new WeatherWebService();   


        private void Form1_Load(object sender, EventArgs e)
        {

            string[] supportProvince = weather.getSupportProvince();
            foreach (String s in supportProvince)
            {
                cb_Province.Items.Add(s);
            }
            String[] supportCity = weather.getSupportCity(cb_Province.Text);
            
            cb_City.Items.Add("----");
            
        }



        private void cb_Province_SelectedIndexChanged(object sender, EventArgs e)
        {
            cb_City.Items.Clear();
            string[] supportCity = weather.getSupportCity(cb_Province.Text);
            foreach (String s in supportCity)
            {
                string[] c = s.Split(new Char[] { '(' }, StringSplitOptions.RemoveEmptyEntries);
                if (c.Length > 0)
                    cb_City.Items.Add(c[0]);
            }
        }

        private void btn_Search_Click(object sender, EventArgs e)
        {

            string city = cb_City.Text;
            string[] weatherDetail=new string[32];
            System.Console.WriteLine(city);

            

            if (city.Equals("----")||city.Equals("选择城市"))
            {
                MessageBox.Show("请输入城市！");
            }
            else
            {
                weatherDetail = weather.getWeatherbyCityName(city);
                
                lab_Weather.Text = weatherDetail[6]+" "+weatherDetail[7]+"  "+weatherDetail[5];
                lab_Nav.Text=weatherDetail[10];
                string detail=weatherDetail[11];
                lab_Detail.Text = weatherDetail[11];

                
            }


        }


    }
}
