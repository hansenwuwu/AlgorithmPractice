#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &v)
{
    for (auto &e : v)
        cout << e << " ";
}

void Merge(vector<int> &arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> left(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1);

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void MergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main()
{
    vector<int> arr = {5, 4, 6, 1, 2, 3};
    MergeSort(arr, 0, arr.size() - 1);
    printVec(arr);
    cout << endl;
    vector<int> arr2 = {5, 4, 6, 7, 1, 2, 3};
    MergeSort(arr2, 0, arr2.size() - 1);
    printVec(arr2);
    cout << endl;
    vector<int> arr3 = {3};
    MergeSort(arr3, 0, arr3.size() - 1);
    printVec(arr3);
    cout << endl;
    vector<int> arr4 = {3, 2};
    MergeSort(arr4, 0, arr4.size() - 1);
    printVec(arr4);

    return 0;
}