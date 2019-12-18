#include "Company.h"

vector<Company> ReadCompanyList(string file_name)
{
	vector<Company> list;

	ifstream fin(file_name);

	if (fin.is_open())
	{
		string line_info;
		getline(fin, line_info);					// Header line

		while (getline(fin, line_info))
		{
			Company cmp;
			vector<string> sub_str;
			char deli = '|';
			int deli_idx;

			line_info += deli;
			for (int i = 0; i < line_info.size(); i = deli_idx + 1) {
				deli_idx = line_info.find(deli, i);
				sub_str.push_back(line_info.substr(i, deli_idx - i));
			}

			cmp.Name = sub_str[0];
			cmp.ProfitTax = sub_str[1];
			cmp.Address = sub_str[2];

			list.push_back(cmp);
		}


		fin.close();
	}

	return list;
}

long long HashString(string company_name)
{
	long long hash = 0;
	string s = company_name;
	int p = 31;
	long long p_pow = 1;
	//long long m = 1e9 + 9;
	long long m = SIZE_OF_HASH_TABLE;

	if (s.size() > 20)
		s = s.substr(s.size() - 20, 20);

	for (int i = 0; i < s.size(); ++i)
	{
		hash = (hash + s[i] * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}

	return hash;
}

Company* CreateHashTable(vector<Company> list_company)
{
	Company* hash_table = new Company[SIZE_OF_HASH_TABLE];
	
	for (int i = 0; i < SIZE_OF_HASH_TABLE; ++i)
		hash_table[i] = NIL;

	for (int i = 0; i < list_company.size(); ++i)
		Insert(hash_table, list_company[i]);

	return hash_table;
}

void Insert(Company* hash_table, Company company)
{
	if (NUMBER_OF_COMPANY >= SIZE_OF_HASH_TABLE)
	{
		cout << "Hash table is full now. Please update the size of the hash table" << endl;
		return;
	}
	
	int index = HashString(company.Name);

	while (hash_table[index].Name != NIL.Name)
		index = (index + 1) % SIZE_OF_HASH_TABLE;

	hash_table[index] = company;

	++NUMBER_OF_COMPANY;
}

Company* Search(Company* hash_table, string company_name)
{
	int index = HashString(company_name);

	int count = 0;
	while (hash_table[index].Name != company_name && count < SIZE_OF_HASH_TABLE)
	{
		index = (index + 1) % SIZE_OF_HASH_TABLE;
		++count;
	}

	if (count == SIZE_OF_HASH_TABLE)
		return nullptr;

	return &hash_table[index];
}
