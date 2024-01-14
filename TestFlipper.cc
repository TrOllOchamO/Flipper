#include "gtest/gtest.h"
#include <cmath>

#include "Circle.h"
#include "Collision.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Vector2D.h"

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
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(2.5, 3)} );

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(2.5, 1));
}

TEST(POLYGONE___get_center, big) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(3, 0), Vector2D(4, 3), Vector2D(3, 5), Vector2D(0, 2)} );

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(2, 2));
}

TEST(POLYGONE___get_center, One) {
  Polygone p;
  p.add_point(Vector2D(1, 1));

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(1, 1));
}

TEST(POLYGONE___get_center, Zero) {
  Polygone p;

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(0, 0));
}

TEST(POLYGONE___get_center, Multiple_Same_Point) {
  Polygone p;
  p.add_point( {Vector2D(3, 1), Vector2D(3, 1), Vector2D(3, 1)} );

  auto center = p.get_center();
  EXPECT_EQ(center, Vector2D(3, 1));
}

// get_futhest_point

TEST(POLYGONE___get_futhest_point, small) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(2.5, 3)} );

  EXPECT_EQ(p.get_futhest_point(Vector2D(2, 3)), Vector2D(2.5, 3));
  EXPECT_EQ(p.get_futhest_point(Vector2D(2.5, 0)), Vector2D(5, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, 0)), Vector2D(0, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, -1)), Vector2D(0, 0));
}

TEST(POLYGONE___get_futhest_point, big) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(3, 0), Vector2D(4, 3), Vector2D(3, 5), Vector2D(0, 2)} );

  EXPECT_EQ(p.get_futhest_point(Vector2D(0, 0)), Vector2D(0, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, -1)), Vector2D(0, 0));
  EXPECT_EQ(p.get_futhest_point(Vector2D(0, 2)), Vector2D(3, 5));
  EXPECT_EQ(p.get_futhest_point(Vector2D(2, 2)), Vector2D(3, 5));
  EXPECT_EQ(p.get_futhest_point(Vector2D(3, 5)), Vector2D(3, 5));
}

// is_convex

TEST(POLYGONE___is_convex, Point) {
  Polygone p;
  p.add_point(Vector2D(0, 0));

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Line) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0)} );

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Triangle) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0), Vector2D(1, 1)} );

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Square) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0), Vector2D(1, 1), Vector2D(0, 1)} );

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, False_Square) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0), Vector2D(1, 1), Vector2D(0.8, 0.2)} );

  EXPECT_FALSE(p.is_convex());
}

TEST(POLYGONE___is_convex, Big_Line) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0), Vector2D(2, 0), Vector2D(3, 0)} );

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, Other_Big_Line) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(0, 1), Vector2D(0, 2), Vector2D(0, 3)} );

  EXPECT_TRUE(p.is_convex());
}

TEST(POLYGONE___is_convex, False) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0), Vector2D(1, 1), Vector2D(2, 1), Vector2D(2, 2), Vector2D(0, 2)} );

  EXPECT_FALSE(p.is_convex());
}

TEST(POLYGONE___is_convex, True) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0), Vector2D(1.5, 1), Vector2D(1.5, 2), Vector2D(1, 2.5), Vector2D(1.5, 2.5), Vector2D(0, 2)} );

  EXPECT_FALSE(p.is_convex());
}

TEST(POLYGONE___is_convex, Also_True) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(1, 0), Vector2D(1.5, 1), Vector2D(1.5, 2), Vector2D(1, 2.5), Vector2D(1.5, 2.5), Vector2D(0, 2), Vector2D(0, 1)} );

  EXPECT_FALSE(p.is_convex());
}

// triangulate

TEST(POLYGONE___triangulate, Simple) {
  Polygone p;
  p.add_point( {Vector2D(3, 0), Vector2D(5, 0), Vector2D(5, 5), Vector2D(0, 5), Vector2D(0, 3), Vector2D(3, 3), Vector2D(3, 2), Vector2D(2, 2), Vector2D(2, 1), Vector2D(3, 1)} );

  auto x = p.triangulate();
  for (auto poly : x) {
    poly.print();
  }
}

TEST(POLYGONE___triangulate, Other) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(2.5, 2.5), Vector2D(5, 5), Vector2D(0, 5)} );

  auto x = p.triangulate();
  for (auto poly : x) {
    poly.print();
  }
}

TEST(POLYGONE___triangulate, Other_Other) {
  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(3, 0), Vector2D(0.5, 1.5), Vector2D(3, 3), Vector2D(0, 3)} );

  auto x = p.triangulate();
  for (auto poly : x) {
    poly.print();
  }
}

TEST(POLYGONE___triangulate, Complexe) {
  Polygone p;
  p.add_point( {Vector2D(2, 1.5), Vector2D(4, 0), Vector2D(3, 1), Vector2D(4, 2), Vector2D(3, 2), Vector2D(2, 3), Vector2D(1, 2), Vector2D(0, 2), Vector2D(1, 1), Vector2D(0, 0)} );

  auto x = p.triangulate();
  for (auto poly : x) {
    poly.print();
  }
}

