#pragma once

#include <iostream>
#include <queue>
using namespace std;

struct BST_Node
{
	int Key;
	BST_Node* Left;
	BST_Node* Right;
};

BST_Node* BST_CreateNode(int data);

void BST_NLR(BST_Node* root);

void BST_LNR(BST_Node* root);

void BST_LRN(BST_Node* root);

void BST_LevelOrder(BST_Node* root);

BST_Node* BST_Search(BST_Node* root, int x);

BST_Node* BST_Search_(BST_Node* root, int x);

void BST_Insert(BST_Node*& root, int x);

void BST_Insert_(BST_Node*& root, int x);

void BST_Remove(BST_Node*& root, int x);

int BST_Height(BST_Node* root);

int BST_Height_(BST_Node* root);

int BST_CountNode(BST_Node* root);

int BST_Level(BST_Node* root, BST_Node* p);

int BST_CountLeaf(BST_Node* root);

int BST_CountLess(BST_Node* root, int x);

int BST_CountLess_(BST_Node* root, int x);

int BST_CountGreater(BST_Node* root, int x);

int BST_CountGreater_(BST_Node* root, int x);

bool BST_IsBST(BST_Node* root);

bool BST_IsBST(BST_Node* root, BST_Node*& prev);

void BST_RemoveAll(BST_Node*& root);