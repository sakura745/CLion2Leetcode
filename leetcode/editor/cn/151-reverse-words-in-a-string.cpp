/**
给你一个字符串 s ，请你反转字符串中 单词 的顺序。 

 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。 

 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。 

 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。 

 

 示例 1： 

 
输入：s = "the sky is blue"
输出："blue is sky the"
 

 示例 2： 

 
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。
 

 示例 3： 

 
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 

 

 提示： 

 
 1 <= s.length <= 10⁴ 
 s 包含英文大小写字母、数字和空格 ' ' 
 s 中 至少存在一个 单词 
 

 
 

 

 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。 

 Related Topics 双指针 字符串 👍 871 👎 0

*/
#include<bits/stdc++.h>

using namespace std;

/*struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};*/
void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void removeSpaces(string& s) {//去除空格
        int slow = 0;//导出新字符串的指针
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {//跳过单词空格，进入双指针操作

                //用slow指针给每个单词前加一个空格
                if (slow != 0/*除了是第一个单词*/) s[slow++] = ' ';

                //给新字符串赋值
                while (i < s.size()/*防止越界*/ && s[i] != ' '/*当有空格跳出循环，即单词完整输入后*/) {
                    s[slow++] = s[i++];
                }
            }
        }

        //slow返回的不是新字符串下标，如果是下标，应为resize(slow + 1).
        //执行到赋值单词的最后一步是slow++，额外加了1。所以resize(slow)
        s.resize(slow);
    }
    void reverse(string& s, int left, int right) {//左闭右闭区间
        while (left < right) {
            s[left] ^= s[right] ^= s[left] ^= s[right];
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        removeSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;//每个单词的起点
        for (int i = 0; i <= s.size(); ++i) {//i=size是为了让最后一个单词也满足reverse区间
            if (s[i] == ' ' || i == s.size()/*最后一个单词*/) {
                reverse(s, start, i - 1);
                start = i + 1;//更新起点
            }
        }
        return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    vector<int> a /*initilization*/;
//    auto x = s. /*function_name*/;
//    cout << x << endl;
    /*    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(6);
    test->next->next->next = new ListNode(3);
    test->next->next->next->next = new ListNode(4);
    test->next->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next->next = new ListNode(6);*/
//    ListNode* head = generateRandomLinkedList(MaxSize, MaxValue);
//    auto x = s. /*function_name*/;
    
    
    
    return 0;
}

void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}