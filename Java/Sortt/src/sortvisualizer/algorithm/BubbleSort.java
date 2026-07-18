package sortvisualizer.algorithm;

import sortvisualizer.model.SortAlgorithm;

public class BubbleSort extends SortAlgorithm {
    @Override
    public String getName() {
        return "冒泡排序";
    }
    @Override
    protected void doSort() {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            pass++;
            boolean swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {

                if (compare(arr[j], arr[j + 1]) > 0) {
                    swap(j, j + 1);
                    swapped = true;
                }
            }
            int sortedCount = i + 1;
            int sunkIndex = n - 1 - i;
            record(new int[]{sunkIndex}, sortedCount, true,
                    "第 " + pass + " 趟：最大值 " + arr[sunkIndex] + " 已沉到第 "
                            + (sunkIndex + 1) + " 位");

            if (!swapped) {
                break;
            }
        }
    }
}
