// Программа вычисления интеграла
//
// Даны функции:
// 1. f1(x) = 0.6*x + 3
// 2. f2(x) = (x-2)**3 - 1
// 3. f3(x) = 3/x
//
// Для поиска корней приравниваем функции друг к другу:
//
// f1(x) = f2(x):
// 0.6*x + 3 = (x-2)**3 - 1
// 0.6*x + 3 = x**3 - 6*x**2 + 12*x - 8 - 1
// x**3 - 6*x**2 + 11.4*x - 12 = 0
//
// f1(x) = f3(x):
// 0.6*x + 3 = 3/x
// 0.6*x**2 + 3*x - 3 = 0
//
// f2(x) = f3(x):
// x**3 - 6*x**2 + 12*x - 9 = 3/x
// x**4 - 6*x**3 + 12*x**2 - 9*x - 3 = 0

#include <stdio.h>
#include <math.h>

typedef float(*function)(float);

float f1(float x);
float f2(float x);
float f3(float x);
float f1f2(float x);
float f1f3(float x);
float f2f3(float x);

float testf(float x);

float rootFindLineSearch(float xl, float xr, float eps, function f);
float calcIntegralSquare(float xl, float xr, size_t n, function f);