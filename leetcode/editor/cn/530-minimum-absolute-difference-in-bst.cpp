/**
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。 

 差值是一个正数，其数值等于两值之差的绝对值。 

 

 示例 1： 
 
 
输入：root = [4,2,6,1,3]
输出：1
 

 示例 2： 
 
 
输入：root = [1,0,48,null,null,12,49]
输出：1
 

 

 提示： 

 
 树中节点的数目范围是 [2, 10⁴] 
 0 <= Node.val <= 10⁵ 
 

 

 注意：本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 相同 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉搜索树 二叉树 👍 463 👎 0

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
    int minValue = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if (!root) return minValue;
        int left = getMinimumDifference(root->left);
        if (pre) minValue > (root->val - pre->val) ? minValue = (root->val - pre->val) : int();
        pre = root;
        int right = getMinimumDifference(root->right);
        return min(left, right);
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
     TreeNode* root = new TreeNode(543);
    root->left = new TreeNode(384);
    root->right = new TreeNode(652);
//    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(445);
//    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(699);
//    root->left->left->left = new TreeNode(7);
//    root->left->left->right  = new TreeNode(2);
//    root->left->right->left  = new TreeNode();
//    root->left->right->right  = new TreeNode();
//    root->right->left->left = new TreeNode();
//    root->right->left->right  = new TreeNode();
//    root->right->right->left  = new TreeNode();
//    root->right->right->right  = new TreeNode(1);

    s.getMinimumDifference(root);
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