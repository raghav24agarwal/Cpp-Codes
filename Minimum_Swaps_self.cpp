#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int minSwaps(vector<int> A) {

    //we need to identify a cycle of elements involved in swapping
    //The no of swaps = elements involved in cycle-1

    int n = A.size();


    vector<pair<int, int>> B(n);

    for(int i=0; i<n; i++) {
        B[i].first = A[i];
        B[i].second = i;
    }

    sort(B.begin(), B.end(), compare);

    // for(int i=0; i<n; i++) {
    //     cout<<"fir "<<B[i].first;
    //     cout<<" sec "<<B[i].second<<endl;
    // }

    vector<bool> visited(n, false);

    int swaps = 0;
    for(int i=0; i<n; i++) {

        int cycleElements = 0;

        while(visited[i]==false and i != B[i].second) {
            //cout<<"i "<<i<<" B[i] "<<B[i].first<<" "<<B[i].second<<endl;
            visited[i] = true;
            i = B[i].second;
            cycleElements += 1;
        }
        //cout<<"cycleElements "<<cycleElements<<endl;

        if(cycleElements != 0) {

            swaps = swaps + (cycleElements-1);
        }
    }

    return swaps;
    
}

int main() {
	
    vector<int> v{5,4,3,2,1};
    int res = minSwaps(v);
    cout<<"Result "<<res;

	return 0;
}

