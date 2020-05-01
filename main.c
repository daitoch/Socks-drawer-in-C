#include <stdio.h>
#include<stdlib.h>
#include"dresserLib.h"
#include "sockLib.h"
#include "drawerLib.h"

#define MAX_LIMIT 40
void printOptions();
//Enumeration for the constants
enum sockAction{Laundary, RemoveSocks, AddSocks, DisplayDresser, SortSocks};

//Main function for the program to execute
int
main(){

    enum sockAction day; //Initializion of the Enumerations
    
    getNumDrawers(); // Initialize the number of dressors
    SockDrawer dresser[numDrawers]; // Array of drawers or Dresser

    for (int i = 0; i < numDrawers; i++)
    {
        createDrawer(&dresser[i], i);
    }
    int len = sizeof(dresser)/sizeof(SockDrawer);

    
    //Loop for displaying the menu
    int choice;
    do
    {
        printOptions();//Function to print options
        scanf("%d", &choice);
        switch (choice)// Case statement for selection for different type of options
        {
        case Laundary:
            printf("Time to do laundry\n\n");
            break;
        case RemoveSocks:
            putAwayMySocks(dresser);// removal function
            break;
        case AddSocks:
            putOnMySocks(dresser);// adder function
            break;
        case DisplayDresser:
            displayMyDresser(dresser);// display command
            break;
        case SortSocks:
            sortMySocks(dresser, len); //sorting command
            break;

        default:// Default for any wrong value
            printf("Wrong option choose the right one\n\n");
        }
    } while (choice != 0);

    
    return 0;
}

//Funtion to print all the available options
void printOptions(){

    printf("What do you need to do?\n\n");
    printf("0. Don't have socks!!\n");
    printf("1. Tak socks out of a drawer?\n");
    printf("2. Put more socks in a drawer?\n");
    printf("3. Display dresser\n");
    printf("4. Sort Socks\n");
    puts("");

}