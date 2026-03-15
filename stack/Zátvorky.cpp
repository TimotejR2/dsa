#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;

short bracketToNumber(char c) {
    switch (c) {
        case '{': return 1;
        case '}': return -1;
        case '(': return 2;
        case ')': return -2;
        case '[': return 3;
        case ']': return -3;
        default: return 0; // iné znaky
    }
}

// stupajuca postupnost
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<short> stack;
    char p;
    while(cin >> p){
        short c = bracketToNumber(p);
        if (c>0){
            stack.push_back(c);
        }
        else{
            if (stack.empty() || stack.back() != -c){
                cout << "Nie\n";
                return 0; 
            }
            else if(!stack.empty() && stack.back() == -c){
                stack.pop_back();
            }

        }
    }
    if (stack.empty()) cout << "Ano\n";
    else cout << "Nie\n";
    return 0;

}