#include <iostream>
#include "circle.hpp"
#include <math.h>

using namespace std;

Circle::Circle() {

  radius = 0.0;
  center = {0.0, 0.0};
  onCenter = false;
}

void Circle::AddPoint(double x, double y) {
  
  //cout << " size: " << points.size() << endl;
  if (points.size() < 100) {
    vector<double> point = {x, y};
    points.push_back(point);
    if (points.size() == 100) {
      CalculateCenterAndRadius();
    }
  }

}

void Circle::CalculateCenterAndRadius() {

  int i=0;
  double avg_center_x = 0.0;
  double avg_center_y = 0.0;
  double avg_radius = 0.0;

  double qtdPoints = 10.0;

  while (i < qtdPoints) {

    int ip1 = fRand(5, 30);
    int ip2 = fRand(40, 60);
    int ip3 = fRand(70, 99);

    cout << "--------------" << ip1<<" "<<ip2<<" "<<ip3<<endl;
    
    double x1, x2, x3, y1, y2, y3;
    x1 = points[ip1][0];
    y1 = points[ip1][1];
    x2 = points[ip2][0];
    y2 = points[ip2][1];
    x3 = points[ip3][0];
    y3 = points[ip3][1];

    //calculate the slopes

    double ma = (y2 - y1) / (x2 - x1);
    double mb = (y3 - y2) / (x3 - x2);

    // defining center using two lines perpendicular
    double X = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) / (2.0 * (mb - ma));

    double ya = -1.0/ma * (X - (x1+x2)/2.0) + (y1+y2)/2.0;

    avg_center_x += X;
    avg_center_y += ya;
    

    double delta_x = x1 - X;
    double delta_y = y1 - ya;

    avg_radius += sqrt(delta_x*delta_x + delta_y*delta_y);

    i += 1;
  }

  center[0] = avg_center_x/qtdPoints;
  center[1] = avg_center_y/qtdPoints;
  radius = avg_radius/qtdPoints;
}

int Circle::fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return (int) (fMin + f * (fMax - fMin));
}

Circle::~Circle() {}
