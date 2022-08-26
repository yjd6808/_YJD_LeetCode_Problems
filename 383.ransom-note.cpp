// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem383.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26]{};
        
        for (size_t i = 0; i < magazine.length(); i++) {
            cnt[magazine[i] - 'a']++;
        }
        
        for (size_t i = 0; i < ransomNote.length(); i++) {
            if (cnt[ransomNote[i] - 'a'] > 0) {
                cnt[ransomNote[i] - 'a']--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

