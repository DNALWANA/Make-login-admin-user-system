#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void adminlog();
void adminmenu();
void user();
void makeacc();
void loginuser();
void usermenu();

FILE *newacc,*f;


void divider(){

    printf("==========================================\n");
}

void slowprint(const char *str, int delay){

    while (*str)
    {
        printf("%c",*str);
        fflush(stdout);
        usleep(delay);
        str++;
    }
    printf("\n");
}


struct account
{
    char nam[50],pss[50],no[30],tanggal[50],addres[50];
}acc;




int main(){
    system("cls");
    int cois;
    

    divider();
    slowprint("WELCOME TO THE [project Name]",1000);
    divider();

    printf("1. Administration section\n");
    printf("2. Costumer section\n");
    printf("3. About us\n");
    printf("4. Exit\n");
    printf("Choose: ");
    scanf("%d",&cois);getchar();
    switch (cois)
    {
    case 1:
        adminlog();
        break;
    case 2:
        user();
        break;
    case 3:
        // blom adaa
        break;
    case 4:
        main();
        break;
    
    default:
    printf("Choose did not exist\n");
    getchar();
    main();
        break;
    }
    
    return 0;
}

void adminlog(){
    
    int attempt = 0;
    char usmin[20];
    char pass[30];

    while (attempt < 3)
    {
        system("cls");
        divider();
        slowprint("WELCOME TO THE ADMIN MENU",1000);
        divider();

        printf("Please enter your Name and Password \n");
        printf("Username: ");
        fgets(usmin,sizeof(usmin),stdin);
        usmin[strcspn(usmin,"\n")] = '\0';

        printf("Password: ");
        fgets(pass,sizeof(pass),stdin);
        pass[strcspn(pass,"\n")] = '\0';

        if (strcmp(usmin, "minmin")==0 && strcmp(pass,"adminganteng")==0)
        {
            printf("Login succes\n");
            usleep(100);
            printf("Welcome Admin!");
            getchar();
            adminmenu();
            return;
        }else
        {
            attempt++;
            printf("Login failed. You have %d more attempt t0 try\n", 3 - attempt);
            system("pause");
        }
    }
    
    printf("\n");
    printf("Login Failed limit in login attempt, try again next time\n");
    system("pause");
    main();
}

void adminmenu(){

    system("cls");
    printf("Hai gantenk\n");


}

//USERRRRRRRRR


void user(){

    int ccois;

    system("cls");
    divider();
    slowprint("WELCOME TO THE USER MENU",1000);
    divider();

    printf("1. Add New Account\n");
    printf("2. Login Account\n");
    printf("3. Delete Account\n");
    printf("4. Back to menu\n");
    printf("Enter your choice: ");
    scanf("%d", &ccois);getchar();
    switch (ccois)
    {
    case 1:
        makeacc();
        break;

    case 2:
        loginuser();
        break;
    
    default:
        break;
    }

}

void makeacc(){

    system("cls");
    int cccois;

    divider();
    printf("Lets make your account\n");
    divider();

    struct account acc;
    newacc = fopen("accdata.dat","ab");

    printf("Username: ");
    fgets(acc.nam,sizeof(acc.nam),stdin);
    acc.nam[strcspn(acc.nam,"\n")] = '\0';

    printf("Password: ");
    fgets(acc.pss,sizeof(acc.pss),stdin);
    acc.pss[strcspn(acc.pss,"\n")] = '\0';

    printf("Phone Number: ");
    fgets(acc.no,sizeof(acc.no),stdin);
    acc.no[strcspn(acc.no,"\n")] = '\0';

    printf("Birth of Date: ");
    fgets(acc.tanggal,sizeof(acc.tanggal),stdin);
    acc.tanggal[strcspn(acc.tanggal,"\n")] = '\0';

    printf("Your Adress: ");
    fgets(acc.addres,sizeof(acc.addres),stdin);
    acc.addres[strcspn(acc.addres,"\n")] = '\0';

    printf("\n");
    printf("Your Account Detail\n");
    printf("Username: %s\n",acc.nam);
    printf("Password: %s\n",acc.pss);
    printf("Phone Number: %s\n",acc.no);
    printf("Birth of Date: %s\n",acc.tanggal);
    printf("Your Adress: %s\n",acc.addres);

    printf("Is it right? (1:Yes/ 2:No)\n");
    printf("Choose: ");
    scanf("%d",&cccois);getchar();
    switch (cccois)
    {
    case 1:
        printf("The Record Is Successfully Saved ! !\n");
        fwrite(&acc,sizeof(struct account),1,newacc);
        fclose(newacc);
        system("pause");
        user();
        break;
    case 2:
        printf("Failed to save data\n");
        fclose(newacc);
        break;
    
    default:
        break;
    }


}

void loginuser(){

    
    int attempt = 0;

    struct account acc;

    char namm[50];
    char psi[50];

    while (attempt < 3) 
    {
        system("cls");
        divider();
        printf("User Login Page\n");
        divider();

        printf("ENTER YOUR NAME AND PASSWORD\n");
        printf("Username: ");
        fgets(namm,sizeof(namm),stdin);
        namm[strcspn(namm,"\n")] = '\0';

        printf("Password: ");
        fgets(psi,sizeof(psi),stdin);
        psi[strcspn(psi,"\n")] = '\0';

        f = fopen("accdata.dat","rb");

        while (fread(&acc,sizeof(struct account),1,f))
        {
            if (strcmp(namm,acc.nam)==00 && strcmp(psi,acc.pss)==0)
            {
                printf("Login Succesful Welcome %s\n", namm);
                fclose(f);
                system("pause");
                usermenu();
                return;
            }else
            {
                attempt++;
                printf("Login failed. You have %d more attempt to try\n", 3 - attempt);
                fclose(f);
                system("pause");
            }
        }
    }

    printf("\n");
    fclose(f);
    printf("Login Failed limit in login attempt, try again next time\n");
    system("pause");
    user();
    
}


void usermenu(){
    system("cls");
    printf("Hai gantenk\n");
}