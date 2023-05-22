/**
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 

 

 示例 1: 

 
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
 

 示例 2: 

 
输入: nums = [1], k = 1
输出: [1] 

 

 提示： 

 
 1 <= nums.length <= 10⁵ 
 k 的取值范围是 [1, 数组中不相同的元素的个数] 
 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
 

 

 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 

 Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 1562 👎 0

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
    class cmp {//比较函数
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return rhs.second < lhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;//key 数字，value出现的次数
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;//小根堆

        for (auto it = map.begin(); it != map.end(); ++it) {//遍历map
            que.push(*it);//加入小根堆
            if (que.size() > k) {//保留前k个
                que.pop();
            }
        }

        while (!que.empty()) {
            res.push_back(que.top().first);
            que.pop();
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