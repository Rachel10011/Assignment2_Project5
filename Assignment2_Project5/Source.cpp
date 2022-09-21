#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#define PRE_RELEASE

using namespace std;

struct STUDENT_DATA
{
	string first_name;
	string last_name;

#ifdef PRE_RELEASE
	string email;
#endif // PRE_RELEASE

};


int main() {
#ifdef PRE_RELEASE
	cout << "The application is running pre-release source code" << endl;
	ifstream inputFile("StudentData_Emails.txt");	//reading data from the file

#else 
	cout << "The application is running standard source code" << endl; 
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
			
#ifdef PRE_RELEASE
			getline(ss, studentObject.last_name, ',');
			getline(ss, studentObject.first_name, ',');
			getline(ss, studentObject.email, '\n');
#else
			getline(ss, studentObject.last_name, ',');
			getline(ss, studentObject.first_name, '\n');
#endif // PRE_RELEASE

			vect.push_back(studentObject);
		}
	}

#ifdef _DEBUG		//predefine compiler directive. only run if the program is running in debug mode
		for (size_t i = 0; i < vect.size(); i++)
		{
			cout << vect[i].last_name << ", " << vect[i].first_name << " ";

#ifdef PRE_RELEASE
			cout << vect[i].email << " ";
#endif // PRE_RELEASE
				
			cout << endl;
		}
#endif //_DEBUG

		return 1;
}