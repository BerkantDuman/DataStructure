#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int veri;
    struct list *sonraki;
} liste;
liste *ilk=NULL;
liste *yeni,*gezici,*gezici2;


int main()
{
    sonaEkle(3);
    basaEkle(7);
    sonaEkle(8);
    basaEkle(5);
    listele();
    arayaEkle(1,8);
    listele();
    return 0;
}
void sonaEkle(int sayi)
{
    yeni=(liste*)malloc(sizeof(liste));
    yeni->veri=sayi;
    yeni->sonraki=NULL;
    if (ilk==NULL)
    {
        ilk=yeni;
    }
    else
    {
        gezici=ilk;
        while(gezici->sonraki!=NULL)
        {
            gezici=gezici->sonraki;

        }
        gezici->sonraki=yeni;
    }
}
void listele()
{
    if (ilk==NULL)
    {
        printf("LİSTE BOSS\n");
    }

    else
    {
        gezici=ilk;
        while(gezici!=NULL)
        {
            printf("%d",gezici->veri);
            gezici=gezici->sonraki;
        }
        printf("\n");
    }
}
void basaEkle(int sayi)
{
    yeni=(liste*)malloc(sizeof(liste));
    yeni->veri=sayi;
    yeni->sonraki=NULL;
    if (ilk==NULL)
    {
        ilk=yeni;
    }
    else
    {
        yeni->sonraki=ilk;
        ilk=yeni;

    }
}
void arayaEkle(int sayi,int konum)
{
    yeni=(liste*)malloc(sizeof(liste));
    yeni->veri=sayi;
    yeni->sonraki=NULL;
    gezici=ilk;
        while(gezici->sonraki->veri!=konum)
        {
            gezici=gezici->sonraki;
        }
    gezici2=gezici->sonraki;
    gezici->sonraki=yeni;
    yeni->sonraki=gezici2;
}
