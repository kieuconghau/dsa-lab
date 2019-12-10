#include "BST.h"

int main()
{
	BST_Node* r = nullptr;
	int x;
	BST_Node* p;

	BST_Insert(r, 7);
	BST_Insert(r, 3);
	BST_Insert_(r, 9);
	BST_Insert(r, 1);
	BST_Insert_(r, 5);
	BST_Insert(r, 8);
	BST_Insert_(r, 11);
	BST_Insert(r, 6);
	BST_Insert_(r, 10);
	
	cout << "- Pre-order:	";
	BST_NLR(r);
	cout << endl;

	cout << "- In-order:	";
	BST_LNR(r);
	cout << endl;

	cout << "- Post-order:	";
	BST_LRN(r);
	cout << endl;

	cout << "- Level-order:	";
	BST_LevelOrder(r);
	cout << endl;
	
	cout << "- Height:	" << BST_Height(r) << endl;
	
	cout << "- CountNode:	" << BST_CountNode(r) << endl;

	x = 9;
	cout << "- Remove " << x << endl;
	BST_Remove(r, x);

	cout << "- In-order:	";
	BST_LNR(r);
	cout << endl;

	cout << "- Level-order:	";
	BST_LevelOrder(r);
	cout << endl;

	p = r->Right->Right->Left;
	cout << "- Level of node ";
	p ? cout << p->Key : cout << "nullptr";
	cout << ": " << BST_Level(r, p) << endl;

	cout << "- CountLeaf: " << BST_CountLeaf(r) << endl;

	x = 5;
	cout << "- Less than " << x << ": " << BST_CountLess_(r, x) << endl;

	x = 5;
	cout << "- Greater than " << x << ": " << BST_CountGreater_(r, x) << endl;

	cout << "- Is a BST: " << BST_IsBST(r) << endl;

	BST_RemoveAll(r);

	return 0;
}
