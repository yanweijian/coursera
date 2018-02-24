/*************************************************************************
    > File Name: closeClass.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 25 Dec 2017 08:19:00 PM DST
 ************************************************************************/

#include<iostream>
using namespace std;
class Base{
	public:
		int k;
		Base(int n):k(n){

		}
};

class Big{
	public:
		int v;
		Base b;
		Big(int x):v(x),b(x){

		}
};

int main()
{
	Big a1(5);
	Big a2=a1;
	cout<<a1.v<<","<<a1.b.k<<endl;
	cout<<a2.v<<","<<a2.b.k<<endl;
	return 0;
}
