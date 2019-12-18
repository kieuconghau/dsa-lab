#include "Student.h"

int main()
{
	Node* root = nullptr;

	LoadData(root, INPUT_FILE_NAME);
	
	DisplayIDs(root);

	float s;
	cin >> s;
	vector<string> list = SearchGreater(root, s);
	for (int i = 0; i < list.size(); ++i)
		cout << " - " << list[i] << endl;



	RemoveAll(root);

	return 0;
}