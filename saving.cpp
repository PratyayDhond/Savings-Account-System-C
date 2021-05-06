// This code has been written by Pratyay Dhond(That's me!)
// If you find any bugs or issues in this code, do let me know 
// You can contact me at dhondpratyay@gmail.com on mail.
// Thanks for checking out this code

//So the goal of this purpose is to create a savings system where your money would be saved
//I have used file management to store the data in the hard disk


// libraries

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

// variables
char firstName[10],lastName[20];
int  age;
char address[50]; 
char password[20];
int balance1;

// functions
void details(void);							// Reads user details			
void printline(void);						// Prints a single line as mentioned in function.
void accountFile(void);						// Contains Account info such as balance.	
void start (void);							// Used for the start of the program.
void Pass(void);							// For creating Password
void Datafile(void);						// For storing data of customers in a FILE.
void showDetailsInputtedNow(void); 			// To display user details
void passwordFile(void);					// Prints password to the file.
void showDetailsBorder(void);				// Shows the details border.
void checkDetails();						// Prints the details on the terminal.
void checkPass();							// checks for user password
void logout();								// Ends the program with a log out message
void passwordBorder();						// Shows the password border
void AccountbalanceFileCreator();			// Used to create a balance file.
void transactions();						// Used for transaction	
void depoMoney();							// Used for depositing(adding) money to the bank account.
void withdrawMoney();						// Used for withdrawing(deducting) money from the bank account.
void lightningBankDesign();					// Used for generating design of Lightning Bank.
void checkPassForDepo(); 					// Used for verifying user before adding money
void checkPassForwithdrawMoney();			// Used for verifying user before withdrawing money
void openmoneyFile1();						// Used for opening the money file to add money.
void openmoneyFile2();						// Used for opening the money file to withdraw money.
void returnOpt();							// Asks users if they want to return to money or log out.
// main function
int main(){	

	start(); 															// opens the start function.
			
	return 0;															// Ends the program.
}

// function used to read details.
void details(void){
	
	system("cls");														// clears the screen
	printline();														// Uses the printline function	
	printf("|\t       Details \t\t   |\n");
	printline();
	fflush(stdin);														// As the last scanned variable was an integer it isn't possible to use gets directly because of the previous '\n' input, so this flushes the previous '\n' input. 
	printf("Enter Your First Name : ");
	scanf("%s",firstName);												// Reads first name.	
	fflush(stdin);
	printf("Enter Your Surname : ");
	gets(lastName);														// Reads last name.
	char age1[5];
	ReAge :
	printf("Enter Your Age : ");
	scanf("%s",age1);													// Reads Age in char data type.
	age = atoi(age1);													// For converting age from char to int and returns 0 if the age isn't an integer
//	printf("\n\n\n%d\n\n\n",age);																				// Used for checking if atoi() function worked;
	if(age==0 || age<0 || age>200){										// checks if the age is valid or not
		printf("Enter a valid age \n");
		goto ReAge;	
	}
	fflush(stdin);														// flushes '\n' (for more refer to comment on line 32).
	printf("Enter Your Address : "); 									// Reads address.	
	gets(address);
	
	system("cls");														// clears the screen.
	reUP:
	showDetailsInputtedNow();
	
	// Editing/ Updating details
	printf("\nDo you want to edit any details? \nEnter Y for Yes and N for no.\n");		
			char ans = getch();																			// takes input for updating details.
			printf("Your Choice : %c\n",ans);
		if(ans == 'Y' || ans == 'y'){
			ReUpdate:
			printf("What do you want to update?\n 1. First Name\n 2. Last Name \n 3. Age \n 4. Address\n 5. Exit\n");
			char choice1 =getch();
			switch(choice1){
				case '1' :	
						// Updating the first name	
							printf("Enter first name : ");
							scanf("%s",firstName);
							system("cls");																// clears the screen
							printf("Updated Name : %s\n",firstName);
							break;
							 
				case '2' :
						// Updating the last name	
							fflush(stdin);
							printf("Enter Surname : ");
							gets(lastName);
							system("cls");																// clears the screen
							printf("Updated last Name : %s\n",lastName);
							break;
							
				case '3' :
						// Updating the age
							ReAge1 :
									printf("Enter Your Age : ");
									scanf("%s",age1);													// Reads Age in char data type.
									age = atoi(age1);													// For converting age from char to int and returns 0 if the age isn't an integer
									if(age==0 || age<0 || age>200){										// checks if the age is valid or not
										printf("Enter a valid age \n");
										goto ReAge1;	
									}
							system("cls");															 	// clears the screen
							printf("Updated Age : %d\n",age);	
							break;		
							
				case '4' :
						// Updating the Address																			
							printf("Enter Your Address : "); 
							fflush(stdin);
							gets(address);
							system("cls");																// clears the screen
							printf("Updated Address : %s\n",address);		
							break;
				case '5' : 
							goto skipIF;
							break;				
			}
			if( choice1 != '1' || choice1 != '2' || choice1 != '3' || choice1 != '4'|| choice1 != '5'){
				system("cls");
				showDetailsInputtedNow();
				goto ReUpdate;
			}
			skipIF:
			printf("Do you want to make any other changes?\n Enter Y for yes and N for no : ");
			
			ans = getch();																				// inputs Y/N
			printf("Do you want to make any other changes : %c\n",ans);
			ReANS:
			if(ans == 'y' || ans == 'Y'){																// checks for y		
				goto ReUpdate;
			}
			else if(ans == 'n' || ans == 'N'){															// checks for n
				goto end1;	
			}
			else if(ans != 'y' || ans != 'Y' || ans != 'n' || ans != 'N'){								// checks if the input is either y or n
				printf("Enter Y or N : ");
				ans = getch();
				showDetailsInputtedNow();
				goto ReANS;																					
			}
		}
		if(ans != 'n' || ans != 'N' || ans != 'y' || ans != 'Y'){
			system("cls");
			if(ans == 'n'){
				goto end1;
			}
			if(ans == 'N'){
				goto end1;
			}
			if(ans == 'Y'){
				goto end1;
			}
			if(ans == 'y'){
				goto end1;
			}
			goto reUP;
		}
		end1:
		system("cls");																					// clears the screen
		Pass();																			
	}

