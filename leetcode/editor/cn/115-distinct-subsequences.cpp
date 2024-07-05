/**
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。 

 题目数据保证答案符合 32 位带符号整数范围。 

 

 示例 1： 

 
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit 

 示例 2： 

 
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
babgbag
babgbag
babgbag
babgbag
babgbag
 

 

 提示： 

 
 1 <= s.length, t.length <= 1000 
 s 和 t 由英文字母组成 
 

 Related Topics 字符串 动态规划 👍 1058 👎 0

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
//    int numDistinct(string s, string t) {
//        vector<vector<unsigned/*int会溢出*/>> dp(s.size() + 1, vector<unsigned>(t.size() + 1, 0));
//        for (auto& tmp : dp) {
//            tmp[0] = 1;//初始化dp[i][0]
//        }
//        for (int i = 1; i < s.size() + 1; ++i) {
//            for (int j = 1; j < t.size() + 1; ++j) {
//                dp[i][j] = (s[i - 1] == t[j - 1])
//                            ? dp[i - 1][j - 1] + dp[i - 1][j]
//                            : dp[i - 1][j];
//            }
//        }
//        return dp.back().back();
//    }
    //动态规划 一维数组
    int numDistinct(string s, string t) {
        vector<unsigned> dp(t.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            int prev = 1;
            for (int j = 1; j <= t.size(); j++) {
                int temp = dp[j];
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = prev + dp[j];
                }
                prev = temp;
            }
        }
        return dp.back();
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