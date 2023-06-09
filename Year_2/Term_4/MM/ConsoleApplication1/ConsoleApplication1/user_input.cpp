#include <iostream>
#include <string>
#include <cstdlib>

#include "user_input.h"

using namespace std;

void error(int err_no)  //перевірка на некоректне введення користувача
{
	switch (err_no) {
	case 0:
		cout << "\n\tInput error\n" << endl;
		break;
	case 1:
		cout << "\n\tYou can't set fewer than two restrictions\n" << endl;
		break;
	case 2:
		cout << "\n\tThe program does not support the system for more than 500 restrictions\n" << endl;
		break;
	case 3:
		cout << "\n\tFewer than two variables cannot be specified\n" << endl;
		break;
	case 4:
		cout << "\n\tIt is not possible to specify more than 100 variables\n" << endl;
		break;
	}
}

void user_data::get_data_from_user()		//запит даних від користувача
{
	string num_limits, num_vars, s_var, fr_m, sn, func, w;
	int i, j;
	bool validator = false;


	do {
		cout << "\t\tHow many restrictions are there in the system? ";
		getline(cin, num_limits);
		if (atoi(num_limits.c_str()) < 2)
			error(1);
		else if (atoi(num_limits.c_str()) > 500)
			error(2);
		else
			validator = true;

	} while (!validator);

	num_l = atoi(num_limits.c_str());
	validator = false;

	do {
		cout << "\t\tNumber of variables: ";
		getline(cin, num_vars);
		if (atoi(num_vars.c_str()) < 2)
			error(3);
		else if (atoi(num_vars.c_str()) > 500)
			error(4);
		else
			validator = true;
	} while (!validator);

	num_v = atoi(num_vars.c_str());
	validator = false;

	function = new double[num_v];
	system = new double* [num_l];
	for (i = 0; i < num_l; i++)
		system[i] = new double[num_v];
	fm = new double[num_l];
	sign = new int[num_l];

	cout << "\n\t\tFill in the coefficients of the objective function.\n" << endl;

	for (i = 0; i < num_v; i++) {
		do {
			cout << "\tEnter the coefficient of the objective function at x" << i + 1 << ": ";
			getline(cin, func);
			if (atof(func.c_str()) == 0)
				error(0);
			else {
				validator = true;
				function[i] = atof(func.c_str());
			}
		} while (!validator);
		validator = false;
	}

	do {
		cout << "\tObjective function type ( min, max ): ";
		getline(cin, w);
		if (w == "max" || w == "MAX" || w == "min" || w == "MIN") {
			validator = true;
			if (w == "max" || w == "MAX")
				way = true;
			else
				way = false;
		}
		else
			error(0);

	} while (!validator);
	cout << "\n\t\tSystem of restrictions:\n" << endl;

	for (i = 0; i < num_l; i++) {
		cout << "Enter " << i + 1 << " limit.\n" << endl;
		for (j = 0; j < num_v; j++) {
			do {
				cout << "Enter the coefficient at x" << j + 1 << ": ";
				getline(cin, s_var);
				if (atof(s_var.c_str()) == 0)
					error(0);
				else {
					validator = true;
				}
			} while (!validator);
			system[i][j] = atof(s_var.c_str());
			validator = false;
		}

		do {
			cout << "\t\tType the sign in " << i + 1 << " constraint ( <=, =, >= ) : ";
			getline(cin, sn);
			if (sn == "<=" || sn == "=" || sn == ">=") {
				validator = true;
				if (sn == "<=")
					sign[i] = 0;
				if (sn == "=")
					sign[i] = 1;
				if (sn == ">=")
					sign[i] = 2;
			}
			else
				error(0);
			cout << sign[i] << endl;
		} while (!validator);

		validator = false;

		do {
			cout << "\tFree member in " << i + 1 << " constraint: ";
			getline(cin, fr_m);
			if (atof(fr_m.c_str()) == 0)
				error(0);
			else
				validator = true;
		} while (!validator);

		fm[i] = atof(fr_m.c_str());
		validator = false;

		cout << endl;
	}

}
