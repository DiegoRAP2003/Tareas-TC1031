#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList{
    public:
        DList();
        DList(const DList<T>&);

        void addFirst(T) ;
        void insertion(T) ;
        int search(T) const;
        bool empty() const;
        void update(T,T);
        void deleteAt(T);
        void removeFirst();

        std::string toStringForward() const;
        std::string toStringBackward() const;


    private:
        DLink<T> *head;
        int size;
        DLink<T> *tail;

};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0){}

template <class T>
void DList<T>::addFirst(T val)  {
	DLink<T> *newDLink;

	newDLink = new DLink<T>(val);
	if (newDLink == 0) {
		return;
	}

    if(empty()){
        head = newDLink;
        tail = newDLink;
    }else{
		newDLink->next = head;
		head->previous = newDLink;
		head = newDLink;
    }
	size++;
}

template <class T>
void DList<T>::insertion(T val)  {
	DLink<T> *newDLink, *p;

	newDLink = new DLink<T>(val);
	if (newDLink == 0) {
		return;
	}

	if (empty()) {
		addFirst(val);
		return;
	}else{
        tail->next = newDLink;
        newDLink->previous = tail;
        tail = newDLink;
    }

	size++;
}

template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;

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
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

template <class T>
int DList<T>::search(T val) const {
	DLink<T> *p;
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
bool DList<T>::empty() const {
	return (head == 0);
}

template <class T>
void DList<T>::update(T i, T val){
	DLink<T> *p = head;
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
void DList<T>::removeFirst(){
	T val;
	DLink<T> *p;

	if (empty()) {
		return;
	}

	p = head;
	val = p->value;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;

	return;
}

template <class T>
void DList<T>::deleteAt(T i) {
    int pos;
	DLink<T> *p;

	if (i < 0 || i >= size) {
		return;
	}

	if (i == 0) {
		return removeFirst();
	}

	p = head;
	pos = 0;
	while (pos != i){
		p = p->next;
		pos++;
	}

	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	}
	size--;

	delete p;
}
















#endif