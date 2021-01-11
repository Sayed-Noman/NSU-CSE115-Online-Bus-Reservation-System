/*
                            Online Bus Management System
                Created BY : Sayed Abu Noman Siddik(1811655642)
                                  Anik Hasan(1331042043)

*/

/*This section is used for Header file*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* this section is used for user defined function declaration */
void registe(); // to get register information
void login();// to get login information
void mainmenu(); // to show main menu
void view_bus_list();//for list of bus
void name_number(int booking,char numstr[100]);//for processing seat names
void book_tickets();//for booking the tickets
int read_number(int Bus_no);//for reading the number from the file
void read_name(int Bus_no);//for reading the name from the file
void bus_status_board(); //for printing the status by user input
void status_1(int Bus_no);//for printing the status while booking ticket
void cancel_booking();//for canceling ticket booking
void view_safety_advices();// for passenger safety issues
void view_bus_ldteail_ist(); //to show detail list for buses


/*This section is for Global variables */
char Bus_name[10][130]={"Green Line Express","Shyamoli Paribahan","Hanif Enterprise","Soudia Paribahan","Ena Paribahan","Asia Exclusive"};
char name[32][100]={'\0'};//for seat name
char number[32][2]={'\0'};//for seat number
int num1[32]={0};
int Bus_no; //for bus number

/* Global pointers for file accessing*/
FILE *p0,*p1,*p2,*p3,*p4;


/*Structure used for a set getting information from user */
struct login{

    char firstname[100];
    char lastname[20];
    char username[20];
    char password[20];
    char emailname[100];
    char address[100];

};

/*This is main function Program statrt Execution from Here */
int main()
{

    int choice; //to get choice for login or registration
    int choice_num; //to get choice for menu

    label: system("CLS");
    printf("Press '1' for  Register \nPress '2' for Login\n");
    printf("Enter your Choice:");
    //scanf("%d",&choice);
    switch(getch())
    {
        case '1':
               system("CLS");
                registe();
                break;
        case '2':
                 system("CLS");
                 login();
                 break;
        default:
        {
                printf("\aWrong Entry!!Please re-entered correct option");
                getch();
                goto label;

        }

    getch();

    }


    do
    {
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO ONLINE RESERVATION SYSTEM: MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 1. View Bus List   ");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 2. View Bus Details List   ");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 3. Book Tickets");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 4. Cancel Booking");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 5. Bus Status Board");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 6. Travel Safety Advices");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 7. Close Application");
    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    printf("\t\t\tEnter your choice:");
   // scanf("%d",&choice_num);

    switch(getch())
    {
       case '1':
                 view_bus_list();
                 break;
        case '2':
                 view_bus_ldteail_ist();
                 break;
       case '3':
                 book_tickets();
                 break;
       case '4':
                cancel_booking();
                break;
       case '5':
               bus_status_board();
               break;
       case '6':
                view_safety_advices();
                break;
       case '7':
        {
              system("CLS");
              printf("\n\n\n");
              printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BUSRESEVATION SYSTEM: EXIT MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
              printf("\n\n");
              printf("\n\n");
              printf("\t\t\t\t  30th July 2018,two students were killed by a speedy Bus\n\t\t\t\tDhaka was Shaken by Youth Spirit in the demand of Safe Road\n\t\t   This Project is Dedicated to those Brave Souls Who took Part in that Student Protest");
              printf("\n\n");
              printf(" \t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Have a nice Day \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
              printf("\n\n");
              printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Press 'Enter' to Exit");

              exit(0);
       }
       default:
      {
            printf("\aWrong Entry!!Please re-entered correct option");

      }


    }
    getch();


    }while(getch()!=7);



}

/* Registe() function is used for Passenger Details registration*/
void registe()
{
    printf("\n\n\n");
    printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 REGISTRATION MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");

    struct login l; // called structure for getting set of information

    FILE*log;
    log=fopen("login.dat","wb");

    printf("--->Enter First Name : "); fflush(stdin); scanf("%s",&l.firstname);
    printf("\n");
    printf("--->Enter Last Name : "); fflush(stdin); scanf("%s",&l.lastname);
    printf("\n");


    printf("--->Enter Your Email Here : "); fflush(stdin); gets(l.emailname);
    printf("\n");
    printf("--->Enter Your Address : "); fflush(stdin); gets(l.address);
    printf("\n");

    printf("--->Enter Username : "); fflush(stdin); scanf("%s",&l.username);
    printf("\n");
    printf("--->Enter Password : "); fflush(stdin); scanf("%s",&l.password);

    fwrite(&l,sizeof(l),1,log); // writing file
    fclose(log);

    printf("\n\n\t\t\t        Your user name is Your UserId\n");
    printf("\t\t\t     Now login with UserID and password\n");
    printf("\n\nPress any key to continue.......");
    getch();
    system("CLS");
    login(); // calling login fuction
}

