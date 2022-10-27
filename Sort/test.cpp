#include<iostream>
using namespace std;

int calc(int arr[], int n)
{
    int bargain = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]-(n+1)>2)
        {
            cout<<"Too chaotic"<<endl;
            return 0;
        }
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i])
                bargain++;
        }
    }
    cout<<bargain<<endl;
    return 0;
}
int main()
{
    int t,n,bargain;
    int *arr = new int[n];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>arr[j];
        calc(arr,n);
    }
    return 0;

}