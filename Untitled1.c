//Project Name:BANKING MANAGEMENT SYSTEM
//Developers:
//CHETAN MALVIYA
//OJASWI GUPTA
//SIMRAN VERMA
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void login();
void menu();
void open();
void update();
void view();
void search();
void deletion();
void transaction();

struct bank{
              unsigned long int acc_no;
              char name[25];
              char add[50];
              char father[25];
              char dob[10],cont;
              signed long int balance;
}cr,upd,check;

void main()
{
    printf("\t\t\t\t**********WELCOME TO CODE AVENGERS BANK*********\n");
    printf("IFSC Code:- CODA18222810\n");
    login();
}
void login()
{
      char user[7],pass[11],user1[7]="soc",pass1[11]="soc123";
      int i;
      i=1;
      l1:
      printf("Enter username:  ");
      scanf(" %s",user);
      printf("\nEnter password: ");
      scanf(" %s",pass);
             if(strcmp(pass,pass1)==0&&strcmp(user,user1)==0)
            {
                  printf("\t\tLogin Successfully!!");
                  getch();
                  system("cls");
                  menu();
            }
           else
          {
            i++;
            printf("\n Username or Password is  wrong\n");
            getch();
            system("cls");
                if(i<=3)
                {
                  goto l1;
                }
            exit(0);
          }
}

void menu()
{
           int ch;
           choices:
            system("cls");

            printf("\n1: Create a new account");

            printf("\n2: Update existing account");

            printf("\n3: View all Accounts Details");

            printf("\n4: Search an Account");

            printf("\n5: Delete an Account ");

            printf("\n6: Transaction ");

            printf("\n7: Exit \n\n");

        printf("\nEnter your choice:");
        scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            open();
        break;
        case 2:
            update();
        break;

        case 3:
            view();
        break;

        case 4:
            search();
        break;

        case 5:
            deletion();
        break;

        case 6:
            transaction();
        break;

        case 7:
            exit(0);

        default:
            printf("\nInvalid choice\nEnter valid choice again\n");
            getch();
            goto choices;
    }
    printf("\nDo you want to continue (Y-for YES:N-for NO)\n");
        scanf(" %c",&cr.cont);
        if(cr.cont=='Y'||cr.cont=='y')
        {
            goto choices;
        }
        else
        {
            printf("\n \t\t***************THANKYOU*****************");
        }
}
void open()
{
   FILE *fp;
   fp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\bank managemenet system.txt ","a+");
   int i=1;
    op:
    system("cls");
    printf("Please enter minimum amount of 10,000Rs to open your account!!\n\n");
    scanf("%ld",&check.balance);
     if(check.balance<10000)
    {
        i++;
        if(i>3)
        {
            printf("\tSorry you can't open your account with this much less amount!!\n");
            return 0;
        }
        printf("Re-enter amount");
        goto op;
    }


    printf("\n \t\tACCOUNT NO.:- ");
    scanf(" %lu",&cr.acc_no);



    printf("\n \t\tFULL NAME:- ");
    scanf(" %[^\n]s",cr.name);

    printf("\n \t\tFATHER'S NAME:- ");
    scanf(" %[^\n]s",&cr.father);

    printf("\n \t\tDOB(dd/mm/yyyy):- ");
    scanf(" %s",&cr.dob);


    printf("\n \t\tADDRESS:- ");
    scanf(" %[^\n]s",&cr.add);


    printf("\n\tEnter confirmed amount again!\n");
    scanf("%ld",&cr.balance);
    if(cr.balance!=check.balance)
    goto op;
    fprintf(fp,"%lu\t\n",cr.acc_no);
    fprintf(fp," %s\t\n",cr.name);
    fprintf(fp,"%s\t\n",cr.father);
    fprintf(fp,"%s\t\n",cr.dob);
    fprintf(fp," %s\t\n",cr.add);
    fprintf(fp," %ld\t\n",cr.balance);

    printf("\t\t*****Account Created Successfully*****\n");
    fclose(fp);
}
void update()
{
    FILE*fp,*ftemp;
    int ch1;

    system("cls");
    fp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\bank managemenet system.txt ","r+");
    ftemp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\new file.txt ","w+");

    printf("Enter account number:-  ");
    scanf(" %lu",&upd.acc_no);

    while (fscanf(fp,"%lu %[^\n]%*c %[^\n]%*c %s %[^\n]%*c %ld",&cr.acc_no,cr.name,cr.father,cr.dob,cr.add,&cr.balance)!= EOF)
 {
    if(upd.acc_no==cr.acc_no)
   {
        {//DETAILS
        printf("Account number : %lu\n",cr.acc_no);
        printf("Name           : %s\n",cr.name);
        printf("Father Name    : %s\n",cr.father);
        printf("Date of Birth  : %s\n",cr.dob);
        printf("Address        : %s\n",cr.add);
        }
       {
       choice:
       printf("\nWhat do you want to update:-\n 1: Name \n 2: Father name  \n 3: Date of birth \n 4: Address");
       printf("\nEnter any choice..........  ");
       scanf("%d",&ch1);
       system("cls");
        if(ch1==1)
        {
         printf("Enter new name  ");
         scanf(" %[^\n]s",upd.name);
         fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,upd.name,cr.father,cr.dob,cr.add,cr.balance);
         printf("::::::::::update successfully:::::::::::");
        }
        if(ch1==2)
        {
         printf ("Enter updated father name ");
         scanf(" %[^\n]s",upd.father);
         fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,upd.father,cr.dob,cr.add,cr.balance);
         printf("::::::::::update successfully:::::::::::");
        }
        if(ch1==3)
        {
         printf("Enter new Date of birth");
         scanf(" %[^\n]s",upd.dob);
         fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,upd.dob,cr.add,cr.balance);
         printf("::::::::::update successfully:::::::::::");
        }
        if(ch1==4)
        {
         printf("Enter new address");
         scanf(" %[^\n]s",upd.add);
         fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,cr.dob,upd.add,cr.balance);
         printf("::::::::::update successfully:::::::::::");
        }

    }
  }
    else
        fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,cr.dob,cr.add,cr.balance);
}
    fclose(ftemp);
    fclose(fp);
    remove("bank managemenet system.txt");
    rename("new file.txt","bank managemenet system.txt");


}
void view()
{
    FILE *fp;
    system("cls");
    fp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\bank managemenet system.txt ","r+");

    printf("\n\n\t\t**********************************ALL ACCOUNT DETAILS*********************************\t\t\t\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");

    while (fscanf(fp,"%lu %[^\n]%*c %[^\n]%*c %s %[^\n]%*c %ld",&cr.acc_no,&cr.name,&cr.father,&cr.dob,&cr.add,&cr.balance) != EOF)
    {
        printf("Account number :  %lu\t",cr.acc_no);
        printf("Name           :  %s\t",cr.name);
        printf("Father Name    :  %s\t",cr.father);
        printf("Date of Birth  :  %s\t",cr.dob);
        printf("Address        :  %s\t",cr.add);
        printf("balance        :  %ld\n\n\n",cr.balance);
        printf("-------------------------------------------------------------------------------------------------------------------\n\n");

    }
    fclose(fp);

}

