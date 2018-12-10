#include <stdio.h>

int analisis(FILE *fin);

int Inicialization(char arg[]);

int main(void)
{
    FILE *fin;
    char fname[120];
    scanf("%s", fname);
    fin = fopen(fname, "r");
    if (!fin)
    {
        printf("Error: can't open file\n");
        return -1;
    }

    int k = 1;
    /*int input[argc - 2];

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            input[i - 1] = Inicialization(argv[i]);
            if (input[i-1] == -1) return 0;

            //дебаг вывод, что мы друг друга поняли
            printf("%d", input[i - 1]);
            printf("\n");

        }
    }
    else
    {
        printf("Error: No arguments!");
    }*/

    k = analisis(fin);
    if (k == 1) printf("1\n");
    else if (k == 0) printf("0\n");
    return (0);
}

int Inicialization(char arg[])//строки в числа
{
    int st;
    int result = 0;
    st = sscanf(arg, "%d", &result);
    if (st == 0) printf("Error: not correct input!\n");
    return(result);
}


int analisis(FILE *fin)
{
    int result = 1, st;//status
    int x1, x2, x3;//x3 = x2 + 2*x1
    char str[6];

    for (int i = 0; i < 3; i++)
    {
        st = fscanf(fin, "%d", &x3);
        printf(x3); printf("\n");
        if (st = 'EOF') printf("End Of File\n");
    }



    /*if(argc < 2) {printf("Error: not enough arguments!"); return -1;}

    for (int i = 0; i < ((3 < argc) ? 3 : argc); i++)//обработка первых трех элементов
    {
        if (input[i] != i) return(0);
    }

    for(int i = 3; i < argc; i++)//обработка последующих элементов
    {
        if (input[i] != 2 * input[i - 1] + input[i - 2]) { result = 0; break; }
        else result = 1;
    }*/
    return(result);
}
