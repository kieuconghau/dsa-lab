#include "AVLT.h"

int main()
{
	Node* r = nullptr;

	Insert(r, 1);
	Insert(r, 3);
	Insert(r, 5);
	Insert(r, 7);
	Insert(r, 9);
	Insert(r, 11);
	Insert(r, 13);
	Insert(r, 15);
	Insert(r, 17);
	Insert(r, 19);
	Insert(r, 14);

	Remove(r, 11);
	Remove(r, 9);

	cout << "- Pre-order:	";
	NLR(r);
	cout << endl;

	cout << "- In-order:	";
	LNR(r);
	cout << endl;

	cout << "- Post-order:	";
	LRN(r);
	cout << endl;

	cout << "- Level-order:	";
	LevelOrder(r);
	cout << endl;

	cout << "- Is a AVLT: " << IsAVLT(r) << endl;

	RemoveAll(r);

	return 0;
}