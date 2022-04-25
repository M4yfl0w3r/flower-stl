#pragma once

#include <iostream>
#include <vector>

// Binary max heap
// The root note is the largest element in the tree
class Flower_Max_Heap
{

public:
  Flower_Max_Heap();
  Flower_Max_Heap(std::size_t);
  Flower_Max_Heap(std::initializer_list<int>);

  ~Flower_Max_Heap() = default;

public:
  auto flower_insert(int) -> void;
  auto flower_extract_max() -> int;  
  auto flower_heap_sort() -> std::vector<int>;

/*
  auto flower_get_item(std::size_t) const -> int;
  auto search(int) const -> std::size_t;
*/

private:
  auto get_left_child(std::size_t) const -> std::size_t;
  auto get_right_child(std::size_t) const -> std::size_t;
  auto get_parent(std::size_t) const -> std::size_t;
  auto flower_heapify(std::size_t) -> void;

private:
  std::vector<int> m_elements;
  std::size_t m_size;
  std::size_t m_capacity;

  friend std::ostream& operator<<(std::ostream& stream, const Flower_Max_Heap& heap);
};

// make a cute tree
std::ostream& operator<<(std::ostream& stream, const Flower_Max_Heap& heap)
{
  for (const auto& el : heap.m_elements)
  {
    stream << el << ' ';
  }
  
  stream << '\n';

  return stream;
}
