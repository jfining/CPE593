#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;

class GrowArray {
private:
	int* p;
	int used;
	int size;
	// double in size
	void grow() {
		int* temp = p;
		size = size*2;
		p = new int[size];
		for (int i=0; i<used; i++){
			p[i] = temp[i];
		}
		delete [] temp;
	}
public:
	GrowArray() {
		p = new int[1];
		used = 0;
		size = 1;
	}
	~GrowArray() {
		delete [] p;
	}
	void ADD_BACK(int v) {
		if (used==size){
			grow();
		}
		p[used++] = v;
	}
	void ADD_FRONT(int v) {
		if (used==size){
			grow();
		}
		for(int i=used; i>0; i--){
			p[i]=p[i-1];
		}
		p[0] = v;
		used++;
	}
	void REMOVE_BACK() {
		used--;
	}
	void REMOVE_FRONT() {
		for(int i=0; i<used; i++){
			p[i]=p[i+1];
		}
		used--;
	}
	void OUTPUT(){
		for(int i=0; i<used; i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}
};


int main() {
	GrowArray a;
	ifstream input;
	input.open("HW4a.txt");
	string command;
	string strValue;
	int value;
	string temp;
	string tempStr;
	while(!input.eof()){
		command="";
		strValue="";
		getline(input,temp);
		if(temp=="")continue;
		if(temp[0]=='O'){
			a.OUTPUT();
			continue;
		}
		else{
			command=temp.substr(0,temp.find(" "));
			strValue=temp.substr(temp.find(" ")+1);
			if(command=="ADD_BACK"){
				for(int i=0; i<(int)sizeof(strValue); i++){
					if(strValue[i]==' '){
						continue;
					}
					else if(strValue[i]==NULL){
						break;
					}
					tempStr = strValue[i];
					value = atoi(tempStr.c_str());

						a.ADD_BACK(value);
						continue;
				}
			}
			else if(command == "ADD_FRONT"){
				for(int i=(int)sizeof(strValue); i>=0; i--){
				if(strValue[i]==' '){
					continue;
				}
				else if(strValue[i]==NULL){
					continue;
				}
				tempStr = strValue[i];
				value = atoi(tempStr.c_str());
					a.ADD_FRONT(value);
					continue;
				}
			}
				else if(command == "REMOVE_FRONT"){
					tempStr = strValue[0];
					value = atoi(tempStr.c_str());
					for(int i=0; i<value; i++)
						a.REMOVE_FRONT();
					continue;
				}
				else if(command == "REMOVE_BACK"){
					tempStr = strValue[0];
					value = atoi(tempStr.c_str());
					for (int i=0; i<value; i++)
						a.REMOVE_BACK();
					continue;
				}
		}
	}
	
}
