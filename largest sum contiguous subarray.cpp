// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int sum=0,maxint=INT_MIN;
	for(int i=0;i<size;i++)
	{
	    sum+=a[i];
	    if(maxint<sum)
	        maxint=sum;
	   if(sum<0)
	    sum=0;
	}
	return maxint;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = {-2, -3, -4, -3, -2, -2, -5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}
