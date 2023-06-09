#include <sstream>

#include "user_input.h"

class simplex : public user_data {
public:
	void init();
	void gen_plane();
	bool plane_is_valid();
	bool function_is_undefined();
	void print_result_to_file(int it_num);
private:
	double func;  //містить значення цільової функції
	double** bv;  //Містить значення базисних змінних задач
	double** sv;  //Матриця коефіцієнтів при змінних задачі розміром num_l* num_v*2
	double* istr; //індексний рядок є одномірним масивом розміром num_v * 2,
	//перша половина якого заповнюється коефіцієнтами цільової функції зі зворотним знаком, а друга нулями на першій ітерації
	double* th;   //останній стовпець симплексної таблиці, ініціалізується одновимірним масивом розміром num_l
	double alm;	  //роздільна здатність елемента, що знаходиться на перетині провідного стовпця і провідного рядка
	int i_lrow;   //індекс провідного рядка поточного плану
	int i_lcol;	  //індекс провідного стовпця поточного плану
	std::stringstream table; //об'єкт класу std::stringstream, який містить весь висновок користувача у вихідний файл
};
