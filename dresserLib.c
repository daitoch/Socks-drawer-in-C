#include<stdio.h>
#include "dresserLib.h"
#include "drawerLib.h"

void displayMyDresser(SockDrawer dresser[]){
    printf("My Dresser\n\n");
    int i = 0;
    while (i < numDrawers)
    {
        printf("Dresser %d\n", i+1);
        printf("\tContents : %d %s", dresser[i].numberOfSocks, dresser[i].sockColor);
        printf("\tCapacity : %d socks\n", dresser[i].maxDrawerCapacity);
        printf("\tid : %d \n", dresser[i].drawerId);      
        ++i;
    }
    
    return;  
}