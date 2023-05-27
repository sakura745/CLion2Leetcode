/**
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回
这颗 二叉树 。 

 

 示例 1: 
 
 
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]
 

 示例 2: 

 
输入：inorder = [-1], postorder = [-1]
输出：[-1]
 

 

 提示: 

 
 1 <= inorder.length <= 3000 
 postorder.length == inorder.length 
 -3000 <= inorder[i], postorder[i] <= 3000 
 inorder 和 postorder 都由 不同 的值组成 
 postorder 中每一个值都在 inorder 中 
 inorder 保证是树的中序遍历 
 postorder 保证是树的后序遍历 
 

 Related Topics 树 数组 哈希表 分治 二叉树 👍 1025 👎 0

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
/*    TreeNode* recursion(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return nullptr;//虽然题目给了，长度大于等于1，但是还要有，是为了递归到最后需要的
        int rootValue = postorder[postorder.size() - 1];//取后序最后一个元素
        TreeNode* root = new TreeNode(rootValue);
        if (postorder.size() == 1) return root;

        int rootIndex = -1;
        for (rootIndex = 0; rootIndex < inorder.size(); ++rootIndex) {
            if (inorder[rootIndex] == rootValue) break;//找到根节点的位置
        }

        //中序数组上分割左、右子树
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);//左闭右开
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        //后序数组上得到右子树（从中序中得到的左区间和最开始得到的根节点中间的区间）
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootIndex);
        vector<int> rightPostorder(postorder.begin() + rootIndex, postorder.end() - 1*//*减去一个根节点*//*);

        //循环上述过程。递归
        root->left = recursion(leftInorder, leftPostorder);
        root->right = recursion(rightInorder, rightPostorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursion(inorder, postorder);
    }*/
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return nullptr;
        auto root = new TreeNode(postorder.back());
        int rootIndex = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootIndex);
        vector<int> rightPostorder(postorder.begin() + rootIndex, postorder.end() - 1);
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
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