#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int left_num = nums[left];
            int right_num = nums[right];
            if (left_num * left_num < right_num * right_num) {
                ans.emplace_back(right_num * right_num);
                right--;
            }
            else {
                ans.emplace_back(left_num * left_num);
                left++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};