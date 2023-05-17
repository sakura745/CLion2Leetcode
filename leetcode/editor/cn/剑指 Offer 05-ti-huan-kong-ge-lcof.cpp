/**
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 

 

 示例 1： 

 输入：s = "We are happy."
输出："We%20are%20happy." 

 

 限制： 

 0 <= s 的长度 <= 10000 

 Related Topics 字符串 👍 483 👎 0

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
    string replaceSpace(string s) {
        int cnt = 0;//计算空格次数
        for (auto& i : s) {
            if (i == ' ') {
                cnt++;
            }
        }
        s.resize(s.size() + cnt * 2);//扩容
        //slow指向原来数组长度结尾，fast指向新数组的结尾。
        int slow = s.size() - 1 - 2 * cnt, fast = s.size() - 1;//从后往遍历
        while (slow < fast) {//当两指针相遇，表示没有空格了，直接跳过就行。
            if (s[slow] != ' ') {
                s[fast--] = s[slow--];//原来赋给新的，都往前移一位
            } else {
                slow--;
                s[fast--] = '0';
                s[fast--] = '2';
                s[fast--] = '%';
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
    auto x = s.replaceSpace("We are happy.")/*function_name*/;
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
