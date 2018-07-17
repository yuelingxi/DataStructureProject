class ChainNode
{
	friend Chain;
	private:
		int data;
		ChainNode *link;
		bool sFind(int k,ChainNode &x)const;//返回第k个内部节点至x
}
class Chain
{
	public:
		Chain(){first=0;}
		~Chain();
		bool IsEmpty(){return first==0;}
		int Length()const;
		bool Find(int k,int &x)const;//返回第k个元素至x
		int Search(int x)const;//返回k的位置
		Chain& Delete(int k,int &x);//删除第k个元素并放入x
		Chain& Insert(int k,int x);//在k之后插入x
		void Output()const;
	private:
		ChainNode *first;
}
int Chain::Length()const
{
	int i=0;
	ChainNode *li=first;
	while(li.link)
	{
		li=li.link;
		i++;
	}
	return i;
}
bool Chain::Find(int k,int x)const
{
	if(k>=Length)
		return false;
	int i;
	ChainNode *li=first;
	for(i=0;i<k-1;i++)
		li=li.link;
	x=li.data;
	return true;
}
bool Chain::sFind(int k,ChainNode *&x)const
{
	if(k>=Length)
		return false;
	int i;
	ChainNode *li=first;
	for(i=0;i<k-1;i++)
		li=li.link;
	x=li;
	return true;
}
int Chain::Search(int x)const
{
	int i=0;
	ChainNode *li=first;
	while(li&&(li.data!=x))
	{
		li++;
		li=li.link;
	}
	if(li)return -1;
	return i;
}
Chain& Chain::Delete(int k,int x)
{
	if(k>=Length())
		throw NoMem();
	if(k)
	{
		ChainNode *father;
		sFind(k-1,father);
		x=father.link.data;
		father.link=father.link.link;
	}
	else
	{
		x=first.data;
		first=first.link;
	}
	delete father;
	return *this;
}
Chain& Chain::Insert(int k,int x)
{
	if(k)
	{
		ChainNode *father;
		sFind(k-1,father);
		x=father.link.data;
		father.link=father.link.link;
	}
	else
	{
		x=first.data;
		first=first.link;
	}
	delete father;
	return *this;


}