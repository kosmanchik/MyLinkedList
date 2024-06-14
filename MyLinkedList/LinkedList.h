#pragma once

template<typename T>
class LinkedList {

private:

	template<typename T>
	struct Node {
		T Val;
		Node* Next_node;

		Node(T User_val = T(), Node* User_next_node = nullptr) {
			this->Val = User_val;
			this->Next_node = User_next_node;
		}

	};

	int Size = 0;
	Node<T>* Head = nullptr;

public:

	int size() { return Size; };
	void push_back(T val);
	void pop_back();
	void insert(T val, int indx);
	void remove(int indx);
	T& operator[](const int index);

};


template<typename T>
void LinkedList<T>::remove(int indx) {
	if (indx <= Size) {
		Node<T>* Current = this->Head;

		for (int i = 0; i < indx; i++) {
			Current = Current->Next_node;
		}

		Node<T>* To_delete = Current->Next_node;

		Current->Next_node = Current->Next_node->Next_node;

		delete To_delete;

		Size--;
	}
}

template<typename T>
void LinkedList<T>::insert(T val, int indx) {

	if (indx <= Size) {
		Node<T>* Current = this->Head;

		for (int i = 0; i < indx - 1; i++) {
			Current = Current->Next_node;
		}
		Node<T>* Temp = Current->Next_node;

		Current->Next_node = new Node<T>(val);
		Current = Current->Next_node;
		Current->Next_node = Temp;

		Size++;
	}
	else {
		return;
	}
}

template<typename T>
T& LinkedList<T>::operator[](const int index) {
	Node<T>* Current = this->Head;

	for (int i = 0; i < index; i++) {
		Current = Current->Next_node;
	}

	return Current->Val;
}

template<typename T>
void LinkedList<T>::push_back(T val) {

	if (Head == nullptr) {
		Head = new Node<T>(val);
	}
	else {

		Node<T>* Current = this->Head;

		while (Current->Next_node != nullptr)
		{
			Current = Current->Next_node;
		}
		Current->Next_node = new Node<T>(val);
	}
	Size++;
}

template<typename T>
void LinkedList<T>::pop_back() {
	if (Head != nullptr) {
		Node<T>* Previous = this->Head;

		for (int i = 0; i < this->Size - 1; i++) {
			Previous = Previous->Next_node;
		}

		Node<T>* To_delete = Previous->Next_node;

		Previous->Next_node = nullptr;

		delete To_delete;

		Size--;
	}

	else {
		return;
	}
}