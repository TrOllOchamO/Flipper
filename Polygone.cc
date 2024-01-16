#include "Polygone.h"


// CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
// CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
// CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
// CONSTRUIRE LES POLYGONES DANS LE SENS HORRAIRES !!!!!
void Polygone::add_point(Vector2D point) {
  points.push_back(point);
  if(is_convex()){
    convex = true;
    concave_points.clear();
  } else {
    convex = false;
    concave_points = triangulate();
  }
}

void Polygone::add_points(std::vector<Vector2D> point) {
  for(auto p : point){
    points.push_back(p);
  }
  if(is_convex()){
    convex = true;
    concave_points.clear();
  } else {
    convex = false;
    concave_points = triangulate();
  }
}

void Polygone::clear(){
  points.clear();
}

bool Polygone::is_convex() const {
  int n = points.size();
  if(n<4) return true;

  bool hasNegative = false;
  bool hasPositive = false;

  for (int i = 0; i < n; i++) {
    const Vector2D& current = points[i];
    const Vector2D& next = points[(i+1)%n];
    const Vector2D& next_next = points[(i+2)%n];

    float crossProduct = (next - current).cross_product(next_next - next);

    if (crossProduct < 0) hasNegative = true; 
    if (crossProduct > 0) hasPositive = true;
    
    if (hasNegative && hasPositive) return false;
  }

  return true;
}

void Polygone::print(){
  std::cout << "[  ";
  for(auto p : points){
    std::cout << p << " ";
  }
  std::cout << " ]\n";
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

void Polygone::render(sf::RenderWindow &window, sf::Color color) const {
  if(convex){
    int n = points.size();
    sf::ConvexShape convex;
    convex.setPointCount(n);
    convex.setPosition(Vector2D(0,0));
    convex.setFillColor(color);
    for (int i=0; i<n; ++i) {
      convex.setPoint(i, points[i]);
    }
    window.draw(convex);
  
  } else {
    for(auto p : concave_points){
      p.render(window, color);   
    }
  }
}

void Polygone::rotate(float angle, Vector2D rotation_point, float dt) {
  if(convex){
    std::vector<Vector2D> new_points;
    float a = angle * dt;
    for (auto p : points){
      float nx = ((p.x-rotation_point.x) * std::cos(a) - (p.y-rotation_point.y) * std::sin(a)) + rotation_point.x;
      float ny = ((p.y-rotation_point.y) * std::cos(a) + (p.x-rotation_point.x) * std::sin(a)) + rotation_point.y;    
      new_points.push_back(Vector2D(nx, ny));
    }
    points.clear();   
    points = new_points;

  } else {
    for(auto &p : concave_points){
      p.rotate(angle, rotation_point, dt);
    }
  }
}

Polygone create_triangle(Vector2D a, Vector2D b, Vector2D c){
  Polygone p;
  p.add_points( {a, b, c} );
  return p;
}

std::vector<Polygone> Polygone::triangulate(){
  std::vector<Polygone> all_triangle;
  std::vector<Vector2D> all_points;
  all_points = points;

  int n = all_points.size();
  int i = 0;

  while (n > 3) {
    if (is_ear(all_points, i)) {
      all_triangle.push_back(create_triangle(all_points[i], all_points[(i+n-1)%n], all_points[(i+1)%n]));
      all_points.erase(all_points.begin() + i);
      n--;
    } else {
      i = (i + 1) % n;
    }
  }

  all_triangle.push_back(create_triangle(all_points[0], all_points[1], all_points[2]));
  return all_triangle;
}

bool Polygone::is_ear(const std::vector<Vector2D>& polygon, int index) {
  int n = polygon.size();
  int previous = (index - 1) % n;
  int next = (index + 1) % n;

  Vector2D a = polygon[previous];
  Vector2D b = polygon[index];
  Vector2D c = polygon[next];

  for (int i = 0; i < n; i++) {
    if (i != previous && i != index && i != next) {
      if (point_inside_triangle(a, b, c, polygon[i]) || is_outside(a,b,c)) {
        return false;
      }
    }
  }

  return true;
}

bool Polygone::point_inside_triangle(Vector2D a, Vector2D b, Vector2D c, Vector2D point) {
  float ab = (b-a).cross_product(point-a);
  float bc = (c-b).cross_product(point-b);
  float ca = (a-c).cross_product(point-c);

  return (ab>=0 && bc>=0 && ca>=0) || (ab<=0 && bc<=0 && ca<=0);
}

bool Polygone::is_outside(Vector2D a, Vector2D b, Vector2D c){
  Vector2D edge1 = b - a;
  Vector2D edge2 = c - b;

  float crossProduct = edge1.cross_product(edge2);

  if (crossProduct > 0) {
    return false;
  } 

  return true;
}
