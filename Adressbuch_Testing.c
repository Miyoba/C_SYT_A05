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
person* pLoeschen(int index, person* p);
adress* aLoeschen(int index, adress* a);

/*
Ein Programm das Personen und deren Adressen speichert , sie zur�ckgeben kann und bestimmte
Eintr�ge l�schen kann
@Author: Wolfgang Mair,Vogt Andreas
@Version: 2013-05-11
*/
int main (int argc , char* argv[])
{
	/*Attribute Deklarieren*/
	person* p;/*Pointer f�r struct*/
	adress* a;/*Pointer f�r struct*/

	int stelle = 0;/*Stelle an dem sich die pointer befinden*/
	char textn[100];
	char texta[100];
	int eingabe = 0;
	int loeschen;
	int fehler;
	do
	{
		/* Abfrage was das Programm als n�chstes machen soll*/
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
				
				p = (person*) realloc(p,sizeof(person)+sizeof(p));/*Dynamisch die Gr��e der Speicherreservierung erh�hen*/
				a = (adress*) realloc(a,sizeof(adress)+sizeof(a));
				
				*(p+stelle) = pHinzufuegen (textn);/* F�gt den text in das Array*/
				*(a+stelle) = aHinzufuegen (texta);
				stelle++;
				break;
			/* Bei 2 gibt er den inhalt von person und adress aus*/
			case 2:	
			
				ausgeben(stelle,p,a);
				break;
			/*Bei 3 l�scht er dem jeweiligen Personenname + Adresse aus dem Array*/
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
			/*Falls nichts oder etwas falsches eingegeben wird bricht er das Programm ab*/
			default:
			
				eingabe = 0;
				printf("Bye!");
				break;
		}
	/*Die Abfrage wird solange wiederholt bis entweder 0 oder etwas anderes eingegeben (au�er 1-3) eingegeben wurde		
	}while(eingabe != 0);

	return EXIT_SUCCESS;
  
}
/* F�gt den Personennamen in das Adressbuch ein*/
person pHinzufuegen (char namet[]){
	int i;
	person p;
	for(i=0;i<100;i++){
		p.name[i] = namet[i];
	}
	return p;
}
/* F�gt den Personennamen in das Adressbuch ein*/
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
/*L�scht den Namen aus einer bestimmten stelle raus*/
person* pLoeschen(int index, person* p){
	int i;
	person* ptemp;
	ptemp = (person*) realloc(ptemp,sizeof(p)-sizeof(person));/* Dynamisch verkleinern*/
	
	for(i = 0; i<(sizeof(p)/sizeof(person));i++){
		if(i!= index)
			ptemp[i] = p[i];
	}
	p = ptemp;
	return p;
}
/*l�scht die Adresse aus einer bestimmten Stelle raus*/
adress* aLoeschen(int index, adress* a){
	int i;
	adress* atemp;
	atemp = (adress*) realloc(atemp,sizeof(a)-sizeof(adress));
	
	for(i = 0; i<(sizeof(a)/sizeof(person));i++){
		if(i!= index)
			atemp[i] = a[i];
	}
	a = atemp;
	return a;
}