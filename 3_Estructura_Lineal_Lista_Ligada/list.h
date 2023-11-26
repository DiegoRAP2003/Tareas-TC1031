#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&) ;

	void addFirst(T) ;
	void insertion(T) ;
	std::string toString() const;
	int search(T) const;
	bool empty() const;
	void update(T,T);
	void deleteAt(T);

private:
	Link<T> *head;
	int 	size;

	friend class ListIterator<T>;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
void List<T>::addFirst(T val)  {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		return;
	}
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::insertion(T val)  {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		return;
	}

	if (empty()) {
		addFirst(val);
		return;
	}

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
int List<T>::search(T val) const {
	Link<T> *p;
	int i = 0;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return i;
		}
		p = p->next;
		i++;
	}
	return -1;
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::update(T i, T val){
	Link<T> *p = head;
	int index = 0;

	while(p != 0){
		if(index == i){
			p->value = val;
			return;
		}
		p = p->next;
		index++;
	}
}

template <class T>
void List<T>::deleteAt(T i){
	Link<T> *p = head, *q = 0;
	int index = 0;

	while(p != 0){
		if(index == i){
			if(q == 0){
				head = p->next;
			}else{
				q->next = p->next;
			}
			delete p;
			size--;
			return;
		}
		q = p;
		p = p->next;
		index++;
	}
}




#endif