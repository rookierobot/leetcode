#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 使用unordered_map统计频率
unordered_map<int, int> countFrequency(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    return freq;
}

// 使用unordered_set去重
vector<int> removeDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    vector<int> result;
    
    for (int num : nums) {
        if (seen.find(num) == seen.end()) {
            seen.insert(num);
            result.push_back(num);
        }
    }
    
    return result;
}

// 两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    
    return {};
}

// 检查是否存在重复元素
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    
    return false;
}

// 打印unordered_map
template<typename K, typename V>
void printMap(const unordered_map<K, V>& map) {
    for (const auto& pair : map) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// 打印vector
template<typename T>
void printVector(const vector<T>& nums) {
    for (const auto& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // 测试代码
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 5};
    
    // 统计频率
    auto freq = countFrequency(nums);
    cout << "Frequency count:" << endl;
    printMap(freq);
    
    // 去重
    auto uniqueNums = removeDuplicates(nums);
    cout << "\nUnique numbers: ";
    printVector(uniqueNums);
    
    // 两数之和
    int target = 6;
    auto indices = twoSum(nums, target);
    cout << "\nTwo sum indices for target " << target << ": ";
    printVector(indices);
    
    return 0;
} 