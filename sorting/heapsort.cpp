#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> &v)
{
    for (auto &e : v)
        cout << e << " ";
}

void Heapify(vector<int> &arr, int root, int size)
{
    int largest = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != root)
    {
        swap(arr[largest], arr[root]);
        Heapify(arr, largest, size);
    }
}

void HeapSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, size);
    }

    for (int i = 0; i < arr.size() - 1; i++)
    {
        swap(arr[0], arr[size - 1]);
        size--;
        Heapify(arr, 0, size);
    }
}

int main()
{
    vector<vector<int>> arrs = {
        {5, 4, 6, 1, 2, 3},
        {5, 4, 6, 7, 1, 2, 3},
        {3},
        {3, 2}};

    for (auto &arr : arrs)
    {
        HeapSort(arr);
        printVec(arr);
        cout << endl;
    }

    return 0;
}