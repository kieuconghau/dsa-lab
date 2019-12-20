#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;

static const string INPUT_FILE_NAME = "data.txt";

static const float EPSILON = 0.0001f;

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
	float Sum;
	vector<Student> List;
};

struct Node
{
	Grade Key;
	Node* Left;
	Node* Right;
	int Height;
};


// Required functions
void DisplayIDs(Node* root);

int Height(Node* root);

vector<string> SearchEqual(Node* root, float s);

vector<string> SearchGreater(Node* root, float s);


// Required functions support
float Sum(Student st);

bool LoadData(Node*& root, string file_name);

void Insert(Node*& root, Student st);

Node* CreateNode(Student st);

void Balance(Node*& p);

int Max(int a, int b);

void SingleRotationWithLeftChild(Node*& p);

void SingleRotationWithRightChild(Node*& p);

void DoubleRotationWithLeftChild(Node*& p);

void DoubleRotationWithRightChild(Node*& p);

void RemoveAll(Node*& root);


// Main support
bool IsNumber(string s);

bool IsInRange(string s, int start, int end);

void PrintOutputLine();

bool IsFloat(string str);