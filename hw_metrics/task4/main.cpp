#include <iostream>
#include <queue>
#include <fstream>
#include "matrix_graph.hpp"

size_t CountMinCut(MatrixGraph graph) {
  size_t cost = SIZE_T_MAX;

  size_t graph_size = graph.VerticesCount();
  std::vector<std::vector<size_t>> merged(graph_size);

  for (size_t i = 0; i < graph_size; ++i) {
    merged[i].push_back(i);
  }

  std::vector<bool> exists(graph_size, true);

  for (size_t iter = 0; iter < graph_size - 1; ++iter) {
    std::vector<bool> in(graph_size, false);
    std::vector<size_t> weight(graph_size, 0);
    size_t prev = 0;

    for (size_t j = 0; j < graph_size - iter; ++j) {

      ssize_t v = -1;
      for (ssize_t i = 0; i < graph_size; ++i) {
        if (exists[i] && !in[i] && (v == -1 || weight[i] > weight[v])) {
          v = i;
        }
      }

      if (j == graph_size - iter - 1) {

        if (weight[v] < cost) {
          cost = weight[v];
        }

        merged[prev].insert(merged[prev].end(), merged[v].begin(), merged[v].end());
        for (size_t i = 0; i < graph_size; ++i) {
          size_t add = graph.GetCost(v, i);

          graph.UpdateCost(prev, i, graph.GetCost(prev, i) + add);
          graph.UpdateCost(i, prev, graph.GetCost(i, prev) + add);
        }
        exists[v] = false;
      } else {
        in[v] = true;
        for (size_t i = 0; i < graph_size; ++i) {
          weight[i] += graph.GetCost(v, i);
        }
        prev = v;
      }
    }
  }
  return cost;
}

size_t CountNetworkConnectivity(const MatrixGraph &network) {
  return CountMinCut(network);
}

int main(int args, char *argv[]) {
  std::ifstream input(argv[1]);
  size_t u, v;
  MatrixGraph network(100);

  while (input >> u >> v) {
    network.UpdateCost(u, v, network.GetCost(u, v) + 1);
    network.UpdateCost(v, u, network.GetCost(v, u) + 1);
  }

  std::cout << "network connectivity: " << CountNetworkConnectivity(network) << std::endl;

  return 0;
}
