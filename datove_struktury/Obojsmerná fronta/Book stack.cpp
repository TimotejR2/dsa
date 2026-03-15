#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <deque>


using namespace std;
stack<int> base;
deque<int> top;

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    int reverse  = 0;

    

    while (true){
        int n;
        cin >> n;
        if (n == 0) break;
        else if(n == -1){
            if(!reverse){
                cout << top.back() << '\n';
                top.pop_back();

                if(base.size()){
                    top.push_front(
                        base.top()
                    );
                    base.pop();
                }
            }
            else{
                cout << top.front() << '\n';
                top.pop_front();

                if(base.size()){
                    top.push_back(
                        base.top()
                    );
                    base.pop();
                }
            }
        }

        else if (n == -2){
            reverse = !reverse;
        }
        else if (n > 0){
            if(!reverse) top.push_back(n);
            else top.push_front(n);

            if(top.size() > k){
                if(!reverse){
                    base.push(
                        top.front()
                    );
                    top.pop_front();
                }
                if(reverse){
                    base.push(
                        top.back()
                    );
                    top.pop_back();
                }
            }
        }


    }


}
