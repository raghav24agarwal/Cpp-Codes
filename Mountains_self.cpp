
#include <iostream>
#include <vector>
using namespace std;

int mountains(vector<int> v) {

    int n = v.size();
    int count = 0;
    int length = 1;
    int i = 0;

    while(i < n-1) {
        while(i<n-1 and v[i+1] > v[i]) {
            cout<<"One"<<v[i]<<endl;
            length++;
            i++;
        }
        while(i<n-1 and v[i+1] < v[i]) {
            cout<<"two"<<v[i]<<endl;
            length++;
            i++;
        }
        
        cout<<"len"<<length<<endl;

        if(length > count) {
            count = length;
        }
            length = 1;
        
        cout<<"count"<<count<<endl;

    }

    return count;

}


int main() {

    vector<int> v{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

    int result = mountains(v);
    cout<<"result "<<result;
	// your code goes here
	return 0;
}

