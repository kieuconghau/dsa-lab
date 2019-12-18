#include <iostream>
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

bool isEmpty(Node* h) {
	return h == nullptr;
}

void display(Node* head) {
	for (Node* p = head; p != nullptr; p = p->next) {
		cout << " " << p->key;
	}
}

void addHead(Node*& head, Node*& tail, int k) {
	Node* p = getNode(k);

	if (isEmpty(head)) {
		head = tail = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

void addTail(Node*& head, Node*& tail, int k) {
	Node* p = getNode(k);

	if (isEmpty(head)) {
		head = tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}

void addAfter(Node*& q, int k) {
	Node* p = getNode(k);
	p->next = q->next;
	q->next = p;
}

void addBefore(Node*& q, int k) {
	Node* p = new Node;
	*p = *q;
	q->next = p;
	q->key = k;
}

void delNode(Node* q) {
	Node* temp = q->next;
	*q = *temp;
	delete temp;
}

int main() {
	Node* head;
	Node* tail;
	head = tail = nullptr;

	addHead(head, tail, 9);
	addHead(head, tail, 10);
	display(head);

	delNode(head);
	display(head);

	return 0;
}