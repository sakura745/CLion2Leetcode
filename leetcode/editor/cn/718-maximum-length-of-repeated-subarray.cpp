/**
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。 

 

 示例 1： 

 
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
 

 示例 2： 

 
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
 

 

 提示： 

 
 1 <= nums1.length, nums2.length <= 1000 
 0 <= nums1[i], nums2[i] <= 100 
 

 Related Topics 数组 二分查找 动态规划 滑动窗口 哈希函数 滚动哈希 👍 950 👎 0

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
    //二维数组
//    int findLength(vector<int>& nums1, vector<int>& nums2) {
//        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
//        int res = 0;
//        for (int i = 1; i <= nums1.size(); ++i) {
//            for (int j = 1; j <= nums2.size(); ++j) {
//                if (nums1[i - 1] == nums2[j - 1]) {
//                    dp[i][j] = dp[i - 1][j - 1] + 1;
//                }
//                res = max(res, dp[i][j]);
//            }
//        }
//        return res;
//    }
    //一维数组
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums2.size() + 1, 0);
        int res = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = nums2.size(); j > 0; --j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else {
                    dp[j] = 0;//压缩数组
                }
                res = max(res, dp[j]);
            }
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