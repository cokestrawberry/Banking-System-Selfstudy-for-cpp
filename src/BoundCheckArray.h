#ifndef __BOUND_CHECK_ARRAY__
#define __BOUND_CHECK_ARRAY__

template <typename T>
class BoundCheckArray
{
private:
	T * arr;
	int arrLen;
	BoundCheckArray(const BoundCheckArray& arr)
	{
		//empty
	}
	BoundCheckArray& operator=(const BoundCheckArray& arr)
	{
		//empty
	}
public:
	BoundCheckArray(int len=100);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int getArrLen() const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) :arrLen(len)
{
	arr=new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if(idx<0 || idx>=arrLen)
	{
		cout<<"Out of boundary"<<endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if(idx<0 || idx>=arrLen)
	{
		cout<<"Out of boundary"<<endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::getArrLen() const
{
	return arrLen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete []arr;
}

#endif