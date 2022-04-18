#include <iostream>
using namespace std;
int main()
{
    int x = 33;
    int y = 44;
    int* p1, * p2;
    p1 = &x;
    p2 = &y;
    *p1 = x + 2;
    *p2 = y - 2;
    p2 = p1;
    x = y;
    *p1 = x + 5;
    p1 = &y;
    *p2 = x - 10;
    *p1 = y + 10;
    cout << " *p1 " << *p1<< endl;
    cout << " *p2 " << *p2 << endl;
    cout << " x " << x << endl;
    cout << " y " << y << endl;
}
