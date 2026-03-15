#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <deque>
#include <queue>


using namespace std;
stack<int> base;
deque<int> top;

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n);
    vector<int> dist (n, INT_MAX);
    for(int i = 0; i < m; i++){
        int a,b, vaha;
        cin >> a >> b >> vaha;
        a--; b--;
        g[a].push_back({b, vaha});
        g[b].push_back({a, vaha});

    }
    int from, to;
    cin >> from >> to;
    from --; to --;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > q;

    q.push({0, from});

    while(!q.empty()){
        auto [d, v] = q.top();
        q.pop();
        if (d > dist[v]) continue;


        for(auto v : g[v]){
            if(v.second != INT_MAX){
                int nd = d + v.second;

                if(dist[v.first] > nd){
                    dist[v.first] = nd;
                    q.push({nd, v.first});
                }
            }
        }
    }
    if(dist[to] == INT_MAX) cout << "-1\n";
    else cout << dist[to] << '\n';
}
