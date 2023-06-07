/**
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。 

 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。 

 

 示例 1： 

 
输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 

 示例 2： 

 
输入：nums = [4,4,3,2,1]
输出：[[4,4]]
 

 

 提示： 

 
 1 <= nums.length <= 15 
 -100 <= nums[i] <= 100 
 

 Related Topics 位运算 数组 哈希表 回溯 👍 665 👎 0

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
    //unordered_set
//    vector<int> path;
//    vector<vector<int>> res;
//    void backtracking(vector<int>& nums, int startIndex) {
//        if (path.size() > 1)
//            res.push_back(path);
//        unordered_set<int> used;
//        for (int i = startIndex; i < nums.size(); ++i) {
//            if ((!path.empty()/*防止path为空造成的异常*/ && path.back() > nums[i]) ||
//                used.find(nums[i]) != used.end()/*去重*/)
//                continue;
//            path.push_back(nums[i]);
//            used.insert(nums[i]);
//            backtracking(nums, i + 1);
//            path.pop_back();
//        }
//    }
//public:
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        if (nums.size() == 1) return {};
//        backtracking(nums, 0);
//        return res;
//    }

    //数组
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1)
            res.push_back(path);
        int used[201] = {};
        for (int i = startIndex; i < nums.size(); ++i) {
            if ((!path.empty()/*防止path为空造成的异常*/ && path.back() > nums[i]) ||
                used[nums[i] + 100] != 0/*去重*/)
                continue;
            path.push_back(nums[i]);
            used[nums[i] + 100]++;
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() == 1) return {};
        backtracking(nums, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a = {4,4,4,4,3,2,1};
    s.findSubsequences(a);
    cout << 1;
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