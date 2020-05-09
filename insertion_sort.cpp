#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void insertion_sort( vector<int>& s )
{
    int n = s.size();
    int min;

    for(int i=1; i<n; i++){
        int j = i;
        while( (j>0) && (s[j]<s[j-1]) ){
            swap( s[j], s[j-1] );
            j--;
        }
    }
}

int main(){

    vector<int> v{ 2, 3, 1, 4, 5, 7, 9, 8 };

    insertion_sort(v);

    for(auto e : v)
        cout << e ;
    cout << endl;
    
    return 0;
}