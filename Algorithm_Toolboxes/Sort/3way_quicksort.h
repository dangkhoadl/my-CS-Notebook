
/******************** 3-way quicksort ***************/	
// For sorting array which have many duplicates:	
//  Ex:  2 3 9 2 2 2 5 9 8 7 2 8 2 4 4 5 6 2	

 /* This function partitions a[] in three parts	
a) a[l..i] contains all elements smaller than pivot	
b) a[i+1..j-1] contains all occurrences of pivot	
c) a[j..r] contains all elements greater than pivot */	

 // Dutch National Flag Algorithm	
void partition(int a[], int left, int right, int &i, int &j) {	
    // To handle 2 elements	
    if (right - left <= 1) {	
        if (a[right] < a[left])	
            swap(a[right], a[left]);	
        i = left;	
        j = right;	
        return;	
    }	

    int mid = left;	
    int pivot =  a[left + rand() % (right - left)];	
    while (mid <= right) {	
        if (a[mid]<pivot)	
            swap(a[left++], a[mid++]);	
        else if (a[mid]==pivot)	
            mid++;	
        else if (a[mid]>pivot)	
            swap(a[mid], a[right--]);	
    }	

     //update i and j	
    i = left-1;	
    j = mid; //or right-1	
}	

 // 3-way partition based quick sort	
void quicksort(int a[], int left, int right) {	
    if (left>=right) //1 or 0 elements	
        return;	

     int i, j;	

     // Note that i and j are passed as reference	
    partition(a, left, right, i, j);	

     // Recur two halves	
    quicksort(a, left, i);	
    quicksort(a, j, right);	
}
