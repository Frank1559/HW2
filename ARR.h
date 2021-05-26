#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <sys/time.h>

int arrSearch(char **list, int dn, char *key){
    int i;
    
    for(i=0;i<dn;i++){
        if(strcmp(key, list[i]) == 0){
            return 0;
        }
    }
    return -1;
}

int ARR(char **randStr, int dn, char **inquire, int qn){
    int i, a;
    char **list;
    char *key;
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    printf("arr:\n");
    gettimeofday(&start, NULL);
    list = randStr;
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n", diff / 1000000.0);
    gettimeofday(&start, NULL);
    for(i=0;i<qn;i++){
        key = inquire[i];
        a = arrSearch(list, dn, key);
        /*if(a == -1) printf("找不到!\n");
        else printf("在%d位置找到\n", a);*/
    }
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n", diff / 1000000.0);
    return 0;
}
