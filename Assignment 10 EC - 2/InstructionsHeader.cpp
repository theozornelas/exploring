/*****************************************************
 *AUTHOR         :  Osvaldo Moreno Ornelas
 *CLASS          :  CS 1D
 *SECTION        :  MW:  430p - 7:50p
 *DUE DATE       :  3/30/16
 *****************************************************/

#include "ClassFunctions.h"

//outputs a header for the execution that is about to happen
string InstructionHeader(string message)
{
    ostringstream out;
    Fill(out,'*',75);
    out << endl << message<< endl;
    Fill(out,'*',75);
    out << endl;
    return out.str();
}
