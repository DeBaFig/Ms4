// ===================================================================================
//
//  Assignment:  1
//  Milestone:   3
//  Description: Main logic/tester
//	Full Name: Denize Bassi Figueiredo
//	Student ID: 111288205
//	E-mail: dbassi-figueiredo@myseneca.ca
//	Section: ZDD
// +---------------------------------------------------------+

#ifndef ACCOUNT_TICKETING_H_
#define ACCOUNT_TICKETING_H_


//1. funtion with the basic information about te account 
void displayAccountSummaryHeader(void);

//2.function that will display the summary record provide by user has as argument the struct account
void displayAccountSummaryRecord(const struct Account DataAcc, const struct Demographic Demo);

//3. Display the Account details  record with the password partially hidden with * 
void displayAccountDetailRecord(const struct Account account, const struct UserLogin login, const struct Demographic demo);

//4. display the head of Accound detail
void displayAccountDetailRecordHead(void);

//5. Funtion to hide the password with * where should have one letter and then on *
void hidethePassword(const struct UserLogin* Password, char* hidePassword);


//6. Application startup, Active the menu, if the logged is a Customer the app should display a specify message 
void applicationStartup(struct Account data[], int maxNumberofElements);

//7. Menu login
//first show the option to login the number to login should be the same register as acc number
// loop to compare the int typed and the data in the array, must return the index of user
int menuLogin(const struct Account ArrayOfDATA[], int MAX_num_of_arguments);

//8.Display the agent main menu
//show the name and the number of the agent on the top
void menuAgent(struct Account Data[], int maxNumberofElements, const struct Account* DataofLoggedUSER);

//9. return an integer representing the array index of Account
// search the arg1 in the array of arg2
//if the arg4 =0 will use the arg1 to looking for the user
//if arg4 != 0 will appear a scanf to add a number to looking for
// return -1 if do not found a user or the index of array if found
int findAccountIndexByAcctNum(int NumberTypetoLookingFor, const struct Account ArrayOfAcc[], int maxNumberofElements, int zeroORnot);

//10.display the summary of all valids accounts(which is all than account number is greater than 0
void displayAllAccountSummaryRecords(const struct Account ArrayofAcc[], int maxNumberofElements);

//11. display a detailed view of all valid account records(which is all than account number is greater than 0
void displayAllAccountDetailRecords(const struct Account ArrayofAcc[], int maxNumberofElements);

//12. Function provided for me
//pause the application
void pauseExecution(void);


//13. loop to find an empyt acocunt to add info
int emptyIndex(const struct Account ArrayofAcc[], int maxNumberofElements);

//14. Menu To update Options
void menuUpdateOptions(struct Account Data[], int ChangeIndex);

void removeaccount(struct Account Data[], int currentLogin);

#endif