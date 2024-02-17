#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;
bool permutation_string(string s,string s1){
        unordered_map<unsigned char,int>smp,s1mp;

        for(char c: s){
            smp[c]++;
        }
        for(int i =0;i<s1.size();i++){
            s1mp[s1[i]]++;
            if(i>=s.size()){
                if(s1mp[s1[i-s.size()]] == 1){
                        s1mp.erase(s1[i-s.size()]);
                }
                else{
                    s1mp[s1[i-s.size()]]--;
                }
            }
            if(smp == s1mp){
                return true;
            }
        }
        return false;
}
int main(){
    string s,s1;
    cout<<"Enter first string : ";
    cin>>s;
    cout<<"Enter second string : ";
    cin>>s1;
    bool i;
    if(s.size()<s1.size()){
        i = permutation_string(s,s1);
    }
    else{
         i = permutation_string(s1,s);
    }
    
    if(i == true){
        cout<<"It is permutation string ";
    }    
    else{
        cout<<"Not a permutation string";
    }
    return 0;
}