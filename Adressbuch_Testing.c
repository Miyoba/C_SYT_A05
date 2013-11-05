#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[100];
}person;

typedef struct
{
	char adr[100];																																											
}adress;

person pHinzufuegen (char namet[]);
adress aHinzufuegen (char adresset[]);
void ausgeben (int stelle, person* p, adress* a);
person* pLoeschen(int index, person* p, int stelle);
adress* aLoeschen(int index, adress* a, int stelle);

int main (int argc , char* argv[])
{
	int stelle = 0;
	char textn[100];
	char texta[100];
	int eingabe = 0;
	int loeschen;
	int fehler;
	
	person* p = NULL;
	adress* a = NULL;
	
	p = (person*)malloc(sizeof(person));
	a = (adress*)malloc(sizeof(adress));
	
	
	do
	{
		printf("Geben sie ein was sie tun wollen:\n0: EXIT\n1: Person und Addresse hinzufuegen.\n2: Ausgeben der Personen und Addressen\n3: Loeschen eines Eintrages\n");
		scanf("%d",eingabe);
		switch(eingabe)
		{
			case 1: 
		
				printf("Geben sie einen Personennamen ein");
				fehler = scanf("%s",textn);
				if(fehler == 0){
					printf("Fehler beim Einlesen");
					break;
				}
				printf("Geben sie einen Adresse ein");
				fehler = scanf("%s",texta);
				if(fehler == 0){
					printf("Fehler beim Einlesen");
					break;
				}
				
				p = (person*) realloc(p,sizeof(person)+sizeof(p));
				if(p == NULL){
					printf("Not enough Memory!");
					break;
				}	
				a = (adress*) realloc(a,sizeof(adress)+sizeof(a));
				if(a == NULL){
					printf("Not enough Memory!");
					break;
				}
				
				*(p+stelle) = pHinzufuegen (textn);
				*(a+stelle) = aHinzufuegen (texta);
				stelle++;
				break;
			
			case 2:	
			
				ausgeben(stelle,p,a);
				break;
			
			case 3: 
				printf("Geben sie einen Index ein");
				fehler = scanf("%d",loeschen);
				if(fehler == 0 || loeschen < 0 || loeschen > (sizeof(p)/sizeof(person))){
					printf("Fehler beim loeschen falscher Index");
					break;
				}
				p = pLoeschen(loeschen,p);
				a = aLoeschen(loeschen,a);
				break;
				
			default:
			
				eingabe = 0;
				printf("Bye!");
				break;
		}
			
	}while(eingabe != 0);
	
	
	free(p);
	free(a);
	p = NULL;
	a = NULL;
	return EXIT_SUCCESS;
  
}

person pHinzufuegen (char namet[]){
	int i;
	person p;
	for(i=0;i<100;i++){
		p.name[i] = namet[i];
	}
	return p;
}

adress aHinzufuegen (char adresset[]){	
	int i;
	adress a;
	for(i=0;i<100;i++){
		a.adr[i]  = adresset[i];
	}
	return a;
}

void ausgeben (int stelle, person* p, adress* a){
	
	int i,z;
	for(i=0; i<stelle; i++){
		for(z=0; z<100;z++){
			printf("%c",p[i].name[z]);
		}
		for(z=0; z<100;z++){
			printf("%c",a[i].adr[z]);
		}
		printf("\n");
	}
}

person* pLoeschen(int index, person* p, int stelle){
	int i;
	person* ptemp = NULL;
	ptemp = (person*) malloc(sizeof(p)-sizeof(person));
	
	if(ptemp == NULL){
		printf("Not enough Memory!");
		return p;
	}	
	
	for(i = 0; i<stelle;i++){
		if(i!= index)
			ptemp[i] = p[i];
	}
	p = ptemp;
	return p;
}
	
adress* aLoeschen(int index, adress* a, int stelle){
	int i;
	adress* atemp = NULL;
	atemp = (adress*) malloc(sizeof(a)-sizeof(adress));
	
	if(atemp == NULL){
		printf("Not enough Memory!");
		return a;
	}	
	
	for(i = 0; i<stelle;i++){
		if(i!= index)
			atemp[i] = a[i];
	}
	a = atemp;
	return a;
}