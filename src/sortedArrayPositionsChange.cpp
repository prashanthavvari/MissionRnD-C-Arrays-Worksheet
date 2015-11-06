/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, j, count = 0, pos = 0, temp, c = 0;
	if (len < 0)
		return NULL;
	if (Arr == NULL)
		return NULL;
	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (Arr[i] <= Arr[j])
				count++;
			else
			{
				c = 1;
				pos = j;
				break;
			}
		}
		if (c == 1)
			break;
	}
	if (c == 1)
	{
		temp = Arr[pos];
		Arr[pos] = Arr[i];
		Arr[i] = temp;
		sortedArrayPositionsChange(Arr, len);
	}
	if (count == len)
		return NULL;

	if (c == 0)
		return Arr;
}
