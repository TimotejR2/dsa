#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;
// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n++;

    vector<__int128> dp(n+1, 0);
    dp[1] = 1;

    for(int i = 2; i <= n; i++){

        
        if(i > 2) dp[i] = (dp[i-1]+ dp[i-2])%1000000007;
        else dp[i] = dp[i-1];
    }
    //cout << dp[n];
    cout << int(dp[n]%1000000007) << endl;
    return 0;

}