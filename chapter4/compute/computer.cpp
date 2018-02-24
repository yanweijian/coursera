/*************************************************************************
    > File Name: computer.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 28 Jan 2018 09:18:37 PM DST
 ************************************************************************/

#include<iostream>
using namespace std;

class computer{
	int n1;
	int n2;
	char op;
	public:
		int add(computer &c){
			return n1+n2;
		}
}

int main()
{
	computer c;
	int in1;
	int in2;
	char opt;
	cin<<in1<<opt<<in2;
	c(in1,opt,in2);
	if(c.op="+"){
		cout<<add(c)<<endl;
	}
}