// function used to print a line.
void printline(){
	printf("------------------------------------\n");				
}

// funtion used for choosing from options in the program.
void start(){
	fflush(stdin);
	printline();
	printf("|\t Lightning Bank\t\t   |\n");
	printline();
	char choice;																						// Used char instead of int to prevent enter if an alphabet is entered. As it will get stuck in an infinite loop generating random values if we enter alphabet in int. 				
	printf("\n 1. New Account\n 2. Check Details\n 3. Transactions\n 4. Log Out\n");		
	printf("Enter your Choice : (1/2/3/4)  : ");
	choice = getch();																					// Used to take input of choice
	printf("\n");
//	while(i==0){
	switch(choice){
		case '1': 																						// Used the numbers as string because using CHAR data type.
				details();																				// Calls the function details()	
				break;
		case '2':
				checkPass(); 
				break;
		case '3':
				transactions();
				break;
		case '4': 
				logout();																				// Calls the logout function.
				break;
		default: 
				
				system("cls");																			// clears the screen.
				start();																				// re-calls the start funtion;		
				break;				
		}	
//	}
}

// Creates a FILE to store user data.
void Datafile(){																						
	FILE *fp1;																							// file pointer
	char filename[30];																									
	strcpy(filename,firstName);																			// copying firstname to file name	
	strcat(filename,"Details.txt");																		// creating a name for the file			
	fp1 = fopen(filename,"w");																			// opens file with fp1 pointer
		fprintf(fp1,"\n First Name : %s\n Last Name  : %s\n Age \t    : %d\n Address    : %s\n\n",firstName,lastName,age,address);
	fclose(fp1);																						// closes file whose pointer is fp1	
//	passwordFile();																						// calls the passwordFile() funtion
}

