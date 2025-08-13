#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique_nums;

        for (int num: nums) {
            if (unique_nums.count(num) > 0) {
                return true;
            }
            unique_nums.insert(num);
        }
        
        return false;
    }

};

int main() {
    Solution sol;

    vector<int> nums = {1,2,3,1};

    bool result = sol.containsDuplicate(nums);
    cout << result;
};

/*
 use unordered_set for O(1) inserts and lookups. it's set up as a hashtable, 
 instead of a red-black tree for normal sets.
*/
