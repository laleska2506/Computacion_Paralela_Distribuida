#include "paralela_tree.h"
#include <omp.h>
#include <algorithm>
#include <vector>

ParalelaTree::ParalelaTree(const std::vector<double>& data)
    : SensorTree(data), contadorEstaciones(1) {}

double ParalelaTree::calculateMaxAverage() {
  return calculateMaxAverageInternal(this);
}

double ParalelaTree::calculateMaxAverageInternal(SensorTree* node_ptr) {
  if (node_ptr == nullptr) return 0.0;

  // suma los datos del sensor en el nodo actual
  double sum = 0.0;
  int cont = 0;

  // Paralelizamos el cálculo de la suma y el conteo de datos
  #pragma omp parallel for reduction(+:sum, cont)
  for (size_t i = 0; i < node_ptr->sensor_data.size(); i++) {
    if (node_ptr->sensor_data[i] > 0.0) {
      sum += node_ptr->sensor_data[i];
      cont += 1;
    }
  }

  // obtenemos promedio
  double current_avg = 0.0;
  if (cont > 0) current_avg = sum / (double)cont;

  // inicializamos valores para las ramas
  double max_avg_left = 0.0, max_avg_right = 0.0;

  // Paralelizamos las llamadas recursivas
  #pragma omp parallel sections
  {
    #pragma omp section
    {
      max_avg_left = calculateMaxAverageInternal(node_ptr->left);
    }
    #pragma omp section
    {
      max_avg_right = calculateMaxAverageInternal(node_ptr->right);
    }
  }

  // retornamos el máximo del promedio del nodo y sus hijos
  return std::max({current_avg, max_avg_left, max_avg_right});
}

void ParalelaTree::insert(const std::vector<double>& data) {
  insertInternal(this, data);
  contadorEstaciones++;
}


void ParalelaTree::insertInternal(SensorTree* node_ptr,
                                    const std::vector<double>& data) {
  if (node_ptr == nullptr) {
    #pragma omp critical
    {
      node_ptr = new ParalelaTree(data);
    }
    return;
  } else if (node_ptr->left == nullptr) {
    #pragma omp critical
    {
      node_ptr->left = new ParalelaTree(data);
    }
    return;
  } else if (node_ptr->right == nullptr) {
    #pragma omp critical
    {
      node_ptr->right = new ParalelaTree(data);
    }
    return;
  }

  // Paralelizamos el recorrido de las ramas izquierda y derecha
  #pragma omp task if (node_ptr->left != nullptr)
  {
    insertInternal(node_ptr->left, data);
  }
  #pragma omp task if (node_ptr->right != nullptr)
  {
    insertInternal(node_ptr->right, data);
  }

  #pragma omp taskwait
}