// Creates a password for account;
void Pass(){
	rePass:
		showDetailsInputtedNow();																		// calls the showDetailsInputtedNow() function.		
	char pass1[20],pass2[20];
	printline();																						// calls the printline function.
	printf("|\t   Create Password \t   |\n");
	printline();																						// calls the printline function.
	printf("Enter Password : ");
	scanf("%s",pass1);																					// reads the password for the first time
	printf("Confirm Password : ");
//	fflush(stdin); 
//	gets(pass2);   (This also works, but i went with scanf)
	scanf("%s",pass2);																					// reads the password for the first time
	if(strcmp(pass1,pass2) == 0){																		// checks if the two password are same or not	
		strcpy(password,pass1);																			// copies the password to the original password variable	
		printf("password set successfully\n");
	printline();
	passwordFile();
	Datafile();
	AccountbalanceFileCreator();	
		char c;
		ReOPT:
		printf("\n Do you want to go back to menu?\n");
		printf(" 1. Back To Main Menu\n 2. Check The Password(you'll only be able to see it here)\n 3. Log out\n Enter a number (1,2,3): ");
		c = getch();
		switch(c){
			case '1': 
						system("cls");																	// Clears the screen
						start();																		// Calls the start() function
						break;	
			case '2':
						printf("\n Password : %s\n",password);
						printf("Press Any Key To Continue : ");
						getch();																		// Holds the screen till the user presses any key
						goto ReOPT;																		// Redirects program to ReOPT point in the function 				
						break;
			case '3': 	
						logout();
						break;			
		}	
	}
	else{
		printf("The entered passwords aren't same. Try again.\n");
		printf("Press ENTER to continue");
		getch();																						// used this so that the screen isn't cleared right away
		system("cls");																					// clears the screen
		goto rePass;																					// Redirects program to RePass point in the function	
	}
	fflush(stdin);
	Datafile();																							// calls the datafile function.
}

// Prints the details in the terminal
void showDetailsInputtedNow(){                															// shows the user details.
	printline();																						// Uses the printline function.	
	printf("|\t   Your Details \t   |\n");
	printline();																						// Uses the printline function.
	printf("\n First Name : %s\n Last Name  : %s\n Age \t    : %d\n Address    : %s\n\n",firstName,lastName,age,address);
	printline();																						// Uses the printline function.
}

void showDetailsBorder(){                																// shows the user details.
	printline();																						// Uses the printline function.	
	printf("|\t   Your Details \t   |\n");
	printline();																						// Uses the printline function.
}

// creates password file.
void passwordFile(){
	FILE *fp2;																							// file pointer					
	char passfile[30];																					
	strcpy(passfile,firstName);																			// copying firstname to file name		
	strcat(passfile,"Password.txt");																	// creating a name for file 
	fp2 = fopen(passfile,"w");																			// opening a file 
	//	for(int i=0;i<20;i++){
			fprintf(fp2,"%s",password);
	//		if(password[i] != '\0'){																	// Checking for null value, i.e end of the string
	//			putc(password[i],fp2);																	// copies the password to the file character by character
	//		}
	//	}										
	fclose(fp2);																						// closes the file having pointer fp2
}

void checkDetails(){
	Rechoose:
	FILE *fp3,*fp7;																						// FILE pointers
	char filename[30],filename1[30];	
	char c;
	
	printline();																						// Uses the printline function.	
	printf("|\t   Your Details \t   |\n");								
	printline();																						// Uses the printline function.

	strcpy(filename,firstName);
	strcat(filename,"Details.txt");
	
		fp3 = fopen(filename,"r");																		// opens the file in read mode
			while((c = getc(fp3)) != EOF){																// checks for the end of file (EOF)
				printf("%c",c);																			// prints a character from the file
			}
	fclose(fp3);																						// closes the file associated with the pointer f3.
	
		strcpy(filename1,firstName);
	strcat(filename1,"Balance.txt");
	int balance;
	FILE *fp6 = fopen(filename1,"r");																	// Opens User Balance FILE in read mode
//	int a = fscanf(fp6,"%d",&balance);																	// Scans the balance from file to user's balance
	fscanf(fp6,"%d",&balance);																			// scans the user's balance from FILE to variable	
		printf("Now your Current Balance is : %d/-\n",balance);											//	Shows the balance to the user 
	fclose(fp6);																						// closes the file associated with FILE pointer fp6
		
	printline();
	printf("\n");
	printf("Go back to  main menu? \n press Y for yes and N for no : ");								
	fflush(stdin);																						// clears standard input from the password to prevent error in getchar.
	c = getch();																						
	if(c == 'y' || c == 'Y'){
		system("cls");																					// clears the screen
		fflush(stdin);																					// clears standard input from the password to prevent error in getchar.
		start();																						// calls the start function.
	}
	else if(c == 'n' or c == 'N'){
		logout();																						// calls the logout function
	}
	else if(c != 'y' || c != 'Y' || c != 'n' || c != 'N'){
		printf("Wrong choice; Enter Y or N");
		printf("Press ANY KEY to continue");
		getch();																						// Used to input any key to continue so that the text printed isn't cleared directly by system("cls");
		system("cls");																					// clears the screen
		fflush(stdin);																					// clears standard input from the password to prevent error in getchar.
		goto Rechoose;																					// Redirects to the Rechoose point in the function. 
	}
} 

