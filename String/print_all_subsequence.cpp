#include<iostream>
using namespace std;

void solve(string input,string output){
    //base case 
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    solve(input.substr(1),input[0]+output);
    solve(input.substr(1),output);
}
int main(){
    string input = "abcd";
    string output = "";
    solve(input,output);
    return 0;
}