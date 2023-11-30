#include "gtest/gtest.h"
#include "Collision.h"


TEST(AutomatonExampleTest, Default) {
  EXPECT_FALSE(false);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}