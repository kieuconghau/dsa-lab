#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

static string const INPUT_TXT = "input.txt";
static string const OUTPUT_TXT = "output.txt";

static string const INPUT_BIN = "input.bin";
static string const OUTPUT_BIN = "output.bin";

struct Student
{
	string ID;
	float A;
	float B;
	float C;
	string Note;
};

void ReadText(vector<Student>& list, string file_name);

void WriteText(vector<Student> list, string file_name);

void ReadBin(vector<Student>& list, string file_name);

void WriteBin(vector<Student> list, string file_name);