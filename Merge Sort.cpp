#include <iostream>
using namespace std;

//It was relatively hard to code


//display array
void display_array(int arr[], int start, int end)
{
	for(int i = start; i < end; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

//Merge function
void merge(int arr[], int start,int mid, int end)
{
	//display_array(arr,start,end);
	int l = mid-start + 1;
	int m = end- mid;
	int temp1[l],temp2[m];
	for(int i = 0; i < l;i++)
	{
		temp1[i] = arr[start + i];
	}
	for(int j = 0; j < m;j++)
	{
		temp2[j] = arr[mid + 1 + j];
	}
	int p = 0;
	int q = 0;
	int r = start;
	while(p < l && q < m)
	{
		
		if(temp1[p] >= temp2[q])
		{
			arr[r] = temp2[q];
			q++;
		}
		else
		{
			arr[r] = temp1[p];
			p++;
		}
		r++;
	}
	while(p < l)
	{
		arr[r] = temp1[p];
		r++;
		p++;
	}
	while(q < m)
	{
		arr[r] = temp2[q];
		r++;
		q++;
	}
}

//The official algorithm
void mergesort(int arr[], int start, int end)
{
	if(start < end)
	{
		int mid = start + (end - start)/2;
		mergesort(arr,start, mid);
		mergesort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

int main()
{
	int arr[5] = {5,4,3,2,1};
	mergesort(arr,0,4);
	display_array(arr,0,5);
}
