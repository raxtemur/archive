#include<stdio.h>
#include<math.h>

#define EPS 1e-9
#define MAX(a,b) (((a)>(b))?(a):(b))

int scan_matrix(FILE *fp, int n, int m, int *a)
{
    for (int i = 0; i < n*m; i++)
    {
        if (fscanf(fp, "%d", &a[i]) != 1)
        {
            printf("Error: WRONG DATA");
            return -1;
        }
    }
    return 1;
}

int print_matrix(FILE *fp, int n, int m, int *a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) fprintf(fp, "%d ", a[i*m+j]);
        fprintf(fp, "\n");
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int m, n, rank;
    FILE *fin, *fout;
    int *a;

    if (argc == 1)
    {
        printf("Error: no input filename in arguments!\n");
        return -1;
    }
    fin = fopen (argv[1], "r");
    fout = fopen ("output.txt", "w");
    if(!fin)
    {
        printf ("Error: cannot open input file!\n");
        return(-1);
    }
    if(!fout)
    {
        printf ("Error: cannot open output file!\n");
        return(-1);
    }

    fscanf(fin, "%d%d", &n, &m);
    a = (int*)malloc(m*n*sizeof(int));
    scan_matrix(fin, n, m, a);
    rank = MAX(n, m);
    print_matrix(fout, n, m, a);


    return 0;
}


/*
const double EPS = 1E-9;

int rank = max(n,m);
vector<char> line_used (n);
for (int i=0; i<m; ++i) {
	int j;
	for (j=0; j<n; ++j)
		if (!line_used[j] && abs(a[j][i]) > EPS)
			break;
	if (j == n)
		--rank;
	else {
		line_used[j] = true;
		for (int p=i+1; p<m; ++p)
			a[j][p] /= a[j][i];
		for (int k=0; k<n; ++k)
			if (k != j && abs (a[k][i]) > EPS)
				for (int p=i+1; p<m; ++p)
					a[k][p] -= a[j][p] * a[k][i];
	}
}
*/
