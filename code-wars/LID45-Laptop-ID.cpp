#include <bits/stdc++.h>
using namespace std;
char nth_letter(int n){
    return "abcdefghijklmnopqrstuvwxyz"[n-1];
}
int main(){
    string id; cin >> id;
    map<char, long long int> freq;
    for(long long int i=0; i<id.length(); i++){
        freq[id[i]]++;
    }

    map<long long int, long long int> map_freq;    
    for(int i=1; i<=26; i++){
        if(freq[nth_letter(i)]>0){
            map_freq[freq[nth_letter(i)]]++;
        }
    }

    long long int freq_max=0;
    long long int freq_min=id.length();
    map<long long int, long long int>::iterator itr;
    for(itr = map_freq.begin(); itr != map_freq.end(); itr++){
        if(itr->first > freq_max)
            freq_max = itr->first;
        if(itr->first < freq_min)
            freq_min = itr->first;
    }

    string str_out;
    if(map_freq.size()>2){
        cout << "The string is invalid\n";
    }else{
        if(map_freq.size()==1){
            str_out = "";
            for(int i=1; i<=26; i++){
                for(int j=0; j<freq[nth_letter(i)]; j++){
                    str_out += nth_letter(i);
                }
            }
            cout << str_out << "\n";
        }else{
            if(map_freq.size()==2){
                if(map_freq[freq_max]==1 && freq_max-freq_min==1){
                    for(int i=1; i<=26; i++)
                        if(freq[nth_letter(i)]==freq_max)
                            freq[nth_letter(i)]--;
                    str_out = "";
                    for(int i=1; i<=26; i++){
                        for(int j=0; j<freq[nth_letter(i)]; j++){
                            str_out += nth_letter(i);
                        }
                    }
                    cout << str_out << "\n";
                }else{
                    if(map_freq[freq_min]==1 && freq_min==1){
                        for(int i=1; i<=26; i++)
                            if(freq[nth_letter(i)]==freq_min)
                                freq[nth_letter(i)]--;
                        str_out = "";
                        for(int i=1; i<=26; i++){
                            for(int j=0; j<freq[nth_letter(i)]; j++){
                                str_out += nth_letter(i);
                            }
                        }
                        cout << str_out << "\n";
                    }else{
                        cout << "The string is invalid\n";
                    }
                }
            }else{
                cout << "The string is invalid\n";
            }
        }
    }
    return 0;
}