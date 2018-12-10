#include<stdio.h>

int analisis(int* min, int* max, FILE *fin);
int analisis(int* min, int* max, FILE *fin)
{
    int x;
    while(fscanf(fin, "%d", &x) == 1)
    {
        if (x < *min)
        {
            *min = x;
        }

        if (x > *max)
        {
            *max = x;
        }
    }
    if (!feof(fin))
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

main(int argc, char* argv[])
{
    FILE *fin;
    int min = (unsigned int) -1 / 2, max = (unsigned int) -1 / 2 + 1;

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
    printf("min = %d, max = %d\n", min, max);
    if (analisis(&min, &max, fin))
    {
        printf("min = %d, max = %d", min, max);
    }
    else
    {
        printf("Error: Incorrect file!");
    }

}
