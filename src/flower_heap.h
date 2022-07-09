#pragma once

#include <iostream>
#include <vector>
#include <optional>

class Flower_Max_Heap
{

public:
  Flower_Max_Heap() : m_elements{}, m_size{}, m_capacity{1} {}
  
  Flower_Max_Heap(std::size_t cap) : m_elements{}, m_size{0}, m_capacity{cap}
  {
    m_elements.reserve(m_capacity);
  }

  Flower_Max_Heap(std::initializer_list<int> list) : m_size {0}, m_capacity{list.size()}
  {
    m_elements.reserve(m_capacity * 2);

    for (const auto& el : list)
    {
      flower_insert(el);
    }
  }

  ~Flower_Max_Heap() = default;

public:
  auto flower_insert(int el) -> void
  {
    m_size++;
    m_elements.emplace_back(el);
    auto i = m_size - 1;

    while (i != 0 && m_elements[get_parent(i)] < m_elements[i])
    {
      std::swap(m_elements[i], m_elements[get_parent(i)]);
      i = get_parent(i);
    }
  }

  auto flower_insert(std::initializer_list<int> list) -> void
  {
    for (const auto& el : list)
    {
      flower_insert(el);
    }
  }

  auto flower_extract_max() -> int
  {
    if (m_size == 0) return -1;

    if (m_size == 1) 
    {
      m_size--;
      return m_elements[0];
    }
    else
    {
      int max = m_elements[0];

      m_elements[0] = m_elements[m_size - 1];
      m_elements.pop_back();
      m_size--;

      flower_heapify(0);

      return max;
    }
  }

  auto flower_heap_sort() -> std::vector<int>
  {
    std::vector<int> sorted;

    sorted.reserve(m_size);

    while (m_size > 0)
    {
      sorted.emplace_back(flower_extract_max());
    }

    return sorted;
  }

  auto flower_get_item(std::size_t index) const -> int
  {
    return m_elements[index];
  }

  auto flower_search(int value) const -> std::optional<std::size_t>
  {  
    for (std::size_t i = 0; i < m_size; i++)
    {
      if (value == m_elements[i]) 
      {
        return i;
      }
    }

    return {};
  }

  auto flower_is_empty() const -> bool
  {
    return (m_size == 0);
  }

public:
  auto get_capacity() const -> std::size_t
  {
    return m_capacity;
  }

  auto get_size() const -> std::size_t
  {
    return m_size;
  }

private:
  auto get_left_child(std::size_t index) const -> std::size_t
  {
    return 2 * index + 1;
  }

  auto get_right_child(std::size_t index) const -> std::size_t
  {
    return 2 * index + 2; 
  }

  auto get_parent(std::size_t index) const -> std::size_t
  {
    return (index - 1) / 2;
  }

  auto flower_heapify(std::size_t index) -> void
  {
    std::size_t left_child = get_left_child(index);
    std::size_t right_child = get_right_child(index);
    std::size_t largest = index;

    if (left_child < m_size && m_elements[left_child] > m_elements[largest])
    {
      largest = left_child; 
    }

    if (right_child < m_size && m_elements[right_child] > m_elements[largest])
    {
      largest = right_child;
    }

    if (largest != index)
    {
      std::swap(m_elements[index], m_elements[largest]);
      flower_heapify(largest);
    }
  }

private:
  std::vector<int> m_elements;
  std::size_t m_size;
  std::size_t m_capacity;

  friend std::ostream& operator<<(std::ostream&, const Flower_Max_Heap&);
};

std::ostream& operator<<(std::ostream& stream, const Flower_Max_Heap& heap)
{
  for (const auto& el : heap.m_elements)
  {
    stream << el << ' ';
  }
  
  stream << '\n';

  return stream;
}

