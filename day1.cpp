#include<iostream>
using namespace std;
int* Two_Sum(int arr[],int n,int target){
    static int arr1[2];
        for(int i =0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((arr[i]+arr[j]) == target){
                    arr1[0] =i;
                    arr1[1] =j;
                     return arr1;
                } 
            }
        }
        return nullptr;
}
int main(){
    int n,target ;
    cout<<"Enter the total number : ";
    cin>>n;cout<<endl;
    cout<<"Target : ";
    cin>>target;cout<<endl;
    int arr[n];
    cout<<"Enter the array number : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    int *a = Two_Sum(arr,n,target);
     if (a != nullptr) {
        cout << "Indices of the two numbers that add up to the target: " << a[0] << " " << a[1] << endl;
    } else {
        cout << "No two numbers found that add up to the target." << endl;
    }
    return 0;
}