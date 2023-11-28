
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string s1, string s2) {
    if(s1.length() == s2.length()) {
        return s1 < s2;
    }

    return s1.length() < s2.length();
}

void sortSubsequences(string input, string output, vector<string> &result) {

    //Base case
    if(input.length() == 0) {
        result.push_back(output);
        return;
    }


    //Recursive calls
    char ch = input[0];
    sortSubsequences(input.substr(1), output+ch, result);
    sortSubsequences(input.substr(1), output, result);

}

int main() {
	
    string input = "abcd";
    vector<string> result;
    sortSubsequences(input, "", result);

    cout<<"Before Sorting "<<endl;
    for(auto str: result) {
        cout<<str<<",";
    }

    cout<<endl;

    sort(result.begin(), result.end(), compare);

    cout<<"After Sorting "<<endl;
    for(auto str: result) {
        cout<<str<<",";
    }
	return 0;
}

