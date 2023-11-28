
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> housing(int *plots, int n, int k) {

    vector<pair<int, int>> result;

    int i = 0 ,j = 0;
    int area = 0;
    while(j<n) {
        area += plots[j];
        while(area > k and i < j) {
            area -= plots[i];
            i++;
        }
        if(area == k) {
            result.push_back({i, j});
        }
        j++;
    }

    return result;
}

int main() {
	
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots)/sizeof(int);
    int k = 8;

    vector<pair<int, int>> res;

    res = housing(plots, n, k);
    for(auto indices: res) {
        cout<<indices.first<<" "<<indices.second<<endl;
    }

	return 0;
}

