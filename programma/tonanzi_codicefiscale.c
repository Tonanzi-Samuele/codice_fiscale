#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define var 50
#define COMUNI "comuni.txt"
FILE *pf;
char CF[15];

char com[var];
char cognome()
{
    int voca = 0;
    int con = 0;
    int lencog = 0;
    char cog[var];
    char voc[var];
    char cons[var];

    printf("inserisci cognome: ");
    scanf("%s", cog);
    lencog = strlen(cog);
    // toupper(cog);
    for(int i = 0; i < lencog; i++)
        cog[i] = toupper(cog[i]);
    
    for (int i = 0; i < lencog; i++)
    {
        if (cog[i] == 'A' || cog[i] == 'E' || cog[i] == 'I' || cog[i] == 'O' || cog[i] == 'U')
        {
            // printf("%c\n", cog[i]);
            voc[voca] = cog[i];
            voca++;
        }
        else
        {
            cons[con] = cog[i];
            con++;
        }
    }

    if (con >= 3)
    {
        for (int i = 0; i < 3; i++)
        {
            CF[i] = cons[i];
        }
    }

    if (con == 2)
    {
        CF[0] = cons[0];
        CF[1] = cons[1];
        CF[2] = cons[0];
    }

    if (con == 1 && voca == 2)
    {
        CF[0] = cons[0];
        CF[1] = cons[0];
        CF[2] = cons[1];
    }

    if (con == 1 && voca == 1)
    {
        CF[0] = cons[0];
        CF[1] = cons[0];
        CF[2] = 'X';
    }

    if (con == 0 && voca == 2)
    {
        CF[0] = cons[0];
        CF[1] = cons[0];
        CF[2] = 'X';
    }
}
char name()
{
    int vocs = 0, cons = 0, lennom = 0;
    char nom[var];
    char con[var];
    char voc[var];
    printf("inserire nome: ");
    scanf("%s", nom);

    lennom = strlen(nom);
    for(int i=0;i<lennom;i++){
        nom[i]=toupper(nom[i]);
    }
    for (int i = 0; i < lennom; i++)
    {
        if (nom[i] == 'A' || nom[i] == 'E' || nom[i] == 'I' || nom[i] == 'O' || nom[i] == 'U')
        {
            voc[vocs] = nom[i];
            vocs++;
        }
        else
        {
            con[cons] = nom[i];
            cons++;
        }
    }

    if (cons >= 4)
    {
        CF[3] = con[0];
        CF[4] = con[2];
        CF[5] = con[3];
    }
    if (cons == 3)
    {
        CF[3] = con[0];
        CF[4] = con[1];
        CF[5] = con[2];
    }
    if (cons == 2)
    {
        CF[3] = con[0];
        CF[4] = con[1];
        CF[5] = voc[0];
    }
    if (cons == 1 && vocs == 2)
    {
        CF[3] = con[0];
        CF[4] = voc[0];
        CF[5] = voc[1];
    }
    if (cons == 1 && vocs == 1)
    {
        CF[3] = con[0];

        CF[4] = voc[0];
        CF[5] = 'X';
    }
    if (cons == 0 && vocs == 2)
    {
        CF[3] = voc[0];
        CF[4] = voc[1];
        CF[5] = 'X';
    }
}
char data()
{

    int v;
    char anno[4];                                                                 // dichiarazione stringa per input dell'anno
    char mese[12] = {'A', 'B', 'C', 'D', 'E', 'H', 'L', 'M', 'P', 'R', 'S', 'T'}; // stringa che contiene le lettere per l'input del mese
    char giorn[2];
    char giorno[2]="";
    char sesso[var];
    printf("inserire anno: ");
    scanf("%s", anno);
    CF[6] = anno[2];
    CF[7] = anno[3];

    printf("inserire mese: ");
    scanf("%d", &v);
    CF[8] = mese[v - 1];

    printf("inserire giorno: ");
    scanf("%s", giorn);
    if(strlen(giorn)==1){
        giorno[0]='0';
        giorno[1]=giorn[0];
    }
    else{
        giorno[0]=giorn[0];
        giorno[1]=giorn[1];
    }
    printf("inserire sesso: ");
    scanf("%s", sesso);
    int s=strlen(sesso);
    for(int i=0;i<s;i++){
    sesso[i]=toupper(sesso[i]);
    }
    if (sesso[0] == 'M')
    {
        CF[9] = giorno[0];
        CF[10] = giorno[1];
    }
    else if (sesso[0] == 'F')
    {
        CF[9] = (giorno[0] + 4);
        CF[10] = giorno[1];
    }
}
char cata()
{

    char comune[var], codice[var], comunefile[var];
    printf("inserire comune: ");
    scanf("%s", comune);
    int lencom=strlen(comune);
    for(int i=0; i<lencom;i++){
        comune[i]=toupper(comune[i]);
    }
    pf = fopen(COMUNI, "r");
    if (pf)
    {
        while (fscanf(pf, "%s %s", codice, comunefile) != EOF)
        {
            if (strcmp(comunefile, comune) == 0)
            {
                break;
            }
        }
    }
    else
    {
        printf("errore di lettura file!");
    }
    fclose(pf);

    CF[11] = codice[0];
    CF[12] = codice[1];
    CF[13] = codice[2];
    CF[14] = codice[3];
}

