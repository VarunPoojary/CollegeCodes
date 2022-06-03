/*
Write a CPP program for collision handling in a hash table using linear probing without replacement and MOD as a hash function. 
12, 01, 04, 03, 07, 08, 10, 02, 05, 14 
*/

#include<iostream>
using namespace std;


void displayHashTable(int arr[])
{
    for(int i = 0;i<10;i++)
    cout<<arr[i]<<"  ";
    cout<<endl;
    cout<<endl;
}
int addToHashTable(int num, int arr[])
{
    int loadFactor = (num % 10);
    int start = loadFactor - 1;
    while(loadFactor != -1)
    {
        if(arr[loadFactor] == -1)
        {
            arr[loadFactor] = num;
            break;
        }
        else if (loadFactor == start)
        {
            loadFactor = -1;
            break;
        }
        else if(loadFactor == 9)
        {
            loadFactor = 0;
        }
        else
        {
            loadFactor++;
        }

    }
    displayHashTable(arr);
    return loadFactor;
}



int main()
{
    int arr[10];

    for(int i=0;i < 10 ; i++)
    arr[i]=-1;

    int num = 0;
    while(num!=-1)
    {
        cout<<"Enter Number:";
        cin>>num;
        cout<<endl;
        int check = addToHashTable(num,arr);
        if(check == -1)
        {
            cout<<"HashTable is Full"<<endl;
            num = -1;
        }
    }
    return 0;
}
