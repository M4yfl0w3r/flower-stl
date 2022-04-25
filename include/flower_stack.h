#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
struct Node
{
	T element;
  std::shared_ptr<Node<T>> next;	
};

template<typename T>
struct Stack 
{	
  std::shared_ptr<Node<T>> top = 0;

	auto push(T value) -> void;
	auto pop() -> T;
	auto stack_empty() -> bool;
	auto get_top() -> T;
};

