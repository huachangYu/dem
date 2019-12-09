#pragma once
#include <String>
#include <fstream>
#include <iostream>
#include <vector>
#include "VPoint.h"
class CSVReader {
 private:
  int status = 1;

 public:
  CSVReader();
  ~CSVReader();
  static std::vector<VPoint> readCSVToPts(const char* csvFilePath,
                                          bool hasHead = false) {
    std::vector<VPoint> points;
    FILE* fp;
    fp = fopen(csvFilePath, "r");
    int pid;
    double x, y, h;
    if (hasHead) {
    }
    while (true) {
      fscanf(fp, "%d,%lf,%lf,%lf", &pid, &h, &x, &y);
      points.push_back(VPoint(x, y, h));
      if (feof(fp)) {
        break;
      }
    }
    fclose(fp);
    return points;
    }
  };

  CSVReader::CSVReader() {}

  CSVReader::~CSVReader() {}