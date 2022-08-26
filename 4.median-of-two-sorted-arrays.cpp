// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem4.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double getMid(vector<int>& v) {
         if (v.size() % 2 == 0) {
            int l = v.size() / 2 - 1;
            int r = v.size() / 2;
            return (v[l] + v[r]) / 2.0;
        }
        
        return double(v[v.size() / 2]);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) return getMid(nums2);
        if (nums2.size() == 0) return getMid(nums1);
        
        size_t sz = nums1.size() + nums2.size();
        size_t n1 = 0, n2 = 0;
        vector<int> merged;
        
        for (;;) {
            if (nums1[n1] < nums2[n2])  merged.push_back(nums1[n1++]);
            else                        merged.push_back(nums2[n2++]);
            
            if (n1 >= nums1.size()) { 
                while (n2 < nums2.size()) merged.push_back(nums2[n2++]); 
                break;
            }
            
            if (n2 >= nums2.size()) { 
                while (n1 < nums1.size()) merged.push_back(nums1[n1++]);
                break;
            }
        }

        
       return getMid(merged);
    }
};
// @lc code=end

