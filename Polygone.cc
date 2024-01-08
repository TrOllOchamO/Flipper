#include "Polygone.h"

void Polygone::add_point(Vector2D point) {
  points.push_back(point+get_pos());
}

void Polygone::clear(){
  points.clear();
}

bool Polygone::is_convex(){
  int n = points.size();
  if(n<4){
    return true;
  }

  bool hasNegative = false;
  bool hasPositive = false;

  for (int i = 0; i < n; i++) {
    const Vector2D& current = points[i];
    const Vector2D& next = points[(i+1)%n];
    const Vector2D& nextNext = points[(i+2)%n];

    Vector2D edge1 = next - current;
    Vector2D edge2 = nextNext - next;

    float crossProduct = edge1.cross_product(edge2);

    if (crossProduct < 0) {
      hasNegative = true;
    } else if (crossProduct > 0) {
      hasPositive = true;
    }

    if (hasNegative && hasPositive) {
      return false;
    }
  }

  return true;
}

Vector2D Polygone::get_center() const {
  Vector2D sum(0,0);
  int n = points.size();
  if(n==0) return sum;

  for(int i=0; i<n; i++){
    sum += points[i];
  }

  return sum / n;
}

Vector2D Polygone::get_futhest_point(const Vector2D &direction) const {
  int n = points.size();
  if(n==0) return Vector2D(0,0);

  Vector2D futhest_point = points[0];
  float best_score = direction.dot(futhest_point);

  // search for a point with a superior score
  for (int i = 1; i < n; ++i) {
    const float new_score = direction.dot(points[i]);
    if (new_score > best_score) {
      best_score = new_score;
      futhest_point = points[i];
    }
  }

  return futhest_point;
}

void Polygone::render(sf::RenderWindow &window, sf::Color color){
  if(!is_convex()){
    std::cerr << "Polygone non convex\n";
    return;
  } 
  int n = points.size();
  sf::ConvexShape convex;
  convex.setPointCount(n);
  convex.setPosition(Vector2D(0,0));
  convex.setFillColor(color);
  for (int i=0; i<n; ++i) {
    convex.setPoint(i, points[i]);
  }
  window.draw(convex);
} 

void Polygone::rotate(float angle, float dt) {
  std::vector<Vector2D> new_points;
  float a = angle * dt;
  for (auto p : points){
    float x = (p.x-rotation_point.x) * std::cos(a) - (p.y-rotation_point.y) * std::sin(a);
    float y = (p.y-rotation_point.y) * std::cos(a) + (p.x-rotation_point.x) * std::sin(a);
    Vector2D np(x,y);
    new_points.push_back(np+rotation_point);
  }
  points.clear();
  points = new_points;
}