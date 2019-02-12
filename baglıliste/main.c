#include <stdio.h>
#include <stdlib.h>
struct  hucre{
    int icerik;
    struct hucre *sonraki;


};
struct hucre* hucre_olustur(int icerik){
    struct hucre *a;
    a=(struct hucre*)malloc(sizeof(struct hucre));
    if  (a == NULL)
    {
        printf("Heap'te yer oluşturulamadı");
        
    }
    a->icerik=icerik;
    a->sonraki=NULL;
    return a;

}
void liste_basina_eleman_ekle(struct hucre **liste_basi, int icerik){
    struct hucre* a=hucre_olustur(icerik);
    a->sonraki = *liste_basi;
    *liste_basi=a;


}
void liste_sonuna_eleman_ekle(struct hucre **liste_basi,int icerik){
    struct hucre* a=hucre_olustur(icerik);
    if (*liste_basi==NULL)
    {
        a->sonraki=*liste_basi;
        *liste_basi=a;

    }
    else {
        struct hucre *x=*liste_basi;
        while(x->sonraki != NULL){
            
            x=x->sonraki;

        }
        x->sonraki=a;
        }
}
void liste_yazdir(struct hucre *liste_basi){
    struct hucre *a=liste_basi;
    while(a!=NULL){
        printf("%2d ",a->icerik);
        a = a->sonraki;

    }
    printf("\n");
}
void liste_yaz_recursive(struct hucre *liste_basi){
    if (liste_basi!=NULL ){
        printf("%2d ",liste_basi->icerik);
        liste_yaz_recursive(liste_basi->sonraki);
    }
    else{
        printf("\n");
    }
    
}
void tersten_liste_yaz_recursive(struct hucre *liste_basi){
    if (liste_basi!=NULL){
        tersten_liste_yaz_recursive(liste_basi->sonraki);
        printf("%2d ",liste_basi->icerik);
    }
}
void sirali_listeye_ekle(struct hucre **liste_basi,int icerik){
    struct hucre *a,*b=*liste_basi;
    struct hucre *yeni;
    yeni=(struct hucre*)malloc(sizeof(struct hucre));
    
    if (*liste_basi==NULL) return ;
    if(icerik > (*liste_basi)->icerik){
        yeni->icerik=icerik;
        yeni->sonraki=*liste_basi;
        *liste_basi=yeni;
        return;
    }
    while(b->sonraki!=NULL){
        if(icerik == b->icerik) return;
        if(icerik > b->sonraki->icerik){
            yeni->icerik=icerik;
            yeni->sonraki=b->sonraki;
            b->sonraki=yeni;
        }
        a=b;
        b=b->sonraki;
    }
    yeni->icerik=icerik;
    b->sonraki=yeni;
    yeni->sonraki=NULL;
}
int main()
{
    struct hucre *liste1=NULL;
    //struct hucre *liste2=NULL;
    
    liste_sonuna_eleman_ekle(&liste1,20);
    liste_sonuna_eleman_ekle(&liste1,17);
    liste_sonuna_eleman_ekle(&liste1,14);
    liste_sonuna_eleman_ekle(&liste1,13);
    liste_sonuna_eleman_ekle(&liste1,9);
    liste_sonuna_eleman_ekle(&liste1,7);
    liste_sonuna_eleman_ekle(&liste1,5);
    liste_sonuna_eleman_ekle(&liste1,3);
    liste_sonuna_eleman_ekle(&liste1,1);
    liste_yazdir(liste1);
    sirali_listeye_ekle(&liste1,11);
    sirali_listeye_ekle(&liste1,21);
    sirali_listeye_ekle(&liste1,22);
    sirali_listeye_ekle(&liste1,0);
    sirali_listeye_ekle(&liste1,-1);
    liste_yazdir(liste1);
    
    
    

    return 0;
}