
#include <iostream>
#include <cstring>
using namespace std;

void replaceString(char *input) {

    int n = strlen(input);
    int blank = 0;

    for(int i=0; i<n; i++) {
        if(input[i] == ' ') {
            blank++;
        }
    }

    int extraSpaces = n + (2*blank);
    
    input[extraSpaces] = '\0';


    for(int i=n-1; i>=0; i--) {
        if(input[i] == ' ') {
            input[extraSpaces-1] = '0';
            input[extraSpaces-2] = '2';
            input[extraSpaces-3] = '%';
            extraSpaces -= 3;
        } else {
            input[extraSpaces-1] = input[i];
            extraSpaces--;
        }
    }
}

int main() {

    char input[10000];
    cin.getline(input, 1000);
    replaceString(input);
    cout<<input<<endl;
	// your code goes here
	return 0;
}

