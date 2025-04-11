#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int min_len = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            // update right edge
            sum += nums[right];

            while (sum >= target) {
                min_len = min(min_len, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << sol.minSubArrayLen(target, nums) << endl;
}
