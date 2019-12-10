#include "BST.h"

/* 1. Create a node */
BST_Node* BST_CreateNode(int data)
{
	BST_Node* p = new BST_Node;

	if (p == nullptr)
		return nullptr;

	p->Key = data;
	p->Left = p->Right = nullptr;

	return p;
}

/* 2. Pre-order traversal */
void BST_NLR(BST_Node* root)
{
	if (root)
	{
		cout << " " << root->Key;
		BST_NLR(root->Left);
		BST_NLR(root->Right);
	}
}

/* 3. In-order traversal */
void BST_LNR(BST_Node* root)
{
	if (root)
	{
		BST_LNR(root->Left);
		cout << " " << root->Key;
		BST_LNR(root->Right);
	}
}

/* 4. Post-order traversal */
void BST_LRN(BST_Node* root)
{
	if (root)
	{
		BST_LRN(root->Left);
		BST_LRN(root->Right);
		cout << " " << root->Key;
	}
}

/* 5. BST_Level-order traversal */
void BST_LevelOrder(BST_Node* root)
{
	if (root)
	{
		queue<BST_Node*> q;

		q.push(root);
		while (q.size())
		{
			cout << " " << q.front()->Key;

			if (q.front()->Left)
				q.push(q.front()->Left);

			if (q.front()->Right)
				q.push(q.front()->Right);

			q.pop();
		}
	}
}

/* 6. BST_Search a node with a given value from a BST */
BST_Node* BST_Search(BST_Node* root, int x)		// Recursive
{
	if (root == nullptr || x == root->Key)
		return root;

	if (x < root->Key)
		return BST_Search(root->Left, x);

	return BST_Search(root->Right, x);
}

BST_Node* BST_Search_(BST_Node* root, int x)	// Iterative
{
	while (root)
	{
		if (x == root->Key)
			return root;

		if (x < root->Key)
			root = root->Left;
		else
			root = root->Right;
	}

	return nullptr;
}

/* 7. Add a node with a given value to a BST */
void BST_Insert(BST_Node*& root, int x)		// Recursive
{
	if (root == nullptr)
	{
		root = BST_CreateNode(x);
	}
	else
	{
		if (x == root->Key)
			return;

		if (x < root->Key)
			BST_Insert(root->Left, x);
		else
			BST_Insert(root->Right, x);
	}
}

void BST_Insert_(BST_Node*& root, int x)	// Iterative
{
	if (root == nullptr)
	{
		root = BST_CreateNode(x);
	}
	else
	{
		BST_Node* chase_p = nullptr;
		BST_Node* p = root;

		while (p)
		{
			chase_p = p;

			if (x == p->Key)
				return;

			if (x < p->Key)
				p = p->Left;
			else
				p = p->Right;
		}

		if (x < chase_p->Key)
			chase_p->Left = BST_CreateNode(x);
		else
			chase_p->Right = BST_CreateNode(x);
	}
}

/* 8. BST_Remove a node with a given value from a BST */
void BST_Remove(BST_Node*& root, int x)
{
	if (root != nullptr)
	{
		if (x == root->Key)
		{
			BST_Node* p = root;

			// root is node-leaf or node-has-1-child
			if (p->Left == nullptr)
				root = root->Right;
			else if (p->Right == nullptr)
				root = root->Left;

			// root is node-has-2-child
			else
			{
				BST_Node* chase_p = root;
				p = root->Left;

				while (p->Right)
				{
					chase_p = p;
					p = p->Right;
				}

				root->Key = p->Key;

				if (chase_p == root)	// if the above while-loop does not run, p is already a predecessor
					chase_p->Left = p->Left;
				else
					chase_p->Right = p->Left;
			}

			delete p;
			p = nullptr;
		}
		else if (x < root->Key)
			BST_Remove(root->Left, x);
		else
			BST_Remove(root->Right, x);
	}
}

/* 9. Calculate the height of a BST */
int BST_Height(BST_Node* root)		// Recursive
{
	if (root == nullptr)
		return 0;

	int left_height = BST_Height(root->Left);
	int right_height = BST_Height(root->Right);

	return (left_height > right_height ? left_height : right_height) + 1;
}

