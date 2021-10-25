#include "gtest/gtest.h"
#include <c3xx/mylib.h>

class MyTestFixture: public ::testing::Test {
public:
    void SetUp( ) override {
        // initialization or some code to run before each test
    }
};

TEST_F(MyTestFixture, test_print) {
    auto lib = mylib();
    testing::internal::CaptureStdout();
    lib.print_hello();
    auto output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("hello from mylib", output);
}