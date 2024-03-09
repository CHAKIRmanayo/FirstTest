#ifndef LIST_UTILS1_H
#define LIST_UTILS1_H
#include <stdio.h>

struct Node
{
	double value;
	Node* next;
};

struct List
{
	Node* start;
	Node* end;
	List(){
		start = nullptr;
		end = nullptr;
	}
};


struct Iterator
{
	Node* current;
};

Iterator begin(List);
Iterator end(List);
bool moveNext(Iterator&);
bool hasNext(Iterator);
double get(Iterator);
void insert(List&,Iterator,double);
bool deleteNext(List&,Iterator);
bool operator==(Iterator,Iterator);
bool operator!=(Iterator,Iterator);
void addsortedUP(List&,double);
void printList(List);
bool hasCurrent(Iterator);
void pushStart(List&,double);
void pushEnd(List&,double);
double getNext(Iterator);
void comp(List&,List);

#endif