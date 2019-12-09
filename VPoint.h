#pragma once
#include <string>

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
  std::string toString();
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

std::string VPoint::toString() {
  return "Point:" + std::to_string(x) + "," + std::to_string(y);
}