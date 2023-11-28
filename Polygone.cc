#include "Polygone.h"

bool Polygone::add_point(Vector2D point) {
  if(point.x<0 || point.y<0){
    return false;
  }
  points.push_back(point);
  return true;
}

// vvv ca fonctionne pas ca vvv
double get_angle_from_points(Vector2D a, Vector2D b, Vector2D c){
  double ra = (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
  double rb = (b.x-c.x)*(b.x-c.x) + (b.y-c.y)*(b.y-c.y);
  double rc = (c.x-a.x)*(c.x-a.x) + (c.y-a.y)*(c.y-a.y);

  double res = std::acos( (ra+rb-rc) / sqrt(4*ra*rb) ) * 180/3.141592653589793238462643383279502884;
  std::cout << res << "\n";
  return res;
}

bool Polygone::is_convex(){
  int n = points.size();
  if(n<4){
    return true;
  }
  for(int i=0; i<n; i++){
    if(get_angle_from_points(points[i%n], points[i+1%n], points[i+2%n]) > 180.0 ){
      return false;
    }
  }
  return true;
}

Vector2D Polygone::get_center() const {
  return Vector2D(0,0);
}

Vector2D Polygone::get_futhest_point(const Vector2D &direction) const {
  return Vector2D(0,0);
}