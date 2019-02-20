#include <stdio.h>
#include <math.h>

#define eps 0.000001

typedef double(*function)(double x); // задание типа function

double fx(double x)
{
    return x*x-17;
} // вычисл€ема€ функци€
double dfx(double x)
{
    return 2*x;
} // производна€ функции

double solveBisection(function fx, double x0, double x1)
{
    double x2 = x1 + 2*eps;
    while(fabs(x1-x0)>eps)
    {
        x2 = x1/2 + x0/2;
        if (fx(x2)*fx(x0) > 0) x0 = x2;
        if (fx(x2)*fx(x1) > 0) x1 = x2;
    }
    return x1;
}

double solveChord(function fx, double x0, double x1)
{
    double x2 = x1;
    do
    {
        x1 = x2;
        x2 = x1 - (x0 - x1) * fx(x1) / (fx(x0) - fx(x1));
    } // x0, x1 Ч (2*i - 1)-й и 2*i-й члены
    while(fabs(x1 - x2) > eps);
    return x1;
}

double solveSecant(function fx, double x0, double x1)
{
    while(fabs(x1 - x0) > eps)
    {
        x0 = x0 - (x1 - x0) * fx(x0) / (fx(x1) - fx(x0));
        x1 = x1 - (x0 - x1) * fx(x1) / (fx(x0) - fx(x1));
    } // x0, x1 Ч (2*i - 1)-й и 2*i-й члены

    return x1;
}

double solveNewton(function fx, function dfx, double x0)
{
    double x1  = x0 - fx(x0)/dfx(x0); // первое приблжение
    while (fabs(x1-x0)>eps)
    {
        x0 = x1;
        x1 = x1 - fx(x1)/dfx(x1); // последующие приближени€
    }
    return x1;
}

int main ()
{
    printf("%f\n",solveBisection(fx, 4, 5));
    printf("%f\n",solveSecant(fx, 4, 5));
    printf("%f\n",solveNewton(fx, dfx, 4));
    printf("%f\n",solveChord(fx, 4, 5));


    return 0;
}
