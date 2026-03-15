#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n <= 2){
    cout << "poriadok" << endl;
    return 0;
    }

    int klesajuce = 1;
    int stupajuce = 1;

    int predosle;
    cin >> predosle;

    for(int i = 1; i < n; i++){
        int aktualne;
        cin >> aktualne;
        klesajuce *= (predosle >= aktualne);
        stupajuce *= (aktualne >= predosle);
        predosle = aktualne;

    }
    if(klesajuce || stupajuce){
        cout << "poriadok" << endl;
    }
    else cout << "bordel" << endl;
    return 0;


}