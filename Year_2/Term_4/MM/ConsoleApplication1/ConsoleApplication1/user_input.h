#ifndef _USER_DATA_H_
#define _USER_DATA_H_

class user_data {
public:
	void get_data_from_user();
	void user_data_is_valid();
protected:
	double* function;	// зберігає значення коефіцієнтів цільової функції задачі
	double* fm;			//зберігає у собі значення вільних членів системи обмежень
	double** system;	//зберігає значення коефіцієнтів самої системи обмежень
	int* sign;			//зберігає у собі знак кожного обмеження системи
	int num_v;			//зберігає в собі значення кількості змінних вихідного завдання
	int num_l;			//зберігає значення кількості обмежень вихідної задачі
	bool way;			//зберігає напрямок цільової функції завдання (min/max)
};

#endif
