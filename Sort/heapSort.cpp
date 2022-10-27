
#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[],int n,int i)
{
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left<n && arr[left]>arr[largest] )
		largest = left;
	
	if(right<n && arr[right]>arr[largest] )
		largest = right;
	
	if(i!=largest)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[],int n)
{
	for(int i = n/2-1;i>=0;i--)
		heapify(arr,n,i);
	
	for (int i = n-1; i>0; i--)
	{
		swap(arr[i],arr[0]);
		heapify(arr,i,0);
	}
	
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int n;
	int *arr = new int[n];
	cout<< "Enter the size of the array \n";
	cin >> n;
	cout << "Enter the elements of the array \n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<endl;
	heapSort(arr,n);
	display(arr,n);

	return 0;
}