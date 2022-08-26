/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */

// @lc code=start
#include <condition_variable>
#include <mutex>

class ZeroEvenOdd {
private:
    const int E_ZERO = 1;
    const int O_ZERO = 12;
    const int ODD = 123;
    const int EVEN = 1234;
    
    
    int n;
    int state = E_ZERO;
    
    std::mutex mtx;
    std::condition_variable condvar;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> ul(mtx);
            condvar.wait(ul, [this]{ return state == E_ZERO || state == O_ZERO; });
            printNumber(0);
            
            if (state == E_ZERO)
                state = ODD;
            else
                state = EVEN;
            condvar.notify_all();
        }
    }
    
    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> ul(mtx);
            condvar.wait(ul, [this]{ return state == ODD; });
            printNumber(i);
            state = O_ZERO;
            condvar.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> ul(mtx);
            condvar.wait(ul, [this]{ return state == EVEN; });
            printNumber(i);
            state = E_ZERO;
            condvar.notify_all();
        }
        
    }

    
};
// @lc code=end

