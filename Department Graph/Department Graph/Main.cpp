//Contestant ID: 01-0024-0045
#include "Classroom.h"
#include "Department.h"
#include <vector>
#include <iostream>
#include <exception>
#include <stdlib.h>

using namespace std;

//prints out the department menu selection screen
void printDeptMenu(vector<Department> & depts) {
	cout << "Up Town University\n" << endl;
	for(unsigned int i = 0; i < depts.size(); i++) {
		cout << depts[i].getDeptID() + ". " + depts[i].getName() << endl;
	}
	cout << "\n";
	cout << "Please pick the department: " << endl;
}

//prints out the horizontal data graph
void horizontal_graph(Department & dept) {
	cout << "Department                                Students\n" << endl;
	for (int i = 0; i < dept.getNumClassrooms(); i++) {
		cout << dept.getDeptID() + dept.getClassrooms()[i].getRoomID() + " ";
		for (int j = 0; j < dept.getClassrooms()[i].getSize(); j++) {
			cout << "*";
		}
		for (int k = 0; k < 40 - dept.getClassrooms()[i].getSize(); k++) {
			cout << " ";
		}
		cout << " ";
		cout << dept.getClassrooms()[i].getSize() << endl;
		cout << "\n";
	}
}

//prints out the vertical data graph
void vertical_graph(Department & dept) {
	cout << "Students       ";
	for (int i = 0; i < dept.getNumClassrooms(); i++) {
		if (dept.getClassrooms()[i].getSize() >= 10) {
			cout << to_string(dept.getClassrooms()[i].getSize() / 10) + " ";
		}
		else {
			cout << "  ";
		}
	}
	cout << "" << endl;
	cout << "               ";
	for (int i = 0; i < dept.getNumClassrooms(); i++) {
		cout << to_string(dept.getClassrooms()[i].getSize() % 10) + " ";
	}
	cout << "" << endl;
	cout << "               ";
	for (int i = 40; i > 0; i--) {
		for (int j = 0; j < dept.getNumClassrooms(); j++) {
			if (dept.getClassrooms()[j].getSize() >= i) {
				cout << "* ";
			}
			else {
				cout << "  ";
			}
		}
		cout << "" << endl;
		cout << "               ";
	}
	cout << "" << endl;
	cout << "Department     ";
	for (int i = 0; i < dept.getNumClassrooms(); i++) {
		cout << dept.getDeptID() + " ";
	}
	cout << "" << endl;
	cout << "               ";
	for (int i = 0; i < dept.getNumClassrooms(); i++) {
		cout << dept.getClassrooms()[i].getRoomID().substr(0, 1) + " ";
	}
	cout << "" << endl;
	cout << "               ";
	for (int i = 0; i < dept.getNumClassrooms(); i++) {
		cout << dept.getClassrooms()[i].getRoomID().substr(1, 2) + " ";
	}
	cout << "" << endl;
}

//fill each classroom with the total students allowed
void menu_collect(vector<Department> & depts, unsigned int deptChoice) {
	unsigned int classSize;
	string nextRoomID;
	for (int i = 0; i < depts[deptChoice].getNumClassrooms(); i++) {
		cout << "Class sizes are from 0 - 40 students" << endl;
		while (true) {
			nextRoomID = "0" + to_string(i);
			cout << depts[deptChoice].getDeptID() + nextRoomID + " ";
			try {
				cin >> classSize;
				if (!cin.good()) {
					throw ("Please enter only numbers from 0-40");
				}
				if (classSize < 0 || classSize > 40) {
					throw ("Please enter only numbers from 0-40");
				}
				break;
			}
			catch (const char * msg) {
				cin.clear();
				cin.get();
				cout << msg << endl;
			}
		}
		Classroom newClass(nextRoomID, classSize);
		depts[deptChoice].addClassroom(newClass);
	}
}

int main() {
	
	char isRunning = 'y';
	do {
		vector<Department> depts = { Department("0", "English Department"), Department("1", "Mathematics Department"), Department("2", "Computer Science Department"),
									 Department("3", "Business Department"), Department("4", "Kinesiology Department"), Department("5", "Architecture Department"),
									 Department("6", "Biology Department"), Department("7", "Education Department"), Department("8", "Chemistry Department"),
								 	 Department("9", "Engineering Department") };
		printDeptMenu(depts);

		unsigned int deptChoice;
		while (true) {
			try {
				cin >> deptChoice;
				if (!cin.good()) {
					throw ("Please enter only numbers from 0-9");
				}
				if (deptChoice < 0 || deptChoice > 9) {
					throw ("Please enter only numbers from 0-9");
				}
				break;
			}
			catch (const char * msg) {
				cin.clear();
				cin.get();
				cout << msg << endl;
			}
		}

		cout << "You selected the " + depts[deptChoice].getName() << endl;

		system("CLS");

		menu_collect(depts, deptChoice);

		system("CLS");

		horizontal_graph(depts[deptChoice]);
		cout << "Press y to see vertical graph" << endl;
		char charTemp;
		cin >> charTemp;
		if (charTemp == 'y') {
			system("CLS");
			vertical_graph(depts[deptChoice]);
		}
		cout << "" << endl;
		cout << "Run the program again? <y/n>" << endl;
		cin >> isRunning;
		system("CLS");
	} while (isRunning == 'y');

	return 0;
}