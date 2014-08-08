#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>


using namespace std;

//functions
void userNotFound (bool calledBefore, string username);
void quickStart ();
void setUp ();
void menu ();
void standardSession(string user);
string intToSting( int num);

//prints menu info
void printStartInfo () {
	cout << "Welcome to Speed Math Skill Builder" << endl << endl << "Enter a menu option's corresponding letter" << endl << endl;
	cout << "Quickstart (q)"<< endl << "History    (h)" << endl <<"Credits    (c)" << endl << "Licence    (l)" << endl << "Setup      (s)"<< endl << "Exit       (e)" << endl <<endl;
	
}

//checks and returns true or false regarding the existence of a file in the current directory
inline bool exist(const std::string& name)
{
	ifstream file(name);
	if(!file)    //if the file was not found, then file is 0, i.e. !file=1 or true
		return false;    //the file was not found
	else         //if the file was found, then file is non-0
		return true;     //the file was found
	//http://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
}

//checks to see if a user exists. there is a file for each user. also handles soultions if the user does not exist.
void userNotFound (bool calledBefore, string username){
	char input;
	if (!calledBefore){
		cout << "No user by that name." << endl << "Would you like to create one ? (c)"
		<< endl << "Enter another name ? (e)" <<endl;
	}
	cin >> input;
	switch (input) {
		case 'c': {
			std::ofstream outfile (username + ".txt");
			outfile.close();
			break;
		}
		case 'e':
			quickStart();
			break;
		default:
			cout << "invalid input" << endl;
			userNotFound(true, username);
			break;
	}

}

//tries to start a session
void quickStart () {
	string user;
	cout << "enter username for quickstart" << endl;
	cin >> user;
	if (exist(user + ".txt")) {
		cout << "Session Options:" << endl;
		standardSession(user);
	} else {
		userNotFound(false, user);
	}
}

//likely will be removed
void setUp (){
	menu();
//	exist("test.txt");
//	
//	std::ofstream outfile ("test.txt");
//	
//	outfile << "my text here!" << std::endl;
//	
//	outfile.close();
}

//hangles main menu choices
void optionCaller (char option) {
	switch (option) {
		case 'q':
			quickStart();
			break;
		case 's':
			setUp();
	}
}

//converts a number to string using stringstream
string intToString (int num) {
	stringstream ss;
	ss << num;
	string str = ss.str();
	return str;
}

//runs a "normal" session
void standardSession(string user) {
	cout << "Standard Session" << endl;
	int i;
	std::time_t start;
	std::time_t end;
    double duration;
	int v1, v2, result;

    start = time(NULL);
	for (i = 0; i < 1; i++) {
		cout << "New Question:" << endl;
		v1 = rand() % 100;
		v2 = rand() % 100;
		result = v1 + v2;
		
		string v1s = intToString(v1);
		string v2s = intToString(v2);
		
		int input;
		
		cout << v1s << " + " << v2s << " = " << endl;
		while (true) {
			cin >> input;
			
			if (input == v1 + v2) {
				break;
			} else {
				cout << "wrong, sorry" << endl;
			}
		}
		
	}
	end = time(NULL);
	duration = end - start;
	cout << "Time Taken: " << duration << endl;
	
//	
//	(s clocks - e clocks) = length clocks
//	x clock per sec
	
	
}

//shows options and handles chosen option
void menu () {
	printStartInfo();
	char option;
	cin >> option;
	optionCaller (option);
	
}

int main() {
	srand(time(0));
	menu();
	return 0;
}

