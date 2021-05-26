#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    <sys/time.h>
#define DEFMAXHASH  500000

struct dnode    {
    char *word;
    struct dnode *next;
};

long int hash65(char *line){
    char *ptr=line;
    long int hv=0;

    while(*ptr){
        if(isalpha(*ptr)){
            hv = hv * 65 + *ptr;
        }
        ptr++;
    }
    return hv;
}

struct dnode *L_find4hash(struct dnode *L, char *line){
    struct dnode *p=L;

    if(L == NULL) return NULL;
    while(p){
        if(strcmp(line, p->word) == 0){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct dnode *hash_find(struct dnode **hTab, int maxhash, char *line){
    long int hv;
    struct dnode *dptr;

    hv = hash65(line) % maxhash;
    dptr = hTab[hv];
    return L_find4hash(dptr, line);
}

struct dnode *L_insert4hash(struct dnode *L, char *line){
    struct dnode *p;
 
    p = (struct dnode *) malloc(sizeof(struct dnode));
    p->word = strdup(line);
    p->next = L;
    return p;
}

void hash_insert(struct dnode **hTab, int maxhash, char *line){
    long int hv;
    struct dnode *dptr;

    hv = hash65(line) % maxhash;
    dptr = hTab[hv];
    hTab[hv] = L_insert4hash(dptr, line);
}

int HASH(char **randStr, int dn, char **inquire, int qn){
    char *line, *key;
    struct dnode **hTab;
    struct dnode *p;
    int maxhash, i;
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    maxhash = DEFMAXHASH;
    hTab = (struct dnode **) malloc(sizeof(struct dnode *) * maxhash);
    for(i=0;i<maxhash;i++){
        hTab[i] = NULL;
    }
    printf("hash:\n");
    gettimeofday(&start, NULL);
    for(i=0;i<dn;i++){
        line = randStr[i];
        if(hash_find(hTab, maxhash, line) == NULL){
            hash_insert(hTab, maxhash, line);
        }
    }
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n", diff / 1000000.0);
    gettimeofday(&start, NULL);
    for(i=0;i<qn;i++){
        key = inquire[i];
        p = hash_find(hTab, maxhash, key);
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
