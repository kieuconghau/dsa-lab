#pragma once

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int Key;
	Node* Left;
	Node* Right;
	int Height;
};

Node* CreateNode(int data);

void Insert(Node*& root, int x);

void Balance(Node*& p);

int Max(int a, int b);

int Height(Node* p);

void SingleRotationWithLeftChild(Node*& p);

void SingleRotationWithRightChild(Node*& p);

void DoubleRotationWithLeftChild(Node*& p);

void DoubleRotationWithRightChild(Node*& p);

void Remove(Node*& root, int x);

void Remove(Node*& root, Node*& p);

void NLR(Node* root);

void LNR(Node* root);

void LRN(Node* root);

void LevelOrder(Node* root);

bool IsAVLT(Node* root);

bool IsAVLT(Node* root, Node*& prev);

void RemoveAll(Node*& root);
