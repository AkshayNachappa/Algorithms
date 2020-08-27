#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minindex = i;
        for(int j =i+1;j<n;j++)
        {
            if(arr[minindex]>arr[j])
                minindex = j;
        }
        swap(&arr[i],&arr[minindex]);
    }
}

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    int *arr = new int[n];
    cout << "Enter the size of array: ";
    cin>>n;
    cout<<"\n Enter the "<<n<<" elements of the array \n";
    for(int i=0;i<50;i++)
        arr[i] = 50 -i;
    display(arr,50);
    selectionSort(arr,50);
    cout << "\n The sorted array is : \n";
    display(arr,50); 
    return 0;
}