#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> &v)
{
    for (auto &e : v)
        cout << e << " ";
}

int Partition(vector<int> &arr, int l, int r)
{
    int pivot = r;
    int i = l - 1;
    for (int j = l; j < pivot; j++)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivot]);
    return i + 1;
}

void QuickSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int p = Partition(arr, l, r);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
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
        QuickSort(arr, 0, arr.size() - 1);
        printVec(arr);
        cout << endl;
    }

    return 0;
}