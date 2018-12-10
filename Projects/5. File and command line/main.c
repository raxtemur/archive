#include <stdio.h>

int analisis(FILE *fin);

int Inicialization(char arg[]);

int main(int argc, char* argv[])
{
    FILE *fin;
    int k = 1;
    if (argc < 2)
    {
        printf("Error: No start arguments!\n");
        return 0;
    }
    fin = fopen(argv[1], "r");
    if (!fin)
    {
        printf("Error: can't open file!\n");
        return -1;
    }

    k = analisis(fin);
    if (k == 1) printf("1\n");
    else if (k == 0) printf("0\n");
    return (0);
}

int analisis(FILE *fin)
{
    int i = 0;
    int st;//reading status
    int x1, x2, x3;//x3 = 2*x2 + x1
    char str[6];

    for (i = 0; i < 3; i++)
    {
        st = fscanf(fin, "%d", &x3);
        if (st == EOF)
        {
            printf("Error: Early End Of File!\n");
            return 0;
        }
        //printf("%d%s", x3,"\n");
        if (x3 != i)
        {
            //printf("%s%d","Element #",i);
            return 0;
        }
        x1 = x2;
        x2 = x3;
    }

    st = fscanf(fin, "%d", &x3);
    while(st != EOF)
    {
        i++;
        //printf("%d%s", x3,"\n");
        if (x3 != 2*x2 + x1)
        {
            //printf("%s%d%s","Element #", i, "\n");
            return 0;
        }
        x1 = x2;
        x2 = x3;
        st = fscanf(fin, "%d", &x3);
    }
    return 1;
}
