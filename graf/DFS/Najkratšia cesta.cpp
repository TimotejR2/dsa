#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> kam(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        kam[u].push_back(v);
        kam[v].push_back(u);
    }

    int start, end;
    cin >> start >> end;

    vector<int> vzdialenost(n + 1, -1);
    queue<int> q;
    vzdialenost[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : kam[v]) {
            if (vzdialenost[w] != -1) continue;
            vzdialenost[w] = vzdialenost[v] + 1;
            q.push(w);
        }
    }

    cout << vzdialenost[end] << endl;
    return 0;
}
