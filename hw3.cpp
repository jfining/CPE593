#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void binarySearch(ifstream& input){
	//parse the necessary information from the txt, first size of list
	string size;
	getline(input,size);
	if (size.find("Cases") != string::npos){
		getline(input,size);
	}
	int intSize = atoi(size.c_str());
	cout<<"Length of list: "<<intSize<<endl;
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
	
	cout<<"List: ";
	for(int i=0; i<intSize; i++){
		cout<<myList[i]<<", ";
	}
	//and third, what we're searching for
	string temp;
	getline(input, temp);
	int target = atoi(temp.c_str());
	cout<<endl<<"Target: "<<target<<endl;
	
	//now we actually do the search
	//handle case for target outside the bounds
	//(preferred but doesn't produce "NOT FOUND 5" for the second trial)
	/*
	if(target > myList[intSize-1] || target < myList[0]){
		cout<<"Target is outside bounds of the list!"<<endl;
		return;
	}
	*/
	
	//search within list:
	int i=0;
	int j=intSize;
	int guess = 0;
	int iterations = 1;
	bool success = 0;
	while (i<j){
		//infinite loop when i=1 and j=2 and neither are the target
		//i would get set to 1 each time when list[1]<target
		if(i==j-1 && myList[i]!=target && myList[j]!=target){
			break;
		}
		//cout<<"i= "<<i<<" j= "<<j<<endl;
		//cout<<"iterations: "<<iterations<<endl;
		guess=(i+j)/2;
		//cout<<"first if"<<endl;
		if(myList[guess] > target){
			j=guess;
			iterations++;
		}
		else if(myList[guess] < target){
			i=guess;
			iterations++;
		}
		else{
			//found it!
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
	string output = "";
	input.open("hw3.txt");
	binarySearch(input);
	binarySearch(input); //investigate NOT FOUND 6 instead of 5
	binarySearch(input);
	input.close();

	
return 0;	
}
