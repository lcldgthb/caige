package sortvisualizer.model;

import java.util.ArrayList;
import java.util.List;

public abstract class SortAlgorithm {


    protected int[] arr;


    protected int compareCount;


    protected int swapCount;


    protected List<sortvisualizer.model.SortStep> steps;


    protected int pass;












    public final List<sortvisualizer.model.SortStep> sort(int[] data) {

        this.arr = data.clone();
        this.compareCount = 0;
        this.swapCount = 0;
        this.pass = 0;
        this.steps = new ArrayList<>();


        record(new int[0], 0, "初始状态，等待排序");


        doSort();


        recordFinal();

        return steps;
    }





    protected abstract void doSort();


    public abstract String getName();









    protected int compare(int a, int b) {
        compareCount++;
        return Integer.compare(a, b);
    }




    protected void swap(int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        swapCount++;
    }









    protected void record(int[] highlightIndices, int sortedCount, String description) {
        steps.add(new sortvisualizer.model.SortStep(arr, highlightIndices, sortedCount,
                pass, compareCount, swapCount, description));
    }










    protected void record(int[] highlightIndices, int sortedCount,
                          boolean sortedFromEnd, String description) {
        steps.add(new sortvisualizer.model.SortStep(arr, highlightIndices, sortedCount, sortedFromEnd,
                pass, compareCount, swapCount, description));
    }




    protected void recordFinal() {
        steps.add(new sortvisualizer.model.SortStep(arr, new int[0], arr.length,
                pass, compareCount, swapCount,
                "排序完成！共 " + pass + " 趟，比较 " + compareCount
                        + " 次，交换 " + swapCount + " 次"));
    }
}
