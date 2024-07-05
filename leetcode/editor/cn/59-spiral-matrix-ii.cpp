/**
给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 

 

 示例 1： 
 
 
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
 

 示例 2： 

 
输入：n = 1
输出：[[1]]
 

 

 提示： 

 
 1 <= n <= 20 
 

 Related Topics 数组 矩阵 模拟 👍 1049 👎 0

*/
#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,-1));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;//每组循环的边界
        int cnt = 1;
        while (cnt <= n * n) {
            for (int i = left;i <= right; ++i) {
                res[top][i] = cnt++;
            }
            //规定了下一边的上边界
            //同时给第二组循环用的，向内逼近，上边界就++，下边界就--
            ++top;
            for (int i = top;i <= bottom; ++i) {
                res[i][right] = cnt++;
            }
            --right;
            for (int i = right;i >= left; --i) {
                res[bottom][i] = cnt++;
            }
            --bottom;
            for (int i = bottom;i >= top; --i) {
                res[i][left] = cnt++;
            }
            ++left;
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> a /*initilization*/
    auto x = s. /*function_name*/
    cout << x << endl;
    return 0;
}