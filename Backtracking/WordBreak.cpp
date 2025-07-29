#include <bits/stdc++.h>
using namespace std;
map<string, int> dict;

void wordBreak(string sentence , int index, vector<string> & ans, string words) {
    if(index  == sentence.length()) {
        ans.push_back(words);
        return;
    }
    for(int i = index; i< sentence.length();i++) {
        string s = sentence.substr(index, i-index+1);
        if(dict.count(s)) {
            wordBreak(sentence, i+1, ans, words + s + " ");
        }
    }
}
int main() {   
    int n; cin >> n;

    for(int i=0;i<n;i++) {
        string s; cin >> s;
        dict[s]++;
    }

    string sentence; cin >> sentence;

    vector<string> ans;

    wordBreak(sentence, 0, ans, "");

    for(string s : ans) cout << s << endl;
    
    return 0;
}
