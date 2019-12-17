#pragma once
#include"iostream"
#include "Iteator.h"
#include "Monom.h"
using namespace std;
template<class T>
class List
{
public:
	Node<T>* head;
	int size;
public:
	List(int n) {
		head = new Node<int>; // выделяется память под один квадратик
		size = n;
		Node<int>* tmp = head; // создаем квадратик как хеад
		for (int i = 0; i < n; i++) {
			Node<int>* tmp2 = new Node<int>; // создаем какой-то квадратик
			tmp->next = tmp2; // связали два квадрата
			tmp = tmp2; // перешли на tmp2
		}
	}
	void change_head_coeff(int a) {
		head->data.coeff = a;
	}
	List( List& a) {
		size = a.Size();
		Node<T>* i = new Node<T>;
		head = i;
		Node<T>* k = a.head;
		while (k->next != NULL) {
			i->data= k->data;
			i->next = new Node<T>;
			i = i->next;
			k = k->next;
		}
		i->data = k->data;
	}
	List<T>() {
		head = new Node<T>; // выделяется память под один квадратик
		size = 1;
	}
	void insert(T data, Node<T>* prev) {
		Node<T>* a = new Node<T>; // создали квадратик а
		a->data = data; // положили туда данные
		Node<T>* b = prev->next; // в b мы сохраняем адрес следующего
		prev->next = a; // связываем с a
		a->next = b; // a связываем со следующим
		size++;
	}
	int Size() {
		return size;
	}
	Node<T>* Head() {
		return head;
	}
	Iterator<T> begin() {
		Iterator<T> i(head);
		return i;
	}
	Iterator<T> end() {
		return NULL;
	}
	void Delete(Node<T>* i) {
		if (i == head) {
			Node<T>* b = head->next;
			delete head;
			head = b;
		}
		else {
			if (i->next->next != NULL) {
				Node<T>* a = i->next->next;
				delete i->next;
				i->next = a;
				size--;
			}
			else {
				delete i->next;
				size--;
			}
		}
	}
	void pop_front() {
		head = head->next;
		size--;
	}
	void insert_front(int _data) {
		Node<int>* a = new Node<int>;
		a->data = _data;
		Node<int>* b = head;
		head = a;
		a->next = b;
		size++;
	}
	int& Getelem(Node<int>* i) { // без ссылки вернется копия
		return i->data;
	}
	int search(int k) {
		int i = 0;
		Node<int>* a = head;
		Node<int>* b = head;
		while (i < k) {
			a = a->next;
			i++;
		}
		while (a->next != NULL) {
			a = a->next;
			b = b->next;
		}
		return b->data;
	}
	int medium() {
		Node<int>* a = head;
		Node<int>* b = head->next;
		while (b->next != NULL) {
			a = a->next;
			b = b->next;
			if (b->next != NULL)
				b = b->next;
			else
				break;
		}
		return a->data;
	}
	void Push(Monom el) {
		Node<Monom>* i = head;
		if (el.coeff == 0)
			return;
		else {
			if (el.deg == 0) {
				head->data = el;
			}
			else {
				while (i->next != NULL) {
					if (i->next == NULL)
						break;
					else if (i->next->data.deg > el.deg)
						break;
					else if (i->next->data.deg == el.deg) {
						el.coeff += i->next->data.coeff;
						Delete(i);
						break;
					}
					else
						i = i->next;
				}
			}
		}
			insert(el, i);
	}
	friend istream& operator>>(istream& in, List& v)
	{
		Node<int>* a = v.Head();
		while (a->next != NULL) {
			in >> a->data;
			a = a->next;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, List& v)
	{
		Node<int>* a = v.Head();
		while (a->next != NULL) {
			out << a->data << ' ';
			a = a->next;
		}
		return out;
	}
	List<T>& operator=(List<T>& a) {
		while (head != NULL) {
			Delete (head);
		}
		size = a.Size();
		Node<T>* i = new Node<T>;
		head = i;
		Node<T>* k = a.head;
		while (k->next != NULL) {
			i->data = k->data;
			i->next = new Node<T>;
			i = i->next;
			k = k->next;
		}
		i->data = k->data;
		return *this;
	}
	~List() {
		while (head != NULL) {
			Node<T>* a = head->next;
			delete head;
			head = a;
		}
	}
};

