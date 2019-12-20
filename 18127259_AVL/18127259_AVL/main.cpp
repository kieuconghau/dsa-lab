#include "Student_AVL.h"

int main()
{
	srand(time(nullptr));

	Node* root = nullptr;

	if (LoadData(root, INPUT_FILE_NAME))
	{
		while (true) {
			string choice;
			do {
				system("cls");

				cout << " 0. Exit" << endl;
				cout << " 1. Display students' ID in ascending order by average grade" << endl;
				cout << " 2. Calculate the height of the tree" << endl;
				cout << " 3. Display students' ID whose average grade is equal to s" << endl;
				cout << " 4. Display students' ID whose average grade is greater than or equal to s" << endl;

				cout << " Select: ";
				getline(cin, choice);
			} while (!IsInRange(choice, 0, 4));

			if (choice == "0") {
				break;
			}

			if (choice == "1") {
				PrintOutputLine();
				DisplayIDs(root);
			}
			else if (choice == "2") {
				PrintOutputLine();
				cout << " " << Height(root) << endl;
			}
			else if (choice == "3")
			{
				float s;
				string str_s;

				cout << endl << " Input s: ";
				getline(cin, str_s);

				if (IsFloat(str_s))
				{
					s = stof(str_s);
					PrintOutputLine();
					vector<string> id_list = SearchEqual(root, s);
					if (id_list.size() == 0)
					{
						cout << " There are no students." << endl;
					}
					else
					{
						for (int i = 0; i < id_list.size(); ++i)
							cout << " " << id_list[i] << endl;
					}
				}
				else
				{
					cout << endl << " \aThe input is not valid!" << endl;
				}
			}
			else if (choice == "4")
			{
				float s;
				string str_s;

				cout << endl << " Input s: ";
				getline(cin, str_s);

				if (IsFloat(str_s))
				{
					s = stof(str_s);
					PrintOutputLine();
					vector<string> id_list = SearchGreater(root, s);
					if (id_list.size() == 0)
					{
						cout << " There are no students." << endl;
					}
					else
					{
						for (int i = 0; i < id_list.size(); ++i)
							cout << " " << id_list[i] << endl;
					}
				}
				else
				{
					cout << endl << " \aThe input is not valid!" << endl;
				}
			}
			else {
				cout << endl << "\aBUG: The selected number is not in range." << endl;
				break;
			}

			cout << endl << "Press Enter to continue...";
			cin.ignore();
		}
	}
	else
	{
		cout << endl << "\aCan not open file " << INPUT_FILE_NAME << "." << endl;
	}

	RemoveAll(root);

	return 0;
}