#pragma once

#include <iostream>
using namespace std;

enum class Color : char
{
	RED,
	BLACK
};

struct Node
{
	int Key;
	Color Color;
	Node* Parent;
	Node* Left;
	Node* Right;
};

void Initialize(Node*& root, Node*& nil);

Node* CreateNode(Node* nil, int key, Color color);

void LNR(Node* root, Node* nil);

void Insert(Node*& root, Node* nil, int key);

void InsFixUp(Node*& root, Node* nil, Node* x);

void Remove(Node*& root, Node* nil, int key);

void RevFixUp(Node*& root, Node* nil, Node* p);

void SingleRotationWithRightChild(Node*& root, Node* nil, Node* p);

void SingleRotationWithLeftChild(Node*& root, Node* nil, Node* p);

void RemoveAll(Node*& root, Node*& nil);

void RemoveAllNode(Node*& root, Node*& nil);