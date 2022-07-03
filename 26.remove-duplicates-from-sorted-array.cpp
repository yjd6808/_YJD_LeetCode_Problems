// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem26.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = 0;
        int next = 1;

        while (next < nums.size()) {
            if (nums[current] != nums[next]) {
                current++;
                swap(nums[current], nums[next]);
            }

            next++;
        }

        return current + 1;
    }
};
// @lc code=end

