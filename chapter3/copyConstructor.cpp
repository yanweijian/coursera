/*************************************************************************
    > File Name: copyConstructor.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 24 Dec 2017 09:59:46 PM DST
 ************************************************************************/

#include<iostream>
using namespace std;
class Sample{
	public:
		int v;
		Sample(int n):v(n){}
		Sample(const Sample &a){
			v=2*a.v;
			cout<<"copy constructor called"<<endl;
		}
};

int main(){
	Sample a(5);
	Sample b=a;
	cout<<b.v<<endl;
	return 0;
}
