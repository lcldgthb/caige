package sortvisualizer.algorithm;

import sortvisualizer.model.SortAlgorithm;

public class ShellSort extends SortAlgorithm {

    @Override
    public String getName() {
        return "希尔排序";
    }

    @Override
    protected void doSort() {
        int n = arr.length;
        if (n <= 1) {
            return;
        }


        for (int gap = n / 2; gap >= 1; gap /= 2) {
            pass++;


            for (int i = gap; i < n; i++) {
                int current = arr[i];
                int j = i - gap;
                while (j >= 0 && compare(arr[j], current) > 0) {
                    arr[j + gap] = arr[j];
                    swapCount++;
                    j -= gap;
                }
                arr[j + gap] = current;
            }



            int sortedCount = (gap == 1) ? n : 0;
            record(new int[0], sortedCount,
                    "第 " + pass + " 趟：增量 gap = " + gap + " 的分组插入完成");
        }
    }
}
