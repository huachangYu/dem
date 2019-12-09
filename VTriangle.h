#include <String>
#include <vector>
#include "VPoint.h"
class VTriangle {
 private:
  std::vector<VPoint> points;

 public:
  VTriangle();
  VTriangle(double x0, double y0, double x1, double y1, double x2, double y2);
  ~VTriangle();
  std::vector<VPoint> getPoints();
  std::string toString();
};
VTriangle::VTriangle() {}
VTriangle::VTriangle(double x0,
                   double y0,
                   double x1,
                   double y1,
                   double x2,
                   double y2) {
  points.push_back(VPoint(x0, y0));
  points.push_back(VPoint(x1, y1));
  points.push_back(VPoint(x2, y2));
}

VTriangle::~VTriangle() {}

std::vector<VPoint> VTriangle::getPoints() {
  return points;
}
std::string VTriangle::toString() {
  return "VTriangle:" + std::to_string(points[0].getX()) + " " +
         std::to_string(points[0].getY()) + "," +
         std::to_string(points[1].getX()) + " " +
         std::to_string(points[1].getY()) + "," +
         std::to_string(points[2].getX()) + " " +
         std::to_string(points[2].getY());
}
