/*
 * @lc app=leetcode id=1117 lang=cpp
 *
 * [1117] Building H2O
 */

// @lc code=start


#include <mutex>
#include <condition_variable>

class H2O {
    int released_oxygen_count{};
    int released_hydrogen_count{};
    
    std::condition_variable condvar;
    std::mutex mtx;
public:
    bool make_water() {
        if (released_oxygen_count == 1 && released_hydrogen_count == 2) {
            released_oxygen_count = 0;
            released_hydrogen_count = 0;
            return true;
        }
        return false;
    }
    
    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> ul(mtx);
        condvar.wait(ul, [this] { return released_hydrogen_count < 2; });
        releaseHydrogen();
        released_hydrogen_count++;
        if (make_water()) condvar.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> ul(mtx);
        condvar.wait(ul, [this] { return released_oxygen_count < 1; });
        releaseOxygen();
        released_oxygen_count++;
        if (make_water()) condvar.notify_all();
    }
};
// @lc code=end

