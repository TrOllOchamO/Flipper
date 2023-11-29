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
    std::cout << res << "\n";
    if((comp && res<0) || (!comp && res>=0)) return false;  
  }
  return true;
}

Vector2D Polygone::get_center() const {
  return Vector2D(0,0);
}

Vector2D Polygone::get_futhest_point(const Vector2D &direction) const {
  return Vector2D(0,0);
}