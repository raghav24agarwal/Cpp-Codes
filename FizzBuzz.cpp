#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    
    vector<string> str;

	for(int i=1;i<n;i++) {
		if(i%15==0) {
			str.push_back("FizzBuzz");
		} else if (i%5==0) {
			str.push_back("Buzz");
		} else if (i%3==0) {
			str.push_back("Fizz");
		} else {
			str.push_back(to_string(i));
		}
	}
    
    return str;
    
}

int main() {

	vector<string> fizz = fizzbuzz(15);
	for(string st : fizz) {
		cout<<"ele"<<st<<" ";
	}
	return 1;
}