#include "Header.h"
void vector(float ve1, float ve2, float ve3, float ve4, float ve5, float ve6)
{
    vc[0] = ve1;
    vc[1] = ve2;
    vc[2] = ve3;
    vm[0] = ve4;
    vm[1] = ve5;
    vm[2] = ve6;
    cout << "Вектор: " << "(" << vc[0] << "+" << "(" << vm[0] << ")" << "i" << "," << vc[1] << "+" << "(" << vm[1] << ")" << "i" << "," << vc[2] << "+" << "(" << vm[2] << ")" << "i" << ")" << "\n";
}
void slogvector(complex <float> x, complex <float>Y)
{
    slv1[0] = x.vc[0] + Y.vc[0];
    slv1[1] = x.vc[1] + Y.vc[1];
    slv1[2] = x.vc[2] + Y.vc[2];
    slv2[0] = x.vm[0] + Y.vm[0];
    slv2[1] = x.vm[1] + Y.vm[1];
    slv2[2] = x.vm[2] + Y.vm[2];
    cout << "Полученный вектор: " << endl;
    cout << "Первый символ: " << "(" << slv1[0] << ")" << slv2[0] << ")" << "i" << "," << slv1[1] << "+" << slv2[1] << ")" << "i" << "," << slv1[2] << "+" << "(" << slv2[2] << ")" << "i" << ")" << "\n";
}
void slog(complex<float> x, complex <float> Y)
{
    vuc1 = x.c + Y.c;
    vuc2 = x.m + Y.m;
    cout << "Сложение равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
}
void vush(complex<float> x, complex <float> Y)
{

    vuc1 = x.c - Y.c;
    vuc2 = x.m - Y.m;
    cout << "Вычитание равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
}
void ymnog(complex<float> x, complex <float> Y)
{
    vuc1 = x.c * Y.c + x.m * Y.m;
    vuc2 = x.c * Y.m + x.m * Y.c;
    cout << "Умножение равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
}
void delenie(complex<float> x, complex <float> Y)
{
    vuc1 = (x.c * Y.c + x.m * Y.m) / (Y.c * Y.c * Y.m * Y.m);
    vuc2 = (x.m * Y.c - x.c * Y.m) / (Y.c * Y.c * Y.m * Y.m);
    cout << "Деление равно: " << vuc1 << "+" << "(" << vuc2 << ")" << "i" << "\n";
}
