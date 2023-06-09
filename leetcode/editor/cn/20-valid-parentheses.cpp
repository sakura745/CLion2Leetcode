/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 

 有效字符串需满足： 

 
 左括号必须用相同类型的右括号闭合。 
 左括号必须以正确的顺序闭合。 
 每个右括号都有一个对应的相同类型的左括号。 
 

 

 示例 1： 

 
输入：s = "()"
输出：true
 

 示例 2： 

 
输入：s = "()[]{}"
输出：true
 

 示例 3： 

 
输入：s = "(]"
输出：false
 

 

 提示： 

 
 1 <= s.length <= 10⁴ 
 s 仅由括号 '()[]{}' 组成 
 

 Related Topics 栈 字符串 👍 3932 👎 0

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
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;//剪枝
        stack<int> stack1;//如果是int，有个类型转换。char也可以
        for (auto& i : s) {
            if (i == '(') stack1.push(')');
            else if (i == '[') stack1.push(']');
            else if (i == '{') stack1.push('}');
            else if (stack1.empty()/*遍历过程中，栈为空，表示有多余的右括号*/ || stack1.top() != i/*左右括号不匹配*/) return false;
            else/*包含了i为})]的情况*/ stack1.pop();
        }
        //遍历结束，栈不为空，表示有多余的左括号
        //return !stack.empty() ? false : true;
        return /*简化成*/stack1.empty();
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

/*void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}*/