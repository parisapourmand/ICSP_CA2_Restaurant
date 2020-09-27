/*parisa pourmand*/
#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

/**--------------- Food --------------**/
//function for using other food functions
void foodfunctions(int n,Akbar_Joojeh* akbarjoojeh) {
	while (n != '4') {
		printf("What do you want to do?\n1.print food\n2.add food\n3.find food\n4.go to main menu\n0.exit program\n");
		scanf_s(" %c", &n);
		switch (n) {
			int y;
		case '1':
			print_foods(akbarjoojeh->foodhead);
			break;
		case '2':
			food* new_food;
			new_food = (food*)malloc(sizeof(food));
			if (new_food == NULL)//error for failing to  allocate memory
				printf("memory allocation failed");
			printf("What's the name of the new food?\t");
			scanf("%s", new_food->name);
			printf("What's the price of the new food?\t");
			while (!scanf_s("%d", &new_food->price)) {//error for invalid price number
				printf("Enter a valid price:\t");
				fflush(stdin);
			}
			y = add_food(akbarjoojeh->foodhead, new_food);
			if (y == 1)
				printf("food added\n");
			else
				printf("food already exists\n");
			break;
		case '3':
			char sname[255];
			food* result;
			printf("What are you looking for?\t");
			scanf("%s", sname);
			result = search_food(akbarjoojeh->foodhead, sname);
			if (result != NULL)
				printf("food found:\n%s,\t%d\n", result->name, result->price);
			else
				printf("food not available\n");
			break;
		case '4':
			break;
		case '0':
			printf("exiting\n");
			exit(1);
		default:
			printf("invalid order.\n");
			break;
		}
	}
}

void print_foods(food * food_list) {
	food* temp =food_list ->next; //fist node is a dummy node(not printed)
	if (temp == NULL)
		printf("Nothing exists\n");
	else
	while (temp != NULL) {
		printf("%s,\t%d\n", temp->name, temp->price);
		temp = temp->next;
	}
}
int add_food(food* food_list, food* new_food) {
	int i;
	food* temp = food_list;
	for (i = 0; temp ->next != NULL; i++) {
		if (new_food->name == temp->next->name)
			return 0;
		temp = temp->next;
	}
	temp -> next = new_food;
	new_food->next = NULL;
	return 1;
}
food* search_food(food* food_list, char name[]) {
	int i,y;
	food* temp = food_list;
	for (i = 0; temp->next != NULL; i++) {
		y = strcmp(temp->next->name, name);//fist node is a dummy node(not searched)
		if (y==0)
			return temp->next;
		temp = temp->next;
	}
	return NULL;
}
/**--------------- Customrs --------------**/
//function for using other cutomer functions
void customerfunctions(int n,Akbar_Joojeh* akbarjoojeh) {
	while (n != '4') {
		printf("What do you want to do?\n1.print customers\n2.add customer\n3.find customer\n4.go to main menu\n0.exit program\n");
		scanf_s(" %c", &n);
		switch (n) {
			int y;
		case '1':
			if (akbarjoojeh->customerroot == NULL) {
				printf("Nothing exists.\n");
				break;
			}
			print_customers(akbarjoojeh->customerroot);
			break;
		case '2':
			customer* new_customer;
			new_customer = (customer*)malloc(sizeof(customer));
			if (new_customer == NULL)//error for failing to  allocate memory
				printf("memory allocation failed");
			new_customer->left_child = NULL;
			new_customer->right_child = NULL;
			printf("What's the new customer's username?(the username must start with a CAPITAL letter)\t");
			while (!scanf("%s", new_customer->username)||new_customer->username[0]<'A' || new_customer->username[0]>'Z') {//error for invalid username
				printf("Username must start with a capital letter!\n Enter username\t");
				fflush(stdin);
			}
			printf("What's the new customer's phone number?\t");
			while (!scanf("%ld", &new_customer->phone)) {//error for invalid phone number
				printf("Enter a valid number:\t");
					fflush(stdin);
			}
			printf("What's the new customer's address?\t");
			scanf("%s", new_customer->address);
			y = insert_customer(&akbarjoojeh->customerroot,new_customer);
			if (y == 1)
				printf("Customer added.\n");
			else
				printf("That username already exists.\n");
			break;
		case '3':
			char username[255];
			customer* result;
			printf("Who are you looking for?\t");
			scanf("%s", username);
			result = search_customer(akbarjoojeh->customerroot, username);
			if (result != NULL)
				printf("Customer found:\nUsername:%s,\tPhone number:%d,\tAddress:%s\n", result->username, result->phone,result->address);
			else
				printf("Customer not found.(The Customer does not exist)\n");
			break;
		case '4':
			break;
		case '0':
			printf("exiting\n");
			exit(1);
		default:
			printf("invalid order.\n");
			break;
		}
	}
}
void print_customers(customer* customer_root) {
	if (customer_root != NULL) {
		if (customer_root->left_child != NULL) 
		    print_customers(customer_root->left_child);
		printf("%s,\tPhone number:%ld,\tAddress:%s\n", customer_root->username, customer_root->phone, customer_root->address);
		if (customer_root->right_child != NULL)
			print_customers(customer_root->right_child);
	}
}
int insert_customer(customer** customer_root, customer* new_node) {
	if ((*customer_root)== NULL) {//if tree is empty
		(*customer_root) = new_node;
		return 1;
	}
	else if (_strcmpi((*customer_root)->username, new_node->username)== 0) {//if username exists
		free(new_node);
		return 0;
	}
	else if (_strcmpi((*customer_root)->username, new_node->username)> 0) {//left child
		return insert_customer(&(*customer_root)->left_child,new_node);
	}
	else if (_strcmpi((*customer_root)->username, new_node->username)< 0) {//right child
		return insert_customer(&(*customer_root)->right_child, new_node);
	}
}

