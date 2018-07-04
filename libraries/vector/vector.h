//	Autor	Alex Krieg
//	Version	0.1
//	Datum 	21.05.2018


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
		Vector &operator+=(const Vector<T> &vec);
		void push_back(T element);
		T& pop_back();
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
#endif