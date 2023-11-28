// Sample Input
// 3
// 92 022
// 82 12
// 77 13
// 2 false numeric

// Sample Output
// 82 12
// 77 13
// 92 022



#include <iostream>
#include<vector>
#include <algorithm>
#include<cstring>
using namespace std;

string strTokeniser(string input, int key) {

    char *ch = strtok((char *)input.c_str(), " ");
    while(key>1) {
        ch = strtok(NULL, " ");
        key--;
    }

    return string(ch);

}

int convertToInt(string num) {
    int res = 0;
    int multiplier = 1;

    int len = num.length();
    for(int i=len-1; i>=0; i--) {
        res += ((num[i] - '0') * multiplier);
        multiplier *= 10;
    }

    return res;
}

bool numericCompare(pair<string, string> p1, pair<string, string> p2) {

    return convertToInt(p1.second) < convertToInt(p2.second);
}

bool lexicoCompare(pair<string, string> p1, pair<string, string> p2) {
    return p1.second < p2.second;
}

int main() {
	
    int n;
    cin>>n;
    cout<<"Size is "<<n<<endl;

    cin.get();

    vector<string> input;
    for(int i=0; i<n; i++) {
        string ins;
        getline(cin, ins);
        input.push_back(ins);
    }

    cout<<"Given Input "<<endl;
    // for(auto str: input) {
    //     cout<<str<<endl;;
    // }

    int key;
    string reversed,comp;

    cin>>key>>reversed>>comp;

    // cout<<"Key is "<<key<<endl;
    // cout<<"Reversed is "<<reversed<<endl;
    // cout<<"Comparison is "<<comp<<endl;


    // Step 1. Tokenising the string and extracting the key separately
    vector<pair<string, string>> modified;
    for(int i=0; i<n; i++) {
        string temp = strTokeniser(input[i], key);
        modified.push_back({input[i], temp});
    }

    // for(auto ins: modified) {
    //     cout<<ins.first<<" "<<ins.second<<endl;
    // }

    // Step 2. Sorting the keys based on the key token extracted
    // if comparison is numerical
    if(comp == "numeric") {
        sort(modified.begin(), modified.end(), numericCompare);
    } 
    else {
        sort(modified.begin(), modified.end(), lexicoCompare);
    }

    // Step 3. Reverse is true or false
    if(reversed == "true") {
        reverse(modified.begin(), modified.end());
    }

    cout<<"Final Output "<<endl;
    for(auto str: modified) {
        cout<<str.first <<endl;
    }

	return 0;
}

