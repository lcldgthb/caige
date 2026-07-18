package sortvisualizer.algorithm;

import sortvisualizer.model.SortAlgorithm;

public class InsertionSort extends SortAlgorithm {
    @Override
    public String getName() {
        return "插入排序";
    }
    @Override
    protected void doSort() {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            pass++;
            int current = arr[i];
            int j = i - 1;
            while (j >= 0 && compare(arr[j], current) > 0) {
                arr[j + 1] = arr[j];
                swapCount++;
                j--;
            }
            arr[j + 1] = current;
            record(new int[]{j + 1}, i + 1,
                    "第 " + pass + " 趟：将 " + current + " 插入到前 " + (i + 1) + " 个元素的有序区");
        }
    }
}
