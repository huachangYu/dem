#pragma once
#include <cmath>
#include <iostream>
using namespace std;
#include "VPoint.h"
#include "VTriangle.h"

class VEdge {
 private:
  const double eps = 0.00001;
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
bool VEdge::operator==(const VEdge& other) {
  VPoint tEndPoint = other.endPoint;
  VPoint tStartPoint = other.startPoint;
  return (double)abs(startPoint.getX() - tStartPoint.getX()) < eps &&
         (double)abs(startPoint.getY() - tStartPoint.getY()) < eps &&
         (double)abs(endPoint.getX() - tEndPoint.getX()) < eps &&
         (double)abs(endPoint.getY() - tEndPoint.getY()) < eps;
}
