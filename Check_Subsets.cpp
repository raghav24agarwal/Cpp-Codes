#include<iostream>
using namespace std;

bool checkSubsets(string s1, string s2) {

    int n1 = s1.length() - 1;
    int n2 = s2.length() - 1;

    while(n1>=0 and n2>=0) {
        if(s1[n1] == s2[n2]) {
            n1--;
            n2--;
        } 
        else {
            n1--;
        }
    }

    if(n2 == -1) {
        return true;
    }

    return false;
}

int main() {
    string s1 = "Coding Minutes";
    string s2 = "Cines";

    bool res = checkSubsets(s1, s2);
    cout<<"Result is "<<res;
    return 0;
}

