/**
给定二叉搜索树（BST）的根节点
 root 和要插入树中的值
 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。 

 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回 任意有效的结果 。 

 

 示例 1： 
 
 
输入：root = [4,2,7,1,3], val = 5
输出：[4,2,7,1,3,5]
解释：另一个满足题目要求可以通过的树是：

 

 示例 2： 

 
输入：root = [40,20,60,10,30,50,70], val = 25
输出：[40,20,60,10,30,50,70,null,null,25]
 

 示例 3： 

 
输入：root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
输出：[4,2,7,1,3,5]
 

 

 提示： 

 
 树中的节点数将在
 [0, 10⁴]的范围内。
 
 -10⁸ <= Node.val <= 10⁸ 
 所有值 
 Node.val 是 独一无二 的。 
 -10⁸ <= val <= 10⁸ 
 保证 val 在原始BST中不存在。 
 

 Related Topics 树 二叉搜索树 二叉树 👍 491 👎 0

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
//    TreeNode* insertIntoBST(TreeNode* root, int val) {
//        //递归到节点为空，也是终止条件，就是插入节点的时机。插入节点之后，返回该节点给上一层
//        if (!root) return new TreeNode(val);
//        val < root->val ? root->left = insertIntoBST(root->left, val)/*递归进入节点，返回该节点*/ :
//                          root->right = insertIntoBST(root->right, val);
//        return root;
//    }
    //迭代
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);//空节点
        auto cur = root;//用于遍历
        auto tmp = root;//用于记录非空cur最后一个值
        while (cur) {
            tmp = cur;
            cur->val > val ? cur = cur->left : cur = cur->right;
        }
        tmp->val > val ? tmp->left = new TreeNode(val) :
                         tmp->right = new TreeNode(val);
        return root;
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
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(20);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(30);
  root->right->left = new TreeNode(50);
    root->right->right = new TreeNode(70);
/*       root->left->left->left = new TreeNode(7);
    root->left->left->right  = new TreeNode(2);
    root->left->right->left  = new TreeNode();
    root->left->right->right  = new TreeNode();
    root->right->left->left = new TreeNode();
    root->right->left->right  = new TreeNode();
    root->right->right->left  = new TreeNode();
    root->right->right->right  = new TreeNode(1);*/
    s.insertIntoBST(root, 25);
    
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