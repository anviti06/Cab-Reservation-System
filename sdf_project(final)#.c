#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cab{

    int cabNo;
    long int mobileNo;

    float rating;

    char name[100];
    char location[100];
    char cabType;

    struct cab *next;

};


///Just to store all the kind of input from the user at one  place.
struct passenger{

    char name[100];
    char pickupLocation[100];
    char dropLocation[100];
    char cabType;

    long int mobileNo;
    int couponNo;

}grahak;


struct cab *head = NULL ;
struct cab *temp;
struct cab *pos;
struct cab *pre;
struct cab *last;



///Creating list (Insertion at the end)
void insert(int cabNo , float rating , long int mobileNo , char *name , char *location , char cabType){

        struct cab * newNode = (struct cab *)malloc(sizeof(struct cab));
        newNode->cabNo = cabNo;
        newNode->rating = rating;
        newNode->mobileNo = mobileNo;

        strcpy( newNode->name , name);
        strcpy( newNode->location , location );
        newNode->cabType = cabType;
        newNode->next = NULL;


        if ( head == NULL ){
           head = newNode ;
        }
        else{

            temp = head ;

            while( temp->next != NULL ){
                temp = temp->next ;
            }

            temp->next = newNode;
            last=newNode;
        }

        return;
}


///Performing insertion at the start
void insert_newcab(){

    struct cab * newNode = (struct cab *)malloc(sizeof(struct cab));

    printf("Please enter the driver's details :-\n\n");

    printf("Driver's Name : ");
    fflush(stdin);
    scanf("%[^\n]s",&newNode->name);

    printf("Mobile No. :");
    fflush(stdin);
    scanf("%ld",&newNode->mobileNo);

    printf("Cab No. :");
    fflush(stdin);
    scanf("%d",&newNode->cabNo);

    printf("Current Location :");
    fflush(stdin);
    scanf("%[^/n]s",&newNode->location);

    printf("Cab Type :");
    fflush(stdin);
    scanf("%c",&newNode->cabType);


    printf("Rating :");
    fflush(stdin);
    scanf("%f",&newNode->rating);


    newNode->next=head;
    head=newNode;

    return ;

}


///Printing the whole driver List
void display(){

    if(head==NULL)
    {
        printf("Empty list");
        return;
    }


    temp=head;

    printf("The list is as follows-");

    while(temp != NULL)
    {
        printf("\n\n");
        printf("The driver's name is : %s\n",temp->name);
        printf("The driver's phone number is : %ld\n",temp->mobileNo);
        printf("The cabno is : %d\n",temp->cabNo);
        printf("The cabtype is : %c\n",temp->cabType);
        printf("The current location is : %s\n",temp->location);
        printf("The driver's rating is : %f\n",temp->rating);

        temp=temp->next;
    }

    printf("\n\n\n\n\n");

    return ;
}


///Perform search on the basis of location and availability
struct cab* search(){


    temp=head;
    while(temp!=NULL){

        if(strcmp(grahak.pickupLocation,temp->location)==0 && grahak.cabType == temp->cabType){
            break;
        }

        else{
            temp=temp->next;
        }
    }

    if(temp==NULL){
        printf("Sorry! No Cab Found\n\n\n\n");
    }

    return(temp);

}


///Shifting the node of the chosen driver to the end of the list
void shift(struct cab* book){

    pre=head;
    pos=head;
    while(pos!=book)
    {
        pre=pos;
        pos=pos->next;
    }
    pre->next=pos->next;
    pos->next=NULL;
    last->next=pos;
    last=pos;

}


///setting the new location of the cab driver
void newlocation (struct cab* book){

    strcpy(book->location,grahak.dropLocation);

}


///Printing the cab details and asking the user for the final confirmation regarding the booking
int cabPrint(struct cab *ptr , int finalFare){

    printf("\n\n\nThe driver details are as follows:\nName: %s\nMobile Number: %ld\nCab Number: %d\nRating : %f",ptr->name,ptr->mobileNo,ptr->cabNo,ptr->rating);
    printf("\nCab Type: %c",ptr->cabType);
    printf("\n\nThe final amount to be paid to the driver at the end of the trip is: Rs %d\n",finalFare);

    int a;

    printf("\n\nDo You wish to confirm your booking ? Enter your choice as:\n1.Yes\n2.No");
    printf("\nEnter the value: ");
    scanf("%d",&a);
    printf("\n\n");

    return a;
}


