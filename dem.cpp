#include <iostream>
#include "VTriangle.h"
using namespace std;
int main() {
  VTriangle t = VTriangle(1.0,2.0,3.0,4.0,5.0,6.0);
  cout<<t.toString()<<"\n";
  system("pause");
  return 0;
}