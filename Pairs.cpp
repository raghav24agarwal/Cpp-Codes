#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> pairs(vector<int> v, int Sum) {

    unordered_set<int> s;
    vector<int> result;

    for(int i=0;i<v.size();i++) {
        int x = Sum-v[i];
        if (s.find(x)!=s.end()) {
            result.push_back(v[i]);
            result.push_back(x);
            return result;
        }

        s.insert(v[i]);
    }

    return {};
}

int main() {
	
    vector<int> arr{10, 5, 2, 3, -6, 9, 11};
    int S=4;

    auto p = pairs(arr, S);
    if (p.size()==0) {
        cout<<"No such pair exist";
    } else {
        cout<<p[0]<<","<<p[1];
    }

    return 0;

}

