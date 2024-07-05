/**
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。 

 回文字符串 是正着读和倒过来读一样的字符串。 

 子字符串 是字符串中的由连续字符组成的一个序列。 

 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 

 

 示例 1： 

 
输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
 

 示例 2： 

 
输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 

 

 提示： 

 
 1 <= s.length <= 1000 
 s 由小写英文字母组成 
 

 Related Topics 字符串 动态规划 👍 1183 👎 0

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
    //动态规划
//    int countSubstrings(string s) {
//        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//        int res = 0;
//        for (int i = s.size() - 1; i >= 0; --i) {
//            for (int j = i/*保证j >= i*/; j < s.size(); ++j) {
//                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
//                    ++res;
//                    dp[i][j] = true;//用来推断dp[i - 1][j + 1]是否为回文的
//                }
//            }
//        }
//        return res;
//    }
    //双指针
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += extend(s, i, i, s.size()); // 以i为中心
            res += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
        }
        return res;
    }
    int extend(const string& s, int l, int r, int n) {
        int res = 0;
        while (l >= 0 && r < n && s[l--] == s[r++]) {
            ++res;
        }
        return res;
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