#include "list_utils1.h"
#include <stdio.h>
#include <conio.h>
#include <string.h> 

Iterator begin(List l) {
	Iterator i = { l.start };
	return i;
}

Iterator end(List l) {
	Iterator i = { l.end };
	return i;
}

bool moveNext(Iterator &i) {
	bool res = i.current->next;
	i.current = i.current->next;
	return res;
}

bool hasNext(Iterator i) {
	return i.current->next != nullptr;
}

double get(Iterator i) {
	return i.current->value;
}

void insert(List &l, Iterator i, double v) {
	Node* n = new Node;
	n->value = v;
	n->next = i.current->next;
	i.current->next = n;
	if (i.current == l.end)
		l.end = n;
}

bool deleteNext(List &l, Iterator i) {
	bool res = i.current->next;
	if (res) {
		Node*n = i.current->next;
		i.current->next = n->next;
		delete n;
		if (!i.current->next) {
			l.end = i.current;
		}
	}
	return res;
}

bool operator==(Iterator a, Iterator b) {
	return a.current == b.current;
}

bool operator!=(Iterator a, Iterator b) {
	return a.current != b.current;
}

void printList(List l) {
	Iterator i = begin(l);
	int n = 0;
	if (hasCurrent(i)) {
		while (hasCurrent(i)) {
			printf("%.0lf", get(i));
			moveNext(i);
			if (hasCurrent(i)) {
				printf("  ->  ");
			}
		}
	}
}

bool hasCurrent(Iterator i) {
	return i.current != nullptr;
}

void addsortedUP(List &l, double v) {
	Iterator i = begin(l);
	if (!hasCurrent(i) || get(i) > v) {
		pushStart(l, v);
	}
	else {
		bool added = false;
		for (; i != end(l) && !added; moveNext(i)) {
			if (getNext(i) > v) {
				insert(l, i, v);
				added = true;
			}
		}
		if (!added) {
			pushEnd(l, v);
		}
	}
}

void pushStart(List &l, double v) {
	Node* n = new Node;
	n->value = v;
	n->next = l.start;
	l.start = n;
	if (l.end == nullptr) {
		l.end = n;
	}
}

void pushEnd(List &l, double v) {
	Node* n = new Node;
	n->value = v;
	l.end->next = n;
	l.end = n;
	l.end->next = nullptr;
}

double getNext(Iterator i) {
	bool res = i.current->next;
	if (res) {
		return(i.current->next->value);
	}
}

void comp(List& l, List m) {
	Iterator b = begin(m);
	if (hasCurrent(b)) {
		do {
			int k = 0;
			Iterator a = begin(l);
			do {
				if (get(a) == get(b)) {
					k++;
				}
			} while (moveNext(a));
			if (k == 0) {
				addsortedUP(l, get(b));
			}
		} while (moveNext(b));
	}
}