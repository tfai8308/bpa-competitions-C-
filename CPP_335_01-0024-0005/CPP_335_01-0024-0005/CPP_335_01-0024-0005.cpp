//01-0024-0005
// CPP_335_01-0024-0005.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

/**
* A method for converting lines of parsed text into vector elements for the sake of easier processing
*
* @param str the line of text to be processed
* @param delim a delimiter character
* @param out the vector to be outputted to
*/
void tokenize(std::string const &str, const char delim, std::vector<std::string> &out){
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos){
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}


class Player {
private:
	std::string name;
	int height;
	int weight;
	double gpa;

public:
	Player();
	Player(std::ifstream & file, std::string line);
	bool isCandidate();
	std::string getName();
};

Player::Player() {
	//default values that couldn't possibly make sense in reality for placeholding.
	this->name = "";
	this->height = -1;
	this->weight = -1;
	this->gpa = -1.0;
}

Player::Player(std::ifstream & file, std::string line) {
	const char delim = ' ';      
	std::vector<std::string> out;
	tokenize(line, delim, out);    //now it's possible to simply pluck elements from the vector
	
	this->name = out[1];
	
	std::stringstream h(out[2]);
	h >> this->height;
	
	std::stringstream w(out[3]);
	w >> this->weight;
	
	std::stringstream g(out[4]);
	g >> this->gpa;
}

/**
* Checks the candidate's GPA
*
* @return gpa, whether the gpa was higher than 2.2 or not
*/
bool Player::isCandidate() {
	return gpa >= 2.2;
}

/**
* Retrieves the player's name
*
* @return the player's name (minus the other pesky brace)
*/
std::string Player::getName() {
	return this->name;  
}


class VolleyballPlayer : public Player {
private:
	int aces;
	int kills;

public:
	VolleyballPlayer();
	VolleyballPlayer(std::ifstream & file, std::string line);
	bool isCandidate();
};

VolleyballPlayer::VolleyballPlayer() : Player() {
	this->aces = -1;
	this->kills = -1;
}

VolleyballPlayer::VolleyballPlayer(std::ifstream & file, std::string line) : Player(file, line){
	const char delim = ' ';
	std::vector<std::string> out;
	tokenize(line, delim, out);

	std::stringstream a(out[5]);
	a >> this->aces;

	std::stringstream k(out[6]);
	k >> this->kills;
}

/**
* A more specific candidate check for volleyballers, now checking ace and kill count.
*
* @return a more thorough check
*/
bool VolleyballPlayer::isCandidate() {
	return Player::isCandidate() && this->aces >= 5 && this->kills >= 8;
}


class HockeyPlayer : public Player {
private:
	int goals;
	int penaltyMinutes;
	int plusMinusScore;

public:
	HockeyPlayer();
	HockeyPlayer(std::ifstream & file, std::string line);
	bool isCandidate();
};

HockeyPlayer::HockeyPlayer() : Player() {
	this->goals = -1;
	this->penaltyMinutes = -1;
	this->plusMinusScore = -1;
}

HockeyPlayer::HockeyPlayer(std::ifstream & file, std::string line) : Player(file, line) {
	const char delim = ' ';
	std::vector<std::string> out;
	tokenize(line, delim, out);

	std::stringstream g(out[5]);
	g >> this->goals;

	std::stringstream pm(out[6]);
	pm >> this->penaltyMinutes;

	std::stringstream score(out[7]);
	score >> this->plusMinusScore;
}

/**
* A more specific candidate check for hockey players, now checking goals, penalty minutes, and plus/minus score.
*
* @return a more thorough check
*/
bool HockeyPlayer::isCandidate() {
	return Player::isCandidate() && this->goals >= 15 && this->penaltyMinutes < 12 && this->plusMinusScore > 18;
}


class FootballPlayer : public Player {
private:
	double dashTime;

public:
	FootballPlayer();
	FootballPlayer(std::ifstream & file, std::string line);
	bool isCandidate();
};

FootballPlayer::FootballPlayer() : Player() {
	this->dashTime = -1.0;
}

FootballPlayer::FootballPlayer(std::ifstream & file, std::string line) : Player(file, line) {
	const char delim = ' ';
	std::vector<std::string> out;
	tokenize(line, delim, out);

	std::stringstream d(out[5]);
	d >> this->dashTime;
}
/**
* A more specific candidate check for footballers, now checking dash time.
* Although the specs ask for a time at least 4.7 seconds, that doesn't make sense in the
* scope of choosing candidates (as faster times are preferred), although it will be implemented,
* the logic should be cautioned.
*
* @return a more thorough check
*/
bool FootballPlayer::isCandidate() {
	return Player::isCandidate() && this->dashTime >= 4.7;
}


int main()
{
	std::ifstream file("players.txt");
	if (file.is_open()) {
		std::string line;
		std::cout << "Here are all the eligible candidates: \n\n";
		while (getline(file, line)) {
			if (line.substr(0, 1).compare("F") == 0) {
				FootballPlayer footballer(file, line);
				if (footballer.isCandidate()) {
					std::cout << footballer.getName() << "\t: Football Candidate" << std::endl;
				}
			}
			else if (line.substr(0, 1).compare("H") == 0) {
				HockeyPlayer hockeyplayer(file, line);
				if (hockeyplayer.isCandidate()) {
					std::cout << hockeyplayer.getName() << "\t: Hockey Candidate" << std::endl;
				}
			}
			else if (line.substr(0, 1).compare("V") == 0) {
				VolleyballPlayer volleyballer(file, line);
				if (volleyballer.isCandidate()) {
					std::cout << volleyballer.getName() << "\t: Volleyball Candidate" << std::endl;
				}
			}
			else {
				std::cout << "An invalid player was loaded at this position." << std::endl;
			}
		}
	}
	else {
		std::cout << "The file could not be opened. Are you sure it was named \"players.txt\"?" << std::endl;
	}
	system("PAUSE");
	return 0;
}

