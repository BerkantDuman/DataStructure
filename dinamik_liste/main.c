#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int *dinamik_dizi;
    dinamik_dizi_olustur(&dinamik_dizi,5);


    dinamik_dizi_yazdirma(dinamik_dizi,5);
    return 0;
}
void dinamik_dizi_olustur(int **dinamik_dizi, int size)
{

    int i;
    for (i=0;i<size;i++){
        *(*dinamik_dizi+i)=rand()%10;


    }


}
void dinamik_dizi_yazdirma(int *dinamik_dizi, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        printf("%d\n",*(dinamik_dizi+i));

    }
}


