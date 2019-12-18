#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

static const string INPUT_FILE_NAME = "data.txt";

static const float DELTA = 0.000001f;

struct Student
{
	string ID;
	float Math;
	float Literature;
	float ForeignLanguage;
	string Note;
};

struct Grade
{
	float Average;
	vector<Student> List;
};

struct Node
{
	Grade Key;
	Node* Left;
	Node* Right;
	int Height;
};

void  DisplayIDs(Node* root);

int Height(Node* root);

vector<string> SearchEqual(Node* root, float s);

vector<string> SearchGreater(Node* root, float s);


float Average(Student st);

void LoadData(Node*& root, string file_name);

void Insert(Node*& root, Student st);

Node* CreateNode(Student st);

void Balance(Node*& p);

int Max(int a, int b);

void SingleRotationWithLeftChild(Node*& p);

void SingleRotationWithRightChild(Node*& p);

void DoubleRotationWithLeftChild(Node*& p);

void DoubleRotationWithRightChild(Node*& p);

void RemoveAll(Node*& root);