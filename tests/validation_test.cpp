#include <gtest/gtest.h>

#include "sequential_tree.h"

TEST(SequentialTest, pruebaSimple) {
  SequentialTree* arbol_datos;
  arbol_datos = new SequentialTree({18, 0, 17});
  arbol_datos->left = new SequentialTree({25, 20});
  arbol_datos->right = new SequentialTree({17, 19, 0});
  arbol_datos->left->left = new SequentialTree({20, 22});
  arbol_datos->left->right = new SequentialTree({23});

  EXPECT_EQ(23, arbol_datos->calculateMaxAverage());
  delete arbol_datos;
}

TEST(SequentialTest, pruebaInsert) {
  SequentialTree* arbol_datos = new SequentialTree({18, 0, 17});
  arbol_datos->insert({25, 20});
  arbol_datos->insert({20, 22});
  arbol_datos->insert({23});
  arbol_datos->insert({17, 19, 0});

  EXPECT_EQ(23, arbol_datos->calculateMaxAverage());
  delete arbol_datos;
}

TEST(SequentialTest, pruebaVacio) {
  SequentialTree* arbol_vacio = new SequentialTree({});
  EXPECT_EQ(0.0, arbol_vacio->calculateMaxAverage());
  delete arbol_vacio;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
