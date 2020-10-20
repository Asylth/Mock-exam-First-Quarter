#pragma once
#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>


bool passcode();
void printpass();
void lockmove();
bool passcheck();


const int password = 14523;
const int lockh = 3;
const int lockl = 3;
char lockArray[lockh][lockl] = {
	{'*', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
};
int lockvalArray[lockh][lockl] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
};
int passent = 1;
int lockmoves = 0;
int attempts = 0;
int lockposx = 0;
int lockposy = 0;
bool rightpas = false;



bool passcode() {
	//do {
	while (lockmoves < 4) {
		printpass();
		//char input = _getch();
		//std::cout << "input: " << input << std::endl;
		lockmove();
		lockmoves++;
		passcheck();
		if (rightpas == true) {
			return true;
		}
		std::cout << "lockmoves: " << lockmoves << std::endl;
	};
}

void printpass() {
	std::cout << "--------------" << std::endl;
	for (int j = 0; j < lockh; j++) {
		for (int i = 0; i < lockl; i++) {
			std::cout << " | ";
			std::cout << lockArray[j][i];
			if (i == 2) {
				std::cout << " | " << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

bool passcheck() {
	passent = passent * 10;
	passent = passent + lockvalArray[lockposy][lockposx];
	std::cout << passent << std::endl;
	if (passent == password) {
		rightpas = true;
		return true;
	}
	return false;
}

void lockmove() {
	char ch;
	lockArray[lockposy][lockposx] = lockArray[lockposy][lockposx + 1] - 1;
	ch = _getch();
	switch (_getch()) {
	case 'w': case 'W': case 'H': //up
		if (lockposy != 0) {
			lockposy = lockposy - 1;
		}
		break;
	case 's': case 'S': case 'P': //down
		if (lockposy != 2) {
			lockposy = lockposy + 1;
		}
		break;
	case 'a': case 'A': case 'K': // left
		if (lockposx != 0) {
			lockposx = lockposx - 1;
		}
		break;
	case 'd': case 'D': case 'M': //right
		if (lockposx != 2) {
			lockposx = lockposx + 1;
		}
		break;
		/*default:
			std::cout << "Invalid input. Use WASD please!" << std::endl;
			break;*/
	}
	lockArray[lockposy][lockposx] = '*';
}