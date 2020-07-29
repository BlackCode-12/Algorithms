#include <iostream>
using namespace std;

int binary_search(int arr[],int begi, int end,int search)
{
	if(begi < end)
	{
		int mid = (begi + end)/2;
		if(arr[mid] == search)
		{
			return mid;
		}
		else if(arr[mid] > search)
		{
			return binary_search(arr,begi,mid,search);	
		}
		else if(arr[mid] < search)
		{
			return binary_search(arr,mid,end,search);
		}	
	}
	return -1;
}

int binary_search_peak(int arr[],int start,int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		if(mid == start)
		{
			if(arr[mid] > arr[mid+1])
			{
				return mid;
			}
		}
		else if(mid == end)
		{
			if(arr[mid] > arr[mid-1])
			{
				return mid;
			}
		}
		else{
			if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
			{
				return mid;
			}
			else if(arr[mid] < arr[mid-1])
			{
				return binary_search_peak(arr,start,mid);
			}
			else if(arr[mid] < arr[mid + 1])
			{
				return binary_search_peak(arr,mid,end);
			}
		}
	}
}

//This is for 2D now
//I will add notes so that you understand the algorithms better.
int find_max(int arr[][100], int row_size,int col)
{
	int max  = arr[0][col];
	for(int i =0; i < row_size; i++)
	{
		if(max <= arr[i][col])
		{
			max = arr[i][col];
		}
	}
	int s = 12;
	return max;
}

int peak_twoD(int arr[][100],int row_start,int col_start, int row_end,int col_end)
{
	int mid_col = (col_start + col_end)/2;
	int max  = arr[0][mid_col];
	int index = 0;
	for(int i =0; i < row_end; i++)
	{
		if(max <= arr[i][mid_col])
		{
			max = arr[i][mid_col];
			index = i;
		}
	}
	if(max > arr[index][mid_col-1] && max > arr[index][mid_col + 1])
	{
		return max;
	}
	else if(max < arr[index][mid_col-1])
	{
		return peak_twoD(arr,row_start,col_start,row_end,mid_col);
	}
	else if(max < arr[index][mid_col+1])
	{
		return peak_twoD(arr,row_start,mid_col,row_end,col_end);
	}
	
	
}

int main()
{
	int arr[100][100] = {{10,8,10,10},{14,13,12,11},{15,9,11,21},{16,17,19,20}};
	int m = peak_twoD(arr,0,0,4,4);
	cout<<m;
	
}
