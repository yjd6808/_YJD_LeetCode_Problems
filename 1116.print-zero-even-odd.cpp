/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */

// @lc code=start
#include <mutex>
#include <atomic>

class ZeroEvenOdd {
private:
    int n;
    int cur{};
    
    volatile int current_state{};
    volatile int before_state = 2;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            while (current_state != 0) {}
            printNumber(0);
            
            if (before_state == 1) current_state = 2;
            if (before_state == 2) current_state = 1;
            
        }
    }
    
    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                while (current_state != 1) {}
                printNumber(i);
                before_state = current_state;
                current_state = 0;
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                while (current_state != 2) {}
                printNumber(i);
                before_state = current_state;
                current_state = 0;
            }
        }
        
    }

    
};
// @lc code=end

