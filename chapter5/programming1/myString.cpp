/*************************************************************************
    > File Name: myString.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年02月16日 星期五 20时21分30秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class MyString{
	public:
		MyString();//构造函数
		MyString(const char *);//有参构造函数
		MyString(const MyString &rhs);//copy constructor

		~MyString();

		MyString & operator=(const MyString &rhs);
		MyString & operator=(const char *str);

		MyString & operator+=(const MyString &rhs);
		MyString & operator+=(const char *str);

		char & operator[](std::size_t index);
		const char & operator[](std::size_t index) const;

		std::size_t size() const;
		const char* c_str() const;
		void debug();

		friend MyString operator+(const MyString & s1,const MyString & s2);
		friend MyString operator+(const MyString &,const char *);
		friend MyString operator+(const char *,const MyString &);
		friend bool operator==(const MyString &,const MyString &);
		friend bool operator!=(const MyString &,const MyString &);

		friend bool operator<(const MyString &,const MyString &);
		friend bool operator>(const MyString &,const MyString &);
		friend bool operator<=(const MyString &,const MyString &);
		friend bool operator>=(const MyString &,const MyString &);

		friend std::ostream & operator<<(std::ostream & os,const MyString &s);
		friend std::istream & operator>>(std::istream & is,MyString & s);

	private:
		char *pstr_;
};

MyString::MyString()
{
	cout<<"MyString()"<<endl;
	pstr_=new char[1];
}

MyString::MyString(const char *str)
{
	cout<<"MyString(const char *str)"<<endl;
	pstr_=new char[strlen(str)+1];
	strcpy(pstr_,str);
}

MyString::MyString(const MyString &rhs)
{
	cout<<"MyString(const MyString &rhs)"<<endl;
	pstr_=new char[strlen(rhs.pstr_)+1];
	strcpy(pstr_,rhs.pstr_);
}

MyString::~MyString()
{
	cout<<"~MyString"<<endl;
	delete []pstr_;
}

MyString & MyString::operator=(const MyString &rhs)
{
	cout<<"MyString & operator=(const MyString & rhs)"<<endl;
	if(this ==&rhs)
		return *this;
	delete []pstr_;
	pstr_=new char[strlen(rhs.pstr_)+1];
	strcpy(pstr_,rhs.pstr_);
	return *this;
}

MyString & MyString::operator=(const char *str)
{
	cout<<"MyString operator=(const char *str)"<<endl;
	pstr_=new char[strlen(str)+1];
	strcpy(pstr_,str);
	return *this;
}

MyString & MyString::operator+=(const MyString &rhs)
{
	cout<<"operator+=(const MyString &rhs)"<<endl;
	int len=strlen(rhs.pstr_)+strlen(pstr_);
	pstr_=(char*)realloc(pstr_,len+1);
	strcat(pstr_,rhs.pstr_);
	return *this;
}

MyString & MyString::operator+=(const char *str)
{
	cout<<"operator+=(const char *str)"<<endl;
	int len=strlen(str)+strlen(pstr_);
	pstr_=(char *)realloc(pstr_,len+1);
	strcat(pstr_,str);
	return *this;
}

char & MyString::operator[](std::size_t index)
{
	return pstr_[index];
}

const char & MyString::operator[](std::size_t index) const 
{
	return pstr_[index];
}

std::size_t MyString::size() const
{
	return strlen(pstr_);
}

const char* MyString::c_str() const
{
	int len =strlen(pstr_);
	pstr_[len+1]='\0';
	return pstr_;
}

void MyString::debug()
{
	cout<<pstr_<<endl;
}

MyString operator+(const MyString &s1,const MyString &s2)
{
	cout<<"operator+(const MyString &s1,const MyString &s2)"<<endl;
	MyString ret_str=s1.pstr_;
	ret_str+=s2.pstr_;
	return ret_str;
}

MyString operator+(const MyString &s,const char *str)
{
	cout<<"operator+(const MyString &s,const char *str)"<<endl;
	MyString temp(str);
	return (s+temp);
}

MyString operator+(const char *str,const MyString &s)
{
	cout<<"operator+(char*,MyString &)"<<endl;
	MyString temp(str);
	return (temp+s);
}

bool operator==(const MyString &lstr,const MyString &rstr)
{
	cout<<"=="<<endl;
	if(strcmp(lstr.pstr_,rstr.pstr_)==0)
		return true;
	else
		return false;
}

bool operator!=(const MyString &lstr,const MyString &rstr)
{
	cout<<"!="<<endl;
	return !(lstr==rstr);
}

bool operator<(const MyString &lstr,const MyString &rstr)
{
	cout<<"<"<<endl;
	if(strcmp(lstr.pstr_,rstr.pstr_)<0)
		return true;
	else
		return false;
}

bool operator>(const MyString &lstr,const MyString &rstr)
{
	cout<<">"<<endl;
	if(strcmp(lstr.pstr_,rstr.pstr_)>0)
		return true;
	else 
		return false;
}

bool operator<=(const MyString &lstr,const MyString &rstr)
{
	cout<<"<="<<endl;
	if(strcmp(lstr.pstr_,rstr.pstr_)<=0)
		return true;
	else
		return false;
}

bool operator>=(const MyString &lstr,const MyString &rstr)
{
	cout<<">="<<endl;
	if(strcmp(lstr.pstr_,rstr.pstr_)>=0)
		return true;
	else 
		return false;
}

std::ostream & operator<<(std::ostream &os,const MyString &s)
{
	os<<s.pstr_<<" ";
	return os;
}

std::istream & operator>>(std::istream &is,MyString &s)
{
	is>>s.pstr_;
	return is;//不能输入空格
}



int CompareString( const void * e1, const void * e2)
{
	MyString *s1=(MyString *) e1;
	MyString *s2=(MyString *) e2;
	if(*s1<*s2) return -1;
	else if(*s1==*s2) return 0;
	else if(*s1>*s2) return 1;
}

int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4]={"big","me","about","take"};
	cout<<"1. "<<s1<<s2<<s3<<s4<<endl;
	s4=s3;
	s3=s1+s3;
	cout<<"2. "<<s1<<endl;
	cout<<"3. "<<s2<<endl;
	cout<<"4. "<<s3<<endl;
	cout<<"5. "<<s4<<endl;
	cout<<"6. "<<s1[2]<<endl;
	s2=s1;
	s1="ijkl-";
	s1[2]='A';
	cout<<"7. "<<s2<<endl;
	cout<<"8. "<<s3<<endl;
	s1+="mnop";
	cout<<"9. "<<s1<<endl;
	s4="qrst-"+s2;
	cout<<"10. "<<s4<<endl;
	s1=s2+s4+"uvw"+"xyz";
	cout<<"11. "<<s1<<endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for(int i=0;i<4;++i)
		cout<<SArray[i]<<endl;
//	cout<<s1(0,4)<<endl;
//	cout<<s1(5,10)<<endl;

	return 0;
}
