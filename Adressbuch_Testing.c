#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[100];
	int anz;
}person;

typedef struct{
	char adr[100];
	int anz;																																											
}adress;

person pHinzufuegen (char namet[],int anzN);
adress aHinzufuegen (char adresset[], int anzA);
void ausgeben (int stelle, person* p, adress* a);

int main (int argc , char* argv[])
{

	person* p;
	adress* a;

	int stelle = 0;
	char textn[100];
	char texta[100];
	int anzN;
	int anzA;
	int eingabe = 0;

	do
	{
		printf("Geben sie ein was sie tun wollen:\n0: EXIT\n1: Person und Addresse hinzufuegen.\n2: Ausgeben der Personen und Addressen\n");
		scanf("%d",eingabe);
		switch(eingabe)
		{
			case 1: 
		
				printf("Geben sie einen Personennamen ein");
				anzN = scanf("%s",textn);
				printf("Geben sie einen Adresse ein");
				anzA = scanf("%s",texta);
				
				p = (person*) realloc(p,sizeof(person)+sizeof(p));
				a = (adress*) realloc(a,sizeof(adress)+sizeof(a));
				
				*(p+stelle) = pHinzufuegen (textn,anzN);
				*(a+stelle) = aHinzufuegen (texta,anzA);
				stelle++;
				break;
			
			case 2:	
			
				ausgeben(stelle,p,a);
				break;
			
			default:
			
				eingabe = 0;
				printf("Bye!");
				break;
		}
			
	}while(eingabe != 0);

	return EXIT_SUCCESS;
  
}

person pHinzufuegen (char namet[],int anzN){
	int i;
	person p;
	for(i=0;i<anzN;i++){
		p.name[i] = namet[i];
	}
	return p;
}

adress aHinzufuegen (char adresset[], int anzA){	
	int i;
	adress a;
	for(i=0;i<anzA;i++){
		a.adr[i]  = adresset[i];
	}
	return a;
}

void ausgeben (int stelle, person* p, adress* a){
	
	int i,z;
	for(i=0; i<stelle; i++){
		for(z=0; z<p[i].anz;z++){
			printf("%c",p[i].name[z]);
		}
		for(z=0; z<p[i].anz;z++){
			printf("%c",a[i].adr[z]);
		}
		printf("\n");
	}
}