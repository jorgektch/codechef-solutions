#include <bits/stdc++.h>
using namespace std;
struct Word{
    char first;
    vector<string> ends = vector<string>();
};
int main(int argc, char** argv){
    int t; cin>>t;
    for(int c=0; c<t; c++){
        int n; cin >> n;
        vector<Word> words = vector<Word>();
        string cad;
        for(int i=0; i<n; i++){
            cin >> cad;
            if(words.size() == 0){
                Word w;
                w.first = cad[0];
                w.ends.push_back(cad.substr(1,cad.length()-1));
                words.push_back(w);
            }else{
                bool exist = false;
                for(int j=0; j<words.size(); j++){
                    if(words[j].first == cad[0]){
                        words[j].ends.push_back(cad.substr(1,cad.length()-1));
                        exist = true;
                    }
                }
                if(!exist){
                    Word w;
                    w.first = cad[0];
                    w.ends.push_back(cad.substr(1,cad.length()-1));
                    words.push_back(w);
                }
            }
        }
        /*
        for(int i=0; i<words.size(); i++){
            cout << words[i].first << " ";
            for(int j=0; j<words[i].ends.size(); j++){
                cout << words[i].ends[j] <<" ";
            }
            cout << "\n";
        }
        */
        
        int count = 0;
        for(int i=0; i<words.size()-1; i++){
            for(int j=i+1; j<words.size(); j++){
                for(int k=0; k<words[i].ends.size(); k++){
                    for(int l=0; l<words[j].ends.size(); l++){
                        if(words[i].ends[k] != words[j].ends[l]){
                            count++;
                        }
                    }
                }
            }
        }
        cout << count << endl;
        
        
    }
    return 0;
}