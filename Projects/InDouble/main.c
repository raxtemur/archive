#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int _mantiss = 0,
        _pow     = 0,
        buf     = 0,
        pow_sign = 0,
        mantiss_sign = 0,
        status  = 0;//0 - m, 1 - prepow, 2 - pow
    double N;
    char ch;
    FILE *fp;
    if (argc == 1)
    {
        printf("Error: no input filename in arguments!\n");
        return -1;
    }
    fp = fopen (argv[1], "r");
    if(!fp)
    {
        printf ("Error: cannot open file!\n");
        return(-1);
    }
    ch = getc(fp);
    do
    {
        switch(ch)
        {
        case ',':
            ch = '.';
        case '.':
            if(status == 0)
                status = 1;
            else
            {
                printf("Error: incorrect input(extra point found)!");
                return -1;
            }
            break;
        case 'e':
            if (status < 2)
                status = 2;
            else
            {
                printf("Error: incorrect input(extra \"e\" symbol found)!");
                return -1;
            }
            break;
        case '-':
            if (status == 0 && _mantiss == 0 && mantiss_sign == 0)
            {
                mantiss_sign = -1;
            }
            else if (status == 2 && _pow == 0 && pow_sign == 0)
            {
                pow_sign = -1;
            }
            else
            {
                printf("Error: incorrect input(extra sign symbol found)!");
            }
            break;
        case '+':
            if (status == 0 && _mantiss == 0 && mantiss_sign == 0)
            {
                mantiss_sign = 1;
            }
            else if (status == 2 && _pow == 0 && pow_sign == 0)
            {
                pow_sign = 1;
            }
            else
            {
                printf("Error: incorrect input(extra sign symbol found)!\n");
            }
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            if (status == 0)
            {
                _mantiss = _mantiss*10 + (int)ch - (int)'0';
            }
            if (status == 1)
            {
                buf -= 1;
                _mantiss = _mantiss*10 + (int)ch - (int)'0';
            }
            if (status == 2)
            {
                _pow = _pow*10 + (int)ch - (int)'0';
            }
            break;
        default:
            printf("Error: incorrect input(unexpected symbols)!\n");

        }
        ch = getc(fp);
    }
    while (ch != EOF);
    if (mantiss_sign != 0)  _mantiss = _mantiss * mantiss_sign;
    if (pow_sign != 0)      _pow = _pow*pow_sign;
    _pow += buf;
    printf("Mantis: %d, pow: %d\n", _mantiss, _pow);
    N = _mantiss * pow(10.0, _pow*1.0);
    printf("%lf", N);
    return(0);
}
