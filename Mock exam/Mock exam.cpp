#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "Password.h"
#include "Tasks.h"

void menu();
int genrand(int);
void task1();
void task2();
void task3();
//void task4();


int main()
{
	std::srand(time(nullptr));
	//passcode();
	//if (attempts == 3) {
	//	return 0;
	//}
	//else if (rightpas == true) {
	system("CLS");
	menu();
	//}
}


int genrand(int choise) {
	switch (choise) {
	case 1:
		return rand() % 6 + 1;
		break;
	case 2:
		return rand() % 20 + 1;
		break;
	}
}

void menu() {
	int pchoise;
	std::cout << "1. Task 1\n";
	std::cout << "2. Task 2\n";
	std::cout << "3. Task 3 & 4\n";
	std::cout << "4. Quit program\n";
	std::cin >> pchoise;
	switch (pchoise) {
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		std::_Exit;
		break;
	};

}

void task1() {
	int diceroll = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;

	for (int i = 0; i <= 2000; i++) {
		diceroll = genrand(1);
		//std::cout << diceroll;
		switch (diceroll) {
		case 1:
			one++;
			break;
		case 2:
			two++;
			break;
		case 3:
			three++;
			break;
		case 4:
			four++;
			break;
		case 5:
			five++;
			break;
		case 6:
			six++;
			break;
		};
	}
	std::cout << "Number of oness: " << one << std::endl;
	std::cout << "Number of twos: " << one << std::endl;
	std::cout << "Number of threes: " << one << std::endl;
	std::cout << "Number of fours: " << one << std::endl;
	std::cout << "Number of fives: " << one << std::endl;
}

void task2() {
	int Vsize = 12;
	char letter = 'A';
	for (int i = 0; i <= Vsize; i++) {
		task2V.push_back(genrand(2));
	}

	std::cout << "No \t" << "Name \t" << "Value\t" << "Health Bar" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	for (int i = 0; i < task2V.size(); i++) {
		std::cout << i << "\t";
		std::cout << static_cast<char>(letter + i) << "\t";
		std::cout << task2V[i] << "\t";
		for (int j = 0; j < task2V[i]; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::sort(std::begin(task2V), std::end(task2V));

	std::cout << "Sorted: " << std::endl << std::endl;
	std::cout << "No \t" << "Name \t" << "Value\t" << "Health Bar" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	for (int i = 0; i < task2V.size(); i++) {
		std::cout << i << "\t";
		std::cout << static_cast<char>(letter + i) << "\t";
		std::cout << task2V[i] << "\t";
		for (int j = 0; j < task2V[i]; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void task3() {
	//std::cout << pacA[10][8];
	//std::cout << pacA[10][9];
	/*for (int j = 0; j < pacH; j++) {
		for (int i = 0; i < pacL; i++) {
			if (pacA[j][i] == 'E'); {
				std::cout << "Y = " << j << " X = " << i << std::endl;
			}
		}
	}*/
	do {
		system("CLS");
		print();
		move();
	} while (task3run == true);
}