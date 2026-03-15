#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> cf(n);
    for(int i = 0; i < n; i++){
        cin >> cf[i];
    }

    int k;
    cin >> k;
    vector<int> cs(k);
    for(int i = 0; i < k; i++){
        cin >> cs[i];
    }

    int f = 0;
    int s = 0;

    while((f < n) && (s < k)){
        if(cf[f] < cs[s]){
            cout << cf[f];
            if (f<n-1 || s<k) cout << ' ';
            f++;
        }
        else{
            cout << cs[s];
            if (f<n || s<k-1) cout << ' ';
            s++;
        }
    }

    while(f < n-1){
            cout << cf[f] << ' ';
            f++;
    }

    while(s < k-1){
            cout << cs[s] << ' ';
            s++;
    }
    if(f < n){
        cout << cf[f];
    }
    if(s < k){
        cout << cs[s];
    }
    cout << endl;
    return 0;
}