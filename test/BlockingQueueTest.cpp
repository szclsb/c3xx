#include "gtest/gtest.h"
#include <c3xx/BlockingQueue.hpp>

#include <chrono>
#include <thread>

using namespace std;
namespace c = szclsb::c3xx;

class BlockingQueueFixture: public ::testing::Test {
public:
    void SetUp( ) override {
        // initialization or some code to run before each test
    }
};

TEST_F(BlockingQueueFixture, test_init) {
    auto s = make_shared<c::BlockingQueue<int>>(5);
    ASSERT_EQ(5, s->queue_length());
    ASSERT_EQ(0, s->count());
}