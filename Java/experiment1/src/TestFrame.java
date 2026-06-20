
import java.awt.*;
public class TestFrame extends Frame {
    public void paint(Graphics g) {
        // 绘制星号三角形
        int startX = 60;       // 三角形水平起始坐标
        int startY = 100;      // 三角形第一行的垂直坐标
        int lineHeight = 20;   // 每行文字的垂直间距

        // 外层循环：控制行数，共3行
        for (int i = 1; i <= 3; i++) {
            // 内层循环：拼接当前行的星号，第i行有i个*
            String line = "";
            for (int j = 1; j <= i; j++) {
                line += "*";
            }
            // 在对应位置绘制当前行星号
            g.drawString(line, startX, startY + (i - 1) * lineHeight);
        }
    }
    public static void main(String[] args){
        TestFrame window = new TestFrame();
        window.setBackground(Color.blue);
        window.setSize(200, 200);  // 调高窗口高度，完整显示三角形
        window.setTitle("星号三角形");
        window.setVisible(true);
    }
}