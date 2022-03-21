#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct przedmioty
{
    int numer;
    char *nazwa;
    char *stan;
    int kwota;
    int cena;
    char *data;
    struct przedmioty *pnast;
}el_przedmioty;
struct przedmioty *nowy;
struct przedmioty *pocz=NULL;
struct przedmioty *koniec=NULL;

struct klienci
{
    char *imie;
    char *nazwisko;
    int zastawione;
    int kupione;
    int wydane;
    struct klienci *nast;
}el_klienci;
struct klienci *nowy_k;
struct klienci *pocz_k=NULL;
struct klienci *koniec_k=NULL;

void wczytaj_p()
{
    FILE *p;
    int nr;
    char naz[20];
    char st[20];
    int kw;
    int cen;
    char dat[20];
    p=fopen("przedmioty.txt","r");
    if(p!=NULL)
    {
        while(feof(p)==0)
        {
             nowy=(struct przedmioty*)malloc(sizeof(el_przedmioty));

             fscanf(p,"%d",&nr);
             nowy->numer=nr;

             fscanf(p,"%s",&naz);
             nowy->nazwa=(char *)malloc( sizeof(char) * strlen(naz)+1);
             strcpy(nowy->nazwa,naz);

             fscanf(p,"%s",&st);
             nowy->stan=(char *)malloc( sizeof(char) * strlen(st)+1);
             strcpy(nowy->stan,st);

             fscanf(p,"%d",&kw);
             nowy->kwota=kw;

             fscanf(p,"%d",&cen);
             nowy->cena=cen;

             fscanf(p,"%s",&dat);
             nowy->data=(char *)malloc( sizeof(char) * strlen(dat)+1);
             strcpy(nowy->data,dat);

             nowy->pnast= NULL;

             if (koniec==NULL) pocz=koniec=nowy;
             else
             {
                koniec->pnast=nowy;
                koniec=nowy;
             }
        }
        fclose(p);
    }
}
void wstaw_p()
{
    int nr;
    char naz[20];
    char st[20];
    int kw;
    int cen;
    char dat[20];

    nowy=(struct przedmioty*)malloc(sizeof(el_przedmioty));

    printf("Podaj wartosc nowego elementu\n");
    printf("numer: \n");
    scanf("%d",&nr);
    nowy->numer=nr;

    printf("nazwa: \n");
    scanf("%s",&naz);
    nowy->nazwa=(char *)malloc( sizeof(char) * strlen(naz)+1);
    strcpy(nowy->nazwa,naz);

    printf("stan:do_sprzedazy / zastawiony \n");
    scanf("%s",&st);
    nowy->stan=(char *)malloc( sizeof(char) * strlen(st)+1);
    strcpy(nowy->stan,st);

    printf("kwota: \n");
    scanf("%d",&kw);
    nowy->kwota=kw;

    printf("cena: \n");
    scanf("%d",&cen);
    nowy->cena=cen;

    printf("data: rok.miesiac.dzien\n");
    scanf("%s",&dat);
    nowy->data=(char *)malloc( sizeof(char) * strlen(dat)+1);
    strcpy(nowy->data,dat);

    nowy->pnast= NULL;

    if(koniec==NULL) pocz=koniec=nowy;
    else
    {
        koniec->pnast=nowy;
        koniec=nowy;
    }
}
void wypisz_p()
{
    struct przedmioty *tmp;
    tmp=(struct przedmioty*)malloc(sizeof(el_przedmioty));
    if(pocz==NULL)
    {
         printf("Pusta baza danych\n");
    }
    else
    {
        tmp=pocz;
        while(tmp)
        {
            printf("%d ",tmp->numer);
            printf("%s ",tmp->nazwa);
            printf("%s ",tmp->stan);
            printf("%d ",tmp->kwota);
            printf("%d ",tmp->cena);
            printf("%s \n",tmp->data);
            tmp=tmp->pnast;
        }
    }
    printf("\n\n");
}
void wypisz_cena_p()
{
    int a,b;
    printf("Podaj zakres cenowy:... ... \n");
    scanf("%d %d",&a,&b);
    struct przedmioty *tmp;
    if(pocz==NULL)
    {
         printf("Pusta baza danych\n");
    }
    else
    {
        tmp=pocz;
        while(tmp)
        {
            if(tmp->cena >a && tmp->cena <b)
            {
                printf("%d ",tmp->numer);
                printf("%s ",tmp->nazwa);
                printf("%s ",tmp->stan);
                printf("%d ",tmp->kwota);
                printf("%d ",tmp->cena);
                printf("%s \n",tmp->data);
            }
            tmp=tmp->pnast;
        }
    }
    printf("\n\n");
}
void wypisz_status_p()
{
    int a;
    printf("Podaj status: 1- zastawiony 2-do_sprzedazy \n");
    scanf("%d",&a);

    struct przedmioty *tmp;
    tmp=(struct przedmioty*)malloc(sizeof(el_przedmioty));

    if(pocz==NULL)
    {
         printf("Pusta baza danych\n");
    }
    else
    {
        tmp=pocz;
        if (a==1)
        {
            while(tmp)
            {

               if(strcmp(tmp->stan, "zastawiony")==0)
                {

                    printf("%d ",tmp->numer);
                    printf("%s ",tmp->nazwa);
                    printf("%s ",tmp->stan);
                    printf("%d ",tmp->kwota);
                    printf("%d ",tmp->cena);
                    printf("%s \n",tmp->data);
                }
                tmp=tmp->pnast;
            }
        }

        if(a==2)
            {
                while(tmp)
                {
                    if(tmp->stan=="do_sprzedazy")
                    {
                        printf("%d ",tmp->numer);
                        printf("%s ",tmp->nazwa);
                        printf("%s ",tmp->stan);
                        printf("%d ",tmp->kwota);
                        printf("%d ",tmp->cena);
                        printf("%s \n",tmp->data);
                    }
                    tmp=tmp->pnast;
                }
            }
        printf("\n\n");
    }
}
void edytuj_p()
{
   int element;
   int nr;
   char naz[20];
   char st[20];
   int kw;
   int cen;
   char dat[20];

   nowy=pocz;
   printf("Podaj numer przedmiotu, ktory chcesz edytowac\n");
   scanf("%d",&element);

   while (nowy!=NULL)
   {
     if (nowy->numer==element)
     {
        printf("stary numer: %d \t nowy numer: \n",nowy->numer);
        scanf("%d",&nr);
        nowy->numer=nr;

        printf("stara nazwa: %s \t nowa nazwa: \n",nowy->nazwa);
        scanf("%s",&naz);
        nowy->nazwa=(char *)malloc( sizeof(char) * strlen(naz)+1);
        strcpy(nowy->nazwa,naz);

        printf("stary stan: %s \t nowy stan:do_sprzedazy / zastawiony \n",nowy->stan);
        scanf("%s",&st);
        nowy->stan=(char *)malloc( sizeof(char) * strlen(st)+1);
        strcpy(nowy->stan,st);

        printf("stara kwota: %d \t nowa kwota: \n",nowy->kwota);
        scanf("%d",&kw);
        nowy->kwota=kw;

        printf("stara cena: %d \t nowa cena: \n",nowy->cena);
        scanf("%d",&cen);
        nowy->cena=cen;

        printf("stara data: %s \t nowa data: rok.miesiac.dzien\n",nowy->data);
        scanf("%s",&dat);
        nowy->data=(char *)malloc( sizeof(char) * strlen(dat)+1);
        strcpy(nowy->data,dat);

        nowy->pnast= NULL;
        break;

     }
     else
     {
       nowy = nowy->pnast;
     }
   }

 }
