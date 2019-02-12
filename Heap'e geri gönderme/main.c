#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void dinamik_dizi_olusturma(int **dizi,int size)
{
    int i;
    *dizi=(int*)malloc(size*sizeof(int));
    for (i=0; i<size; i++)
    {
        *(*dizi+i)=i;

    }

}
void dinamik_dizi_yadirma(int *dizi , int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        printf("%d",*(dizi+i));
    }

}
int main()
{
    srand(time(NULL));
    int *dizi;
    dinamik_dizi_olusturma(&dizi,5);
    dinamik_dizi_yadirma(dizi,5);

    return 0;
}
