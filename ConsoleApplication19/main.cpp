#include <stdio.h>
#include <conio.h>
#include "list_utils1.h"
#include <string.h> 
#include <math.h>

void main() {
	double v;
	List l = List();
	List m = List();
	int n1;
	printf("Enter list1 size: ");
	scanf("%i", &n1);
	printf("Enter %i items: \n", n1);
	for (int i = 0; i < n1; i++) {
		scanf("%lf", &v);
		addsortedUP(l, v);
	}
	printf("\n\n");
	printf("List1: ");
	printList(l);
	printf("\n\n");
	int n2;
	printf("Enter list2 size: ");
	scanf("%i", &n2);
	printf("Enter %i items: \n", n2);
	for (int i = 0; i < n2; i++) {
		scanf("%lf", &v);
		addsortedUP(m, v);
	}
	printf("\n\n");
	printf("List2: ");
	printList(m);
	printf("\n\n");
	comp(l, m); // list of non-repeating elements!
	printf("Unite list: ");
	printList(l);
	getch();
}