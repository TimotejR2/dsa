#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int x;
        cin >> x;

        int l, r, index;
        l = 0; r = n-1;

        while(r >= l){
            index = (l+r)/2;

            if(nums[index] == x){
                cout << "A\n";
                break;
            }
            else if(nums[index] < x){
                l = index +1;
            }
            else r = index -1;
        }
        l = 0; r = n-1;
        if (nums[index] != x){
            x -= 2*x;
            while(r >= l){
            index = (l+r)/2;

            if(nums[index] == x){
                cout << "A\n";
                break;
            }
            else if(nums[index] < x){
                l = index +1;
            }
            else r = index -1;
        }
        if(nums[index] != x) cout << "N\n";
        }
    }


    return 0;
}
