#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


template <class T>
class complex
{
    T v;
public:float c, m;
      float vc[3];
      float vm[3];
      float slv1[3];
      float slv2[3];
      float vuc1, vuc2;
      complex(float d, float e)
      {
          c = d;
          m = e;
      };
      complex()
      {}
      void vector(float ve1, float ve2, float ve3, float ve4, float ve5, float ve6);
      void slogvector(complex <float> x, complex <float>Y);
      void slog(complex<float> x, complex <float> Y);
      void vush(complex<float> x, complex <float> Y);
      void ymnog(complex<float> x, complex <float> Y);
      void delenie(complex<float> x, complex <float> Y);
};
