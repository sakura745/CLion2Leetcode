/**
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 

 回文串 是正着读和反着读都一样的字符串。 

 

 示例 1： 

 
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
 

 示例 2： 

 
输入：s = "a"
输出：[["a"]]
 

 

 提示： 

 
 1 <= s.length <= 16 
 s 仅由小写英文字母组成 
 

 Related Topics 字符串 动态规划 回溯 👍 1523 👎 0

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
    vector<string> path;
    vector<vector<string>> res;
    void backtracking(const string& s, int startIndex) {
        if (startIndex == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); ++i) {
            if (isPalindrome(s, startIndex, i)/*[startIndex, i]是分割区间*/)
                path.push_back(s.substr(startIndex, i - startIndex + 1/*substr第二个参数是子串的长度，长度至少为1*/));
            else
                continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(const std::string& s, int l, int r) {//回文子串
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
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