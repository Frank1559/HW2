#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

void s_merge(char *arr[], int head, int mid, int tail){
        int lenA = mid - head + 1;
        int lenB = tail - (mid + 1) + 1;
        char *A[lenA];
        char *B[lenB];

        //Copy data to temp arrays A[] and B[]
        int i, j, k;
        for(i = 0; i < lenA; i++){
                A[i] = arr[head + i];
        }
        for(j = 0; j < lenB; j++){
                B[j] = arr[mid + 1 + j];
        }
        // Merge two temp arrays back into arr[head..tail]
        i = 0;
        j = 0;
        k = head;
        //while array A and B haven't finished scanning
        while(i < lenA && j < lenB){
                if(strcmp(A[i], B[j]) < 0){
                        arr[k] = A[i];
                        i++;
                }
                else{
                        arr[k] = B[j];
                        j++;
                }
                k++;
        }
        //Copy the remaing elements into arr[], if A[] haven't finished scanning
        while(i < lenA){
                arr[k] = A[i];
                i++;
                k++;
        }
        //Copy the remaing elements into arr[], if B[] haven't finished scanning
        while(j < lenB){
                arr[k] = B[j];
                j++;
                k++;
        }
}

void s_merge_sort(char *arr[], int head, int tail){
        if(head < tail){
                int mid = (head + tail) / 2;
                s_merge_sort(arr, head, mid);
                s_merge_sort(arr, mid+1, tail);
                s_merge(arr, head, mid, tail);
        }
}
