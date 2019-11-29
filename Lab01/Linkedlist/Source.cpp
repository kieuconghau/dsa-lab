#include <iostream>
#include "Source.h"
using namespace std;

struct NODE {
	int key;
	NODE* p_next;
};

struct List {
	NODE* p_head;
	NODE* p_tail;
};

NODE* CreateNode(int data) {
	NODE* node = new NODE;
	
	if (node == nullptr) {
		return nullptr;
	}

	node->key = data;
	node->p_next = nullptr;

	return node;
}

List* CreateList(NODE* p_node) {
	List* list = new List;

	if (list == nullptr) {
		return nullptr;
	}

	list->p_head = list->p_tail = p_node;

	return list;
}

bool AddHead(List* L, int data) {
	NODE* node = CreateNode(data);
	
	if (node == nullptr) {
		return false;
	}

	if (L->p_head == nullptr) {
		L->p_head = L->p_tail = node;
	}
	else {
		node->p_next = L->p_head;
		L->p_head = node;
	}

	return true;
}

bool AddTail(List* L, int data) {
	NODE* node = CreateNode(data);

	if (node == nullptr) {
		return false;
	}

	if (L->p_head == nullptr) {
		L->p_head = L->p_tail = node;
	}
	else {
		L->p_tail->p_next = node;
		L->p_tail = node;
	}

	return true;
}

void RemoveHead(List* L) {
	if (L->p_head != nullptr) {
		if (L->p_head == L->p_tail) {
			delete L->p_head;
			L->p_head = L->p_tail = nullptr;
		}
		else {
			NODE* old_head = L->p_head;
			L->p_head = L->p_head->p_next;
			delete old_head;
		}
	}
}

void RemoveTail(List* L) {
	if (L->p_head != nullptr) {
		if (L->p_head == L->p_tail) {
			delete L->p_head;
			L->p_head = L->p_tail = nullptr;
		}
		else {
			for (NODE* node = L->p_head; node != L->p_tail; node = node->p_next) {
				if (node->p_next == L->p_tail) {
					delete L->p_tail;
					L->p_tail = node;
				}
			}
		}
	}
}

void RemoveAll(List*& L) {
	while (L->p_head != nullptr) {
		RemoveHead(L);
	}
	delete L;
}

void PrintList(List* L) {
	for (NODE* node = L->p_head; node != nullptr; node = node->p_next) {
		cout << " " << node->key;
	}
}

int CountElements(List* L) {
	int count = 0;

	for (NODE* node = L->p_head; node != nullptr; node = node->p_next) {
		++count;
	}
	return count;
}

List* ReverseList(List* L) {
	List* r_list = CreateList(nullptr);

	if (r_list == nullptr) {
		return nullptr;
	}

	for (NODE* node = L->p_head; node != nullptr; node = node->p_next) {
		AddHead(L, node->key);
	}

	return r_list;
}

/*
Method 1: 2 nested loop => O(n^2)
Method 2: Merged sort first, then remove duplicates in linear time => O(nlogn) + O(n)
Method 3: Hashing table => O(n)
*/
void RemoveDuplicate(List*& L) {
	NODE* p = L->p_head;
	NODE* pre = nullptr;
	NODE* cur = nullptr;

	while (p != nullptr) {
		pre = p;
		cur = pre->p_next;
		while (cur != nullptr) {
			if (cur->key == p->key) {
				if (cur == L->p_tail) {
					L->p_tail = pre;
				}

				pre->p_next = cur->p_next;
				delete cur;
			}
			else {
				pre = cur;
			}
			cur = pre->p_next;
		}
		p = p->p_next;
	}
}

bool RemoveElement(List*& L, int key) {
	if (L->p_head != nullptr) {
		while (L->p_head->key == key) {
			RemoveHead(L);
		}

		for (NODE* node = L->p_head; node != L->p_tail; node = node->p_next) {
			if (node->p_next->key == key) {
				NODE* temp = node->p_next;

				if (temp == L->p_tail) {
					L->p_tail = node;
				}

				node->p_next = temp->p_next;
				delete temp;
			}
		}
	}
}

int main() {

}