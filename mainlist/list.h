#pragma once
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <stdexcept>

namespace mainset {
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
		List(int size);
		~List();

		void push_tail(T data);
		void push_head(T data);
		void pop_head();
		void pop_tail();
		void clear();
		void push_tail(List<T>& otherList);
		void push_head(List<T>& otherList);
		void print_reverse(Node<T>* current, std::ostream& os) const;
		void print_list(List<T>& list);
		int get_size()
		{
			return Size;
		}


		T& operator[](const int index);
		List<T>& operator=(const List<T>& otherList)
		{
			if (this == &otherList)
				return *this;
			clear();
			Node<T>* current = otherList.head;
			while (current != nullptr)
			{
				push_tail(current->_data);
				current = current->_pNext;
			}
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const List<T>& list)
		{
			list.print_reverse(list.head, os);
			return os;
		}
		//friend std::ostream& operator << (std::ostream& os, const List<T>& list)
		//{
		//	Node<T>* current = list.head;
		//	while (current != nullptr)
		//	{
		//		os << current->_data << " ";
		//		current = current->_pNext;
		//	}
		//	return os;
		//}

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
	List<T>::List(int size)
	{
		Size = 0;
		head = nullptr;
		std::srand(std::time(0));
		for (int i = 0; i < size; i++)
		{
			push_tail(std::rand());
		}
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
		if (index < 0 || index >= Size)
		{
			throw std::runtime_error("Invalid index");
		}
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

	template<typename T>
	void print_list(List<T>& list) {
		for (int i = 0; i < list.get_size(); i++) {
			std::cout << list[i] << " ";
		}
		std::cout << std::endl;
	}

	template<typename T>
	void List<T>::print_reverse(Node<T>* current, std::ostream& os) const
	{
		if (current == nullptr)
			return;
		print_reverse(current->_pNext, os);
		os << current->_data << " ";
	}
}