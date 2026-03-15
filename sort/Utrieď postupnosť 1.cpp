#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int n;
    cin >> n;


    vector<int> cisla(n);
    for(int i = 0; i < n; i++){
        cin >> cisla[i];
    }
    std::sort(cisla.begin(), cisla.end());

    int i  = 0;
    for(auto x : cisla){
        cout << x;
        if (i<n-1) cout << ' ';
        i++;
    }
    cout << endl;
    return 0;



}