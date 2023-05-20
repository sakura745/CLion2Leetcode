/**
给定一个非空的字符串
 s ，检查是否可以通过由它的一个子串重复多次构成。 

 

 示例 1: 

 
输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。
 

 示例 2: 

 
输入: s = "aba"
输出: false
 

 示例 3: 

 
输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 

 

 提示： 

 
 

 
 1 <= s.length <= 10⁴ 
 s 由小写英文字母组成 
 

 Related Topics 字符串 字符串匹配 👍 967 👎 0

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
/*void printLinkedList(ListNode* head);*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //移动匹配
/*    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);
        return ss.find(s) != string::npos ? true : false;
    }*/
    void getNext(const string& s, int* next) {
        next[0] = -1;
        if (s.size() == 1) return;
        next[1] = 0;
        int i = 2;
        int cn = 0;
        while (i < s.size()) {
            if (s[i - 1] == s[cn]) {
                next[i++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[i++] = 0;
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        int len = s.size();

        int next[len + 1];//多一位是因为next数组的构造不同，需要整个字符串的next数组

        getNext(s + 'A'/*只要加一个不满足s要求的字符都行*/, next);
        //比如字符串是"aba",变成"abaA"

        //return (next[len] != 0/*等于0，直接跳出为false*/ && len % (len - next[len]) == 0) ? true : false;
        //简化为
        return next[len] != 0/*等于0，直接跳出为false*/&& len % (len - next[len]) == 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    cout << s.repeatedSubstringPattern("abac");
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

/*
void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}*/
