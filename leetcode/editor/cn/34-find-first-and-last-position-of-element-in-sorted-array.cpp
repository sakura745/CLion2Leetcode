/**
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。 

 如果数组中不存在目标值 target，返回 [-1, -1]。 

 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。 

 

 示例 1： 

 
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4] 

 示例 2： 

 
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1] 

 示例 3： 

 
输入：nums = [], target = 0
输出：[-1,-1] 

 

 提示： 

 
 0 <= nums.length <= 10⁵ 
 -10⁹ <= nums[i] <= 10⁹ 
 nums 是一个非递减数组 
 -10⁹ <= target <= 10⁹ 
 

 Related Topics 数组 二分查找 👍 2292 👎 0

*/
#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int r = nums.size() - 1, l = 0;
        while (r >= l) {
            int m = l + ((r - l) >> 1);
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                while (nums[m] > nums[l]) {
                    ++l;
                }
                while (nums[m] < nums[r]) {
                    --r;
                }
                res.push_back(l);
                res.push_back(r);
                return res;
            }
        }
        return {-1, -1};
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a {5,7,7,8,8,10}/*initilization*/;
    auto x = s.searchRange(a, 8) /*function_name*/;
    for (auto&& i : x) {
        cout << i << " ";
    }
    return 0;
}