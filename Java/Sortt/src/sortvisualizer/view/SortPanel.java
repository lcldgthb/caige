package sortvisualizer.view;

import sortvisualizer.model.SortStep;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
















public class SortPanel extends JPanel {


    private SortStep currentStep;


    private int maxValue = 1;


    private static final Color COLOR_SORTED = new Color(76, 175, 80);
    private static final Color COLOR_ACTIVE = new Color(255, 152, 0);
    private static final Color COLOR_UNSORTED = new Color(33, 150, 243);
    private static final Color COLOR_BG = Color.WHITE;
    private static final Color COLOR_TEXT = new Color(60, 60, 60);

    public SortPanel() {
        setBackground(COLOR_BG);
        setPreferredSize(new Dimension(600, 360));
    }







    public void setStep(SortStep step, int maxValue) {
        this.currentStep = step;
        this.maxValue = Math.max(1, maxValue);
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        if (currentStep == null) {
            return;
        }

        int[] data = currentStep.getSnapshot();
        int n = data.length;
        if (n == 0) {
            return;
        }

        Graphics2D g2 = (Graphics2D) g;

        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        int panelWidth = getWidth();
        int panelHeight = getHeight();


        int marginX = 20;
        int marginTop = 20;
        int marginBottom = 30;
        int usableWidth = panelWidth - 2 * marginX;
        int usableHeight = panelHeight - marginTop - marginBottom;




        double slotWidth = (double) usableWidth / n;
        int barWidth = (int) Math.max(2, slotWidth * 0.7);


        boolean drawLabel = n <= 30;
        g2.setFont(new Font("SansSerif", Font.PLAIN, 11));

        for (int i = 0; i < n; i++) {

            int barHeight = (int) ((double) data[i] / maxValue * usableHeight);
            if (barHeight < 1) {
                barHeight = 1;
            }


            int x = marginX + (int) (i * slotWidth) + (int) ((slotWidth - barWidth) / 2);
            int y = marginTop + (usableHeight - barHeight);


            g2.setColor(pickColor(i, n));
            g2.fillRect(x, y, barWidth, barHeight);


            if (drawLabel) {
                g2.setColor(COLOR_TEXT);
                String text = String.valueOf(data[i]);
                int textWidth = g2.getFontMetrics().stringWidth(text);
                int textX = x + (barWidth - textWidth) / 2;
                g2.drawString(text, textX, y - 3);
            }
        }
    }





    private Color pickColor(int index, int n) {
        if (currentStep.isHighlighted(index)) {
            return COLOR_ACTIVE;
        }
        if (currentStep.isSorted(index, n)) {
            return COLOR_SORTED;
        }
        return COLOR_UNSORTED;
    }
}
