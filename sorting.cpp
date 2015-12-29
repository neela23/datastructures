#include<iostream>
using namespace std;

void displayArray(int arr[], int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
}
void swap(int arr[], int j, int k)
{
	int temp = arr[j];
	arr[j] = arr[k];
	arr[k] = temp;
}
void selectionSort(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
				swap(arr,i,j);	
		}
	}
}

void bubbleSort(int arr[], int n)
{
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(arr[j-1]>arr[j])
				swap(arr,j-1,j);
		}
	}
}

void insertionSort(int arr[], int n)
{
	for(int i=2;i<n;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(arr[j-1]>arr[j])
				swap(arr,j-1,j);
			else
				break;
		}
	}
}
// Quick sort
int partition(int arr[],int start, int end)
{
	int pivot = start;
	start = start+1;
	while(start < end)
	{
		while(arr[start] < arr[pivot])
			start++;
		while(arr[end] > arr[pivot])
			end--;
		if(start < end)
			swap(arr,start,end);
	}
	swap(arr,end,pivot);
	return end;
}
void quickSort(int arr[], int start, int end)
{
	if(start < end)
	{
		int p = partition(arr,start,end);
		quickSort(arr,start,p-1);
		quickSort(arr,p+1,end);
	}
}
//merge Sort

void merge(int arr[],int start,int end,int B[])
{
	int mid = (start+end)/2;
	int i = start;
	int j = mid+1;
	int k = start;
	int size = end-start+1;

	while(i<=mid && j<=end)
	{
	
		if(arr[i]<arr[j])
		{
			B[k++] = arr[i++];
		}
		else
		{
			
			B[k++] = arr[j++];
		}
	}
	while(i<=mid)
	{
			B[k++] = arr[i++];
	}
	while(j<=end)
	{
		B[k++] = arr[j++];
	}
	for(i=0;i<=size;i++)
	{
		arr[end] = B[end];
		end--;
	}
}
void mergeSort(int arr[],int start,int end,int B[])
{
	if(start < end)
	{
		int mid = (start+end)/2;
		mergeSort(arr,start,mid,B);
		mergeSort(arr,mid+1,end,B);
		merge(arr,start,end,B);
	}
}

int main()
{
	int arr[] = {6,4,8,9,13,16,5,3,2};
	int B[50];
	int n = 9;
	displayArray(arr,n);
	mergeSort(arr,0,n-1,B);
	displayArray(B,n);
	return 1;
}
