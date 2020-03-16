/*
 * mapApi.c
 *
 *  Created on: 30-Dec-2019
 *      Author: santosh
 */

#include "../include/common.h"
#include "../include/map.h"


/************************************************************************************
 * ********************                                 *****************************
 * ********************    LOCAL FUNCTION DEFINITION    *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

static int findVarPresence(mapper *head, unsigned int var)
{
	int idx = -1;
	unsigned int i = 0;

	for(; i < head->size; i++) {
		if(head->entries[i].key == var) {
			idx = (signed int)i;
		}
	}
	return idx;
}

static mapper *copyData(mapper *src, mapper *dest)
{
	unsigned int i = 0;

	for(; i < src->size; i++)
	{
		dest->entries[i].key = src->entries[i].key;
		dest->entries[i].count = src->entries[i].key;
	}

	dest->size = src->size;

	return dest;
}


/************************************************************************************
 * ********************                                 *****************************
 * ********************    GLOBAL MAP APIS              *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

mapper *createNewEntry(mapper *head, uint32 var)
{
	int idx = findVarPresence(head, var);
	if(idx == -1) {
		if(head->size+1 == head->capacity) {
			mapper *newMapEntries = NULL;

			newMapEntries = (mapper *)malloc(sizeof(mapper) * head->capacity * 2);
			if(newMapEntries == NULL)
			{
				printf("Failed to allocate memory\n");
				return NULL;
			}

			newMapEntries->capacity = head->capacity * 2;
			newMapEntries->size = head->size;

			newMapEntries = copyData(head, newMapEntries);
			++newMapEntries->size;
			newMapEntries->entries[newMapEntries->size].key = var;
			newMapEntries->entries[newMapEntries->size].count = 1;
			free(head);
			head = newMapEntries;
		}
		else {
			head->size++;
			head->entries[head->size].key = var;
			head->entries[head->size].count = 1;
		}
	}
	else {
		head->entries[idx].count++;
	}

	return head;
}

void printTable(mapper *mapTable)
{
	if(mapTable == NULL)
		return;

	unsigned int i = 0;

	for(; i < mapTable->size; i++) {
		printf("The Entry %d has count %d\n", mapTable->entries[i].key, mapTable->entries[i].count);
	}

	return;
}


mapper *initMapper(unsigned int size)
{
	mapper *mapEntries = (mapper *)malloc(sizeof(mapper));
	if(mapEntries == NULL)
	{
		printf("Failed to allocate memory.\n");
		return NULL;
	}

	mapEntries->capacity = size;
	mapEntries->size = 0;

	mapEntries->entries = (map *)malloc(sizeof(map) * mapEntries->capacity);

	for(unsigned int i=0; i < mapEntries->capacity; i++)
	{
		mapEntries->entries[i] = {0};
	}

	return mapEntries;
}

void destroyTable(mapper *mapTable)
{
	unsigned int i = 0;

	for(i = 0; i < mapTable->capacity; i++)
	{
		mapTable->entries[i].key = 0;
		mapTable->entries[i].count = 0;
	}

	free(mapTable->entries);
	free(mapTable);

	return;
}

