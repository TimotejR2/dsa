#include <iostream>
#include <vector>
#include <limits.h>


using namespace std;

int main(){
    int n;
    cin >> n;

    int min = INT_MAX;
    int min_index;
    vector<int> cisla(n);
    for(int i = 0; i < n; i++){
        cin >> cisla[i];
        if (cisla[i] < min){
            min = cisla[i];
            min_index = i;
        }
    }

    int tmp = cisla[0];
    cisla[0] = cisla[min_index];
    cisla[min_index] = tmp;

    int i  = 0;
    for(auto x : cisla){
        cout << x;
        if (i<n-1) cout << ' ';
        i++;
    }
    cout << endl;
    return 0;




}