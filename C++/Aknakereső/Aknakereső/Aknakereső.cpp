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

	//Random aknák

	std::srand(std::time(0));

	for (int i = 0; i < 2; i++) {
		int randMineHeight, randMineWidth;
		randMineHeight = std::rand() % 5;
		randMineWidth = std::rand() % 5;
		while (gameBoard[randMineHeight][randMineWidth] == "[X]") {
			randMineHeight = std::rand() % 5;
			randMineWidth = std::rand() % 5;
		}
		gameBoard[randMineHeight][randMineWidth] = "[X]";
	}

	int mineCount = 0;

	//Számok elhelyezése

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (gameBoard[i][j] != "[X]") {
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

	if (gameBoard[rowNum][colNum] == "[0]") {
		showBoard[rowNum][colNum] = "[-]";
	}

	//Ha az "Első kattintás" egy akna

	else if (gameBoard[rowNum][colNum] == "[X]") {
		int randMineHeight, randMineWidth;
		randMineHeight = std::rand() % 5;
		randMineWidth = std::rand() % 5;
		while (gameBoard[randMineHeight][randMineWidth] == "[X]") {
			randMineHeight = std::rand() % 5;
			randMineWidth = std::rand() % 5;
		}
		gameBoard[randMineHeight][randMineWidth] = "[X]";
		gameBoard[rowNum][colNum] = "[E]";
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
	}
	else {
		showBoard[rowNum][colNum] = gameBoard[rowNum][colNum];
	}

	//gameBoard klónozása a screwBoard-ra

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			screwBoard[i][j] = gameBoard[i][j];
		}
	}

	//Az "Első kattintás" felvétele a screwBoard-ra

	screwBoard[rowNum][colNum] = "[-]";

	//Üres mezők felismerése az "Első kattintás"-tól nézve

	for (int k = 0; k < 9; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; ++j) {
				if (screwBoard[i][j] == "[0]") {
					if ((i - 1) > (-1)) {
						if (screwBoard[i - 1][j] == "[-]") {
							screwBoard[i][j] = "[-]";
							showBoard[i][j] = "[-]";
						}
					}
					if ((j - 1) > (-1)) {
						if (screwBoard[i][j - 1] == "[-]") {
							screwBoard[i][j] = "[-]";
							showBoard[i][j] = "[-]";
						}
					}
					if ((j + 1) < 5) {
						if (screwBoard[i][j + 1] == "[-]") {
							screwBoard[i][j] = "[-]";
							showBoard[i][j] = "[-]";
						}
					}
					if ((i + 1) < 5) {
						if (screwBoard[i + 1][j] == "[-]") {
							screwBoard[i][j] = "[-]";
							showBoard[i][j] = "[-]";
						}
					}
				}
			}
		}
	}

	//Üres mezők melletti számok felszabadítása

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; ++j) {
			if (screwBoard[i][j] != "[X]" && screwBoard[i][j] != "[-]" && screwBoard[i][j] != "[0]") {
				if ((i - 1) > (-1)) {
					if (screwBoard[i - 1][j] == "[-]") {
						showBoard[i][j] = gameBoard[i][j];
					}
				}
				if ((j - 1) > (-1)) {
					if (screwBoard[i][j - 1] == "[-]") {
						showBoard[i][j] = gameBoard[i][j];
					}
				}
				if ((j + 1) < 5) {
					if (screwBoard[i][j + 1] == "[-]") {
						showBoard[i][j] = gameBoard[i][j];
					}
				}
				if ((i + 1) < 5) {
					if (screwBoard[i + 1][j] == "[-]") {
						showBoard[i][j] = gameBoard[i][j];
					}
				}
			}
		}
	}

	if (gameBoard[rowNum][colNum] != "[X]") {
		showBoard[rowNum][colNum] = gameBoard[rowNum][colNum];
	}
	else if (gameBoard[rowNum][colNum] != "[0]") {
		showBoard[rowNum][colNum] = "[-]";
	}

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

	int gameLoop = 0;

	while (gameLoop == 0) {
		cout << "Choose a cell!" << endl;
		cout << "Row: ";
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

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (showBoard[i][j] == "[0]") {
					showBoard[i][j] = "[-]";
				}
			}
		}

		string flag = (showBoard[rowNum][colNum] == "[Y]") ? "1. Remove flag" : "1. Place flag";
		cout << flag << endl;
		cout << "2. Uncover cell" << endl;
		cout << "Choose action! (1 / 2): ";
		string action;
		cin >> action;
		cout << endl;
		while (action != "1" && action != "2") {
			cout << "Incorrect, Try Again!" << endl;
			cin >> action;
		}
		if (action == "1") {
			if (showBoard[rowNum][colNum] == "[Y]") {
				showBoard[rowNum][colNum] = "[O]";
			}
			else {
				showBoard[rowNum][colNum] = "[Y]";
			}

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
		}
		else if (action == "2") {
			if (gameBoard[rowNum][colNum] == "[X]") {
				cout << endl;
				for (int i = 0; i < 5; ++i) {
					for (int j = 0; j < 5; ++j) {
						cout << gameBoard[i][j] << " ";
					}
					cout << endl << endl;
				}

				cout << "Game Over!" << endl;
				cout << "Do you want to play again? (yes / no) ";
				string playAgain;
				cin >> playAgain;
				while (playAgain != "yes" && playAgain != "no") {
					cout << "invalid, Try again!" << endl;
					cout << "Do you want to play again? (yes / no) ";
					cin >> playAgain;
					cout << endl;
				}
				if (playAgain == "yes") {
					cout << endl;
					gameDifficulties();
				}
				else {
					cout << "Goodbye!";
					exit(0);
				}
			}
			else if (screwBoard[rowNum][colNum] == "[0]") {
				screwBoard[rowNum][colNum] = "[-]";
				showBoard[rowNum][colNum] = "[-]";

				for (int k = 0; k < 9; k++) {
					for (int i = 0; i < 5; i++) {
						for (int j = 0; j < 5; ++j) {
							if (screwBoard[i][j] == "[0]") {
								if ((i - 1) > (-1)) {
									if (screwBoard[i - 1][j] == "[-]") {
										screwBoard[i][j] = "[-]";
										showBoard[i][j] = "[-]";
									}
								}
								if ((j - 1) > (-1)) {
									if (screwBoard[i][j - 1] == "[-]") {
										screwBoard[i][j] = "[-]";
										showBoard[i][j] = "[-]";
									}
								}
								if ((j + 1) < 5) {
									if (screwBoard[i][j + 1] == "[-]") {
										screwBoard[i][j] = "[-]";
										showBoard[i][j] = "[-]";
									}
								}
								if ((i + 1) < 5) {
									if (screwBoard[i + 1][j] == "[-]") {
										screwBoard[i][j] = "[-]";
										showBoard[i][j] = "[-]";
									}
								}
							}
						}
					}
				}

				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; ++j) {
						if (screwBoard[i][j] != "[X]" && screwBoard[i][j] != "[-]" && screwBoard[i][j] != "[0]") {
							if ((i - 1) > (-1)) {
								if (screwBoard[i - 1][j] == "[-]") {
									showBoard[i][j] = gameBoard[i][j];
								}
							}
							if ((j - 1) > (-1)) {
								if (screwBoard[i][j - 1] == "[-]") {
									showBoard[i][j] = gameBoard[i][j];
								}
							}
							if ((j + 1) < 5) {
								if (screwBoard[i][j + 1] == "[-]") {
									showBoard[i][j] = gameBoard[i][j];
								}
							}
							if ((i + 1) < 5) {
								if (screwBoard[i + 1][j] == "[-]") {
									showBoard[i][j] = gameBoard[i][j];
								}
							}
						}
					}
				}


			}

			else {
				if (gameBoard[rowNum][colNum] != "[0]") {
					showBoard[rowNum][colNum] = gameBoard[rowNum][colNum];
				}
			}
		}
		else {
			showBoard[rowNum][colNum] = gameBoard[rowNum][colNum];
		}

		int winPoint = 0;

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (showBoard[i][j] == "[O]" || showBoard[i][j] == "[Y]") {
					if (gameBoard[i][j] == "[X]") {
						winPoint++;
					}
				}
			}
		}

		if (winPoint == 2) {
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					cout << gameBoard[i][j] << " ";
				}
				cout << endl << endl;
			}
			cout << "You Won!!!" << endl;
			cout << "Do you want to play again? (yes / no) ";
			string playAgain;
			cin >> playAgain;
			while (playAgain != "yes" && playAgain != "no") {
				cout << "invalid, Try again!" << endl;
				cout << "Do you want to play again? (yes / no) ";
				cin >> playAgain;
				cout << endl;
			}
			if (playAgain == "yes") {
				cout << endl;
				gameDifficulties();
			}
			else {
				cout << "Goodbye!";
				exit(0);
			}
		}

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
	}
}

