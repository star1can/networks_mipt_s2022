#include "graph.hpp"

Graph::Graph(size_t vertices_num) {
  graph_.resize(vertices_num);
}

void Graph::AddEdge(size_t from, size_t to, int64_t cost) {
  graph_[from].push_back({from, to, cost});
}

const std::vector<Graph::Edge> &Graph::GetNeighbours(size_t v) const {
  return graph_[v];
}

void Graph::UpdateCost(size_t from, size_t to, int64_t new_cost) {
  for (auto &edge: graph_[from]) {
    if (edge.to == to) {
      edge.cost = new_cost;
    }
  }
}

size_t Graph::GetVertexCount() const {
  return graph_.size();
}