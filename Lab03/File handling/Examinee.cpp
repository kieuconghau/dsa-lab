#include "Examinee.h"

Examinee readExaminee(string line_info) {
	Examinee examinee;
	vector<string> subs;
	int comma_index;
	
	line_info += ",";
	for (int index = 0; index < line_info.size(); index = comma_index + 1) {
		comma_index = line_info.find(',', index);
		subs.push_back(line_info.substr(index, comma_index - index));
	}

	examinee.ID = subs[0];
	examinee.FullName = subs[1];
	examinee.Math = subs[2] == "" ? 0 : stof(subs[2]);
	examinee.Literature = subs[3] == "" ? 0 : stof(subs[3]);
	examinee.Physic = subs[4] == "" ? 0 : stof(subs[4]);
	examinee.Chemistry = subs[5] == "" ? 0 : stof(subs[5]);
	examinee.Biology = subs[6] == "" ? 0 : stof(subs[6]);
	examinee.History = subs[7] == "" ? 0 : stof(subs[7]);
	examinee.Geography = subs[8] == "" ? 0 : stof(subs[8]);
	examinee.CivicEducation = subs[9] == "" ? 0 : stof(subs[9]);
	examinee.NaturalScience = subs[10] == "" ? 0 : stof(subs[10]);
	examinee.SocialScience = subs[11] == "" ? 0 : stof(subs[11]);
	examinee.ForeignLanguage = subs[12] == "" ? 0 : stof(subs[12]);
	examinee.Note = subs[13];
	examinee.City = subs[14];

	return examinee;
}

vector<Examinee> readExamineeList(string file_name) {
	vector<Examinee> list;
	ifstream fin(file_name);

	if (fin.is_open()) {
		string temp;
		getline(fin, temp);
		
		while (getline(fin, temp)) {
			list.push_back(readExaminee(temp));
		}

		fin.close();
	}

	return list;
}

void writeSumOfScores(vector<Examinee> examinee_list, string out_file_name) {
	ofstream fout(out_file_name);

	if (fout.is_open()) {
		for (vector<Examinee>::iterator examinee = examinee_list.begin();
			examinee != examinee_list.end(); ++examinee) {
			calculateNaturalScienceScore(*examinee);
			calculateSocialScienceScore(*examinee);
			fout << examinee->ID << " " << calculateTotalScore(*examinee) << endl;
		}

		fout.close();
	}
}

void calculateNaturalScienceScore(Examinee& examinee) {
	examinee.NaturalScience = examinee.Physic + examinee.Chemistry + examinee.Biology;
}

void calculateSocialScienceScore(Examinee& examinee) {
	examinee.SocialScience = examinee.History + examinee.Geography + examinee.CivicEducation;
}

float calculateTotalScore(Examinee examniee) {
	return examniee.Math + examniee.Literature + examniee.ForeignLanguage
		+ examniee.NaturalScience + examniee.SocialScience;
}
