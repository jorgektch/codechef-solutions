#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool is_not_desc(string str){
    if(str.length()<=1){
        return true;
    }else{
        for(int i=0; i<str.length()-1; i++){
            if(str[i]=='1' && str[i+1]=='0') return false;
        }
    }
    return true;
}
int main() {
    int t;
    int n;
    string cad, sub_cad;
    vector<int> lengths;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin >> n; cin >> cad;

        if(is_not_desc(cad)){
            cout << "0\n";
        }else{
            for(int i=0; i<n; i++){
                for(int j=i; j<n; j++){
                    // cout << "n: "<<n<<", i: "<<i<<", j: "<<j<<", long: "<<j-i+1<<"\n";
                    sub_cad = cad;
                    // cout << "cad: " << cad << " \n";
                    sub_cad.erase(i,j-i+1);
                    // cout << "subcad: " << sub_cad << " \n";
                    if(0<sub_cad.length() && sub_cad.length()<n && is_not_desc(sub_cad)){
                        lengths.push_back(j-i+1);
                    }
                }
            }
            cout << *min_element(lengths.begin(), lengths.end())<<"\n";
            lengths.clear();
        }
    }
    return 0;
}