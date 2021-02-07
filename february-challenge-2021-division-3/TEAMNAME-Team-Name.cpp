#include <bits/stdc++.h>
using namespace std;
int num_distincts(vector<char> v1, vector<char> v2){
    vector<char> v3;
    vector<char> v1_c = v1;
    vector<char> v2_c = v2;
    sort(v1_c.begin(), v1_c.end());
    sort(v2_c.begin(), v2_c.end());
    set_intersection(v1_c.begin(),v1_c.end(), v2_c.begin(),v2_c.end(), back_inserter(v3));
    return v1_c.size()+v2_c.size()-v3.size();
}
int main(int argc, char** argv){
    int t; cin>>t;
    for(int c=0; c<t; c++){
        int n; cin >> n;
        vector<string> words_vector;
        map<string, vector<char>> words_map;
        map<string, int> keys_map;
        for(int i=0; i<n; i++){
            string cad; cin >> cad;
            char cad_0 = cad[0];
            string cad_rest = cad.substr(1,cad.length()-1);
            keys_map[cad_rest] == true;
            words_map[cad_rest].push_back(cad_0);
        }
        int count = 0;
        for (auto it = words_map.begin(); it != words_map.end(); it++){
            for (auto jt = it ; jt != words_map.end(); jt++){
                if(it->first != jt->first){
                    int distincts = num_distincts(it->second, jt->second);
                    count += (it->second.size()-distincts)*(jt->second.size()-distincts);
                }
            }
        }
        cout << 2*count << "\n";
    }
    return 0;
}