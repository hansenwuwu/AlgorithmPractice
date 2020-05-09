#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort( vector<int>& s )
{
    int n = s.size();
    int min;

    for(int i=0; i<n; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if( s[j] < s[min] ) min = j;
        }
        swap( s[i], s[min] );
    }
}

int main(){

    vector<int> v{ 2, 3, 1, 4, 5, 7, 9, 8 };

    selection_sort(v);

    for(auto e : v)
        cout << e ;
    cout << endl;
    
    return 0;
}