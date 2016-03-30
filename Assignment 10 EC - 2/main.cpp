/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  3/30/16
 *****************************************************/

//#include "ClassFunctions.h"
#include "BSTprinter.h"
#include <fstream>
 using namespace std;

 int main()
 {

	 FILE *myFile1;
	 myFile1 = fopen("beforeinsert.txt", "w");

	 PrintHeader(cout, "AVL Trees", "Osvaldo Moreno Ornelas", 'A', 10);

	 cout << endl << InstructionHeader("CREATING THE LIST") << endl;

	 BTreePrinter<int> printer;

	 node *listNode = new node(44);
//	 node *listNode = new node(48);
//
//	 listNode = insert(listNode,32);
//	 listNode = insert(listNode,50);
//	 listNode = insert(listNode,17);
//
//	 listNode = insert(listNode,44);
//	 listNode = insert(listNode,78);
//
//
//	 listNode = insert(listNode,49);
//	 listNode = insert(listNode,62);
//	 listNode = insert(listNode,88);


	 	 listNode = insert(listNode,17);
	 	 listNode = insert(listNode,78);
	 	 listNode = insert(listNode,32);

	 	 listNode = insert(listNode,50);
	 	 listNode = insert(listNode,88);


	 	 listNode = insert(listNode,48);
	 	 listNode = insert(listNode,62);
	 	// listNode = insert(listNode,88);

	 cout << endl << InstructionHeader("LIST BEFORE INSERTING 54") << endl;

	 printer.printNode(listNode);

	 cout << endl;
	 in_order_traversal(listNode);

	 bst_print_dot(listNode, myFile1);

	 listNode = insert(listNode,54);

	 cout << endl << InstructionHeader("LIST AFTER INSERTING 54") << endl;
	 cout << endl;
	 in_order_traversal(listNode);

	 FILE *myFile2;
	 myFile2 = fopen("afterinsert.txt", "w");

	 bst_print_dot(listNode, myFile2);
	 cout << endl << endl;

	 printer.printNode(listNode);

	 cout << endl << InstructionHeader("LIST BEFORE REMOVING 32") << endl;
	 cout << endl;
	 in_order_traversal(listNode);

	 cout << endl << endl;
	 printer.printNode(listNode);

	 FILE *myFile3;
	 myFile3 = fopen("beforedelete.txt", "w");
	 bst_print_dot(listNode, myFile3);

	listNode = remove(listNode, 32);

	cout << endl << InstructionHeader("LIST AFTER REMOVING 32") << endl;

	 cout << endl;
	 in_order_traversal(listNode);

	 cout << endl << endl;
	 printer.printNode(listNode);

	 FILE *myFile4;
	 myFile4 = fopen("afterdelete.txt", "w");
	 bst_print_dot(listNode, myFile4);
	 //void bst_print_dot(node* tree, FILE* stream)



	 //bst_print_ascii(listNode, myFile);

	 return 0;
 }
