/**
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果
 needle 不是 haystack 的一部分，则返回 -1 。 

 

 示例 1： 

 
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
 

 示例 2： 

 
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 

 

 提示： 

 
 1 <= haystack.length, needle.length <= 10⁴ 
 haystack 和 needle 仅由小写英文字符组成 
 

 Related Topics 双指针 字符串 字符串匹配 👍 1866 👎 0

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
//void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    void getNext(const string& pattern, vector<int>& next) {
        next[0] = -1;
        if (next.size() == 1) return;
        next[1] = 0;
        int idxP = 2, nextValue = 0;
        while (idxP < pattern.size()) {
            if (pattern[idxP - 1] == pattern[nextValue]) {
                next[idxP++] = ++nextValue;
            } else if (nextValue > 0) {
                nextValue = next[nextValue];
            } else {
                next[idxP++] = 0;
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        getNext(needle, next);
        int idxH = 0, idxN = 0;
        while (idxH < haystack.size() && idxN < needle.size()) {
            if (haystack[idxH] == needle[idxN]) {
                idxN++;
                idxH++;
            } else if (idxN > 0) {
                idxN = next[idxN];
            } else {
                idxH++;
            }
        }
        return idxN == needle.size() ? idxH - idxN : -1;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    cout << s.strStr("a", "a");

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

//void printLinkedList(ListNode* head) {
//    if(head == nullptr) return;
//    while(head->next != nullptr){//为了调整输出中 "->" 的位置
//        cout << head->val << " -> ";
//        head = head->next;
//    }
//    cout << head->val << endl;//同上
//}