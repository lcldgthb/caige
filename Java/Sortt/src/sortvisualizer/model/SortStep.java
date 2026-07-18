package sortvisualizer.model;

import java.util.Arrays;

public class SortStep {

    private final int[] snapshot;
    private final int[] highlightIndices;
    private final int sortedCount;
    private final boolean sortedFromEnd;
    private final int pass;
    private final int compareCount;
    private final int swapCount;
    private final String description;

    public SortStep(int[] snapshot, int[] highlightIndices, int sortedCount, boolean sortedFromEnd,
                    int pass, int compareCount, int swapCount, String description) {

        this.snapshot = Arrays.copyOf(snapshot, snapshot.length);
        this.highlightIndices = (highlightIndices == null)
                ? new int[0]
                : Arrays.copyOf(highlightIndices, highlightIndices.length);
        this.sortedCount = sortedCount;
        this.sortedFromEnd = sortedFromEnd;
        this.pass = pass;
        this.compareCount = compareCount;
        this.swapCount = swapCount;
        this.description = (description == null) ? "" : description;
    }
    public SortStep(int[] snapshot, int[] highlightIndices, int sortedCount,
                    int pass, int compareCount, int swapCount, String description) {
        this(snapshot, highlightIndices, sortedCount, false, pass, compareCount, swapCount, description);
    }
    public int[] getSnapshot() {
        return Arrays.copyOf(snapshot, snapshot.length);
    }
    public boolean isHighlighted(int index) {
        for (int h : highlightIndices) {
            if (h == index) {
                return true;
            }
        }
        return false;
    }
    public boolean isSorted(int index, int n) {
        if (sortedFromEnd) {

            return index >= n - sortedCount;
        } else {

            return index < sortedCount;
        }
    }

    public int getSortedCount() {
        return sortedCount;
    }

    public boolean isSortedFromEnd() {
        return sortedFromEnd;
    }

    public int getPass() {
        return pass;
    }

    public int getCompareCount() {
        return compareCount;
    }

    public int getSwapCount() {
        return swapCount;
    }

    public String getDescription() {
        return description;
    }
}
