#include <iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp =x;
    x=y;
    y=temp;
}
void selectionSort(int *arr,int size)
{
    int minIndex=0;
    //int iteration=0;
    for(int counter =0;counter<size-1;counter++)
    {
        minIndex=counter;
        for(int index=minIndex+1;index<size;index++)
        {
            if(arr[index]<arr[minIndex])
            {
                minIndex=index;
            }
            //iteration++;
        }
        swap(arr[counter],arr[minIndex]);
    }
    //cout<<"Selection Sort : No of Iteration = "<<iteration<<endl;
}
int binarySearch(int *arr , int size, int item)
{
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    while (start<=end)
    {
        if(arr[mid]==item)
        {
            return mid;
        } else if(arr[mid]>item)
        {
            end = mid-1;
        }
        else if(arr[mid]<item)
        {
            start= mid+1;
        }
    }
    return -1;

}
int* found = new int [5];
int linearSearch(int *arr, int s, int item)
{
    int counter=0;
    for(int i=0;i<s;i++)
    {
        if(arr[i]==item)
        {
            found[counter]= i;
            counter++;
        }
    }
    if(counter >0)
    {
        return counter;
    }
    else
    {
        counter=-1;
        return counter;
    }
}

void display (int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout << arr[i] <<"\t";
    }
    cout <<endl;
}
int main() {
    int s;
    cin >> s;
    int arr1[s];
    for(int i=0;i<s;i++)
    {
        cin >> arr1[i];
    }
    display(arr1,s);
    int item;
    cin >> item;
    int index = linearSearch(arr1,s,item);
    if(index == -1)
    {
        cout<<"Item : " <<item << " NOT FOUND\n";
    }
    else
    {
        cout<<"Item : " <<item << " FOUND AT INDEX : ";
        for (int i = 0; i < index; i++)
        {
            cout << found[i] <<"   ";
        }
        cout <<endl;
    }
    selectionSort(arr1,s);
    display(arr1,s);
    int item2;
    cin >> item2;
    int element = binarySearch(arr1,s,item2);
    if(element == -1)
    {
        cout<<"Item : " <<item << " NOT FOUND\n";
    }
    else
    {
        cout<<"Item : " <<item << " FOUND AT INDEX : " <<element;
    }
    delete [] found;
    return 0;
}
