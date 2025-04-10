#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            }
            else if (nums[middle] > target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int result = solution.search(nums, target);
    cout << result << endl;
}  
