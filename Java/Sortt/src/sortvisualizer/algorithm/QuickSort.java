package sortvisualizer.algorithm;
import sortvisualizer.model.SortAlgorithm;

public class QuickSort extends SortAlgorithm {
    @Override
    public String getName() {
        return "快速排序";
    }
    @Override
    protected void doSort() {
        if (arr.length <= 1) {
            return;
        }
        quickSort(0, arr.length - 1);
    }
    private void quickSort(int low, int high) {
        if (low >= high) {
            return;
        }

        int pivotIndex = partition(low, high);
        pass++;
        record(new int[]{pivotIndex}, 0,
                "第 " + pass + " 趟：基准值 " + arr[pivotIndex]
                        + " 归位到第 " + (pivotIndex + 1) + " 位，左小右大");
        quickSort(low, pivotIndex - 1);
        quickSort(pivotIndex + 1, high);
    }
    private int partition(int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {

            if (compare(arr[j], pivot) < 0) {
                i++;
                if (i != j) {
                    swap(i, j);
                }
            }
        }

        if (i + 1 != high) {
            swap(i + 1, high);
        }
        return i + 1;
    }
}
