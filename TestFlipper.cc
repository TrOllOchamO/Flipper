#include <cmath>
#include "gtest/gtest.h"

#include "Vector2D.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygone.h"


// =========================================================
//
// CIRCLE
//
// =========================================================

// get_center

TEST(CIRCLE___get_center, Both_Positive) {
  Circle c(Vector2D(0, 0), 1);
  auto center = c.get_center();
  EXPECT_EQ(center, Vector2D(1, 1));
}

TEST(CIRCLE___get_center, Positive_Negative) {
  Circle c(Vector2D(0, -2), 1);
  auto center = c.get_center();
  EXPECT_EQ(center, Vector2D(1, -1));
}

TEST(CIRCLE___get_center, Negative_Positive) {
  Circle c(Vector2D(-2, 0), 1);
  auto center = c.get_center();
  EXPECT_EQ(center, Vector2D(-1, 1));
}

TEST(CIRCLE___get_center, Both_Negative) {
  Circle c(Vector2D(-2, -2), 1);
  auto center = c.get_center();
  EXPECT_EQ(center, Vector2D(-1, -1));
}

TEST(CIRCLE___get_center, Both_Zero) {
  Circle c(Vector2D(-1, -1), 1);
  auto center = c.get_center();
  EXPECT_EQ(center, Vector2D(0, 0));
}


// get_futhest_point

TEST(CIRCLE___get_futhest_point, Zero) {
  Circle c(Vector2D(0, 0), 0);
  auto point = c.get_futhest_point(Vector2D(1, 1));
  EXPECT_EQ(point, Vector2D(0, 0));
}

  TEST(CIRCLE___get_futhest_point, Ten) {
  Circle c(Vector2D(-10, -10), 10);
  auto point = c.get_futhest_point(Vector2D(1, 0));
  EXPECT_EQ(point, Vector2D(10, 0));
}

TEST(CIRCLE___get_futhest_point, All_4_Direction) {
  Circle c1(Vector2D(-10, -10), 10);
  EXPECT_EQ(c1.get_futhest_point(Vector2D(1, 0)), Vector2D(10, 0));
  EXPECT_EQ(c1.get_futhest_point(Vector2D(0, 1)), Vector2D(0, 10));
  EXPECT_EQ(c1.get_futhest_point(Vector2D(-1, 0)), Vector2D(-10, 0));
  EXPECT_EQ(c1.get_futhest_point(Vector2D(0, -1)), Vector2D(0, -10));
}


// =========================================================
//
// RECTANGLE
//
// =========================================================

// get_center

TEST(RECTANGLE___get_center, Both_Positive) {
  Rectangle r(Vector2D(0, 0), 2, 2);
  auto center = r.get_center();
  EXPECT_EQ(center, Vector2D(1, 1));
}

TEST(RECTANGLE___get_center, Positive_Negative) {
  Rectangle r(Vector2D(0, -2), 2, 2);
  auto center = r.get_center();
  EXPECT_EQ(center, Vector2D(1, -1));
}

TEST(RECTANGLE___get_center, Negative_Positive) {
  Rectangle r(Vector2D(-2, 0), 2, 2);
  auto center = r.get_center();
  EXPECT_EQ(center, Vector2D(-1, 1));
}

TEST(RECTANGLE___get_center, Both_Negative) {
  Rectangle r(Vector2D(-2, -2), 2, 2);
  auto center = r.get_center();
  EXPECT_EQ(center, Vector2D(-1, -1));
}

TEST(RECTANGLE___get_center, Both_Zero) {
  Rectangle r(Vector2D(-1, -1), 2, 2);
  auto center = r.get_center();
  EXPECT_EQ(center, Vector2D(0, 0));
}


// get_futhest_point

TEST(RECTANGLE___get_futhest_point, All_8_Direction) {
  Rectangle r(Vector2D(-1, -1), 2, 2);
  EXPECT_EQ(r.get_futhest_point(Vector2D(1, 0)), Vector2D(1, -1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(0, 1)), Vector2D(-1, 1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(-1, 0)), Vector2D(-1, -1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(0, -1)), Vector2D(-1, -1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(1, 1)), Vector2D(1, 1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(-1, -1)), Vector2D(-1, -1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(-1, 1)), Vector2D(-1, 1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(1, -1)), Vector2D(1, -1));
}

