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
  /**
   * @brief      Constructs a new flower vector.
   */
  Flower_Vector();

  /**
   * @brief      Constructs a new flower vector with one element
   *
   * @param[in]   First element 
   */
  Flower_Vector(T);

  /**
   * @brief Copy constructor
   *
   */
  Flower_Vector(const Flower_Vector<T>&);

  /**
   * @brief      Move constructor
   *
   */
  Flower_Vector(Flower_Vector<T>&&);

  /**
   * @brief      Constructs a new flower vector with any parameters 
   *
   * @param[in]  Any number of parameters
   */
  Flower_Vector(std::initializer_list<T>);

  /**
   * @brief      Destroys the object.
   */
  ~Flower_Vector();

public: 
  /**
   * @brief Iterators
   */
  iterator begin();
  iterator end();
  
  /**
   * @brief const Iterators
   */
  const_iterator const_begin() const;
  const_iterator const_end() const;

public: 
  /**
   * @brief      What is the size of the vector?
   *
   * @return    Number of elements in flower vector.
   */
  std::size_t flower_size() const; 
  /**
   * @brief      What is the maximum size of the vector? 
   *
   * @return     Max size of the flower vector with given type.
   */
  std::size_t flower_max_size() const;
  /**
   * @brief      How many elements vector can store without memory reallocation
   *
   * @return    Capacity
   */
  std::size_t flower_capacity() const; 
  /**
   * @brief      Checks whether vector is empty
   *
   * @return     True - vector empty, False - vector not empty 
   */
  bool flower_empty() const; 
  /**
   * @brief      Make space for given number of elements
   *
   * @param[in]  Size - number of elements 
   */
  void flower_reserve(std::size_t);
  /**
   * @brief      Shrink vector - make capacity equal to size
   */
  void shrink_to_fit();

public: 
  /**
   * @brief     Add a new element at the end of the flower vector 
   *
   * @param     Value to be moved 
   */
  void flower_push_back(T&&);

  /**
   * @brief      Add multiple element at the end of the flower vector
   *
   * @param     Values to be moved to the flower vector 
   */
  void flower_push_back(std::initializer_list<T>&&);
  /**
   * @brief     Append a new element to the end of the flower vector, but construct it in place and than add
   *
   * @param     Values to be add to the flower vector
   */
  void flower_emplace_back(std::initializer_list<T>&&);
  /**
   * @brief      Remove the last element of the flower vector 
   */
  void flower_pop_back();
  /**
   * @brief     Remove all the elements from the vector 
   */
  void flower_clear(); 

  /**
   * @brief Remove the element at given position
   */
  iterator erase(const_iterator);

public: 
  /**
   * @brief      Array indexer operator.
   *
   * @param[in]  Index 
   *
   * @return     The result of the array indexer
   */
  const T& operator[](std::size_t) const; 
  T& operator[](std::size_t); 
  /**
   * @brief      Assignment operator.
   * 
   * @return     The result of the assignment
   */
  Flower_Vector<T> operator=(const Flower_Vector<T>&);

  Flower_Vector<T> operator=(std::initializer_list<T>&);
  /**
   * @brief      Compare two vectors operator
   *
   *
   * @return     The result of the equality
   */
  bool operator==(const Flower_Vector<T>&) const;

private:
  /**
   * Vector's size (number of elements)
   */
  std::size_t size; 
  /**
   * Vector's capacity (how many elemnents can it store without memory reallocation)
   */
  std::size_t capacity; 
  /**
   * Vector's buffer (dynamic array to store the elements)
   */
  T* flower_buffer; 
 
private: 
  /**
   * @brief      Reallocate the memory
   *
   * @param[in]  New capacity of the vector 
   */
  void flower_realloc(std::size_t); 

private: 
  template <typename G>
  friend std::ostream& operator<<(std::ostream&, const Flower_Vector<G>&); 
}; 

template <typename G>
std::ostream& operator<<(std::ostream&, const Flower_Vector<G>&);

