#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Examinee {
	string ID, FullName, Note, City;
	float Math, Literature, Physic, Chemistry, Biology, History,
		Geography, CivicEducation, NaturalScience, SocialScience, ForeignLanguage;
};

Examinee readExaminee(string line_info);

vector<Examinee> readExamineeList(string file_name);

void writeSumOfScores(vector<Examinee> examinee_list, string out_file_name);


void calculateNaturalScienceScore(Examinee& examinee);

void calculateSocialScienceScore(Examinee& examinee);

float calculateTotalScore(Examinee examniee);