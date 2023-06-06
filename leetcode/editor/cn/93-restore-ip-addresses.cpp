/**
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 

 
 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 
"192.168@1.1" 是 无效 IP 地址。 
 

 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序
或删除 s 中的任何数字。你可以按 任何 顺序返回答案。 

 

 示例 1： 

 
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
 

 示例 2： 

 
输入：s = "0000"
输出：["0.0.0.0"]
 

 示例 3： 

 
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

 

 提示： 

 
 1 <= s.length <= 20 
 s 仅由数字组成 
 

 Related Topics 字符串 回溯 👍 1241 👎 0

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
    vector<string> res;
    void backtracking(string& s, int startIndex, int pointSum = 3) {
        if (pointSum == 0) {
            if (isValid(s, startIndex, s.size() - 1)) {//结尾和回文的区别
                res.push_back(s);
                return;
            }
        }
        for (int i = startIndex; i < s.size(); ++i) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1,'.');
                --pointSum;
                backtracking(s, i + 2/*startIndex多了一个1，是 . 的索引*/, pointSum);
                s.erase(s.begin() + i + 1);
                ++pointSum;
            } else break;//剪枝，有一个不满足，直接终止循环，而不是continue，执行下一个循环;
        }
    }
    bool isValid(const string& s, int l, int r) {
        if (r - l > 4) return false;//剪枝，且防止stoi溢出int
        string tmpS = s.substr(l, r - l + 1);
        if (!tmpS.empty()/*防止空字符引起的异常*/) {
            int tmpV = stoi(tmpS);
            int cnt = 1;
            if (tmpV < 256) {
                while (tmpV / 10) {
                    ++cnt;
                    tmpV /= 10;
                }
                return cnt == tmpS.size();
            }
        }
        return false;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size()< 4 || s.size() > 12/*剪枝*/) return {};
        backtracking(s, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.restoreIpAddresses("10000");
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