#pragma once
#include <iostream>
#include <string>

template <typename T>
struct Node {
	Node* _pNext;
	T _data;
	Node(T data = T(), Node* pNext = nullptr)
	{
		this->_data = data;
		this->_pNext = pNext;
	}
};

template <typename T>
class List
{
public:
	List();
	~List();

	void push_tail(T data);
	void push_head(T data);
	void pop_head();
	void pop_tail();
	void clear();
	void push_tail(List<T>& otherList);
	void push_head(List<T>& otherList);

	int get_size()
	{
		return Size;
	}


	T& operator[](const int index);

	friend std::ostream& operator << (std::ostream& os, const List<T>& list)
	{
		Node<T>* current = list.head;
		while (current != nullptr)
		{
			os << current->_data << " ";
			current = current->_pNext;
		}
		return os;
	}
private:

	int Size;
	Node<T>* head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List()
{
	while (head != nullptr)
	{
		Node<T>* temp = head;
		head = head->_pNext;
		delete temp;
	}
}

template<typename T>
inline void List<T>::push_tail(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->_pNext != nullptr)
		{
			current = current->_pNext;
		}
		current->_pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::push_head(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::pop_head()
{
	if (head == nullptr)
	{
		return;
	}
	Node<T>* temp = head;
	head = head->_pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::pop_tail()
{
	if (head == nullptr)
	{
		return;
	}
	if (head->_pNext == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node<T>* current = this->head;
		while (current->_pNext->_pNext != nullptr)
		{
			current = current->_pNext;
		}
		delete current->_pNext;
		current->_pNext = nullptr;
	}
	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_head();
	}
}

template<typename T>
void List<T>::push_tail(List<T>& otherList)
{
	if (otherList.head == nullptr)
	{
		return;
	}
	Node<T>* current = this->head;
	while (current->_pNext != nullptr)
	{
		current = current->_pNext;
	}
	current->_pNext = otherList.head;
	Size += otherList.Size;
	otherList.head = nullptr;
	otherList.Size = 0;
}

template<typename T>
void List<T>::push_head(List<T>& otherList)
{
	if (otherList.head == nullptr)
	{
		return;
	}
	Node<T>* current = otherList.head;
	while (current->_pNext != nullptr)
	{
		current = current->_pNext;
	}
	current->_pNext = head;
	head = otherList.head;
	Size += otherList.Size;
	otherList.head = nullptr;
	otherList.Size = 0;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->_data;
		}
		current = current->_pNext;
		counter++;
	}
}