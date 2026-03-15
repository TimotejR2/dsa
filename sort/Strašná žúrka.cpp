#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n <= 3){
        cout << "Maja" << '\n';
        return 0;
    }

    vector<int> nums(n);
    vector<int> sorted(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sorted[i] = nums[i];
    }
    sort(sorted.begin(), sorted.end());

    int err = 0;
    for (int i = 0; i< n; i++){
        err += (nums[i] != sorted[i]);
    }
    if (err  > 2){
        cout << "ne";
    }
    cout << "Maja" << '\n';
    return 0;

    

}