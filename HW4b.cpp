#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class LinkedListHW {
private:
	class Node {
		public:
		int val;
		Node* next;
	};
	
	Node* head;
	Node* tail;
	
public:
	LinkedListHW() {
		//nullptr is c++11
		head = NULL;
		tail = NULL;
	}
	~LinkedListHW(){
		Node* q;
		for (Node* p=head; p->next != NULL; p=q){
			q=p->next;
			delete p;
		}
	}
	
	void ADD_BACK(int v){
		Node* p = new Node();
		p->val = v;
		tail->next = p;
		tail = p;
	}
	
	void ADD_FRONT(int v){
		Node* temp = new Node();
		temp->val = v;
		temp->next = head;
		head = temp;
		//First node added will be both head and tail
		if(tail==NULL){
			tail=temp;
		}
		
	}
	
	void REMOVE_BACK(){
		Node* p;
		Node* q = tail;
		for (p=head; p->next->next != tail; p = p->next){
		}
		//p is now pointing to 2 nodes behind tail
		tail = p->next;
		tail->next = NULL;
		delete q;
	}
	
	void REMOVE_FRONT(){
		Node* p = head;
		head = head->next;
		delete p;
	}
	
	void OUTPUT(){
		for (Node* p = head; p != NULL; p = p->next){
			cout<<p->val<<" ";
		}
		cout<<endl;
	}
};

int main() {
	LinkedListHW a;
	ifstream input;
	input.open("HW4b.txt");
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
					for(int i=0; i<value; i++){
						a.REMOVE_FRONT();
					}
					continue;
				}
				else if(command == "REMOVE_BACK"){
					tempStr = strValue[0];
					value = atoi(tempStr.c_str());
					for (int i=0; i<value; i++){
						a.REMOVE_BACK();
					}
					continue;
				}
		}
	}
	
}
