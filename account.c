// ===================================================================================
//
//  Assignment:  1 
//  Milestone:   3
//  Description: Main logic/tester
//
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"



//1.Funtion Account type to get the data
//int NumCustomer; number must be a valid Int
//char AccountType; type must be only A or C which A means Agent And C Customer

struct Account GetAccount(struct Account account[], int FreeIndex)
{
	printf("Account Data: New Record\n");
	printChar('-', 40);
	printf("Enter the account number: ");
	account[FreeIndex].NumCustomer = getInteger();
	printf("Enter the account type (A=Agent | C=Customer): ");
	account[FreeIndex].AccountType = getCharOption("AC");
	printf("\n");
	GetUserLogin(account, FreeIndex);
	GetDemographic(account, FreeIndex);
	return account[FreeIndex];
}


//2. Function User Login type to get the Login information
//char LoginName[10];   must have only 10 chars
//char Name[30];  Name of that user must have max 30 char
//char Password[8];  should have ->exactly<- 8 chars

struct UserLogin GetUserLogin(struct Account account[], int FreeIndex)
{
	printf("User Login Data Input\n");
	printChar('-', 40);
	printf("Enter user login (%d chars max): ", (MAX_LOGIN_NAME - 1));
	clearStandardInputBuffer();
	getCString(account[FreeIndex].User.LoginName, 1, (MAX_LOGIN_NAME - 1));
	printf("Enter the display name (%d chars max): ", (MAX_DISPLAY_NAME - 1));
	clearStandardInputBuffer(); 
	getCString(account[FreeIndex].User.Name, 1, (MAX_DISPLAY_NAME - 1));
	printf("Enter the password (must be %d chars in length): ", (MAX_PASSWORD - 1));
	clearStandardInputBuffer();
	getCString(account[FreeIndex].User.Password, (MAX_PASSWORD - 1), (MAX_PASSWORD - 1));
	printf("\n");
	return account[FreeIndex].User;

}

//03. Function Demographic type
// int BdayDate; age between 18 and 110 (update ever year INPUT: Birth Year
// 	double HouseIncome; a valid positive double floating-point number
// char CountryName[30];  Country name
struct Demographic GetDemographic(struct Account account[], int FreeIndex)
{
	printf("Demographic Data Input\n");
	printChar('-', 40);
	clearStandardInputBuffer(); 
	int MinAge = currentYear() - MAX_AGE, MaxAge = currentYear() - MIN_AGE;
	printf("Enter birth year (current age must be between %d and %d): ", MIN_AGE, MAX_AGE);
	account[FreeIndex].Demo.BdayDate = getIntFromRange(MinAge, MaxAge);
	printf("Enter the household Income: $");
	account[FreeIndex].Demo.HouseIncome = getPositiveDouble();
	printf("Enter the country (%d chars max.): ", (MAX_DISPLAY_COUNTRY - 1));
	getCString(account[FreeIndex].Demo.CountryName, 1, MAX_DISPLAY_COUNTRY);
	printf("\n");
	return account[FreeIndex].Demo;
}


//4.display the update menu option for account until the user whishes to exit
//print at top the number of account and 40 - to separate
//alow modify the 3 parts of user login demografic and account type
//ATENTION: DO NOT CALL THE AGENT MENU TO LEAVE BACK TO MENU AGENT
void updateAccount(struct Account ArrayofData[], int changeIndex)
{
	printf("Enter the account type (A=Agent | C=Customer): ");
	ArrayofData[changeIndex].AccountType = getCharOption("AC");
	printf("\n");
}

//5. display's the name, 
//ID member is not modifiable
void updateUserLogin(struct Account ArrayofData[], int changeIndex)
{
	int selection = 0, done = 1;
	while (done == 1)
	{
		int flag = 0;
		printf("\n");
		printf("User Login: %s - Update Options\n",  ArrayofData[changeIndex].User.LoginName);
		printChar('-', 46);
		printf("1) Display name (current value: %s)\n", ArrayofData[changeIndex].User.Name);
		printf("2) Password\n"
			"0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 2);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				printf("Enter the display name (%d chars max): ", (MAX_DISPLAY_NAME - 1));
				getCString(ArrayofData[changeIndex].User.Name, 1, (MAX_DISPLAY_NAME - 1));
				flag = 1;
				break;
			case 2:
				printf("Enter the password (must be %d chars in length): ", (MAX_PASSWORD - 1));
				getCString(ArrayofData[changeIndex].User.Password, (MAX_PASSWORD - 1), (MAX_PASSWORD - 1));
				flag = 1;
				break;
			case 0:
				done = 0;
				flag = 1;
				break;
			}

		}
		printf("\n");
	}
}

//6.can change the value of household income and country
//NO CALL THE UPDATE ACCOUNT FUNCTION WHEN EXIT
void updateDemographic(struct Account ArrayofData[], int changeIndex)
{
	int selection = 0, done = 1;
	while (done == 1)
	{
		int flag = 0;
		printf("\n");
		printf("Demographic Update Options\n");
		printChar('-', 46);
		printf("1) Household Income (current value: %.2lf)\n", ArrayofData[changeIndex].Demo.HouseIncome);
		printf("2) Country (current value: %s)\n"
			"0) Done\n", ArrayofData[changeIndex].Demo.CountryName);
		printf("Selection: ");
		selection = getIntFromRange(0, 2);
		printf("\n");
		while (flag == 0)
		{
			switch (selection)
			{
			case 1:
				printf("\n");
				printf("Enter the household Income: $");
				ArrayofData[changeIndex].Demo.HouseIncome = getPositiveDouble();
				flag = 1;
				break;
			case 2:
				printf("\n");
				printf("Enter the country (%d chars max.): ", (MAX_DISPLAY_COUNTRY - 1));
				getCString(ArrayofData[changeIndex].Demo.CountryName, 1, MAX_DISPLAY_COUNTRY);
				flag = 1;
				break;
			case 0:
				printf("\n");
				done = 0;
				flag = 1;
				break;
			}

		}
		
	}
}

