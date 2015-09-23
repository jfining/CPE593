#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void quickSort(int x[], int left, int right){
	//choose middle element for pivot
	int pivot = x[(left+right)/2];
	//initialize i and j to the ends of the array
	int i=left;
	int j=right;
	//temporary int for swapping the values
	int temp;
	while(i<=j){
		while(x[i] < pivot){
			i++;
		}
		while(x[j] >pivot){
			j--;
		}
		if(i<=j){
			temp=x[i];
			x[i]=x[j];
			x[j]=temp;
			i++;
			j--;
		}
	}
	if(left<j){
		quickSort(x, left, j);
	}
	if(i<right){
		quickSort(x, i, right);
	}
}


int main(){
	//open file
	ifstream input;
	input.open("HW2.txt");
	
	//get the first line (number of elements)
	string size;
	getline(input, size);
	int intSize = atoi(size.c_str());
	
	//get the next line and parse it for numbers, then add to array
	string list;
	int count=0;
	int myList[intSize];
	while(getline(input, list, ' ')){
		int num = atoi(list.c_str());
		myList[count]=num;
		count++;
	}
	
	//show the list before sorting
	cout<<"Input: ";
	for(int i=0; i<intSize; i++){
		cout<<myList[i]<<", ";
	}
	cout<<endl;
	
	//perform quicksort
	quickSort(myList, 0, 10);
	
	//show sorted list
	cout<<"Output: ";
	for (int i=0; i<intSize; i++){
		cout<<myList[i]<<", ";
	}
	
	return 1;
	
}
