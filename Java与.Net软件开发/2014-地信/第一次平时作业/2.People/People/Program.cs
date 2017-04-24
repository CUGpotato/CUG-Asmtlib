using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace People
{


    class people
    {
        private string name;       //姓名
        private string address;    //籍贯
        private int age;           //年龄
        public people() { }         //构造函数
        public people(string name, string address, int age)    //带参构造函数
        {
            this.name = name;
            this.address = address;
            this.age = age;
        }
        public virtual void Display()
        {
            Console.Write("姓名：" + name + "\t" + " 籍贯:" + address + "\t" + " 年龄：" + age + "\t");
        }
        public String getName()
        {
            return name;
        }
        public String getAddress()
        {
            return address;
        }
        public int getAge()
        {
            return age;
        }
    }
    class student : people                     //学生类
    {
        private String Snumber;      //学号
        private int rank;           //排名
        public student() { }
        public student(string name, string address, int age, String Snumber, int rank)
            : base(name, address, age)
        {
            this.Snumber = Snumber;
            this.rank = rank;
        }
        public override void Display()
        {
            Console.WriteLine("姓名：" + getName() + "  " + " 籍贯:" + getAddress() + "  " + " 年龄：" + getAge() + "  " + "学号：" + Snumber + "  " + " 排名:" + rank + "  ");
        }
    }

    class Master : people                 //导师类
    {
        private String Mnumber;           //职工号
        private String Direction;         //研究方向
        private String Studentname;       //学生姓名
        public Master() { }
        public Master(string name, string address, int age, String Mnumber, String Direction, String Studentname)
            : base(name, address, age)
        {
            this.Mnumber = Mnumber;
            this.Direction = Direction;
            this.Studentname = Studentname;
        }
        public override void Display()
        {
            Console.WriteLine("姓名：" + getName() + "  " + " 籍贯:" + getAddress() + "  " + " 年龄：" + getAge() + "  " + "职工号：" +
                Mnumber + "  " + " 研究方向:" + Direction + "  " + " 学生:" + Studentname + "  ");
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            student A = new student("董欣怡", "浙江", 20, "20141001143", 15);
            Master B = new Master("杨之江", "湖北", 40, "201003272", "遥感", "董欣怡");
            A.Display();
            B.Display();
        }
    }


}
