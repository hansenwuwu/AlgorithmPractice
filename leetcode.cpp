#include <iostream>

using namespace std;

int main(){

    printf("hello");

    int n = 30;
    int r = 0;

    // n-1 times
    for(int i=1; i<n; i++){
        // 
        for(int j=i+1; j<=n; j++){
            // 
            for(int k=1; k<=j; k++ ){
                r++;
            }
        }
    }
    
    cout << r << endl;

    return 0;
}