customer* search_customer(customer* customer_root, char username[]) {
	if (customer_root == NULL) {//if tree is empty
		return NULL;
	}
	else if (!strcmp(customer_root->username, username))//foud username
		return customer_root;
	else if (_strcmpi(customer_root->username, username)>0)//search left child
		return search_customer(customer_root->left_child,username);
	else//search right child
		return search_customer(customer_root->right_child, username);
}

/**--------------- Orders --------------**/
//function for using other cutomer functions
void orderfunctions(int n, Akbar_Joojeh* akbarjoojeh) {
	while (n != '4') {
		printf("What do you want to do?\n1.print orders\n2.add order\n3.go to main menu\n0.exit program\n");
		scanf_s(" %c", &n);
		char m = '1';
		food_row* templist;
		switch (n) {
			int y;
		case '1':
			if (akbarjoojeh->ordhead == NULL) {
				printf("Nothing exists.\n");
				break;
			}
			print_orders(akbarjoojeh);
			break;
		case '2':
			order* new_order;
			new_order = (order*)malloc(sizeof(order));	
			new_order->list = (food_row*)malloc(sizeof(food_row));
			if (new_order == NULL)//error for failing to  allocate memory
				printf("memory allocation failed");
			new_order->next= NULL;
			new_order->list->next = NULL;
			templist = new_order->list;
			if (akbarjoojeh->foodhead->next == NULL || akbarjoojeh->customerroot == NULL)//error if no customers or food exists
				printf("Add food and cutomers befor ordering");
			printf("What's the customer's username?(the username must start with a CAPITAL letter)\t");
			scanf("%s", new_order->username);
			if (search_customer(akbarjoojeh->customerroot, new_order->username)==NULL) {//error for invalid username
				printf("Username does not exist!\n");
				continue;
			}
			while (m != '2') {
				printf("What's the order?\n");
				printf("Food name:\t");//Enter food name
				scanf("%s", templist->name);
				if (search_food(akbarjoojeh->foodhead, templist->name) == NULL) {//error for invalid food
					printf("Food does not exist.\t");
					continue;
				}
				printf("Amount:\t");//Enter amount
				while (!scanf("%d", &new_order->list->num)) {//error for invalid number
					printf("Enter a number:\t");
					fflush(stdin);
				}		
            	printf("What do you want to do?\t1.continue ordering\t2.end ordering\n");
				scanf(" %c", &m);		
				templist = templist->next;
				templist = (food_row*)malloc(sizeof(food_row));
			}
			y = add_order(akbarjoojeh, new_order);
			if (y == 1)
				printf("Order added.\n");
			else
				printf("That username already exists.\n");
			break;
		case '3':
			break;
		case '0':
			printf("exiting\n");
			exit(1);
		default:
			printf("invalid order.\n");
			break;
		}
	}
}

 void print_orders(Akbar_Joojeh* akbar_joojeh){
	int i;
	order* ordtemp = akbar_joojeh->ordhead->next;//first node is a dummy
  	customer* ctmtemp;
	food* fdtemp;
	int total=0;
	if (ordtemp == NULL)
		printf("Nothing exists\n");
	else
  	 while ( ordtemp != NULL) {//printing orders
  		printf("Order Number:%d,\t\t Date:%s", ordtemp->ordnum, ordtemp->date);
		ctmtemp = search_customer(akbar_joojeh->customerroot, ordtemp->username);
		printf("\nUsername:%s, \t Phone Number : %d, \t Address : %s, \n", ctmtemp->username, ctmtemp->phone,ctmtemp->address);
		while (ordtemp->list != NULL) {
			fdtemp=search_food(akbar_joojeh->foodhead, ordtemp->list->name);
			printf("%s, \t  %d, \t  %d, \n", ordtemp->list->name, ordtemp->list->num, fdtemp->price);
			total += (ordtemp->list->num)*(fdtemp->price);
			ordtemp->list = ordtemp->list->next;
		}
		printf("Total:%d, \n",total);
		printf("*********************************************************************");
  		ordtemp = ordtemp->next;
  	}
}
 int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order) {
	 order* temp = akbar_joojeh->ordhead;
	 while (temp->next != NULL) {
		 if (new_order->username == temp->next->username) {//for duplicated username
			 free(new_order);
			 free(new_order->list);
				 return 0;
		 }
			 temp = temp->next;
		 }
	 temp->next = new_order;
	 strcpy(new_order->date, GetTime());
	 new_order->ordnum=temp->ordnum+1;
	 return 1;
 }
 //function for gettind date & time
 char* GetTime() {
	 time_t compile;
	 char* neededtime;
	 compile = time(NULL);
	 neededtime = ctime(&compile);
	 return neededtime;
 }