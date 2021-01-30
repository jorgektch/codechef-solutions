#include <iostream>
using namespace std;
int main() {
    int t;
    int x, y, z;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>x; cin>>y, cin>>z;
        if(x==y+z || y==z+x || z==x+y){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}