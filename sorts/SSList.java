/*
 * SSList.java
 *
 * Osvaldo Moreno Ornelas  04/04/14      
 *
 * Period: 2.
 * 
 * This Data Class implements a SSList - a list of Strings with operations on
 * the strings like searching, sorting, ...
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

public class SSList {
    //-------------------- Private GLOBAL Data -----------------

    ArrayList<String> myList = new ArrayList();
    //private String[] myList;
    private final int WORDSIZE = 5;//changeble

    //-------------------- Constructors ------------------------
    public SSList() {
        // Creates an empty list
        myList = new ArrayList();
    }

    public SSList(int n) {
        // Creates a list of n random words of length WORDSIZE
        // -- Call createword(int) to create the words
        myList = new ArrayList(n);
        for (int i = 0; i < n; i++) {
            myList.add(CreateWord(WORDSIZE));
        }
    }

    //-------------------- Public Methods-----------------------
    public int size() {
        // returns the size of the list
        return myList.size();
    }

    public void add(String s) {
        myList.add(s);
    }

    public String get(int i) {
        // Returns the string at index i or "" if i is invalid
        if (myList.size() > 0) {
            return myList.get(i);
        } else {
            return "" + -1;
        }


    }

    public String toString() {
        // Returns a string representation of the list in a nice columned
        // chart to be used by System.out.println()
        //this code is the same as the one in the scores project it gives a list with rows of 4 words
        int col = 4;
        String s = "";
        for (int i = 0; i < myList.size(); i++) {
            String temp = myList.get(i) + " ";
            while (temp.length() <= 4) {
                temp = " " + temp;
            }
            s += temp;
            if ((i + 1) % col == 0) {
                s += "\n";
            }
        }
        return s;
    }
// -----------------------------------------------------------------------------

    public int LinearSearch(String s) {
        // Searches for s in the list and returns the index or -1
        // Remember that you cannot use == with strings since they are objects
        // - you need to use .equals() or .compareTo()
        for (int i = 0; i < size(); i++) {
            if (myList.get(i).equalsIgnoreCase(s)) {
                return i;
            }
        }
        return -1;
    }

    public int BinarySearch(String s) {
        // Searches for s in a Sorted list and returns the index or -1
        // Remember that you cannot use == with strings since they are objects
        // - you need to use .equals() or .compareTo()
        int start = 0;//index 0
        int end = myList.size() - 1;
        while (end >= start) {//if end is bigger than start
            int middle = (start + end) / 2;//middle of list by doing average formula
            if (myList.get(middle).equalsIgnoreCase(s)) {
                return middle;//if the middle one is the one you need
            } else if (myList.get(middle).compareToIgnoreCase(s) > 0) {//is is not there
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }

        return -1;
    }
// -----------------------------------------------------------------------------

    public void BubbleSort() {
        // Sorts the list using the Bubble Sort algorithm
        // Remember that you cannot use == with strings since they are objects
        // - you need to use .equals() or .compareTo()
        boolean swapped;
        int len = myList.size() - 2;
        do {
            swapped = false;
            for (int i = 0; i <= len; i++) {
                if (myList.get(i).compareTo(myList.get(i + 1)) >= 0) {
                    Swap(i, i + 1);
                    swapped = true;
                }
            }
            len--;//decrement lenght
        } while (swapped);//swapping

    }
// -----------------------------------------------------------------------------

    public void InsertionSort() {
        // Sorts the list using the Insertion Sort algorithm
        // Remember that you cannot use == with strings since they are objects
        // - you need to use .equals() or .compareTo()
        //
        // This should call the private insert() method below
        for (int i = 1; i < myList.size(); i++) {
            Insert(myList.get(i), i - 1);
        }
    }

    private void Insert(String value, int last) {
        // This will insert the string v into myList in the already sorted
        // top of the list from 0 to last. There should not be a call to swap
        // Used by InsertionSort()
        while (last >= 0 && (myList.get(last).compareToIgnoreCase(value)) > 0) {
            //myList[last + 1] = myList[last];
           // myList.set(myList.get(last), myList.get(last+1));
           myList.set(last + 1, myList.get(last));
            
            last--;
        }
        myList.set(last + 1, value);
    }
// -----------------------------------------------------------------------------

    public void SelectionSort() {
        // Sorts the list using the Selection Sort algorithm
        // Remember that you cannot use == with strings since they are objects
        // - you need to use .equals() or .compareTo()
        //
        // This should call the private Smallest method below

        for (int i = 0; i < myList.size() - 1; i++) {
            int s = Smallest(i, myList.size());
            Swap(i, s);
        }
    }

    private int Smallest(int start, int last) {
        // find the index of the smallest value in myList between start and the
        // end of myList. Used by SelectionSort()
        int small = start;
        for (int i = (start + 1); i < last; i++) {
            if (myList.get(i).compareTo(myList.get(small)) < 0) {
                small = i;
            }
        }
        return small;
    }
// -----------------------------------------------------------------------------

    public boolean WritetoDisk(String filename) {
        // creates a text file named filename and writes the words
        // in myList to the text file one per line
        try {
            FileWriter out = new FileWriter(filename);
            BufferedWriter buffer = new BufferedWriter(out);

            for (int i = 0; i < myList.size(); i++) {
                buffer.write(myList.get(i));
                buffer.newLine();
            }
            buffer.close();
        } catch (IOException ex) {
            return false;
        }

        return true;
    }

    public boolean ReadfromDisk(String filename) {
        // opens a text file named filename and reads the words one per line
        // and adds them to an empty list (use add())
        SSList tmp = new SSList();
        try {
            FileReader in = new FileReader(filename);

            BufferedReader buffer = new BufferedReader(in);

            String Word = buffer.readLine();
            while (Word != null) {
                tmp.add(Word);
                Word = buffer.readLine();
            }

            buffer.close();
        } catch (IOException ex) {
            return false;
        }
        myList = tmp.myList;
        return true;
    }
    //-------------------- Private Utility Methods------------------------------

    private void Swap(int a, int b) {
        // swaps the ath and bth values in myList
        String temp = myList.get(a);
        myList.set(a, myList.get(b));
        myList.set(b, temp);

    }

    private String CreateWord(int len) {
        // Creates a Random Capitalized Word of length len
        String tmp = "";
        Random gen = new Random();
        for (int i = 0; i < len; i++) {
            tmp += (char) ('A' + gen.nextInt(26));
        }
        return tmp;
    }
    public void MergeSort(){
       Msort(0, myList.size()-1);
    }

    private void Msort(int s, int e){
        if(s<e){
            int m =(s+e)/2;
            Msort(s,m);
            Msort(m+1,e);
            Merge (s,m,m+1,e);
        }
    }
    private void Merge (int s1 , int e1, int s2, int e2){
        ArrayList <String> tmp = new ArrayList (e2-s1+1);
        int start =s1;
        while(s1<=e1 && s2 <= e2){
            if(myList.get(s1).compareTo(myList.get(s2))>0){
                tmp.add(myList.get(s2++));
            }else{
                tmp.add(myList.get(s1++));
            }
        }//end of while
        for(; s1<=e1;s1++){
            tmp.add(myList.get(s1));
        }
        for(;s2<=e2;s2++){
            tmp.add(myList.get(s2));
        }
        for(int i =0; i<tmp.size();i++){
            myList.set(start+i,tmp.get(i));
        }
    }
    
    public void QuickSort(){
        if(myList.size()>1){
            QSort(0,myList.size()-1);
        }
    }
    
    private void QSort (int start, int end){
        int low = start;
        int high = end;
        
        String midvalue = myList.get((start+end)/2);
        
        do{
            while(myList.get(low).compareTo(midvalue)<0){
                low++;
            }
            while(myList.get(high).compareTo(midvalue)>0){
                high--;
            }
            if(low<=high){
                Swap(low,high);
                low++;
                high--;
            }//if
            
        }while(low<=high);//while of the do
        
        if (start < high){
           QSort(start,high); 
        }//if
        if(end>low){
            QSort(low,end);
        }
    }//method end
    
    public int RbinSearch(String v) {
       
        return RBinSearch(v, 0 , myList.size() - 1);
    }

    private int RBinSearch(String v, int s, int e) {

        if (s > e) {
            return -1;
        } else {
            int middle = (s + e) / 2;
            int i = myList.get(middle).compareTo(v);

            if (i == 0) {
                return middle;
            }else if (i > 0) {
                return RBinSearch(v, s, middle - 1);
            } else {
                return RBinSearch(v, middle + 1, e);
            }
        }
    }
}
