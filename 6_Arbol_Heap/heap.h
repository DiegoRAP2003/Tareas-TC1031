#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int count;
	unsigned int sze;
	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);

public:
	Heap(unsigned int) ;
	bool empty() const;
	bool full() const;
	void push(T) ;
	T pop() ;
	void clear();
	std::string toString() const;
	unsigned int size();
	T top();
};

template <class T>
bool Heap<T>::full() const {
	return (count == sze);
}
template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return pos / 2;
}

template <class T>
bool Heap<T>::empty() const {
	return (count == 1);
}

template <class T>
Heap<T>::Heap(unsigned int size)  {
	sze = size + 1;
	data = new T [sze];
	if (data == 0) {
		return;
	}
	count = 1;
}

template <class T>
void Heap<T>::push(T val)  {
	unsigned int pos;
	if (full()) {
		return;
	}

	pos = count;
	count++;
	while (pos > 0 && val < data[parent(pos)]) {
		data[pos] = data[parent(pos)];
		pos = parent(pos);
	}
	data[pos] = val;
}

template <class T>
T Heap<T>::pop()  {
	if (empty()) {
		return -1;
	}
	T aux = data[0];

	data[0] = data[--count];
	heapify(0);
	return aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
	unsigned int le = left(pos);
	unsigned int ri = right(pos);
	unsigned int min = pos;
	if (le <= count && data[le] < data[min]) {
		min = le;
	}
	if (ri <= count && data[ri] < data[min]) {
		min = ri;
	}
	if (min != pos) {
		swap(pos, min);
		heapify(min);
	}
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return 2 * pos;
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return 2 * pos + 1;
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
unsigned int Heap<T>::size(){
	return count - 1;
}

template <class T>
T Heap<T>::top(){
	return data[1];
}

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 1; i < count; i++) {
		if (i != 1) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}
#endif /* HASH_H_ */
