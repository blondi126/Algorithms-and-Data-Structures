#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//void QuickSort2(int*, int*, int, int);
void QuickSort(int*, int, int);
void HeapSort(int*, int*,int);
void siftDown(int*, int*, int, int);
void InsertionSort(int*, int, int);


int main()
{
    int i, n;
    scanf("%d", &n);
    int* a, * b;
    a = (int*)malloc(n * sizeof(int));
    b = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = i + 1;
    }
    //QuickSort(a, b, 0, n - 1);
    HeapSort(a,b,n);
    int count = 0;
    for (i = 0;i < n - 1;i++) {
        if (a[i] == a[i + 1]) {
            count++;
            continue;
        }
        
        if (count > 0) {
            if (count > 7) QuickSort(b, i - count, i);
            else InsertionSort(b, i - count, i);
         
        }
        count = 0;
    
    }
    if (count > 0) {
        if (count > 7) QuickSort(b, i - count, i);
        else InsertionSort(b, i - count, i);
    }
   
    int q;
    scanf("%d", &q);
    int* l, * r, * x;
    l = (int*)malloc(q * sizeof(int));
    r = (int*)malloc(q * sizeof(int));
    x = (int*)malloc(q * sizeof(int));
    for (i = 0; i < q; i++)
    {
        scanf("%d %d %d", &l[i], &r[i], &x[i]);
    }


    for (i = 0; i < q; i++) {
        int right = n - 1;
        int left = 0;
        int z = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] > x[i]) right = mid - 1;
            if (a[mid] < x[i]) left = mid + 1;
            if (a[mid] == x[i]) {
                while (b[mid] > r[i] && b[mid] > 0 && a[mid]==x[i]) mid--;
                while (b[mid] < l[i] && b[mid] < n && a[mid] == x[i]) mid++;
                if ((b[mid] >= l[i]) && (b[mid] <= r[i]) && (a[mid] == x[i])) z = 1;
                break;
            } 
            /* int pr = 0;
             while (a[mid] == x[i]) {
                if ((b[mid] >= l[i]) && (b[mid] <= r[i])) {
                    z = 1; pr = 1; break;
                } else 
                if (b[mid] > r[i]) mid--; else 
                if (b[mid] < l[i]) mid++;
            }
            if (pr == 1) break; */
        }
        printf("%d", z);
    }
    free(a);
    free(b);
    free(l);
    free(r);
    free(x);
    return 0;
}



void QuickSort(int* num, int left, int right)
{
    int pivot;
    int l_hold = left;
    int r_hold = right;
    pivot = num[left];
    while (left < right)
    {
        while ((num[right] > pivot) && (left < right))
            right--;
        if (left != right)
        {
            num[left] = num[right];
            left++;
        }
        while ((num[left] < pivot) && (left < right))
            left++;
        if (left != right)
        {
            num[right] = num[left];
            right--;
        }
    }
    num[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        QuickSort(num, left, pivot - 1);
    if (right > pivot)
        QuickSort(num, pivot + 1, right);
}

 void HeapSort(int* numbers, int* numbers2, int array_size) {
    
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers,numbers2, i, array_size - 1);
 
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        int temp2 = numbers2[0];
        numbers[0] = numbers[i];
        numbers2[0] = numbers2[i];
        numbers[i] = temp;
        numbers2[i] = temp2;
        siftDown(numbers,numbers2, 0, i - 1);
    }
}
void siftDown(int* numbers,int* numbers2,int root, int bottom)
{
    int maxChild; 
    int done = 0; 
   
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    
            maxChild = root * 2;    
         
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
       
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; 
            int temp2 = numbers2[root];
            numbers[root] = numbers[maxChild];
            numbers2[root] = numbers2[maxChild];
            numbers[maxChild] = temp;
            numbers2[maxChild] = temp2;
            root = maxChild;
        }
        else  
            done = 1;
    }
} 
void InsertionSort(int* num, int l, int r)
{
    int newElement, location;

    for (int i = l+1; i < r+1; i++)
    {
        newElement = num[i];
        location = i - 1;
        while (location >= l && num[location] > newElement)
        {
            num[location + 1] = num[location];
            location = location - 1;
        }
        num[location + 1] = newElement;
    }
}