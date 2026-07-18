package sortvisualizer.algorithm;

import sortvisualizer.model.SortAlgorithm;

public class SelectionSort extends SortAlgorithm {
    @Override
    public String getName() {
        return "选择排序";
    }
    @Override
    protected void doSort() {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            pass++;
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (compare(arr[j], arr[minIndex]) < 0) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(i, minIndex);
            }
            record(new int[]{i}, i + 1,
                    "第 " + pass + " 趟：选出最小值 " + arr[i] + " 放到第 " + (i + 1) + " 位");
        }
    }
}
