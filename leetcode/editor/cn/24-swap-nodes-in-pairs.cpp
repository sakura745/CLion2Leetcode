/**
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。 

 

 示例 1： 
 
 
输入：head = [1,2,3,4]
输出：[2,1,4,3]
 

 示例 2： 

 
输入：head = []
输出：[]
 

 示例 3： 

 
输入：head = [1]
输出：[1]
 

 

 提示： 

 
 链表中节点的数目在范围 [0, 100] 内 
 0 <= Node.val <= 100 
 

 Related Topics 递归 链表 👍 1823 👎 0

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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dum = new ListNode(-1, head);//虚拟头结点
        ListNode* cur = dum;//遍历节点
        while (cur->next != nullptr && cur->next->next != nullptr) {//区分奇偶
            ListNode* tmp = cur->next;//保存1节点防止丢失
            ListNode* tmp2 = tmp->next->next;//保存3节点
            cur->next = cur->next->next;//dum->2
            cur->next->next = tmp;//2->1
            tmp->next = tmp2;//1->3
            cur = cur->next->next;//更新cur位置
        }
        return dum->next;
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