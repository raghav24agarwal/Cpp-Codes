
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//helper function
//to find out if an element is out of sorted order
bool outOfOrder (vector<int> arr, int index) {

    int n = arr.size();

    if (index == 0) {
        return arr[index] > arr[index+1];
    } else if (index == n-1) {
        return arr[index] < arr[index-1];
    } else {
        return arr[index] > arr[index+1] or arr[index] < arr[index-1];
    }
}

//finding smallest and largest element which are unsorted
pair<int, int> subarraySort(vector<int> v) {

    int n = v.size();

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i=0; i<n; i++) {
        if(outOfOrder(v, i)) {
            smallest = min(smallest, v[i]);
            largest = max(largest, v[i]);
        }
    }

    if (smallest == INT_MAX) {
        return {-1, -1};
    }

    cout<<"smallest "<<smallest<<endl;
    cout<<"largest "<<largest<<endl;

    //finding correct positions of smallest and largest values

    int left = 0;
    int right = n-1;

    while (smallest >= v[left]) {
        left++;
    }

    while (largest <= v[right]) {
        right--;
    }

    cout<<"left "<<left<<" right "<<right<<endl;

    return {left, right};
}

int main() {
	
    vector<int> v{1,2,3,4,5,8,7,6,9,10,11};

    auto p = subarraySort(v);
    cout<<p.first<<" "<<p.second;

	return 0;
}