/* Login() function  is used for manager login after completing registe() function*/
void login()
{
     char username[200];
     char password[20];
     struct login l;

     printf("\n\n\n");
     printf("\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOGIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
     printf("\n\n");

    FILE*log;
    log=fopen("login.dat","rb");

    printf("--->UserId : ");
    fflush(stdin);
    scanf("%s",&username);
    printf("--->Password : ");
    fflush(stdin);
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(log==NULL)
        {
            printf("Login file not found");
        }

        else if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            printf("\n\n\n\t\t\t\tSuccessfully Login Completed");
            getch();
        }
        else
        {
            printf("\n\n\t\tPlease Enter correct UserID and password\n");
            getch();
            system("CLS");
            login(); //calling login function
        }
    }

    fclose(log);
}
/* void view_bus_list() function Used to show bus list to the passanger */
void view_bus_list()
{
    char input[1000]; // for reading string inputs from file
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BUS MANAGEMENT SYSTEM: BUS LIST MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 1.  %s",Bus_name[0]);
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 2.  %s",Bus_name[1]);
    printf("\n\n");
	printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 3.  %s",Bus_name[2]);
    printf("\n\n");
	printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 4.  %s",Bus_name[3]);
    printf("\n\n");
	printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 5.  %s",Bus_name[4]);
	printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");


}
/*void book_tickets() function is used for booking tickets from user */
void book_tickets()
{

    int i=0; // to control loop
    char numstr[100]; // for seat name

    system("CLS");
    view_bus_list(); //for seeing bus list
    printf("\t\t\tEnter The Bus number : ");
    scanf("%d",&Bus_no);

    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BUS MANAGEMENT SYSTEM: TICKET BOOKING MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");//for selecting coach
    //printf("Your Bus Number is %d ********** %s",Bus_no,Bus_name[Bus_no-1]);

    status_1(Bus_no); //calling this function to show current seat status while printing

    FILE *f1, *fopen();//for reading the seats from the user.

    char str1[80]="32",str2[4],str3[4];
    int seat1,seat2,booking=0;//booking is for how many seats passenger want to book

    if(Bus_no == 1)
    {
       f1 = fopen("Green_Line_Express.txt","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(Bus_no == 2)
    {
      f1 = fopen("Shyamoli_Paribahan.txt","r+");
      fgets(str1,80,f1);
      fclose(f1);
    }
    else if(Bus_no == 3)
    {
       f1 = fopen("Hanif_Enterprise.txt","r+");
       fgets(str1,80,f1);
       fclose(f1);
    }
    else if(Bus_no == 4)
    {
      f1 = fopen("Soudia_Paribahan.txt","r+");
      fgets(str1,80,f1);
      fclose(f1);
    }
    else if(Bus_no == 5)
    {
      f1 = fopen("Ena_Paribahan.txt","r+");
      fgets(str1,80,f1);
      fclose(f1);
    }
    seat1=atoi(str1);//covert the string into number
    if(seat1 <= 0)
    {
       printf("There is no blank seat in this bus ");
    }
   else
   {
      printf("\n\n\nAvailable Seats: %d\n",seat1);
      printf("\nNumber of Tickets you want to Book :");
      scanf("%d",&booking);
      printf("\n");

      seat1=seat1-booking;

      itoa(Bus_no,numstr,10); //converting integer into ascii
      name_number(booking,numstr);//function calling
      printf("\n\t======================================================================================================");
      printf("\n\n                                    The Total booking amount is %d  Taka Only",350*booking);
      printf("\n\t======================================================================================================\n");

      itoa(seat1, str1, 10);//for reading the seats from the user.
      if(Bus_no == 1)
     {
         f1 = fopen("Green_Line_Express.txt","w");
         fputs(str1,f1);
         fclose(f1);
     }
     else if(Bus_no == 2)
     {
         f1 = fopen("Shyamoli_Paribahan.txt","w");
         fputs(str1,f1);
         fclose(f1);
     }
     else if(Bus_no == 3)
     {
        f1 = fopen("Hanif_Enterprise.txt","w");
        fputs(str1,f1);
        fclose(f1);
     }
    else if(Bus_no == 4)
    {
        f1 = fopen("Soudia_Paribahan.txt","w");
        fputs(str1,f1);
        fclose(f1);
    }
    else if(Bus_no == 5)
    {
         f1 = fopen("Ena_Paribahan.txt","w");
         fputs(str1,f1);
         fclose(f1);
    }

  }

}

/* void name_number() function is used for reading  seatNumber from user */
void name_number(int booking,char numstr[100])
{
    char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
    int number;
    FILE *a,*b;
    int i=0;
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    strcat(tempstr2,numstr);
    a = fopen(tempstr1,"a");//for open the file to write the name in the file
    b = fopen(tempstr2,"a");//for open the file for writing the number in the file
    for(i=0; i<booking; i++)//for entering the person name and seat number in the file
   {

      printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter the details for ticket no : %d \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n",i+1);
      printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 Enter the seat number : ");
      scanf("%d",&number);
      printf("\n\n\n");
      printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 Enter the name of person : ");
      scanf("%s",name[number-1]);
      printf("\n======================================================================================================\n\n");
      printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

   }

     fclose(a);
     fclose(b);
}


/* for putting the numeric value in the array */
int read_number(int Bus_no)
{
     char tempstr[100],tempstr2[12]="number"; //some temporary variables
     FILE *a,*b;
     char numstr[100]; //for seat name in string
     int i=0,j=0,k;

     itoa(Bus_no,numstr,10);
     strcat(numstr,".txt");
     strcat(tempstr2,numstr);

     a = fopen(tempstr2,"a+");//for open the file to write the name in the file
     while(!feof(a))
     {
        number[i][j] = fgetc(a);

        if(number[i][j] == ' ')
        {
           j=0;
           i++;
        }
       else
       {
          j++;
       }

    }
    k=i;
     for(i=0; i<k; i++)
     {
       num1[i] = atoi(number[i]);
     }

     fclose(a);
     return k;
}

/*void read_name(int Bus_no) function is used for putting the numeric value in the array*/
void read_name(int Bus_no)
{
     char tempstr1[12]="status";
     FILE *b;
     char numstr[100];
     int i=0,j=0,k=0;
     itoa(Bus_no,numstr,10);
     strcat(numstr,".txt");
     strcat(tempstr1,numstr);
     b = fopen(tempstr1,"a+");//for open the file to write the name in the file
     while(!feof(b))
     {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
         j++;
      }

    }
    name[i][j]='\0';
    k=i;
    fclose(b);
}

/*void bus_status_board() function is used to show current bust status to it's passenger */
void bus_status_board()
{
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ONLINE BUS RESERVATION SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");

    int i,Bus_no,index=0,j;  // loop control variables

    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 Enter Bus Number :");
    scanf("%d",&Bus_no);

    j=read_number(Bus_no);
    read_name(Bus_no); //function calling for reading name

    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n",Bus_no,Bus_name[Bus_no-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]); // to copy temporary name
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

/* void status_1(int Bus_no) function is used for showing bus status to it's passenger while booking*/
void status_1(int Bus_no)
{
    //printf("Your Bus Number is %d ********** %s",Bus_no,Bus_name[Bus_no-1]);
     system("CLS");
     printf("\n\n\n");
     printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BUS RESERVATION SYSTEM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
     printf("\n\n");
     printf("Your Bus Number is %d  %s \n",Bus_no,Bus_name[Bus_no-1]);
     printf("====================================================\n\n\n");

     int i,index=0,j; // lop control variables
     j=read_number(Bus_no);
     read_name(Bus_no);
     char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
     for(i=0; i<j; i++)
     {
        strcpy(tempname[num1[i]],name[i]);
     }
     for(i=0; i<8; i++)
     {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
        {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
        }
            printf("\n");
    }

}

/*void cancel_booking() booked tickets*/
void cancel_booking()
{
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BUS RESERVATION SYSTEM : CANCEL BOOKING MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");

    view_bus_list(); //here i called bus list to  show bus list to the use

    int seat_no,i,j; // seat no and loop control variables

    char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
    printf("\n\nt\t\t\xDB\xDB\xDB\xDB\xB2 Enter the bus number :");
    scanf("%d",&Bus_no);

    itoa(Bus_no,numstr,10);
    strcat(numstr,".txt");

    strcat(tempstr1,numstr);
    strcat(tempstr2,numstr);

    read_number(Bus_no); //function calling for reading seat number
    read_name(Bus_no); //function calling for reading seat name
    status_1(Bus_no); //function calling for showing bus current status

    printf("\n\n\t\t\t\xDB\xDB\xDB\xDB\xB2 Enter the seat number you want to cancel : ");
    scanf("%d",&seat_no);

    FILE *a,*b;
    a = fopen(tempstr1,"w+");
    b = fopen(tempstr2,"w+");
    for(i=0; i<32; i++)
   {
       if(num1[i] == seat_no)
       {
           for(j=0; j<32; j++)
           {
               if(num1[j] != seat_no && num1[j] != 0)
               {
                  fprintf(b,"%d ",num1[j]);
                  fprintf(a,"%s",name[j]);
              }
              else if(num1[j] == seat_no && num1[j] != 0)
              {
                 strcpy(name[j],"Empty ");
              }
         }
     }
   }
   fclose(a);
   fclose(b);

    printf("\n\n");
    printf("======================================================================================================\n");
    printf("\t\t\t\tYour 350 Taka has been Returned\t\t\t\n\n");
    printf("======================================================================================================\n");

}

/* void view_safety_advices() is used to prrint safety advices */
void view_safety_advices()
{
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Travel Safety Advices \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    FILE *ptofile =fopen("travel_advices.txt","r");
    char input[1000]; // to read string inputs from file
    while(fgets(input,1000,ptofile))
    {
        printf("\n%s",input);
    }


    fclose(ptofile);
}
/*void view_bus_ldteail_ist() function is to bus rote and contac details */
void view_bus_ldteail_ist()
{
    char input[1000];
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO RESERVATION SYSTEM: BUS LIST MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 1.  %s",Bus_name[0]);
    printf("\n\n");
    printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 2.  %s",Bus_name[1]);
    printf("\n\n");
	printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 3.  %s",Bus_name[2]);
    printf("\n\n");
	printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 4.  %s",Bus_name[3]);
    printf("\n\n");
	printf("\t\t\t\xDB\xDB\xDB\xDB\xB2 5.  %s",Bus_name[4]);
	printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");

    printf("\n\n");
    printf("Enter Your Choice: ");
    switch(getch())
    {
    case '1':
             system("CLS");
             printf("\n\n\n");
             printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME BUs TO RESERVATION SYSTEM: BUS DETAIL LIST MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
             printf("\n\n");
            FILE *p0 =fopen("greenline_details.txt","r");

            while(fgets(input,1000,p0))
           {
           printf("\n%s",input);
          }

          fclose(p0);
            break;

    case '2':
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BUS  RESERVATION SYSTEM: BUS DETAIL LIST MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    FILE *P1 =fopen("Shyamoli_Paribahan_Detail.txt","r");
    while(fgets(input,1000,p1))
    {
        printf("\n%s",input);
    }


    fclose(p1);




    case '3':
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BUS RESERVATION SYSTEM: BUS DETAIL LIST MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    FILE *p2 =fopen("Hanif_details.txt","r");
    while(fgets(input,1000,p2))
    {
        printf("\n%s",input);
    }

    fclose(p2);
    break;

    case '4' :
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO  BUS RESERVATION SYSTEM: BUS DETAIL LIST MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    FILE *P3 =fopen("Saudia_details.txt","r");
    while(fgets(input,1000,p3))
    {
        printf("\n%s",input);
    }


    fclose(p3);
    break;

    case '5':
    system("CLS");
    printf("\n\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO BUS RESERVATION SYSTEM: BUS DETAIL LIST MENU\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n");
    FILE *p4 =fopen("ena_details.txt","r");
    while(fgets(input,1000,p4))
    {
        printf("\n%s",input);
    }


    fclose(p4);
    break;
}




}







