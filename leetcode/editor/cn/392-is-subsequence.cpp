/**
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。 

 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而
"aec"不是）。 

 进阶： 

 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？
 

 致谢： 

 特别感谢 @pbrother 添加此问题并且创建所有测试用例。 

 

 示例 1： 

 
输入：s = "abc", t = "ahbgdc"
输出：true
 

 示例 2： 

 
输入：s = "axc", t = "ahbgdc"
输出：false
 

 

 提示： 

 
 0 <= s.length <= 100 
 0 <= t.length <= 10^4 
 两个字符串都只由小写字符组成。 
 

 Related Topics 双指针 字符串 动态规划 👍 890 👎 0

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
    //动态规划 二维数组
//    bool isSubsequence(string s, string t) {
//        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
//        for (int i = 1; i < s.size() + 1; ++i) {
//            for (int j = 1; j < t.size() + 1; ++j) {
//                dp[i][j] = (s[i - 1] == t[j - 1])
//                           ? dp[i - 1][j - 1] + 1
//                           : dp[i][j - 1];
//            }
//        }
//        return dp.back().back() == s.size();
//    }
    //动态规划 一维数组
    bool isSubsequence(string s, string t) {
        vector<int> dp(t.size() + 1, 0);
        for (int i = 1; i < s.size() + 1; ++i) {
            int prev = 0;
            for (int j = 1; j < t.size() + 1; ++j) {
                int temp = dp[j]; // 保存当前 dp[j] 的值
                dp[j] = (s[i - 1] == t[j - 1])
                        ? prev + 1
                        : max(dp[j], dp[j - 1]);
                prev = temp; // 更新 prev
            }
        }
        return dp.back() == s.size();
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