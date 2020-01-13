#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
long long max(long long a, long long b)
{
    return (a > b) ? a : b;
}
 
int min_low, max_high;
 
long long MaxCrossingSum(long long arr[100000], int low, int mid, int high)
{
	// Include elements having index value less than or equal to the mid.
	long long sum = 0, left_sum = 0;
	long long leftpartsum = -1;
	int i_idx = mid;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + (long long) arr[i];
		if (sum > leftpartsum)
			leftpartsum = sum;
		left_sum += arr[i];
	}
 
	// Include elements having index value greater mid.
	sum = 0;
	long long rightpartsum = -1, right_sum = 0;
	int j_idx = mid + 1;
	for (int i = mid + 1; i <= high; i++)
	{
		sum = sum + (long long) arr[i];
		if (sum > rightpartsum)
			rightpartsum = sum;
		right_sum += arr[i];
	}
 
	if (low == min_low && high == max_high && leftpartsum == left_sum && rightpartsum == right_sum) {
		return max(leftpartsum + (rightpartsum - arr[high]), rightpartsum + (leftpartsum - arr[0]));
	}
 
	// Return sum of elements on left and right of mid.
	return leftpartsum + rightpartsum;
}
 
// Returns sum of maxium subarray sum.
long long MaxSubArraySum(long long arr[], int low, int high)
{
	int mid;
	// If low index is equal to the high index h then the subarray contains only one element.
	if (low == high)
		return (long long) arr[low];
 
	// Otherwise find the mid index and proceed.
	mid = (low + high) / 2;
 
	// Maximum sum sub-array can be either in the left part, right part or covering elements from both parts.
	return max(max(MaxSubArraySum(arr, low, mid), MaxSubArraySum(arr, mid + 1, high)), MaxCrossingSum(arr, low, mid, high));
}
 
int main()
{
	int t;
	cin >> t;
	long long arr[100000];
	while (t--) {
		int n;
		cin >> n;
		int high = n - 1;
		int i = 0;
		long long total_sum = 0;
		while (n--) {
			long long input;
			cin >> input;
			arr[i] = input;
			i++;
			total_sum += input;
		}
		min_low = 0, max_high = high;
		long long max_subarray = MaxSubArraySum(arr, 0, high);
		if (total_sum > max_subarray) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}