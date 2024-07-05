/**
给定一个含有 n 个正整数的数组和一个正整数 target 。 

 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。 

 

 示例 1： 

 
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 

 示例 2： 

 
输入：target = 4, nums = [1,4,4]
输出：1
 

 示例 3： 

 
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

 

 提示： 

 
 1 <= target <= 10⁹ 
 1 <= nums.length <= 10⁵ 
 1 <= nums[i] <= 10⁵ 
 

 

 进阶： 

 
 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。 
 

 Related Topics 数组 二分查找 前缀和 滑动窗口 👍 1700 👎 0

*/
#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX, length/*窗口长度*/ = 0;
        int left = 0;//滑动窗口的左边界
        for (int right = 0; right < nums.size(); ++right) {//right滑动窗口的右边界
            target -= nums[right];
            while (target <= 0) {
                length = right - left + 1;
                res = res < length ? res : length;
                target += nums[left++];//调节窗口的左侧
            }
        }
        return res == INT_MAX ? 0 : res;//把两种情况结合到一起
    }
};


//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a{1,4,4}; /*initilization*/
    auto x = s.minSubArrayLen(4, a);/*function_name*/
    cout << x << endl;
    return 0;
}