#pragma once
#include <cmath>
#include <string>

using namespace std;

class VPoint {
 private:
  double x, y;
  double height;

 public:
  VPoint();
  VPoint(double x, double y);
  VPoint(double x, double y, double heigh);
  ~VPoint();
  double getX();
  void setX(double x);
  double getY();
  void setY(double y);
  double getHeight();
  void setHeight(double height);
  string toString();
  bool operator==(const VPoint& other);
  double distance(VPoint other);
};

VPoint::VPoint() {}

VPoint::VPoint(double x, double y) {
  this->x = x;
  this->y = y;
  this->height = -99999;
}

VPoint::VPoint(double x, double y, double height) {
  this->x = x;
  this->y = y;
  this->height = height;
}

VPoint::~VPoint() {}

double VPoint::getX() {
  return this->x;
}

double VPoint::getY() {
  return this->y;
}

double VPoint::getHeight() {
  return this->height;
}

void VPoint::setX(double x) {
  this->x = x;
}

void VPoint::setY(double y) {
  this->y = y;
}

void VPoint::setHeight(double h) {
  this->height = h;
}

string VPoint::toString() {
  return "Point:" + to_string(x) + "," + to_string(y);
}

bool VPoint::operator==(const VPoint& other) {
  const double eps = 1e-5;
  return (double)abs(this->x - other.x) < eps &&
         (double)abs(this->y - other.y) < eps;
}

double VPoint::distance(VPoint other){
  double dx=this->x-other.getX();
  double dy=this->y-other.getY();
  return sqrt(dx*dx+dy*dy);
}