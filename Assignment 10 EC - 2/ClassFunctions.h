/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  3/30/16
 *****************************************************/

#ifndef CLASSFUNCTIONS_H_
#define CLASSFUNCTIONS_H_

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

struct node
{
    int key;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = 0; height = 1; }
};

unsigned char height(node* p);

int bfactor(node* p);

void fixheight(node* p);

node* rotateright(node* p);

node* rotateleft(node* q);

node* balance(node* p); // balancing the p node

node* insert(node* p, int k); // insert k key in a tree with p root

node* findmin(node* p); // find a node with minimal key in a p tree

node* removemin(node* p); // deleting a node with minimal key from a p tree

node* remove(node* p, int k); // deleting k key from p tree

string printLeft(node* p);

string printRight(node *p);

string Print(node* p);

void in_order_traversal(node *p);

void bst_print_ascii(node* tree, FILE* stream);

void print_offset(FILE* stream, int offset);

void bst_print_dot_null(int key, int nullcount, FILE* stream);

void bst_print_dot_aux(node* node, FILE* stream);

void bst_print_dot(node* tree, FILE* stream);

void PrintHeader(ostream& outputF, // OUT - class header to file
                 string asName,    // IN  - Assignment name
                 string programers,// IN  - Programmer(s) name
                 char asType,      // IN  - Type of project
        //      (lab or assignment)
                 int asNum);        // IN  - Project number


void Fill(ostream& outputT, //OUT - output stream
          char fillChar,    //IN  - character to fill the line with
          int width);        //IN  - width of the line to be filled out


string InstructionHeader(string message);
#endif /* CLASSFUNCTIONS_H_ */
