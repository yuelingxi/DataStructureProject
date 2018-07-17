#include <iostream>
using namespace std;
template <class T>
inline void Swap(T& a,T& b)
{
	T temp=a;
	a=b;
	b=temp;
}
int* rank(int a[],int n)
{
int i,j,rank;
int *b=new int[n];
for(i=0;i<n;i++)
	{
		rank=0;
		for(j=0;j<n;j++)
		{
			if(a[j]<a[i])
				rank++;
			if(j>i&&a[j]==a[i])
				rank++;
		}
	b[i]=rank;
	}
	return b;
}
void ranksort(int a[],int b[],int n)
{
	//b为名次数组
	int i;
	for(i=0;i<n;i++)
	{
		if(i!=b[i])
			Swap(a[i],a[b[i]]);
	}

}
int main()
{
	//数组相当于指针
	int a[]={1,4,2,6,4,8,9};
	int *b;
	b=rank(a,7);
	ranksort(a,b,7);
	int i=0;
	for(i=0;i<7;i++)
		cout<<a[i]<<endl;
}