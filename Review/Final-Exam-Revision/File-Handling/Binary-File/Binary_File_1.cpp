#include "Binary_File_1.h"

//https://stackoverflow.com/questions/23399931/c-reading-string-from-binary-file-using-fstream

void ReadText(vector<Student>& list, string file_name)
{
	ifstream fin(file_name);

	if (fin.is_open())
	{
		string str;
		while (getline(fin, str))
		{
			Student st;
			vector<string> temp;
			char deli = ',';
			int deli_idx = 0;

			str += deli;
			for (int i = 0; i < str.size(); i = deli_idx + 1)
			{
				deli_idx = str.find(deli, i);
				temp.push_back(str.substr(i, deli_idx - i));
			}

			st.ID = temp[0];
			st.A = stof(temp[1]);
			st.B = stof(temp[2]);
			st.C = stof(temp[3]);
			st.Note = temp[4];

			list.push_back(st);
		}

		fin.close();
	}
}

void WriteText(vector<Student> list, string file_name)
{
	ofstream fout(file_name);

	if (fout.is_open())
	{
		for (int i = 0; i < list.size(); ++i)
			fout << list[i].ID << "," << list[i].A << "," << list[i].B << "," << list[i].C << "," << list[i].Note << endl;

		fout.close();
	}
}

void ReadBin(vector<Student>& list, string file_name)
{
	ifstream fin(file_name, ios::binary);

	if (fin.is_open())
	{
		int i = 0;
		while (fin.peek() != EOF)
		{
			Student st;

			int size;
			char* temp;

			fin.read(reinterpret_cast<char*> (&size), sizeof(int));
			temp = new char[size + 1];
			fin.read(reinterpret_cast<char*> (temp), size);
			temp[size] = '\0';
			st.ID = temp;
			delete[] temp;

			fin.read(reinterpret_cast<char*> (&st.A), sizeof(float));
			fin.read(reinterpret_cast<char*> (&st.B), sizeof(float));
			fin.read(reinterpret_cast<char*> (&st.C), sizeof(float));
			
			fin.read(reinterpret_cast<char*> (&size), sizeof(int));
			temp = new char[size + 1];
			fin.read(temp, size);
			temp[size] = '\0';
			st.Note = temp;
			delete[] temp;

			list.push_back(st);
		}

		fin.close();
	}
}

void WriteBin(vector<Student> list, string file_name)
{
	ofstream fout(file_name, ios::binary);

	if (fout.is_open())
	{
		for (int i = 0; i < list.size(); ++i)
		{
			int size;

			size = list[i].ID.size();
			fout.write(reinterpret_cast<const char*> (&size), sizeof(int));
			fout.write(reinterpret_cast<const char*> (list[i].ID.c_str()), size);

			fout.write(reinterpret_cast<const char*> (&list[i].A), sizeof(float));
			fout.write(reinterpret_cast<const char*> (&list[i].B), sizeof(float));
			fout.write(reinterpret_cast<const char*> (&list[i].C), sizeof(float));
			
			size = list[i].Note.size();
			fout.write(reinterpret_cast<const char*> (&size), sizeof(int));
			fout.write(reinterpret_cast<const char*> (list[i].Note.c_str()), size);
		}

		fout.close();
	}
}
