#include<iostream>
#include<fstream>
using namespace std;
int main(){
int n, temp, count=0;
cout<<"How many random number do you want to your txt file"<<endl;
cin>>n;
//Creating a txt file
ofstream outFile;
outFile.open("outFile.txt");
for(int i=0; i<n; i++)
outFile<<1+rand()%100<<endl;
outFile.close();
//Passing value from txt file
ifstream inFile("outFile.txt");
int arr[n];
for(int i=0; i<n; i++)
inFile>>arr[i];
inFile.close();
//Creating Insertion Sort
for(int i=0; i<n-1; i++){
if(arr[i]>arr[i+1]){
temp=arr[i];
arr[i]=arr[i+1];
arr[i+1]=temp;
count++;
if(i>0){
for(int k=i; arr[k]<arr[k-1]; k--){
if(k<=0)
break;
temp=arr[k];
arr[k]=arr[k-1];
arr[k-1]=temp;
count++;
}
}
}
}

//Inputting the sorted array
ofstream sorted;
sorted.open("Sorted.txt");
for(int i=0; i<n; i++)
sorted<<arr[i]<<"\t";
sorted.close();
return 0;
}
