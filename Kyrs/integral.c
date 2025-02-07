#include "integral.h"

float rootFindLineSearch(float xl, float xr, float eps, function f)
{
    float x, minx = xl, nextstep;
    nextstep = fabs(xr-xl)/(1/eps);

    int stepcount = 0;
    for(x = xl; x < xr; x += nextstep, stepcount++) {
        if (fabs(f(x)) < fabs(f(minx))) {
            minx = x;
        }
    }

    return minx;
}

float calcIntegralSquare(float xl, float xr, size_t n, function f)
{
    float sum = 0;
    float h = (xr-xl)/n;
    for (size_t i = 0; i < n; i++) {
        sum += f(xl);
        xl += h;
    }

    return sum*h;
}

float f1(float x)
{
    return (float)0.6*x + (float)3.0;
}

float f2(float x)
{
    return (x-(float)2.0)*(x-(float)2.0)*(x-(float)2.0) - (float)1.0;
}

float f3(float x)
{
    return (float)3.0/x;
}

float f1f2(float x)
{
    return x*x*x - (float)6.0*x*x + (float)11.4*x - (float)12.0;
}

float f1f3(float x)
{
    return (float)0.6*x*x + (float)3.0*x - (float)3.0;
}

float f2f3(float x)
{
    return x*x*x*x - (float)6.0*x*x*x + (float)12.0*x*x - (float)9.0*x - (float)3.0;
}

float testf(float x)
{
    return (float)2.0;
}
