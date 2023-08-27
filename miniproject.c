/* ------------------------------------------------------- CAFETERIA MANAGEMENT SYSTEM --------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
struct customer              // Structure to store details of the costumer                      
{          
	int customerID;      // Integer variable to store the customer ID
	char name[15];       // Character array to store name of the costumer
	char phone[11];      // Character array to store mobile number of the costumer
	char address[50];    // Character array to store address of the costumer
	float amount;        // float variable to store the amount paid last by the costumer
};

int ref = 0;
float totalbill=0;
void Coffee();
void FastFood();
void Desserts();
void DisplayBill();
void Menu_display();
void Customer();
void add_account();
void view_account();
void edit_account();
void delete_account();
void PayBill();
int quiz();
int points(int,char);
void admin();
void viewAllAccounts();
int isNameValid(const char *);
int isValidNumber(const char *);
void add_check(char y[]);
void thankyou_message();

void outputcursorposition(int x,int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void printMessage(const char* message)
{
    int len =0;
    int pos = 0;

    //calculating how many spaces need to be printed
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }

    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    system("color 0B");
    getch();
    printf("\n\t\t\t\t\t#################################################################");
    getch();
    printf("\n\t\t\t\t\t############                                         ############");
    getch();
    printf("\n\t\t\t\t\t############      Cafeteria Management System        ############");
    getch();
    printf("\n\t\t\t\t\t############                                         ############");
    getch();
    printf("\n\t\t\t\t\t#################################################################");
    getch();
    printf("\n\t\t\t\t\t-----------------------------------------------------------------\n");
    printMessage(message);
    printf("\n\t\t\t\t\t-----------------------------------------------------------------\n");
}
void welcomeMessage()
{
     	headMessage("");
        printf("\n\n\n\n\n");
	getch();
    	printf("\n\t\t\t\t\t    **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    	getch();
	printf("\n\t\t\t\t\t          =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	getch();
    	printf("\n\t\t\t\t\t          =                WELCOME                    =");
    	getch();
	printf("\n\t\t\t\t\t          =                  TO                       =");
    	getch();
	printf("\n\t\t\t\t\t          =               CAFETERIA                   =");
    	getch();
	printf("\n\t\t\t\t\t          =               MANAGEMENT                  =");
    	getch();
	printf("\n\t\t\t\t\t          =                 SYSTEM                    =");
    	getch();
	printf("\n\t\t\t\t\t          =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    	getch();
	printf("\n\t\t\t\t\t    **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    	getch();
	printf("\n\n\n\t\t\t\t\t     Press any key to continue.....");
    	getch();
}
void main()
{
	welcomeMessage();
	time_t t;
	time(&t);
	int choice;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t\t  -----------------------------------------------------");
	printf("\n\t\t\t\t\t\t                                                       ");
	printf("\n\t\t\t\t\t\t               Today's date and time                   ");
	printf("\n\t\t\t\t\t\t             %s",ctime(&t));
	printf("\n\t\t\t\t\t\t                                                       ");
	printf("\n\t\t\t\t\t\t  -----------------------------------------------------");
	printf("\n\t\t\t\t\t\t  Press any key to continue...        ");
	getch();
	system("cls");

	while(1)
	{
		printf("\n\n\n\n\n\n\t\t\t\t\t1.Admin \n\t\t\t\t\t2.Customer \n\t\t\t\t\t3.Exit \n");

		printf("\n\t\t\t\t\tEnter your choice : ");
	        scanf("%d",&choice);
		switch(choice)
		{
			case 1  : admin();
				  break;
			case 2  : Customer();
				  break;
			case 3  : system("cls");
				  system("color 0E");
				  thankyou_message();
				  system("color 06");
				  getch();
				  system("cls");
				  exit(0);
				  break;
			default : printf("\n\t\t\t\t\tInvalid choice !!\n");
				  printf("\n\t\t\t\t\tPress any key to continue...\n");
				  getch();
				  break;
		}
	}
}
void admin()
{
	system("cls");
	system("color 0E");
	int choice;
        int k,a = 0,i = 0;
        char p;
        char checkuname[13];
        char checkpword[13];
        char username[13] = "miniproject";
        char password[13] = "cafeteria";
    	do{
        	printf("\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN FORM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
		printf("\t\t\t\t\t            Enter username: ");
		scanf("%s",&checkuname);
		printf("\n\t\t\t\t\t            Enter password: ");
		p = 0;
		while(p!=13)
		{
			p = getch();
			if(p!=13 && p!=9)
			{
				printf("*");
				checkpword[i]=p;
				i++;
			}
		}
		checkpword[i]='\0';
		int z = strcmp(checkuname,username);
		int x = strcmp(checkpword,password);
		if( !z && !x)
		{
			printf("\n\n\t\t\t\t\t            WELCOME! LOGIN SUCCESSFUL");
			getch();
			goto opt;
			break;
		}
		else
		{
       			printf("\n\n\t\t\t\t\t            SORRY! LOGIN UNSUCCESSFUL");
			a++;
       			getch();
			system("cls");
		}
	}while(a<3);
	if(a>=3)
    	{
		system("cls");
		system("color oC");
   	        printf("\n\n\n\n\n\n\t\t\t\t\t\t SORRY YOU HAVE ENTERED WRONG DETAILS FOR THREE TIMES!!!\n\n");
   		exit(1);
    	}
	opt:{
   	system("cls");
    	if(a<3)
	{
		system("color 09");
    		printf("\n\n\n\n\n\t\t\t\t\t\t 1. View all accounts    \n");
		printf("\t\t\t\t\t\t 2. Back to home  \n\n");
    		printf("\t\t\t\t\t\t Enter your choice : ");
    		scanf("%d",&choice);
    		switch(choice)
    		{
        		case 1 : viewAllAccounts();break;
			default :
				  printf("\n\t\t\t\t\t\t Press any key to continue...");
				  getch();
				  system("cls");
				  break;
    		}	    
    	}//end of if block
        }//end of opt
}
void viewAllAccounts()
{
	system("cls");
	system("color 03");
	FILE *fp;
	struct customer c;
	fp=fopen("customerInfo.txt","r");
	printf("\n\t\t\t\t\t==============================================================\n");
	printf("\t\t\t\t\t\t\tAll Customer Details");
	printf("\n\t\t\t\t\t==============================================================\n");
	while(1)
	{
		fread(&c,sizeof(c),1,fp);
		if(feof(fp))
			break;
		printf("\n\t\t\t\t\tCustomerID       :%d",c.customerID);
		printf("\n\t\t\t\t\tName             :%s",c.name);
		printf("\n\t\t\t\t\tPhone            :%s",c.phone);
		printf("\n\t\t\t\t\tAddress          :%s",c.address);
		printf("\n\t\t\t\t\tAmount last paid :%.2f\n",c.amount);
	}
	printf("\t\t\t\t\t==============================================================\n\n");
	getch();
	system("cls");
	fclose(fp);
}
void Customer()
{
	system("cls");
	system("color 0D");
	int choice;
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t 1.Create account");
        printf("\n\t\t\t\t\t\t 2.view account");
	printf("\n\t\t\t\t\t\t 3.Edit account");
	printf("\n\t\t\t\t\t\t 4.Delete account");
        printf("\n\t\t\t\t\t\t 5.View Menu to order food");
	printf("\n\t\t\t\t\t\t 6.Display bill");
	printf("\n\t\t\t\t\t\t 7.Pay bill");
	printf("\n\t\t\t\t\t\t 8.Back to home\n");
	printf("\n\t\t\t\t\t\t Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1  :  add_account();break;
		case 2  :  view_account();break;
		case 3  :  edit_account();break;
	        case 4  :  delete_account();break;
		case 5  :  Menu_display();break;
		case 6  :  DisplayBill();break;
		case 7  :  PayBill();break;
	        case 8  :  system("cls");
			   break;
		default :  printf("\n\n\t\t\t\t\t\t Invalid input\n");
			   printf("\t\t\t\t\t\t Press any key to continue...");
			   getch();
			   break;
	}
}
void PayBill()
{
	system("cls");
	system("color 09");
	FILE *fp,*fp1;
	struct customer c1;
	char name[20];
	int id,found=0;
	fp=fopen("customerInfo.txt","r");
	fp1=fopen("temp.txt","w");
	printf("\n\n\n\n\n\t\t\t\t\t\tEnter the your id to pay bill:");
	scanf("%d",&id);
	fflush(stdin);
	printf("\n\t\t\t\t\t\tEnter your name : ");
	gets(name);
	fflush(stdin);
	while(1)
	{
		fread(&c1,sizeof(c1),1,fp);
		if(feof(fp))
			break;
		if(c1.customerID==id && (strcmp(c1.name,name) == 0))
		{
			found=1;
			c1.amount=0;
			if(totalbill != 0){
			printf("\n\n\t\t\t\t\t\t Your total bill is %.2f",totalbill);
		        printf("\n\n\t\t\t\t Play the quiz and get upto 10%c discount !!! (Press y/Y to play the quiz)\n\t\t\t\t\t\t\t Press any other key to continue \n",37);
			//char option;
			fflush(stdin);
			//scanf("%c",&option);
			if(toupper(getch()) == 'Y')
			{
				int dis = quiz();
				float Bill = totalbill;
				float discount = (dis*Bill)/100;
				totalbill = Bill - discount;
				system("cls");
				printf("\n\t\t\t\t\t\t Your total bill after discount is %.2f",totalbill);
				printf("\n\t\t\t\t\t\t Enter bill amount:");
				scanf("%f",&c1.amount);
				fwrite(&c1,sizeof(c1),1,fp1);
				printf("\n\t\t\t\t\t\t You have paid successfully.....\n");
				getch();
				system("cls");
				totalbill = 0;
			}
			else
			{	system("cls");
				printf("\n\t\t\t\t\t\t Enter bill amount:");
				scanf("%f",&c1.amount);
				fwrite(&c1,sizeof(c1),1,fp1);
				printf("\n\t\t\t\t\t\t You have paid successfully.....\n");
				getch();
				system("cls");
				totalbill = 0;
			}
			}
			else
			{
				fwrite(&c1,sizeof(c1),1,fp1);
				printf("\n\n\t\t\t\t\t\t It seems you have not yet ordered.....\n");
				getch();
				system("cls");
			}
		}
		else
		{
			fwrite(&c1,sizeof(c1),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found==0){
		printf("\n\t\t\t\t\t\t Sorry record not found\n\n");
		getch();
		system("cls");
	}
	else
	{
		fp=fopen("customerInfo.txt","w");
		fp1=fopen("temp.txt","r");
		while(1)
		{
			fread(&c1,sizeof(c1),1,fp1);
			if(feof(fp1))
				break;
			fwrite(&c1,sizeof(c1),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);	

}
int quiz()
{
	system("cls");
	system("color 03");
	char c;
	int score = 0;
	int lower = 1;
	int upper = 20;
	srand(time(0));
	int i=0;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 QUIZ \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	getch();
	while(i<5)
	{
		int choice = (rand()%(upper-lower+1)) + lower;
		switch(choice)
		{
			case 1  : system("cls");
				 // goto label;
				  printf("\n\t\t\t\tIn which US state is coffee grown commercially?\n");
				  printf("\t\t\t\ta. California \t\t b. Florida\n\t\t\t\tc. Hawaii \t \t d. Montana\n");
				  printf("\t\t\t\tEnter your answer : ");
				  //getch();
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 2  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhich coffee is also known as Cat Poop Coffee?\n");
				  printf("\t\t\t\ta. Luwak \t\t b. Espresso\n\t\t\t\tc. Cafe Cubano \t\t d. Caramel Macchiato\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 3  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhere did the tres leches cake originate?\n");
				  printf("\t\t\t\ta. Australia \t \t   b. Mexico\n\t\t\t\tc. Russia \t \t d. New Zealand\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 4  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhat country is known for this torched dessert called creme brulee?\n");
				  printf("\t\t\t\ta. South Africa \t\t\t b. Russia\n\t\t\t\tc. Australia\t \t d. France\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 5  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tOn an average how many donuts are made per year in US?\n");
				  printf("\t\t\t\ta. 70 million \t b. 1 million\n\t\t\t\tc. 10 billion \t d. 5 billion\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 6  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhere did the first commercial pizza originate?\n");
				  printf("\t\t\t\ta. US\t\t b. Italy\n\t\t\t\tc. China \t d. Russia\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 7  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhich month is celebrated as the National Pizza month in America?\n");
				  printf("\t\t\t\ta. December \t b. January\n\t\t\t\tc. October  \t d. April\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 8  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhere were the French Fries first invented?\n");
				  printf("\t\t\t\ta. Belgium \t b. France\n\t\t\t\tc. Australia \t d. Italy\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 9  : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhen is National Latte day celebrated?\n");
				  printf("\t\t\t\ta. January 10th \t b.November 29th\n\t\t\t\tc. April 15th   \t d. October 7th\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 10 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tOn an average how many sandwiches are eaten by the people in the US?\n");
				  printf("\t\t\t\ta. 70 billion \t b. 300 million\n\t\t\t\tc. 30 billion \t d. 6 million\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 11 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhich city consumes most ice cream per year?\n");
				  printf("\t\t\t\ta. Los Angeles\t b. New York\n\t\t\t\tc. Bagheria   \t d. Rome\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 12 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tHow much pasta is produced by Italy per year?\n");
				  printf("\t\t\t\ta. 100300 tons \t         b. 68110 tons\n\t\t\t\tc. 1432990 tons \t d. None\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 13 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tCoffee was discovered in?\n");
				  printf("\t\t\t\ta. 750 AD \t b. 800 AD\n\t\t\t\tc. 900 AD \t d. 960 AD\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 14 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tHow many Big Macs are sold per year in US?\n");
				  printf("\t\t\t\ta. 500 million \t b. 100 million\n\t\t\t\tc. 50 million  \t d. 120 million\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 15 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tHow many calories does one slice of Black Forest Cake have?\n");
				  printf("\t\t\t\ta. 120 \t b. 299\n\t\t\t\tc. 610 \t d. 441\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 16 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tHow many types of coffee exists?\n");
				  printf("\t\t\t\ta.22 \t b. 9\n\t\t\t\tc.12 \t d. 20\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 17 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tModern commercial American cream cheese was developed in?\n");
				  printf("\t\t\t\ta. 1900 \t b. 1872\n\t\t\t\tc. 2000 \t d. 1720\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 18 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhich dessert given has most calories?\n");
				  printf("\t\t\t\ta. Puff Pastry \t  b. Cheesecake\n\t\t\t\tc. Tiramisu \t d. Treacle tart\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 19 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhich pasta is also known as mixed sauce pasta?\n");
				  printf("\t\t\t\ta. Red sauce pasta \t b. White sauce pasta\n\t\t\t\tc. Pink sauce pasta \t d. None\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			case 20 : system("cls");
				  //goto label;
				  printf("\n\t\t\t\tWhich milkshake is the most popular?\n");
				  printf("\t\t\t\ta. Peanut Butter Milkshakes \t b. Mint Chocolate Milkshakes\n\t\t\t\tc. Venilla Berry Milkshakes \t d. Cookies and Cream Milkshakes\n");
				  printf("\t\t\t\tEnter your answer : ");
				  fflush(stdin);
				  scanf("%c",&c);
				  score = score + points(choice,c);
				  break;
			default : break;
		}
		i++;
	}
	return (score*2);
}
int points(int ch,char ans)
{
	if(ans>='a' && ans<='d')
	{
			if(ch == 1)
			{
				if(ans == 'c')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 2)
			{
				if(ans == 'a')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 3)
			{
				if(ans == 'b')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 4)
			{
				if(ans == 'd')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 5)
			{
				if(ans == 'c')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}	
			else if(ch == 6)
			{
				if(ans == 'b')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 7)
			{
				if(ans == 'c')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 8)
			{
				if(ans == 'a')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 9)
			{
				if(ans == 'd')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 10)
			{
				if(ans == 'b')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 11)
			{
				if(ans == 'a')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 12)
			{
				if(ans == 'c')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 13)
			{
				if(ans == 'b')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
		        	
			else if(ch == 14)
			{
				if(ans == 'a')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 15)
			{
				if(ans == 'd')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 16)
			{
				if(ans == 'c')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 17)
			{
				if(ans == 'b')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 18)
			{
				if(ans == 'a')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 19)
			{
				if(ans == 'c')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else if(ch == 20)
			{
				if(ans == 'd')
				{
					printf("\t\t\t\tCorrect answer !! You have got a point\n");
					getch();
					return 1;
				}
				else
				{
					printf("\n\t\t\t\tWrong answer...\n");
					getch();
					return 0;
				}
			}
			else{
				printf("\t\t\t\tWrong choice\n");
				getch();
			}
	}
	else{
		printf("\n\t\t\t\twrong Choice entered\n");
		getch();
	}
}
int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])))
        {
		if(!(isspace(name[index])))
		{
            		validName = 0;
            		break;
		}
		else
			break;
        }
    }
    return validName;
}
int isValidNumber(const char *number)
{
	int validNumber = 1;
	int len = strlen(number);
	int num = atoi(number);
	if(num != 0)
	{
		if(len == 10)
			return validNumber;
		else
		{
			validNumber = 0;
			return validNumber;
		}
	}
	else
	{
		validNumber = 0;
		return validNumber;
	}
}
void add_account()
{
	system("cls");
	system("color 02");
	FILE *fp;
	char y[20];
	struct customer c1;
	int id,status = 0;
	fflush(stdin);
	printf("\n\n\n\t\t\t\t\t\t Do you want to create an account? [Y/N]:");
	while(toupper(getche())=='Y'){
		getchar();
		fp=fopen("customerInfo.txt","a");
		add_check(y);
		c1.customerID = atoi(y);

		do{
			printf("\n\t\t\t\t\t\tEnter your Name        :");
			gets(c1.name);
			status = isNameValid(c1.name);
			if (!status)
        		{
            			printf("\n\t\t\t\t\t\t\tName contains an invalid character. Please enter again...\n");
	    			getch();
        		}
		}while(!status);
		status = 0;
		do{
			printf("\n\t\t\t\t\t\tEnter your phone number:");
			gets(c1.phone);
			status = isValidNumber(c1.phone);
			if(!status)
			{
				printf("\n\t\t\t\t\t\t\t\tMobile number is in invalid format.Please enter again...\n");
			}
		}while(!status);
		printf("\n\t\t\t\t\t\tEnter your Address     :");
		gets(c1.address);
		c1.amount=0;
		printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YOUR ACCOUNT IS CREATED SUCCESSFULLY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
		getch();
		system("cls");
		fwrite(&c1,sizeof(c1),1,fp);
	//	fprintf(fp,"\n");
		fclose(fp);
	}
}
void add_check(char y[])
{
	int flag;
	FILE *fp;
	struct customer c;
	int status = 0;
	fp = fopen("customerInfo.txt","r");
	while(1)
	{
		flag = 1;
		rewind(fp);
		printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Creating Your Account.......... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
		printf("\n\t\t\t\t\t\tEnter a reference id   :");
		gets(y);
		while(fread(&c,sizeof(c),1,fp)==1)
		{
			if(atoi(y) == c.customerID)
			{
				flag = 0;
				printf("\n\t\t\tSorry it seems this reference id already exists.... Press any key to enter a differnet id ..\n");
				getch();
				system("cls");
				getch();
				break;
			}
		}
		if(flag == 1)
			break;
	}
	fclose(fp);
}
void view_account()
{
	system("cls");
	system("color 03");
	FILE *fp;
	struct customer c;
	int id,found=0;
	fp=fopen("customerInfo.txt","r");
	printf("\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t\tEnter your reference ID to view your account:");
	scanf("%d",&id);
	while(1)
	{
		fread(&c,sizeof(c),1,fp);
		if(feof(fp))
			break;
		if(c.customerID==id)
		{
			found=1;
			printf("\n\n\n\n\n\n");
			printf("\n\t\t\t\t\t\t  =============================================\n");
			printf("\t\t\t\t\t\t\t\tCustomer Details of %d",c.customerID);
			printf("\n\t\t\t\t\t\t  =============================================\n");
			printf("\n\t\t\t\t\t\t    Name             : %s",c.name);
			printf("\n\t\t\t\t\t\t    Phone Number     : %s",c.phone);
			printf("\n\t\t\t\t\t\t    Address          : %s",c.address);
			printf("\n\t\t\t\t\t\t    Amount last paid : %.2f",c.amount);
			printf("\n\t\t\t\t\t\t  =============================================\n");
			getch();
			system("cls");
		}
	}
	if(found==0)
	{
		printf("\n\n\t\t\t\t\t\t         Sorry no record found");
		getch();
		system("cls");
	}
	fclose(fp);
}
void edit_account()
{
	system("cls");
	system("color 09");
	FILE *fp,*fp1;
	struct customer c1;
	int id,found=0,status=0;
	char name[20];
	char Name[20],Mobile[12],Addr[200];
	fp=fopen("customerInfo.txt","r");
	fp1=fopen("temp.txt","w");
	printf("\n\n\n\n\n\n\t\t\t\t\t\tEnter your reference id to edit:");
	scanf("%d",&id);
	fflush(stdin);
	printf("\n\t\t\t\t\t\tEnter your name                :");
	gets(name);
	system("cls");
	while(1)
	{
		fread(&c1,sizeof(c1),1,fp);
		if(feof(fp))
			break;
		if(c1.customerID==id && (strcmp(c1.name,name) == 0))
		{
			found=1;
			printf("\n\t\t\t\t\t\t  =================================================\n");
			printf("\t\t\t\t\t\t\t\tCustomer Details of %d",c1.customerID);
			printf("\n\t\t\t\t\t\t  =================================================\n");
			printf("\n\t\t\t\t\t\t        Name                   : %s",c1.name);
			printf("\n\t\t\t\t\t\t        Phone Number           : %s",c1.phone);
			printf("\n\t\t\t\t\t\t        Address                : %s",c1.address);
			printf("\n\t\t\t\t\t\t        Amount paid last       : %.2f",c1.amount);
			printf("\n\t\t\t\t\t\t  =================================================\n");
			strcpy(Name,c1.name);
			strcpy(Mobile,c1.phone);
			strcpy(Addr,c1.address);
			printf("\n\n\t\t\t\t\t\t   Do you want to edit your account ? [Y/N] ");
			if(toupper(getche()) == 'Y'){
				system("cls");
				printf("\n\n\n\n\n");
				printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Edit Your Account....... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
				fflush(stdin);
				do{
					printf("\n\t\t\t\t\t\tEnter your Name        :");
					gets(c1.name);
					status = isNameValid(c1.name);
					if (!status)
        				{
            					printf("\n\t\t\t\t\tName contains an invalid character. Please enter again...\n");
	    					getch();
        				}
				}while(!status);
				status = 0;
				do{
					printf("\n\t\t\t\t\t\tEnter your phone number:");
					gets(c1.phone);
					status = isValidNumber(c1.phone);
					if(!status)
					{
						printf("\n\t\t\t\t\t\t\t\tMobile number is in invalid format.Please enter again...\n");
					}
				}while(!status);
				printf("\n\t\t\t\t\t\tEnter your address     :");
				scanf("%s",c1.address);
				printf("\n\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Account edited successfully \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				getch();
				system("cls");
				fwrite(&c1,sizeof(c1),1,fp1);
			}
			else
			{
				fwrite(&c1,sizeof(c1),1,fp1);
				getch();
				system("cls");
			}
		}
		else
		{
			fwrite(&c1,sizeof(c1),1,fp1);
			getch();
			system("cls");
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found==0){
		printf("\n\n\n\n\n\n\n\t\t\t\t\t\t    Sorry record not found\n\n");
		getch();
		system("cls");
	}
	else
	{
		fp=fopen("customerInfo.txt","w");
		fp1=fopen("temp.txt","r");
		while(1)
		{
			fread(&c1,sizeof(c1),1,fp1);
			if(feof(fp1))
				break;
			fwrite(&c1,sizeof(c1),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
void delete_account()
{
	system("cls");
	system("color 08");
	FILE *fp,*fp1;
	struct customer c1;
	int id,found=0;
	char name[20];
	fp=fopen("customerInfo.txt","r");
	fp1=fopen("temp.txt","w");
	printf("\n\n\n\n\t\t\t\t\t    Enter your reference id to delete your account:");
	scanf("%d",&id);
	fflush(stdin);

	while(1)
	{
		fread(&c1,sizeof(c1),1,fp);
		if(feof(fp))
			break;
		if(c1.customerID==id)
		{
			found=1;
			printf("\n\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Account deleted successfully..... \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
			getch();
			system("cls");
		}
		else
		{
			fwrite(&c1,sizeof(c1),1,fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
		printf("\n\t\t\t\t\t\tSorry record not found\n\n");
	else
	{
		fp=fopen("customerInfo.txt","w");
		fp1=fopen("temp.txt","r");
		while(1)
		{
			fread(&c1,sizeof(c1),1,fp1);
			if(feof(fp1))
				break;
			fwrite(&c1,sizeof(c1),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
void Menu_display()
{
	system("cls");
	system("color 01");
	FILE *FP=fopen("bill.txt","w");
	while(1)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FOOD MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
		printf("\n\n\t\t\t\t\t\t     --------------- Food Categories --------------- \n\n");
	       	printf("\t\t\t\t\t\t    1.Coffee\n\t\t\t\t\t\t    2.FastFood\n\t\t\t\t\t\t    3.Desserts\n\t\t\t\t\t\t    4.Back go home\n");
		int n;
		printf("\n\t\t\t\t\t\t    Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:Coffee();break;
			case 2:FastFood();break;
			case 3:Desserts();break;
			case 4:break;
			default:printf("\n\t\t\t\t\t    Invalid");
				printf("\n\t\t\t\t\t    Enter any key to continue..");
				getch();
				break;
		}
		if(n==4){
			Customer();
			break;
		}
	}
	fclose(FP);
}
void FastFood()
{ 
	system("cls");
	system("color 02");
	char ch;
	ref = 1;
	FILE *fp1=fopen("bill.txt","a");
	do{
	printf("\n\t\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FastFood menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t\t\t\t\t\t     1.veg pizza          Rs.50/-\n");
	printf("\t\t\t\t\t\t     2.chicken pizza      Rs.60/-\n");
	printf("\t\t\t\t\t\t     3.veg burger         Rs.40/-\n");
	printf("\t\t\t\t\t\t     4.chicken burger     Rs.50/-\n");
	printf("\t\t\t\t\t\t     5.white sauce pasta  Rs.30/-\n");
	printf("\t\t\t\t\t\t     6.red sauce pasta    Rs.30/-\n");
	printf("\t\t\t\t\t\t     7.pink sauce pasta   Rs.30/-\n");
	printf("\t\t\t\t\t\t     8.French fries       Rs.40/-\n");
	printf("\t\t\t\t\t\t     9.Masala fries       Rs.50/-\n");
	printf("\t\t\t\t\t\t     10.veg sandwich      Rs.20/-\n");
	printf("\t\t\t\t\t\t     11.chicken sandwich  Rs.30/-\n");
	int n;
	printf("\n\t\t\t\t\t\t     Enter your choice 1-11:");
	scanf("%d",&n);
	
	switch(n)
	{
		int a;
		float totalPrice=0;
		case 1:printf("\t\t\t\t\t\t     One veg pizza costs Rs.50/-\n");
		       printf("\t\t\t\t\t\t     Enter quantity:");
		       scanf("%d",&a);
                       totalPrice=50*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Veg pizza","Rs.50/-",a,"Rs.",totalPrice,"/-");
		       totalbill+=a*50;break;
		case 2:printf("\t\t\t\t\t\t     one chicken pizza costs Rs.60/-\n");
                       printf("\t\t\t\t\t\t     Enter quantity:");
	               scanf("%d",&a);
		       totalPrice=60*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Chicken pizza","Rs.60/-",a,"Rs.",totalPrice,"/-");
		       totalbill+=a*60;break;
		case 3:printf("\t\t\t\t\t\t     one veg burger costs Rs.40/-\n");
		       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=40*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Veg Burger","Rs.40/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=40;break;
                case 4:printf("\t\t\t\t\t\t     one chicken burger costs Rs.50/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=50*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Chicken Burger","Rs.50/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*50;break;
                case 5:printf("\t\t\t\t\t\t     one white sauce pasta costs Rs.30/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=30*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","White Sauce Pasta","Rs.30/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*30;break;
	        case 6:printf("\t\t\t\t\t\t     one red sauce pasta costs Rs.30/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=30*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Red Sauce Pasta","Rs.30/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*30;break;
	        case 7:printf("\t\t\t\t\t\t    one pink sauce pasta costs Rs.30/-\n");
                       printf("\t\t\t\t\t\t    enter quantity:");
                       scanf("%d",&a);
		       totalPrice=30*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Pink Sauce Pasta","Rs.30/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*30;break;
	        case 8:printf("\t\t\t\t\t\t     one French fries costs Rs.40/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=40*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","French Fries","Rs.30/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*40;break;
	        case 9:printf("\t\t\t\t\t\t     one Masala fries costs Rs.50/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=50*a;
		       fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Masala Fries","Rs.50/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*50;break;
	        case 10:printf("\t\t\t\t\t\t    one veg sandwich costs Rs.20/-\n");
                        printf("\t\t\t\t\t\t    enter quantity:");
			scanf("%d",&a);
		        totalPrice=20*a;
		        fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Veg Sandwich","Rs.20/-",a,"Rs.",totalPrice,"/-");
                        totalbill+=a*20;break;
	        case 11:printf("\t\t\t\t\t\t     one chicken sandwich costs Rs.30/-\n");
                        printf("\t\t\t\t\t\t     enter quantity:");
			scanf("%d",&a);
		        totalPrice=30*a;
		        fprintf(fp1,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Chicken Sandwich","Rs.30/-",a,"Rs.",totalPrice,"/-");
                        totalbill+=a*30;break;
                default:printf("\t\t\t\t\t\t     sorry your choice is invalid\n");
	}
	printf("\n\t\t\t\t\t\t     Do you want to order anything else from fastfood [Y/N]:");
       scanf(" %c",&ch);
        system("cls");
	}while(toupper(ch) == 'Y');
        fclose(fp1);	
}
void Coffee()
{
	system("cls");
	system("color 0D");
        char ch;
	ref = 1;
	FILE *fp2=fopen("bill.txt","a");
	do{
	printf("\n\t\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Coffee menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t\t\t\t\t\t     1.Cappuccino         Rs.40/-\n");
	printf("\t\t\t\t\t\t     2.Espresso           Rs.40/-\n");
	printf("\t\t\t\t\t\t     3.Latte              Rs.40/-\n");
	printf("\t\t\t\t\t\t     4.Mocha              Rs.50/-\n");
	printf("\t\t\t\t\t\t     5.Americano          Rs.40/-\n");
	printf("\t\t\t\t\t\t     6.cold coffee        Rs.30/-\n");
	int n;
        
	printf("\n\t\t\t\t\t\t     Enter your choice 1-6:");
	scanf("%d",&n);
	switch(n)
	{
		int a;
		float totalPrice=0;
		case 1:printf("\t\t\t\t\t\t     one Cappuccino costs Rs.40/-\n");
		       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=40*a;
		       fprintf(fp2,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Cappuccino","Rs.40/-",a,"Rs.",totalPrice,"/-");
		       totalbill+=a*40;break;
		case 2:printf("\t\t\t\t\t\t     one Espresso costs Rs.40/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
	               scanf("%d",&a);
		       totalPrice=40*a;
		       fprintf(fp2,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Espresso","Rs.40/-",a,"Rs.",totalPrice,"/-");
		       totalbill+=a*40;break;
		case 3:printf("\t\t\t\t\t\t     one Latte costs Rs.40/-\n");
		       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=40*a;
		       fprintf(fp2,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Latte","Rs.40/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=40;break;
                case 4:printf("\t\t\t\t\t\t     one Mocha costs Rs.50/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
                       totalPrice=50*a;
		       fprintf(fp2,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Mocha","Rs.50/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*50;break;
                case 5:printf("\t\t\t\t\t\t     one Americano costs Rs.40/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=40*a;
		       fprintf(fp2,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Americano","Rs.40/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*40;break;
	        case 6:printf("\t\t\t\t\t\t     one Cold coffee costs Rs.30/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=30*a;
		       fprintf(fp2,"\t\t\t\t\t    %s\t\t\t%s\t\t %d\t\t%s%.2f%s\n","Cold coffee","Rs.30/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*30;break;
                default:printf("sorry your choice is invalid\n");
	}
	printf("\n\t\t\t\t\t\t     Do you want to order anything else from Coffee section [Y/N]:");
        scanf(" %c",&ch);
	system("cls");
	}while(toupper(ch) == 'Y');       
	fclose(fp2);
}
void Desserts()
{
	system("cls");
	system("color 0B");
        char ch;
	ref = 1;
	FILE *fp3=fopen("bill.txt","a");
	do{
	printf("\n\t\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Desserts menu \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\t\t\t\t\t\t     1.Choco lava cake             Rs.90/-\n");
	printf("\t\t\t\t\t\t     2.Brownies with icecream      Rs.80/-\n");
	printf("\t\t\t\t\t\t     3.chocolate mousse cake       Rs.60/-\n");
	printf("\t\t\t\t\t\t     4.Classic donuts              Rs.50/-\n");
	printf("\t\t\t\t\t\t     5.Black forest pastry         Rs.40/-\n");
	printf("\t\t\t\t\t\t     6.Blueberry cheesecake        Rs.50/-\n");
	printf("\t\t\t\t\t\t     7.Chocochip icecream          Rs.70/-\n");
	printf("\t\t\t\t\t\t     8.Oreo milkshake              Rs.60/-\n");
	int n;
	
	printf("\n\t\t\t\t\t\t     Enter your choice 1-8:");
	scanf("%d",&n);
	switch(n)
	{
		int a;
		float totalPrice=0;
		case 1:printf("\t\t\t\t\t\t     one Choco lava cake costs Rs.90/-\n");
		       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
  		       totalPrice=90*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Choco lava Cake","Rs.90/-",a,"Rs.",totalPrice,"/-");
		       totalbill+=a*90;break;
		case 2:printf("\t\t\t\t\t\t     one Brownies with icecream costs Rs.80/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
	               scanf("%d",&a);
		       totalPrice=80*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t%s\t\t %d\t\t%s%.2f%s\n","Brownies with icecream","Rs.80/-",a,"Rs.",totalPrice,"/-");
		       totalbill+=a*80;break;
		case 3:printf("\t\t\t\t\t\t     one piece of chocolate mousse cake Rs.60/-\n");
		       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=60*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t%s\t\t %d\t\t%s%.2f%s\n","Chocolate mousse cake","Rs.60/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=60;break;
                case 4:printf("\t\t\t\t\t\t     one Classic donut costs Rs.50/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=50*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Classic donut","Rs.50/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*50;break;
                case 5:printf("\t\t\t\t\t\t     one Black forest pastry costs Rs.40/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
	               totalPrice=40*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Black forest pastry","Rs.40/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*40;break;
	        case 6:printf("\t\t\t\t\t\t     one piece of blueberry cheesecake costs Rs.50/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=50*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t%s\t\t %d\t\t%s%.2f%s\n","Blueberry cheesecake","Rs.50/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*50;break;
                case 7:printf("\t\t\t\t\t\t     one chocochip icecream costs Rs.70/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
                       scanf("%d",&a);
		       totalPrice=70*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Chocochip icecream","Rs.70/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*70;break;
	        case 8:printf("\t\t\t\t\t\t     one Oreo milkshake costs Rs.60/-\n");
                       printf("\t\t\t\t\t\t     enter quantity:");
		       scanf("%d",&a);
		       totalPrice=60*a;
		       fprintf(fp3,"\t\t\t\t\t    %s\t\t%s\t\t %d\t\t%s%.2f%s\n","Oreo milkshake","Rs.60/-",a,"Rs.",totalPrice,"/-");
                       totalbill+=a*60;break;
                default:printf("\n\t\t\t\t\t\t     sorry your choice is invalid\n");
	}
	printf("\n\t\t\t\t\t\t     Do you want to order anything else from Desserts section [Y/N]:");
       scanf(" %c",&ch);
        system("cls");
	}while(toupper(ch) == 'Y');       
	fclose(fp3);
}
void DisplayBill()
{
	system("cls");
	system("color 0D");
	if(ref != 1 || totalbill == 0)
	{
		printf("\n\n\n\t\t\t\t\t\t It seems you have not yet ordered !!!!!!!\n");
		getch();
		system("cls");
	}
	else{
		printf("\n\t\t\t\t\t\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 YOUR BILL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
		printf("\n\t\t\t\t\t    ===============================================================================\n");
		printf("\t\t\t\t\t         Item		        Unit price       Quantity 	Total price   ");
		printf("\n\t\t\t\t\t    ===============================================================================\n");
		char c;
		FILE *fp=fopen("bill.txt","r");
		while((c=getc(fp))!=EOF)
		{		
			putchar(c);
		}
		fclose(fp);
		printf("\n\t\t\t\t\t    ===============================================================================\n");
		printf("\t\t\t\t\t                           Total amount is Rs.%.2f/-",totalbill);
		printf("\n\t\t\t\t\t    ===============================================================================\n");
		getch();
		system("cls");
	}
}

void thankyou_message()
{
    outputcursorposition(20, 15);
    Sleep(150);
    printf("   ==================\n");
    outputcursorposition(20, 16);
    printf("           ||        \n");
    outputcursorposition(20, 17);
    printf("           ||        \n");
    outputcursorposition(20, 18);
    printf("           ||        \n");
    outputcursorposition(20, 19);
    printf("           ||        \n");
    outputcursorposition(20, 20);
    printf("           ||        \n");
    outputcursorposition(20, 21);
    printf("           ||        \n");
    outputcursorposition(20, 22);
    printf("           ||        \n");
    outputcursorposition(20, 23);
    printf("           ||        \n");

    outputcursorposition(40, 15);
    Sleep(150);
    printf("    ||             ||\n");
    outputcursorposition(40, 16);
    printf("    ||             ||\n");
    outputcursorposition(40, 17);
    printf("    ||             ||\n");
    outputcursorposition(40, 18);
    printf("    ||             ||\n");
    outputcursorposition(40, 19);
    printf("    || =========== ||\n");
    outputcursorposition(40, 20);
    printf("    ||             ||\n");
    outputcursorposition(40, 21);
    printf("    ||             ||\n");
    outputcursorposition(40, 22);
    printf("    ||             ||\n");
    outputcursorposition(40, 23);
    printf("    ||             ||\n");

    outputcursorposition(61, 15);
    Sleep(150);
    printf("      ============\n");
    outputcursorposition(61, 16);
    printf("    ||            ||\n");
    outputcursorposition(61, 17);
    printf("    ||            ||\n");
    outputcursorposition(61, 18);
    printf("    ||            ||\n");
    outputcursorposition(61, 19);
    printf("    ||============||\n");
    outputcursorposition(61, 20);
    printf("    ||            ||\n");
    outputcursorposition(61, 21);
    printf("    ||            ||\n");
    outputcursorposition(61, 22);
    printf("    ||            ||\n");
    outputcursorposition(61, 23);
    printf("    ||            ||\n");

    outputcursorposition(81, 15);
    Sleep(150);
    printf("    || \\\\         ||\n");
    outputcursorposition(81, 16);
    printf("    ||  \\\\        ||\n");
    outputcursorposition(81, 17);
    printf("    ||   \\\\       ||\n");
    outputcursorposition(81, 18);
    printf("    ||    \\\\      ||\n");
    outputcursorposition(81, 19);
    printf("    ||     \\\\     ||\n");
    outputcursorposition(81, 20);
    printf("    ||      \\\\    ||\n");
    outputcursorposition(81, 21);
    printf("    ||       \\\\   ||\n");
    outputcursorposition(81, 22);
    printf("    ||        \\\\  ||\n");
    outputcursorposition(81, 23);
    printf("    ||         \\\\ ||\n");

    outputcursorposition(101, 15);
    Sleep(150);
    printf("    ||     //\n");
    outputcursorposition(101, 16);
    printf("    ||    //\n");
    outputcursorposition(101, 17);
    printf("    ||   //\n");
    outputcursorposition(101, 18);
    printf("    ||  //\n");
    outputcursorposition(101, 19);
    printf("    || //\n");
    outputcursorposition(101, 20);
    printf("    || \\\\\n");
    outputcursorposition(101, 21);
    printf("    ||  \\\\\n");
    outputcursorposition(101, 22);
    printf("    ||   \\\\\n");
    outputcursorposition(101, 23);
    printf("    ||    \\\\\n");

    outputcursorposition(120, 15);
    Sleep(150);
    printf("    ||             ||\n");
    outputcursorposition(120, 16);
    printf("    ||             ||\n");
    outputcursorposition(120, 17);
    printf("    ||             ||\n");
    outputcursorposition(120, 18);
    printf("    ||             ||\n");
    outputcursorposition(120, 19);
    printf("    ||             ||\n");
    outputcursorposition(120, 20);
    printf("    ||             ||\n");
    outputcursorposition(120, 21);
    printf("    ||             ||\n");
    outputcursorposition(120, 22);
    printf("    ||             ||\n");
    outputcursorposition(120, 23);
    printf("      =============\n");

    outputcursorposition(120, 42);
    getch();
    system("cls");
}

