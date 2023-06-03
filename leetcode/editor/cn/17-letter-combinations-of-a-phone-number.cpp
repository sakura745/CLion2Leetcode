/**
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 

 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 

 

 

 示例 1： 

 
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 

 示例 2： 

 
输入：digits = ""
输出：[]
 

 示例 3： 

 
输入：digits = "2"
输出：["a","b","c"]
 

 

 提示： 

 
 0 <= digits.length <= 4 
 digits[i] 是范围 ['2', '9'] 的一个数字。 
 

 Related Topics 哈希表 字符串 回溯 👍 2484 👎 0

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
    vector<string> telephoto{"", "", "abc" ,"def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void backtracking(const string& digits, int index, const string& path) {
        if (index == digits.size()/*深度*/) {
            res.push_back(path);
            return;
        }
        int tmp = digits[index] - '0';//取出digits中对应的数字
        for (auto& i : telephoto[tmp]/*宽度*/) {
            backtracking(digits, index + 1/*终止条件和去重*/, path + i/*回溯*/);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtracking(digits, 0, "");
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.letterCombinations("23");
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