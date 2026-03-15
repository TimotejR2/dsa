#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;
// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, suma;
    cin >> n >> suma;

    vector<int> num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    vector<int> dp(suma+1, INT_MAX-1);
    dp[0] = 0;

    for(int i = num[0]; i <= suma; i++){

        for(int j  = 0; j < n; j++){
            if(i >= num[j]) dp[i] = min(dp[i], dp[i-num[j]]+1);
        }
    }
    if(dp[suma] == INT_MAX-1) cout << "-1";
    else cout << dp[suma] << endl;
    return 0;

}