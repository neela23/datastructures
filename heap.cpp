#include<iostream>
using namespace std;
class Heap
{
	int arr[50];
	int size;
	public:
	Heap()
	{
		size = 0;
	}
	void heapUp(int);
	void heapDown(int);
	void buildHeap(int a[], int n);
	void insertIntoHeap(int);
	int deleteMax();
	void deleteElement(int);
	void heapSort();
	void displayHeap();
};

void swap(int arr[], int j, int k)
{
	int temp = arr[j];
	arr[j] = arr[k];
	arr[k] = temp;
}	

void Heap::insertIntoHeap(int element)
{
	arr[size++] = element;
	heapUp(size-1);
}
int Heap::deleteMax()
{
	if(size == 0)
		return -1;
	int temp = arr[0];
	arr[0] = arr[--size];
	heapDown(0);
	return temp;
}
void Heap::heapUp(int i)
{
	while(i > 0)
	{
		int parentIndex = (i-1)/2;
		if(arr[parentIndex] < arr[i])
		{
			swap(arr, parentIndex,i);
			i = parentIndex;
		}
		else
			break;
	}
}

void Heap::heapDown(int i)
{

	int left_child = 2*i + 1;
	int right_child = 2*i + 2;
	int max_child = 0;
	if(left_child < size && right_child < size)
		max_child = arr[left_child] > arr[right_child] ? left_child:right_child;
	else if(left_child < size)
		max_child = left_child;
	else if(right_child < size)
		max_child = right_child;
	if(max_child)
	{
		if(arr[i] < arr[max_child])
		{
			swap(arr, max_child, i);
			heapDown(max_child);
		}
	}
}
void Heap::buildHeap(int A[],int n)
{
	for(int i=0;i<n;i++)
		arr[i] = A[i];
	size = n;
	for(int i=2;i<n;i++)
		heapUp(i);
}
void Heap::heapSort()
{
	int actualSize = size;
	while(size-1)
	{
		swap(arr, 0, size-1);
		size--;
		heapDown(0);
	}
	size = actualSize;
}
void Heap::displayHeap()
{	
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
int main()
{
	Heap h;
	int arr[]={ 5, 6, 2, 8, 14, 3, 7,9,12, 4,10};
	h.buildHeap(arr, 11);
	h.displayHeap();
	//h.heapSort();
	//h.displayHeap();
	cout<<"Max Element:"<<h.deleteMax()<<"\n";
	h.displayHeap();
	h.insertIntoHeap(1);
	h.insertIntoHeap(50);
	h.displayHeap();
	return 1;
}
