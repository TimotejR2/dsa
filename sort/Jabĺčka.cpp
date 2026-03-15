#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> more;
    int same = 0;


    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a < k){
            if(i) cout << ' ';
            cout << a;
        }
        else if (a==k) same++;
        else more.push_back(a);
    }
    cout << '\n';

    for(int i = 0; i < same; i++){
        if(i) cout << ' ';
        cout << k;
    }
    cout << '\n';
    for(int i = 0; i < more.size(); i++){
        if(i) cout << ' ';
        cout << more[i];
    }
    cout << '\n';

    return 0;

}