char lettera(){
    int somma=0;
    int resto=0;
    
    for(int i=0; i<15;i++){
        if(i%2!=0){
            switch(CF[i]){
                case 'A':
                somma+=0;
                   break;
                case 'B':
                somma+=1;
                   break;
                case 'C':
                somma+=2;
                   break;
                case 'D':
                somma+=3;
                   break;
                case 'E':
                somma+=4;
                   break;
                case 'F':
                somma+=5;
                   break;
                case 'G':
                somma+=6;
                   break;
                case 'H':
                somma+=7;
                   break;
                case 'I':
                somma+=8;
                   break;
                case 'J':
                somma+=9;
                   break;
                case 'K':
                somma+=10;
                   break;
                case 'L':
                somma+=11;
                   break;
                case 'M':
                somma+=12;
                   break;
                case 'N':
                somma+=13;
                   break;
                case 'O':
                somma+=14;
                   break;
                case 'P':
                somma+=15;
                   break;
                case 'Q':
                somma+=16;
                   break;
                case 'R':
                somma+=17;
                   break;
                case 'S':
                somma+=18;
                   break;
                case 'T':
                somma+=19;
                   break;
                case 'U':
                somma+=20;
                   break;
                case 'V':
                somma+=21;
                   break;
                case 'W':
                somma+=22;
                   break;
                case 'X':
                somma+=23;
                   break;
                case 'Y':
                somma+=24;
                   break;
                case 'Z':
                somma+=25;
                   break;
                case '0':
                somma+=0;
                   break;
                case '1':
                somma+=1;
                   break;
                case '2':
                somma+=2;
                   break;
                case '3':
                somma+=3;
                   break;
                case '4':
                somma+=4;
                   break;
                case '5':
                somma+=5;
                   break;
                case '6':
                somma+=6;
                   break;
                case '7':
                somma+=7;
                   break;
                case '8':
                somma+=8;
                   break;
                case '9':
                somma+=9;
                   break;
                
                
            }
            
        }
        else{
            switch(CF[i]){
                
            
              case 'A':
                somma+=1;
                   break;
                case 'B':
                somma+=0;
                   break;
                case 'C':
                somma+=5;
                   break;
                case 'D':
                somma+=7;
                   break;
                case 'E':
                somma+=9;
                   break;
                case 'F':
                somma+=13;
                   break;
                case 'G':
                somma+=15;
                   break;
                case 'H':
                somma+=17;
                   break;
                case 'I':
                somma+=19;
                   break;
                case 'J':
                somma+=21;
                   break;
                case 'K':
                somma+=2;
                   break;
                case 'L':
                somma+=4;
                   break;
                case 'M':
                somma+=18;
                   break;
                case 'N':
                somma+=20;
                   break;
                case 'O':
                somma+=11;
                   break;
                case 'P':
                somma+=3;
                   break;
                case 'Q':
                somma+=6;
                   break;
                case 'R':
                somma+=8;
                   break;
                case 'S':
                somma+=12;
                   break;
                case 'T':
                somma+=14;
                   break;
                case 'U':
                somma+=16;
                   break;
                case 'V':
                somma+=10;
                   break;
                case 'W':
                somma+=22;
                   break;
                case 'X':
                somma+=25;
                   break;
                case 'Y':
                somma+=24;
                   break;
                case 'Z':
                somma+=23;
                   break;
                case '0':
                somma+=1;
                   break;
                case '1':
                somma+=0;
                   break;
                case '2':
                somma+=5;
                   break;
                case '3':
                somma+=7;
                   break;
                case '4':
                somma+=9;
                   break;
                case '5':
                somma+=13;
                   break;
                case '6':
                somma+=15;
                   break;
                case '7':
                somma+=17;
                   break;
                case '8':
                somma+=19;
                   break;
                case '9':
                somma+=21;
                   break;
                
            }
        }
        
    }
    
    
resto=somma%26;
    switch(resto){
        case 0:
        CF[15]='A';
         break;
        case 1:
        CF[15]='B';
         break;
        case 2:
        CF[15]='C';
         break;
        case 3:
        CF[15]='D';
         break;
        case 4:
        CF[15]='E';
         break;
        case 5:
        CF[15]='F';
         break;
        case 6:
        CF[15]='G';
         break;
        case 7:
        CF[15]='H';
         break;
        case 8:
        CF[15]='I';
         break;
        case 9:
        CF[15]='J';
         break;
        case 10:
        CF[15]='K';
          break;
        case 11:
        CF[15]='L';
          break;
        case 12:
        CF[15]='M';
          break;
        case 13:
        CF[15]='N';
          break;
        case 14:
        CF[15]='O';
          break;
        case 15:
        CF[15]='P';
          break;
        case 16:
        CF[15]='Q';
          break;
        case 17:
        CF[15]='R';
          break;
        case 18:
        CF[15]='S';
          break;
        case 19:
        CF[15]='T';
          break;
        case 20:
        CF[15]='U';
          break;
        case 21:
        CF[15]='V';
          break;
        case 22:
        CF[15]='W';
          break;
        case 23:
        CF[15]='X';
          break;
        case 24:
        CF[15]='Y';
          break;
        case 25:
        CF[15]='Z';
          break;
        
    }
}

