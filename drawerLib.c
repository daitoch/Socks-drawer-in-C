#include<stdio.h>
#include "drawerLib.h"

//Function to get he number of drawer
int getDrawer(SockDrawer dresser [], int key){
    int i = 0;
    int index = -1;
    do
    {
        if (key == dresser[i].drawerId)
        {
            index = i;
        }
        ++i;
    } while (i < numDrawers);
    return index;
}
//Function to get total number of drawers
void getNumDrawers(){
    int drawersNum ;
    do
    {
        printf("How many drawers does your dresser have? (1-10) ");
        scanf("%d", &drawersNum);
        if (drawersNum <= 0 || drawersNum > MAX_DRAWERS)
        {
            printf("Number of drawers must be between 1 and 10. \nPlease reenter.\n");
        }
        
    } while (drawersNum <= 0 || drawersNum > MAX_DRAWERS);
    numDrawers = drawersNum;
}
//Function to create drawers
void createDrawer(SockDrawer* drawers, int key){

    drawers->drawerId = key;
    printf("How many total socks will fit in Drawer %d? ", (key+1));
    scanf("%d", &(drawers->maxDrawerCapacity));
    puts("");
    printf("How many socks are you putting in Drawer %d? ", (key+1));
    scanf("%d", &(drawers->numberOfSocks));
    if (drawers->numberOfSocks > drawers->maxDrawerCapacity)
    {
        printf("%d socks fit in the drawer and %d fell on the floor\n", drawers->maxDrawerCapacity, drawers->numberOfSocks - drawers->maxDrawerCapacity);
        drawers->numberOfSocks = drawers->maxDrawerCapacity;
    }
    getchar();
    puts("");
    printf("What are the color of socks in drawer %d? ", (key+1));
    fgets(drawers->sockColor, 40, stdin);
    puts("");
}