#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>
#include <string>

using namespace std;

class Circle {
public:

  vector<vector<double>> points;

  vector<double> center;

  double radius;

  bool onCenter;

  /**
   * Constructor
   */
  Circle();

  /**
   * Destructor
   */
  virtual ~Circle();

  void AddPoint(double x, double y);

  void CalculateCenterAndRadius();

  int fRand(double fMin, double fMax);
  
};

#endif