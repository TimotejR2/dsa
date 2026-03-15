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

    vector<vector<int>> mat(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        sort(mat[i].begin(), mat[i].end());
        // print row
        for(int j = 0; j < mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";

    }




}