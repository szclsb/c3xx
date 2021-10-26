#include "gtest/gtest.h"
#include <c3xx/CountDownLatch.h>

#include <chrono>
#include <thread>

using namespace std;
namespace c = szclsb::c3xx;

class CountDownLatchFixture: public ::testing::Test {
public:
    void SetUp( ) override {
        // initialization or some code to run before each test
    }
};

TEST_F(CountDownLatchFixture, test_count) {
    auto cdl = make_shared<c::CountDownLatch>(5);
    ASSERT_EQ(5, cdl->count());
}

TEST_F(CountDownLatchFixture, test_count_down) {
    auto cdl = make_shared<c::CountDownLatch>(5);
    cdl->count_down();
    ASSERT_EQ(4, cdl->count());
}

TEST_F(CountDownLatchFixture, test_count_down_multiple) {
    auto cdl = make_shared<c::CountDownLatch>(5);
    cdl->count_down();
    cdl->count_down();
    cdl->count_down();
    cdl->count_down();
    cdl->count_down();
    cdl->count_down();
    cdl->count_down();
    ASSERT_EQ(0, cdl->count());
}

TEST_F(CountDownLatchFixture, test_await) {
    auto cdl = make_shared<c::CountDownLatch>(1);
    auto i = make_shared<int>(1);
    thread t2([cdl, i]() {
        cdl->await();
        ASSERT_EQ(2, *i);
    });

    // hope for t2 to await before i is modified
    this_thread::sleep_for(chrono::milliseconds(100));

    *i = 2;
    cdl->count_down();
    t2.join();
}