#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define WALL -2
#define EMPTY -1

vector<vector<int>> next(const vector<int>& node, const vector<vector<int>>& map) {
    int x = node[1];
    int y = node [0];
    int dX[4] = {1, 0, -1, 0};
    int dY[4] = {0, 1, 0, -1};

    vector<vector<int>> coords;
    for(int smer=0; smer<4; smer++) {
        int nx = x+dX[smer], ny = y+dY[smer];
        if(nx < map[0].size() && ny < map.size()) {
            // valid coordinate
            if(map[ny][nx] == EMPTY) {
                coords.push_back({ny, nx});
            }
        }
    }
    return coords;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int r, s;
    cin >> r >> s;

    vector<vector<int>> map(r, vector<int>(s, EMPTY));
    vector<int> start;
    vector<int> end;
        

    for(int i = 0; i < r; i++){ // y coord
        string line;
        cin >> line; // načíta riadok bez medzier

        for (int j = 0; j < s; j++) {
            if(line[j] == 'S') start = {i,j};
            else if(line[j] == 'F') end = {i,j};

            if(line[j] == '#') map[i][j] = WALL;
        }
    }

    // search
    queue<vector<int>> fronta;
    fronta.push(start);
    map[start[0]] [start[1]] = 0;
    while(!fronta.empty()){
        vector<int> node = fronta.front();
        fronta.pop();
        if(node == end){
            cout << map[node[0]][node[1]] << endl;
            return 0;
        }
        vector<vector<int>> childs;
        childs = next(node, map);
        for(auto child : childs){
            fronta.push(child);
            map[child[0]][child[1]] = map[node[0]][node[1]] +1;
        }
    }
    cout << "-1" << endl;
    return 0;
    
}
