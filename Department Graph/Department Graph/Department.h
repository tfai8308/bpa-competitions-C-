#pragma once
#include <vector>
#include "Classroom.h"
/*
	Each department object will store the corresponding classroom objects in a vector.
*/
using namespace std;

class Department {
public:
	Department();
	Department(string deptID, string name);
	string getName();
	void setName(string name);
	string getDeptID();
	void setDeptID(string deptID);
	vector<Classroom> & getClassrooms();
	void addClassroom(Classroom & classroom);
	const int getNumClassrooms();

private:
	vector<Classroom> classrooms;
	string name;
	string deptID;
	const int numClassrooms = 10;
};