TEST(RECTANGLE___get_futhest_point, Random) {
  Rectangle r(Vector2D(-1, -1), 2, 2);
  EXPECT_EQ(r.get_futhest_point(Vector2D(1, 2)), Vector2D(1, 1));
  EXPECT_EQ(r.get_futhest_point(Vector2D(2, -1)), Vector2D(1, -1));  
  EXPECT_EQ(r.get_futhest_point(Vector2D(4, -3)), Vector2D(1, -1));  
}


// =========================================================
//
// POLYGONE
//
// =========================================================

// get_center

TEST(POLYGONE___get_center, small) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(5,0));
  p.add_point(Vector2D(2.5,3));

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(2.5, 1)); 
}

TEST(POLYGONE___get_center, big) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(3,0));
  p.add_point(Vector2D(4,3));
  p.add_point(Vector2D(3,5));
  p.add_point(Vector2D(0,2));

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(2, 2)); 
}

TEST(POLYGONE___get_center, One) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(1,1));

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(1, 1)); 
}

TEST(POLYGONE___get_center, Zero) {
  Polygone p(Vector2D(0, 0));

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(0, 0)); 
}

TEST(POLYGONE___get_center, Multiple_Same_Point) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(3,1));
  p.add_point(Vector2D(3,1));
  p.add_point(Vector2D(3,1));

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(3, 1)); 
}


// get_futhest_point

TEST(POLYGONE___get_futhest_point, small) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(5,0));
  p.add_point(Vector2D(2.5,3));

  EXPECT_EQ(p.get_futhest_point(Vector2D(2, 3)), Vector2D(2.5, 3));
  EXPECT_EQ(p.get_futhest_point(Vector2D(2.5, 0)), Vector2D(5, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, 0)), Vector2D(0, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, -1)), Vector2D(0, 0));
}

TEST(POLYGONE___get_futhest_point, big) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(3,0));
  p.add_point(Vector2D(4,3));
  p.add_point(Vector2D(3,5));
  p.add_point(Vector2D(0,2));

  EXPECT_EQ(p.get_futhest_point(Vector2D(0, 0)), Vector2D(0, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, -1)), Vector2D(0, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, 2)), Vector2D(3, 5));
  EXPECT_EQ(p.get_futhest_point(Vector2D(2, 2)), Vector2D(3, 5));
  EXPECT_EQ(p.get_futhest_point(Vector2D(3, 5)), Vector2D(3, 5));
}


// is_convex

TEST(POLYGONE___is_convex, Point) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Line) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Triangle) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));
  p.add_point(Vector2D(1,1));

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Square) {
  Polygone p(Vector2D(0, 0));

  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));
  p.add_point(Vector2D(1,1));
  p.add_point(Vector2D(0,1));

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, False_Square) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));
  p.add_point(Vector2D(1,1));
  p.add_point(Vector2D(0.8,0.2));

  EXPECT_FALSE(p.is_convex());
}

TEST(POLYGONE___is_convex, Big_Line) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));
  p.add_point(Vector2D(2,0));
  p.add_point(Vector2D(3,0));

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Other_Big_Line) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(0,1));
  p.add_point(Vector2D(0,2));
  p.add_point(Vector2D(0,3));

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, False) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));
  p.add_point(Vector2D(1,1));
  p.add_point(Vector2D(2,1));
  p.add_point(Vector2D(2,2));
  p.add_point(Vector2D(0,2));

  EXPECT_FALSE(p.is_convex());
}

TEST(POLYGONE___is_convex, True) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));
  p.add_point(Vector2D(1.5,1));
  p.add_point(Vector2D(1.5,2));
  p.add_point(Vector2D(1,2.5));
  p.add_point(Vector2D(1.5,2.5));
  p.add_point(Vector2D(0,2));

  EXPECT_FALSE(p.is_convex());
}

TEST(POLYGONE___is_convex, Also_True) {
  Polygone p(Vector2D(0, 0));
  p.add_point(Vector2D(0,0));
  p.add_point(Vector2D(1,0));
  p.add_point(Vector2D(1.5,1));
  p.add_point(Vector2D(1.5,2));
  p.add_point(Vector2D(1,2.5));
  p.add_point(Vector2D(1.5,2.5));
  p.add_point(Vector2D(0,2));
  p.add_point(Vector2D(0,1));

  EXPECT_FALSE(p.is_convex());
}


// =========================================================
//
// MAIN
//
// =========================================================

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}