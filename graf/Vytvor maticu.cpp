#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >>b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }



}