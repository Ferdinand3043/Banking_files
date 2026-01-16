#include "Banking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greeting(void){

    printf("\nWelcome to my banking application!");
    printf("\n------------------------------------");
    printf("\nPress Enter to continue.");
    getchar();
    
}


void default_menu(void){

    const char *original_menu[] = {"\n\n1. Login", "2. Create Profile", "3. Exit\n"};

    char x = sizeof(original_menu)/sizeof(original_menu[0]);

    for(int i = 0; i < x; i++){
        printf("%s\n", original_menu[i]);
    };

    printf("\nChoose between 1 & 3 for decision: ");
    scanf("%d", &answer);

    switch(answer){

        case 1:
            login();
            break;

        case 2:
            profile_creation();
            break;
        
        case 3: 
            printf("\nYour session is over.\n");
            exit(1);
        
        default:
        printf("\nInvalid input\n");
        default_menu();
    };
}



void menu(void){

    printf("\nMenu options: ");

    char *default_menu[] = {"\n\n1. Check balance", "2. Deposit money", "3. Withdrawl money", "4. Add bank", "5. Exit"};

    char z = sizeof(default_menu)/sizeof(default_menu[0]);

    for(int i = 0; i < z; i++){
        printf("%s\n", default_menu[i]);
    };

    printf("\nChoose between 1 & 5 for next decision: ");
    scanf("%d", &answer_3);

    switch(answer_3){

        case 1:
            account_balance();
            break;

        case 2:
            add_money();
            break;
            
        
        case 3: 
            withdrawl_money();
            break;
            
        
        case 4:
            bank_information();
            break;
        
        
        case 5:
            printf("\nYour session is over.\n");
            exit(1);
        
        default:
        printf("\nInvalid input\n");

    };

}


void profile_creation(void){

    printf("\nProfile Information");
    printf("\n-------------------");

    printf("\n\nFirst Name: ");
    scanf(" %s", first_name);

    printf("\nLast name: ");
    scanf(" %s", last_name);

    printf("\nDate of Birth (Enter DOB in 00/00/0000 format): ");
    scanf("%d", &age);

    printf("\nState(Enter State Abbreviation): ");
    scanf("%s", state);

    printf("\nCity: ");
    scanf("%s", city);

    printf("\nZip Code: ");
    scanf("%d", &zip);

    printf("\nSocial Security (No Dashes): ");
    scanf("%d", &fake_social);

    printf("\nIs all the information correct? ");
    scanf("%s", answer_2);

    if(strcmp(answer_2, "no") == 0){
        profile_creation();
    }
    else if(strcmp(answer_2, "yes") == 0){
        printf("\nProfile Information completed!\n\n");
        pinfo = fopen("Personal_Information.txt", "a");
        fprintf(pinfo, "\n%s\n%s\n%d\n%s\n%s\n%d\n%d\n%s", first_name, last_name, age, state, city, zip, fake_social, email);
        fclose(pinfo);
    }

    printf("\n\nUsername & Password Creation");
    printf("\n-----------------------------");

    printf("\n\nEnter Username: ");
    scanf("%s", username);

    printf("\nEnter Password: ");
    scanf("%s", password);

    uppter = fopen("Username_Password.txt", "a");

    fprintf(uppter, " %s\n %s\n", username, password);

    fclose(uppter);

    printf("\nUsername & Password Creation Completed!\n\n");

    menu();
}


void login(void){

    printf("\nLogin Portal");
    printf("\n----------------");

    printf("\n\nEnter Username: ");
    scanf("%s", inputusername);

    printf("\nEnter Password: ");
    scanf("%s", inputpassword);

    uppter = fopen("Username_Password.txt", "r");

    while(fscanf(uppter, "%s %s", storedusername, storedpassword) == 2){

        if(strcmp(inputusername, storedusername) == 0 && strcmp(inputpassword, storedpassword) == 0){
            authenticated = 1;
            break;
        }
    }    
    
    
    fclose(uppter);
    
    if (authenticated){
        printf("\nLogin successful! Welcome back %s. \n\n", inputusername);
        menu();
    }
    else {
        printf("\nLogin failed! Invalid username or password.\n");
        printf("\nIf you would like to try again press 1 or press 2 to return to main menu: ");
        scanf("%d", &login_fail);

        switch (login_fail)
        {
        case 1:
            login();
            break;
        
        case 2:
            default_menu();
            break;
        }
        
        
    }
}


void bank_information(void){

    printf("\nBank Information");
    printf("\n----------------");

    printf("\nEnter account number: ");
    scanf("%d", &account_number);

    printf("\nRouting number: ");
    scanf("%d", &routing_number);

    pbank = fopen("Banking Details.txt", "a");
    fprintf(pbank, "\n%d\n%d", account_number, routing_number);
    fclose(pbank);

    printf("\nBank information added successfully.\n");
    menu();

}


void add_money(void){

    pincrease = fopen("Account balance.txt", "r");

    fscanf(pincrease, "%d", &existing_balance);

    fclose(pincrease);

    printf("\nDollar amount you would like to deposit: ");
    scanf("%d", &additional_balance);

    new_balance = existing_balance + additional_balance;

    pincrease = fopen("Account balance.txt", "w");

    fprintf(pincrease, "%d\n", new_balance);

    fclose(pincrease);

    printf("\n\nBalance updated successfully.\n");

    menu();
}


void account_balance(void){

    printf("\nAccount Balance");
    printf("\n---------------");

    pbalance = fopen("Account balance.txt", "r");

    if(fscanf(pbalance, "%d", &current_balance) == 1){
        printf("\nAccount balance: $%d\n", current_balance );
    }
    else{
        printf("\nNo balance.\n");
    }

    fclose(pbalance);

    menu();
}

void withdrawl_money(void){

    pdecrease = fopen("Account balance.txt", "r");

    fscanf(pdecrease, "%d", &existing_balance);

    fclose(pdecrease);

     printf("\nDollar amount you would like to withdrawl: ");
    scanf("%d", &withdrawl_balance);

    new_balance = existing_balance - withdrawl_balance;

    pincrease = fopen("Account balance.txt", "w");

    fprintf(pincrease, "%d\n", new_balance);

    fclose(pincrease);

    printf("\n\nBalance updated successfully.\n");

    menu();



}

    