#include <stdio.h>

int m = 8, n = 256;

void DUP(int* a, int* b, int n)
{
    for(int i = 0; i < n; i++) b[i] = a[i];
}

int main()
{
    FILE *fout;
    fout = fopen("output.txt", "w");

    int *P2, *P2_c, *P2_d;
    P2 = (int*)malloc(n*sizeof(int));
    P2_c = (int*)malloc(n*sizeof(int));
    P2_d = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) P2[i] = 0;

    int *x, *y, *z;
    x = (int*)malloc(n*sizeof(int));
    y = (int*)malloc(n*sizeof(int));
    z = (int*)malloc(n*sizeof(int));

    x[0] = 0; y[0] = 0; z[0] = 0;
    x[1] = 0; y[1] = 0; z[1] = 1;
    x[2] = 0; y[2] = 1; z[2] = 0;
    x[3] = 0; y[3] = 1; z[3] = 1;
    x[4] = 1; y[4] = 0; z[4] = 0;
    x[5] = 1; y[5] = 0; z[5] = 1;
    x[6] = 1; y[6] = 1; z[6] = 0;
    x[7] = 1; y[7] = 1; z[7] = 1;

    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < m; i++)
    {
        a = a << 1;
        b = b << 1;
        c = c << 1;
        a += x[i];
        b += y[i];
        c += z[i];
    }
    P2[a] = 1;
    P2[b] = 1;
    P2[c] = 1;
    printf("%d, %d, %d \n", a, b, c);
    for (int circle = 0; circle < 10; circle++)
    {
        for (int i = 0; (i < n); i++) if ((P2[i] == 1))
            for(int j = i; (j < n); j++) if (P2[j] == 1)
                {
                        P2[i|j] = 1;
                        P2[i&j] = 1;
                }
    }

    int s = 0, sum = 0;
    s = 0; for (int i = 0; i < n; i++) s += P2[i];
    for(c = 0; c < n; c++) if((P2[c] == 1) && (c != a) && (c != b))
        {
            printf("%d is doing\n", c);
            DUP(P2, P2_c, n);
            P2_c[255 - c] = 1;

            for (int circle = 0; circle < 3; circle++)
                {
                for (int i = 0; (i < n); i++) if ((P2_c[i] == 1)) for(int j = i; (j < n); j++) if (P2_c[j] == 1)
                    {
                        if (circle%2)
                            P2_c[i|j] = 1;
                        else
                            P2_c[i&j] = 1;
                    }
                }
            for(d = 0; d < n; d++) if ((P2_c[d] == 1)&& (d != a) && (d != b) && (d != c))
            {
                DUP(P2_c, P2_d, n);
                P2_d[255 - d] = 1;
                for (int circle = 0; circle < 2; circle++)
                {
                    for (int i = 0; (i < n); i++) if (P2_d[i] == 1) for(int j = i; (j < n); j++) if (P2_d[j] == 1)
                            {
                                if (circle%2)
                                    P2_d[i|j] = 1;
                                else
                                    P2_d[i&j] = 1;
                            }
                }
                sum = 0; for (int i = 0; i < n; i++) sum += P2_d[i];
                fprintf(fout, "\nc = %d, d = %d, sum = %d", c, d, sum);
                if ((P2_d[240] == 1) && (P2_d[204] == 1) && (P2_d[170] == 1)) fprintf(fout, " Done! %d, %d", 255 - c, 255 - d);
            }
        }

    int **G;
    G = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        G[i] = (int*)malloc(4*sizeof(int));
        G[i][0] = 0; G[i][1] = 0; G[i][2] = 0; G[i][3] = 0;
    }

    a = 0; b = 0; c = 0; d = 0;
    for (int i = 0; i < m; i++)
    {
        a = a << 1;
        b = b << 1;
        c = c << 1;
        a += x[i];
        b += y[i];
        c += z[i];
    }

    G[a][0] = 1; G[a][1] = 0; G[a][2] = 0;
    G[b][0] = 1; G[b][1] = 0; G[b][2] = 0;
    G[c][0] = 1; G[c][1] = 0; G[c][2] = 0;

    for (int circle = 0; circle < 10; circle++)
    {
        for (int i = 0; (i < n); i++) if ((G[i][0] == 1))
            for(int j = i; (j < n); j++) if (G[j][0] == 1)
                {
                        if (G[i|j][0] == 0)
                        {
                            G[i|j][0] = 1; G[i|j][1] = i; G[i|j][2] = j; G[i|j][3] = 1;
                        }
                        if (G[i&j][0] == 0)
                        {
                            G[i&j][0] = 1; G[i&j][1] = i; G[i&j][2] = j; G[i&j][3] = 2;
                        }
                }
    }

    c = 232; d = 150;

    G[c][0] = 1; G[c][1] = 255 - c; G[c][2] = 0; G[c][3] = 3;
    G[d][0] = 1; G[d][1] = 255 - d; G[d][2] = 0; G[d][3] = 3;
    for (int circle = 0; circle < 10; circle++)
    {
        for (int i = 0; (i < n); i++) if ((G[i][0] == 1))
            for(int j = i; (j < n); j++) if (G[j][0] == 1)
                {
                        if (G[i|j][0] == 0)
                        {
                            G[i|j][0] = 1; G[i|j][1] = i; G[i|j][2] = j; G[i|j][3] = 1;
                        }
                        if (G[i&j][0] == 0)
                        {
                            G[i&j][0] = 1; G[i&j][1] = i; G[i&j][2] = j; G[i&j][3] = 2;
                        }
                }
    }

    fout = fopen("output.csv", "w");
    fprintf(fout, "\n");
    for(int j = 0; j < n; j++)  fprintf(fout, "%d, ", j);
    fprintf(fout, "\n");
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < n; j++)  fprintf(fout, "%d, ", G[j][i]);
        fprintf(fout, "\n");
    }

    /*
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum +=P2[i];
        printf("%d ", P2[i]);
    }
    printf("\n%d", sum);*/
}
