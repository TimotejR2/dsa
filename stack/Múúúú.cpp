#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // najvecsia na zaciatku
    vector<int, int>stack;
    vector<int> vol(n, 0);

    for(int i = 0; i < n; i++){
        int h, v;
        cin >> h >> v;

        if(stack.empty() && stack.back()[0] >= h){
            stack.push_back((h, v));
        }
        else{
            while(!stack.empty() && stack.back()[0] < h){
                vol[i] += stack.back()[1];
                stack.pop_back();
            }
        }

    }


}