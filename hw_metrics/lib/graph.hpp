#pragma once
#include <vector>

class Graph {

 public:
  struct Edge {
    size_t from;
    size_t to;
    int64_t cost;
  };

 public:
  explicit Graph(size_t vertices_num);
  void AddEdge(size_t from, size_t to, int64_t cost = 0);
  void UpdateCost(size_t from, size_t to, int64_t new_cost);
  const std::vector<Edge> &GetNeighbours(size_t v) const;
  size_t GetVertexCount() const;

 private:
  std::vector<std::vector<Edge>> graph_;
};