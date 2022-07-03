// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include "commoncppproblem20.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    pair<char, char> bracket_pairs[3] = 
    { 
        {'(', ')'}, 
        {'[', ']'}, 
        {'{', '}'}
    };

    bool is_left_bracket(char& ch)  {
        for (auto& pair : bracket_pairs) {
            if (ch == pair.first) {
                return true;
            }
        }

        return false;
    }

    bool is_paired_bracket(char& left, char& right) {
        for (auto& pair : bracket_pairs) {
            if (left == pair.first) {
                if (pair.second == right) {
                    return true;
                }

                return false;
            }
        }

        return false;
    }

    bool isValid(string s) {

        // 홀수 길이는 무조건 실패
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<char> remain_opened_bracket;
        for (int i = 0; i < s.size(); i++) {
            char& bracket = s[i];

            if (is_left_bracket(bracket)) {
                remain_opened_bracket.push(bracket);
            } else {
                if (remain_opened_bracket.empty()) {
                    return false;
                }

                char left_bracket = remain_opened_bracket.top();
                remain_opened_bracket.pop();

                if (!is_paired_bracket(left_bracket, bracket))
                    return false;
            }
        }

        // 아직 닫히지 않은 열린 괄호가 있을 경우 실패
        return remain_opened_bracket.size() > 0 ? false : true;
    }
};
// @lc code=end

