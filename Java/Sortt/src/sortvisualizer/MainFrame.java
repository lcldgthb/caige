package sortvisualizer;

import sortvisualizer.algorithm.BubbleSort;
import sortvisualizer.algorithm.InsertionSort;
import sortvisualizer.algorithm.QuickSort;
import sortvisualizer.algorithm.SelectionSort;
import sortvisualizer.algorithm.ShellSort;
import sortvisualizer.model.SortAlgorithm;
import sortvisualizer.view.AlgorithmTab;
import javax.swing.JFrame;
import javax.swing.JTabbedPane;

public class MainFrame extends JFrame {

    public MainFrame() {
        setTitle("排序算法图形化演示程序");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(760, 560);
        setLocationRelativeTo(null);
        JTabbedPane tabbedPane = new JTabbedPane();
        SortAlgorithm[] algorithms = {
                new BubbleSort(),
                new SelectionSort(),
                new InsertionSort(),
                new ShellSort(),
                new QuickSort()
        };
        for (SortAlgorithm algo : algorithms) {
            tabbedPane.addTab(algo.getName(), new AlgorithmTab(algo));
        }
        add(tabbedPane);
    }
}
