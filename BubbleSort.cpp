#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>

void Sort(int*, char*, int, int);

int main()
{
	int n;
	FILE* input;
	if ((input = fopen("InputFile.txt", "r")) == nullptr)
	{
		return 1;
	}
	fscanf(input, "%d", &n);
	int* A;
	char* B;
	A = static_cast<int*>(malloc(n * sizeof(int)));
	B = static_cast<char*>(malloc(n * 200 * sizeof(char)));
	for (int i = 0; i < n; i++)
	{
		fscanf(input, "\n%d %s", &A[i], (B + i * 200));
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
		// printf("%s\n", (B + i * 200));
	}
	printf("\n");
	fclose(input);
	Sort(A, B, 0, n - 1);
	free(A);
	free(B);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
		// printf("%s\n", (B + i * 200));
	}
	return 0;
}

void Sort(int* num, char* words, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = num[left];
	/* char* t2[200];
	 for (int i = 0; i < 200; i++) {
	    *t2[i] = *(words + left * 200 + i);
	} */

	while (left < right) // пока границы не сомкнутся
	{
		while ((num[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			num[left] = num[right]; // перемещаем элемент [right] на место разрешающего
			/* for (int i = 0; i < 200; i++) {
			    *(words + left * 200 + i) = *(words + right * 200 + i);
			} */
			left++; // сдвигаем левую границу вправо
		}
		while ((num[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			num[right] = num[left]; // перемещаем элемент [left] на место [right]
			/* for (int i = 0; i < 200; i++) {
			    *(words + right * 200 + i) = *(words + left * 200 + i);
			} */
			right--; // сдвигаем правую границу вправо
		}
	}
	num[left] = pivot; // ставим разрешающий элемент на место
	/*for (int i = 0; i < 200; i++) {
	   *(words + left * 200 + i) = *t2[i];
   } */
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		Sort(num, words, left, pivot - 1);
	if (right > pivot)
		Sort(num, words, pivot + 1, right);
}
