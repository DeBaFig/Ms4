// ===================================================================================
//
//  Assignment:  1
//  Milestone:   2
//  Description: Main logic/tester
//	Full Name: Denize Bassi Figueiredo
//	Student ID: 111288205
//	E-mail: dbassi-figueiredo@myseneca.ca
//	Section: ZDD
// +---------------------------------------------------------+
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "commonHelpers.h"
#include "account.h"  
#include  "accountTicketingUI.h"


//function provide for me
//1. Get the current 4 digit year from the system
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

//2. Empty the standard input buffer
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n');
}


//3. get a valid integer from the keyboard, and display an error if an invalid value is entered
int getInteger(void)
{
	int num;
	char line;
	scanf("%d%c", &num, &line);
	while (line != '\n')
	{
		printf("ERROR: Value must be an integer: ");
		clearStandardInputBuffer();
		scanf("%d%c", &num, &line);
	}
	return num;
}


//4. get a valid integer and validate if the number if more then 0, and display an erro if an invalid value is entered
int getPositiveInteger(void)
{
	int a = 0;
	while (a <= 0)
	{
		a = getInteger();
		if (a < 0)
			printf("ERROR: Value must be a positive integer greater than zero: ");
	}
	return a;
}


//5. get a valid double and return in the funtion, if an invalid number was typed an erro will be displayed
double getDouble(void)
{
	double num;
	char line;
	scanf("%lf%c", &num, &line);
	while (line != '\n')
	{
		printf("ERROR: Value must be a double floating-point number: ");
		clearStandardInputBuffer();
		scanf("%lf%c", &num, &line);
	}
	return num;
}

//6.get a valid double from the  and return in the funtion, if an invalid number was typed an erro will be displayed
double getPositiveDouble(void)
{
	double a = 0;
	while (a <= 0)
	{
		a = getDouble();
		if (a <= 0)
			printf("ERROR: Value must be a positive double floating-point number: ");
	}
	return a;
}

//7. Get the argument 1 and set as a min value to a integer and argument 2 max value to a integer return the number if the input is correct, else show a error messenge
int getIntFromRange(int lowerNumber, int highestNumber)
{
	int num = getInteger();
	while (!(num >= lowerNumber && num <= highestNumber))
	{
		printf("ERROR: Value must be between %d and %d inclusive: ", lowerNumber, highestNumber);
		clearStandardInputBuffer();
		num = getInteger();
	}
}


//8. Return a single valid char value and receives one argument which is the strig with the valid options to type 
char getCharOption(char* ArrayofvalidArgument)
{
	char letter[10], line;
	int a = 0, valid = 0, length = 0;
	while (valid == 0)
	{
		scanf("%[^'\n']s%1c", letter, &line);
		length = stringlength(letter);
		if (length == 1)
		{
			for (a = 0; ArrayofvalidArgument[a] != '\0'; a++)
			{
				if (letter[0] == ArrayofvalidArgument[a]) {
					valid = 1;
					return letter[0];
				}
			}
			printf("ERROR: Character must be one of [%s]: ", ArrayofvalidArgument);
		}
		else
			printf("ERROR: Character must be one of [%s]: ", ArrayofvalidArgument);
		clearStandardInputBuffer();
	}
	return letter[0];
}
//9. obtain the user input for a String with the number max and min of chars allowed
void getCString(char* Cstring, int min_NumberChar, int max_NumberChar)
{
	int valid = 0, length = 0;
	char line = 'x';
	scanf("%[^\n]s%c", Cstring, &line);
	length = stringlength(Cstring);
	while (valid == 0)
	{
		if ((length < min_NumberChar || length > max_NumberChar) && length != 0)
		{
			if (min_NumberChar == max_NumberChar)
				printf("ERROR: String length must be exactly %d chars: ", max_NumberChar);
			else
			{
				if (length > max_NumberChar)
					printf("ERROR: String length must be no more than %d chars: ", max_NumberChar);
				if (length < min_NumberChar)
					printf("ERROR: String length must be between %d and %d chars: ", min_NumberChar, max_NumberChar);
			}
			clearStandardInputBuffer();
			scanf("%[^\n]s%c", Cstring, &line);
			length = stringlength(Cstring);
		}
		else
			valid = 1;
	}
	/*scanf("%[^\n]s%c", &Cstring, &line);
	printf("string %s \n", Cstring);*/
}


//10. String length

int stringlength(char* string) {
	int length = 0, a;

	for (a = 0; string[a] != '\0'; a++)
		length = a + 1;

	return length;
}
//11. variant of getstring to attend the demografic that was jumping a line withno reason

void printChar(char simbol, int xTimes) {
	int a;
	for (a = 0; a < xTimes; a++)
		printf("%c", simbol);
	printf("\n");
}
