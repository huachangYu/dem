#pragma once
#include <cmath>
#include "VPoint.h"
#include "VTriangle.h"

class VEdge {
 private:
  const double eps = 1e-6;
  VTriangle leftTriangle;
  VTriangle rightTriangle;
  VPoint startPoint, endPoint;

 public:
  VEdge(VPoint startPoint, VPoint endPoint);
  VEdge(double x0, double y0, double x1, double y1);
  ~VEdge();
  bool operator==(const VEdge& other);
  VPoint getStartPoint();
  VPoint getEndPoint();
  VTriangle getLeftTriangle();
  VTriangle getRightTriangle();
  void setLeftTriangle(VTriangle leftTriangle);
  void setRightTriangle(VTriangle rightTriangle);
};

VEdge::VEdge(VPoint startPoint, VPoint endPoint) {
  this->startPoint = startPoint;
  this->endPoint = endPoint;
}

VEdge::VEdge(double x0, double y0, double x1, double y1) {
  this->startPoint = VPoint(x0, y0);
  this->endPoint = VPoint(x1, y1);
}

VEdge::~VEdge() {}

VPoint VEdge::getEndPoint() {
  return endPoint;
}
VPoint VEdge::getStartPoint() {
  return startPoint;
}

VTriangle VEdge::getLeftTriangle() {
  return this->leftTriangle;
}
void VEdge::setLeftTriangle(VTriangle leftTriangle) {
  this->leftTriangle = leftTriangle;
}

VTriangle VEdge::getRightTriangle() {
  return this->rightTriangle;
}
void VEdge::setRightTriangle(VTriangle rightTriangle) {
  this->rightTriangle = rightTriangle;
}

bool VEdge::operator==(const VEdge& other) {
  VPoint tEndPoint = other.endPoint;
  VPoint tStartPoint = other.startPoint;
  return (double)abs(startPoint.getX() - tStartPoint.getX()) < eps &&
         (double)abs(startPoint.getY() - tStartPoint.getY()) < eps &&
         (double)abs(endPoint.getX() - tEndPoint.getX()) < eps &&
         (double)abs(endPoint.getY() - tEndPoint.getY()) < eps;
}
