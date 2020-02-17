#include "../include/common.h"
#include "../include/hashTable.h"


void hashEntryFreeBucket(ht_entry **entry)
{
	ht_entry *temp = NULL;
	if(entry)
	{
		while(*entry)
		{
			temp = (*entry);
			(*entry) = (*entry)->nextEntry;

			hashEntryFreeEntry(&temp);
		}
	}
}

int hashTableDestroy(hashtable **htable)
{
	unsigned int idx;

	if(htable)
	{
		if(*htable)
		{
			if((*htable)->bucketList)
			{
				idx = 0;
				while(idx < (*htable)->noBuckets)
				{
					if(((*htable)->bucketList)[idx])
						hashEntryFreeBucket(&((*htable)->bucketList)[idx]);
					idx++;
				}
				free((*htable)->bucketList);
				(*htable)->bucketList = NULL;
			}
			free(*htable);
			(*htable) = NULL;
		}
		return 0;
	}
	return -1;
}

int hashTableRehashEntry(hashtable **htable_to, ht_entry **entry)
{
	int idx = 0;

	if((htable_to != NULL && (*htable_to == NULL)) && (entry != NULL && (*entry) != NULL))
	{
		idx = hashCode(*entry->key, (int)(*htable_to)->noBuckets);
		(*entry)->nextEntry = ((*htable_to)->bucketList)[idx];
		((*htable_to)->bucketList)[idx] = (*entry);
		(*htable_to)->noEntries += 1;
		return 0;
	}
	return -1;
}

int hashTableGrowTable(hashtable **hTable)
{
	hashtable *table = NULL;
	int retCode = -1;

	if(hTable != NULL && (*hTable != NULL))
	{
		retCode = hashTableAllocTable((*hTable)->noBuckets * 2);
		if(retCode == -1)
			return -1;

		retCode = hashTableRehashTable(hTable, &table);
		if(retCode == -1)
			return -1;

		hashTableDestroy(hTable);
		(*hTable) = table;
		return 0;
	}

	return -1;
}

int hashTableShrinkTable(hashtable **hTable)
{
	hashtable *table = NULL;
	int retCode = -1;

	if(hTable == NULL && (*hTable) == NULL)
	{
		if((*hTable)->noBuckets > 1)
		{
			table = hashTableAllocTable((*hTable)->noBuckets/2);
			if (table == NULL)
				return -1;

			if(hashTableRehashTable(hTable, &table) == -1)
				return -1;

			hashTableDestroy(hTable);
			(*hTable) = table;
			return 0;
		}
		return 0;
	}
	return -1;
}


int hashTableSetLoadFactor(hashtable *htable)
{
	int retCode = -1;
	hashTable *temp;

	if(htable != NULL)
	{
		if((float)htable->noEntries/(float)htable->noBuckets > MAX_LOAD_FACTOR)
		{
			temp = hashTableGrowTable(htable);
			if(temp == htable)
			{
				printf("Failed to get new hash table.\n");
				return htable;

			}
			destroy
			htable = temp;

			return 0;
		}

		if((float)htable->noEntries/(float)htable->noBuckets < MIN_LOAD_FACTOR)
		{
			retCode = hashTableShrinkTable(htable);
			if(retCode == -1)
				return -1;

			return 0;
		}
		else
			return 0;
	}

	return -1;
}


ht_entry *hashTableCreateEntry(const char *key, const char *value)
{
	ht_entry *newEntry = NULL;

	if(key && value)
	{
		newEntry = (ht_entry *)malloc(sizeof(ht_entry));
		if(newEntry == NULL)
		{
			error("Failed to allocate memory. \n");
			return NULL;
		}

		newEntry->key = strdup(key);
		newEntry->value = strdup((char *)value);
		newEntry->nextEntry = NULL;
		return newEntry;
	}

	return NULL;
}

int hashTableInsertEntry(hashTable *hTable, char *key, char *value)
{
	ht_entry *entry = NULL;
	unsigned int idx;

	if(hTable && (key) && (value))
	{
		entry = hashTableCreateEntry(key, value);
		if(entry == NULL)
			return -1;

		idx = hashCode(key, htable->noBuckets);
		printf("%d\n", idx);

		entry->nextEntry = htable->bucketList[idx];
		htable->bucketList[idx] = entry;
		htable->noEntries += 1;
		return htable->noEntries;
	}

	return -1;
}

int hashTableInsertEntry_g(hashTable *hTable, uint32 key)
{
	ht_entry *entry = NULL;
	unsigned int idx;

	if(hTable && (key))
	{
		entry = hashTableCreateEntry(key);
		if(entry == NULL)
			return -1;

		idx = hashCode(key, htable->noBuckets);
		printf("%d\n", idx);

		entry->nextEntry = htable->bucketList[idx];
		htable->bucketList[idx] = entry;
		htable->noEntries += 1;
		return htable->noEntries;
	}

	return -1;
}


hashTable *hashTableAllocTable(unsigned int noEntries)
{
	unsigned int tmp = 0;

	if(noEntries == 0)
		return NULL;

	hashTable *table = NULL;

	table = (hashTable *)malloc(sizeof(hashTable));
	if(table == NULL)
	{
		error("Failed to allocate memory.\n");
		return NULL;
	}

	table->noBuckets = noEntries;

	table->bucketList = (ht_entry **)malloc(sizeof(ht_entry *) * (table->noBuckets));
	table->noEntries = 0;

	while(tmp < (table->noBuckets))
		(table->bucketList)[tmp++] = NULL;

	return table;
}

void printHashTableEntries(hashTable *htable)
{
	for (unsigned int idx = 0; idx < htable->noBuckets; idx++)
	{
		if(htable->bucketList[idx])
		{
			ht_entry *p = htable->bucketList[idx];
			while(p)
			{
				printf("%s at index: %d\n", p->key, idx);
				p = p->nextEntry;
			}
		}
	}
	return;
}



int main(int argc, char **argv) {
	hashTable *htable = NULL;
	uint32 numEntries = MAXHASHENTRY;
	uint32 hashc = 0;

	uint32 *arr1 = {12, 4, 24, 3, 6};
	uint32 *arr2 = {13, 7, 31, 4, 6, 17};

	htable = hashTableAllocTable(numEntries);

	for(uint32 idx = 0; idx < len(arr1); idx++)
	{
		hashc = hashCode_intp(arr1[idx], htable->noBuckets);


	}

	UnionOfNumbers(arr1, arr2);

	printHashTableEntries(htable);

	return 0;
}
