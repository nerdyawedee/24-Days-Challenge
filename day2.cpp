# include<iostream>
# include<climits>
using namespace std;
int Max_Subarray(int arr[],int n){
    int sum = 0 ,maxSum = INT_MIN;
    if(n == 1){
        return arr[0];
    }
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(maxSum<sum){
            maxSum = sum;
        } 
        if(sum<0){
            sum =0;
        }
    }
    return maxSum;
}
int main(){
    int n;
    cout<<"Enter Number of ele : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s = Max_Subarray(arr,n);
    cout<<s<<endl;
}