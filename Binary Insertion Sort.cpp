#include <iostream>
using namespace std;

//for counting the comparisons
int count = 0;

//swap
void swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

//display array
void display_array(int arr[], int start, int end)
{
	for(int i = start; i < end; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

//custom binary search for insertion sort
int binary_search(int arr[], int start, int end, int number)
{
	if(start < end)
	{	
		int mid = (start + end)/2;
		count++;
		if(arr[mid] >= number)
		{
			return binary_search(arr,start, mid, number);
		}
		else if(arr[mid] < number)
		{
			
			return binary_search(arr,mid+1,end,number);
		}
		
	}
	return start;
}

//binary Insertion Sort
void binary_insertion_sort(int arr[], int start, int end)
{
	int key = 0;
	int m = 0;
	int swaps = 0;
	for(int i = start+1; i < end; i++)
	{
		key = arr[i];
		m = binary_search(arr,start,i,key);
		for(int j = i; j > m; j--)
		{
			swap(arr[j],arr[j-1]);
			swaps++;
		}
	}
	cout<<"Total Swaps are "<<swaps<<"\n";
}


int main()
{
	int arr[8] = {8,7,6,5,4,3,2,1};
	binary_insertion_sort(arr,0,4);
	cout<<"Total comparisons are "<<count<<"\n";
	display_array(arr,0,4);
}