void customLevel() {
	cout << "Please give me the width and height of the board, and the number of mines!" << endl;
	cout << "(max height: 30, max width: 20, max mines: (height * width))" << endl;
	int height, width, mines;
	cout << "Height: ";
	cin >> height;
	while (height > 30 || height < 0) {
		cout << ((height > 30) ? "The number for height is too big!\n" : "The number for height is too small!\n") << endl;
		cout << "Height: ";
		cin >> height;
	}
	cout << "Width: ";
	cin >> width;
	while (width > 20 || width < 0) {
		cout << ((width > 20) ? "The number for height is too big!\n" : "The number for height is too small!\n") << endl;
		cout << "Width: ";
		cin >> width;
	};
	cout << endl << "Max number of mines: " << height * width << endl;
	cout << "Recommended number of mines (25% of (height * width)):  " << height * width / 4 << endl;
	cout << "Number of mines: ";
	cin >> mines;
	while (mines > (height * width) || mines < 0) {
		cout << (mines > (height * width) ? "The number for mines is too big!\n" : "The number for mines is too small!\n") << endl;
		cout << "Mines: ";
		cin >> mines;
	}
	cout << endl;

	vector<vector<string>> gameBoard(height, vector<string>(width));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			gameBoard[i][j] = "[O]";
		}
	}

	std::srand(std::time(0));

	int accident = 0;

	for (int i = 0; i < mines; i++) {
		int randMineHeight, randMineWidth;
		randMineHeight = std::rand() % height;
		randMineWidth = std::rand() % width;
		while (gameBoard[randMineHeight][randMineWidth] == "[X]") {
			randMineHeight = std::rand() % height;
			randMineWidth = std::rand() % width;
			accident++;
		}
		gameBoard[randMineHeight][randMineWidth] = "[X]";
	}

	int mineNum = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (gameBoard[i][j] == "[X]") {
				mineNum++;
			}
		}
	}

	cout << endl << "Number of mines: " << mineNum << endl;
	cout << "Accidents: " << accident;
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
	else {
		customLevel();
	}
}