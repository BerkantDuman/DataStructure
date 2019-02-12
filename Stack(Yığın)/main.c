#include <stdio.h>
#include <stdlib.h>
struct stack {
    int *dizi;
    int kapasite;
    int ust;
};
struct stack* yigin_olustur(int kapasite){
    if(kapasite<=0){
        printf("Kapasite 0'dan büyük bir tam sayi olmalıdır...");
    }
    struct stack *yigin=(struct stack *)malloc(sizeof(struct stack));
    yigin->dizi=(int *)malloc(kapasite*sizeof(int));
    yigin->ust=-1;
    yigin->kapasite=kapasite;
    return yigin;
}
void yigin_olustur_parametreile(int kapasite, struct stack **yigin){
    if (kapasite<=0){
        printf("kapasite pozitif bir tam sayi olmalıdır...");
    }
    *yigin=(struct stack *)malloc(sizeof(struct stack));
    (*yigin)->dizi=(int *)malloc(kapasite*sizeof(int));
    (*yigin)->ust=-1;
    (*yigin)->kapasite=kapasite;
    
}
int yigin_dolumu(struct stack *yigin){
    if(yigin->ust==(yigin->kapasite-1)){
        return(1);
    }
    else {
        return(0);
    }
}
int yigin_bosmu(struct stack *yigin){
    if (yigin->ust==-1){
        return(1);
    }
    else{
        return(0);
    }
}
void yigina_eleman_ekle(struct stack *yigin , int eleman){
    if(yigin_dolumu(yigin)){
        printf("Bu yigin dolu olduğundan ekleme yapılamıyor...");
    }
    else {
        yigin->dizi[++yigin->ust]=eleman;
    }
}
void yigin_yazdir(struct stack *yigin){
    printf("Yigin kapasitesi = %d\n",yigin->kapasite);
    printf("Yigin eleman sayisi = %d\n",yigin->ust+1);
    for (int i=yigin->ust;i>=0;i--){  
        printf("%d  ",yigin->dizi[i]);
    }
    printf("\n-------------------------------------------\n");
}
void yigin_eleman_sil(struct stack *yigin){
    if(yigin_bosmu(yigin)){
        printf("Bu yigin zaten bos....");
    }
    else{
        yigin->ust=yigin->ust-1;
    }
    printf("\n");
}
void yigin_yoket (struct stack **yigin){
    free((*yigin)->dizi);
    free(*yigin);
    *yigin=NULL;
    printf("Yigin yok edildi.......\n---------------------------------\n");

}
void kapasite_arttir(struct stack **yigin, int kackat){
    struct stack *yeni;
    yeni=yigin_olustur(((*yigin)->kapasite)*2);
    for(int i=0;i<=(*yigin)->ust;i++){
        yeni->dizi[i]=(*yigin)->dizi[i];
    }
    
    yeni->ust=(*yigin)->ust;
    yigin_yoket(&(*yigin));
    *yigin=yeni;
}

int main(int argc, char** argv) {
    struct stack *A=NULL;
    struct stack *B=NULL;
    B=yigin_olustur(10);
    //yigin_olustur_parametreile(10,&A);
    yigina_eleman_ekle(B,10);
    yigina_eleman_ekle(B,57);
    yigina_eleman_ekle(B,65);
    yigina_eleman_ekle(B,30);
    yigina_eleman_ekle(B,12);
   
    /*yigina_eleman_ekle(A,10);
    yigina_eleman_ekle(A,57);
    yigina_eleman_ekle(A,65);
    yigina_eleman_ekle(A,30);
    yigina_eleman_ekle(A,12);
    
   yigin_yazdir(A);
    yigin_eleman_sil(A);
    yigin_yazdir(A);
    yigina_eleman_ekle(A,56);
    yigin_yazdir(A);
    kapasite_arttir(&A,2);
    yigina_eleman_ekle(A,4555);
    yigin_yazdir(A);
    yigin_eleman_sil(A);
    yigin_yazdir(A);*/
    
    
    yigin_yazdir(B);
    yigin_yoket(&B);
    yigin_yazdir(B);
    
    return (EXIT_SUCCESS);
}

