#include "sockLib.h"


#ifndef DRAWERLIB_H
#define DRAWERLIB_H
int numDrawers;

int getDrawer(SockDrawer dresser [], int key);
void getNumDrawers();
void createDrawer(SockDrawer* drawers, int key);

#endif