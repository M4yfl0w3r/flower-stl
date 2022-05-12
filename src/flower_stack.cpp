#include "flower_stack.h"

template<typename T>
void Stack<T>::push(T value)
{
  std::shared_ptr< Node<T> > new_node = std::make_shared< Node<T> >();
	new_node -> element = value;
	new_node -> next = top;
	top = new_node;
}

template<typename T>
T Stack<T>::pop()
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

template<typename T>
bool Stack<T>::stack_empty()
{
	return top == NULL;
}

template<typename T> 
T Stack<T>::get_top()
{
	return top -> element;
}

