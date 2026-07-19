/*************************************************
 * 917. 仅仅反转字母
 *
 * 题目描述：
 * 给定一个字符串 s，反转其中所有英文字母的位置，
 * 非字母字符保持原来的位置不变。
 *************************************************/
class Solution {
public:
    bool islettle(char a)
    {
        if (a >= 'a' && a <= 'z')
            return true;
        if (a >= 'A' && a <= 'Z')
            return true;
        return false;
    }

    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            while (!islettle(s[left]) && left < right)
                left++;

            while (!islettle(s[right]) && left < right)
                right--;

            swap(s[left++], s[right--]);
        }

        return s;
    }
};

/*************************************************
 * 387. 字符串中的第一个唯一字符
 *
 * 题目描述：
 * 给定一个字符串，找出第一个不重复字符，
 * 返回它的下标；如果不存在，返回 -1。
 *************************************************/
class Solution {
public:
    int firstUniqChar(string s) {

        int arr[26] = {0};

        // 统计每个字符出现次数
        for (auto ch : s)
            arr[ch - 'a']++;

        // 找到第一个出现一次的字符
        for (int i = 0; i < s.size(); i++)
        {
            if (arr[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

/*************************************************
 * 牛客 HJ1 字符串最后一个单词的长度
 *
 * 题目描述：
 * 输入一行字符串，
 * 输出最后一个单词的长度。
 *************************************************/
#include <iostream>
using namespace std;

int main() {

    string s;
    getline(cin, s);

    int p = s.rfind(' ');

    cout << s.size() - p - 1;

    return 0;
}

/*************************************************
 * 125. 验证回文串
 *
 * 题目描述：
 * 给定一个字符串，只保留字母和数字，
 * 忽略大小写，判断是否为回文串。
 *************************************************/
class Solution {
public:
    bool isPalindrome(string s) {

        string ns;

        // 提取字母和数字，并统一转成小写
        for (auto &it : s)
        {
            if ((it >= 'a' && it <= 'z') ||
                (it >= '0' && it <= '9'))
            {
                ns += it;
            }
            else if (it >= 'A' && it <= 'Z')
            {
                ns += (char)(it + 32);
            }
        }

        int left = 0;
        int right = ns.size() - 1;

        while (left < right)
        {
            if (ns[left] != ns[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};

/*************************************************
 * 415. 字符串相加
 *
 * 题目描述：
 * 给定两个非负整数形式的字符串，
 * 返回它们的和。
 *************************************************/
class Solution {
public:
    string addStrings(string num1, string num2) {

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string ret;

        int c = 0;
        int i = 0;

        while (i < num1.size() && i < num2.size())
        {
            c += (num1[i] - '0') + (num2[i] - '0');
            ret += (c % 10) + '0';
            c /= 10;
            i++;
        }

        while (i < num1.size())
        {
            c += num1[i] - '0';
            ret += (c % 10) + '0';
            c /= 10;
            i++;
        }

        while (i < num2.size())
        {
            c += num2[i] - '0';
            ret += (c % 10) + '0';
            c /= 10;
            i++;
        }

        if (c == 1)
            ret += '1';

        reverse(ret.begin(), ret.end());

        return ret;
    }
};

/*************************************************
 * 541. 反转字符串 II
 *
 * 题目描述：
 * 每隔 2k 个字符，
 * 反转前 k 个字符。
 *************************************************/
class Solution {
public:
    void reverse(int left, int right, string &s)
    {
        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }

    string reverseStr(string s, int k) {

        if (s.size() < k)
        {
            reverse(0, s.size() - 1, s);
            return s;
        }

        int left = 0;
        int right = k - 1;

        reverse(left, right, s);

        while (left < s.size())
        {
            left += 2 * k;
            right += 2 * k;

            right = right > s.size() ? s.size() - 1 : right;

            if (left < s.size())
                reverse(left, right, s);
        }

        return s;
    }
};

/*************************************************
 * 557. 反转字符串中的单词 III
 *
 * 题目描述：
 * 反转每个单词，
 * 保留单词顺序和空格位置不变。
 *************************************************/
class Solution {
public:
    void my_reverse(string &s, int left, int right)
    {
        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }

    string reverseWords(string s) {

        int left = 0;
        int right = 0;

        for (; right < s.size(); right++)
        {
            if (s[right] == ' ')
            {
                my_reverse(s, left, right - 1);
                left = right + 1;
            }
        }

        my_reverse(s, left, right - 1);

        return s;
    }
};

/*************************************************
 * 43. 字符串相乘
 *
 * 题目描述：
 * 给定两个字符串表示的大整数，
 * 返回它们相乘后的结果。
 *************************************************/
class Solution {
public:
    string multiply(string num1, string num2) {

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> arr(num1.size() + num2.size() + 1);

        // 模拟竖式乘法
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                arr[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        // 统一处理进位
        for (int i = 0; i < arr.size() - 1; i++)
        {
            arr[i + 1] += arr[i] / 10;
            arr[i] %= 10;
        }

        // 去除高位多余的 0
        int j = arr.size() - 1;
        while (j > 0 && arr[j] == 0)
        {
            arr.pop_back();
            j--;
        }

        string ret;

        for (auto it : arr)
            ret += to_string(it);

        reverse(ret.begin(), ret.end());

        return ret;
    }
};