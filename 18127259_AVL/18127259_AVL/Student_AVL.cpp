#include "Student_AVL.h"

void DisplayIDs(Node* root)
{
	if (root)
	{
		DisplayIDs(root->Left);

		int const size = root->Key.List.size();
		bool* table = new bool[size]();

		//cout << root->Key.Sum << endl;
		int count = 0;
		while (count < size)
		{
			int i = rand() % size;
			if (table[i] == false)
			{
				cout << " " << root->Key.List[i].ID << endl;
				table[i] = true;
				++count;
			}
		}

		delete[] table;

		//cout << root->Key.Sum << endl;
		//for (int i = 0; i < root->Key.List.size(); ++i)
		//	cout << " " << root->Key.List[i].ID << endl;

		DisplayIDs(root->Right);
	}
}

int Height(Node* root)
{
	return root ? root->Height : 0;
}

vector<string> SearchEqual(Node* root, float s)
{
	if (root == nullptr)
		return vector<string>();

	if (fabs(root->Key.Sum - s) < EPSILON)
	{
		vector<string> id_list;

		for (int i = 0; i < root->Key.List.size(); ++i)
			id_list.push_back(root->Key.List[i].ID);

		return id_list;
	}

	if (s < root->Key.Sum)
		return SearchEqual(root->Left, s);

	return SearchEqual(root->Right, s);
}

vector<string> SearchGreater(Node* root, float s)
{
	if (root == nullptr)
		return vector<string>();

	vector<string> res;

	vector<string> r_list = SearchGreater(root->Right, s);
	res.insert(res.end(), r_list.begin(), r_list.end());

	if (root->Key.Sum < s)
	{
		return res;
	}
	else
	{
		vector<string> list;
		for (int i = 0; i < root->Key.List.size(); ++i)
			list.push_back(root->Key.List[i].ID);
		res.insert(res.end(), list.begin(), list.end());
	}

	vector<string> l_list = SearchGreater(root->Left, s);
	res.insert(res.end(), l_list.begin(), l_list.end());

	return res;
}

float Sum(Student st)
{
	return st.Math + st.Literature + st.ForeignLanguage;
}

bool LoadData(Node*& root, string file_name)
{
	ifstream fin(file_name);

	if (!fin.is_open())
		return false;

	RemoveAll(root);

	string line_info;
	getline(fin, line_info);				// Header line

	while (getline(fin, line_info))
	{
		Student st;
		vector<string> sub_str;
		char deli = ',';
		int deli_idx;

		line_info += deli;
		for (int i = 0; i < line_info.size(); i = deli_idx + 1) {
			deli_idx = line_info.find(deli, i);
			sub_str.push_back(line_info.substr(i, deli_idx - i));
		}

		st.ID = sub_str[0];
		st.Math = stof(sub_str[1]);
		st.Literature = stof(sub_str[2]);
		st.ForeignLanguage = stof(sub_str[3]);
		st.Note = sub_str[4];

		Insert(root, st);
	}

	fin.close();

	return true;
}

void Insert(Node*& root, Student st)
{
	if (root == nullptr)
	{
		root = CreateNode(st);
	}
	else
	{
		if (fabs(Sum(st) - root->Key.Sum) < EPSILON)
		{
			root->Key.List.push_back(st);
			return;
		}

		if (Sum(st) < root->Key.Sum)
			Insert(root->Left, st);
		else
			Insert(root->Right, st);
	}

	Balance(root);
}

Node* CreateNode(Student st)
{
	Node* p = new Node;

	if (p == nullptr)
		return nullptr;

	p->Key.Sum = Sum(st);
	p->Key.List.push_back(st);
	p->Left = p->Right = nullptr;
	p->Height = 1;

	return p;
}

void Balance(Node*& p)
{
	if (p == nullptr)
		return;

	if (Height(p->Left) - Height(p->Right) > 1)			// Left-imbalanced
	{
		if (Height(p->Left->Left) >= Height(p->Left->Right))
			SingleRotationWithLeftChild(p);					// Left Left
		else
			DoubleRotationWithLeftChild(p);					// Left Right
	}
	else if (Height(p->Right) - Height(p->Left) > 1)	// Right-imbalanced
	{
		if (Height(p->Right->Right) >= Height(p->Right->Left))
			SingleRotationWithRightChild(p);				// Right Right
		else
			DoubleRotationWithRightChild(p);				// Right Left
	}

	p->Height = Max(Height(p->Left), Height(p->Right)) + 1;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

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

void DoubleRotationWithLeftChild(Node*& p)
{
	if (p == nullptr)
		return;

	SingleRotationWithRightChild(p->Left);
	SingleRotationWithLeftChild(p);
}

void DoubleRotationWithRightChild(Node*& p)
{
	if (p == nullptr)
		return;

	SingleRotationWithLeftChild(p->Right);
	SingleRotationWithRightChild(p);
}

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

bool IsNumber(string s) {
	if (s == "")
		return false;

	for (int i = 0; i < s.size(); ++i)
		if (s[i] < '0' || s[i] > '9')
			return false;
	return true;
}

bool IsInRange(string s, int start, int end) {
	if (!IsNumber(s))
		return false;

	int num = stoi(s);
	return num >= start && num <= end;
}

void PrintOutputLine()
{
	cout << endl << ".=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.OUTPUT.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=." << endl;
}

bool IsFloat(string str) {
	if (str == "")
		return false;

	int i = 0;
	if (str[0] == '-')
		i = 1;

	int dot_count = 0;
	for (; i < str.size(); ++i) {
		if (str[i] == '.')
			++dot_count;
		else if (str[i] < '0' || str[i] > '9')
			return false;
	}

	if (dot_count > 1)
		return false;

	if (str[0] == '.' && str.size() == 1)
		return false;

	if (str[0] == '-' && str[1] == '.' && str.size() == 2)
		return false;

	return true;
}