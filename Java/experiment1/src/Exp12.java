
    public class Exp12 {
        public static void main(String[] args) {

            int a = 10;
            boolean b = true;
            double c = 3.14;
            char d = 'A';
            System.out.println("a=" + a + " b=" + b + " c=" + c + " d=" + d);

            // ========== 任务2：给d赋值反斜杠字符 ==========
            d = '\\'; // 反斜杠是转义字符，需要用两个\\表示一个反斜杠
            System.out.println("d=" + d);

            // ========== 任务3：错误写法（编译报错） ==========
            // 错误原因：Math.random()返回double类型，属于高精度类型，不能自动转换为int，会损失精度
            // a = Math.random();  // 取消本行注释会出现编译错误

            // ========== 任务4：修正：强制类型转换 ==========
            a = (int)(Math.random() * 100); // 将double强转为int，生成0~99的随机整数
            System.out.println("随机赋值后a=" + a);
        }
    }

