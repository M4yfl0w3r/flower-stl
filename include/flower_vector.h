#pragma once

#include <initializer_list>
#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <cstring>
#include <limits>

template<typename T> 
class Flower_Vector
{
public:
  typedef T * iterator;
  typedef const T* const_iterator;

public: 
  Flower_Vector();
  
  explicit Flower_Vector(T);

  Flower_Vector(const Flower_Vector<T>&);
  Flower_Vector(Flower_Vector<T>&&) noexcept;
  Flower_Vector(std::initializer_list<T>);

  ~Flower_Vector();

public: 
  iterator begin() noexcept;
  iterator end() noexcept;
  
  const_iterator const_begin() const noexcept;
  const_iterator const_end() const noexcept;

public: 
  auto flower_size() const -> std::size_t; 
  auto flower_max_size() const -> std::size_t;
  auto flower_capacity() const -> std::size_t; 
  bool flower_empty() const noexcept; 
  auto flower_reserve(std::size_t) -> void;
  auto shrink_to_fit() -> void;

public: 
  auto flower_push_back(T&&) -> void;
  auto flower_push_back(std::initializer_list<T>&&) -> void;
  auto flower_emplace_back(std::initializer_list<T>&&) -> void;
  auto flower_pop_back() -> void;
  auto flower_clear() -> void;  
  auto erase(const_iterator) -> iterator;

public: 
  auto operator[](std::size_t) const -> const T&; 
  auto operator[](std::size_t) -> T&; 
  auto operator=(const Flower_Vector<T>&) -> Flower_Vector<T>;
  auto operator=(std::initializer_list<T>&) -> Flower_Vector<T>;
  auto operator==(const Flower_Vector<T>&) const -> bool;

private:
  std::size_t size; 
  std::size_t capacity; 
  T* flower_buffer; 
 
private: 
  auto flower_realloc(std::size_t) -> void; 

private: 
  template <typename G>
  friend std::ostream& operator<<(std::ostream&, const Flower_Vector<G>&); 
}; 

template <typename G>
std::ostream& operator<<(std::ostream&, const Flower_Vector<G>&);

