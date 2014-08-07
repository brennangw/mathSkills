#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>

using namespace std;


void printStartInfo () {
	cout << "Welcome to Speed Math Skill Builder" << endl << endl << "Enter a menu option's corresponding letter" << endl << endl;
	cout << "Quickstart (q)"<< endl << "History    (h)" << endl <<"Credits    (c)" << endl << "Licence    (l)" << endl << "Setup      (s)"<< endl << "Exit       (e)" << endl <<endl;
	
}
void quickStart () {
	cout << "enter username for quickstart" << endl;
}

void setUp (){
	ofstream outputFile;
	outputFile.open("program3data.txt");
}

void optionCaller (char option) {
	switch (option) {
		case 'q':
			quickStart();
			break;
		case 's':
			setUp();
	}
}
void menu () {
	printStartInfo();
	char option;
	cin >> option;
	optionCaller (option);
	
}



int main() {
	menu();
	

	

}

