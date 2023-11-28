
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rains(vector<int> v) {

    int n = v.size();

    if (n <= 2) {
        return 0;
    }

    vector<int> leftToRight(n, 0);  //initializing a vector of size n with all values 0
    vector<int> rightToLeft(n, 0);  //initializing a vector of size n with all values 0

    leftToRight[0] = v[0];
    rightToLeft[n-1] = v[n-1];

    int maxLeft = 0;
    int maxRight = 0;

    for (int i=0; i<n; i++) {
        maxLeft = max(maxLeft, v[i]);
        leftToRight[i] = maxLeft;
    }

    for (int i=0; i<n; i++) {
        cout<<leftToRight[i]<<" ";
    }

    cout<<endl;

    for (int i=n-1; i>=0; i--) {
        maxRight = max(maxRight, v[i]);
        rightToLeft[i] = maxRight;
    }

    for (int i=0; i<n; i++) {
        cout<<rightToLeft[i]<<" ";
    }

    cout<<endl;

    int result = 0;

    for(int i=0; i<n; i++) {
        int val = min(leftToRight[i], rightToLeft[i]) - v[i];
        result += val;
    }

    cout<<"result "<<result<<endl;

    return result;
}

int main() {
	
    vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rains(v);

	return 0;
}

