#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int,int>>> G;
vector<int> V;
int n,m;

void dijkstra_s_haldou(int a) {
    V.assign(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, a});
    while (!Q.empty()) {
        while (!Q.empty() && V[Q.top().second] != -1) Q.pop();
        if (Q.empty()) break;
        int v = Q.top().second;
        int vzd = Q.top().first;
        Q.pop();
        V[v] = vzd;
        for (auto [w, dlz] : G[v]) {
            if (V[w] != -1) continue;
            Q.push({vzd + dlz, w});
        }
    }
}

int main() {
    cin >> n >> m;
    G.resize(n);
    for(int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--; b--;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    int from, to;
    cin >> from >> to;    
    from--; to--;
    dijkstra_s_haldou(from);
    cout << V[to] << endl;
}
