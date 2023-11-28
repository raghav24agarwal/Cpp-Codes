#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> triplets(vector<int> v, int Sum) {

    vector<vector<int>> result;

    int n = v.size();
    sort(v.begin(), v.end());

    for(int i=0;i<=n-3;i++) {
        int start = i+1;
        int end = n-1;

        while(start < end) {
            if ( (start+end) == (Sum-v[i]) ) {
                result.push_back({v[i],start,end});
                start++;
                end--;
            } else if ( (start+end) < (Sum-v[i]) ) {
                start++;
            } else {
                end--;
            }
        }
    }

    return result;

}


int main() {
	
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int S = 18;

    auto result = triplets(v, S);

    for (auto v: result) {
        for (auto no: v) {
            cout<<no<<",";
        }
        cout<<endl;
    }

	return 0;
}

