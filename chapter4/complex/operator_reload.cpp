/*************************************************************************
    > File Name: operator_reload.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Fri 26 Jan 2018 09:04:17 PM DST
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include"opt_reloadConfig.h"

using namespace std;

class Complex{
	private:
		double r,i;
	public:
		void Print(){
			cout<<r<<"+"<<i<<"i"<<endl;
		}
		Complex(double real=0.0,double imag=0.0){
			r=real;
			i-imag;
		}
		Complex(const Complex &c){
			r=c.r;
			i=c.i;
		}
		Complex& operator=(string s){
			int pos=s.find("+",0);
			string sTmp=s.substr(0,pos);
			cout<<"real part is : "<<sTmp<<endl;
			//Complex c;
			r=atof(sTmp.c_str());
			cout<<r<<endl;
			sTmp=s.substr(pos+1,s.length()-pos-2);
			cout<<"image part is : "<<sTmp<<endl;
			i=atof(sTmp.c_str());
			cout<<i<<endl;
			return *this;
		}
};

int main(){
	Complex a;
	a="3+4i";
	a.Print();
	cout<<opt_reload_VERSION_MAJOR<<" "<<opt_reload_VERSION_MINOR<<endl;
	return 0;
}
