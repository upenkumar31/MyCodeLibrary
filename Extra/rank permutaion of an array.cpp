#include <bits/stdc++.h>
using namespace std;
int rnk;
void permuteArray(int *arr,int i,int n)
{
	if(i==n)
	{
		cout<<"rank: "<<rnk<<" ";
		rnk++;
		cout<<"purmuted arr: ";
		for(int j=0;j<n;j++)
		cout<<arr[j]<<" ";
		cout<<endl;
	}
	else
	{
		for(int j=i;j<n;j++)
		{
			swap(arr[i],arr[j]);
			permuteArray(arr,i+1,n);
			swap(arr[i],arr[j]);
		}
	}
}
int main() {
	int arr[] = {2,3,6,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	rnk=1;
	sort(arr,arr+n);
	permuteArray(arr,0,n);
	return 0;
}