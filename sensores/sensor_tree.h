#ifndef BASE_H
#define BASE_H

#include <vector>
#include <initializer_list>

class SensorTree {
  public:

  std::vector<double> sensor_data; // datos de los sensores en esta sub-estación
  SensorTree* left;
  SensorTree* right;

  SensorTree(const std::initializer_list<double>&);
  virtual double calculateMaxAverageInternal(SensorTree*) = 0;
  double calculateMaxAverage();
  // void insertInternal(SensorTree*, const std::vector<double>&);
  // void insert(const std::vector<double>&);
  ~SensorTree();
};

#endif  // BASE_H
