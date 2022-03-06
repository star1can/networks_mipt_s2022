#include "matrix_graph.hpp"

MatrixGraph::MatrixGraph(size_t vertices_num) : matrix_(vertices_num, std::vector<size_t>(vertices_num, 0)) {}

void MatrixGraph::AddEdge(size_t from, size_t to, size_t cost) {
  matrix_[from][to] = cost;
}

std::vector<size_t> MatrixGraph::GetNeighbours(size_t v) const {
  std::vector<size_t> neighbours;

  for (size_t i = 0; i < matrix_[v].size(); ++i) {
    if (matrix_[v][i] != 0) {
      neighbours.push_back(i);
    }
  }

  return neighbours;
}

std::vector<std::pair<size_t, size_t>> MatrixGraph::GetEdges() const {
  std::vector<std::pair<size_t, size_t>> edges;
  for (size_t i = 0; i < matrix_.size(); ++i) {
    std::vector<size_t> next;
    next = GetNeighbours(i);
    for (size_t u : next) {
      edges.emplace_back(i, u);
    }
  }
  return edges;
}

size_t MatrixGraph::VerticesCount() const {
  return matrix_.size();
}

size_t MatrixGraph::GetCost(size_t from, size_t to) const {
  return matrix_[from][to];
}

void MatrixGraph::UpdateCost(size_t from, size_t to, size_t new_cost) {
  matrix_[from][to] = new_cost;
}

