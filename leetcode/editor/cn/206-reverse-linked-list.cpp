/**
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

 
 
 
 
 

 示例 1： 
 
 
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
 

 示例 2： 
 
 
输入：head = [1,2]
输出：[2,1]
 

 示例 3： 

 
输入：head = []
输出：[]
 

 

 提示： 

 
 链表中节点的数目范围是 [0, 5000] 
 -5000 <= Node.val <= 5000 
 

 

 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 

 Related Topics 递归 链表 👍 3146 👎 0

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
    ListNode* recursive(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return recursive(cur, tmp);
    }
    ListNode* reverseList(ListNode* head) {
        return recursive(nullptr, head);

        //双指针
/*        ListNode* cur = head;//cur把链表接过来了，在cur上操作
        ListNode* pre = nullptr;//cur的上一个节点
        ListNode* tmp = nullptr;
        while (cur) {
            //tmp保存cur下一个节点。为了下一次循环找到剩下的节点
            tmp = cur->next;

            //反转列表
            cur->next = pre;

            //两个指针向下一节点移动
            pre = cur;
            cur = tmp;
        }
        return pre;*/
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