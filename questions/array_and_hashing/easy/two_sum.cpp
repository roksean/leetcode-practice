#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> search_vals;

        for (size_t i = 0; i < nums.size(); i++) {
            int search_val = target - nums[i];

            if (search_vals.find(search_val) != search_vals.end()) {
                return {search_vals[search_val], static_cast<int>(i)};
            }

            search_vals[nums[i]] = i; 
        }

        return {};
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2,7,11,13};
    int target = 9;

    auto result = sol.twoSum(nums, target);
    cout << "test: ";
    for (int val : result) {
        cout << val << " "; 
    }
    return 0;
}; 

/*
unorderd_map is like a hashmap, better than map because O(1) lookups vs O(logn),
static_cast<int> is used to change size_t to int, which the function requires
*/


