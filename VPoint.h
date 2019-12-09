#include <string>
class VPoint {
 private:
  double x, y;

 public:
  VPoint(/* args */);
  VPoint(double x, double y);
  ~VPoint();
  double getX();
  double getY();
  std::string toString();
};

VPoint::VPoint(/* args */) {}
VPoint::VPoint(double x, double y) {
  this->x = x;
  this->y = y;
}
VPoint::~VPoint() {}
double VPoint::getX() {
  return x;
}
double VPoint::getY() {
  return y;
}
std::string VPoint::toString() {
  return "Point:" + std::to_string(x) + "," + std::to_string(y);
}