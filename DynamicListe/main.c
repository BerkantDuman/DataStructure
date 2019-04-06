#include <time.h>
#include <stdlib.h>
#include <stdio.h>
void dinamik_matris_olusturma(int ***matris,int satir ,int sutun)
{
    int i,j;
    *matris=(int**)malloc(satir*sizeof(int));
    for (i=0; i<satir; i++)
    {
        *(*matris+i)=(int*)malloc(sutun*sizeof(int));
        for (j=0; j<sutun; j++)
        {
            if(i==j){
                *(*(*matris+i)+j)=1;}
            else{
                *(*(*matris+i)+j)=0;}
        }
    }
}
void dinamik_matris_yazdir(int **matris, int satir, int sutun)
{
    int i,j;
    for (i=0; i<satir; i++)
    {
        printf("\n");
        for (j=0; j<sutun; j++)
        {
            printf("%d",*(*(matris+i)+j));

        }
    }

}

int main()
{
    int **matris;
    srand(time(NULL));
    dinamik_matris_olusturma(&matris,3,3);
    dinamik_matris_yazdir(matris,3,3);

}
