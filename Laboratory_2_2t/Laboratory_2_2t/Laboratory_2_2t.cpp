#include "Konst.h"
#define PRINT_TYPE
int main()
{
#ifdef PRINT_TYPE
	random_input();
#else
	user_input();
#endif // PRINT_TYPE

}
