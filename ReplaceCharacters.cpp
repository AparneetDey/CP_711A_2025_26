#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int fact(int n) {
    int f = 1;
    while(n>0) {
        f *= n;
        n--;
    }
    return f;
}

string replaceCharacter(string s, int n) {
    string res = s;
    int minPerm = fact(n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            string temp = s;
            unordered_map<char, int> mp; 
            temp[i] = s[j];
            int count = temp.size();
            for(int k=0; k<temp.size(); k++) {
                mp[temp[k]]++;
            }
            int per = fact(count);
            for (auto &p : mp) {
                per = per/fact(p.second);
            }
            if(per<minPerm) {
                res = temp;
                minPerm = per;
            }
        }
    }

    return res;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        string res = replaceCharacter(s, n);
        cout<<res<<endl;
    }
    return 0;
}