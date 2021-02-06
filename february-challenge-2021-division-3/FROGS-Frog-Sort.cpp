#include <bits/stdc++.h>
using namespace std;
struct frog{
    int pos;
    int weight;
    int jumps;
};
bool compare_by_weight(const frog &f1, const frog &f2){
    return f1.weight < f2.weight;
}
int main(){
    int t; cin>>t;
    for(int c=0; c<t; c++){
        int n; cin >> n;
        vector<frog> frogs = vector<frog>();
        vector<int> ws = vector<int>();
        vector<int> js = vector<int>();
        for(int i=0; i<n; i++){
            int w; cin >> w;
            ws.push_back(w);
        }
        for(int i=0; i<n; i++){
            int j; cin >> j;
            js.push_back(j);
        }
        for(int i=0; i<n; i++){
            frog f;
            f.pos = i;
            f.weight = ws[i];
            f.jumps = js[i];
            frogs.push_back(f);
        }
        sort(frogs.begin(), frogs.end(), compare_by_weight);
        int count = 0;
        for(int i=1; i<n; i++){
            while(frogs[i].pos <= frogs[i-1].pos){
                frogs[i].pos = frogs[i].pos + frogs[i].jumps;
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}