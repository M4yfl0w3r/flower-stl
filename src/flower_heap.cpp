#include "flower_heap.h"

Flower_Max_Heap::Flower_Max_Heap() 
: m_elements{}, m_size{0}, m_capacity{1} {}

Flower_Max_Heap::Flower_Max_Heap(std::size_t cap) 
: m_elements{}, m_size{0}, m_capacity{cap}
{
  m_elements.reserve(m_capacity);
}

Flower_Max_Heap::Flower_Max_Heap(std::initializer_list<int> list)
: m_size {0}, m_capacity{list.size()}
{
  m_elements.reserve(m_capacity * 2);

  for (const auto& el : list)
  {
    flower_insert(el);
  }
}

// Time complexity 
// Worst: -> max number of swaps -> height of the tree -> O(log(n))
// Best: -> no swaps -> O(1)
auto Flower_Max_Heap::flower_insert(int el) -> void
{
  m_size++;
  m_elements.emplace_back(el);
  std::size_t i = m_size - 1;

  while (i != 0 && m_elements[get_parent(i)] < m_elements[i])
  {
    std::swap(m_elements[i], m_elements[get_parent(i)]);
    i = get_parent(i);
  }
}
  
auto Flower_Max_Heap::flower_insert(std::initializer_list<int> list) -> void
{
  for (const auto& el : list)
  {
    flower_insert(el);
  }
}

auto Flower_Max_Heap::flower_extract_max() -> int
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

    // Change root to last element - to maintain complete binary tree
    m_elements[0] = m_elements[m_size - 1];
    m_elements.pop_back();
    m_size--;

    // Heapify - to maintain max binary tree 
    flower_heapify(0);

    return max;
  }
}

auto Flower_Max_Heap::flower_heap_sort() -> std::vector<int> 
{ 
  std::vector<int> sorted;

  sorted.reserve(m_size);

  while (m_size > 0)
  {
    sorted.emplace_back(flower_extract_max());
  }

  return sorted;
}

auto Flower_Max_Heap::flower_get_item(std::size_t index) const -> int 
{
  return m_elements[index];
}

auto Flower_Max_Heap::flower_search(int value) const -> std::optional<std::size_t>
{
  for (std::size_t i = 0; i < m_size; i++)
  {
    if (value == m_elements[i]) return i;
  }

  return {};
}

auto Flower_Max_Heap::flower_is_empty() const -> bool 
{
  return m_size == 0;
}

auto Flower_Max_Heap::get_capacity() const -> std::size_t
{
  return m_capacity;
}

auto Flower_Max_Heap::get_size() const -> std::size_t
{
  return m_size;
}

auto Flower_Max_Heap::flower_heapify(std::size_t index) -> void
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

auto Flower_Max_Heap::get_left_child(std::size_t index) const -> std::size_t
{
  return 2 * index + 1;
}

auto Flower_Max_Heap::get_right_child(std::size_t index) const -> std::size_t
{
  return 2 * index + 2; 
}

auto Flower_Max_Heap::get_parent(std::size_t index) const -> std::size_t
{
  return (index - 1) / 2;
}

std::ostream& operator<<(std::ostream& stream, const Flower_Max_Heap& heap)
{
  for (const auto& el : heap.m_elements)
  {
    stream << el << ' ';
  }
  
  stream << '\n';

  return stream;
}

