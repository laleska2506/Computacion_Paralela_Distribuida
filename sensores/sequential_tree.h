#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

#include "sensor_tree.h"

class SequentialTree : public SensorTree {
  public:

  SequentialTree(const std::initializer_list<double>&);
  double calculateMaxAverageInternal(SensorTree* node_ptr) override;
};

#endif  // SEQUENTIAL_H
