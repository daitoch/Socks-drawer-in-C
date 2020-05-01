#include<stdio.h>
#include<stdlib.h>

//Custom header files
#include "sockLib.h"
#include "drawerLib.h"
#include "dresserLib.h"
#include "sortLib.h"


//Function pointer array for qsort function
void sortMySocks(SockDrawer dresser[], int len){
    
    int (*fun_ptr[])(const void *, const void *) = {draweridCompare, numberOfSocksCompare, MaxCapacityCompare, sockColorCompare};
    int check, summ;
    do
    {
        printf("Do you want to sort by?\n\n");
        printf("0. Change my mind - don;t want to sort\n");
        printf("1. DrawerId?\n");
        printf("2. Number of socks in drawer?\n");
        printf("3. Max capacity of the drawers?\n");
        printf("4. Socks color?\n");
        puts("");
        scanf("%d", &check);
        if (check <= 0 || check > 4)
        {
            if (check == 0)
            {
                printf("Your drawers are a messs\n");
            }
            else
            {
                printf("Enter a valid number\n");
            }  
        }
        else
        {
            qsort(dresser, len, sizeof(SockDrawer), fun_ptr[check-1]);//qsort function for different sortings

        }
        displayMyDresser(dresser);

    } while (check != 0);
   
    
    
}
//Function to remove socks from the drawer
void putAwayMySocks(SockDrawer dresser[]){
    int some, draw, socks, getDrawers;
    printf("Which drawer do you want to get socks from? ");
    do
    {
        scanf("%d", &draw);
        getDrawers = getDrawer(dresser, draw-1);
        if (getDrawers == -1)
        {
            printf("That's not one of your drawers !!");
            printf("Pick again\n\n");
            some = 1;
        }
        else
        {
            some = 0;
        }    
    } while (some);
    
    printf("How many socks are you getting out? ");
    scanf("%d", &socks);
    if (socks > dresser[getDrawers].numberOfSocks)
    {
     printf("You don't have that many sock!! You only get %d socks\n\n", dresser[getDrawers].numberOfSocks);
     displayMyDresser(dresser);
    }
    else
    {
        dresser[getDrawers].numberOfSocks -= socks;
        displayMyDresser(dresser);
    }
    
}
//Function to add socks to the drawer
void putOnMySocks(SockDrawer dresser[]){
    int some, draw, socks, getDrawers;
    printf("Which drawer are you putting socks into? ");
    do
    {
        scanf("%d", &draw);
        getDrawers = getDrawer(dresser, draw-1);
        if (getDrawers == -1)
        {
            printf("That's not one of your drawers !!");
            printf("Pick again\n\n");
            some = 1;
        }
        else
        {
            some = 0;
        }
    } while (some);

    printf("How many socks are you putting away? ");
    scanf("%d", &socks);
    if ((dresser[getDrawers].maxDrawerCapacity + socks) > dresser[getDrawers].maxDrawerCapacity)
    {
        int num = dresser[getDrawers].maxDrawerCapacity - dresser[getDrawers].numberOfSocks;
        dresser[getDrawers].numberOfSocks = dresser[getDrawers].maxDrawerCapacity;
        printf("%d socks fit in the drawer and %d fell on the floor\n", num, socks - num);
        displayMyDresser(dresser);
    }
    else
    {
        dresser[getDrawers].numberOfSocks += socks;
        displayMyDresser(dresser);
    }
    
}