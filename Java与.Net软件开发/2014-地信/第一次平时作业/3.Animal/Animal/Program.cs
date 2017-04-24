using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animal
{


    public class Animal                 //动物基类
    {
        public virtual void Eat()
        {
            Console.WriteLine("动物都要吃东西");
        }
    }

    public class Fish : Animal          //鱼
    {
        /// 重写父类中Eat方法

        public override void Eat()
        {
            Console.WriteLine("鱼吃水草和虫子");
        }
    }

    public class Dog : Animal           //狗
    {

        /// 重写父类中Eat方法
        public override void Eat()
        {
            Console.WriteLine("狗是杂食性动物，喜欢吃肉");
        }
    }


    class Program
    {
        static void Main(string[] args)
        {

            Animal[] Animals = { 
                       new Animal(),
                       new Fish(),
                       new Dog()
        };
            //遍历一下birds数组
            foreach (Animal animal in Animals)
            {
               animal.Eat();
            }
            Console.ReadKey();
        }
    }
}
