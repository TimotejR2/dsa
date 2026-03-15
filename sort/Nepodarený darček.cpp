#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> num(n);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    cout << '1';

    int onesum = 0;
    for(int i = 0; i < n-1; i++){
        if (num[i] == 1) onesum++;
        if (onesum < n-1) cout << ' ' << num[i];
        else cout << " 2";
    }
    cout << endl;
    return 0;

    

}