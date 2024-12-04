#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void childLevel();

void gameDifficulties() {
	cout << "==============================" << endl;
	cout << "- child: 5x5 board, 2 mines" << endl;
	cout << "- easy: 9x9 board, 10 mines" << endl;
	cout << "- medium: 16x16 board, 40 mines" << endl;
	cout << "- hard: 30x16 board, 99 mines" << endl;
	cout << "==============================" << endl << endl;
	cout << "What difficulty do you want to play on ?: ";
	string difficulty;
	cin >> difficulty;
	while (difficulty != "child" && difficulty != "easy" && difficulty != "medium" && difficulty != "hard") {
		cout << endl << "Invalid, Try again!" << endl;
		cin >> difficulty;
	}
	cout << endl;

	if (difficulty == "child") {
		childLevel();
	}
}

void childLevel() {
	//Array-ek létrehozása

	vector<vector<string>> gameBoard(5, vector<string>(5));
	vector<vector<string>> showBoard(5, vector<string>(5));
	vector<vector<string>> winBoard(5, vector<string>(5));

	//Array-ek feltöltése

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gameBoard[i][j] = "[O]";
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			showBoard[i][j] = "[O]";
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			winBoard[i][j] = "[O]";
		}
	}

	//Az "Első kattintás"

	cout << "Which cell do you want to reveal first?" << endl;
	cout << "Row: ";
	int rowNum, colNum;
	cin >> rowNum;
	while (rowNum < 0 && rowNum > 5) {
		cout << endl << "Invalid, Try again!" << endl;
		cin >> rowNum;
	}
	cout << "Column: ";
	cin >> colNum;
	while (colNum < 0 && colNum > 5) {
		cout << endl << "Invalid, Try again!" << endl;
		cin >> colNum;
	}
	cout << endl;

	rowNum -= 1;
	colNum -= 1;

	gameBoard[rowNum][colNum] = "[-]";
	winBoard[rowNum][colNum] = "[-]";

	//Random aknák

	std::srand(std::time(0));

	for (int i = 0; i < 2; i++) {
		int randMineHeight, randMineWidth;
		randMineHeight = std::rand() % 5;
		randMineWidth = std::rand() % 5;
		while (gameBoard[randMineHeight][randMineWidth] == "[X]" || gameBoard[randMineHeight][randMineWidth] == "[-]") {
			randMineHeight = std::rand() % 5;
			randMineWidth = std::rand() % 5;
		}
		gameBoard[randMineHeight][randMineWidth] = "[X]";
	}

	int mineCount = 0;

	//Számok elhelyezése

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (gameBoard[i][j] != "[X]" && gameBoard[i][j] != "[-]") {
				if (i == 0) {
					if (j == 0) {
						if (gameBoard[i][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j + 1] == "[X]") {
							mineCount++;
						}
					}
					else if (j == 4) {
						if (gameBoard[i][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j] == "[X]") {
							mineCount++;
						}
					}
					else {
						if (gameBoard[i][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j + 1] == "[X]") {
							mineCount++;
						}
					}
				}
				else if (i == 4) {
					if (j == 0) {
						if (gameBoard[i - 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j + 1] == "[X]") {
							mineCount++;
						}
					}
					else if (j == 4) {
						if (gameBoard[i - 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j - 1] == "[X]") {
							mineCount++;
						}
					}
					else {
						if (gameBoard[i - 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j + 1] == "[X]") {
							mineCount++;
						}
					}
				}
				else {
					if (j == 0) {
						if (gameBoard[i + 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j + 1] == "[X]") {
							mineCount++;
						}
					}
					else if (j == 4) {
						if (gameBoard[i - 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j] == "[X]") {
							mineCount++;
						}
					}
					else {
						if (gameBoard[i - 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i - 1][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i][j + 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j - 1] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j] == "[X]") {
							mineCount++;
						}
						if (gameBoard[i + 1][j + 1] == "[X]") {
							mineCount++;
						}
					}
				}
				gameBoard[i][j] = "[" + to_string(mineCount) + "]";
				mineCount = 0;
			}
		}
	}

	//Array-ek kiiratása

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << gameBoard[i][j] << " ";
		}
		cout << endl << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << showBoard[i][j] << " ";
		}
		cout << endl << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << winBoard[i][j] << " ";
		}
		cout << endl << endl;
	}
}

int main() {
	cout << "Welcome to MineSweeper!" << endl;
	cout << "Here\'s a little help understanding the cell's state:" << endl << endl;
	cout << "==========================" << endl;
	cout << "Undiscovered cell: [O]" << endl;
	cout << "Discovered cell: [-]" << endl;
	cout << "Mine: [X]" << endl;
	cout << "Flag: [Y]" << endl;
	cout << "Numbers: [1], [2]..." << endl;
	cout << "==========================" << endl << endl;
	cout << "Do you want to play pre-made difficulties, or on a custom board? (pre / cust): ";
	string gameType;
	cin >> gameType;
	while (gameType != "pre" && gameType != "cust") {
		cout << endl << "Invalid, Try again!" << endl;
		cin >> gameType;
	}
	cout << endl;
	if (gameType == "pre") {
		gameDifficulties();
	}
	/*else {
		customLevel();
	}*/
}