// =========================================================
//
// COLLISION
//
// =========================================================

// are_colliding

TEST(COLLISION___are_colliding, True) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(0, 0), 2, 2);

  EXPECT_TRUE(Collision::are_colliding(&r1, &r2));
}

TEST(COLLISION___are_colliding, False) {
  Rectangle r1(Vector2D(10, 0), 2, 2);
  Rectangle r2(Vector2D(0, 0), 2, 2);

  EXPECT_FALSE(Collision::are_colliding(&r1, &r2));
}

TEST(COLLISION___are_colliding, Almost) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(2, 0), 2, 2);

  EXPECT_TRUE(Collision::are_colliding(&r1, &r2));
}

TEST(COLLISION___are_colliding, Almost_None) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(2.01, 0), 2, 2);

  EXPECT_FALSE(Collision::are_colliding(&r1, &r2));
}

TEST(COLLISION___are_colliding, Circle_True) {
  Circle c1(Vector2D(0, 0), 2);
  Circle c2(Vector2D(1, 0), 2);

  EXPECT_TRUE(Collision::are_colliding(&c1, &c2));
}

TEST(COLLISION___are_colliding, Circle_False) {
  Circle c1(Vector2D(0, 0), 2);
  Circle c2(Vector2D(10, 0), 2);

  EXPECT_FALSE(Collision::are_colliding(&c1, &c2));
}

TEST(COLLISION___are_colliding, Polygone_True) {
  Polygone p1;
  p1.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(1, 3), Vector2D(0, 3)} );

  Polygone p2;
  p2.add_point( {Vector2D(4, 0), Vector2D(9, 0), Vector2D(9, 3), Vector2D(8, 3)} );

  EXPECT_TRUE(Collision::are_colliding(&p1, &p2));
}

TEST(COLLISION___are_colliding, Polygone_False) {
  Polygone p1;
  p1.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(1, 3), Vector2D(0, 3)} );

  Polygone p2;
  p2.add_point( {Vector2D(6, 0), Vector2D(11, 0), Vector2D(11, 3), Vector2D(10, 3)} );

  EXPECT_FALSE(Collision::are_colliding(&p1, &p2));
}

TEST(COLLISION___are_colliding, Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(2, 1));

  EXPECT_TRUE(Collision::are_colliding(&p, &r));
}

TEST(COLLISION___are_colliding, Line) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point( {Vector2D(2, 1), Vector2D(3, 1)} );

  EXPECT_TRUE(Collision::are_colliding(&p, &r));
}

TEST(COLLISION___are_colliding, Polygone_Close) {
  Polygone p1;
  p1.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(1, 1), Vector2D(0, 1)} );

  Polygone p2;
  p2.add_point( {Vector2D(5.1, 0), Vector2D(6, 0), Vector2D(6, 1), Vector2D(1.1, 1)} );

  EXPECT_FALSE(Collision::are_colliding(&p1, &p2));
}

TEST(COLLISION___are_colliding, All_Shape_True) {
  Rectangle r(Vector2D(2, 1), 2, 2);

  Circle c(Vector2D(0, 2), 2);

  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(1, 3), Vector2D(0, 3)} );

  EXPECT_TRUE(Collision::are_colliding(&p, &r));
  EXPECT_TRUE(Collision::are_colliding(&r, &c));
  EXPECT_TRUE(Collision::are_colliding(&c, &p));
}

TEST(COLLISION___are_colliding, All_Shape_False) {
  Rectangle r(Vector2D(3, 2), 2, 2);

  Circle c(Vector2D(0, 4), 2);

  Polygone p;
  p.add_point( {Vector2D(0, 0), Vector2D(5, 0), Vector2D(1, 3), Vector2D(0, 3)} );

  EXPECT_FALSE(Collision::are_colliding(&p, &r));
  EXPECT_FALSE(Collision::are_colliding(&r, &c));
  EXPECT_FALSE(Collision::are_colliding(&c, &p));
}


// get_minimum_dist

TEST(COLLISION___get_minimum_dist, True) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(1, 0), 2, 2);

  EXPECT_NEAR(Collision::get_minimum_dist(&r1, &r2), -1.0, 0.01);
}

TEST(COLLISION___get_minimum_dist, Perfectly_Overlap) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(0, 0), 2, 2);

  EXPECT_NEAR(Collision::get_minimum_dist(&r1, &r2), -2, 0.001);
}

TEST(COLLISION___get_minimum_dist, False) {
  Rectangle r1(Vector2D(10, 0), 2, 2);
  Rectangle r2(Vector2D(0, 0), 2, 2);

  EXPECT_NEAR(Collision::get_minimum_dist(&r1, &r2), 8, 0.01);
}

TEST(COLLISION___get_minimum_dist, Almost) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(2, 0), 2, 2);

  EXPECT_NEAR(Collision::get_minimum_dist(&r1, &r2), 0, 0.01);
}

TEST(COLLISION___get_minimum_dist, Almost_None) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(2.01, 0), 2, 2);

  EXPECT_NEAR(Collision::get_minimum_dist(&r1, &r2), 0.01, 0.01);
}

