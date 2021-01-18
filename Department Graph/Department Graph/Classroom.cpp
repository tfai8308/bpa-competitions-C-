#include "Classroom.h"

Classroom::Classroom() {
	this->roomID = "DEFAULT_ROOMID";
	this->size = 0;
}

Classroom::Classroom(string roomID, unsigned short size) {
	this->roomID = roomID;
	this->size = size;
}

unsigned short Classroom::getSize() {
	return this->size;
}

void Classroom::setSize(unsigned short size) {
	this->size = size;
}

string Classroom::getRoomID() {
	return this->roomID;
}

void Classroom::setRoomID(string roomID) {
	this->roomID = roomID;
}