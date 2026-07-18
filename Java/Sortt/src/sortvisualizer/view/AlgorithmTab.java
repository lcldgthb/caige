package sortvisualizer.view;

import sortvisualizer.model.SortAlgorithm;
import sortvisualizer.model.SortStep;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.Timer;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import java.util.Random;

















public class AlgorithmTab extends JPanel {


    private final SortAlgorithm algorithm;


    private final SortPanel sortPanel;


    private final JLabel statsLabel;
    private final JLabel descLabel;


    private final JButton btnRandom;
    private final JButton btnStart;
    private final JButton btnPause;
    private final JButton btnNext;
    private final JButton btnReset;


    private final JSlider speedSlider;


    private final Timer timer;



    private int[] data;

    private List<SortStep> steps;

    private int currentFrame;

    private int maxValue;


    private static final int DEFAULT_SIZE = 20;

    private static final int VALUE_BOUND = 100;

    public AlgorithmTab(SortAlgorithm algorithm) {
        this.algorithm = algorithm;
        setLayout(new BorderLayout(8, 8));
        setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));


        statsLabel = new JLabel();
        statsLabel.setFont(new Font("SansSerif", Font.BOLD, 14));
        statsLabel.setBorder(BorderFactory.createEmptyBorder(4, 6, 4, 6));
        add(statsLabel, BorderLayout.NORTH);


        JPanel centerPanel = new JPanel(new BorderLayout(0, 6));
        sortPanel = new SortPanel();
        sortPanel.setBorder(BorderFactory.createLineBorder(new Color(200, 200, 200)));
        centerPanel.add(sortPanel, BorderLayout.CENTER);

        descLabel = new JLabel(" ");
        descLabel.setFont(new Font("SansSerif", Font.PLAIN, 13));
        descLabel.setForeground(new Color(80, 80, 80));
        centerPanel.add(descLabel, BorderLayout.SOUTH);

        add(centerPanel, BorderLayout.CENTER);


        btnRandom = new JButton("随机生成");
        btnStart = new JButton("开始");
        btnPause = new JButton("暂停");
        btnNext = new JButton("下一趟");
        btnReset = new JButton("重置");

        JPanel controlPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 8, 4));
        controlPanel.add(btnRandom);
        controlPanel.add(btnStart);
        controlPanel.add(btnPause);
        controlPanel.add(btnNext);
        controlPanel.add(btnReset);


        controlPanel.add(Box.createHorizontalStrut(12));
        controlPanel.add(new JLabel("速度:"));
        speedSlider = new JSlider(1, 10, 5);
        speedSlider.setPreferredSize(new Dimension(140, 30));
        controlPanel.add(speedSlider);

        add(controlPanel, BorderLayout.SOUTH);


        timer = new Timer(sliderToDelay(speedSlider.getValue()), new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                stepForward();
            }
        });


        bindEvents();


        generateRandomData();
    }


    private void bindEvents() {
        btnRandom.addActionListener(e -> generateRandomData());

        btnStart.addActionListener(e -> {

            if (currentFrame >= steps.size() - 1) {
                currentFrame = 0;
                showFrame(currentFrame);
            }
            timer.start();
            updateButtonState(true);
        });

        btnPause.addActionListener(e -> {
            timer.stop();
            updateButtonState(false);
        });

        btnNext.addActionListener(e -> {
            timer.stop();
            updateButtonState(false);
            stepForward();
        });

        btnReset.addActionListener(e -> {
            timer.stop();
            currentFrame = 0;
            showFrame(currentFrame);
            updateButtonState(false);
        });


        speedSlider.addChangeListener(e -> timer.setDelay(sliderToDelay(speedSlider.getValue())));
    }


    private int sliderToDelay(int sliderValue) {

        return 1100 - sliderValue * 100;
    }


    private void generateRandomData() {
        timer.stop();
        Random rnd = new Random();
        data = new int[DEFAULT_SIZE];
        maxValue = 1;
        for (int i = 0; i < DEFAULT_SIZE; i++) {
            data[i] = rnd.nextInt(VALUE_BOUND) + 1;
            maxValue = Math.max(maxValue, data[i]);
        }
        prepareSteps();
        updateButtonState(false);
    }







    private void prepareSteps() {
        steps = algorithm.sort(data);
        currentFrame = 0;
        showFrame(currentFrame);
    }


    private void stepForward() {
        if (currentFrame < steps.size() - 1) {
            currentFrame++;
            showFrame(currentFrame);
        }

        if (currentFrame >= steps.size() - 1) {
            timer.stop();
            updateButtonState(false);
            onSortFinished();
        }
    }







    private void showFrame(int index) {
        SortStep step = steps.get(index);
        sortPanel.setStep(step, maxValue);
        statsLabel.setText(String.format("  趟数: %d      比较次数: %d      交换次数: %d",
                step.getPass(), step.getCompareCount(), step.getSwapCount()));
        descLabel.setText("  " + step.getDescription());
    }


    private void onSortFinished() {
        SortStep last = steps.get(steps.size() - 1);

        if (last.getDescription().contains("完成")) {
            JOptionPane.showMessageDialog(this,
                    algorithm.getName() + " " + last.getDescription(),
                    "排序完成",
                    JOptionPane.INFORMATION_MESSAGE);
        }
    }






    private void updateButtonState(boolean playing) {
        btnStart.setEnabled(!playing);
        btnPause.setEnabled(playing);
        btnNext.setEnabled(!playing);
        btnRandom.setEnabled(!playing);

    }
}
