#include "Polygone.h"

bool Polygone::add_point(Vector2D point) {
  if(point.x<0 || point.y<0){
    return false;
  }
  points.push_back(point);
  return true;
}

bool Polygone::is_convex(){
  int n = points.size();
  int comp = true;
  if(n<4){
    return true;
  }
  if((points[1].x - points[0].x) * (points[2].y - points[1].y) - (points[1].y - points[0].y) * (points[2].x - points[1].x) < 0){
    comp = false;
  }
  for(int i=0; i<n; i++){
    Vector2D a = points[i%n];
    Vector2D b = points[i+1%n];
    Vector2D c = points[i+2%n];
    double res = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
    if((comp && res<0) || (!comp && res>=0)) return false;  
  }
  return true;
}

Vector2D Polygone::get_center() const {
  Vector2D sum_center(0,0);
  double sum_weight = 0.0;
  int n = points.size();
  for(int i=0; i<n; i++){
    Vector2D a = points[i-1 % n];
    Vector2D b = points[i % n];
    Vector2D c = points[i+1 % n];
    double w = (b-c).length() + (b-a).length();
    sum_center += b * w;
    sum_weight += w;
  }
  sum_center.x/=sum_weight;
  sum_center.y/=sum_weight;
  return sum_center;
}

Vector2D Polygone::get_futhest_point(const Vector2D &direction) const {
  const std::vector<Vector2D> vertices = points;
  Vector2D futhest_point = vertices[0];
  float best_score = direction.dot(futhest_point);

  // search for a point with a superior score
  for (int i = 1; i < 4; ++i) {
    const float new_score = direction.dot(vertices[i]);
    if (new_score > best_score) {
      best_score = new_score;
      futhest_point = vertices[i];
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
  convex.setPosition(get_pos().to_sfml());
  convex.setFillColor(color);
  for (int i=0; i<n; ++i) {
    convex.setPoint(i, points[i].to_sfml());
  }
  window.draw(convex);
} 
