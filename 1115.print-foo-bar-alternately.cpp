/*
 * @lc app=leetcode id=1115 lang=cpp
 *
 * [1115] Print FooBar Alternately
 */

// @lc code=start

volatile int state = 0;

class FooBar {
private:
    int n;
    

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            while (state == 1) {}
            printFoo();
            state = 1;
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            while (state == 0) {}
        	printBar();
            state = 0;
        }
    }
};
// @lc code=end

