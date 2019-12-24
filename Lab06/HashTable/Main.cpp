#include "Company.h"

int main()
{
	vector<Company> company_list = ReadCompanyList(INPUT);

	Company* hash_table = CreateHashTable(company_list);

	Company* cmp;
	for (int i = 0; i < company_list.size(); ++i)
	{
		cmp = Search(hash_table, company_list[i].Name);
		cout << " - Name: " << cmp->Name << endl;
		cout << " - Profit Tax: " << cmp->ProfitTax << endl;
		cout << " - Address: " << cmp->Address << endl;
		cout << endl;
	}

	delete[] hash_table;

	return 0;
}