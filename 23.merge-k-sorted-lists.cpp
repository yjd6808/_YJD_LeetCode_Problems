// @before-stub-for-debug-begin
#include <vector>
#include "commoncppproblem23.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (;;) {
            int maxVal = 10001;
            int minNodeIdx = -1;
            
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) continue;  // 이미 끝자락에 도달한 경우 스킵
                if (lists[i]->val < maxVal) {
                    maxVal = lists[i]->val;
                    minNodeIdx = i;
                }
            }
            if (minNodeIdx == -1)   break;                              // 연결할 값을 못찾은 경우는 머지 소팅이 끝난 경우임

            // 처음 연결하는 경우
            if (head == nullptr)  {
                head = lists[minNodeIdx];
                tail = head;
            } else {
                tail->next = lists[minNodeIdx];
                tail = tail->next;
            }

            lists[minNodeIdx] = lists[minNodeIdx]->next;
        }
        return head;
    }
};
// @lc code=end