void usun_p()
{
   int element;
   nowy=pocz;
   printf("Podaj numer przedmiotu, który chcesz usunac\n");
   scanf("%d",&element);
   while (nowy->pnast != NULL)
   {
     if (nowy->pnast->numer==element)
     {
       struct przedmioty *usuwany=nowy->pnast;
       nowy->pnast = usuwany->pnast;
       free(usuwany);
     }
     else
     {
       nowy = nowy->pnast;
     }
   }
 }

void wczytaj_k()
{
    FILE *r;
    char im[20];
    char naz[20];
    int zas;
    int kup;
    int wyd;
    r=fopen("klienci.txt","r");
    if(r!=NULL)
    {
        while(feof(r)==0)
        {
             nowy_k=(struct klienci*)malloc(sizeof(el_klienci));

             fscanf(r,"%s",&im);
             nowy_k->imie=(char *)malloc( sizeof(char) * strlen(im)+1);
             strcpy(nowy_k->imie,im);

             fscanf(r,"%s",&naz);
             nowy_k->nazwisko=(char *)malloc( sizeof(char) * strlen(naz)+1);
             strcpy(nowy_k->nazwisko,naz);

             fscanf(r,"%d",&zas);
             nowy_k->zastawione=zas;

             fscanf(r,"%d",&kup);
             nowy_k->kupione=kup;

             fscanf(r,"%d",&wyd);
             nowy_k->wydane=wyd;

             nowy_k->nast= NULL;

             if (koniec_k==NULL) pocz_k=koniec_k=nowy_k;
             else
             {
                koniec_k->nast=nowy_k;
                koniec_k=nowy_k;
             }
        }
        fclose(r);
    }
}
void wstaw_k()
{
    char im[20];
    char naz[20];
    int zas;
    int kup;
    int wyd;

    nowy_k=(struct klienci*)malloc(sizeof(el_klienci));

    printf("Podaj imie nowego klienta: \n");
    scanf("%s",&im);
    nowy_k->imie=(char *)malloc( sizeof(char) * strlen(im)+1);
    strcpy(nowy_k->imie,im);

    printf("nazwisko: \n");
    scanf("%s",&naz);
    nowy_k->nazwisko=(char *)malloc( sizeof(char) * strlen(naz)+1);
    strcpy(nowy_k->nazwisko,naz);

    printf("numer przedmiotu zastawionego (jesli klient nic nie zastawia wstaw 0): \n");
    scanf("%d",&zas);
    nowy_k->zastawione=zas;

    printf("numer przedmiotu kupionego (jesli klient nic nie kupuje wstaw 0): \n");
    scanf("%d",&kup);
    nowy_k->kupione=kup;

    printf("ile pieniedzy wydal klient: \n");
    scanf("%d",&wyd);
    nowy_k->wydane=wyd;

    nowy_k->nast= NULL;

    if(koniec_k==NULL) pocz_k=koniec_k=nowy_k;
    else
    {
        koniec_k->nast=nowy_k;
        koniec_k=nowy_k;
    }
}
void wypisz_k()
{
    struct klienci *tmp_k;
    tmp_k=(struct klienci*)malloc(sizeof(el_klienci));
    if(pocz_k==NULL)
    {
         printf("Pusta baza danych\n");
    }
    else
    {
        tmp_k=pocz_k;
        while(tmp_k)
        {
            printf("%s ",tmp_k->imie);
            printf("%s ",tmp_k->nazwisko);
            printf("%d ",tmp_k->zastawione);
            printf("%d ",tmp_k->kupione);
            printf("%d \n",tmp_k->wydane);
            tmp_k=tmp_k->nast;
        }
    }
    printf("\n\n");
}
void wypisz_kwota_k()
{
    int a,b;
    printf("Podaj zakres kwoty:... ... \n");
    scanf("%d %d",&a,&b);
    struct klienci *tmp_k;
    if(pocz_k==NULL)
    {
         printf("Pusta baza danych\n");
    }
    else
    {
        tmp_k=pocz_k;
        while(tmp_k)
        {
            if(tmp_k->wydane >a && tmp_k->wydane <b)
            {
                printf("%s ",tmp_k->imie);
                printf("%s ",tmp_k->nazwisko);
                printf("%d ",tmp_k->zastawione);
                printf("%d ",tmp_k->kupione);
                printf("%d \n",tmp_k->wydane);
            }
            tmp_k=tmp_k->nast;
        }
    }
    printf("\n\n");
}
void wypisz_nazwisko_k()
{
    char a[20];
    printf("Podaj nazwisko:\n");
    scanf("%s",&a);

    struct klienci *tmp_k;
    tmp_k=(struct klienci*)malloc(sizeof(el_klienci));

    if(pocz_k==NULL)
    {
         printf("Pusta baza danych\n");
    }
    else
    {
        tmp_k=pocz_k;
        while(tmp_k)
        {
            if(strcmp(tmp_k->nazwisko, a)==0)
            {
                printf("%s ",tmp_k->imie);
                printf("%s ",tmp_k->nazwisko);
                printf("%d ",tmp_k->zastawione);
                printf("%d ",tmp_k->kupione);
                printf("%d \n",tmp_k->wydane);
            }
            tmp_k=tmp_k->nast;
        }
        printf("\n\n");
    }
}
void edytuj_k()
{
    char element[20];
    char im[20];
    char naz[20];
    int zas;
    int kup;
    int wyd;

   nowy_k=pocz_k;
   printf("Podaj nazwisko klienta, ktorego chcesz edytowac\n");
   scanf("%s",&element);

   while (nowy_k!=NULL)
   {
     if (nowy_k->nazwisko==element)
     {
        printf("stare imie: %s \t nowe imie: \n",nowy_k->imie);
        scanf("%s",&im);
        nowy_k->imie=(char *)malloc( sizeof(char) * strlen(im)+1);
        strcpy(nowy_k->imie,im);

        printf("stare nazwisko: %s \t nowe nazwisko: \n",nowy_k->nazwisko);
        scanf("%s",&naz);
        nowy_k->nazwisko=(char *)malloc( sizeof(char) * strlen(naz)+1);
        strcpy(nowy_k->nazwisko,naz);

        printf("stary numer elementu zastawionego: %d \t nowy numer elementu zastawionego: \n",nowy_k->zastawione);
        scanf("%d",&zas);
        nowy_k->zastawione=zas;

        printf("stary numer elementu kupionego: %d \t nowy numer elementu kupionego: \n",nowy_k->kupione);
        scanf("%d",&kup);
        nowy_k->kupione=kup;

        printf("stary wydana kwota: %d \t nowa wydana kwota: \n",nowy_k->wydane);
        scanf("%d",&wyd);
        nowy_k->wydane=wyd;

        nowy_k->nast= NULL;
        break;

     }
     else
     {
       nowy_k=nowy_k->nast;
     }
   }
 }
