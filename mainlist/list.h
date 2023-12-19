#pragma once
#include <iostream>
#include <string>


template <typename T>
class List 
{
public:
	List();
	~List();
private:
	
	template <typename T>
	class Node 
	{
	public:
		Node* _pNext;
		T _data;
		Node(T data=T(), Node* pNext = nullptr)
		{
			this->_data = data;
			this->_pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;

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
}