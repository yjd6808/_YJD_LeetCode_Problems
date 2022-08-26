/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */

// @lc code=start
#include <mutex>

class ZeroEvenOdd {
private:
    int n;

    std::mutex zero_mtx;
    std::mutex odd_mtx;
    std::mutex even_mtx;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        
        odd_mtx.lock();
        even_mtx.lock();
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            zero_mtx.lock();
            printNumber(0);
            
            if (i % 2 == 0) odd_mtx.unlock();
            else            even_mtx.unlock();
        }
    }
    
    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            odd_mtx.lock();
            printNumber(i);
            zero_mtx.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            even_mtx.lock();
            printNumber(i);
            zero_mtx.unlock();
        }
    }
};
// @lc code=end