int BST_Height_(BST_Node* root)		// Iterative
{
	int height = 0;

	if (root)
	{
		queue<BST_Node*> q;
		int count = 0;		// The number of nodes in a level

		q.push(root);
		while (true)
		{
			count = q.size();

			if (count)
				++height;
			else
				break;

			while (count--)
			{
				if (q.front()->Left)
					q.push(q.front()->Left);

				if (q.front()->Right)
					q.push(q.front()->Right);

				q.pop();
			}
		}
	}

	return height;
}

/* 10. Count the number of nodes from a BST */
int BST_CountNode(BST_Node* root)		// Recursive
{
	if (root == nullptr)
		return 0;

	return BST_CountNode(root->Left) + BST_CountNode(root->Right) + 1;
}

int CountNode_(BST_Node* root)		// Iterative
{
	int count = 0;

	if (root)
	{
		queue<BST_Node*> q;

		q.push(root);
		while (q.size())
		{
			++count;

			if (q.front()->Left)
				q.push(q.front()->Left);

			if (q.front()->Right)
				q.push(q.front()->Right);

			q.pop();
		}
	}

	return count;
}

/* 11. Calculate the level of a given node */
int BST_Level(BST_Node* root, BST_Node* p)
{
	if (p == nullptr)
		return 0;

	int p_level = 0;

	while (root)
	{
		++p_level;

		if (p->Key == root->Key)
			break;

		if (p->Key < root->Key)
			root = root->Left;
		else
			root = root->Right;
	}

	return p_level;
}

/* 12. Count the number of leaves from a BST */
int BST_CountLeaf(BST_Node* root)
{
	if (root == nullptr)
		return 0;

	if (root->Left == nullptr && root->Right == nullptr)
		return 1;

	return BST_CountLeaf(root->Left) + BST_CountLeaf(root->Right);
}

/* 13. Count the number of node from a given BST which key value is less than a given value */
int BST_CountLess(BST_Node* root, int x)	// Recursive
{
	if (root == nullptr)
		return 0;

	if (root->Key < x)
		return 1 + BST_CountLess(root->Left, x) + BST_CountLess(root->Right, x);

	return BST_CountLess(root->Left, x);
}

int BST_CountLess_(BST_Node* root, int x)	// Iterative
{
	int count = 0;

	if (root)
	{
		queue<BST_Node*> q;
		
		q.push(root);
		while (q.size())
		{
			if (q.front()->Key < x)
				++count;

			if (q.front()->Left)
				q.push(q.front()->Left);

			if (q.front()->Right)
				q.push(q.front()->Right);

			q.pop();
		}
	}

	return count;
}

/* 14. Count the number of node from a given BST which key value is greater than a given value */
int BST_CountGreater(BST_Node* root, int x)		// Recursive
{
	if (root == nullptr)
		return 0;

	if (root->Key > x)
		return 1 + BST_CountGreater(root->Left, x) + BST_CountGreater(root->Right, x);

	return BST_CountGreater(root->Right, x);
}

int BST_CountGreater_(BST_Node* root, int x)	// Iterative
{
	int count = 0;

	if (root)
	{
		queue<BST_Node*> q;

		q.push(root);
		while (q.size())
		{
			if (q.front()->Key > x)
				++count;

			if (q.front()->Left)
				q.push(q.front()->Left);

			if (q.front()->Right)
				q.push(q.front()->Right);

			q.pop();
		}
	}

	return count;
}

/* 15. Determine if a given BT is a BST */
bool BST_IsBST(BST_Node* root)
{
	BST_Node* prev = nullptr;
	return BST_IsBST(root, prev);
}

bool BST_IsBST(BST_Node* root, BST_Node*& prev)
{
	if (root)
	{
		if (!BST_IsBST(root->Left, prev))
			return false;

		if (prev != nullptr && root->Key <= prev->Key)
			return false;

		prev = root;

		if (!BST_IsBST(root->Right, prev))
			return false;
	}

	return true;
}

/* Remove all nodes from a BST */
void BST_RemoveAll(BST_Node*& root)
{
	if (root)
	{
		BST_RemoveAll(root->Left);
		BST_RemoveAll(root->Right);
		delete root;
		root = nullptr;
	}
}