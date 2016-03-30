/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  3/30/16
 *****************************************************/

#include "ClassFunctions.h"
#include <stdio.h>
unsigned char height(node* p)
{
	return p?p->height:0;
}

int bfactor(node* p)
{
	 return height(p->right)-height(p->left);
}

void fixheight(node* p)
{
	unsigned char hl = height(p->left);
	    unsigned char hr = height(p->right);
	    p->height = (hl>hr?hl:hr)+1;
}

node* rotateright(node* p)
{
	node* q = p->left;
	    p->left = q->right;
	    q->right = p;
	    fixheight(p);
	    fixheight(q);
	    return q;
}

node* rotateleft(node* q)
{
	 node* p = q->right;
	    q->right = p->left;
	    p->left = q;
	    fixheight(q);
	    fixheight(p);
	    return p;
}

node* balance(node* p) // balancing the p node
{
	fixheight(p);
	    if( bfactor(p)==2 )
	    {
	        if( bfactor(p->right) < 0 )
	            p->right = rotateright(p->right);
	        return rotateleft(p);
	    }
	    if( bfactor(p)==-2 )
	    {
	        if( bfactor(p->left) > 0  )
	            p->left = rotateleft(p->left);
	        return rotateright(p);
	    }
	    return p; // balancing is not required
}

node* insert(node* p, int k) // insert k key in a tree with p root
{
	if( !p ) return new node(k);
	    if( k<p->key )
	        p->left = insert(p->left,k);
	    else
	        p->right = insert(p->right,k);
	    return balance(p);
}
node* findmin(node* p) // find a node with minimal key in a p tree
{
	return p->left?findmin(p->left):p;
}
node* removemin(node* p)// deleting a node with minimal key from a p tree
{
	 if( p->left==0 )
	        return p->right;
	    p->left = removemin(p->left);
	    return balance(p);
}

node* remove(node* p, int k) // deleting k key from p tree
{
	if( !p ) return 0;
	    if( k < p->key )
	        p->left = remove(p->left,k);
	    else if( k > p->key )
	        p->right = remove(p->right,k);
	    else //  k == p->key
	    {
	        node* q = p->left;
	        node* r = p->right;
	        delete p;
	        if( !r ) return q;
	        node* min = findmin(r);
	        min->right = removemin(min);
	        min->left = q;
	        return balance(min);
	    }
	    return balance(p);
}

void bst_print_ascii(node* tree, FILE* stream)
{
	static int offset = 0;

	    print_offset(stream, offset);

	    if (tree == NULL)
	    {
	        fprintf(stream, "-\n");
	        return;
	    }
	    fprintf(stream, "%d\n", tree->key);

	    offset += 3;
	    bst_print_ascii(tree->left, stream);
	    bst_print_ascii(tree->right, stream);
	    offset -= 3;
}

void print_offset(FILE* stream, int offset)
{
	int i;
	    for (i = 0; i < offset; ++i)
	    {
	        fprintf(stream, " ");
	    }
}


void bst_print_dot_null(int key, int nullcount, FILE* stream)
{
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    %d -> null%d;\n", key, nullcount);
}

void bst_print_dot_aux(node* node, FILE* stream)
{
    static int nullcount = 0;

    if (node->left)
    {
        fprintf(stream, "    %d -> %d;\n", node->key, node->left->key);
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node->key, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    %d -> %d;\n", node->key, node->right->key);
        bst_print_dot_aux(node->right, stream);
    }
    else
        bst_print_dot_null(node->key, nullcount++, stream);
}

void bst_print_dot(node* tree, FILE* stream)
{
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %d;\n", tree->key);
    else
        bst_print_dot_aux(tree, stream);

    fprintf(stream, "}\n");
}

string Print(node* p)
{
	ostringstream out;

	out << printLeft(p) << " " << printRight(p);

	return out.str();
}

string printLeft(node* p)
{
	ostringstream out;


	if(p != NULL)
	{
		out << p->left->key;
		printLeft(p->left);
	}


	return out.str();
}

string printRight(node *p)
{
	ostringstream out;
	if(p != NULL)
		{
			out << p->right->key;
			printLeft(p->right);
		}
	return out.str();
}

void in_order_traversal(node *p)
{
        if(p != NULL)
        {
                in_order_traversal(p->left);
                cout << p->key << " ";
                in_order_traversal(p->right);
        }
}
