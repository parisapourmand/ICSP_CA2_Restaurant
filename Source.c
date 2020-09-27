/*parisa pourmand*/
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

void main() {
	//initializing
	Akbar_Joojeh* akbarjoojeh;
	akbarjoojeh = (Akbar_Joojeh*)malloc(sizeof(Akbar_Joojeh));
	if (akbarjoojeh == NULL)//error for failing to  allocate memory
		printf("memory allocation failed");
	akbarjoojeh->foodhead =(food*) malloc(sizeof(food));
	if (akbarjoojeh->foodhead == NULL)//error for failing to  allocate memory
		printf("memory allocation failed");
	akbarjoojeh->ordhead =(order*) malloc(sizeof(order));
	if (akbarjoojeh->ordhead== NULL)//error for failing to  allocate memory
		printf("memory allocation failed");
	akbarjoojeh->ordhead->ordnum = 0;
	akbarjoojeh->ordhead->next = NULL;
	akbarjoojeh->foodhead->next = NULL;	
	akbarjoojeh->customerroot= NULL;
	char n;
	while (1) {
	printf("**********************************Main Menu************************************\n");
	printf("What do you want to do?\n1.manage food\n2.manage customers\n3.manage orders\n0.exit program\n");
	scanf_s(" %c", &n);
		switch (n) {
		case '1':
			printf("****************************Food Operations Menu******************************\n");
			foodfunctions(n, akbarjoojeh);
			break;
		case '2':
			printf("**************************customers Operations Menu****************************\n");
			customerfunctions(n, akbarjoojeh);
			break;
		case '3':
			printf("***************************Orders Operations Menu*****************************\n");
			orderfunctions(n,akbarjoojeh);
			break;

		case '0':
			printf(" exiting\n");
			free(akbarjoojeh->foodhead);
        	free(akbarjoojeh);
			exit(1);
		default:
			printf(" invalid order.\n");

		}
	}
}