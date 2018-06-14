// C++ program to find Maximum difference
// between two elements such that larger
// element appears after the smaller number
#include <bits/stdc++.h>
using namespace std;

/* The function assumes that there are
at least two elements in array. The
function returns a negative value if the
array is sorted in decreasing order and
returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size)
{
	// Maximum difference found so far
	int min1=0,diff=-1;
	int i;
	for(i=1;i<arr_size;i++)
	{
	    if(arr[i]>=arr[min1])
	    {
	        diff=max(diff,(arr[i]-arr[min1]));
	    }
	    else
	        min1=i;
	}
	return diff;
}

/* Driver program to test above function */
int main()
{
int arr[] = {11, 2};
int n = sizeof(arr) / sizeof(arr[0]);

// Function calling
cout << "Maximum difference is " << maxDiff(arr, n);

return 0;
}
