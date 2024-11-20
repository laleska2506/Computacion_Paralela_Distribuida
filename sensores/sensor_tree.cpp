#include "sensor_tree.h"

SensorTree::SensorTree(const std::initializer_list<double>& data) : sensor_data(data), left(nullptr), right(nullptr) {}

double SensorTree::calculateMaxAverage() {
  return calculateMaxAverageInternal(this);
}

// void SensorTree::insertInternal(SensorTree* node_ptr, const std::vector<double>& data){
//     if (node_ptr == nullptr) node_ptr = new SensorTree(data);

//     // suma los datos del sensor en el nodo actual
//     double sum = 0.0;
//     int cont = 0;
//     for (int value : node_ptr->sensor_data) {
//         if(value > 0.0){
//           sum += value;
//           cont += 1;
//         }
//     }
//     double current_avg = 0.0;
//     if(cont > 0)
//       current_avg = sum / (double)cont;

//     // llamadas recursivas para los hijos
//     double max_avg_left = calculateMaxAverageInternal(node_ptr->left);
//     double max_avg_right = calculateMaxAverageInternal(node_ptr->right);
// }

// void SensorTree::insert(const std::vector<double>& data){

//     sensor_data = data;
// }

SensorTree::~SensorTree() {
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}