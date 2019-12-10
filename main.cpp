#include <fstream>
#include <iostream>
#include <vector>
#include "CSVReader.h"
#include "TriangleNet.h"
#include "VPoint.h"
#include "VTriangle.h"
using namespace std;

bool cmpPoint(VPoint p0, VPoint p1) {
  return p0.getX() < p1.getX();
}

int main() {
  vector<VPoint> pts = CSVReader::readCSVToPts("data\\pts2.csv");
  TriangleNet tn(pts);
  tn.buildTriangleNet();
  tn.triangleGrownth();
  vector<VTriangle> triangles = tn.getTriangles();
  cout << triangles.size() << "\n";
  ofstream out("data\\triangles.txt");
  for (auto triangle : triangles) {
    vector<VPoint> points = triangle.getPoints();
    string str =
        to_string(points[0].getX()) + " " + to_string(points[0].getY()) + "," +
        to_string(points[1].getX()) + " " + to_string(points[1].getY()) + "," +
        to_string(points[2].getX()) + " " + to_string(points[2].getY()) + "\n";
    out << str.c_str();
  }
  out.close();
  system("pause");
  return 0;
}