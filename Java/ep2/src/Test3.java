////////interface Measurable {
////////    double getMeasure();
////////}
////////
////////class Employee implements Measurable {
////////    String name;
////////    double salary;
////////    public Employee(String name, double salary) {
////////        this.name = name;
////////        this.salary = salary;
////////    }
////////    public double getMeasure() {
////////        return salary;
////////    }
////////}
////////
////////public class Test3 {
////////    public static double average(Measurable[] objects) {
////////        double sum = 0;
////////        for (Measurable m : objects) {
////////            sum += m.getMeasure();
////////        }
////////        return sum / objects.length;
////////    }
////////    public static void main(String[] args) {
////////        Employee[] emps = {
////////                new Employee("张三", 5500),
////////                new Employee("李四", 6200),
////////                new Employee("王五", 7100),
////////                new Employee("赵六", 4800)
////////        };
////////        System.out.println("平均工资：" + average(emps));
////////    }
////////}
//////import java.util.Scanner;
//////
//////class Triangle {
//////    double a, b, c;
//////    public Triangle(double a, double b, double c) {
//////        if (a + b <= c || a + c <= b || b + c <= a) {
//////            throw new IllegalArgumentException();
//////        }
//////        this.a = a;
//////        this.b = b;
//////        this.c = c;
//////    }
//////    public double getArea() {
//////        double p = (a + b + c) / 2;
//////        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
//////    }
//////}
//////
//////public class Test3 {
//////    public static void main(String[] args) {
//////        Scanner sc = new Scanner(System.in);
//////        System.out.print("请输入三角形三条边长：");
//////        double a = sc.nextDouble();
//////        double b = sc.nextDouble();
//////        double c = sc.nextDouble();
//////        try {
//////            Triangle t = new Triangle(a, b, c);
//////            System.out.println("三角形面积：" + t.getArea());
//////        } catch (IllegalArgumentException e) {
//////            System.out.println("三条边不满足构建三角形的条件");
//////        }
//////        sc.close();
//////    }
//////}
////import java.util.Scanner;
////
////public class Test3 {
////    public static void main(String[] args) {
////        Scanner sc = new Scanner(System.in);
////        String password = sc.nextLine();
////        int score = 0;
////        boolean hasDigit = false;
////        boolean hasUpper = false;
////        boolean hasLower = false;
////        boolean hasSpace = false;
////        boolean hasSpecial = false;
////
////        for (int i = 0; i < password.length(); i++) {
////            char ch = password.charAt(i);
////            if (Character.isDigit(ch)) {
////                hasDigit = true;
////            } else if (Character.isUpperCase(ch)) {
////                hasUpper = true;
////            } else if (Character.isLowerCase(ch)) {
////                hasLower = true;
////            } else if (Character.isWhitespace(ch)) {
////                hasSpace = true;
////            } else {
////                hasSpecial = true;
////            }
////        }
////
////        if (password.length() >= 8) score += 2;
////        if (hasDigit) score += 2;
////        if (hasUpper || hasLower) score += 2;
////        if (hasUpper) score += 1;
////        if (hasLower) score += 1;
////        if (hasSpecial) score += 3;
////        if (!hasSpace) score += 1;
////
////        System.out.println(score);
////        sc.close();
////    }
////}
//import java.util.Scanner;
//
//public class Test3 {
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        String line = sc.nextLine().trim();
//        String[] parts = line.split(" ");
//        String[] fields = new String[parts.length];
//        for (int i = 0; i < parts.length; i++) {
//            fields[i] = parts[i].trim();
//        }
//        double price = Double.parseDouble(fields[2]);
//        int count = Integer.parseInt(fields[3]);
//        String type = fields[4];
//
//        double total = price * count;
//        if (type.equals("VIP")) {
//            total *= 0.8;
//        }
//        if (total < 200) {
//            total += 10;
//        }
//        System.out.println((int) total);
//        sc.close();
//    }
//}
import java.math.BigInteger;
import java.util.Scanner;

public class Test3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] parts = line.split(",");
        BigInteger current = new BigInteger(parts[0]);
        BigInteger num = new BigInteger(parts[1]);
        BigInteger max = new BigInteger(parts[2]);

        BigInteger last = current.add(num);
        System.out.println(last.compareTo(max) <= 0 ? 1 : 0);
        System.out.println(max.subtract(last));
        sc.close();
    }
}