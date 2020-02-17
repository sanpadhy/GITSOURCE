/*
 * hashTable.h
 *
 *  Created on: 18-Jan-2020
 *      Author: santosh
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#define MAX_LOAD_FACTOR 0.7
#define MIN_LOAD_FACTOR 0.0

#define HASHCODE(key, buckets) (c)

#define MAXHASHENTRY 10

#define error(x)  printf("ERROR: %s\n", x)

#define len(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct _ht_entry_t_
{
	char *key;
	char *value;
	struct _ht_entry_t_ *nextEntry;
}ht_entry;

typedef struct _hashtable_t_
{
	unsigned int noEntries;
	unsigned int noBuckets;
	ht_entry **bucketList;
}hashTable;

int hashCode(char *key, int buckets)
{
	unsigned int id = strtol("santosh kumar padhy", (char **)NULL, strlen("santosh"));
	printf("is is: %d\n", id);
	id = strtol("amrita nanda", (char **)NULL, strlen("amrita"));
	printf("is is: %d\n", id);

	return atoi(key)/buckets;
}

int hashCode_intp(uint32 key, uint32 buckets)
{
	return (key%buckets);
}

static int findNextPrime(unsigned int no)
{
    int i,j;

    for(i=no+1;;i++)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                break;
        }

        if(j==i)
            break;
    }
    return i;
}


static hashtable *hashTableAllocTable(unsigned int noEntries);
static int hashTableGrowTable(hashtable **hTable);
static int hashTableShrinkTable(hashtable **hTable);

static ht_entry *hashTableFetchEntry(hashtable *htable, char *key);
static int hashTableInsertEntry(hashtable **htable, char *key, char *value);
static int hashTableRehashEntry(hashtable **htable_from, ht_entry **entry);
static int hashTableRehashTable(hashtable **htable_from, hashtable **htable_to);
static int hashTableDestroy(hashtable **htable);
static int hashTableSetLoadFactor(hashtable **htable);
static ht_entry hashEntryCreateEntry(char *key, void *value);
static void hashEntryFreeEntry(ht_entry **entry);
static void hashEntryFreeBucket(ht_entry **entry);





#endif /* HASHTABLE_H_ */
