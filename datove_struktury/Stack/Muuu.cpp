#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>


using namespace std;

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> h(n); // vyska
    vector<int> v(n); // hlasitost
    for(int i = 0; i < n; i++){
        cin >> h[i] >> v[i];
    }

    stack<int> sh;
    stack<int> sv;
    vector<int> res(n, 0);

    
    for(int i = 0; i < n; i++){
        while(!sh.empty() && sh.top() < h[i]){
            sh.pop();
            res[i] += sv.top();
            sv.pop();
        }
        sh.push(h[i]);
        sv.push(v[i]);
    }
    while(!sh.empty()){
        sh.pop();
        sv.pop();
    }

    for(int i = n-1; i >=0; i--){
        while(!sh.empty() && sh.top() < h[i]){
            sh.pop();
            res[i] += sv.top();
            sv.pop();
        }
        sh.push(h[i]);
        sv.push(v[i]);
    }



    auto max_it = std::max_element(res.begin(), res.end());
    // dereferencovanie iteratora dá hodnotu
    if (max_it != v.end()) {
        std::cout << *max_it << "\n";
    }
    return 0;


}