/**
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。 

 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。 

 
 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。 
 

 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。 

 

 示例 1： 
 
 
输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
输出：["JFK","MUC","LHR","SFO","SJC"]
 

 示例 2： 
 
 
输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL",
"SFO"]]
输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
 

 

 提示： 

 
 1 <= tickets.length <= 300 
 tickets[i].length == 2 
 fromi.length == 3 
 toi.length == 3 
 fromi 和 toi 由大写英文字母组成 
 fromi != toi 
 

 Related Topics 深度优先搜索 图 欧拉回路 👍 795 👎 0

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
    unordered_map<string, map<string, int>> targets;//<起点, <终点，起点到终点的次数>>
    bool backtracking(int ticketSum, vector<string>& res) {
        if (res.size()/*通过res大小来确定飞了几次*/ == ticketSum + 1) {
            return true;
        }
        for (auto& [k, v] : targets[res.back()]/*表示以res.back()为起点，对应的航班信息*/) {
            if (v > 0/*票不为零，还有票*/) {
                res.push_back(k);//起飞
                --v;//少一张票
                if (backtracking(ticketSum, res)) return true;
                res.pop_back();
                ++v;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;//将targets赋值
        }
        vector<string> res;
        res.push_back("JFK");//起点
        backtracking(tickets.size(), res);
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