#include<iostream>
using namespace std;
 int change(int n)
    {
        int ret=0;
        while(n)
        {
            int x=n%10;
            ret+=(x*x);
            n/=10;
        }
        return ret;
    }
    
void test()
{
    change(10);
    cout<<change(10)<<endl;
}
int main()
{
    test();
    return 0;
}
/*
/*
 * 题目：快乐数 (LeetCode 202)
 * 编写一个算法判断一个数 n 是不是快乐数。
 * 快乐数定义：每次将数字替换为其各位数字的平方和，重复这个过程，
 * 如果最终能得到 1，则是快乐数；如果陷入无限循环且始终得不到 1，则不是。
 *
 * 解题思路：快慢指针 (Floyd 判圈算法)
 * - 由于求平方和的过程要么最终到 1，要么进入一个不包含 1 的循环。
 *   问题转化为检测链表中是否存在环（且环点是否为 1）。
 * - 使用两个指针 slow 和 fast，初始都指向 n。
 *   - slow 每次走一步（调用一次 change）
 *   - fast 每次走两步（调用两次 change）
 * - 如果过程中任一指针达到 1，说明是快乐数，返回 true。
 * - 如果快慢指针相遇（相等）且值不为 1，说明进入了无 1 的循环，返回 false。
 * - 时间复杂度 O(log n) 量级，空间复杂度 O(1)。
 
class Solution {
    // 辅助函数：计算一个数各位数字的平方和
    int change(int n) {
        int ret = 0;
        while (n) {
            int x = n % 10;      // 取出最后一位
            ret += (x * x);      // 累加平方
            n /= 10;             // 去掉最后一位
        }
        return ret;
    }
public:
    bool isHappy(int n) {
        int fast = n;   // 快指针，每次走两步
        int slow = n;   // 慢指针，每次走一步
        while (true) {
            // 途中任一指针到达 1，说明是快乐数
            if (fast == 1 || slow == 1)
                return true;
            
            // 快指针移动两步
            fast = change(fast);
            fast = change(fast);
            // 慢指针移动一步
            slow = change(slow);
            
            // 若两指针相遇且不为 1，说明进入了无限循环且不是快乐数
            if (fast == slow && fast != 1)
                return false;
        }
    }
};

/*
 * 题目：复写零 (LeetCode 1089)
 * 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，
 * 并将其余的元素向右平移。注意：不要超过数组长度写入元素，必须原地修改。
 *
 * 解题思路：两次遍历，双指针（快慢指针模拟 + 反向填充）
 * 1. 第一次遍历（模拟复写）：
 *    - slow 指针逐个扫描原数组元素，fast 指针模拟在结果数组中的下标。
 *    - 当 fast < n 时，若 arr[slow] == 0，fast 前进两步（复写两个零），
 *      否则 fast 前进一步；同时 slow 前进一步。
 *    - 循环结束后，slow 指向原数组中最后一个会被保留的元素之后的位置。
 * 2. 边界处理：
 *    - 如果 fast == n+1，说明原数组中最后一个零在复写时会超出数组右边界，
 *      只能保留一个零。此时将数组最后一个元素直接置为 0，
 *      并回退指针：fast 指向 n-1，slow 回退一位。
 * 3. 第二次遍历（从后向前原地填充）：
 *    - 利用 slow 从后向前遍历原数组，fast 从结果数组末尾向前填充。
 *    - 若 arr[slow-1] == 0，则在 arr[fast-1] 和 arr[fast-2] 处放两个 0，
 *      fast 减 2，slow 减 1。
 *    - 否则将 arr[slow-1] 复制到 arr[fast-1]，fast 和 slow 各减 1。
 *    - 从后向前操作保证了未处理的元素不会被覆盖。
 * - 时间复杂度 O(n)，空间复杂度 O(1)。
 *
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int fast = 0; // 快指针，模拟复写零后在结果数组中的下标
        int slow = 0; // 慢指针，遍历原数组

        // 第一遍：模拟复写，找到原数组中最后一个会被保留的元素
        while (fast < n) {
            if (arr[slow] == 0) {
                fast += 2; // 遇到0，结果中会放两个0，快指针前进两步
            } else {
                fast += 1; // 非0元素，结果中放一个，快指针前进一步
            }
            slow++; // 原数组指针前进一步
        }

        // 边界情况：模拟结束后 fast == n+1，说明最后的0复写会越界一个位置
        if (fast == n + 1) {
            arr[n - 1] = 0;   // 数组最后一个元素强制置0（只能放下一个0）
            fast = n - 1;     // 修正 fast 指针到最后一个有效下标
            slow--;           // slow 回退，跳过这个导致越界的0
        }

        // 第二遍：从后向前填充，避免覆盖未处理的元素
        while (slow > 0) {
            if (arr[slow - 1] == 0) {
                // 原数组中是0，结果中连续放两个0
                arr[fast - 1] = 0;
                arr[fast - 2] = 0;
                fast -= 2;     // 填充了两个位置
            } else {
                // 非0元素直接复制
                arr[fast - 1] = arr[slow - 1];
                fast -= 1;     // 填充了一个位置
            }
            slow--; // 原数组指针前移
        }
    }
};

/*
 * 题目：移动零 (LeetCode 283)
 * 给定一个数组 nums，将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 要求：必须在不复制数组的情况下原地对数组进行操作。
 *
 * 解题思路：双指针 (快慢指针)
 * - dest：慢指针，指向已处理好的非零元素序列的最后一个位置（初始 -1）。
 * - cur：快指针，用于遍历整个数组（初始 0）。
 * - 遍历过程中：
 *   1. 若 nums[cur] != 0，说明遇到非零元素，需要将其交换到前面。
 *      先将 dest 后移一位 (++dest)，然后交换 nums[cur] 与 nums[dest]，
 *      最后 cur 后移一位 (cur++)。
 *   2. 若 nums[cur] == 0，则不做交换，只将 cur 后移一位，跳过该零元素。
 * - 整个过程保证了非零元素的相对顺序，且所有零被“挤”到数组末尾。
 * - 时间复杂度 O(n)，空间复杂度 O(1)。
 *
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dest = -1; // 慢指针，指向已处理好的非零序列末尾
        int cur = 0;   // 快指针，用于扫描数组
        while (cur < nums.size()) {
            if (nums[cur] != 0) {
                // 当前元素非零：dest向前移动，然后与cur交换，将非零元素归位
                swap(nums[cur++], nums[++dest]);
            } else {
                // 当前元素为零：仅移动快指针，跳过
                cur++;
            }
        }
    }
};
*/