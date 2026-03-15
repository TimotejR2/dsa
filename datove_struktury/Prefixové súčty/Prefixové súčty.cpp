#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <deque>


using namespace std;

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix_sum[i] = prefix_sum[i - 1] + x;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << prefix_sum[x] << '\n';
    }
    return 0;
}
