#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

typedef struct node * Ref;
struct node {
	int key;
	Ref next;
};

typedef struct bin * BRef;
struct bin {
	int id;
	Ref head;
	Ref tail;
	BRef next;
};

Ref getNode(int k) {
	Ref p = new node;
	p->key = k;
	p->next = NULL;
	return p;
}

BRef getBin(int id) {
	BRef p = new bin;
	p->id = id;
	p->head = p->tail = NULL;
	p->next = NULL;
	return p;
}

void insertLast(Ref& h, Ref& t, Ref p) {
	if (h == NULL)
		h = t = p;
	else {
		t->next = p;
		t = p;
	}
}

void createList(Ref& h, Ref& t) {
	int n, i;
	Ref p;
	while (true) {
		cout << "Enter the number of elements: ";
		cin >> n;
		if (n)
			break;
		cout << "Wrong value!" << endl;
	}
	for (i = 0; i < n; i++) {
		int num = rand() % 100000;
		p = getNode(num);
		insertLast(h, t, p);
	}
}

void showList(Ref h) {
	for (Ref p = h; p; p = p->next)
		cout << p->key << " ";
	cout << endl;
}

void delList(Ref& h, Ref& t) {
	Ref p;
	while (h) {
		p = h;
		h = h->next;
		p->next = NULL;
		delete p;
	}
	h = t = NULL;
}

int getLoop(Ref h, int k) {
	int maxVal = h->key;
	for (Ref p = h->next; p; p = p->next)
		if (maxVal < p->key)
			maxVal = p->key;
	int d = 0;
	while (maxVal) {
		d++;
		maxVal /= 10;
	}
	
	return (d + k - 1) / k;
}

int getId(int val, int z, int k) {
	int digits = (int)pow(10, k);
	while (z) {
		val /= digits;
		z--;
	}
	return val % digits;
}

void insertBin(BRef bins, int id, Ref p) {	// Dummy head
	BRef q1, q2;
	q2 = bins;
	q1 = bins->next;
	
	while (q1 && q1->id < id) {
		q2 = q1;
		q1 = q1->next;
	}
	
	if (q1 && q1->id == id)
		insertLast(q1->head, q1->tail, p);
	else {
		BRef q = getBin(id);
		q2->next = q;
		q->next = q1;
		insertLast(q->head, q->tail, p);
	}
}

void sortList(Ref& h, Ref& t, int z, int k, BRef bins) {
	Ref p;
	int id;
	
	// Split list
	while (h) {
		p = h;
		h = h->next;
		p->next = NULL;
		id = getId(p->key, z, k);
		insertBin(bins, id, p);
	}
	
	// Join lists
	BRef q = bins->next;
	bins->next = NULL;
	while (q) {
		if (q->head) {
			if (h == NULL) {
				h = q->head;
				t = q->tail;
			}
			else {
				t->next = q->head;
				t = q->tail;
			}
		}

		BRef r = q;
		q = q->next;
		delete r;
	}
}

void radixSort(Ref & h, Ref & t, int k) {
	BRef bins = getBin(-1);
	int loop = getLoop(h, k);
	for (int i = 0; i < loop; i++)
		sortList(h, t, i, k, bins);
	delete bins;
} 
	
int main() {
	srand(time(0));
	
	Ref head = NULL, tail = NULL;
	int k;
	
	createList(head, tail);
	
	cout << "Before ..." << endl;
	showList(head);
	
	cout << "Enter the number of digits that you want to split: ";
	cin >> k;
	radixSort(head, tail, k);
	
	cout << "After ..." << endl;
	showList(head);
	
	delList(head, tail);
	
	return 0;
}