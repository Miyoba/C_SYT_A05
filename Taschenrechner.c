/*Berechnet Informationen einer Kugel*/
#include <stdio.h>
#include <stdlib.h>
/*Prototypen*/
int addition(int,int);
int subtraktion(int,int);
int division(int,int);
int multiplikation(int,int);

int(*fup)(int,int);
/*
Ein Programm das die Eigenschaften einer Kugel berechnet mittels eingaben
@Author: Wolfgang Mair
@Version: 2013-10-08
*/
int main(int argc, char* argv[])
{
	/*Die Attribute Deklarieren*/
	char zeichen;
	int erg = 0;
	int zahl1,zahl2;
	/*Eine Schleife die überprüft ob die Eingabe akzeptabel war*/
	do
	{
		printf("Geben sie ein wie sie die Zahlen berechnen wollen.\n(+ , - , / , *)");
		scanf("%c",&zeichen);
		
		switch(zeichen)
		{
			case '+':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				fup = addition;
				
				printf("\nAdditions ergebnis = %d\n",(*fup)(zahl1,zahl2));
				break;
				
			case '-':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				fup = subtraktion;
				
				printf("\nSubtraktions ergebnis = %d\n",(*fup)(zahl1,zahl2));
				break;
				
			case '/':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				fup = division;
				
				printf("\nDivisions ergebnis = %d\n",(*fup)(zahl1,zahl2));
				break;
				
			case '*':
				printf("\nZahl 1: ");
				erg = scanf("%d",&zahl1);
				printf("%d",zahl1);
				/*Keine Zahl überprüfung*/
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				printf("\nZahl 2: ");
				erg = scanf("%d",&zahl2);
				printf("%d",zahl2);
				
				if(erg == 0)
				{
					printf("\nFalsche Eingabe!\n");
					break;
				}
				
				fup = multiplikation;
				
				printf("\n Multiplikations ergebnis = %d\n",(*fup)(zahl1,zahl2));
				break;
					
			default:
				printf("\nFalsche Eingabe! Denken sie nach wollten sie wirklich %c eingeben?\n",zeichen);
				break;	
		}
		
		printf("Wollen sie eine weitere Eingabe machen? (y/n)\n");
		scanf("%c",&zeichen);
		zeichen = tolower(zeichen);
		
		switch(zeichen)
		{
			case 'y':
				erg = 0;
				break;
				
			case 'n':
				erg = 1;
				break;
				
			default:
				printf("Fehler beenden des Programmes");
				return EXIT_FAILURE;
				break;
		}
	}
	while(erg == 0);
	/*Berechnen der Werte der Kugel*/
	
	return EXIT_SUCCESS;
}

/*Definierung der Methoden*/
int addition(int nr1,int nr2)
{
	return nr1+nr2;
}
int subtraktion(int nr1,int nr2)
{
	return nr1-nr2;
}
int division(int nr1,int nr2)
{
	return nr1/nr2;
}
int multiplikation(int nr1,int nr2)
{
	return nr1*nr2;
}
	