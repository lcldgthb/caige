//public class  {
//    public static void main(String a[]) {
//
//        int x = 125;
//
//        System.out.print("line1="+x % 2);
//
//        System.out.print(",line2="+x / 10);
//
//        System.out.print(",line3="+x % 3 == 0);
//
//    }
//}
import java.util.Scanner;
public class exam03{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        // System.out.println("请输入一个整数N");
        int n=sc.nextInt();
        int g=(n+7)/8;
        int b=n/g;
        int e=n%g;
        //  System.out.println("各分组的人数如下：");
        for(int i=0;i<g;i++)
        {
            if(i<e)
                System.out.println(b+1);
            else
                System.out.println(b);
        }

    }
}
