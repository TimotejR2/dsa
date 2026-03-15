#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>



using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<pair<int,int>> body(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        body[i] = {x, y};
    }

    // SORT
    sort(body.begin(), body.end());

    // konvexny obal
    vector<pair<int,int>> konvexny_obal1;
    konvexny_obal1.push_back(body[0]);
    konvexny_obal1.push_back(body[1]);

    for(int i = 2; i < n; i++){
        pair<long long, long long> v1 = {
            konvexny_obal1[konvexny_obal1.size()-1].first - konvexny_obal1[konvexny_obal1.size()-2].first,
            konvexny_obal1[konvexny_obal1.size()-1].second - konvexny_obal1[konvexny_obal1.size()-2].second
        };

        pair<long long,long long> v2 = {
            body[i].first - konvexny_obal1[konvexny_obal1.size()-1].first,
            body[i].second - konvexny_obal1[konvexny_obal1.size()-1].second
        };
        while( ((v1.first*v2.second) - (v2.first*v1.second)) >= 0 && konvexny_obal1.size() >= 2 ){
                        konvexny_obal1.pop_back();

            v1 = {
                konvexny_obal1[konvexny_obal1.size()-1].first - konvexny_obal1[konvexny_obal1.size()-2].first,
                konvexny_obal1[konvexny_obal1.size()-1].second - konvexny_obal1[konvexny_obal1.size()-2].second
            };

            v2 = {
                body[i].first - konvexny_obal1[konvexny_obal1.size()-1].first,
                body[i].second - konvexny_obal1[konvexny_obal1.size()-1].second
            };
        }

        konvexny_obal1.push_back(body[i]);
    }
    vector<pair<int,int>> konvexny_obal2;
    konvexny_obal2.push_back(body[n-1]);
    konvexny_obal2.push_back(body[n-2]);



    for(int i = n-3; i >= 0; i--){
        pair<long long, long long> v1 = {
            konvexny_obal2[konvexny_obal2.size()-1].first - konvexny_obal2[konvexny_obal2.size()-2].first,
            konvexny_obal2[konvexny_obal2.size()-1].second - konvexny_obal2[konvexny_obal2.size()-2].second
        };

        pair<long long,long long> v2 = {
            body[i].first - konvexny_obal2[konvexny_obal2.size()-1].first,
            body[i].second - konvexny_obal2[konvexny_obal2.size()-1].second
        };


        while( (v1.first*v2.second - v2.first*v1.second) >= 0 && konvexny_obal2.size() >= 2 ){

            konvexny_obal2.pop_back();

            v1 = {
                konvexny_obal2[konvexny_obal2.size()-1].first - konvexny_obal2[konvexny_obal2.size()-2].first,
                konvexny_obal2[konvexny_obal2.size()-1].second - konvexny_obal2[konvexny_obal2.size()-2].second
            };

            v2 = {
                body[i].first - konvexny_obal2[konvexny_obal2.size()-1].first,
                body[i].second - konvexny_obal2[konvexny_obal2.size()-1].second
            };
        }

        konvexny_obal2.push_back(body[i]);
    }

    // odstranime posledny bod, lebo je rovnaky ako prvy
    //konvexny_obal1.pop_back();

    //konvexny_obal2.pop_back();


    cout << konvexny_obal1.size() + konvexny_obal2.size() - 2<< "\n";

    return 0;

}