#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> holes(n+2);
    holes[0] = 0;
    for(int i = 1; i < n+1; i++) cin >> holes[i];
    vector<int> dp(n+5, __INT_MAX__);
    int SMALL = 3;
    int BIG = 5;
    dp[0] = 0;

    for(int i = 1; i <= n; i++){


        int j = 0;
        while(i+j <= n && holes[i+j] <= holes[i] + SMALL){
            dp[i+j] = min(dp[i-1] + SMALL, dp[i+j]);
            j++;
        }

        j = 0;
        while(i+j <= n && holes[i+j] <= holes[i] + BIG){
            dp[i+j] = min(dp[i-1] + BIG, dp[i+j]);
            j++;
        }

    }
    cout << dp[n] << '\n';



}