/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  4/06/16
 *****************************************************/
#include "RedBlackTree.h"

int main(){

	PrintHeader(cout, "Red Black Tree Implementation", "Osvaldo Moreno Ornelas", 'A',11);

	RBtree myTree;

	int dataAr[6] = {33,22,50,44,55,60};

	cout << endl << InstructionHeader("INSERTING INTO THE TREE") << endl;

	for(int index = 0; index <6; index++){

		cout << "Inserting.... " << dataAr[index] << endl;

		myTree.insert(dataAr[index]);
	}

	cout << endl << InstructionHeader("Tree after insertions") << endl;

	myTree.printTree();


	cout << endl << InstructionHeader("ABOUT TO DELETE 50 FROM TREE") << endl;
	myTree.del(50);

	cout << endl << InstructionHeader("TREE AFTER DELETING 50") << endl;
	myTree.printTree();

	myTree.del(45);


	myTree.printTree();

	return 0;
}
