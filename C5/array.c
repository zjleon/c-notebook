# include <stdarg.h>

# define ElemType int
# define MAX_ARRAY_DIM 8

typedef struct Array
{
    /* data */
    ElemType *base;
    int dim;
    int *bounds;
    int *contants;
};

int InitArray(struct Array *A, int dim, ...) {
    if (dim<1 || dim>MAX_ARRAY_DIM) return -1;
    A->dim = dim;
    A->bounds = (int *)malloc(dim*sizeof(int));
    if(!A->bounds) return -1;
    int elemTotal = 1;
    va_list ap;
    va_start(ap, dim);
    for(int i=0;i<dim;++i){
        A->bounds[i]=va_arg(ap,int);
        if(A->bounds[i]<0)return -1;
        elemTotal = elemTotal * A->bounds[i];
    }
    va_end(ap);
    A->base = (ElemType *)malloc(elemTotal*sizeof(ElemType));
    printf("elemTotal: %d\n", elemTotal);
    if(!A->base) return -1;
    A->contants=(int *)malloc(dim*sizeof(int));
    if(!A->contants) return -1;
    A->contants[dim-1]=1;
    for(int i=dim-2;i>=0;--i){
        A->contants[i]=A->bounds[i+1]*A->contants[i+1];
    }
    return 0;
}
int Locate(struct Array *A, va_list ap, int *off){
    off = 0;
    for(int i=0;i<A->dim;++i){
        int ind = va_arg(ap,int);
        if(ind<0 || ind>=A->bounds[i]) return -1;
        off += A->contants[i]*ind;
    }
    return 0;
}
int Assign(struct Array *A, ElemType e, ...){
    va_list ap;
    va_start(ap, e);
    int offset;
    int result = Locate(A, ap, &offset);
    if(result<=0) return result;
    *(A->base+offset) = e;
}


int main() {
    struct Array Arr1;
    InitArray(&Arr1, 2,3,3);
    Assign(&Arr1, 1, 1,1);
    return 0;
}
