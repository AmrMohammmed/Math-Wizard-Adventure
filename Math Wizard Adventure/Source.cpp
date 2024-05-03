#include <iostream>
#include <cstdlib> 
#include <time.h>
#include<limits>
#include<string>

using namespace std;

void print_tabs(int n) {
	for (int i = 0; i < n; i++) {
		cout << "\t";
	}
}
float do_operation(float arr[], int length, int operation)
{
	float result = 0;

	switch (operation)
	{

	case 1:
		for (int i = 0; i < length; i++)
		{
			if (i == length - 1)
				cout << arr[i];
			else
				cout << arr[i] << " + ";

			result += arr[i];
		}
		break;

	case 2:
		result = arr[0];
		cout << arr[0] << " - ";

		for (int i = 1; i < length; i++)
		{
			if (i == length - 1)
				cout << arr[i];
			else
				cout << arr[i] << " - ";
			result -= arr[i];
		}
		break;

	case 3:
		result = 1;
		for (int i = 0; i < length; i++)
		{
			if (i == length - 1)
				cout << arr[i];
			else
				cout << arr[i] << " * ";
			result *= arr[i];
		}
		break;
	default:
		cout << "Invalid Operation Game Ended!" << endl;
		exit(1);
	}

	cout << " = ";
	return result;


}




bool run_game(int operation, bool flag, int &life_points, int num_max, int stage)
{
	float num[10];
	float player_answer;
	float right_answer;
	bool bad_cin;

	for (int i = 0; i < stage; i++)
		num[i] = rand() % num_max + 1;

	if (flag == true)
		operation = rand() % 3 + 1;

	right_answer = do_operation(num, stage, operation);
	cin >> player_answer;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		life_points--;
		cout << "\t\t Wrong!    ";
		cout << "\t" << "Answer = " << right_answer;
		cout << "\t" << "Try Next!" << endl;
		print_tabs(10);
		cout << "Life Points : " << life_points << endl;

		return false;
	}
	if (player_answer == right_answer)
	{
		cout << "\t\t Well done!" << endl;
		return true;
	}
	else {
		life_points--;
		cout << "\t\t Wrong!    ";
		cout << "\t" << "Answer = " << right_answer;
		cout << "\t" << "Try Next!" << endl;
		print_tabs(10);
		cout << "Life Points : " << life_points << endl;

		return false;

	}

}

void drawbox(char c, int n) {
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << c;
	cout << endl;
}


int main()
{
	string player_name;
	srand(time(0));
	int operation = 1;
	bool flag = false;
	int life_points = 3;
	int player_score = 0;
	int num_max = 10;
	int questions_counter = 0;
	int stage = 2;
	int Qpoints = 1;
	cout << "Enter Your Name : ";
	cin >> player_name;
	cout << endl << "*** Welcome " << player_name << " to Our Math Adventure ***" << endl << endl;
	cout << "Choose Operation Number to Start the Game :\n\n1-Addition\n\n2-Subtraction\n\n3-Multilplication\n\n4-Mixed Mode\n\n";
	cout << "Your Number : ";
	cin >> operation;

	print_tabs(10);
	cout << "Life Points : " << life_points << endl;

	cout << endl;

	if (operation == 4)
		flag = true;
	while (life_points)
	{
		questions_counter++;

		bool scored = false;

		scored = run_game(operation, flag, life_points, num_max, stage);
		if (scored)
			player_score += Qpoints;

		if (questions_counter % 10 == 0) {
			life_points++;
			print_tabs(10);
			cout << "Life Points : " << life_points << endl;

		}
		if (questions_counter % 5 == 0) {
			num_max *= 2;
			stage++;
			Qpoints++;
		}
		if (num_max > 50 || stage > 5)
		{
			num_max = 50;
			stage = 5;

		}
	}

	drawbox('*', 120);
	cout << endl;
	print_tabs(6);

	cout << "Game Over!" << endl;

	cout << endl;
	print_tabs(6);
	cout << player_name << "'s Score : " << player_score << endl << endl;

	drawbox('*', 120);


	return 0;
}