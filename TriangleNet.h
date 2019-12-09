#pragma once
#include <vector>
#include <map>
#include <utility>
#include "VPoint.h"
#include "VEdge.h"
#include "VTriangle.h"

using namespace std;

class TriangleNet {
 private:
  vector<VPoint> points;
  vector<VTriangle> triangles;
  map<VEdge,pair<int,int> > edgeInd;

 public:
  TriangleNet(std::vector<VPoint> points);
  ~TriangleNet();
  void buildTriangleNet();
  void show();
};

TriangleNet::TriangleNet(std::vector<VPoint> points) {
  this->points = points;
}

TriangleNet::~TriangleNet() {}

void TriangleNet::buildTriangleNet() {}
