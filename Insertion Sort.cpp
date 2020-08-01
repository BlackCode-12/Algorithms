#include <iostream>
using namespace std;

//swapping
void swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

//display the array
void display(int arr[], int start, int end)
{
	for(int i = start; i < end; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

//Insertion Sort
void insertion_sort(int arr[], int start, int end)
{
	int swapps = 0;
	int key = 0;
	int comp = 0;
	for(int i =start; i <end; i++)
	{
		key = arr[i];
		for(int j = i-1; j >= start; j--)
		{
			if(key < arr[j])
			{
				swap(arr[j+1],arr[j]);
				swapps += 1;
			}
			comp++;
		}
		cout<<"Array after "<<i<<" Steps is";
		display(arr,0,i+1);
	}
	cout<<"Total swapps are:"<<swapps<<"\n";
	cout<<"Total comparisons are:"<<comp<<"\n";
}


int main()
{
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	display(arr,0,10);
	insertion_sort(arr,0,10);
	display(arr,0,10);
}
