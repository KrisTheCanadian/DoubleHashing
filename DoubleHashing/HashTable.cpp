#include "HashTable.h"
#include <iostream>

HashTable::HashTable(int N, int q)
{
	this->N = N;
	this->q = q;
	Table = new int[N];

	for (int i = 0; i < N; i++) 
	{
		Table[i] = -1;
	}
}

HashTable::~HashTable()
{
	delete Table;
}

void HashTable::put(unsigned int k)
{
	int h = k % N;
	int d = q - (k % q);
	if (Table[h] < 0)
	{
		Table[h] = k;
	}
	else {
		cout << "collision #" << collisions +1 << " @ " << h << " for k: " << k << endl;
		int index = (h + d) % N;

		while(true)
		{
			collisions++;
			if (Table[index] < 0 )
			{
				Table[index] = k;
				break;
			}
			cout << "collision #" << collisions + 1 << " @ " << index << " for k: " << k << endl;
			index = index + d;
			index = index % N;
			
		}
	}
}

bool HashTable::remove(unsigned int k)
{
	int h = k % N;
	int d = q - (k % q);
	bool removed = false;
	if (Table[h] == k)
	{
		Table[h] = -10;
	}
	else {
		int index = (h + d) % N;

		while (Table[index] != -1)
		{
			if (Table[index] == k)
			{
				Table[index] = -10;
				return true;
			}

			index = index + d;
			index = index % N;

		}
	}
	return false;
}

void HashTable::display() 
{
	for (int i = 0; i < N; i++) 
	{
		std::cout << "[ " << i << " ] = " << Table[i]  << std::endl;
	}
}