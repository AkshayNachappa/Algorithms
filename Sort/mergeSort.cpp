#include<iostream>
using namespace std;
void merge(int arr[],int low,int high,int mid);
void mergeSort(int arr[],int low, int high)
{
    int mid = (low+high)/2;
    if(low<high)
    {
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr,low,high,mid);
    }
}

void merge(int arr[],int low,int high,int mid)
{
    int i=low, j=mid+1, k=low;
    int c[50];

    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
        
    }
    while(i<=mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
        arr[i] = c[i];
}

int main()
{
    int arr[10]; int n;
    cout << "Enter the no. of elements \n";
    cin >> n;
    cout << "Enter "<<n<<" no. of elements \n";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    cout << "The sorted array is \n";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<"\t";
    }
    return 0;
}