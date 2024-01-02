#include "gtest/gtest.h"
#include "Circle.h"
#include "Vector2D.h"



// =========================================================
//
// CIRCLE
//
// =========================================================

TEST(get_center, Both_Positive) {
  Circle c(Vector2D(0, 0), 1);
  auto center = c.get_center();
  EXPECT_EQ(center, Vector2D(1, 1));
}

// TEST(get_center, Positive_Negative) {
//   EXPECT_FALSE(false);
// }

// TEST(get_center, Negative_Positive) {
//   EXPECT_FALSE(false);
// }

// TEST(get_center, Both_Negative) {
//   EXPECT_FALSE(false);
// }






int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}