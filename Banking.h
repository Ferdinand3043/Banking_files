#include <stdio.h>

static void greeting(void);

static void profile_creation(void);

static void default_menu(void);

static void menu(void);

static void login(void);

void bank_information(void);

void account_balance(void);

void add_money(void);

void withdrawl_money(void);

void *mpter;

char first_name[10], last_name[10], city[10], state[10], street[10], email[10], answer_2[10], inputusername[10], inputpassword[10];
char username[10], password[10], enter_username[10], enter_passowrd[10], correct_username[10], correct_password[10], storedusername[10], storedpassword[10];
int age, zip, fake_social, answer, answer_3, answer_4, authenticated, login_fail, account_number, routing_number, money, additional_balance, existing_balance, new_balance, current_balance, withdrawl_balance;

FILE *uppter;
FILE *pinfo;
FILE *pbank;
FILE *pbalance;
FILE *pincrease;
FILE *pdecrease;
