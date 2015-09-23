#include <iostream>
#include <math.h>
using namespace std;

void eSieve(long long a, long long b){
	//n will be used for finding primes up to sqrt(B)
	//I added 1 so that sqrt(B) will be included in the array index
	long n=floor(sqrt(b))+1;
	
	//cout<<"Creating primes"<<endl;
	bool primes[n];
	//cout<<"Done"<<endl;
	//cout<<"Initializing primes"<<endl;
	primes[0]=0;
	primes[1]=0;
	for(long i=2; i<n; i++){
		primes[i]=1;
	}
	//cout<<"Done"<<endl;
	//cout<<"Eliminating all even numbers"<<endl;
	for (long i=4; i<n; i+=2){
		primes[i]=0;
	}
	//cout<<"Done"<<endl;
	//cout<<"Eliminating multiples of primes starting at 3"<<endl;
	for (long i=3; i<n; i++){
		if(primes[i]==1){
			for (long long j=i*i; j<n; j+=2*i){
				primes[j]=0;
			}
		}
	}
	//cout<<"Done"<<endl;
	
	//primes is now a list of primes from 2 to sqrt(n)
	//now for the numbers between a and b (b+1-a so that b is included):
	//cout<<"Initalize finalPrimes"<<endl;
	bool finalPrimes[b+1-a];
	for (long i=0; i<b+1-a; i++){
		finalPrimes[i]=1;
	}
	//cout<<"Done"<<endl;
	//cout<<"Eliminating muliples of primes from finalPrimes"<<endl;
	
	for (long i=2; i<n; i++){
		if(primes[i]==1){
			long long temp=floor(a/i)*i; //find smallest mulitple between a and b
			for (long long j=temp; j<=b; j+=i){
				//handles segFaults and overlapping primes
				if(j-a<0 || j-a>b+1-a || j==i){ 
					continue;
				}
				else{
					finalPrimes[j-a]=0;
				}
			}
		}
	}
	//catch case when a=1 (1 gets marked as prime)
	if(a==1){
		finalPrimes[0]=0;
	}
	//cout<<"Done"<<endl;
	
	//To see the primes:
	/*
	for (int i=0; i<b+1-a; i++){
		if(finalPrimes[i]==1){
			cout<<a+i<<", ";
		}
	}
	*/
	//To count the primes:
	int count=0;
	for (int i=0; i<b+1-a; i++){
		if(finalPrimes[i]==1){
			count++;
		}
	}
	cout<<"Total primes from "<<a<<" to "<<b<<": "<<count;
	
}


int main(){
	long long a=0;
	long long b=-1;
	while(b<=a){
		cout<<"Enter upper bound B (must be larger than a): ";
		cin>>b;
	}
	while(a<1 || a>=b){
		cout<<"Enter lower bound A (must be greater than or equal to 1 and less than b): ";
		cin>>a;
	}
	eSieve(a,b);
	return 1;
}
