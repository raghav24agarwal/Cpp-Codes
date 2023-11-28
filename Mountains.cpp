
#include <iostream>
#include <vector>
using namespace std;

int mountains(vector<int> v) {
    int n = v.size();
    int largest = 0;

    for(int i=1;i<=n-2;) {

        //check v[i] is peak or not
        if(v[i-1]<v[i] and v[i]>v[i+1]) {
            int count = 1;
            int j = i;

            //count backwards (left)
            while(j>=1 and v[j]>v[j-1]) {
                count++;
                j--;
            }

            //count forwards (right)
            while(i<=n-2 and v[i]>v[i+1]) {
                count++;
                i++;
            }

            largest = max(largest, count);

        } else {
            i++;
        }
        
        
    }
        
    return largest;
}

int main() {

    vector<int> v{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
    cout<<mountains(v)<<endl;

	return 0;
}

