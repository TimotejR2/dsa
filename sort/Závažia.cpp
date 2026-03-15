#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> freq(1001);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        freq[a]++;
    }

    int mi = 0;
    int mv = 0;
    for(int i = 0; i < 1001; i++){
        if(mv < freq[i]){
            mv= freq[i];
            mi = i;
        }
    }
    cout << mi<< ' ' << mv << '\n';


    return 0;

}