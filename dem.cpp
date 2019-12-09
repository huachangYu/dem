#include <iostream>
#include <vector>
#include "CSVReader.h"
#include "TriangleNet.h"
#include "VEdge.h"
#include "VPoint.h"
#include "VTriangle.h"
using namespace std;

int main() {
  vector<VPoint> pts = CSVReader::readCSVToPts("data\\pts.csv");
  TriangleNet tn(pts);
  tn.buildTriangleNet();
  VEdge v1(1, 2, 3, 4);
  VEdge v2(1, 2, 3, 4);
  cout << (v1 == v2) << endl;
  system("pause");
  return 0;
}