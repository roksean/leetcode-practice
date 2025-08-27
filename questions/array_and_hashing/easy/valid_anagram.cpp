#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s == t){
            return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    
    auto result1 = sol.isAnagram("rat", "car");
    auto result2 = sol.isAnagram("anagram","nagaram");

    cout << result1 << ": should be false" << "\n";
    cout << result2 << ": should be true" << "\n";

    return 0;
};

/* 
 * just need sort from <algorithm>. can compare with ==
*/
