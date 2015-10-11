#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void binarySearch(ifstream& input){
	//parse the necessary information from the txt, first being the size of list
	string size;
	getline(input,size);
	int intSize = atoi(size.c_str());
	//cout<<"Length of list: "<<intSize<<endl;
	
	//second, the list itself
	string list;
	int myList[intSize];
	int num;
	int count=0;
	while(count<intSize){
		//handle end of line, where the next char is not a space
		if(count==intSize-1){
			getline(input,list,'\n');
			num = atoi(list.c_str());
			myList[count]=num;
			break;
		}
		else{
			getline(input, list, ' ');
			num = atoi(list.c_str());
			myList[count]=num;
			count++;
		}
	}
	/*
	cout<<"List: ";
	for(int i=0; i<intSize; i++){
		cout<<myList[i]<<", ";
	}
	*/
	//and third, what we're searching for
	string temp;
	getline(input, temp);
	int target = atoi(temp.c_str());
	//cout<<endl<<"Target: "<<target<<endl;
	
	//search within list:
	int i=0;
	int j=intSize;
	int guess = 0;
	int iterations = 0;
	bool success = false;
	while (i<=j){
		guess=(i+j)/2;
		if(myList[guess] > target){
			j=guess-1;
			iterations++;
		}
		else if(myList[guess] < target){
			i=guess+1;
			iterations++;
		}
		else{
			//found it!
			iterations++;
			cout<<myList[guess]<<" "<<iterations<<endl;
			success=true;
			break;
		}
	}
	if(!success){
	cout<<"Not Found "<<iterations<<endl;
	}
	return;
}

int main() {
	ifstream input;
	input.open("hw3.txt");
	string cases;
	//assuming the cases line will always be in the format: Cases: #
	getline(input, cases, ' ');
	getline(input, cases);
	int intCases = atoi(cases.c_str());
	for (int i=0; i<intCases; i++){
		binarySearch(input);
	}
	input.close();
return 0;	
}
