#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        int len = nums.size();
        while (slow <= len - 1 && fast <= len - 1) {
            while (fast <= len - 1 && nums[fast] == val) fast++;
            if (fast >= len) break;
            nums[slow] = nums[fast];
            slow++;
            fast++;
        }
        return slow;
    }
};