#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>



using namespace std;

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();


    queue<string> pl;
    for(int i = 0; i < n; i++){
        string line;
        getline(std::cin, line);
        char c = line[0];
        string nazov;
        if(line.size() > 1){
            nazov = line.substr(2);
        }
        if(c == '+'){
            pl.push(nazov);
        }
        else if(c == '-'){
            pl.pop();
        }
        else{
            cout << pl.front() << '\n';
        }

    }
    return 0;

}