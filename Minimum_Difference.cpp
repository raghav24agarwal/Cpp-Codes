
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> minDifference(vector<int> a, vector<int> b) {

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int one = 0;
    int two = 0;
    int minDiff = INT_MAX;
    pair<int, int> p;

    while(one < a.size() and two < b.size()) {
        int diff = abs(a[one] - b[two]);
        
        if (diff < minDiff) {
            p.first = a[one];
            p.second = b[two];
            minDiff = diff;
            //cout<<"fir "<<p.first<<" sec "<<p.second<<endl;
        }

        //cout<<"diff "<<diff<<endl;

        if (a[one] <= b[two] and one < a.size()) {
            one++;
        } else if (two < b.size()) {
            two++;
        }

    }

    return p;

}

int main() {
	
    vector<int> v1{23, 5, 10, 17, 30};
    vector<int> v2{26, 134, 135, 14, 19};

    pair<int, int> res = minDifference(v1, v2);
    cout<<"first "<<res.first<<" second "<<res.second;

	return 0;
}

