//////////////////////////class Point {
//////////////////////////    int x;
//////////////////////////    int y;
//////////////////////////    public Point() {
//////////////////////////    }
//////////////////////////    public Point(int x, int y) {
//////////////////////////        this.x = x;
//////////////////////////        this.y = y;
//////////////////////////    }
//////////////////////////}
//////////////////////////public class Test2 {
//////////////////////////    public static void main(String[] args) {
//////////////////////////        Point p = new Point(5, 10);
//////////////////////////        System.out.println(p);
//////////////////////////        System.out.println("x=" + p.x);
//////////////////////////        System.out.println("y=" + p.y);
//////////////////////////    }
//////////////////////////}
////////////////////////class Point {
////////////////////////    int x;
////////////////////////    int y;
////////////////////////    public Point() {
////////////////////////    }
////////////////////////    public Point(int x, int y) {
////////////////////////        this.x = x;
////////////////////////        this.y = y;
////////////////////////    }
////////////////////////    public String toString() {
////////////////////////        return x + "," + y;
////////////////////////    }
////////////////////////}
////////////////////////public class Test2 {
////////////////////////    public static void main(String[] args) {
////////////////////////        Point p = new Point(5, 10);
////////////////////////        System.out.println(p);
////////////////////////    }
////////////////////////}
//////////////////////class Point {
//////////////////////    int x;
//////////////////////    int y;
//////////////////////    public Point() {
//////////////////////    }
//////////////////////    public Point(int x, int y) {
//////////////////////        this.x = x;
//////////////////////        this.y = y;
//////////////////////    }
//////////////////////    public String toString() {
//////////////////////        return x + "," + y;
//////////////////////    }
//////////////////////}
//////////////////////public class Test2 {
//////////////////////    public static void main(String[] args) {
//////////////////////        Point[] c = new Point[8];
//////////////////////        for (int i = 0; i < c.length; i++) {
//////////////////////            c[i] = new Point(i, i * 2);
//////////////////////        }
//////////////////////    }
//////////////////////}
////////////////////class Point {
////////////////////    int x;
////////////////////    int y;
////////////////////    public Point() {
////////////////////        this(0, 0);
////////////////////    }
////////////////////    public Point(int x, int y) {
////////////////////        this.x = x;
////////////////////        this.y = y;
////////////////////    }
////////////////////    public String toString() {
////////////////////        return x + "," + y;
////////////////////    }
////////////////////}
////////////////////public class Test2 {
////////////////////    public static void main(String[] args) {
////////////////////        Point p = new Point();
////////////////////        System.out.println(p);
////////////////////    }
////////////////////}
//////////////////class Triangle {
//////////////////    double a;
//////////////////    double b;
//////////////////    double c;
//////////////////    public Triangle() {
//////////////////    }
//////////////////    public Triangle(double a, double b, double c) {
//////////////////        this.a = a;
//////////////////        this.b = b;
//////////////////        this.c = c;
//////////////////    }
//////////////////    public double getPerimeter() {
//////////////////        return a + b + c;
//////////////////    }
//////////////////    public double getArea() {
//////////////////        double p = getPerimeter() / 2;
//////////////////        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
//////////////////    }
//////////////////}
//////////////////public class Test2 {
//////////////////    public static void main(String[] args) {
//////////////////        Triangle t1 = new Triangle(3, 4, 5);
//////////////////        Triangle t2 = new Triangle(7, 8, 9);
//////////////////        System.out.println("三角形1周长：" + t1.getPerimeter());
//////////////////        System.out.println("三角形1面积：" + t1.getArea());
//////////////////        System.out.println("三角形2周长：" + t2.getPerimeter());
//////////////////        System.out.println("三角形2面积：" + t2.getArea());
//////////////////    }
//////////////////}
////////////////class Student {
////////////////    String id;
////////////////    String name;
////////////////    int age;
////////////////    public Student(String id, String name, int age) {
////////////////        this.id = id;
////////////////        this.name = name;
////////////////        this.age = age;
////////////////    }
////////////////    public String toString() {
////////////////        return "学号：" + id + "，姓名：" + name + "，年龄：" + age;
////////////////    }
////////////////}
////////////////public class Test2 {
////////////////    public static void main(String[] args) {
////////////////        Student[] students = {
////////////////                new Student("001", "张三", 19),
////////////////                new Student("002", "李四", 21),
////////////////                new Student("003", "王五", 20),
////////////////                new Student("004", "赵六", 22)
////////////////        };
////////////////        for (Student s : students) {
////////////////            s.age++;
////////////////        }
////////////////        System.out.println("所有学生信息：");
////////////////        for (Student s : students) {
////////////////            System.out.println(s);
////////////////        }
////////////////        System.out.println("年龄大于20岁的学生：");
////////////////        for (Student s : students) {
////////////////            if (s.age > 20) {
////////////////                System.out.println(s.name);
////////////////            }
////////////////        }
////////////////    }
////////////////}
//////////////class Person {
//////////////    String name;
//////////////    String gender;
//////////////    int age;
//////////////    Person[] children;
//////////////    public Person(String name, String gender, int age) {
//////////////        this.name = name;
//////////////        this.gender = gender;
//////////////        this.age = age;
//////////////    }
//////////////    public String getName() {
//////////////        return name;
//////////////    }
//////////////    public int getAge() {
//////////////        return age;
//////////////    }
//////////////    public void addAge() {
//////////////        age++;
//////////////    }
//////////////    public Person[] getChildren() {
//////////////        return children;
//////////////    }
//////////////    public void setChildren(Person[] children) {
//////////////        this.children = children;
//////////////    }
//////////////}
//////////////public class Test2 {
//////////////    public static void main(String[] args) {
//////////////        Person parent = new Person("父亲", "男", 50);
//////////////        Person c1 = new Person("儿子", "男", 25);
//////////////        Person c2 = new Person("女儿", "女", 22);
//////////////        parent.setChildren(new Person[]{c1, c2});
//////////////        System.out.println("姓名：" + parent.getName());
//////////////        System.out.println("年龄：" + parent.getAge());
//////////////        parent.addAge();
//////////////        System.out.println("加一岁后年龄：" + parent.getAge());
//////////////        System.out.println("子女：");
//////////////        for (Person child : parent.getChildren()) {
//////////////            System.out.println(child.getName() + "，" + child.getAge() + "岁");
//////////////        }
//////////////    }
//////////////}
////////////class Counter {
////////////    int value = 10;
////////////}
////////////public class Test2 {
////////////    public static void main(String args[]) {
////////////        Counter c = new Counter();
////////////        System.out.println(c.value);
////////////    }
////////////}
//////////class Counter {
//////////    static int value = 20;
//////////    public static void showValue() {
//////////        // 方式3：同类静态方法内直接访问
//////////        System.out.println(value);
//////////    }
//////////}
//////////public class Test2 {
//////////    public static void main(String args[]) {
//////////        // 方式1：类名.静态变量
//////////        System.out.println(Counter.value);
//////////        // 方式2：对象.静态变量
//////////        Counter c = new Counter();
//////////        System.out.println(c.value);
//////////        // 方式3：通过静态方法调用演示
//////////        Counter.showValue();
//////////    }
//////////}
////////import java.util.Scanner;
////////
////////class Student {
////////    String id;
////////    String name;
////////    int age;
////////    public Student() {
////////    }
////////    public Student(String id, String name, int age) {
////////        this.id = id;
////////        this.name = name;
////////        this.age = age;
////////    }
////////    public String toString() {
////////        return "学号：" + id + "，姓名：" + name + "，年龄：" + age;
////////    }
////////}
////////
////////class StudentManager {
////////    Student[] students = new Student[100];
////////    int count = 0;
////////
////////    public void addStudent(Student s) {
////////        students[count++] = s;
////////    }
////////
////////    public void deleteStudent(String id) {
////////        for (int i = 0; i < count; i++) {
////////            if (students[i].id.equals(id)) {
////////                for (int j = i; j < count - 1; j++) {
////////                    students[j] = students[j + 1];
////////                }
////////                count--;
////////                System.out.println("删除成功");
////////                return;
////////            }
////////        }
////////        System.out.println("未找到该学生");
////////    }
////////
////////    public void updateStudent(String id, String newName, int newAge) {
////////        for (int i = 0; i < count; i++) {
////////            if (students[i].id.equals(id)) {
////////                students[i].name = newName;
////////                students[i].age = newAge;
////////                System.out.println("修改成功");
////////                return;
////////            }
////////        }
////////        System.out.println("未找到该学生");
////////    }
////////
////////    public void findStudent(String id) {
////////        for (int i = 0; i < count; i++) {
////////            if (students[i].id.equals(id)) {
////////                System.out.println(students[i]);
////////                return;
////////            }
////////        }
////////        System.out.println("未找到该学生");
////////    }
////////
////////    public void showAll() {
////////        for (int i = 0; i < count; i++) {
////////            System.out.println(students[i]);
////////        }
////////    }
////////}
////////
////////public class Test2 {
////////    public static void main(String[] args) {
////////        Scanner sc = new Scanner(System.in);
////////        StudentManager manager = new StudentManager();
////////        while (true) {
////////            System.out.println("=====学生管理系统=====");
////////            System.out.println("1. 添加学生");
////////            System.out.println("2. 删除学生");
////////            System.out.println("3. 修改学生");
////////            System.out.println("4. 查询学生");
////////            System.out.println("5. 查看所有");
////////            System.out.println("0. 退出");
////////            System.out.print("请输入操作序号：");
////////            int choice = sc.nextInt();
////////            if (choice == 0) break;
////////            switch (choice) {
////////                case 1:
////////                    System.out.print("输入学号：");
////////                    String id = sc.next();
////////                    System.out.print("输入姓名：");
////////                    String name = sc.next();
////////                    System.out.print("输入年龄：");
////////                    int age = sc.nextInt();
////////                    manager.addStudent(new Student(id, name, age));
////////                    break;
////////                case 2:
////////                    System.out.print("输入要删除的学号：");
////////                    String did = sc.next();
////////                    manager.deleteStudent(did);
////////                    break;
////////                case 3:
////////                    System.out.print("输入要修改的学号：");
////////                    String uid = sc.next();
////////                    System.out.print("输入新姓名：");
////////                    String uname = sc.next();
////////                    System.out.print("输入新年龄：");
////////                    int uage = sc.nextInt();
////////                    manager.updateStudent(uid, uname, uage);
////////                    break;
////////                case 4:
////////                    System.out.print("输入要查询的学号：");
////////                    String fid = sc.next();
////////                    manager.findStudent(fid);
////////                    break;
////////                case 5:
////////                    manager.showAll();
////////                    break;
////////                default:
////////                    System.out.println("输入错误");
////////            }
////////        }
////////        sc.close();
////////    }
////////}
////////// 方式1：全类名直接引用（无需import）
////////public class Test2 {
////////    public static void main(String[] args) {
////////        pkg1.DemoA a = new pkg1.DemoA();
////////        a.show();
////////    }
////////}
//////class Parent {
//////    int x = 100;
//////    void m() {
//////        System.out.println(x);
//////    }
//////}
//////class Child extends Parent {
//////    int x = 200;
//////}
//////public class Test2 {
//////    public static void main(String args[]) {
//////        Child a = new Child();
//////        a.m();
//////        System.out.println(a.x);
//////    }
//////}
////class Parent {
////    int x = 100;
////    void m() {
////        System.out.println(x);
////    }
////}
////class Child extends Parent {
////    int x = 200;
////    void m() {
////        System.out.println("x=" + x);
////    }
////}
////public class Test2 {
////    public static void main(String args[]) {
////        Child a = new Child();
////        a.m();
////        System.out.println(a.x);
////    }
////}
//class Parent {
//    int x = 100;
//    void m() {
//        System.out.println("父类方法x=" + x);
//    }
//}
//class Child extends Parent {
//    int x = 200;
//    void m() {
//        super.m();
//        System.out.println("super访问父类x=" + super.x);
//        System.out.println("子类x=" + x);
//    }
//}
//public class Test2 {
//    public static void main(String args[]) {
//        Child a = new Child();
//        a.m();
//    }
//}
abstract class Fruit {
    double weight;
    abstract double getWeight();
}

class Apple extends Fruit {
    public Apple(double weight) {
        this.weight = weight;
    }
    double getWeight() {
        return weight;
    }
}

class Peach extends Fruit {
    public Peach(double weight) {
        this.weight = weight;
    }
    double getWeight() {
        return weight;
    }
}

public class Test2 {
    public static void main(String[] args) {
        Fruit[] fruits = {
                new Apple(1.2),
                new Apple(0.85),
                new Peach(0.6),
                new Peach(0.75)
        };
        for (Fruit f : fruits) {
            System.out.println("类型：" + f.getClass().getName() + "，重量：" + f.getWeight());
        }
    }
}