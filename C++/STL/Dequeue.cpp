/*
 * Use a dequeue to solve a sliding max window problem
 */
#include <iostream>
#include <deque> 
using namespace std;

/*
 * Example to show how code works
 * arr[10, 5, 4, 6, 1, 7] and k = 3
 * 
 * Step 0: - Dequeue is empty
 *         - Push index 0 to the back of the queue
 *         - {0}
 * Step 1: - 5 is less than 10 so just push index 2
 *         - {0, 1}
 * Step 2: - 4 is less than 5 so push index 2
 *         - Processed 3(k) elements so print 10(max of sub-array)
 *         - {0, 1, 2}
 * Step 3: - Index 0 is out of range (pop it)
 *         - 6 is greater than 4 and 5 so pop indecies 1 and 2
 *         - Push index 3
 *         - Processed sub-array 1,2,3 so print 6(max of sub-array)
 *         - {3}
 * Step 4: - Index 1 is out of range, but already popped
 *         - 1 is not greater than 6 so just push index 4
 *         - Processed sub-array 2,3,4 so print 6(max of sub-array)
 *         - {3, 4}
 * Step 5: - Index 2 is out of bounds, but already popped
 *         - 7 is greater than 1 and 6 so pop indecies 3 and 4
 *         - push index 5
 *         - Processed sub-array 3,4,5 so print 7(max of sub-array)
 */

void printKMax(int arr[], int n, int k){
	//Write your code here.
    // Keep the max of each sub-array at the back of the dequeue
    deque<int> dq;
    
    // Moves through array and tracks beginning of sub-array
    for (int i = 0; i < n; i++) {
        // Pop index that is outside of the sub-array range
        if (!dq.empty() && dq.front() == (i - k))
            dq.pop_front();
            
        // If current element is larger than the element at the back of the queue
        // pop that element b/c it can't be the max in the current or future iterations
        while(!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();
        
        // Add current index into the back dequeue
        dq.push_back(i);
        
        // Print the stored max after processing k elements
        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }
    // Make sure next print is on its own line
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
