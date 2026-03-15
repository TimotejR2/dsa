#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n <= 2){
        cout << "-1" << '\n';
        return 0;
    }

    cout << n;
    for(int i = n-1; i > 0; i--){
        cout<< ' ' << i;
    }
    cout << endl;


    return 0;

    

}