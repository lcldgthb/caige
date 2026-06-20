////////TIP 要<b>运行</b>代码，请按 <shortcut actionId="Run"/> 或
//////// 点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
////////public class Test {
////////    public static void main(String[] args) {
////////        //TIP 当文本光标位于高亮显示的文本处时按 <shortcut actionId="ShowIntentionActions"/>
////////        // 查看 IntelliJ IDEA 建议如何修正。
////////        System.out.printf("Hello and welcome!");
////////
////////        for (int i = 1; i <= 5; i++) {
////////            //TIP 按 <shortcut actionId="Debug"/> 开始调试代码。我们已经设置了一个 <icon src="AllIcons.Debugger.Db_set_breakpoint"/> 断点
////////            // 但您始终可以通过按 <shortcut actionId="ToggleLineBreakpoint"/> 添加更多断点。
////////            System.out.println("i = " + i);
////////        }
////////    }
////////}
//////package Test;
//////
//////public   class  Test {
//////    public static void main(String[] args) {
//////        int a = 10;
//////        boolean b = true;
//////        double c = 3.14;
//////        char d = 'A';
//////        System.out.println(a + " " + b + " " + c + " " + d);
//////
//////        d = '\\';
//////        System.out.println(a + " " + b + " " + c + " " + d);
//////
//////        a = (int)(Math.random() * 100);
//////        System.out.println(a);
//////    }
//////}
//////package Test;
////
////public class Test {
////    public static void main(String[] args) {
////        int a = 10;
////        boolean b = true;
////        double c = 3.14;
////        char d = 'A';
////        System.out.println(a + " " + b + " " + c + " " + d);
////
////        d = '\\';
////        System.out.println(a + " " + b + " " + c + " " + d);
////
////        a = (int)(Math.random() * 100);
////        System.out.println(a);
////    }
////}
////package ;
//
//public class Test {
//    public static void main(String[] args) {
//        int a = 10;
//        boolean b = true;
//        double c = 3.14;
//        char d = 'A';
//        System.out.println(a + " " + b + " " + c + " " + d);
//        d = '\\';
//        System.out.println(a + " " + b + " " + c + " " + d);
//        a = (int)(Math.random() * 100);
//        System.out.println(a);
//    }
//}
//package Test;
import javax.swing.JOptionPane;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Test {

    public static void main(String[] args) {
        String rStr = JOptionPane.showInputDialog("请输入圆柱体半径：");
        String hStr = JOptionPane.showInputDialog("请输入圆柱体高：");
        double r = Double.parseDouble(rStr);
        double h = Double.parseDouble(hStr);
        double v1 = Math.PI * r * r * h;
        JOptionPane.showMessageDialog(null, String.format("圆柱体体积：%.3f", v1));

        Scanner sc = new Scanner(System.in);
        System.out.print("请输入球的半径：");
        double r2 = sc.nextDouble();
        double v2 = 4.0 / 3 * Math.PI * Math.pow(r2, 3);
        System.out.println("球的体积：" + v2);

        System.out.print("请输入矩形的长：");
        double len = sc.nextDouble();
        System.out.print("请输入矩形的宽：");
        double wid = sc.nextDouble();
        System.out.println("矩形周长：" + 2 * (len + wid));
        System.out.println("矩形面积：" + len * wid);

        System.out.print("请输入摄氏温度：");
        double c = sc.nextDouble();
        double f = 9.0 / 5 * c + 32;
        System.out.println("华氏温度：" + f);

        System.out.print("请输入一个实数：");
        double num = sc.nextDouble();
        int intPart = (int) num;
        double diff = num - intPart;
        System.out.println(diff);
        System.out.printf("%.4f%n", diff);

        int n1 = (int)(Math.random() * 10);
        int n2 = (int)(Math.random() * 10);
        int sum = n1 + n2;
        int pro = n1 * n2;
        JOptionPane.showMessageDialog(null, "两个数：" + n1 + "、" + n2 + "\n和：" + sum + "\n积：" + pro);
        sc.close();
    }
}