void checkPass(){
	char passcode[20];
	system("cls");																						// clears the screen
	passwordBorder();																					// Calls the passwordBorder() function	
	
	printf("Enter your first name : ");
	gets(firstName);																					// reads username
	
	FILE *fp4;																							// declares fp4 as a pointer of data type FILE
	int i=0,n;
	char passfile1[30],passfile2[30],c;																					
	strcpy(passfile1,firstName);																		// copying firstname to file name		
	strcat(passfile1,"Password.txt");																	// creating a name for file 
	fp4 = fopen(passfile1,"r");																			// opening a file
		while((c = getc(fp4)) != EOF){																	// scans password from the file character by character and saves each char temporarily in variable c.	
			passfile1[i] = c;																			// saves the scanned character of the password in the char array passfile in index 'i'.
			i++;																						// increments the value of i by 1(unity).
		}
		passfile1[i] = '\0';																			// places '\0' in the end of the passfile char array.	
																											
	/*	Another method for password, but lengthy and not properly working.								
		for( i=0;i<20;i++){																				
			if((passfile1[i] = getc(fp4)) != EOF || (passfile1[i] = getc(fp4)) != ' ');							
		} 																									
	for(i=0;i<strlen(passfile1);i++){																	
		if(passfile1[i] != '\0'){																		
			passfile2[i] = passfile1[i];																
		}																								
	}																									
	*/
	RePass:																									
	printf(" Enter Your Passcode : ");																	
	scanf("%s",passcode);																				// Reads the password that the user has inputted.
	
	//  USED FOR CHECKING THE OUTPUT VALUES OF STRLEN AND STRCMP (Not Needed Any More)
	/*				
	passcode[strlen(passcode)+1] = '\0';
	//	passfile2[i+1] = '\0';
	int n1 = strlen(passfile1);		
	int n2 = strlen(passfile2);																			// THIS PART WAS FOR TESTING THE WORKING AND ERRORS OF PASSWORD FUNCTION
	int n3 = strlen(passcode);
	printf("\n\n %d %d %d\n\n",n1,n2,n3);
	printf(" %s \n %s",passfile1,passcode);
	
	printf("\n\n\n %d \n\n\n",n);
	printf("\n\n\n\n\n\%s",passfile1);
	*/
	n = strcmp(passcode,passfile1);																		// Compares the passwords ( The one in the files and the one entered now)
	if(n == 0){
		printf("Login Successful. Press ENTER to continue\n");
		getch();																						// Used to hold the screen and take input from the keyboard to continue.
		printf("\n");
		system("cls");
		checkDetails();																					// Calls the check details function	
	}
	else{
		printf("\n Wrong Password");
		printf("\n Do you want to Try again or go back to menu\n");
		printf(" 1. Go To Main Menu\n 2. Try Again\n Press any other key to Log Out : ");
		char e;
		e = getch();																					// Inputs the value of 'e'
		if(e == '1'){
			system("cls");																				// Clears The Screen	
			fflush(stdin);																				// Flushes any previous user input, like '\n'
			start();																					// calls the start function
		}else if(e == '2'){
			system("cls");																				// Clears The Screen	
			passwordBorder();																			// calls the start function
			printf(" Enter your first name : %s\n",firstName);
			goto RePass;																				// Redirects to RePass 
		}else{
			system("cls");																				// Clears The Screen	
			logout();																					// Calls the logout() function
		}
		
	//	printf("Press any key to continue");
	//	getch();
		
		
	}
		
//	printf("\n\n\n%s\n\n\n",passfile1);
	
	
}

