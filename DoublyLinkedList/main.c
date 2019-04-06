#include <stdio.h>
#include <stdlib.h>
struct  hucre{
    int icerik;
    struct hucre *sonraki;
    struct hucre *onceki;


};
struct liste {
    struct hucre *bas;
    struct hucre *son;
};
struct hucre *hucre_olustur(int icerik){
    struct hucre *a;
    a=(struct hucre*)malloc(sizeof(struct hucre));
    if  (a == NULL)
    {
        printf("Heap'te yer oluşturulamadı");
        exit(1);
    }
    a->icerik=icerik;
    a->onceki=NULL;
    a->sonraki= NULL;
    return a;
}
void cift_yonlu_liste_olustur(struct liste **liste){
    *liste=(struct liste*)malloc(sizeof(struct liste));
    if (liste==NULL){
        printf("liste oluturulamadi...");
    }
    (*liste)->bas=(*liste)->son=NULL;
    
}
void liste_basa_eleman_ekle(struct liste *liste , int icerik){
    struct hucre *a;
    a=hucre_olustur(icerik);
    if (liste->son==NULL){
        liste->son=a;
    }
    else {
    liste->bas->onceki=a;
    a->sonraki=liste->bas;
    
    }
    liste->bas=a;
}
void sona_eleman_ekle(struct liste *liste, int icerik){
    struct hucre *a;
    a=hucre_olustur(icerik);
    if (liste->bas==NULL){
        liste->bas=a;
    }
    else{
    liste->son->sonraki=a;
    a->onceki=liste->son;
    }
    liste->son=a;
}
void liste_bastan_yazdir(struct liste *liste){
    struct hucre *a;
    a=liste->bas;
    if(liste==NULL){
        return;
    }
    while(a!=NULL){
        printf("%d ",a->icerik);
        a = a->sonraki;

    }
    printf("\n");
}
void liste_sondan_yazdir(struct liste *liste){
    struct hucre *a;
    if (liste==NULL) return;
    a=liste->son;
    while(a!=NULL)
   {
        printf("%d ",a->icerik);
        a =a->onceki;
    }
}

int main(int argc, char** argv) {
    
    struct liste *liste;
    
    cift_yonlu_liste_olustur(&liste);
    liste_basa_eleman_ekle(liste,5);
    liste_basa_eleman_ekle(liste,6);
    liste_basa_eleman_ekle(liste,7);
    sona_eleman_ekle(liste,12);
    liste_bastan_yazdir(liste);
    sona_eleman_ekle(liste,22);
    liste_sondan_yazdir(liste);
    
   
    
    return (EXIT_SUCCESS);
}

