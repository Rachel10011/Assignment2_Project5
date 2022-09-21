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

#define PRE_RELEASE

int main() {
#ifdef PRE_RELEASE
	cout << "the application is running pre-release source code" << endl;
	ifstream inputFile("StudentData_Emails.txt");	//reading data from the file

#else 
	cout << "the application is running standard source code" << endl; 
	ifstream inputFile("StudentData.txt");	//reading data from the file
#endif

	vector<STUDENT_DATA> vect;
	string line;
	if (inputFile.is_open()) {
		while (getline(inputFile, line))
		{
			//parse data read from file, and store into vector space
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