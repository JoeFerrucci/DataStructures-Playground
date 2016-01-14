#include <iostream>
#include <string>
using namespace std;

class HashTable {
public:

	HashTable() 
	{
		for (int i = 0; i < tableSize; ++i)
		{
			table[i] = new item;
			table[i]->name = "empty";
			table[i]->drink = "empty";
			table[i]->next = NULL;
		}
	};

	size_t hash(string key) 
	{
		int hashValue = 0;
		for (int i = 0; i != key.length(); ++i) {
			hashValue += size_t(key[i]);
			cout << "key[" << i << "] = " << size_t(key[i]) << endl;
		}
		return hashValue % tableSize; // index
	};

	void AddItem(string name, string drink) 
	{
		size_t index = hash(name);

		if (table[index]->name == "empty")
		{
			table[index]->name = name;
			table[index]->drink = drink;
		}

		else 
		{
			item* PtrItem = table[index];

			item* chainedItem = new item;
			chainedItem->name = name;
			chainedItem->drink = drink;
			chainedItem->next = NULL;

			while (PtrItem->next != NULL) 
			{
				PtrItem = PtrItem->next; // advance down the list.
			}

			PtrItem->next = chainedItem;

		}

	};

private:
	static const size_t tableSize = 10;
	struct item {
		string name;
		string drink;
		item* next;
	};
	item* table[tableSize];

};

int main(int argc, char const *argv[])
{
    HashTable ht;

    int i = ht.hash("Joe");

    cout << "index = " << i << endl;
    return 0;
}