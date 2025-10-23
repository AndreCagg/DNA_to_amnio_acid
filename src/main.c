#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char codoneToAminoacid(const char* codone) {
    switch (codone[0]) {
        case 'A':
            switch (codone[1]) {
                case 'T':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'T') return 'I';
                    else if (codone[2] == 'G') return 'M';
                    break;
                case 'C':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'T';
                    break;
                case 'A':
                    if (codone[2] == 'A' || codone[2] == 'G') return 'K';
                    else if (codone[2] == 'C' || codone[2] == 'T') return 'N';
                    break;
                case 'G':
                    if (codone[2] == 'A' || codone[2] == 'G') return 'R';
                    else if (codone[2] == 'C' || codone[2] == 'T') return 'S';
                    break;
            }
            break;
        case 'C':
            switch (codone[1]) {
                case 'T':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'L';
                    break;
                case 'C':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'P';
                    break;
                case 'A':
                    if (codone[2] == 'A' || codone[2] == 'G') return 'Q';
                    else if (codone[2] == 'C' || codone[2] == 'T') return 'H';
                    break;
                case 'G':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'R';
                    break;
            }
            break;
        case 'G':
            switch (codone[1]) {
                case 'T':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'V';
                    break;
                case 'C':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'A';
                    break;
                case 'A':
                    if (codone[2] == 'A' || codone[2] == 'G') return 'E';
                    else if (codone[2] == 'C' || codone[2] == 'T') return 'D';
                    break;
                case 'G':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'G';
                    break;
            }
            break;
        case 'T':
            switch (codone[1]) {
                case 'C':
                    if (codone[2] == 'A' || codone[2] == 'C' || codone[2] == 'G' || codone[2] == 'T') return 'S';
                    break;
                case 'T':
                    if (codone[2] == 'C' || codone[2] == 'T') return 'F';
                    else if (codone[2] == 'A' || codone[2] == 'G') return 'L';
                    break;
                case 'A':
                    if (codone[2] == 'A' || codone[2] == 'G') return '_'; // codice di stop
                    else if (codone[2] == 'C' || codone[2] == 'T') return 'Y';
                    break;
                case 'G':
                    if (codone[2] == 'G') return 'W';
                    else if (codone[2] == 'A') return '_';
                    else return 'C';
                    break;
            }
            break;
    }
    return '?'; // codone non riconosciuto
}


int main(){
    FILE *dna, *trans;
    char *res, prot[4], temp;
    int n=0, messi=0, dim=9;

    res=malloc(dim*sizeof(char)); //allocazione della stringa risultante
    if(res==NULL){
        perror("Errore nell'allocazione della stringa risultante");
        exit(1);
    }

    dna=fopen("../asset/dna.txt","r");
    if(dna==NULL){
        perror("Apertura del file DNA fallita");
        exit(1);
    }

    int i=0;
    while(n=fread(&temp,sizeof(char),1, dna)){
        if(n>0 && temp!='\n'){
            prot[i]=temp;
            i+=1;

            if(i==3){
                prot[3]='\0';
                i=0;

                if(messi==dim){ //espansione della stringa
                    dim*=2;
                    res=realloc(res,dim*sizeof(char));

                    if(res==NULL){
                        perror("Errore nella reallocazione della stringa risultante");
                        exit(1);
                    }
                }

                res[messi]=codoneToAminoacido(prot); //conversione verso l'amminoacido
                messi+=1;
            }
        }
    }
    if(fclose(dna)==EOF){
        perror("Errore nella chiusura del file DNA");
        exit(1);
    }

    res[messi]='\0';    

    trans=fopen("../asset/translation.txt","w");
    if(trans==NULL){
        perror("Errore nell'apertura del file risultato");
        exit(1);
    }
    
    if(messi>0){
        if(fwrite(res,sizeof(char), messi,trans)!=messi){ //scrittura della trascrizione
            perror("Errore nella scrittura del risultato");
            exit(1);
        }else{
            if(fclose(trans)==EOF){
                perror("Errore nella chiusura del file risultato");
                exit(1);
            }
        }
    }

    free(res);

    return 0;
}