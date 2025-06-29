#include "auxiliary.h"

// 冒泡排序
void AUX_BubbleSort(Polynomial* poly)
{
	/*
	3 8 5 1 4
	
	3 8 5 1 4
	3 5 8 1 4
	3 5 1 8 4
	3 5 1 4 8

	3 5 1 4 8
	3 1 5 4 8
	3 1 4 5 8
	3 1 4 5 8
	*/
	Term temp;
	for (int i = poly->length - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			// 后项>前项，项间交换
			if (poly->terms[i].exp > poly->terms[j].exp)
			{
				temp = poly->terms[i];
				poly->terms[i] = poly->terms[j];
				poly->terms[j] = temp;
			}
		}
	}
}