void usun_k()
{
   char element[20];
   nowy_k=pocz_k;
   printf("Podaj nazwisko klienta, ktorego chcesz usunac\n");
   scanf("%s",&element);
   while (nowy_k->nast != NULL)
   {
     if (nowy_k->nast->nazwisko==element)
     {
       struct klienci *usuwany=nowy_k->nast;
       nowy_k->nast = usuwany->nast;
       free(usuwany);
     }
     else
     {
       nowy_k = nowy_k->nast;
     }
   }
 }

void zapisz()
{
    FILE *p;
    p = fopen("przedmioty.txt", "w");
    nowy=pocz;
    while(nowy!=NULL)
    {
        fprintf(p,"\n%d ",nowy->numer);
        fprintf(p,"%s ",nowy->nazwa);
        fprintf(p,"%s ",nowy->stan);
        fprintf(p,"%d ",nowy->kwota);
        fprintf(p,"%d ",nowy->cena);
        fprintf(p,"%s ",nowy->data);
        nowy=nowy->pnast;
    }
    fclose(p);

    FILE *r;
    r= fopen("klienci.txt", "w");
    nowy_k=pocz_k;
    while(nowy_k!=NULL)
    {
        fprintf(r,"\n%s ",nowy_k->imie);
        fprintf(r,"%s ",nowy_k->nazwisko);
        fprintf(r,"%d ",nowy_k->zastawione);
        fprintf(r,"%d ",nowy_k->kupione);
        fprintf(r,"%d ",nowy_k->wydane);
        nowy_k=nowy_k->nast;
    }
    fclose(r);
}

