#include <benchmark/benchmark.h>

#include <random>
#include <thread>

#include "sequential_tree.h"

static int* randomInput = nullptr;
static const int MAXIMO_VALOR = 5;
static const int NUMERO_ELEMENTOS = 100000000;

void inicializa() {
  /*std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> uni_dis(1, MAXIMO_VALOR);

  if(randomInput == nullptr) {
    randomInput = new int[NUMERO_ELEMENTOS];
    for(int i = 0; i < NUMERO_ELEMENTOS; ++i) {
      randomInput[i] = uni_dis(gen);
    }
  }*/
}

void finaliza() {
  /*if(randomInput != nullptr) {
    delete[] randomInput;
    randomInput = nullptr;
  }*/
}

static void BM_secuencial(benchmark::State& state) {
  int histograma[MAXIMO_VALOR] = {0};

  /*for(auto _ : state) {
    for(int idx = 0; idx < NUMERO_ELEMENTOS; idx++) {
      histograma[randomInput[idx] - 1]++;
    }
    benchmark::DoNotOptimize(histograma);
  }*/
}


BENCHMARK(BM_secuencial)->UseRealTime()->Unit(benchmark::kMillisecond);

int main(int argc, char** argv) {
  inicializa();
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  finaliza();
}
