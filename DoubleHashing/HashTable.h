#pragma once
#include <vector>

using namespace std;

class HashTable
{
public:
	unsigned int N;
	unsigned int q;
	int* Table;
	unsigned int collisions = 0;

public:

	HashTable(int N, int q);

	~HashTable();

	void put(unsigned int k);

	bool remove(unsigned int k);

	void display();
};

