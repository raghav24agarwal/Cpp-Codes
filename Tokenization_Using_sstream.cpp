
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

    string input;
    getline(cin, input);

    //creating a string stream object and passing input string in it.
    stringstream ss(input);
	
    string token;
    vector<string> tokens;

    while(getline(ss, token, ' ')) {    //space is delimiter here
        tokens.push_back(token);
    }

    for(auto toke: tokens){
        cout<<toke<<endl;
    }
	return 0;
}

