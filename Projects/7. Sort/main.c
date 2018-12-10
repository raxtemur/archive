#include <stdio.h>
#include<stdlib.h>
#include  <math.h>

void bubblesort(int *arr, int arr_size);
void print_array(int arr[], int arr_size);
int *scan_array(int *arr_size, FILE *fin);
int quicksort(int *arr, int arr_size, int left, int right);
void heapsort(int *arr, int arr_size);
void mergesort(int *arr, int arr_size, int left, int right, int *buf);

int main()
{
    int arr_size = 0;
    int *arr;
    char filename[120];
    FILE *fin;
    printf("input filename\n");
    scanf("%s", filename);
    fin = fopen(filename, "r");
    if (!fin)
    {
        printf("file not opened!\n");
        return -1;
    }

    arr = scan_array(&arr_size, fin);
    print_array(arr, arr_size);
    //quicksort(arr, arr_size, 0, arr_size);
    //heapsort(arr, arr_size);
    int* buf =(int*)malloc(arr_size);
    mergesort(arr, arr_size, 0, arr_size, buf);
    free(arr);
    arr = buf;
    print_array(arr, arr_size);
    return 0;
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int *scan_array(int *arr_size, FILE *fin)
{
    if (!fscanf(fin, "%d", arr_size))
    {
        printf("empty file!\n");
        return -1;
    }
    int *arr = (int*) malloc(sizeof(int) * (*arr_size));
    for (int i = 0; i < (*arr_size); i++)
    {
        if(!fscanf(fin, "%d", &arr[i]))
        {
            printf("not enough data!\n");
            return -1;
        }
    }
    return (arr);
}

void print_array(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d%s", arr[i], " ");
    }
    printf("\n");
}

void bubblesort(int *arr, int arr_size)
{
    int buf;
    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 1; j < arr_size - i; j++)
        {
            if (arr[j] < arr[j-1] )
            {
                swap(&arr[j-1], &arr[j]);
            }
            print_array (arr, arr_size);
        }
    }
}

int quicksort(int *arr,  int arr_size, int left, int right) //for (i = left; i < right;..
{
    int  point = arr[right - 1];
    int l = left, r = right - 1;
    if (l >= r) return 0;
    while (l < r)
    {
        while (arr[l] < point)
        {
            l++;
        }
        while (arr[r] > point)
        {
            r--;
        }
        swap(&arr[l], &arr[r]);
    }
    print_array(arr, arr_size);
    quicksort(arr, arr_size, left, l);
    quicksort(arr, arr_size, l, right);
    return 1;
}

void heapsort(int *arr, int arr_size)
{
    int n, heap_size = 0, depth, index;
    int *heap = (int*) malloc(sizeof(int) * arr_size);
    for (int i = 0; i < arr_size; i++)
    {
        index = i;
        heap[i] = arr[i];
        heap_size++;
        depth = (int)(log(i + 1)/log(2)) + 1;
        while (index > 0)
        {
            if (heap[index] < heap[(index + 1)/2 - 1])
            {
                swap(&heap[index], &heap[(index + 1)/2 - 1]);
                index = (index + 1)/2 - 1;
            }
            else
            {
                break;
            }
        }
    }

    //print_array(heap, heap_size);
    int min_i, max_i;
    for(int i = 0; i < arr_size; i++)
    {
        arr[i] = heap[0];
        index = 0;
        heap[0] = heap[heap_size - 1];
        heap[heap_size - 1] = 0;
        heap_size -= 1;
        while ((index + 1)*2 - 1 < heap_size)
        {
            if ((index + 1)*2 >= heap_size)
            {
                max_i = (index + 1)*2 - 1;
                min_i = (index + 1)*2 - 1;
            }
            else if(heap[(index + 1)*2 - 1] > heap[(index + 1)*2])
            {
                min_i = (index + 1)*2;
                max_i = (index + 1)*2 - 1;
            }
            else
            {
                max_i = (index + 1)*2;
                min_i = (index + 1)*2 - 1;
            }

            if (heap[index] > heap[min_i])
            {
                swap(&heap[index], &heap[min_i]);
                index = min_i;
            }
            else if (heap[index] > heap[max_i])
            {
                swap(&heap[index], &heap[max_i]);
                index = max_i;
            }
            else
            {
                break;
            }
        }
        //print_array(heap, heap_size);
        //print_array(arr, arr_size);
    }
}

void mergesort(int *arr, int arr_size, int left, int right, int *buf)
{
    if (right - left == 1)
    {
        buf[0] = arr[left];
    }
    else
    {
        int mid = (left + right)/2;
        int *l_arr = (int*)malloc(mid - left);
        int *r_arr = (int*)malloc(right - mid);
        mergesort(arr, arr_size, left, mid, l_arr);
        mergesort(arr, arr_size, mid, right, r_arr);

        int l = 0, r = 0;
        while (r < right - mid && l < mid - left)
        {
            if (r_arr[r] < l_arr[l])
            {
                buf[r + l] = r_arr[r];
                r++;
            }
            else
            {
                buf[r + l] = l_arr[l];
                l++;
            }
        }
        while (r < right - mid)
        {
            buf[l + r] = r_arr[r];
            r++;
        }
        while (l < mid - left)
        {
            buf[l + r] = l_arr[l];
            l++;
        }
    }
    //print_array(buf, right - left);
}

