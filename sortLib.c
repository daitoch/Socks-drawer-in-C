#include "sortLib.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Comparision functions for qsort
int draweridCompare(const void * a, const void * b){
    SockDrawer *orderA = (SockDrawer *)a;
    SockDrawer *orderB = (SockDrawer *)b;

  return ( orderB->drawerId - orderA->drawerId );
}

int numberOfSocksCompare(const void * a, const void * b){
    SockDrawer *orderA = (SockDrawer *)a;
    SockDrawer *orderB = (SockDrawer *)b;

  return ( orderB->numberOfSocks - orderA->numberOfSocks );
}

int MaxCapacityCompare(const void * a, const void * b){
    SockDrawer *orderA = (SockDrawer *)a;
    SockDrawer *orderB = (SockDrawer *)b;

  return ( orderB->maxDrawerCapacity - orderA->maxDrawerCapacity );
}

int sockColorCompare(const void * a, const void * b){
    SockDrawer *orderA = (SockDrawer *)a;
    SockDrawer *orderb = (SockDrawer *)b;

    return (strcmp (orderA->sockColor, orderb->sockColor));
}
