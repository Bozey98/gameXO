#include <iostream>

using namespace std;

class Matrix {

private:
	int row, col, **mas, Counter=0;
	bool end;
public:
	Matrix(int length = 3);
	void show() const;
	void choiseX();
	void choiseO();
	void game();
	void checkXwin();
	void checkOwin();
};

Matrix::Matrix(int length) {
	Counter;
	end = false;
	row = length;
	col = length;
	int value = 1;
	mas = new int*[row];

	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
		for (int j = 0; j < col; j++) {
			mas[i][j] = value;
			value++;
		}
	}
	show();
}


void Matrix::choiseX() {
	int move;
	int  check = 0;
	cin >> move;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mas[i][j] == move) check++;
		}
	}

	if ((check == 1) && (move != 0) && (move != -1)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (move == mas[i][j])
				{
					mas[i][j] = 0;
				}

			}
		}
	}
	else
	{
		cout << "Wrong choise, try again" << endl;
		choiseX();
		Counter--;
	}
	Counter++;
}

void Matrix::choiseO() {
	int check = 0;
	int move;
	cin >> move;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mas[i][j] == move) check++;
		}
	}

	if ((check == 1) && (move != 0) && (move != -1)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (move == mas[i][j])
				{
					mas[i][j] = -1;
				}

			}
		}
	}
	else
	{
		cout << "Wrong choise, try again" << endl;
		choiseO();
		Counter--;
	}
	Counter++;
}

void Matrix::game() {
	
	while (end == false)
	{

		choiseX();
		show();
		checkXwin();
		if (end == true) break;
		if ((Counter == 9) && (end == false)) {
			cout << "Game over" << endl;
			break;
		}

		choiseO();
		show();
		checkOwin();
		if (end == true) break;
     	if ((Counter == 9) && (end == false)) {
			cout << "Game over" << endl;
			break;
		}

	}
}


void Matrix::checkXwin() {

	for (int i = 0; i < 3; ++i) {
		if ((mas[0][i] == mas[1][i]) && (mas[1][i] == mas[2][i]) && (mas[0][i] == 0)) {
			cout << "You are champion, X-player" << endl;
			end = true;
		}
		if ((mas[i][0] == mas[i][1]) && (mas[i][1] == mas[i][2]) && (mas[0][i] == 0)) {
			cout << "You are champion, X-player" << endl;
			end = true;
		}
	}

	if ((mas[0][0] == 0) && (mas[1][1] == 0) && (mas[2][2] == 0))
	{
		cout << "You are champion, X-player" << endl;
		end = true;
	}
	if ((mas[0][2] == 0) && (mas[1][1] == 0) && (mas[2][0] == 0))
	{
		cout << "You are champion, X-player" << endl;
		end = true;
	}
}

void Matrix::checkOwin() {
	for (int i = 0; i < 3; ++i) {
		if ((mas[0][i] == mas[1][i]) && (mas[1][i] == mas[2][i]) && (mas[0][i] == -1)) {
			cout << "You are champion, O-player" << endl;
			end = true;
		}
		if ((mas[i][0] == mas[i][1]) && (mas[i][1] == mas[i][2]) && (mas[0][i] == -1)) {
			cout << "You are champion, O-player" << endl;
			end = true;
		}
	}

	if ((mas[0][0] == -1) && (mas[1][1] == -1) && (mas[2][2] == -1))
	{
		cout << "You are champion, O-player" << endl;
		end = true;
	}
	if ((mas[0][2] == -1) && (mas[1][1] == -1) && (mas[2][0] == -1))
	{
		cout << "You are champion, O-player" << endl;
		end = true;
	}
}

void Matrix::show() const {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mas[i][j] == 0)
			{
				cout << "X" << " ";
			}
			else if (mas[i][j] == - 1)
			{
				cout << "O" << " ";
			}
			else
			{
				cout << mas[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}


int main() {

	Matrix test;
	test.game();

	system("pause");
	return 0;
}

