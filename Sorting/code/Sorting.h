template <class T>
T* BubbleSort(T& hd) {
	bool done = false;
	T* head = &hd;
	T* prev = NULL;
	T* curr = NULL;
	T* temp = NULL;
	
	while (!done) { //each iteration through the whole list
		done = true;
		curr = prev = head;
		while (curr->getNext() != NULL) {
			if (curr->getText() > curr->getNext()->getText()) {
				done = false;
				// do swap
				temp = curr->getNext();
				curr->setNext(curr->getNext()->getNext());
				temp->setNext(curr);
				if (curr == head) {
					head = prev = temp;
				} else {
					prev->setNext(temp);
				}
				curr = temp;
			}
			prev = curr;
			curr = curr->getNext();
		}
	}
	return head;
}
/*
template <class T>
T* MergeSort(T* head) {
	if (head == NULL || head->getNext() == NULL) {
		return head;
	}
	T* middle = GetMiddle(head);
	//std::cout << "Got middle: " << middle->getText() << std::endl;
	
	T* sHalf = middle->getNext();
	//std::cout << "Got thing: " << sHalf->getText() << std::endl;

	middle->setNext(NULL);
	return Merge(MergeSort(head),MergeSort(sHalf));
}

template <class T>
T* Merge(T* a, T* b) {
	//T* dummyHead = new T();
	T dummyHead;
	T* curr = &dummyHead;
	dummyHead.setNext(NULL);
	while (a != NULL && b != NULL) {
		if (b->getText() > a->getText()) {
			curr->setNext(a);
			a = a->getNext();
		} else {
			curr->setNext(b);
			b = b->getNext();
		}
		curr = curr->getNext();
	}
	curr->setNext( ( a == NULL ) ? b : a );
	return dummyHead.getNext();
}*/

/*template <>
Value* Merge(Value* a, Value* b) {
	Value* dummyHead = new Value("");
	Value* curr = dummyHead;
	while (a != NULL && b != NULL) {
		if (b->getText() > a->getText()) {
			curr->setNext(a);
			a = a->getNext();
		} else {
			curr->setNext(b);
			b = b->getNext();
		}
		curr = curr->getNext();
	}
	curr->setNext( ( a == NULL ) ? b : a );
	return dummyHead->getNext();
}*/
/*
template <class T>
T* GetMiddle(T* head) {
	if (head == NULL) {
		return head;
	}
	//std::cout << "Getting middle" << std::endl;

	T* slow = NULL;
	T* fast = NULL;
	slow = fast = head;
	while (fast->getNext() != NULL && fast->getNext()->getNext() != NULL) {
		slow = slow->getNext();
		fast = fast->getNext()->getNext();
	}
	return slow;
}
*/
