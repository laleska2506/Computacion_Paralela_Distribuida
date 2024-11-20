#include "sequential_tree.h"

SequentialTree::SequentialTree(const std::initializer_list<double>& data) : SensorTree(data) { }

double SequentialTree::calculateMaxAverageInternal(SensorTree* node_ptr) {
    if (node_ptr == nullptr) return 0.0;

    // suma los datos del sensor en el nodo actual
    double sum = 0.0;
    int cont = 0;
    for (int value : node_ptr->sensor_data) {
        if(value > 0.0){
          sum += value;
          cont += 1;
        }
    }
    double current_avg = 0.0;
    if(cont > 0)
      current_avg = sum / (double)cont;

    // llamadas recursivas para los hijos
    double max_avg_left = calculateMaxAverageInternal(node_ptr->left);
    double max_avg_right = calculateMaxAverageInternal(node_ptr->right);

    return std::max(std::max(current_avg, max_avg_left), max_avg_right);
}
