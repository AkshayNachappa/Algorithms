#include<iostream>
using namespace std;

void insertSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n, arr[20];
    cout << "Enter the size of the array \n";
    cin >> n;
    cout << "Enter "<<n<<" no. of elements \n";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    insertSort(arr,n);
    cout << "The sorted array is \n";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<" ";
    }
    return 0;
}