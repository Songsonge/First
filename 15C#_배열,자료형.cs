using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StructTest
{
    public enum Job
    {
        King=1,
        Nobleman=2,
        Soilder=1,
        Etc=4
    }
    class Test
    {
        static void Main()
        {
            Job j1 = Job.King;
            Job j2 = Job.Nobleman;
            Console.WriteLine(j1);          //King
            Console.WriteLine(j2);          //Nobleman
            Console.WriteLine((int)j1);     //1
            Console.WriteLine((int)j2);     //2

            int[] ar1 = new int[5];     //다 0
            int[] ar2 = new int[5] { 1,2,3,4,5};
            int[] ar3 = { 1, 2, 3, 4, 5 };
            Console.WriteLine(ar1[0]);      //0
            Console.WriteLine(ar2[0]);      //1
            Console.WriteLine(ar3[0]);      //1

            object obj = new Object();
            string str = "Hello World";
            Console.WriteLine(obj);
            Console.WriteLine(str);
            Console.WriteLine(obj.ToString());      //string형으로 반환
            Console.WriteLine(str.ToString());
            Console.WriteLine(obj.GetType());       //어떤 타입인지 반환
            Console.WriteLine(str.GetType());
            Console.WriteLine(obj.GetHashCode());   //hash코드 반환
            Console.WriteLine(str.GetHashCode());
        }
    }
}