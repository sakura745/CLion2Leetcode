/**
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

 

 示例 1： 
 
 
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
 

 示例 2： 

 
输入：head = [], val = 1
输出：[]
 

 示例 3： 

 
输入：head = [7,7,7,7], val = 7
输出：[]
 

 

 提示： 

 
 列表中的节点数目在范围 [0, 10⁴] 内 
 1 <= Node.val <= 50 
 0 <= val <= 50 
 

 Related Topics 递归 链表 👍 1246 👎 0

*/
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* generateRandomLinkedList(const int& MaxSize, const int& MaxValue);
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dum = new ListNode(-1, head);//虚拟头结点
        ListNode* cur = dum;//用作遍历链表
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;//回收cur->next
                cur->next = cur->next->next;
                delete tmp;//回收cur->next
            } else {
                cur = cur->next;//指向下一个
            }
        }

        //回收dum
        head = dum->next;
        delete dum;

        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    vector<int> a /*initilization*/;
//    auto x = s. /*function_name*/;
//    cout << x << endl;
    
//    ListNode* head = generateRandomLinkedList(MaxSize, MaxValue);
//    auto x = s. /*function_name*/;
    ListNode* text = new ListNode(7);
    text->next = new ListNode(7);
    text->next->next = new ListNode(7);
    text->next->next->next = new ListNode(7);
    text->next->next->next->next = new ListNode(7);
    text->next->next->next->next->next = new ListNode(7);
//    text->next->next->next->next->next->next = new ListNode(6);
    s.removeElements(text, 7);
    printLinkedList(text);
    
    return 0;
}

ListNode* generateRandomLinkedList(const int& MaxSize, const int& MaxValue) {
    srand(time(0));
    ListNode* dum = new ListNode(-1);//define dummy node
    ListNode* ptr = dum;//using generate Linked List
    for(int i = 0; i < MaxSize; i++){
        ptr->next = new ListNode(rand() % MaxValue + 1);//赋值
        ptr = ptr->next;//下移
    }
    ptr = dum->next;//生成List之后，将ptr设为linkedlist 的head node
    delete dum;
    return ptr;
}

void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}