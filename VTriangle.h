#pragma once
#include <String>
#include <utility>
#include <vector>
#include "VEdge.h"
#include "VPoint.h"

using namespace std;

class VTriangle {
 private:
  vector<VPoint> points;
  pair<double, pair<double, double>> circumcircle;

 public:
  VTriangle();
  VTriangle(double x0, double y0, double x1, double y1, double x2, double y2);
  VTriangle(VPoint pt0, VPoint pt1, VPoint pt2);
  ~VTriangle();
  vector<VPoint> getPoints();
  string toString();
  pair<double, pair<double, double>> getCircumcircle();
  bool contains(VPoint point);
  bool circumcircleContains(VPoint point);
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

VTriangle::VTriangle(VPoint pt0, VPoint pt1, VPoint pt2) {
  points.push_back(pt0);
  points.push_back(pt1);
  points.push_back(pt2);
}

VTriangle::~VTriangle() {}

vector<VPoint> VTriangle::getPoints() {
  return points;
}
string VTriangle::toString() {
  return "VTriangle:" + to_string(points[0].getX()) + " " +
         to_string(points[0].getY()) + "," + to_string(points[1].getX()) + " " +
         to_string(points[1].getY()) + "," + to_string(points[2].getX()) + " " +
         to_string(points[2].getY());
}
pair<double, pair<double, double>> VTriangle::getCircumcircle() {
  if (this->circumcircle.first != 0) {
    return this->circumcircle;
  }
  VPoint pt0 = points[0];
  VPoint pt1 = points[1];
  VPoint pt2 = points[2];
  double radius = -1;
  double center_x = -1, center_y = -1;
  double a = 2 * (pt1.getX() - pt0.getX());
  double b = 2 * (pt1.getY() - pt0.getY());
  double c = pt1.getX() * pt1.getX() + pt1.getY() * pt1.getY() -
             pt0.getX() * pt0.getX() - pt0.getY() * pt0.getY();
  double d = 2 * (pt2.getX() - pt1.getX());
  double e = 2 * (pt2.getY() - pt1.getY());
  double f = pt2.getX() * pt2.getX() + pt2.getY() * pt2.getY() -
             pt1.getX() * pt1.getX() - pt1.getY() * pt1.getY();
  center_x = (b * f - e * c) / (b * d - e * a);
  center_y = (d * c - a * f) / (b * d - e * a);
  radius = sqrt((center_x - pt0.getX()) * (center_x - pt0.getX()) +
                (center_y - pt0.getY()) * (center_y - pt0.getY()));
  this->circumcircle = make_pair(radius, make_pair(center_x, center_y));
  return this->circumcircle;
}

bool VTriangle::contains(VPoint point) {
  if (points[0] == point || points[1] == point) {
    return false;
  }
  double vec0_x = points[1].getX() - points[0].getX();
  double vec0_y = points[1].getY() - points[0].getY();
  double vec1_x = points[2].getX() - points[0].getX();
  double vec1_y = points[2].getY() - points[0].getY();
  double vec_pt_x = point.getX() - points[0].getX();
  double vec_pt_y = point.getY() - points[0].getY();
  double a = vec1_x * vec0_y - vec0_x * vec1_y;
  double b = vec_pt_x * vec0_y - vec0_x * vec_pt_y;
  double c = vec0_x * vec1_y - vec1_x * vec0_y;
  double d = vec_pt_x * vec1_y - vec1_x * vec_pt_y;
  return b / a + d / c < 1 && b / a + d / c > 0;
}

bool VTriangle::circumcircleContains(VPoint point) {
  const double eps=1e-9;
  pair<double, pair<double, double>> circle = this->getCircumcircle();
  double radius = circle.first;
  pair<double, double> position = circle.second;
  double dx = point.getX() - position.first,
         dy = point.getY() - position.second;
  return dx * dx + dy * dy < pow(radius-eps,2);
}