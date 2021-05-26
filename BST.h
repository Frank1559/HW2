#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/time.h>

struct tnode    {
    char *word;
    struct tnode *LC;
    struct tnode *RC;
};

struct tnode *BST_find(struct tnode *t, char *line){

    if(t == NULL) return NULL;
    else{
        if(strcmp(line, t->word) == 0) return t;
        else if(strcmp(line, t->word) < 0){
            return BST_find(t->LC, line);
        }
        else return BST_find(t->RC, line);
    }
    return NULL;
}

struct tnode *BST_insert(struct tnode *t, char *line){
    struct tnode *p;

    if(t == NULL){
        p = (struct tnode *) malloc(sizeof(struct tnode));
        p->word = strdup(line);
        p->LC = NULL;
        p->RC = NULL;
        return p;
    }
    if(strcmp(line, t->word) < 0) t->LC = BST_insert(t->LC, line);
    else t->RC = BST_insert(t->RC, line);
    return t;
}

int BST(char **randStr, int dn, char **inquire, int qn){
    struct tnode *tree=NULL, *p;
    char *line, *key;
    int i;
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
	
    printf("bst:\n");
    gettimeofday(&start, NULL);
    for(i=0;i<dn;i++){
        line = randStr[i];
        if(BST_find(tree, line) == NULL){
            tree = BST_insert(tree, line);
        }
    }
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n", diff / 1000000.0);
    gettimeofday(&start, NULL);
    for(i=0;i<qn;i++){
        key = inquire[i];
        p = BST_find(tree, key);
        if(p == NULL){
            //printf("NOT find!\n");
        }
        else {}//printf("In place %d find:%s\n", i, p->word);
    }
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n", diff / 1000000.0);
    return 0;
}
