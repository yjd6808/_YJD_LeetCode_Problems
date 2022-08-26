/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start
#include <condition_variable>
#include <mutex>

using namespace std;

template <int max_count>
class my_sem {
public:
    my_sem(int cnt = max_count) : m_available_count(cnt) {}

    void acquire() {
        unique_lock<mutex> guard(m_mtx);
        m_condvar.wait(guard, [this]{ return m_available_count > 0; });
        m_available_count--;
    }
    
    void release() {
        unique_lock<mutex> guard(m_mtx);
        if (m_available_count < max_count) {
            m_available_count++;
            m_condvar.notify_one();
        }
    }
private:
    int m_available_count;
    condition_variable m_condvar;
    mutex m_mtx;
};

class Foo {

private:
    my_sem<1> second_waiter{0};
    my_sem<1> third_waiter{0};
public:
    void first(function<void()> printFirst) {
        printFirst();
        second_waiter.release();
    }

    void second(function<void()> printSecond) {
        second_waiter.acquire();
        printSecond();
        third_waiter.release();
    }

    void third(function<void()> printThird) {
        third_waiter.acquire();
        printThird();
    }


};
// @lc code=end

