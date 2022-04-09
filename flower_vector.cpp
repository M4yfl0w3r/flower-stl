#include "flower_vector.h"

template <typename T>
Flower_Vector<T>::Flower_Vector() 
  : size{0}, capacity{2}, flower_buffer{nullptr}
{
  flower_realloc(capacity);
}

template <typename T>
Flower_Vector<T>::Flower_Vector(T value) 
  : size{0}, capacity{2}, flower_buffer{nullptr}
{
  flower_realloc(capacity);
  flower_push_back(std::move(value));
}  

template <typename T>
Flower_Vector<T>::Flower_Vector(const Flower_Vector<T>& other) 
  : size{other.size}
{
  flower_buffer = new T[size];

  for (std::size_t i = 0; i < size; i++)
  {
    flower_buffer[i] = other.flower_buffer[i];
  }
}

template <typename T>
Flower_Vector<T>::Flower_Vector(Flower_Vector<T>&& other) 
  : size{std::exchange(size, other.size)}, capacity{std::exchange(capacity, other.capacity)}
{
  flower_buffer = new T[size];

  for (std::size_t i = 0; i < size; i++) 
  {
    flower_buffer[i] = std::move(other.flower_buffer[i]);
  }
}

template <typename T>
Flower_Vector<T>::Flower_Vector(std::initializer_list<T> l) 
  : size{0}, capacity{l.size()}, flower_buffer{nullptr}
{
  flower_realloc(capacity);

  for (auto e : l)
  {
    flower_push_back(std::move(e));
  }
}

template <typename T>
Flower_Vector<T>::~Flower_Vector() 
{
  if (flower_buffer != nullptr)
  {
    size = 0;
    capacity = 0;
    delete [] flower_buffer;
  }
}

template<typename T>
typename Flower_Vector<T>::iterator Flower_Vector<T>::begin()
{
  return flower_buffer;
}

template<typename T>
typename Flower_Vector<T>::const_iterator Flower_Vector<T>::const_begin() const
{
  return flower_buffer;
}

template<typename T>
typename Flower_Vector<T>::iterator Flower_Vector<T>::end()
{
  return flower_buffer + size;
}

template<typename T>
typename Flower_Vector<T>::const_iterator Flower_Vector<T>::const_end() const
{
  return flower_buffer + size;
}

template <typename T>
std::size_t Flower_Vector<T>::flower_size() const
{
  return this -> size;
}

template <typename T>
std::size_t Flower_Vector<T>::flower_max_size() const
{
  return std::numeric_limits<T>::max();
}

template <typename T>
std::size_t Flower_Vector<T>::flower_capacity() const
{
  return this -> capacity;
}

template <typename T>
bool Flower_Vector<T>::flower_empty() const
{
  return (size == 0);
}

template <typename T>
void Flower_Vector<T>::flower_reserve(std::size_t n)
{
  flower_realloc(n);
}

template <typename T>
void Flower_Vector<T>::shrink_to_fit()
{
  capacity = size;
  flower_realloc(size);
}

template <typename T>
const T& Flower_Vector<T>::operator[](std::size_t index) const
{ 
  return flower_buffer[index];
}

template <typename T>
T& Flower_Vector<T>::operator[](std::size_t index)
{
  return flower_buffer[index];
}

template <typename T>
bool Flower_Vector<T>::operator==(const Flower_Vector<T>& other) const
{
  if (size != other.flower_size()) 
    return false;

  for (std::size_t i = 0; i < size; i++)
    if (flower_buffer[i] != other.flower_buffer[i])
      return false;

  return true;
}

template <typename T>
Flower_Vector<T> Flower_Vector<T>::operator=(const Flower_Vector<T>& other)
{
  if (this == &other)
    return *this;
  
  delete [] flower_buffer;
  size = other.size;
  flower_buffer = new int[size];

  for (std::size_t i = 0; i < size; i++)
  {
      flower_buffer[i] = other.flower_buffer[i];
  }

  return *this;
}

template <typename T>
void Flower_Vector<T>::flower_realloc(std::size_t new_capacity)
{ 
  T* new_buffer = new T[new_capacity];

  if (new_capacity < size)
  {
    size = new_capacity;
  }

  for (std::size_t i = 0; i < size; i++)
  { 
    new (&new_buffer[i]) T(std::move(flower_buffer[i]));
  }

  delete [] flower_buffer;
  flower_buffer = new_buffer;
  capacity = new_capacity;
}

template <typename T>
void Flower_Vector<T>::flower_push_back(T&& value)
{ 
  if (size >= capacity)
  {

    flower_realloc(capacity + capacity);
  }
 
  //flower_buffer[size++] = std::move(value);
  flower_buffer[size++] = static_cast<T&&>(value);
}
  
template <typename T>
void Flower_Vector<T>::flower_push_back(std::initializer_list<T>&& l)
{
  for (auto e : l)
  {
    flower_push_back(static_cast<T&&>(e));
  }
}

template <typename T>
void Flower_Vector<T>::flower_emplace_back(std::initializer_list<T>&& l)
{
  if (size >= capacity)
  {
    flower_realloc(capacity + capacity);
  }

  for (auto e : l)
  {
    new (&flower_buffer[size++]) T(static_cast<T&&>(e));
  }
}

template <typename T>
void Flower_Vector<T>::flower_pop_back()
{
  flower_realloc(size--);
}

template <typename T>
void Flower_Vector<T>::flower_clear()
{
  delete [] flower_buffer;   
  capacity = 2;
  size = 0;
}

template <typename T>
typename Flower_Vector<T>::iterator Flower_Vector<T>::erase(typename Flower_Vector<T>::const_iterator it)
{
  iterator _it = &flower_buffer[it - flower_buffer];
  _it -> ~T();
  memmove(_it, _it + 1, (size - (it - flower_buffer) - 1) * sizeof(T));
  size--;
  return _it;
}

template <typename T>
std::ostream& operator << (std::ostream& stream, const Flower_Vector<T>& vec)
{ 
  for (std::size_t i = 0; i < vec.flower_size(); i++)
  {
    stream << vec.flower_buffer[i] << " ";
  }

  return stream;
}

