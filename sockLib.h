#ifndef SOCKLIB_H
#define SOCKLIB_H

#define MAX_DRAWERS 10
 
typedef struct sockLib
{
    int drawerId;
    int numberOfSocks;
    char sockColor[40];
    int maxDrawerCapacity;
}SockDrawer;
void sortMySocks(SockDrawer dresser[], int len);
void putAwayMySocks(SockDrawer dresser[]);
void putOnMySocks(SockDrawer dresser[]);

#endif