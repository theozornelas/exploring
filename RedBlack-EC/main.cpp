/*
 * main.cpp
 *
 *  Created on: Apr 1, 2016
 *      Author: osvaldo
 */
#include "RedBlackTree.h"


int main(){

	RBtree myTree;

	int dataAr[10];

	for(int index = 0; index <10; index++){
		dataAr[index] = index+1;

		myTree.insert(dataAr[index]);
	}

	myTree.disp();

	return 0;
}