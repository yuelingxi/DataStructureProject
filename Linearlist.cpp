#include <iostream>
using namespace std;
class Linearlist
{
public:
	Linearlist(int Maxlistsize);
	~Linearlist(){delete []element;element=0;}
	bool IsEmpty()const {return length==0;}
	int Length()const {return length;}
	bool Find(int k, int& x)const;//返回第k个元素至x
	int Search(const int x)const;//返回k的位置
	Linearlist& Delete(int k,int &x);//删除第k个元素并放入x
	Linearlist& Insert(int k,int x);//在k之后插入x
	void Output(ostream& out)const;
private:
	int length;
	int MaxSize;
	int *element;
};//要加分号
//处理异常
class NoMem
{
public:
	NoMem(){}
};
void my_new_handler()
{
	throw NoMem();
}

Linearlist::Linearlist(int Maxlistsize)
{
	element=new int[Maxlistsize];
	MaxSize=Maxlistsize;
	length=0;
}
//注意函数头的写法
bool Linearlist::Find(int k, int &x)const
{
	//返回第k个元素至x
	if(k<length)
   	{
   		x=element[k];
   		return true;
   	}
   	else
   		return false;
}
int Linearlist::Search(const int x)const
{
	//返回x的位置
	int i;
	for(i=0;i<length;i++)
		if(element[i]==x)
			return i;
	return -1;
}
Linearlist& Linearlist::Delete(int k,int &x)
{
	int i;
	x=element[k];
	length--;
	for(i=k;i<length;i++)
		element[i]=element[i+1];
	return *this;
}
Linearlist& Linearlist::Insert(int k,int x)
{
	//在k之后插入x
	if(length<MaxSize)
	{
		int i;
		for(i=length;i>k;i--)
			element[i]=element[i-1];
		element[k]=x;
		length++;
	}
	else
		throw NoMem();
	return *this;
}
void Linearlist::Output(ostream& out)const
{
	int j;
	for(j=0;j<length;j++)
		out<<element[j]<<"	";
}
//重载<<
ostream& operator<<(ostream& out ,const Linearlist & x)
{
	x.Output(out);
	return out;
}
int main()
{
	new_handler Old_Handler_=set_new_handler(my_new_handler);
	Linearlist ls(5);
	cout<<"length="<<ls.Length()<<endl;
	cout<<"IsEmpty="<<ls.IsEmpty()<<endl;
	ls.Insert(0,2).Insert(1,6);
	cout<<"List is"<<ls<<endl;
	cout<<"IsEmpty="<<ls.IsEmpty()<<endl;
	int z;
	ls.Find(0,z);
	cout<<"Frist element is"<<z<<endl;
	cout<<"length="<<ls.Length()<<endl;
	ls.Delete(0,z);
	cout<<"Delete element is"<<z<<endl;
	cout<<"List is"<<ls<<endl;
}