/**
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建: 

 
 创建一个根节点，其值为 nums 中的最大值。 
 递归地在最大值 左边 的 子数组前缀上 构建左子树。 
 递归地在最大值 右边 的 子数组后缀上 构建右子树。 
 

 返回 nums 构建的 最大二叉树 。 

 

 示例 1： 
 
 
输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。
 

 示例 2： 
 
 
输入：nums = [3,2,1]
输出：[3,null,2,null,1]
 

 

 提示： 

 
 1 <= nums.length <= 1000 
 0 <= nums[i] <= 1000 
 nums 中的所有整数 互不相同 
 

 Related Topics 栈 树 数组 分治 二叉树 单调栈 👍 689 👎 0

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
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //递归
/*    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;//终止条件
        int maxValue = nums[0], maxIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] > maxValue ? maxValue = nums[i], maxIndex = i : int{};
        }
        auto root = new TreeNode(maxValue);//中
        vector<int> left(nums.begin(), nums.begin() + maxIndex);
        root->left = constructMaximumBinaryTree(left);//左
        vector<int> right(nums.begin() + maxIndex + 1, nums.end());
        root->right = constructMaximumBinaryTree(right);//右
        return root;
    }*/
    //递归 + 算法
/*    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        auto maxIter = max_element(nums.begin(), nums.end());
        auto root = new TreeNode(*maxIter);
        vector<int> left(nums.begin(), maxIter);
        root->left = constructMaximumBinaryTree(left);
        vector<int> right(maxIter + 1, nums.end());
        root->right = constructMaximumBinaryTree(right);
        return root;
    }*/
    TreeNode* recursion(vector<int>& nums, int startIndex, int endIndex) {
        if (endIndex == startIndex) return nullptr;//终止条件
        int maxValue = nums[startIndex], maxIndex = startIndex;
        for (int i = startIndex; i < endIndex; ++i) {
            nums[i] > maxValue ? maxValue = nums[i], maxIndex = i : int{};
        }
        auto cur = new TreeNode(maxValue);
        cur->left = recursion(nums, startIndex, maxIndex);
        cur->right = recursion(nums, maxIndex + 1, endIndex);
        return cur;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recursion(nums, 0, nums.size());
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
     TreeNode* root = new TreeNode(5);
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
    root->right->right->right  = new TreeNode(1);
    vector<int> a{3,2,1,6,0,5};
    s.constructMaximumBinaryTree(a);
    
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