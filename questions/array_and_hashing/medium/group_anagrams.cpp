#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> grouped_words;

       for (string& word: strs) {
           string sorted_word = word;
           sort(sorted_word.begin(), sorted_word.end());
           grouped_words[sorted_word].push_back(word);
       }

       vector<vector<string>> result;
       for (auto& key_val_pair: grouped_words) {
           result.push_back(key_val_pair.second);
       }
       return result;
    }
};

/*
 * unordered_map to vector<string>. note auto here is pair(const string, 
 * vector<string>)
*/
