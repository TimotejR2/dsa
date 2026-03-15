#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        total_sum += nums[i];
    }
    sort(nums.begin(), nums.end());

    int sum = 0;

    int i = 0;
    sum = 0;

    while(sum*2 < total_sum){
        sum += nums[i++];
    }
    cout << n - i  +1 << '\n';
    return 0;


}