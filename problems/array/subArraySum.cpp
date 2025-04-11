#include <iostream>
#include <vector>
using namespace std;

int main() {
    int len = 0;
    cin >> len;
    vector<int> nums(len, 0);
    for (int i = 0; i < len; i++) {
        cin >> nums[i];
    }
    int start = 0;
    int end = 0;
    vector<pair<int, int>> subAaaryIndex;
    while (cin >> start >> end) {
        subAaaryIndex.emplace_back(pair<int, int> {start, end});
    }
    vector<int> sumarray(len + 1, 0);
    sumarray[0] = 0;
    for (int i = 1; i < sumarray.size(); i++) {
        sumarray[i] = nums[i - 1] + sumarray[i - 1];
    }
    for (auto pair : subAaaryIndex) {
        cout << sumarray[pair.second + 1] - sumarray[pair.first] << endl;
    }
    return 0;
}