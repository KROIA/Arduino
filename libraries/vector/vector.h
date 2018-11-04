//	Autor	Alex Krieg
//	Version	00.02.00
//	Datum 	04.11.2018


#ifndef VECTOR_H
#define VECTOR_H

template <typename T >
class Vector
{
	public:
		Vector();
        Vector(unsigned int size,T value);
		~Vector();
		T& operator[](unsigned int pos);
		Vector &operator=(const Vector<T> &vec);
        Vector &operator+=(Vector<T> &vec);
		void push_back(T element);
        T pop_back();
		unsigned int size();
		unsigned int capacity();
		void resize(unsigned int size);
		void erase(unsigned int pos,unsigned int amount = 1);
		void clear();
		T* begin();
		T* end();
		
	
	private:
		T* value;
		unsigned int arraySize;
		unsigned int _capacity;
};



template <typename T >
Vector<T>::Vector()
{
    arraySize = 0;
    _capacity = 0;
    value = new T[_capacity];
    this->resize(arraySize);
}
template <typename T >
Vector<T>::Vector(unsigned int size,T value)
{
    arraySize = 0;
    _capacity = 0;
    this->value = new T[_capacity];
    this->resize(size);
    arraySize = size;
    for(unsigned int a=0; a<arraySize; a++)
    {
        this->value[a] = value;
    }
}
template <typename T >
Vector<T>::~Vector()
{
    delete[] value;
}
template <typename T >
T& Vector<T>::operator[](unsigned int pos)
{
    return value[pos % arraySize];
}
template <typename T >
Vector<T>& Vector<T>::operator=(const Vector<T> &vec)
{
    arraySize = vec.arraySize;
    _capacity = vec._capacity;
    delete[] value;
    value = new T[_capacity];
    for(unsigned int a=0; a<arraySize; a++)
    {
        value[a] = vec.value[a];
    }
    return *this;
}
template <typename T >
Vector<T>& Vector<T>::operator+=(Vector<T> &vec)
{
    this->resize(arraySize+vec.arraySize);
    for(unsigned int a=0; a<vec.arraySize; a++)
    {
        this->push_back(vec[a]);
    }
    return *this;
}
template <typename T >
void Vector<T>::push_back(T element)
{
    arraySize++;
    this->resize(arraySize);
    value[arraySize-1] = element;
}
template <typename T >
T Vector<T>::pop_back()
{
    arraySize--;
    if(arraySize+1 == _capacity)
    {
        T ret = value[arraySize];
        _capacity--;
        T* newVal = new T[_capacity];
        for(unsigned int a=0; a<arraySize; a++)
        {
            newVal[a] = value[a];
        }
        delete[] value;
        value = new T[arraySize];
        for(unsigned int a=0; a<arraySize; a++)
        {
            value[a] = newVal[a];
        }
        delete[] newVal;
        return ret;
    }
    else
    {
        return value[arraySize];
    }
}
template <typename T >
unsigned int Vector<T>::size()
{
    return arraySize;
}
template <typename T >
unsigned int Vector<T>::capacity()
{
    return _capacity;
}
template <typename T >
void Vector<T>::resize(unsigned int size)
{
    if(_capacity != size)
    {
        _capacity = size;
        if(_capacity < arraySize){arraySize = _capacity;}
        T* newVal = new T[arraySize];

        for(unsigned int a=0; a<arraySize; a++)
        {
            newVal[a] = value[a];
        }
        delete[] value;
        value = new T[_capacity];
        for(unsigned int a=0; a<arraySize; a++)
        {
            value[a] = newVal[a];
        }
        delete[] newVal;
    }
}
template <typename T >
void Vector<T>::erase(unsigned int pos,unsigned int amount)
{
    if(amount == 0){return;}
    if(pos<arraySize)
    {
        if(pos+amount > arraySize){amount = arraySize-pos;}
        unsigned int newSize = pos+arraySize-(pos+amount);
        T* newVal = new T[newSize];
        for(unsigned int a=0; a<pos; a++)
        {
            newVal[a] = value[a];
        }
        for(unsigned int a=pos; a<pos+arraySize-(pos+amount); a++)
        {
            newVal[a] = value[a+amount];
        }
        if(_capacity == arraySize)
        {
            _capacity = newSize;
            delete[] value;
            value = new T[_capacity];
        }
        for(unsigned int a=0; a<newSize; a++)
        {
            value[a] = newVal[a];
        }
        arraySize = newSize;
        delete[] newVal;
    }
}
template <typename T >
void Vector<T>::clear()
{
    if(arraySize == _capacity)
    {
        _capacity = 0;
    }
    arraySize = 0;
    delete[] value;
    value = new T[arraySize];
}
template <typename T >
T* Vector<T>::begin()
{
    return &value[0];
}
template <typename T >
T* Vector<T>::end()
{
    return &value[arraySize-1];
}

#endif
