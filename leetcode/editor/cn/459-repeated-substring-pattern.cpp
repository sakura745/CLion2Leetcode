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
    //移动匹配
/*    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);
        return ss.find(s) != string::npos;
    }*/
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
    bool repeatedSubstringPattern(string s) {
        int length = s.size();
        vector<int> next(length + 1);//+1是因为next数组是所表示的为当前位置之前的字符串
        getNext(s + 'A'/*类似于哨兵的作用，不满足于s要求的字符就行*/, next);
        //比如s为aba，则为abaA

        return next[length] > 0 && length % (length - next[length]) == 0;
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
