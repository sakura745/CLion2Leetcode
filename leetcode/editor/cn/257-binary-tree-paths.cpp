/**
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。 

 叶子节点 是指没有子节点的节点。 

 示例 1： 
 
 
输入：root = [1,2,3,null,5]
输出：["1->2->5","1->3"]
 

 示例 2： 

 
输入：root = [1]
输出：["1"]
 

 

 提示： 

 
 树中节点的数目在范围 [1, 100] 内 
 -100 <= Node.val <= 100 
 

 Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 960 👎 0

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
    //递归 前序遍历 回溯
/*    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res) {
        path.push_back(cur->val);//中
        if (!cur->left && !cur->right) {//终止条件
            string tmp;
            //处理前size-1个元素，留下最后一个元素。因为最后一个元素没有"->"
            for (int i = 0; i < path.size() - 1; ++i) {
                tmp += to_string(path[i]);
                tmp += "->";
            }
            res.push_back(tmp + to_string(path[path.size() - 1]));//加上最后一个元素
            return;
        }
        if (cur->left) {//左
            traversal(cur->left, path, res);
            path.pop_back();//回溯
        }
        if (cur->right) {//右
            traversal(cur->right, path, res);
            path.pop_back();//回溯
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        traversal(root, path, res);
        return res;
    }*/
    //递归 没有回溯
/*    void traversal(TreeNode* cur, string& path, vector<string>& res) {
        path += to_string(cur->val);
        if (!cur->left && !cur->right) {
            res.push_back(path);
            return;
        }
        if (cur->left){
            string tmp = path + "->";
            traversal(cur->left, tmp, res);
        }
        if (cur->right) {
            string tmp = path + "->";
            traversal(cur->right, tmp, res);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path;
        traversal(root, path, res);
        return res;
    }*/
    //回溯方法二
/*    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val); // 中，中为什么写在这里，因为最后一个节点也要加入到path中
        if (!cur->left && !cur->right) {
            result.push_back(path);
            return;
        }
        if (cur->left) {
            path += "->";
            traversal(cur->left, path, result); // 左
            path.pop_back(); // 回溯 '>'
            path.pop_back(); // 回溯 '-'
        }
        if (cur->right) {
            path += "->";
            traversal(cur->right, path, result); // 右
            path.pop_back(); // 回溯'>'
            path.pop_back(); // 回溯 '-'
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        traversal(root, path, result);
        return result;
    }*/
    //迭代 前序遍历
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        stack<pair<TreeNode*, string/*保存路径的节点*/>> st;
        st.emplace(root, to_string(root->val));
        while (!st.empty()) {
            auto tmp = st.top();//中
            st.pop();
            if (!tmp.first->left && !tmp.first->right) {
                res.push_back(tmp.second);
            }
            if (tmp.first->right) {//右
                st.emplace(tmp.first->right, tmp.second + "->" + to_string(tmp.first->right->val));
            }
            if (tmp.first->left) {//左
                st.emplace(tmp.first->left, tmp.second + "->" + to_string(tmp.first->left->val));
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
    TreeNode* root = new TreeNode(100);
    root->left = new TreeNode(200);
    root->right = new TreeNode(300);
    root->left->left = new TreeNode(400);
    root->left->right = new TreeNode(500);
    root->right->left = new TreeNode(600);
    root->right->right = new TreeNode(700);
    vector<string> res;
    res = s.binaryTreePaths(root);
    for (auto& i : res) {
        cout << i << " ";
    }
    
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