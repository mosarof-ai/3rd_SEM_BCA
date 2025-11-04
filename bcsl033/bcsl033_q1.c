#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r1,c1,r2,c2;
    printf("Rows Columns for first matrix: ");
    if(scanf("%d %d",&r1,&c1)!=2) return 1;
    printf("Rows Columns for second matrix: ");
    if(scanf("%d %d",&r2,&c2)!=2) return 1;
    if(c1!=r2){ printf("Error: columns of first must\n equal rows of second\n"); return 1; }

    int *a = malloc(r1*c1*sizeof(int));
    int *b = malloc(r2*c2*sizeof(int));
    int *res = calloc(r1*c2,sizeof(int));
    if(!a||!b||!res){ fprintf(stderr,"Allocation failed\n"); return 1; }

    for(int i=0;i<r1;i++){
        printf("Row %d of matrix1 (%d numbers): ", i, c1);
        for(int j=0;j<c1;j++) scanf("%d",&a[i*c1+j]);
    }
    for(int i=0;i<r2;i++){
        printf("Row %d of matrix2 (%d numbers): ", i, c2);
        for(int j=0;j<c2;j++) scanf("%d",&b[i*c2+j]);
    }

    for(int i=0;i<r1;i++)
        for(int k=0;k<c1;k++){
            int aik = a[i*c1+k];
            for(int j=0;j<c2;j++) res[i*c2+j] += aik * b[k*c2+j];
        }

    printf("\nMatrix1:\n");
    for(int i=0;i<r1;i++){ for(int j=0;j<c1;j++) printf("%d\t", a[i*c1+j]); printf("\n"); }
    printf("\nMatrix2:\n");
    for(int i=0;i<r2;i++){ for(int j=0;j<c2;j++) printf("%d\t", b[i*c2+j]); printf("\n"); }
    printf("\nResult:\n");
    for(int i=0;i<r1;i++){ for(int j=0;j<c2;j++) printf("%d\t", res[i*c2+j]); printf("\n"); }

    free(a); free(b); free(res);
    return 0;
}
