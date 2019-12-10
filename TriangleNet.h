#pragma once
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include "VEdge.h"
#include "VPoint.h"
#include "VTriangle.h"

using namespace std;

class TriangleNet {
 private:
  vector<VPoint> points;
  vector<VTriangle> triangles;
  map<VEdge, pair<int, int>> edgeNeighbors;

 public:
  TriangleNet(vector<VPoint> points);
  ~TriangleNet();
  void buildTriangleNet();
  void triangleGrownth();
  vector<VTriangle> getTriangles();
  bool relativeRight(VPoint pt, VEdge edge);
  void show();
};

TriangleNet::TriangleNet(vector<VPoint> points) {
  this->points = points;
}

TriangleNet::~TriangleNet() {}

void TriangleNet::buildTriangleNet() {}

vector<VTriangle> TriangleNet::getTriangles() {
  return this->triangles;
}

bool TriangleNet::relativeRight(VPoint pt, VEdge edge) {
  double dx0 = edge.getEndPoint().getX() - edge.getStartPoint().getX();
  double dy0 = edge.getEndPoint().getY() - edge.getStartPoint().getY();
  double dx1 = pt.getX() - edge.getStartPoint().getX();
  double dy1 = pt.getY() - edge.getStartPoint().getY();
  return dx0 * dy1 - dx1 * dy0 < 0;
}

void TriangleNet::triangleGrownth() {
  queue<pair<int, int>> outlineEdgesInd;
  queue<pair<int, int>> nextOutlineEdgesInd;
  vector<vector<bool>> visit(points.size(), vector<bool>(points.size(),false));
  // find the nearest point around a certain point
  VPoint tPoint = points[0];
  double minPointInd = 1;
  double minDistance = tPoint.distance(points[minPointInd]);
  for (int i = 2; i < points.size(); i++) {
    if (tPoint.distance(points[i]) < minDistance) {
      minDistance = tPoint.distance(points[i]);
      minPointInd = i;
    }
  }
  outlineEdgesInd.push(make_pair(0, minPointInd));
  // start growing
  while (outlineEdgesInd.size() > 0) {
    pair<int, int> tEdgeInd = outlineEdgesInd.front();
    outlineEdgesInd.pop();
    for (int j = 0; j < points.size(); j++) {
      if (!visit[tEdgeInd.first][tEdgeInd.second]) {
        if (!relativeRight(points[j], VEdge(points[tEdgeInd.first],
                                            points[tEdgeInd.second]))) {
          continue;
        }
        VTriangle tTriangle(points[tEdgeInd.first], points[tEdgeInd.second],
                            points[j]);
        bool containsPoint = false;
        for (int k = 0; k < points.size(); k++) {
          if (k == tEdgeInd.first || k == tEdgeInd.second || k == j) {
            continue;
          }
          if (tTriangle.circumcircleContains(points[k])) {
            containsPoint = true;
            break;
          }
        }
        if (!containsPoint) {
          triangles.push_back(tTriangle);
          outlineEdgesInd.push(make_pair(tEdgeInd.first, j));
          outlineEdgesInd.push(make_pair(j, tEdgeInd.second));
          break;
        }
      }
    }
    cout<<triangles.size()<<"\n";
    visit[tEdgeInd.first][tEdgeInd.second]=true;
    visit[tEdgeInd.second][tEdgeInd.first]=true;
  }
}