int main()
{
    char g;
    printf("Wybierz funkcje: \n");
    printf("1-dodaj przedmiot\n2-wypisz przedmioty wedlug statusu\n3-wypisz przedmioty wedlug przedzialu cenowego\n4-wypisz przedmioty\n5-usun przedmiot\n6-edytuj przedmiot\n\n");
    printf("a-dodaj klienta \nb-wypisz klientow wedlug wydanej kwoty\nc-wypisz klientow wedlug nazwiska\nd-wypisz klientow\ne-usun klienta\nf-edytuj klienta\n7-zakoncz");
    wczytaj_p();
    wczytaj_k();

    do
    {
        g=getch();
        system( "cls" );

        switch(g)
        {
        case '1':

                wstaw_p();
                break;
        case '2':
            {
                wypisz_status_p();
                break;}
        case '3':
            {
                wypisz_cena_p();
                break;}
        case '4':
            {
                wypisz_p();
                break;}
        case '5':
            {
                usun_p();
                break;}
        case '6':
            {
                edytuj_p();
                break;}
        case 'a':

                wstaw_k();
                break;
        case 'b':
            {
                wypisz_kwota_k();
                break;}
        case 'c':
            {
                wypisz_nazwisko_k();
                break;}
        case 'd':
            {
                wypisz_k();
                break;}
        case 'e':
            {
                usun_k();
                break;}
        case 'f':
            {
                edytuj_k();
                break;}
        case '7':
            {
                zapisz();
                printf("Koniec\n");
                break;}
        default: printf("blad\n");
        break;
        }
        printf("1-dodaj przedmiot\n2-wypisz przedmioty wedlug statusu\n3-wypisz przedmioty wedlug przedzialu cenowego\n4-wypisz przedmioty\n5-usun przedmiot\n6-edytuj przedmiot\n\n");
        printf("a-dodaj klienta \nb-wypisz klientow wedlug wydanej kwoty\nc-wypisz klientow wedlug nazwiska\nd-wypisz klientow\ne-usun klienta\nf-edytuj klienta\n7-zakoncz");
    }
    while(g!='7');
}
