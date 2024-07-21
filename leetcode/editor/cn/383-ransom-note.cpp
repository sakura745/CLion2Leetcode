/**
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。 

 如果可以，返回 true ；否则返回 false 。 

 magazine 中的每个字符只能在 ransomNote 中使用一次。 

 

 示例 1： 

 
输入：ransomNote = "a", magazine = "b"
输出：false
 

 示例 2： 

 
输入：ransomNote = "aa", magazine = "ab"
输出：false
 

 示例 3： 

 
输入：ransomNote = "aa", magazine = "aab"
输出：true
 

 

 提示： 

 
 1 <= ransomNote.length, magazine.length <= 10⁵ 
 ransomNote 和 magazine 由小写英文字母组成 
 

 Related Topics 哈希表 字符串 计数 👍 721 👎 0

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
//void printLinkedList(ListNode* head);
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        int record['z' - 'A' + 1] = {};//个数别查错了。+1
        for (auto& i : magazine) {
            record[i - 'A']++;
        }
        for (auto& i : ransomNote) {
            record[i - 'A']--;

            //出现就直接返回，不用在该循环之后再遍历record
            if (record[i - 'A'] < 0) return false;
        }
        return true;
    }
};
/*
class Solution {
        public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> map;
            for (auto letter : magazine) {
                map[letter]++;
            }
            for (auto letter : ransomNote) {
                if (map.find(letter) != map.end() && map[letter]) {
                    map[letter]--;
                } else {
                    return false;
                }
            }
            return true;
        }
};
*/
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
//    vector<int> a /*initilization*/;
    auto x = s.canConstruct("aaccc", "AAzzzzzz") /*function_name*/;
    cout << x << endl;
    /*    ListNode* test = new ListNode(1);
    test->next = new ListNode(2);
    test->next->next = new ListNode(6);
    test->next->next->next = new ListNode(3);
    test->next->next->next->next = new ListNode(4);
    test->next->next->next->next->next = new ListNode(5);
    test->next->next->next->next->next->next = new ListNode(6);*/
//    ListNode* head = generateRandomLinkedList(MaxSize, MaxValue);
//    auto x = s. /*function_name*/;

    
    
    return 0;
}

/*
void printLinkedList(ListNode* head) {
    if(head == nullptr) return;
    while(head->next != nullptr){//为了调整输出中 "->" 的位置
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;//同上
}*/
