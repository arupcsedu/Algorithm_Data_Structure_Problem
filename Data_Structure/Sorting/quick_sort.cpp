/* Author : Arup Sarker
 * Date : 30-11-2017
 * url : http://www.geeksforgeeks.org/quick-sort/
 * Algorithm : QuickSort
 *Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

    Always pick first element as pivot.
    Always pick last element as pivot (implemented below)
    Pick a random element as pivot.
    Pick median as pivot.

 * The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
 *
 */

#include<stdio.h>


int quick_partition(int arr[], int l, int h)
{
	int pivot = arr[h];
	int i = l-1;
	int temp;
	for(int j = l; j<h; j++)
	{
		if(arr[j]<=pivot)
		{
			i++;

			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[h];
	arr[h] = temp;

	return i+1;

}
void quick_sort_mechanism(int arr[], int l, int h)
{
	if(l<h)
	{
		int pivot = quick_partition(arr,l,h);
		quick_sort_mechanism(arr,l, pivot-1);
		quick_sort_mechanism(arr, pivot+1, l);

	}
}
int main()
{
	int quick_arr[] = {3 , 4, 6, 7, 1 , 2, 4, 8, 5, 10};
	int quick_arr_size = sizeof(quick_arr)/ sizeof(quick_arr[0]);

	printf("Before Sorting: ");
	for (int i = 0; i<quick_arr_size; i++)
		printf("%d ", quick_arr[i]);
	printf("\n");
	quick_sort_mechanism(quick_arr,0, quick_arr_size-1);

	printf("After Sorting: ");
	for (int i = 0; i<quick_arr_size; i++)
		printf("%d ", quick_arr[i]);
	printf("\n");


	return 0;
}
