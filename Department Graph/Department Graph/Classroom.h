#pragma once
#include <string>
/*
	Each classroom object will store a size corresponding to the total number of students in the class.
*/
using namespace std;

class Classroom {
public:
	Classroom();
	Classroom(string roomID, unsigned short size);
	unsigned short getSize();
	void setSize(unsigned short size);
	string getRoomID();
	void setRoomID(string roomID);

private:
	unsigned short size;
	string roomID;
};