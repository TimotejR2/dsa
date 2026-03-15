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

    string line;
    cin >> line; // načíta riadok bez medzier
    stack<char> st;

    for(char c : line){
        if(c == '(' || c == '{' || c == '[' || st.empty()){
            st.push(c);
        }
        else{
            char last = st.top();
            if(
                (c == ')' && last == '(') ||
                (c == '}' && last == '{') ||
                (c == ']' && last == '[')
            ){
                st.pop();
            }
        }
    }
    if(st.empty()){
        cout << "Ano\n";
    }
    else cout << "Nie\n";
    return 0;



}