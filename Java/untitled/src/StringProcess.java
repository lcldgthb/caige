//
//import java.util.Scanner;
//
//public class StringProcess {
//    public static void main(String[] args) {
//        // 1. 读取输入字符串
//        Scanner scanner = new Scanner(System.in);
//        String str = scanner.nextLine();
//        scanner.close();
//
//        // （1）统计"we"出现的次数
//        int count1 = 0;
//        int index = 0;
//        while ((index = str.indexOf("we", index)) != -1) {
//            count1++;
//            index += 2; // 跳过已匹配的"we"，避免重复统计
//        }
//        System.out.println("count1=" + count1);
//
//        // （2）输出字符串的逆序
//        String reverseStr = new StringBuilder(str).reverse().toString();
//        System.out.println(reverseStr);
//
//        // （3）统计英文字母的数量
//        int count2 = 0;
//        for (int i = 0; i < str.length(); i++) {
//            char ch = str.charAt(i);
//            if (Character.isLetter(ch)) { // 判断是否为英文字母
//                count2++;
//            }
//        }
//        System.out.println("count2=" + count2);
//    }
//}
