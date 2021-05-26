#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <sys/time.h>

struct L_list  {
    char *word;
    struct  L_list *next;
};

struct L_list *L_Find(struct L_list *L, char *line){
    struct L_list *p=L;
    while(p){
        if(strcmp(line, p->word) == 0){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct L_list *insert_f(struct L_list *L, char *line){
    struct L_list *p;

    p = (struct L_list *) malloc(sizeof(struct L_list));
    p->word = strdup(line);
    p->next = L;
    return p;
}

int LL(char **randStr, int dn, char **inquire, int qn){
    char *line, *key;
    struct L_list *keylist=NULL, *p;
    int i;
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    printf("ll:\n");
    gettimeofday(&start, NULL);
    for(i=0;i<dn;i++){
        line = randStr[i];
        keylist = insert_f(keylist, line);
    }
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n", diff / 1000000.0);
    gettimeofday(&start, NULL);
    for(i=0;i<qn;i++){
        key = inquire[i];
        p = L_Find(keylist, line);
        if(p == NULL){
            //printf("NOT find!\n");
        }
        else {}//printf("find:%s!\n", p->word);
    }
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n", diff / 1000000.0);
    return 0;
}
