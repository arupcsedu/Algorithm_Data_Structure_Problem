#include<stdio.h>
#include<string.h>

void selectionSort(int arr[], int n)
{
    int i,j, minimum;
    i = 0;
    while(i < n-1)
    {
        minimum = i;
        j = i+1;
        while(j < n)
        {
            if(arr[j] < arr[minimum])
            {
                minimum = j;
            }
            j++;
        }

        int tmp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = tmp;

        i++;
    }
    i = 0;
    while(i < n)
    {
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        bool isSwaped = false;
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                isSwaped = true;
            }
        }

        if(!isSwaped)
            break;
    }
    int i = 0;
    while(i < n)
    {
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
}
void mergeStr(int arr[], int l,int r,int m)
{
    unsigned int n1 = m - l + 1;
    unsigned int n2 = r - m;
    int L[n1], R[n2];
    int i = 0;
    int j = 0;

    for(i = 0; i<n1; i++)
        L[i] = arr[l+i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m+j+1];
    int k = l;
    i = 0;
    j = 0;
    while(i < n1 && j <n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Merge remaining array

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int n, int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        mergeSort(arr,n,l,m);
        mergeSort(arr,n,m+1,r);
        mergeStr(arr,l,r,m);

    }
}
void quickSwapped(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
int quickPartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l-1;
    for(int j = l; j <= h-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            quickSwapped(&arr[i], &arr[j]);

        }
    }
    quickSwapped(&arr[i+1], &arr[h]);
    return i+1;
}

void quickSortAlg(int arr[], int l, int h)
{
    if(l<h)
    {
        int pivot = quickPartition(arr,l,h);
        quickSortAlg(arr,l,pivot-1);
        quickSortAlg(arr,pivot+1,h);
    }
}

void quickSortIterative(int arr[], int l, int h)
{
    int qStack[h-l+1];
    int top = 0;
    qStack[top++] = l;
    qStack[top++] = h;
    while(top > 0)
    {
        h = qStack[--top];
        l = qStack[--top];
        int pivot = quickPartition(arr, l, h);

        if(pivot > l)
        {
            qStack[top++] = l;
            qStack[top++] = pivot - 1;
        }

        if(pivot + 1 < h)
        {
            qStack[top++] = pivot + 1;
            qStack[top++] = h;
        }
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if(i != largest)
    {
        quickSwapped(&arr[i], &arr[largest]);
        heapify(arr, n , largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = (n/2)-1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }

    for(int i = n-1; i >= 0; i--)
    {
        quickSwapped(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void countingSort(int arr[], int n)
{
    int countArr[100],outputArr[100];
    memset(countArr, 0, sizeof(countArr));
    for(int i = 0; i <n; i++)
    {
        countArr[arr[i]]++;
    }

    for(int i = 1; i < 99; i++)
    {
        countArr[i] += countArr[i-1];
    }

    for(int i = 0; i < n; i++)
    {
        outputArr[countArr[arr[i]] - 1] = arr[i];
        countArr[arr[i]]--;
    }
    for(int i = 0 ;i < n;i++)
    {
        printf("%d ",outputArr[i]);
    }
    printf("\n");
}

void printArray(int arr[], int n)
{
    for(int i = 0; i <n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main_sort()
{
    int arr[] = {11, 25, 12, 22, 3, 15,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    //selectionSort(arr,n);
   // bubbleSort(arr,n);

    //mergeSort(arr,n,0,n-1);
    //quickSortAlg(arr,0,n-1);
    //quickSortIterative(arr,0,n-1);
   // heapSort(arr,n);
   countingSort(arr,n);
    //printArray(arr,n);
    return 0;
}
