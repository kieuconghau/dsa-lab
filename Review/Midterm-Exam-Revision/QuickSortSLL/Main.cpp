#include <iostream>
#include <ctime>
using namespace std;

struct Node {
	int key;
	Node* next;
};

Node* getNode(int k) {
	Node* p = new Node;
	p->key = k;
	p->next = nullptr;
	return p;
}

void initList(Node*& h, Node*& t) {
	h = t = nullptr;
}

void insertLast(Node*& h, Node*& t, Node* p) {
	if (h == nullptr) {
		h = t = p;
	}
	else {
		t->next = p;
		t = p;
	}
}

void generateList(Node*& h, Node*& t, int n) {
	srand(time(nullptr));

	for (int i = 0; i < n; ++i) {
		int data = rand() % 10000;
		insertLast(h, t, getNode(data));
	}
}

void display(Node* head, Node* tail) {
	for (Node* p = head; p; p = p->next) {
		cout << " " << p->key;
	}
	cout << endl;
}

bool isAscending(Node* head, Node* tail) {
	for (Node* p = head; p != tail; p = p->next) {
		if (p->next->key < p->key)
			return false;
	}
	return true;
}

void join(Node*& h, Node*& t, Node*& h1, Node*& t1, Node*& h2, Node*& t2, Node*& p) {
	if (h1 != nullptr) {
		h = h1;
		t1->next = p;
	}
	else {
		h = p;
	}

	if (h2 != nullptr) {
		p->next = h2;
		t = t2;
	}
	else {
		t = p;
	}
}

void quickSort(Node*& h, Node*& t) {
	if (h != t) {
		Node* h1 = nullptr;
		Node* t1 = nullptr;
		Node* h2 = nullptr;
		Node* t2 = nullptr;
		Node* pivot = h;
		h = h->next;
		pivot->next = nullptr;

		Node* p;
		while (h) {
			p = h;
			h = h->next;
			p->next = nullptr;
			
			if (p->key < pivot->key) {
				insertLast(h1, t1, p);
			}
			else {
				insertLast(h2, t2, p);
			}
		}

		quickSort(h1, t1);
		quickSort(h2, t2);

		join(h, t, h1, t1, h2, t2, pivot);
	}
}

int main() {
	Node* head = nullptr;
	Node* tail = nullptr;

	generateList(head, tail, 111);
	display(head, tail);

	quickSort(head, tail);
	if (isAscending(head, tail))
		display(head, tail);

	return 0;
}