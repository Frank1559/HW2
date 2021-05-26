#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/time.h>
#include	"BST.h"
#include	"BS.h"
#include	"LL.h"
#include	"ARR.h"
#include	"HASH.h"

char **Random(int n, char **randStr){
    int i, j;
    char c;
    char *word;

    srand(1);
    for(i=0;i<n;i++){
	word = (char *) malloc(sizeof(char) * 6);
        for(j=0;j<5;j++){
            c = 'a' + (rand() % 26);
            word[j] = c;
        }
        word[5] = '\0';
	randStr[i] = word;
	//printf("%s\n", randStr[i]);
    }
    return randStr;
}

char **randquire(int n, char **inquire){
    int i, j;
    char c;
    char *word;

    srand(101);
    for(i=0;i<n;i++){
	word = (char *) malloc(sizeof(char) * 6);
        for(j=0;j<5;j++){
            c = 'a' + (rand() % 26);
            word[j] = c;
        }
        word[5] = '\0';
	inquire[i] = word;
    }
    return inquire;
}

int main(int argc, char *argv[]){
    int i=1, j, dcnt=0, qcnt=0, dn=0, qn=0;
    char **randStr;
    char **inquire;
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;

    j = argc;
    if(j > 1){
        while((i < j) && argv[i]){
            if((strcmp(argv[i], "-d") == 0) && dcnt < 2){
                dcnt++;
                if((i + 1 < j) && (strcmp(argv[i+1], "1e4") == 0)){
                    dn = 10000;
		    randStr = (char **) malloc(sizeof(char *) * dn);
                    randStr = Random(dn, randStr);
		    /*for(int k=0;k<dn;k++){
			printf("%s\n", randStr[k]);
		    }*/
                    i++;
                }
                else if((i + 1 < j) && (strcmp(argv[i+1], "1e5") == 0)){
                    dn = 100000;
                    randStr = (char **) malloc(sizeof(char *) * dn);
                    Random(dn, randStr);
                    i++;
                }
                else if((i + 1 < j) && (strcmp(argv[i+1], "1e6") == 0)){
                    dn = 1000000;
                    randStr = (char **) malloc(sizeof(char *) * dn);
                    Random(dn, randStr);
                    i++;
                }
                else{
                    printf("error format\n");
                    exit(1);
                }
            }
            else if((strcmp(argv[i], "-q") == 0) && qcnt < 2){
                qcnt++;
                if((i + 1 < j) && (strcmp(argv[i+1], "1e3") == 0)){
                    qn = 1000;
                    inquire = (char **) malloc(sizeof(char *) * qn);
                    randquire(qn, inquire);
                    i++;
                }
                else if((i + 1 < j) && (strcmp(argv[i+1], "1e4") == 0)){
                    qn = 10000;
                    inquire = (char **) malloc(sizeof(char *) * qn);
                    randquire(qn, inquire);
                    i++;
                }
                else if((i + 1 < j) && (strcmp(argv[i+1], "1e5") == 0)){
                    qn = 100000;
                    inquire = (char **) malloc(sizeof(char *) * qn);
                    randquire(qn, inquire);
                    i++;
                }
                else{
                    printf("error format\n");
                    exit(1);
                }
            }
            else if((strcmp(argv[i], "-bst") == 0) && dn >= qn){ 
                BST(randStr, dn, inquire, qn);
            }
            else if((strcmp(argv[i], "-bs") == 0) && dn >= qn){
                BS(randStr, dn, inquire, qn);
            }
            else if((strcmp(argv[i], "-arr") == 0) && dn >= qn){
                ARR(randStr, dn, inquire, qn);
            }
            else if((strcmp(argv[i], "-ll") == 0) && dn >= qn){
                LL(randStr, dn, inquire, qn);
            }
            else if((strcmp(argv[i], "-hash") == 0) && dn >= qn){
                HASH(randStr, dn, inquire, qn);
            }
            else{
                printf("error format\n");
                exit(1);
            }
            i++;
        }
    }
    return 0;
}
