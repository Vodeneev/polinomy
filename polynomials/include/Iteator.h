#pragma once
#include "iostream"
#include "Monom.h"
#pragma once
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
	Node() {
		next = 0;
	}
};

template <typename T>
class Iterator
{
	Node<T>* i;
public:
	Iterator() {
		i = NULL;
	}
	Iterator(Node<T>* a) {
		i = a;
	}
	Iterator operator++() { // слева, делает ++ и возвр результат, справа прибавит, но вернет старое
		i = i->next;// через i мы можем обратиться к квадратику, а в нем уже лежит адрес следующего
		return *this;
	}
	Iterator operator++(int){
		Node<T>* a = i;
		i = i->next;
		return Iterator(a);
	}
	T& operator*() { // без ссылки вернется копия
		return i->data;
	}
	bool operator!=(Iterator a) {
		return i != a.i;
	}
	bool operator==(Iterator a) {
		return i == a.i;
	}
};

