#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    for(int c=0; c<t; c++){
        string hour; string turn;
        cin >> hour; cin >> turn;
        int time_p = 0;
        if(turn=="PM" && hour.substr(0,2)!="12"){
            time_p = time_p+720;
        }
        if(!(turn=="AM" && hour.substr(0,2)=="12")){
            time_p = time_p+stoi(hour.substr(0,2))*60;
        }
        time_p = time_p+stoi(hour.substr(3,2));
        int n; cin >> n;
        for(int i=0; i<n; i++){
            cin >> hour; cin >> turn;
            int time_l = 0;
            if(turn=="PM" && hour.substr(0,2)!="12"){
                time_l = time_l+720;
            }
            if(!(turn=="AM" && hour.substr(0,2)=="12")){
                time_l = time_l+stoi(hour.substr(0,2))*60;
            }
            time_l = time_l+stoi(hour.substr(3,2));

            cin >> hour; cin >> turn;
            int time_r = 0;
            if(turn=="PM" && hour.substr(0,2)!="12"){
                time_r = time_r+720;
            }
            if(!(turn=="AM" && hour.substr(0,2)=="12")){
                time_r = time_r+stoi(hour.substr(0,2))*60;
            }
            time_r = time_r+stoi(hour.substr(3,2));

            if(time_l<=time_p && time_p<=time_r){
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << "\n";
    }
    return 0;
}