#include "AVLT.h"

/* 1. Initialize a node from a given value */
Node* CreateNode(int data)
{
	Node* p = new Node;

	if (p == nullptr)
		return nullptr;

	p->Key = data;
	p->Left = p->Right = nullptr;
	p->Height = 1;

	return p;
}

/* 2. Add a node with a given value into an AVL Tree */
void Insert(Node*& root, int x)
{
	if (root == nullptr)
	{
		root = CreateNode(x);
	}
	else
	{
		if (x == root->Key)
			return;

		if (x < root->Key)
			Insert(root->Left, x);
		else
			Insert(root->Right, x);
	}

	Balance(root);
}

/* Balance a (sub)tree rooted at a given node p */
void Balance(Node*& p)
{
	if (p == nullptr)
		return;

	if (Height(p->Left) - Height(p->Right) > 1)			// Left-imbalanced
	{
		if (Height(p->Left->Left) >= Height(p->Left->Right))
			SingleRotationWithLeftChild(p);		// Left Left
		else
			DoubleRotationWithLeftChild(p);		// Left Right
	}
	else if (Height(p->Right) - Height(p->Left) > 1)	// Right-imbalanced
	{
		if (Height(p->Right->Right) >= Height(p->Right->Left))
			SingleRotationWithRightChild(p);
		else
			DoubleRotationWithRightChild(p);
	}

	p->Height = Max(Height(p->Left), Height(p->Right)) + 1;
}

/* Find the maximum value between 2 integers a and b */
int Max(int a, int b)
{
	return a > b ? a : b;
}

/* Calculate the height of a tree rooted at a given node p */
int Height(Node* p)
{
	return p ? p->Height : 0;
}

/* Right rotation at a given node p */
void SingleRotationWithLeftChild(Node*& p)
{
	if (p == nullptr)
		return;

	Node* p1 = p->Left;
	
	p->Left = p1->Right;
	p1->Right = p;

	p->Height = Max(Height(p->Left), Height(p->Right)) + 1;
	p1->Height = Max(Height(p1->Left), Height(p1->Right)) + 1;

	p = p1;
}

/* Left rotation at a given node p */
void SingleRotationWithRightChild(Node*& p)
{
	if (p == nullptr)
		return;
	
	Node* p1 = p->Right;

	p->Right = p1->Left;
	p1->Left = p;

	p->Height = Max(Height(p->Left), Height(p->Right)) + 1;
	p1->Height = Max(Height(p1->Left), Height(p1->Right)) + 1;

	p = p1;
}

/* Double rotation at a given node p: Left rotation at p->Left then Right rotation at p */
void DoubleRotationWithLeftChild(Node*& p)
{
	if (p == nullptr)
		return;

	SingleRotationWithRightChild(p->Left);
	SingleRotationWithLeftChild(p);
}

/* Double rotation at a given node p: Right rotation at p->Right then Left rotation at p */
void DoubleRotationWithRightChild(Node*& p)
{
	if (p == nullptr)
		return;

	SingleRotationWithLeftChild(p->Right);
	SingleRotationWithRightChild(p);
}

/* 3. Remove a node with a given value from a given AVL Tree*/
void Remove(Node*& root, int x)
{
	if (root == nullptr)
		return;

	if (x < root->Key)
		Remove(root->Left, x);
	else if (x > root->Key)
		Remove(root->Right, x);
	else
	{
		Node* p = root;

		if (root->Left == nullptr)
			root = root->Right;
		else if (root->Right == nullptr)
			root = root->Left;
		else
			Remove(root->Left, p);

		delete p;
	}

	Balance(root);
}

void Remove(Node*& root, Node*& p)
{
	if (root->Right)
		Remove(root->Right, p);
	else
	{
		p->Key = root->Key;
		p = root;
		root = root->Left;
	}

	Balance(root);
}

/* 4. Pre-order traversal */
void NLR(Node* root)
{
	if (root)
	{
		cout << " [" << root->Key << ", " << root->Height << "]";
		NLR(root->Left);
		NLR(root->Right);
	}
}

/* 5. In-order traversal */
void LNR(Node* root)
{
	if (root)
	{
		LNR(root->Left);
		cout << " [" << root->Key << ", " << root->Height << "]";
		LNR(root->Right);
	}
}

/* 6. Post-order traversal */
void LRN(Node* root)
{
	if (root)
	{
		LRN(root->Left);
		LRN(root->Right);
		cout << " [" << root->Key << ", " << root->Height << "]";
	}
}

/* 7. Level-order traversal */
void LevelOrder(Node* root)
{
	if (root)
	{
		queue<Node*> q;

		q.push(root);
		while (q.size())
		{
			cout << " [" << q.front()->Key << ", " << q.front()->Height << "]";

			if (q.front()->Left)
				q.push(q.front()->Left);

			if (q.front()->Right)
				q.push(q.front()->Right);

			q.pop();
		}
	}
}

/* 8. Determine if a given Binary Tree is an AVL Tree*/
bool IsAVLT(Node* root)
{
	Node* prev = nullptr;
	return IsAVLT(root, prev);
}

bool IsAVLT(Node* root, Node*& prev)
{
	if (root)
	{
		if (!IsAVLT(root->Left, prev))
			return false;

		if (prev != nullptr && root->Key <= prev->Key)
			return false;

		if (abs(Height(root->Left) - Height(root->Right)) > 1)
			return false;

		prev = root;

		if (!IsAVLT(root->Right, prev))
			return false;
	}

	return true;
}

/* Remove all nodes from a AVT Tree */
void RemoveAll(Node*& root)
{
	if (root)
	{
		RemoveAll(root->Left);
		RemoveAll(root->Right);
		delete root;
		root = nullptr;
	}
}