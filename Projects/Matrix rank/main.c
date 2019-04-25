#include<stdio.h>
#include<math.h>
#include <stdlib.h>


#define EPS 1e-6

int scan_matrix(FILE *fp, int n, double *a)
{
    for (int i = 0; i < n*n; i++)
    {
        if (fscanf(fp, "%lf", &a[i]) != 1)
        {
            printf("Error: WRONG DATA");
            return -1;
        }
    }
    return 1;
}

double f(int i, int j)
{
    return rand();
    //return (sin(i) + cos(j))/exp(i*j);
}

int gen_matrix(int n, double *a)
{
    for (int i = 0; i < n*n; i++)
    {
        a[i] = f(i/n + 1, i%n + 1);
    }
    return 1;
}

int print_matrix(FILE *fp, int n, double *a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(fp, "%lf ", a[i*n+j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n\n");
    return 1;
}



//Gauss returns:
//-1 - if 0 on diag in non-zero string
//0 - if verhnetreug
//else - number of zero-strings
int gauss(int n, double *a)
{
    double k;
    int zero_str = 0;
    for (int hard_s = 0, hard_c = 0; hard_s < n; hard_s++, hard_c++)
    {
        while ((fabs(a[hard_s*n + hard_c]) < EPS) && (hard_s < n))
        {
            for (int col = hard_c; col < n; col++)
            {
                //printf("%.50lf\n", fabs(a[hard_s*n + col]));
                if (fabs(a[hard_s*n + col]) > EPS)
                {
                    printf("Error: 0 on diagonal in non-zero string");
                    return -1;
                }
            }
            zero_str += 1;
            hard_s++;
        }
        for(int soft = hard_s + 1; soft < n; soft++)
        {
            k = a[soft*n + hard_c]/a[hard_s*n + hard_c];
            for (int col = hard_c; col < n; col++)
            {
                a[soft*n + col] = a[soft*n + col] - k*a[hard_s*n + col];
            }
        }
    }
    return zero_str;
}

double det(int n, double *a)
{
    double determinant = 1;
    for(int i = 0; i < n; i++)
    {
        determinant *= a[i*n + i];
    }
    return determinant;
}

//flags in program arguments
//1 - file input "1 filename.txt"
//2 - matrix gen "2 size"
int main(int argc, char *argv[])
{
    int n, rank, gauss_result;
    FILE *fin, *fout;
    double *a;

    srand(time(NULL));

    fout = fopen("output.txt", "w");
    if(!fout)
    {
        printf ("Error: cannot open output file!\n");
        return(-1);
    }

    if (argc != 3)
    {
        if (argc == 1)
        {
            printf("Error: no arguments!\n");
            return -1;
        }
        if (argc < 3)
        {
            printf("Error: not enough arguments!\n");
            return -1;
        }
        if (argc > 3)
        {
            printf("Error: too much arguments!\n");
            return -1;
        }
    }


    if(atoi(argv[1]) == 1)
    {

        fin = fopen (argv[2], "r");
        if(!fin)
        {
            printf ("Error: cannot open input file!\n");
            return(-1);
        }
        fscanf(fin, "%d", &n);
        a = (double*)malloc(n*n*sizeof(double));
        scan_matrix(fin, n, a);
    }
    else if(atoi(argv[1]) == 2)
    {
        n = atoi(argv[2]);
        if ((n <= 0))
        {
            printf("Error: not correct 2nd argument");
            return -1;
        }
        a = (double*)malloc(n*n*sizeof(double));
        gen_matrix(n, a);
    }
    else
    {
        printf("ERROR: NCFA!");
        return -1;
    }

    rank = n;

    print_matrix(fout, n, a);

    gauss_result = gauss(n, a);//returns the number of zero strings or -1

    print_matrix(fout, n, a);
    switch(gauss_result)
    {
    case -1:
        fprintf(fout, "Excepted 0 on diagonal in non-zero string\n");
        return 0;
        break;
    case 0:
        fprintf(fout, "Determinant = %lf\n", det(n, a));
        fprintf(fout, "Matrix rank is %d\n", n);
        break;
    default:
        fprintf(fout, "Determinant = 0\n");
        fprintf(fout, "Matrix rank is %d\n", (n - gauss_result));
        break;
    }

    fclose(fout);
    return 0;
}