void search()
{
    FILE*fp;
    struct bank c;
    system("cls");
    printf("Enter Account Number ");
    scanf(" %lu",&check.acc_no);
    fp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\bank managemenet system.txt ","r+");
   while (fscanf(fp,"%lu %[^\n]%*c %[^\n]%*c %s %[^\n]%*c %ld",&cr.acc_no,cr.name,cr.father,cr.dob,cr.add,&cr.balance) != EOF)
    {

                if(check.acc_no==cr.acc_no)
       {
        printf("Account number : %lu\n",cr.acc_no);
        printf("Name           : %s\n",cr.name);
        printf("Father Name    : %s\n",cr.father);
        printf("Date of Birth  : %s\n",cr.dob);
        printf("Address        : %s\n",cr.add);
        printf("balance        : %ld\n",cr.balance);
        getch();
        menu();
       }
    }
    printf("Account not found");
}
void deletion()
{
    FILE*fp,*ftemp;

    system("cls");
    fp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\bank managemenet system.txt ","r+");
    ftemp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\new file.txt ","w+");

    printf("Enter account number ");
    scanf("%lu",&check.acc_no);

    while (fscanf(fp,"%lu %[^\n]%*c %[^\n]%*c %s %[^\n]%*c %ld",&cr.acc_no,cr.name,cr.father,cr.dob,cr.add,&cr.balance)!= EOF)


    if(check.acc_no==cr.acc_no)
    {

         remove(fp);
         printf("::::::::::remove successfully:::::::::::\n");

    }
    else
       fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,cr.dob,cr.add,cr.balance);
    fclose(ftemp);
    fclose(fp);
    remove("bank managemenet system.txt");
    rename("new file.txt","bank managemenet system.txt");

}
void transaction()
{
     FILE*fp,*ftemp;
     signed long int deposit, withdraw;
    int ch2;

    system("cls");
    printf("Enter account number ");
    scanf("%lu",&check.acc_no);

    fp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\bank managemenet system.txt ","r+");
    ftemp=fopen("C:\\Users\\998go\\OneDrive\\Desktop\\project\\new file.txt ","w+");

    while (fscanf(fp,"%lu %[^\n]%*c %[^\n]%*c %s %[^\n]%*c %ld",&cr.acc_no,cr.name,cr.father,cr.dob,cr.add,&cr.balance)!= EOF)
    if(check.acc_no==cr.acc_no)
   {
        {
        printf("Account number : %lu\n",cr.acc_no);
        printf("Name           : %s\n",cr.name);
        printf("Father Name    : %s\n",cr.father);
        printf("Date of Birth  : %s\n",cr.dob);
        printf("Address        : %s\n",cr.add);
        printf("balance        : %ld\n",cr.balance);
       }
       printf(" \n1: withdraw \n2: deposit ");
       scanf("%d",&ch2);
   switch(ch2)
   {
    case 1:
          printf("Enter the amount you want to withdraw ");
         scanf("%ld",&withdraw);
          if(cr.balance>=withdraw)
          {
            cr.balance=cr.balance-withdraw;
            fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,cr.dob,cr.add,cr.balance);

            printf("::::::::::withdraw successfully:::::::::::\n");
            printf("Current balance:%ld\n",cr.balance);
          }
        else
            printf("Insufficient amount\n");
             fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,cr.dob,cr.add,cr.balance);

            getch();
            break;
     case 2:
          printf("Enter the amount you want to deposit ");
          scanf("%ld",&deposit);
          cr.balance=cr.balance+deposit;
          fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,cr.dob,cr.add,cr.balance);

            printf("::::::::::deposit successfully:::::::::::\n\n");
            printf("\t\tCurrent balance:%ld\n\n",cr.balance);
    }
  }

    else
    fprintf(ftemp,"%lu\n %s\n %s\n %s\n %s\n %ld\n",cr.acc_no,cr.name,cr.father,cr.dob,cr.add,cr.balance);

    fclose(ftemp);
    fclose(fp);
    remove("bank managemenet system.txt");
    rename("new file.txt","bank managemenet system.txt");
}


