#include<iostream>

using namespace std;

class A{
	public:
		int val;
		A(int x=0):val(x){
		}
		A& GetObj(){
			return *this;
		}
};

int main()
{
	A a;
	cout<<a.val<<endl;
	a.GetObj()=5;
	cout<<a.val<<endl;

	return 0;
}
