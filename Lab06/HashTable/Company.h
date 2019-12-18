#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Company
{
	string Name;
	string ProfitTax;
	string Address;
};

static const string INPUT = "MST.txt";

static const int SIZE_OF_HASH_TABLE = 2000;

static int NUMBER_OF_COMPANY = 0;

static const Company NIL;

vector<Company> ReadCompanyList(string file_name);

long long HashString(string company_name);

Company* CreateHashTable(vector<Company> list_company);

void Insert(Company* hash_table, Company company);

Company* Search(Company* hash_table, string company_name);