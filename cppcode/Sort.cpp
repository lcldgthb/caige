#include<iostream>
using namespace std;
void printarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//插入排序
void insertsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
//希尔排序
void shellsort(int arr[],int n)
{
        for(int gap=n/2;gap>0;gap/=2)//增量gap每次减半
        {
            for(int i=gap;i<n;i++)//从gap开始，依次对每个元素进行插入排序
            {
                //小的插入排序
                int key=arr[i];
                int j=i-gap;//j是待插入元素的前一个元素的索引
                while(j>=0&&arr[j]>key)//将大于key的元素向后移动gap个位置
                {
                    arr[j+gap]=arr[j];
                    j-=gap;
                }
                arr[j+gap]=key;
            }
        }
}
//选择排序
void selectsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
}
// 堆排序
void adjustdown(int arr[],int n,int i)//向下调整堆，使以i为根的子树满足大根堆的性质
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        adjustdown(arr,n,largest);
    }
}
void heapsort(int arr[],int n)
{
    //构建大根堆
    for(int i=n/2-1;i>=0;i--)
    {
        adjustdown(arr,n,i);
    }
    //将堆顶元素与末尾元素交换，并调整堆
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        adjustdown(arr,i,0);
    }
}
//向下调整，
//              数组      数组大小 根节点索引
void adjustdown1(int arr[],int n,int i)
{
    int parent=i;
    int left=2*i+1;
    int right=2*i+2;   
    if(left<n&&arr[left]<arr[parent])
    {
        parent=left;
    }
    if(right<n&&arr[right]<arr[parent])
    {
        parent=right;
    }
    if(parent!=i)
    {
        swap(arr[i],arr[parent]);
        adjustdown1(arr,n,parent);
    }
    
}
void heapsort1(int arr[],int n)
{
    //建堆，升序，建大根堆
    for(int i=n/2-1;i>=0;i--)
    {
        adjustdown1(arr,n,i);
    }

}
void selectsort1(int arr[],int n)
{
    //每次选择最小的元素放到前面
    for(int i=0;i<n-1;i++)
    {
        int minval=arr[i];
        int minindex=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<minval)
            {
                minval=arr[j];
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
}
void insertsort1(int arr[],int n)
{
    //默认第一个元素已经有序
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                j--;
            }
            else
            {
                break;
            }
        }

    }
}
void test()
{
    int arr[10]={9,8,7,6,5,4,3,2,1,0};
    printarr(arr,10);
    insertsort(arr,10);
    printarr(arr,10);
}
int main()
{
    test();
    return 0;
}