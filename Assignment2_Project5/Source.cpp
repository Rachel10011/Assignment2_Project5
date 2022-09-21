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
			getline(ss, studentObject.last_name, ',');
			getline(ss, studentObject.first_name, '\n');
			vect.push_back(studentObject);
		}

#ifdef _DEBUG		//predefine compiler directive. only run if the program is running in debug mode
		for (size_t i = 0; i < vect.size(); i++)
		{
			cout << vect[i].last_name << ", " << vect[i].first_name << endl;
		}
#endif 

	}
}