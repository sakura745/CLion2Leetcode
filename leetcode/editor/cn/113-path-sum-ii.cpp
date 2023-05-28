/**
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。 

 叶子节点 是指没有子节点的节点。 

 
 
 
 
 

 示例 1： 
 
 
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
 

 示例 2： 
 
 
输入：root = [1,2,3], targetSum = 5
输出：[]
 

 示例 3： 

 
输入：root = [1,2], targetSum = 0
输出：[]
 

 

 提示： 

 
 树中节点总数在范围 [0, 5000] 内 
 -1000 <= Node.val <= 1000 
 -1000 <= targetSum <= 1000 
 

 Related Topics 树 深度优先搜索 回溯 二叉树 👍 977 👎 0

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
/*    vector<vector<int>> res;
    vector<int> res1;
    void recursion(TreeNode* cur, int sum) {
        if (!cur->left && !cur->right) {
            //?的左右操作符返回类型要相同。void() no-op
            (sum == 0) ? res.push_back(res1) : void();
            return;
        }
        if (cur->left){
            res1.push_back(cur->left->val);
            recursion(cur->left, sum - cur->left->val);
            res1.pop_back();//回溯
        }
        if (cur->right){
            res1.push_back(cur->right->val);
            recursion(cur->right, sum - cur->right->val);
            res1.pop_back();//回溯
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        //对头节点的处理
        res1.push_back(root->val);
        recursion(root, targetSum - root->val);

        return res;
    }*/
    //迭代
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        stack<pair<TreeNode*, vector<int>>> stk;
        stk.emplace(root, root->val);
        vector<vector<int>> res;
        while (!stk.empty()) {
            auto [node, path] = stk.top();
            stk.pop();
            if (!node->left && !node->right && accumulate(path.begin(), path.end(), 0) == targetSum) {
                res.push_back(path);
            }
            if (node->right) {
                vector<int> newPath = path;
                newPath.push_back(node->right->val);
                stk.emplace(node->right, newPath);
            }
            if (node->left) {
                vector<int> newPath = path;
                newPath.push_back(node->left->val);
                stk.emplace(node->left, newPath);
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
    s.pathSum(root, 22);
    
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