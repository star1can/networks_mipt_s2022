#include <iostream>
#include <queue>
#include <fstream>
#include "graph.hpp"

std::vector<size_t> FindShortestPaths(size_t from, const Graph &graph) {
  std::queue<size_t> queue;
  std::vector<size_t> dist(graph.GetVertexCount(), 0);
  std::vector<bool> used(graph.GetVertexCount(), false);

  used[from] = true;
  queue.push(from);

  while (!queue.empty()) {

    auto curr = queue.front();
    queue.pop();

    for (const auto &edge: graph.GetNeighbours(curr)) {
      auto neighbour = edge.to;
      if (!used[neighbour]) {
        dist[neighbour] = dist[curr] + 1;
        queue.push(neighbour);
        used[neighbour] = true;
      }
    }

  }
  return dist;
}

size_t CountTreeDiameter(const Graph &tree) {
  auto dist = FindShortestPaths(0, tree);
  size_t most_dist = std::distance(dist.begin(), std::max_element(dist.begin(), dist.end()));
  dist = FindShortestPaths(most_dist, tree);
  return *std::max_element(dist.begin(), dist.end());
}

size_t CountNetworkDiameter(const Graph &network) {
  return CountTreeDiameter(network);
}

int main(int args, char *argv[]) {
  std::ifstream input(argv[1]);
  size_t u, v;
  Graph network(100);

  while (input >> u >> v) {
    network.AddEdge(u, v);
    network.AddEdge(v, u);
  }

  std::cout << "network diameter: " << CountNetworkDiameter(network) << std::endl;

  return 0;
}
