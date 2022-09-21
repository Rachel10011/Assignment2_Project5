#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct STUDENT_DATA
{
	string first_name;
	string last_name;
};

int main() {

	vector<STUDENT_DATA> vect;
	string line;

	//reading data from the file, parse data, and store into vector space
	ifstream inputFile("StudentData.txt");
	if (inputFile.is_open()) {
		while (getline(inputFile, line))
		{
			STUDENT_DATA studentObject;
			std::istringstream ss(line);
			getline(ss, studentObject.first_name, ',');
			getline(ss, studentObject.last_name, '\n');
			vect.push_back(studentObject);
		}

		
	}
}