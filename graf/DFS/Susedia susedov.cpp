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

    int start;
    cin >> start;

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

    bool printed = false;
    for (int i = 1; i <= n; ++i) {
        if (vzdialenost[i] == 2) {
            cout << i << '\n';
            printed = true;
        }
    }
    if (!printed) cout << "-1\n";
    return 0;
}
