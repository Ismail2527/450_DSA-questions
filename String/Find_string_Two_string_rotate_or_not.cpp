#include<bits/stdc++.h>
using namespace std;

bool solve(string str1,string str2){
    if(str1.size() != str2.size()) {
        return false; 
    }
    string temp = str1 + str1;
    if(temp.find(str2) != string::npos){
        return true;
    }else{
        return false;
    }
}
int main(){
    string s1 = "abcd";
    string s2 = "cdab";
    if(solve(s1,s2)){
        cout<<"Yes"<<endl;
    }else{

        cout<<"No"<<endl;
    }
   return 0;
}