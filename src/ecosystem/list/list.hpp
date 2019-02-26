// File: list.hpp

#ifndef LIST_HPP
#define LIST_HPP

/* System headers */
#include <iostream>
/******************/

/* Namespace access */
using namespace std;
/********************/

template <class T>
class List {
	private:
		struct Node {
			Node *next;
			Node *prev;
			T *data;
		};
		Node *header;
		Node *current;
	public:
		List();
		~List();
		void push(T *data);
		T *pop();  // Deletes the node, returns the data.
		T *get_data() const;
		bool move_left();
		bool move_right();
		void move_start();
};

template <class T>
List<T>::List()
	: header(NULL), current(NULL)
{
	header = new Node();
	header->prev = NULL;
	header->next = NULL;
	header->data = NULL;
}

template <class T>
List<T>::~List()
{
	current = header->next;
	while (current != NULL) {
		current = current->next;
		delete current->prev->data;
		delete current->prev;
	}
}

template <class T>
void List<T>::push(T *data) {
	Node *node = new Node();
	node->data = data;
	node->next = header->next;
	node->prev = NULL;
	if (header->next != NULL) header->next->prev = node;
	header->next = node;
	if (current == NULL) current = header->next;
}

template <class T>
T *List<T>::pop() {
	if (current == NULL) return NULL;
	T *data = current->data;
	Node *node = current;
	if (current->prev == NULL)
		current = current->next;
	else
		current = current->prev;
	if (node->prev != NULL)
		node->prev->next = node->next;
	else
		header->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	delete node;
	return data;
}

template <class T>
T *List<T>::get_data() const {
	if (current == NULL) return NULL;
	return current->data;
}

template <class T>
bool List<T>::move_left() {
	if (current == NULL) return false;
	if (current->prev == NULL) return false;
	current = current->prev;
	return true;
}

template <class T>
bool List<T>::move_right() {
	if (current == NULL) return false;
	if (current->next == NULL) return false;
	current = current->next;
	return true;
}

template <class T>
void List<T>::move_start() {
	current = header->next;
}

#endif  // #ifndef LIST_HPP