char cognome_inverso(){
    char cognome_inv[3];
    
    cognome_inv[0]=CF[0];
    cognome_inv[1]=CF[1];
    cognome_inv[2]=CF[2];
    printf("cognome: %s\n", cognome_inv);
}

char nome_inverso(){
    char nome_inv[3];
    
    nome_inv[0]=CF[3];
    nome_inv[1]=CF[4];
    nome_inv[2]=CF[5];
    printf("nome: %s\n", nome_inv);
}
char anno_inverso(){
    char anno_inv[4];
    if(CF[6]=='0'||CF[6]=='1'||CF[6]=='2'){
        anno_inv[0]='2';
        anno_inv[1]='0';
        anno_inv[2]=CF[6];
        anno_inv[3]=CF[7];
        printf("anno: %s\n", anno_inv);
    }
    else{
        anno_inv[0]='1';
        anno_inv[1]='9';
        anno_inv[2]=CF[6];
        anno_inv[3]=CF[7];
        printf("anno: %s\n", anno_inv);
    }
}

char mese_inverso(){
    char mese_inv[12]="ABCDEHLMPRST";
    
    for(int i=0;i<12;i++){
    if(CF[8]==mese_inv[i]){
        printf("mese: %d\n", i + 1);
    }
}
}
char giorno_inverso(){
    char giorno_inv[2];
    if(CF[9]=='4'||CF[9]=='5'||CF[9]=='6'||CF[9]=='7'){
        giorno_inv[0] = (CF[9] - 4);
        giorno_inv[1] = CF[10];
    }
    else{
        giorno_inv[0] = CF[9];
        giorno_inv[1] = CF[10];
    }
    printf("giorno: %s\n", giorno_inv);
}
char comune_inverso(){
    char codice[var], comunefile[var];
    char cata[5]={CF[11],CF[12],CF[13],CF[14],'\0'};
     pf = fopen(COMUNI, "r");
    if (pf)
    {
        while (fscanf(pf, "%s %s", codice, comunefile) != EOF)
        {
            if (strcmp(codice, cata) == 0)
            {
                break;
            }
        }
    }
    else
    {
        printf("errore di lettura file!");
    }
    fclose(pf);
    printf("comune: %s", comunefile);
}

int main()
{
    int scelta;
    printf("se si vuole calcolare il codice fiscale inserire 1\n se si vogliono ricavare i dati inserire 2\n");
    scanf("%d", &scelta);
    switch(scelta){
        case 1:
        cognome(); // entra nella funzione che permette di ricevere il cognome
        name();    // entra nella funzione che permette di ricevere il nome
        data();    // entra nella funzione che permette di ricevere la data
        cata();
        lettera(); 
        printf("%s", CF);    
        break;
        
        case 2:
        printf("inserire codice fiscale: ");
        scanf("%s", CF);
        cognome_inverso();
        nome_inverso();
        anno_inverso();
        mese_inverso();
        giorno_inverso();
        comune_inverso();
    }
}