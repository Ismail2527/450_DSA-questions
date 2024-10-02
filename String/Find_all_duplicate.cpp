#include<bits/stdc++.h>
using namespace std;

void solve(string str){
    int n = str.size();
    stack<char> st;

    for (int i = 0; i < n - 1; i++) {  // Avoid out-of-bounds access
        if (str[i] == str[i + 1]) {
            char ch = str[i];

            // Ensure stack is not empty before calling st.top()
            if (st.empty() || st.top() != ch) {
                st.push(ch);
                cout << st.top() << endl;
            }
        }
    }
    cout << endl;
}
void print(string str){
    for(int i=0; i<str.size(); i++){
        cout<<str[i]<<" ";
    }
    cout<<endl;
}
int main(){
    string str = "Ismaaaiiil";
    cout<<"String size"<<str.size()<<endl;
    //print(str);
    sort(str.begin(),str.end());
    print(str);
    solve(str);

    return 0;
}