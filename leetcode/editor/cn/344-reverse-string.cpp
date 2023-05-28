/**
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。 

 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。 

 

 示例 1： 

 
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
 

 示例 2： 

 
输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"] 

 

 提示： 

 
 1 <= s.length <= 10⁵ 
 s[i] 都是 ASCII 码表中的可打印字符 
 

 Related Topics 双指针 字符串 👍 772 👎 0

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
/*    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {//当s为奇数时，直接跳过。当s为偶数时，交换后自动满足
            s[left] ^= s[right] ^= s[left] ^= s[right];//交换
            left++;
            right--;
        }
    }*/
    //仿照算法reverse函数写的
    void reverseString(vector<char>& s) {
        int fisrt = 0, last = s.size();
        while ((fisrt != last) && (fisrt != --last)) {
            swap(s[fisrt++], s[last]);
        }
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

/*
void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}*/
