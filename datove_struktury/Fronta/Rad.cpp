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
    

    int max_lenght = 0;
    int cas_dalsi = 0; // cas kedy sa najblizsi dostane na radu

    queue<int> odchody;
    vector<pair<int,int>> ludia;
    for(int i  = 0; i < n; i++){
        int prichod, trvanie;
        cin >> prichod >> trvanie;
        ludia.push_back({prichod, trvanie});
    }

    sort(ludia.begin(), ludia.end());

    for(int i = 0; i < n; i++){
        int prichod = ludia[i].first;
        int trvanie = ludia[i].second;



        int odchod;
        if(prichod > cas_dalsi) odchod = prichod + trvanie;
        else odchod = cas_dalsi + trvanie;
        odchody.push(odchod);

        

        while(!odchody.empty() && odchody.front() < prichod){
            odchody.pop();
        }


        if(odchody.size() > max_lenght) max_lenght = odchody.size();
        cas_dalsi += trvanie;

    }
    cout << max_lenght -1 << "\n";
    return 0;

}