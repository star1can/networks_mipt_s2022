#pragma once
#include <vector>

class MatrixGraph {
 public:
  explicit MatrixGraph(size_t vertices_num);
  void AddEdge(size_t from, size_t to, size_t cost = 1);
  size_t VerticesCount() const;
  std::vector<size_t> GetNeighbours(size_t v) const;
  std::vector<std::pair<size_t, size_t>> GetEdges() const;
  size_t GetCost(size_t from, size_t to) const;
  void UpdateCost(size_t from, size_t to, size_t new_cost);
 private:
  std::vector<std::vector<size_t>> matrix_;
};
