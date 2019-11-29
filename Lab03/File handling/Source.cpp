#include "Examinee.h"

string const INPUT_FILE_NAME = "data.txt";
string const OUTPUT_FILE_NAME = "output.txt";

int main() {
	vector<Examinee> examinee_list = readExamineeList(INPUT_FILE_NAME);
	writeSumOfScores(examinee_list, OUTPUT_FILE_NAME);

	return 0;
}