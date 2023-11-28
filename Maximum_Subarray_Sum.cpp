
#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> v) {

    int n = v.size();

    int two = 0;
    int result = 0;
    int value = 0;

    while(two <= n-1) {
        value = value + v[two];
        two++;
        if (value<=0) {
            value = 0;
        } 

        result = max(result, value);
        cout<<"res "<<result<<endl;
    }

    cout<<"res "<<result;
    return result;

}

int main() {
	
    vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
    maxSubarraySum(v);

	return 0;
}

