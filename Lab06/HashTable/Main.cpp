#include "Company.h"

int main()
{
	vector<Company> company_list = ReadCompanyList(INPUT);

	Company* hash_table = CreateHashTable(company_list);

	Company* cmp = Search(hash_table, "MB BANK - NGAN HANG QUAN DOI VIET NAM");

	if (cmp)
	{
		cout << " - Name: " << cmp->Name << endl;
		cout << " - Profit Tax: " << cmp->ProfitTax << endl;
		cout << " - Address: " << cmp->Address << endl;
	}

	delete[] hash_table;

	return 0;
}