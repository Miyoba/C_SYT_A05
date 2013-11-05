/*Adressbuch*/
#include <stdio.h>
#include <stdlib.h>

/* Structs Person und Adress*/
typedef struct
{
	char name[100];
}person;

typedef struct
{
	char adr[100];																																											
}adress;

/*Prototypen*/
person pHinzufuegen (char namet[]);
adress aHinzufuegen (char adresset[]);
void ausgeben (int stelle, person* p, adress* a);
person* pLoeschen(int index, person* p, int stelle);
adress* aLoeschen(int index, adress* a, int stelle);

/*
Ein Programm das Personen und deren Adressen speichert , sie zurückgeben kann und bestimmte
Eintraege loeschen kann
@Author: Wolfgang Mair,Vogt Andreas
@Version: 2013-05-11
*/
int main (int argc , char* argv[])
{
	/*Attribute Deklarieren*/
	int stelle = 0;/*Anzahl der Einträge*/
	char textn[100];
	char texta[100];
	int eingabe = 0;
	int loeschen;
	int fehler;
	
	person* p = NULL;/*Pointer für struct*/
	adress* a = NULL;/*Pointer für struct*/
	
	p = (person*)malloc(sizeof(person));
	a = (adress*)malloc(sizeof(adress));
	
	
	do
	{
		/* Abfrage was das Programm als naechstes machen soll*/
		printf("Geben sie ein was sie tun wollen:\n0: EXIT\n1: Person und Addresse hinzufuegen.\n2: Ausgeben der Personen und Addressen\n3: Loeschen eines Eintrages\n");
		scanf("%d",eingabe);
		switch(eingabe)
		{
			/*Falls der Benutzer 1 eingibt kann er eine Person und seine Addresse eingeben welche
			gespeichert wird*/
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
				
				/*Dynamisch die Groeße der Speicherreservierung erhoehen*/
				p = (person*) realloc(p,sizeof(person)*(stelle+1));
				/*Ueberpruefung des Speicherplatzes*/
				if(p == NULL){
					printf("Not enough Memory!");
					break;
				}	
				a = (adress*) realloc(a,sizeof(adress)*(stelle+1));
				if(a == NULL){
					printf("Not enough Memory!");
					break;
				}
				
				*(p+stelle) = pHinzufuegen (textn);/* Fügt den text in das Array*/
				*(a+stelle) = aHinzufuegen (texta);
				stelle++;
				break;
			
			/* Bei 2 gibt er den inhalt von person und adress aus*/
			case 2:	
			
				ausgeben(stelle,p,a);
				break;
			
			/*Bei 3 loescht er dem jeweiligen Personenname + Adresse aus dem Array*/
			case 3: 
				printf("Geben sie einen Index ein");
				fehler = scanf("%d",loeschen);
				if(fehler == 0 || loeschen < 0 || loeschen > stelle){
					printf("Fehler beim loeschen falscher Index");
					break;
				}
				p = pLoeschen(loeschen,p);
				a = aLoeschen(loeschen,a);
				stelle--;
				break;
			
			/*Falls nichts oder etwas falsches eingegeben wird bricht er das Programm ab*/
			default:
			
				eingabe = 0;
				printf("Bye!");
				break;
		}
			
	}while(eingabe != 0);
	
	/*Gibt den reservierten speicherplatz wieder frei*/
	free(p);
	free(a);
	p = NULL;
	a = NULL;
	return EXIT_SUCCESS;
  
}

/* Fuegt den Personennamen in das Adressbuch ein*/
person pHinzufuegen (char namet[]){
	int i;
	person p;
	for(i=0;i<100;i++){
		p.name[i] = namet[i];
	}
	return p;
}

/* Fuegt den Personennamen in das Adressbuch ein*/
adress aHinzufuegen (char adresset[]){	
	int i;
	adress a;
	for(i=0;i<100;i++){
		a.adr[i]  = adresset[i];
	}
	return a;
}

/*Gibt alles was im Adressbuch gespeichert aus */
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

/*Loescht den Namen aus einer bestimmten stelle raus*/
person* pLoeschen(int index, person* p, int stelle){
	int i;
	person* ptemp = NULL;
	ptemp = (person*) malloc(sizeof(person)*stelle);
	
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

/*Loescht die Adresse aus einer bestimmten Stelle raus*/
adress* aLoeschen(int index, adress* a, int stelle){
	int i;
	adress* atemp = NULL;
	atemp = (adress*) malloc(sizeof(adress)*stelle);
	
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