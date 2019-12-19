#include "Binary_File_1.h"

int main()
{
	vector<Student> list;
	ReadText(list, INPUT_TXT);
	WriteBin(list, INPUT_BIN);
	
	vector<Student> list_1;
	ReadBin(list_1, INPUT_BIN);
	WriteText(list_1, OUTPUT_TXT);

	return 0;
}