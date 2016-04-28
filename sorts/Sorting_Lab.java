/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sorting_lab;

import java.util.Random;

/**
 *
 * @author osvaldomorenoornelas
 */
public class Sorting_Lab {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        int size = 1000000;
        Random rand = new Random(); 
        
        int [] arList1 = new int [size];
        int [] arList2 = new int [size];
        int [] arList3 = new int [size];
        
        for(int i  = 0; i<size; i++){
            arList1[i] = rand.nextInt(size);
            arList2[i] = rand.nextInt(size);
            arList3[i] = rand.nextInt(size);
            //System.out.println(arList1[i]);
        }
        
        long mergeStart = System.nanoTime();
        mergeSort(arList1);
        long mergeEnd   = System.nanoTime();
        
        System.out.println("It took: " + (mergeEnd-mergeStart) + " Nanoseconds to do Merge sort");
        
        long insertionStart = System.nanoTime();
        InsertionSort(arList2);
        long insertionEnd = System.nanoTime();
        
        System.out.println("It took: " + (insertionEnd-insertionStart) + " Nanoseconds to do Insertion sort");
        
        long quickStart = System.nanoTime();
        quickSort(arList3);
        long quickEnd = System.nanoTime();
        
        System.out.println("It took: " + (quickEnd-quickStart) + " Nanoseconds to do Quick sort");
        
        System.out.println("");
        System.out.println("");
        
//        for(int j = 0; j<size; j++){
//            System.out.println(arList1[j]);
//        }
//        
//        System.out.println("");
//        System.out.println("");
//        System.out.println("");
//        
//         for(int k = 0; k<size; k++){
//            System.out.println(arList2[k]);
//        }
//         System.out.println("");
//         System.out.println("");
//         System.out.println("");
//         
//          for(int h = 0; h<size; h++){
//            System.out.println(arList3[h]);
//        }
    }
    
    public static void InsertionSort(int [] intAr){
        
        for(int i = 0; i<intAr.length; i++){
            int currentElem = intAr[i];
            int k;
            
            for(k = i-1; k>=0&&intAr[k]>currentElem; k--){
                intAr[k+1] = intAr[k];
            }
            
            intAr[k+1] = currentElem;
        }
    }
    
    public static void mergeSort(int[] list){
        if(list.length > 1){
            int [] firstHalf = new int [list.length/2];
            System.arraycopy(list, 0, firstHalf, 0, list.length/2);
            mergeSort(firstHalf);
            
            int secondHalfLenght = list.length-list.length/2;
            int[] secondHalf = new int[secondHalfLenght];
            System.arraycopy(list, list.length/2, secondHalf, 0, secondHalfLenght);
            mergeSort(secondHalf);
            
            merge(firstHalf, secondHalf,list);
        }//end of if
    }//end of method
    
    
    public static void merge(int[] list1, int [] list2, int [] temp){
        int current1 = 0;
        int current2 = 0;
        int current3 = 0;
        
        while(current1 < list1.length && current2 < list2.length){
            if(list1[current1]<list2[current2]){
                temp[current3++] = list1[current1++];
            }
            else{
                temp[current3++] = list2[current2++];
            }
        }//end of while
        
        while(current1 < list1.length){
            temp[current3++] = list1[current1++];
        }//end of while
        
        while(current2 < list2.length){
            temp[current3++] = list2[current2++];
        }//end of while
    }//end of method
    
    
    public static void quickSort(int[] list){
        quickSort(list,0,list.length-1);
    }//end of method
    
    public static void quickSort(int[] list, int first, int last){
        
        if(last > first){
            int pivotIndex = partition(list,first,last);
            quickSort(list,first,pivotIndex-1);
            quickSort(list, pivotIndex+1,last);
        }//end of if
               
    }//end method
    
    public static int partition(int [] list, int first, int last){
        
        int pivot = list[first];
        int low = first + 1;
        int high = last;
        
        while(high > low){
            while(low <= high && list[low] <= pivot){
                low++;
            }//end of second while
            while(low <= high && list[high] > pivot){
                high--;
            }//end of third while
            
            if(high > low){
                int temp = list[high];
                list[high] = list[low];
                list[low] = temp;
            }//end of if
        }//end of first while
        
        while(high > first && list[high] >= pivot){
            high--;//changed
        }//end of while
        
        if(pivot > list[high]){
            list[first] = list[high];
            list[high] = pivot;
            return high;
        }//end of if
        else{
            
            return first;
        }
        
        
    }//end of method
}