void logout(){
		system("cls");																					// Clears the screen
		lightningBankDesign();																			// Calls the printline() function
		printf("\n   Logged Out Successfully.\n");
}

void passwordBorder(){
	printline();																						// Calls the printline() function
	printf("|\t User Verification\t   | \n");
	printline();																						// Calls the printline() function
}

void lightningBankDesign(){
		printline();																					// Calls the printline() function
		printf("|\t Lightning Bank\t\t   |\n");
		printline();																					// Calls the printline() function	
}

void AccountbalanceFileCreator(){
	FILE *fp5;																								
	char balanceFile[30];
	strcpy(balanceFile,firstName);																		// copying firstname to file name		
	strcat(balanceFile,"Balance.txt");																	// creating a name for file 
	fp5 = fopen(balanceFile,"w");																		// Creates the user's balance file in Writing mode
	//	fprintf(fp5,"%d",0);																			// Prints the account balance of 0 in user's file
		putw(0,fp5);																					// Prints the account balance of 0 in user's file
		fclose(fp5);																					// Closes the user's balance file	
}

void transactions(){
	char a;
	reinput1:	
	system("cls");																						// Clears the screen
	lightningBankDesign();																				// Calls the lightningBankDesign() function	
	fflush(stdin);																						// flushes the previous user input(if any) such as '\n'
	printf("\n Which Action do you want to perform?\n");
	printf(" 1.Deposit Money\n 2.Withdraw Money\n 3.Main Menu\n 4.Log Out\n Enter a number : ");
	a = getch();																						// Reads the value of char 'a'	
	switch(a){
		case '1':
				checkPassForDepo();																		// Calls the checkPassForDepo() function									
				break;
		case '2':
				checkPassForwithdrawMoney();															// Calls the checkPassForwithdrawMoney() function		
				break;
		case '3':
				system("cls");																			// Clears the screen
				start(); 																				// Calls the start() function	
				break;
		case '4':
				logout();																				// Calls the logout() Function		
				break;				
		default:
				printf("Incorrect choice");
				goto reinput1;																			// Redirects tto reinput1:(line 479)
				break;	
	}				
	
}

void withdrawMoney(){
	openmoneyFile2();																					// calls the openmoneyFile2() function	
}

void depoMoney(){
	openmoneyFile1();																					// calls the openmoneyFile1() function
	
}

// For depositing
void openmoneyFile1(){
	FILE *fp6;																							// FILE pointers	
	int addMoney;	
	int balance;
	char moneyFileName[30];
	strcpy(moneyFileName,firstName);																	// Copies the firstname to moneyFileName.
	strcat(moneyFileName,"Balance.txt");																// Joins the "Balance.txt" to the moneyFileName.
	fp6 = fopen(moneyFileName,"r");																		// Opens User's Balance file
		fscanf(fp6,"%d",&balance1);																		// Scans the balance from file to user's balance
		fclose(fp6);																					// closes User's Balance file
fp6 = fopen(moneyFileName,"w+");
		if(getw(fp6) == NULL){
			balance = 0;
			fprintf(fp6,"%d",balance);	
		}
		ReAddMoney:
		lightningBankDesign();																			// calls the lightningBankDesign() function
		printf(" Enter Amount You want to add. : ");
		scanf("%d",&addMoney);
		balance = balance1;
		if(addMoney<0){
			printf("Error Money to be deposited cannot be less than zero\n");
			printf("Press any key to continue\n");
			getch();
			system("cls");
			goto ReAddMoney;																			// Redirects to ReAddMoney.(Line 533)
		}
		balance = balance + addMoney;
		fprintf(fp6,"%d",balance);																		// Prints the Updated balance to the file
		printf(" Now your Account Balance is : %d/-",balance);
	fclose(fp6);																						// Closes the file associated with FILE pointer fp6.
		printf("\n");
		printline();																					// Calls the printline function
		returnOpt();																					// Calls the returOpt() function
}

