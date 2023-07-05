/**
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是： 

 
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 

 给定 n ，请计算 F(n) 。 

 

 示例 1： 

 
输入：n = 2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 

 示例 2： 

 
输入：n = 3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 

 示例 3： 

 
输入：n = 4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 

 

 提示： 

 
 0 <= n <= 30 
 

 Related Topics 递归 记忆化搜索 数学 动态规划 👍 650 👎 0

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
/*struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};*/
//void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //动态规划 一维数组
    int fib(int n) {
        vector<int> dp{0, 1};
        dp.resize(n + 1);
        for (int i = 2; i < n + 1; ++i) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp.back();
    }
    //动态规划 滚动数组
/*    int fib(int n) {
        if (n <= 1) return n;
        int val1 = 0, val2 = 1;
        while(n-- >= 2) {
            int sum = val2 + val1;
            val1 = val2;
            val2 = sum;
        }
        return val2;
    }*/
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.fib(2);
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
/*     TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode();
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right  = new TreeNode(2);
    root->left->right->left  = new TreeNode();
    root->left->right->right  = new TreeNode();
    root->right->left->left = new TreeNode();
    root->right->left->right  = new TreeNode();
    root->right->right->left  = new TreeNode();
    root->right->right->right  = new TreeNode(1);*/
    
    
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