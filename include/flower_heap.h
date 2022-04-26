#pragma once

#include <iostream>
#include <vector>
#include <optional>

class Flower_Max_Heap
{

public:
  Flower_Max_Heap();
  Flower_Max_Heap(std::size_t);
  Flower_Max_Heap(std::initializer_list<int>);

  ~Flower_Max_Heap() = default;

public:
  auto flower_insert(int) -> void;
  auto flower_insert(std::initializer_list<int>) -> void;
  auto flower_extract_max() -> int;  
  auto flower_heap_sort() -> std::vector<int>;
  auto flower_get_item(std::size_t) const -> int;
  auto flower_search(int) const -> std::optional<std::size_t>; 
  auto flower_is_empty() const -> bool;

public:
  auto get_capacity() const -> std::size_t;
  auto get_size() const -> std::size_t;

private:
  auto get_left_child(std::size_t) const -> std::size_t;
  auto get_right_child(std::size_t) const -> std::size_t;
  auto get_parent(std::size_t) const -> std::size_t;
  auto flower_heapify(std::size_t) -> void;

private:
  std::vector<int> m_elements;
  std::size_t m_size;
  std::size_t m_capacity;

  friend std::ostream& operator<<(std::ostream&, const Flower_Max_Heap&);
};

std::ostream& operator<<(std::ostream&, const Flower_Max_Heap&);
