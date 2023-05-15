/**
编写一个算法来判断一个数 n 是不是快乐数。 

 「快乐数」 定义为： 

 
 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。 
 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。 
 如果这个过程 结果为 1，那么这个数就是快乐数。 
 

 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。 

 

 示例 1： 

 
输入：n = 19
输出：true
解释：
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1
 

 示例 2： 

 
输入：n = 2
输出：false
 

 

 提示： 

 
 1 <= n <= 2³¹ - 1 
 

 Related Topics 哈希表 数学 双指针 👍 1308 👎 0

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
    //是否是快乐数
    int getSum(int& n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> res;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            } else if (res.find(sum) != res.end()) {
                return false;
            } else {
                res.insert(sum);
                n = sum;
            }
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

void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}