// For withdrawing
void openmoneyFile2(){
	FILE *fp6;																							// Declares fp6 as a FILE pointer 
	char moneyFileName[30];
	int balance;
	int SubMoney;
	strcpy(moneyFileName,firstName);																	// Copying firstname to file name 
	strcat(moneyFileName,"Balance.txt");																// Joins "Balance.txt" to the moneyFileName	
		fp6 = fopen(moneyFileName,"r");																	// opens the User's balance file in read mode	
		fscanf(fp6,"%d",&balance1);																		// Scans the balance from file to user's balance
		fclose(fp6);																					
	balance = balance1;	
fp6 = fopen(moneyFileName,"w+");
		if(getw(fp6) == NULL){
			balance = 0;
			fprintf(fp6,"%d",balance);	
		}
		ReAddMoney1:
		lightningBankDesign();
		fflush(stdin);																					// Flushes previous user input such as '\n'
		printf("Enter the amount you want to withdraw : ");	
		scanf("%d",&SubMoney);																			// Reads the value for money to be withdrawn by user	
		if(SubMoney < 0){																				// If the money to be withdrawn is less than 0.	
			printf("Error! Money to be withdrawn cannot be less than zero\n");
			printf("Press any key to continue\n");
			getch();
			system("cls");
			goto ReAddMoney1;																			// Redirects to reAddMoney1(Line 570)
		}
		if(SubMoney > balance){																			// If money to be withdrawn is less than the balance in account		 
			system("cls");
			lightningBankDesign();																		// Calls the lightningBankDesign() 
			printf(" Your account doesn't have enough balance");
			printf("\n Your Account Balance : %d/-\n",balance);
			SubMoney = 0;																				// Sets money to be deducted as 0 so that even if it is deducted after going back to menu, it won't affect the balance of the user
			printline();
			printf("\n 1. To Continue\n 2. Go To Transactions\n");
			printf("Press any key to logout\n");
			char a = getch();
			if(a == '1'){
			system("cls");
			fflush(stdin);
			goto ReAddMoney1;																			// Redirects to ReAddMoney1(Line 580)
			}
			if(a == '2'){
				system("cls");
				fflush(stdin);
				lightningBankDesign();															
				transactions();																			// calls the transactions() function		
			}
			else{
				balance = balance;																		
				fprintf(fp6,"%d",balance);
				logout();																				// Calls the logout() function
				goto endX;
			}
		}
		if(balance > SubMoney){																			// Checks if balance is greater than money to be withdrawn
		balance = balance - SubMoney;																	// calculates the new value of balance	
		printf("\n");
		}
		else{
			balance = balance;																			// If balance is not greater than money to be withdrawn, this sets balance to itself;
			printf("\n");
		}
		fprintf(fp6,"%d",balance);																		// Prints the balance to the user's data file
		printf(" Your Account Balance is : %d/-\n",balance);
	fclose(fp6);																						// Closes the file associated with pointer fp6
	printline();																						// Calls the printline() function	
		returnOpt();																					// Calls the returnOpt() function
	endX:		
		fflush(stdin);
}

void checkPassForDepo(){
	char passcode[20];
	system("cls");
	passwordBorder();																					// Calls the passwordBorder() funtion
	
	printf("Enter your first name : ");
	gets(firstName);																					// reads username
	
	FILE *fp4;																							// Declares the FILE pointer fp4
	int i=0,n;
	char passfile1[30],passfile2[30],c;																					
	strcpy(passfile1,firstName);																		// copying firstname to file name		
	strcat(passfile1,"Password.txt");																	// creating a name for file 
	fp4 = fopen(passfile1,"r");																			// opening a file
		while((c = getc(fp4)) != EOF){																	// scans password from the file character by character and saves each char temporarily in variable c.	
			passfile1[i] = c;																			// saves the scanned character of the password in the char array passfile in index 'i'.
			i++;																						// increments the value of i by 1(unity).
		}
		passfile1[i] = '\0';																			// places '\0' in the end of the passfile char array.	
	
	RePass1:																									
	printf(" Enter Your Passcode : ");																	
	scanf("%s",passcode);																				// Reads the password that the user has inputted.
	
	n = strcmp(passcode,passfile1);																		// Compares the passwords ( The one in the files and the one entered now)
	if(n == 0){
		printf("Login Successful. Press ENTER to continue\n");
		getch();																						// Used to hold the screen and take input from the keyboard to continue.
		printf("\n");
		system("cls");
		depoMoney();																					// Calls the depoMoney() function
	}
	else{
		printf("\n Wrong Password");
		printf("\n Do you want to Try again or go back to menu\n");
		printf(" 1. Go To Main Menu\n 2. Try Again\n Press any other key to Log Out : ");
		char e;
		e = getch();																					// Reads the value of 'e' from user input
		if(e == '1'){
			system("cls");
			fflush(stdin);
			start();																					// Calls the start function
		}else if(e == '2'){
			system("cls");
			passwordBorder();																			// Calls tthe passwordBorder() function
			printf(" Enter your first name : %s\n",firstName);
			goto RePass1;																				// Redirects to rePass Function
		}else{
			system("cls");
			logout();																					// Calls the logout() function
		}	
}
}

