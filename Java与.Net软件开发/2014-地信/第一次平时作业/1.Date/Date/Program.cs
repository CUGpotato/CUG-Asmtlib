using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Date
{
    class Date
    {
        System.DateTime currentTime = new System.DateTime();
        private int year;        //年
        private int month;       //月
        private int day;         //日
        private bool isLegal = false;       //判断日期是否合法的标志
        private bool isLastDay = false;     //判断日期是否为每月最后一天的标志

        public Date()            //不带参构造函数
        {
            currentTime = System.DateTime.Now;
            year = currentTime.Year;
            month = currentTime.Month;
            day = currentTime.Day;
        }
        public Date(int year, int month, int day)    //带参构造函数
        {
            this.year = year;
            this.month = month;
            this.day = day;
        }

        public void JudgeLagal()            //判断日期是否合法
        {
            int[] a = { 31, (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            isLegal = month >= 1 && month <= 12 && day >= 1 && day <= a[month - 1];
        }

        public void JudgeLastDay()          //判断日期是否为最后一天
        {
            int[] a = { 31, (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            isLastDay = day == a[month - 1];
        }

        public void show()      //show()函数显示日期
        {
            JudgeLagal();
            if (isLegal == true)
            {
                Console.WriteLine(year + "-" + month + "-" + day);
            }
            else
            {
                Console.WriteLine("不合法日期");
            }
        }

        public void add()
        {                       //add()函数使日期加一
            JudgeLastDay();
            if (isLegal == false)
            {
                Console.WriteLine("不合法日期");
            }
            else
            {
                if (isLastDay == false)
                {
                    Console.WriteLine(isLastDay);
                    day++;
                    Console.WriteLine("加一天："+year + "-" + month + "-" + day);
                }
                else if (isLastDay==true)
                {
                    day = 1;
                    if (month == 12)
                    {
                        year++;
                        month = 1;
                    }
                    else
                    {
                        month++;
                    }
                    Console.WriteLine("加一天：" + year + "-" + month + "-" + day);
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Date MyDate = new Date();
            MyDate.show();
            MyDate.add();
            Date MyDate1 = new Date(2017, 2, 32);    //某不合法日期对象
            MyDate1.show();
            MyDate1.add();
            Date MyDate2= new Date(2017, 2, 28);    //某合法日期对象
            MyDate2.show();
            MyDate2.add();

        }
    }
}
