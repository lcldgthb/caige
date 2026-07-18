package sortvisualizer;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;

public class Main {

    public static void main(String[] args) {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (Exception ignored) {

        }
        SwingUtilities.invokeLater(() -> {
            sortvisualizer.MainFrame frame = new sortvisualizer.MainFrame();
            frame.setVisible(true);
        });
    }
}