///Final fare  of the trip that has to be paid
int FinalFare(int normalFare){

    int a;

    if(grahak.cabType == 'H'){
        a = normalFare + (5*normalFare)/100 ;
    }
    else if(grahak.cabType == 'S'){
        a = normalFare + (15*normalFare)/100;
    }
    else if(grahak.cabType == 'X'){
        a = normalFare + (30*normalFare)/100;
    }
    else if(grahak.cabType == 'L'){
        a = normalFare + (55*normalFare)/100;
    }

    return a;
}


///This is the base price of all type of taxis (just destination depended). With variation in type of taxi, their final fare will change with some fixed %age
int fare(){

    int a = -1;

    if (strcmp(grahak.pickupLocation , "noida") == 0){

        if(strcmp(grahak.dropLocation , "noida") == 0){
            a = 1520;
        }
        else if( strcmp(grahak.dropLocation , "gurgaon")==0){
            a = 5900;
        }
        else if(strcmp(grahak.dropLocation , "dwarka")==0){
            a = 9700;
        }
        else if(strcmp(grahak.dropLocation , "rohini")==0){
            a = 6540;
        }
        else if(strcmp(grahak.dropLocation , "vasant vihar") == 0){
            a = 3280;
        }
    }

    else if(strcmp(grahak.pickupLocation , "gurgaon") ==0 ){

        if(strcmp(grahak.dropLocation , "noida") == 0){
            a = 5900;
        }
        else if(strcmp(grahak.dropLocation , "gurgaon") == 0){
            a = 3800;
        }
        else if(strcmp(grahak.dropLocation , "dwarka") == 0){
            a = 7860;
        }
        else if(strcmp(grahak.dropLocation ,"rohini") == 0){
            a = 5420;
        }
        else if(strcmp(grahak.dropLocation ,"vasant vihar") == 0){
            a = 8200;
        }
    }

    else if (strcmp(grahak.pickupLocation , "dwarka") == 0){

        if(strcmp(grahak.dropLocation ,"dwarka") ==0 ){
            a = 7900;
        }
        else if(strcmp(grahak.dropLocation , "noida")== 0){
            a = 9700;
        }
        else if(strcmp(grahak.dropLocation , "rohini")== 0){
            a = 2880;
        }
        else if(strcmp(grahak.dropLocation ,"vasant vihar")== 0){
            a = 4690;
        }
        else if(strcmp(grahak.dropLocation , "gurgaon")== 0){
            a = 7860;
        }
    }

    else if (strcmp(grahak.pickupLocation , "vasant vihar")== 0){

        if(strcmp(grahak.dropLocation , "rohini")== 0){
           a = 6910;
        }
        else if(strcmp(grahak.dropLocation , "dwarka")== 0){
            a = 4690;
        }
        else if(strcmp(grahak.dropLocation , "vasant vihar")== 0){
            a = 3870;
        }
        else if(strcmp(grahak.dropLocation , "gurgaon")== 0){
            a = 8200;
        }
        else if(strcmp(grahak.dropLocation , "noida")== 0){
            a = 3280;
        }
    }

    else if (strcmp(grahak.pickupLocation , "rohini")== 0){

        if(strcmp(grahak.dropLocation ,"noida")== 0){
            a = 6540;
        }
        else if(strcmp(grahak.dropLocation , "gurgaon")== 0){
            a = 5420;
        }
        else if(strcmp(grahak.dropLocation , "dwarka")== 0){
            a = 2880;
        }
        else  if(strcmp(grahak.dropLocation , "vasant vihar")== 0){
            a = 6910;
        }
        else if(strcmp(grahak.dropLocation , "rohini")== 0){
            a = 1320;
        }
    }

    return a;
}


