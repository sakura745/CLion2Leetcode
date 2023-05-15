/**
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 

 

 示例 1： 
 
 
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
 

 示例 2： 

 
输入：head = [1], n = 1
输出：[]
 

 示例 3： 

 
输入：head = [1,2], n = 1
输出：[1]
 

 

 提示： 

 
 链表中结点的数目为 sz 
 1 <= sz <= 30 
 0 <= Node.val <= 100 
 1 <= n <= sz 
 

 

 进阶：你能尝试使用一趟扫描实现吗？ 

 Related Topics 链表 双指针 👍 2532 👎 0

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dum = new ListNode(-1, head);
        ListNode* fast = dum;
        ListNode* slow = dum;
        while (n--) fast = fast->next;//快指针偷跑，保持快满指针的距离

        //根据1<=n<=sz，有快指针不会指向空指针，所以不需要有fast != null的条件
        while (fast->next != nullptr) {

            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;//释放内存
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