#ifndef PARALELA_H
#define PARALELA_H

#include "sensor_tree.h"

class ParalelaTree : public SensorTree {
 public:
  int contadorEstaciones;
  ParalelaTree(const std::vector<double>&);
  double calculateMaxAverageInternal(SensorTree* node_ptr) override;
  double calculateMaxAverage() override;
  void insertInternal(SensorTree*, const std::vector<double>&) override;
  void insert(const std::vector<double>&) override;
};

#endif  // PARALELA_H
