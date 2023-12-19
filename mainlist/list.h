#pragma once
#include <iostream>
#include <string>


template <typename T>
class List 
{
public:
	List();
	~List();

	void push_back(T data);

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

template<typename T>
inline void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{

	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	List<int> lst;
	lst.push_back(5);
	return 0;

}