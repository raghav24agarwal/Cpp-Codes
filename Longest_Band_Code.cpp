
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestBandCode(vector<int> v) {

    unordered_set<int> us;
    int n = v.size();
    int longest = 1;
    int count = 1;

    //preparing the set
    for(int ele: v) {
        us.insert(ele);
    }

    //if the current element can be the starting element of band
    for(auto ele: us) {
        int pre_ele = ele - 1;

        if(us.find(pre_ele)==us.end()){

            //this element can be the starting element
            int next_ele = ele + 1;
            count = 1;
            while(us.find(next_ele)!=us.end()) {
                count++;
                next_ele++;
            }

            if(count > longest) {
                longest = count;
        }
        }

        
    }

    return longest;

}

int main() {

    vector<int> v{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
    cout<<longestBandCode(v)<<endl;
	return 0;
}