void checkPassForwithdrawMoney(){
	char passcode[20];
	system("cls");
	passwordBorder();																					// Calls the passwordBorder() function
	
	printf("Enter your first name : ");
	gets(firstName);																					// reads username
	
	FILE *fp4;
	int i=0,n;
	char passfile1[30],passfile2[30],c;																					
	strcpy(passfile1,firstName);																		// copying firstname to file name		
	strcat(passfile1,"Password.txt");																	// creating a name for file 
	fp4 = fopen(passfile1,"r");																			// opening a file
		while((c = getc(fp4)) != EOF){																	// scans password from the file character by character and saves each char temporarily in variable c.	
			passfile1[i] = c;																			// saves the scanned character of the password in the char array passfile in index 'i'.
			i++;																						// increments the value of i by 1(unity).
		}
		passfile1[i] = '\0';																			// places '\0' in the end of the passfile char array.	
	
	RePass2:																									
	printf(" Enter Your Passcode : ");																	
	scanf("%s",passcode);																				// Reads the password that the user has inputted.
	
	n = strcmp(passcode,passfile1);																		// Compares the passwords ( The one in the files and the one entered now)
	if(n == 0){
		printf("Login Successful. Press ENTER to continue\n");
		getch();																						// Used to hold the screen and take input from the keyboard to continue.
		printf("\n");
		system("cls");
		withdrawMoney();
	}
	else{
		printf("\n Wrong Password");
		printf("\n Do you want to Try again or go back to menu\n");
		printf(" 1. Go To Main Menu\n 2. Try Again\n Press any other key to Log Out : ");
		char e;
		e = getch();																					// Reads the value of char 'e' from user input
		if(e == '1'){
			system("cls");
			fflush(stdin);
			start();																					// Calls the start function
		}else if(e == '2'){
			system("cls");
			passwordBorder();																			// Calls the passwordBorder() function
			printf(" Enter your first name : %s\n",firstName);
			goto RePass2;																				// Redirects to RePass2(Line 701)
		}else{
			system("cls");
			logout();																					// Calls the logout() function.
		}	
}
}

void returnOpt(){
	fflush(stdin);																						// Flushes the previous user input which might cause any errors in the program such as a previous '\n'
	printf("\n");
	printf("Do you want to go back to Main Menu? \n");
	printf(" 1. Back to Main Menu\n 2. Transactions\n Press any other key to Log Out : \n ");
	char c;
	c = getch();																						// Reads the value of 'c' of data type char inputted by user
	fflush(stdin);																						// Flushes the previous user input which might cause any errors in the program such as a previous '\n'
	system("cls");
	switch(c){
		case '1':
					start();																			// Calls the start function
					break;
		case '2':	
					lightningBankDesign();																// Calls the lightningBankDesign() function
					char a;
					printf("\n");
					printf("What do you want to do?");
					printf("\n 1. Deposit Money.\n 2. Withdraw Money\n Press any other key to Log Out\n Your Choice : \n");
					a = getch();																		// Reads the value of 'a' of data type char inputted by user
					switch(a){
						case '1' : 
									system("cls");
									depoMoney();														// Calls the depoMoney() function
									break;
						case '2' : 
									system("cls");
									withdrawMoney();													// Calls the withdrawMoney() function
									break;
						case '3' : 
									logout();															// Calls the logout() function
									break;			
						default  :	
									printf("Enter a Valid Choice");
									break;		
					}
					
						break;			
		default :
					logout();																			// Calls the logout() function	
					break;
		}
}

// pointers used till now  fp1,fp2,fp3,fp4,fp5,fp6,fp7.
