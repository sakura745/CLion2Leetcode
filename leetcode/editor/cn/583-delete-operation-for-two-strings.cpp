/**
给定两个单词 word1 和
 word2 ，返回使得
 word1 和 
 word2 相同所需的最小步数。 

 每步 可以删除任意一个字符串中的一个字符。 

 

 示例 1： 

 
输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
 

 示例 2: 

 
输入：word1 = "leetcode", word2 = "etco"
输出：4
 

 

 提示： 
 

 
 1 <= word1.length, word2.length <= 500 
 word1 和 word2 只包含小写英文字母 
 

 Related Topics 字符串 动态规划 👍 594 👎 0

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
/*    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i < word1.size() + 1; ++i) dp[i][0] = i;
        for (int j = 0; j < word2.size() + 1; ++j) dp[0][j] = j;
        for (int i = 1; i < word1.size() + 1; ++i) {
            for (int j = 1; j < word2.size() + 1; ++j) {
                dp[i][j] = (word1[i - 1] == word2[j - 1])
                                ? dp[i - 1][j - 1]
                                : min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
            }
        }
        return dp.back().back();
    }*/
    //整体 - 2 * 最长公共子序列
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i < word1.size() + 1; ++i) {
            for (int j = 1; j < word2.size() + 1; ++j) {
                dp[i][j] = (word1[i - 1] == word2[j - 1])
                           ? dp[i - 1][j - 1] + 1
                           : max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return word1.size() + word2.size() - 2 * dp.back().back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.minDistance("sea","eat");
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