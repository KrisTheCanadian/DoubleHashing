#include <iostream>
#include "HashTable.h"

int main()
{
    HashTable hashTable1(19, 7);
    hashTable1.put(25);
    hashTable1.put(12);
    hashTable1.put(42);
    hashTable1.put(31);
    hashTable1.put(35);
    hashTable1.put(39);
    hashTable1.remove(31);
    hashTable1.put(48);
    hashTable1.remove(25);
    hashTable1.put(18);
    hashTable1.put(29);
    hashTable1.put(29);
    hashTable1.put(35);
    hashTable1.display();
    cout << "Number of collisions: " << hashTable1.collisions << endl;
}
