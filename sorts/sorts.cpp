template <class elemType>
void insertionSort(elemType list[], int length)
{
for (int firstOutOfOrder = 1; firstOutOfOrder < length;
firstOutOfOrder++)
if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
{
elemType temp = list[firstOutOfOrder];
int location = firstOutOfOrder;
do
{
list[location] = list[location - 1];
location--;
}
while (location > 0 && list[location - 1] > temp);
list[location] = temp;
}
} //end insertionSort


template <class elemType>
void bubbleSort(elemType list[], int length)
{
for (int iteration = 1; iteration < length; iteration++)
{
for (int index = 0; index < length - iteration;
index++)
{
if (list[index] > list[index + 1])
{
elemType temp = list[index];
list[index] = list[index + 1];
list[index + 1] = temp;
}
}
}
} //end bubbleSort

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
int loc, minIndex;
minIndex = first;
for (loc = first + 1; loc <= last; loc++)
if (list[loc] < list[minIndex])
minIndex = loc;
return minIndex;
} //end minLocation
Given the locations in the list of the elements to be swapped, the following C++
function, swap, swaps those elements:
template <class elemType>
void swap(elemType list[], int first, int second)
{
elemType temp;
temp = list[first];
list[first] = list[second];
list[second] = temp;
} //end swap
We can now complete the definition of the function selectionSort:
template <class elemType>
void selectionSort(elemType list[], int length)
{
int loc, minIndex;
for (loc = 0; loc < length; loc++)
{
minIndex = minLocation(list, loc, length - 1);
swap(list, loc, minIndex);
}
} //end selectionSort