///Function which would return the discounted fare if user applies any coupon
int couponFare(int couponNo , int finalfare){

    int df = -1;
    int a = grahak.couponNo ;

    switch(a){

    case 101:
        df = finalfare - ((5*finalfare)/100);
        break;

    case 1010:
        df = finalfare - ((10*finalfare)/100);
        break;

    case 1111:
        df = finalfare - ((15*finalfare)/100);
        break;
    }

    return df;
}


int main(){

    ///making a list of 16 drivers
    insert(3448 , 4.1 , 989234533 , "Raju" , "noida" ,'S');
    insert(5183 , 2.6 , 984635272 , "Pappu", "gurgaon",'H');
    insert(7854 , 4.7 , 983843747 , "Ramu" , "dwarka" ,'X');
    insert(5647 , 3.9 , 987564535 , "Pandey" , "vasant vihar",'L');
    insert(6453 , 3.6 , 982327646 , "Misriya" , "rohini" , 'S');
    insert(8996 , 3.8 , 987612334 , "Khalnayak" , "rohini" , 'S');
    insert(5144 , 4.4 , 983473466 , "Rambo" , "vasant vihar",'H' );
    insert(9134 , 4.2 , 982340012 , "Gangadhar" , "gurgaon",'X');
    insert(7654 , 4.8 , 956743884 , "Shaktiman" , "noida",'H');
    insert(4231 , 4.3 , 934356732 , "Gormint","dwarka",'L');
    insert(6978 , 4.0 , 912546434 , "Chacha" , "vasant vihar" , 'X');
    insert(3456 , 2.3 , 934359665 , "Maalik" , "rohini" , 'H');
    insert(6775 , 3.2 , 923453468 , "Ratan Singh" ,"dwarka", 'H');
    insert(7644 , 3.4 , 923424568 , "Baman", "noida" , 'X');
    insert(3655 , 3.5 , 873456737 , "Baburao Apte" , "gurgaon",'S');
    insert(7854 , 3.6 , 734375347 , "Mohan" , "noida" , 'L');
    insert(7890 , 4.6 , 934375347 , "Shamoo" , "gurgaon" , 'L');
    insert(7832 , 2.6 , 904375347 , "Faiz" , "dwarka" , 'S');
    insert(5092 , 3.6 , 834905347 , "Pintu" , "vasant vihar" , 'S');

    FILE *rp,*fp;
    char c;

    while(1){

        int choice;


        printf("\t\t\t\t\t***Welcome to YAAR Cab Services Pvt. Ltd.***\n");
        printf("\n\tPlease enter the number associated with the option you want to choose-\n");
        printf("1.Book a Cab\n");
        printf("2.EXIT\n");
        printf("3.Add a new driver\n");
        printf("4.Display list of drivers\n");
        printf("5.Display Complete Booking History\n\n");
        scanf("%d",&choice);

        switch(choice){

        case 1:
                system("COLOR E1");

                printf("First please introduce yourself to us by entering the following details :\n");

                ///Required inputs from the USER.

                printf("Name: ");
                fflush(stdin);
                scanf("%[^\n]s",&grahak.name);

                printf("Mobile Number: ");
                fflush(stdin);
                scanf("%ld",&grahak.mobileNo);


                printf("\nOur servicing areas are GURGAON , NOIDA , ROHINI , VASANT VIHAR and DWARKA .\nPlease choose your pickup location (Enter in small letters)\n");
                printf("Pickup Location: ");
                fflush(stdin);
                scanf("%[^\n]s",&grahak.pickupLocation);

                printf("Drop Location: ");
                fflush(stdin);
                scanf("%[^\n]s",&grahak.dropLocation);

                int normalFare = fare();

                while ( normalFare == -1 ){

                    printf("Please check your Pickup and Drop Location (check syntax too) !!\n");
                    printf("Pickup Location: ");
                    fflush(stdin);
                    scanf("%[^\n]s",&grahak.pickupLocation);
                    printf("Drop Location: ");
                    fflush(stdin);
                    scanf("%[^\n]s",&grahak.dropLocation);

                    normalFare = fare();
                }

                printf("\nThe Following notations mean:\n1.S : Sedan(3-4 Seater + extra luggage space + comfort)\n2.H : Hatchback(3-4 seater)");
                printf("\n3.L : Luxury (travel in luxury)\n4.X : Xtra Large(7-8 seater capacity)");
                printf("\nPlease enter your choice of cab: ");
                fflush(stdin);
                scanf("%c",&grahak.cabType);

                while ( grahak.cabType == 's' || grahak.cabType == 'l' || grahak.cabType == 'h' || grahak.cabType ==  'x'){
                    printf("please enter your cab choice (in capitals) !");
                    fflush(stdin);
                    scanf("%c",&grahak.cabType);
                }

                struct cab *current = search();
                if(current!=NULL){

                    printf("\n\n***Well we are searching for a cab near you !!***");


                    int ff= FinalFare(normalFare);

                    printf("\nDo you have any coupon to be applied ?\nEnter Y or N: ");
                    char b;
                    fflush(stdin);
                    scanf("%c",&b);
                    int a;
                    if ( b == 'Y' ){
                        printf("\nPlease enter your coupon code: ");
                        scanf("%d",&grahak.couponNo);

                        if (couponFare(grahak.couponNo , ff) == -1){
                            printf("Invalid Coupon Number ! Sorry the coupon could not be applied.\n");
                            a = cabPrint(current , ff);
                        }
                        else{
                            a = cabPrint(current , couponFare(grahak.couponNo , ff));
                        }
                    }
                    else{

                        a = cabPrint(current , ff);
                    }



                    if( a==1 ){

                        printf( "\n***Your Cab Is Booked***\n\n\n");
                        printf("You've been sent an E-Mail regarding the driver details too !! ");
                        printf("\nThank You %s for choosing a cab with us ! We hope to serve you further in the future !!\n\n\n\n\n\n\n",grahak.name);
                        shift(current);
                        newlocation(current);


                        fp=fopen("YAAR Cab Database.txt","a");

                        if( fp == NULL ){
                            printf("Error opening file !");
                            break;
                        }

                        fprintf(fp,"\n\n\tCustomer's Name : %s ",grahak.name);
                        fprintf(fp,"\n\tCustomer's Mobile Number : %ld",grahak.mobileNo);
                        fprintf(fp,"\n\tCustomer's Pickup Location : %s",grahak.pickupLocation);
                        fprintf(fp,"\n\tCustomer's Drop Location : %s",grahak.dropLocation);
                        fprintf(fp,"\n\tDriver's Name : %s",current->name);
                        fprintf(fp,"\n\tCustomer's Cab Type : %c",grahak.cabType);

                        if (couponFare(current , ff) == -1){
                            fprintf(fp,"\n\tCustomer's Ride Total Fare : %d",ff);
                        }
                        else {
                            fprintf(fp,"\n\tCustomer's Ride Total Fare : %d",couponFare(current , ff));
                        }

                        fclose(fp);

                        printf("\n\n\n\n");

                        break;

                    }
                    else{
                        break;
                    }
                }

                else{
                    break;
                }

        case 2:
                system("COLOR F0");

                exit(1);
                break;

        case 3:


                printf("Please proceed only if you are a employee or trustee of YAAR cabs.\nThis section requires necessary authentication.");
                printf("\nIf you wish to continue , Then Press  1.Else press any other number to exit.\n");
                int t;
                scanf("%d",&t);
                if(t==1 ){
                    printf("Enter the password\n");
                    char u[100];
                    scanf("%s",u);
                        if(strcmp(u,"YAAR")==0){

                            printf("\nWelcome to the employee/trustee section\n");
                            insert_newcab();

                            }

                        else{

                            printf("Incorrect Password\n");
                            continue;

                            }
                        }
                else
                    continue;

                break;
    case 4:


            display();
            break;

    case 5:

            rp=fopen("YAAR Cab Database.txt","r");

            if( rp == NULL ){
                printf("Error opening file !");
                break;
            }

            while(1){

                c=fgetc(rp);
                if(c==EOF)
                    break;
                printf("%c",c);

            }

            printf("\n");
            fclose(rp);

            break;

        }
    }

    return 0;
}
