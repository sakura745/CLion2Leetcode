/**
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返
回左旋转两位得到的结果"cdefgab"。 

 

 示例 1： 

 输入: s = "abcdefg", k = 2
输出: "cdefgab"
 

 示例 2： 

 输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

 

 限制： 

 
 1 <= k < s.length <= 10000 
 

 Related Topics 数学 双指针 字符串 👍 398 👎 0

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
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //字符串拼接
/*        string tmp;
        for (int i = n; i < s.size(); ++i) {
            tmp += s[i];
        }
        for (int i = 0; i < n; i++) {
            tmp += s[i];
        }
        return tmp;*/
//三个反转
        reverse(s.begin(), s.begin() + n);//反转前n个
        reverse(s.begin(), s.end());//全反转
        reverse(s.begin(), s.end() - n);//反转前end - n个
        return s;
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