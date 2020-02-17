/*
 * map.h
 *
 *  Created on: 30-Dec-2019
 *      Author: santosh
 */

#ifndef MAP_H_
#define MAP_H_

#include "common.h"

#define MAX 10

typedef struct map_t_
{
	unsigned int /*uint32 */ count;
	unsigned int /*uint32*/  key;
}map;

typedef struct mapper_t_ {
	map *entries;
	unsigned int size;
	unsigned int capacity;
}mapper;


mapper *createNewEntry(mapper *head, uint32 var);
void printTable(mapper *mapTable);
mapper *initMapper(unsigned int size);
void destroyTable(mapper *mapTable);

#endif /* MAP_H_ */
