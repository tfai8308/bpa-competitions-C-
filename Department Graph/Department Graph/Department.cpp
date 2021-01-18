#include "Department.h"

using namespace std;

Department::Department() {
	this->deptID = "-99";
	this->name = "DEFAULT_NAME";
}

Department::Department(string deptID, string name) {
	this->deptID = deptID;
	this->name = name;
}

string Department::getDeptID() {
	return this->deptID;
}

void Department::setDeptID(string deptID) {
	this->deptID = deptID;
}

string Department::getName() {
	return this->name;
}

void Department::setName(string name) {
	this->name = name;
}

vector<Classroom> & Department::getClassrooms() {
	return this->classrooms;
}

void Department::addClassroom(Classroom & classroom) {
	this->classrooms.push_back(classroom);
}

const int Department::getNumClassrooms() {
	return this->numClassrooms;
}