#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
struct Node
{
	T element;
  std::shared_ptr< Node<T> > next;	
};

template<typename T>
struct Stack 
{	
  std::shared_ptr< Node<T> > top = 0;

	void push(T value);
	T pop();

	bool stack_empty();
	T get_top();
};

