/*parisa pourmand*/
#ifndef CODE_HEADER_H
#define CODE_HEADER_H

typedef struct _Akbar_Joojeh Akbar_Joojeh;
typedef struct _customer customer;
typedef struct _food food;
typedef struct _food_row food_row;
typedef struct _order order;

/* This Struct must contain:
*     list of customers
*     list of foods
*     list of orders
*/
struct _Akbar_Joojeh {
	customer* customerroot;
	food* foodhead;
	order* ordhead;
};


/* This Struct must contain:
*     username
*     phone number
*     address
*     left_child
*     right_child
* *** if you want to use linklist, use next instead of left child and right child
*/
struct _customer {
	char username[255];
	long int phone;
	char address[255];
	customer* left_child;
	customer* right_child;
};


/* This Struct must contain:
*     name
*     price
*     next_node
*/
struct _food {
	char name[255];
	int price;
	food* next;
};


/* This Struct must contain:
*     food name
*     quantity
*     next
*/
struct _food_row {
	char name[255];
	int num;
	food_row* next;
};


/* This struct must contain:
*     order number
*     customer username
*     list of food_row
*     Date and Time
*     next_node
*/
struct _order {
	int ordnum;
	char username[255];
	food_row* list;
	char date[10];
	order* next;
};

/* NOTICE: YOU CANNOT CHANGE ANY FUNCTION DECLARATION */

/**--------------- Customrs --------------**/
//function for using other customer functions
void customerfunctions(int n,Akbar_Joojeh* akbarjoojeh);
/*
* print all customers in detail sorted by usernames (alphabetically)
*/
void print_customers(customer* customer_root);

/*
* add new node in tree in alphabetical order
*      return 1 if added successfully, otherwise if username is duplicated return 0
*/
int insert_customer(customer** customer_root, customer* new_node);

/* Bonus Part:
* remove a customer by its username
* (also you should remove all his/her orders)
*      return 1 if removed successfully, otherwise return 0
*/
int remove_customer(Akbar_Joojeh* akbar_joojeh, char username[]);

/*
* search a customer by username and return its pointer
*     return NULL if customer did not find
*/
customer* search_customer(customer* customer_root, char username[]);


/**--------------- Foods --------------**/
//function for using other food functions
void foodfunctions(int n, Akbar_Joojeh* );
/*
* print all foods
*/
void print_foods(food* food_list);

/*
* add new food
*     return 1 if added successfully, otherwise if name is duplicated return 0
*/
int add_food(food* food_list, food* new_food);

/*
* search a food by name and return its pointer
*      return NULL if food did not find
*/
food* search_food(food* food_list, char name[]);


/**--------------- Orders --------------**/
//function for using other order functions
void orderfunctions(int n, Akbar_Joojeh*);
/*
* print all orders with user informatin and total price
*/
void print_orders(Akbar_Joojeh* akbar_joojeh);

/*
* add new order
*     return 1 if added successfully, otherwise if order number is duplicated or entered invalid username or invalid food return 0
*/
int add_order(Akbar_Joojeh* akbar_joojeh, order* new_order);

/*
* remover a order by its number
*      return 1 if removed successfully, otherwise return 0
*/
int remove_order(order* order_list, int order_number);

//function for gettind date & time
char* GetTime();

#endif //CODE_HEADER_H
