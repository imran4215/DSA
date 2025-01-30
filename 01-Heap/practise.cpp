#include <bits/stdc++.h>
using namespace std;

void heapify(int n, int arr[], int i)
{
    int curr = i;
    int left = 2 * i;
    int right = i * 2 + 1;

    if (left < n && arr[left] > arr[curr])
    {
        curr = left;
    }
    if (right < n && arr[right] > arr[curr])
    {
        curr = right;
        ;
    }

    if (curr != i)
    {
        swap(arr[curr], arr[i]);
        heapify(n, arr, curr);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        arr[1] = arr[size];
        size--;

        heapify(size, arr, 1);
    }
}

int main()
{

    return 0;
}