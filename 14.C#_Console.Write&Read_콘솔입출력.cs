using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//using Con = System.Console;

//public class GlobalTest
//{
//    public static string str = "전역에 속한 클래스";
//}

//namespace LocalNamespace
//{
//    public class LocalTest
//    {
//        public static string msg = "네임스페이스 안에 속한 클래스";
//    }
//}

//namespace ConsoleApplication8
//{
//    class MainClass
//    {
//        static void Main(string[] args)
//        {
//            Console.WriteLine(GlobalTest.str);
//            Console.WriteLine(LocalNamespace.LocalTest.msg);
//        }
//    }
//}

//namespace ConsoleWrite
//{
//    class Write
//    {
//        static void Write2()
//        {
//            int i = 0;
//            string s = "안녕하세요";
//            Console.WriteLine(i);
//            Console.WriteLine("i=" + i);
//            Console.WriteLine("i={0} str={1}", i, s);
//        }
//    }
//}

//namespace Test
//{
//    class Program
//    {
//        static void Main(string[] args)
//        {
//            int money = 10000;
//            double d = 10.876;
//            Console.WriteLine("화폐 단위 출력: {0,3:C} 퍼센트 출력: {1,0:P}", money, d);
//            Console.WriteLine("부동 소수 출력: {0,1:E} 고정 소수 출력: {0,1:F} 짧게 출력: {0,1:G}", d);
//        }
//    }
//}

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            string name, temp;
            int age;
            double height;

            Console.Write("이름 입력: ");
            name = Console.ReadLine();          // ReadLine은 문자열만 입력받음
            Console.WriteLine("이름:" + name);

            Console.Write("나이 입력: ");
            temp = Console.ReadLine();
            age = Convert.ToInt32(temp);       // Convert.To = 변환
            Console.WriteLine("나이: " + age);

            Console.Write("키 입력: ");
            temp = Console.ReadLine();
            height = Convert.ToDouble(temp);
            Console.WriteLine("키: " + height);


            ConsoleKeyInfo key;
            Console.Write("키를 누르세요 ");
            key = Console.ReadKey();
            Console.WriteLine("누른 키는" + key.Key + "입니다.");  //key.Key
        }
    }
}