TEST(COLLISION___get_minimum_dist, Diagonal) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(1, 1), 2, 2);

  EXPECT_NEAR(Collision::get_minimum_dist(&r1,&r2), -1, 0.001);
}

TEST(COLLISION___get_minimum_dist, Rectangle_Triangle) {
  Rectangle r(Vector2D(0, 0), 2, 2);
  Polygone p;
  p.add_point( {Vector2D(1, 1), Vector2D(3, 0), Vector2D(3.2, 5)} );

  EXPECT_NEAR(Collision::get_minimum_dist(&r,&p), -1, 0.001);
}

TEST(COLLISION___get_minimum_dist, Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(2, 1));

  EXPECT_NEAR(Collision::get_minimum_dist(&r,&p), 0, 0.001);
}

TEST(COLLISION___get_minimum_dist, Line) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point( {Vector2D(2, 1), Vector2D(3, 1)} );

  EXPECT_NEAR(Collision::get_minimum_dist(&r,&p), 0, 0.001);
}

TEST(COLLISION___get_minimum_dist, Other_Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(1, 0));

  EXPECT_NEAR(Collision::get_minimum_dist(&r,&p), 0, 0.001);
}

TEST(COLLISION___get_minimum_dist, Other_Other_Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(1, 2));

  EXPECT_NEAR(Collision::get_minimum_dist(&r,&p), 0, 0.001);
}

TEST(COLLISION___get_minimum_dist, Other_Other_Other_Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(0, 1));

  EXPECT_NEAR(Collision::get_minimum_dist(&r,&p), 0, 0.001);
}

// get_minimum_dist_and_direction

TEST(COLLISION___get_minimum_dist_and_direction, Collide) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(1, 0), 2, 2);

  Vector2D v = Vector2D::zero();
  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r1, &r2, v), -1.0, 0.01);
  EXPECT_EQ(v, Vector2D(1, 0));
}

TEST(COLLISION___get_minimum_dist_and_direction, Do_Not_Collide) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(3, 0), 2, 2);

  Vector2D v = Vector2D::zero();
  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r1, &r2, v), 1.0, 0.01);
}

TEST(COLLISION___get_minimum_dist_and_direction, Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(2, 1));

  Vector2D v = Vector2D::zero();

  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r,&p,v), 0, 0.001);
  EXPECT_EQ(v,Vector2D(1,0));
}

TEST(COLLISION___get_minimum_dist_and_direction, Other_Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(1, 0));

  Vector2D v = Vector2D::zero();

  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r,&p,v), 0, 0.001);
  EXPECT_EQ(v,Vector2D(0,-1));
}

TEST(COLLISION___get_minimum_dist_and_direction, Other_Other_Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(1, 2));

  Vector2D v = Vector2D::zero();

  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r,&p,v), 0, 0.001);
  EXPECT_EQ(v,Vector2D(0,1));
}

TEST(COLLISION___get_minimum_dist_and_direction, Other_Other_Other_Point) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point(Vector2D(0, 1));

  Vector2D v = Vector2D::zero();

  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r,&p,v), 0, 0.001);
  EXPECT_EQ(v,Vector2D(-1,0));
}

TEST(COLLISION___get_minimum_dist_and_direction, Line) {
  Rectangle r(Vector2D(0, 0),2,2);

  Polygone p;
  p.add_point( {Vector2D(2, 1), Vector2D(3, 1)} );

  Vector2D v = Vector2D::zero();

  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r,&p,v), 0, 0.001);
  EXPECT_EQ(v,Vector2D(1,0));
}

TEST(COLLISION___get_minimum_dist_and_direction, Same) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(0, 0), 2, 2);

  Vector2D v = Vector2D::zero();
  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r1, &r2, v), -2.0, 0.01);
  EXPECT_EQ(v, Vector2D(-1, 0));
}

TEST(COLLISION___get_minimum_dist_and_direction, Diagonal) {
  Rectangle r1(Vector2D(0, 0), 2, 2);
  Rectangle r2(Vector2D(1, 1), 2, 2);

  Vector2D v = Vector2D::zero();
  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r1, &r2, v), -1, 0.01);
  EXPECT_EQ(v, Vector2D(0, 1));
}

TEST(COLLISION___get_minimum_dist_and_direction, Rectangle_Triangle) {
  Rectangle r(Vector2D(0, 0), 2, 2);

  Polygone p;
  p.add_point( {Vector2D(1, 1), Vector2D(3, 0), Vector2D(3, 2.5)} );

  Vector2D v = Vector2D::zero();

  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r,&p,v), -1, 0.001);
  EXPECT_EQ(v, Vector2D(1, 0));
}

TEST(COLLISION___get_minimum_dist_and_direction, Big) {
  Rectangle r1(Vector2D(0, 0), 20, 20);
  Rectangle r2(Vector2D(10, 10), 20, 20);

  Vector2D v = Vector2D::zero();

  EXPECT_NEAR(Collision::get_minimum_dist_and_direction(&r1,&r2,v), -10, 0.001);
  EXPECT_EQ(v, Vector2D(0, 1));
}


// =========================================================
//
// MAIN
//
// =========================================================

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
