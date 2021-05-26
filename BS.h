#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/time.h>
#include	"mergesort.h"

int search(char **list, char *target, int left, int right){
    int middle;

    while(left <= right){
    	middle =  (left + right) / 2;
    	if(strcmp(list[middle], target) == 0) return middle;
    	// 比目標大，再搜索左半邊
    	else if(strcmp(list[middle], target) < 0){
		left = middle + 1;
    	}
    	// 比目標小，再搜索右半邊
    	else if(strcmp(list[middle], target) > 0){
        	right = middle - 1;
    	}
    }
    return -1;
}

int BS(char **randStr, int dn, char **inquire, int qn){
    int i, j, a, left=0, right=dn-1;
    char **list;
    char *key;
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    printf("bs:\n");
    gettimeofday(&start, NULL);
    list = randStr;
    s_merge_sort(list, 0, dn - 1);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    /*for(int k=0;k<dn;k++){
	    printf("%s\n", list[k]);
    }*/
    printf("building time: %f sec\n", diff / 1000000.0);
    gettimeofday(&start, NULL);
    for(i=0;i<qn;i++){
        key = inquire[i];
        a = search(list, key, left, right);
    }
    /*if(a == -1) printf("找不到!\n");
    else printf("在%d位置找到\n", a);*/
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n", diff / 1000000.0);
    return 0;
}
