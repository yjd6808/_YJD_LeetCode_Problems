// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem28.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;

        if (needle.size() > haystack.size()) {
            return -1;
        }

        for (int i = 0; i < haystack.size(); i++) {
            int needle_idx = 0;

            while (needle_idx < needle.size() && haystack[i + needle_idx] == needle[needle_idx]) {
                needle_idx++;
            }

            if (needle_idx == needle.size()) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

