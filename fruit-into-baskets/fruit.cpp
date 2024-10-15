//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n = arr.size();
        int l = 0, mxlen = 0;
        map < int,int>frq;
        for(int i = 0; i < n; i++) {
            frq[arr[i]]++;
            if(frq.size() > 2) {
                while(frq.size() > 2) {
                    frq[arr[l]]--;
                    if(frq[arr[l]] == 0) {
                        frq.erase(arr[l]);
                        l++;
                        break;
                    }
                    l++;
                }
            }
            if(frq.size() <= 2) mxlen = max(mxlen,i-l+1);
        }
        return mxlen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends