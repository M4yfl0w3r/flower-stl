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

	auto push(T value) -> void
	{
		std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>();
		new_node -> element = value;
		new_node -> next = top;
		top = new_node;
	}

	auto pop() -> T
	{
		if (top != NULL)
		{
			std::shared_ptr< Node<T> > tmp_top = top;
			top = top -> next;
			tmp_top -> next = NULL;
			T tmp_val = tmp_top -> element;
			return tmp_val;
		}

		throw new std::underflow_error ("Stack is empty");
	}

	auto stack_empty() -> bool
	{
		return (top == nullptr);
	}

	auto get_top() -> T
	{
		return top -> element;
	}
};

