/**
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。 

 在 S 上反复执行重复项删除操作，直到无法继续删除。 

 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。 

 

 示例： 

 输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有
 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 

 

 提示： 

 
 1 <= S.length <= 20000 
 S 仅由小写英文字母组成。 
 

 Related Topics 栈 字符串 👍 529 👎 0

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
public:
    string removeDuplicates(string s) {
        string res;//用string代替stack
        for (auto& i : s)
            (!res.empty() && i == res.back())
                        ? res.pop_back()
                        : res.push_back(i);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.removeDuplicates("abbaca");
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
