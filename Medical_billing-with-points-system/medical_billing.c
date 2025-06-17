#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define LP 0.10
#define MAX 1000
#define C_MAX 150
#define M_MAX 120

void normalize_phone(char *src, char *dest, int size);
int assign_cust_id(); //assigns customer id to each new customer
int add_cust(); //adds a new customer to the entry list
int check_points(); //to check the loyalty points of a given customer
float add_med(char id[],int n); //adds the amount for a given medicine id and quantity in the bill
int bill();
int display(char number[],float sum,float final_sum);
int check_exist(char number[]);

// Helper function to normalize phone numbers (removes =" and ")
void normalize_phone(char *src, char *dest, int size) {
    if (src == NULL) {
        dest[0] = '\0';
        return;
    }
    if (src[0] == '=' && src[1] == '"') {
        // Copy from after ="
        strncpy(dest, src + 2, size - 1);
        dest[size-1] = '\0';
        // Remove trailing quote if present
        size_t len = strlen(dest);
        if (len > 0 && dest[len-1] == '"') {
            dest[len-1] = '\0';
        }
    } else {
        strncpy(dest, src, size-1);
        dest[size-1] = '\0';
    }
}

int assign_cust_id(){
    
    int used[MAX]={0};
    char line[C_MAX];
    FILE *fp= fopen("customer_info.csv","r");
    if(fp==NULL){
        printf("Error Adding User. Please try again later.\n");
        fclose(fp); 
        return 1;
    }
    //fgets(line,sizeof(line),fp);
    while(fgets(line,sizeof(line),fp)){
        char *id=strtok(line,",");
        if (id != NULL && id[0] != '\0') {
            int id_int=atoi(id);
            if(id_int>0 && id_int<MAX){
                used[id_int]=1;    
            }
        }
    }
    fclose(fp);
    
    for(int i=1;i<MAX;i++){
        if(used[i]==0){
            return i; 
        }
    }
    return -1; 
}    

int check_exist(char cust_number[]){
    char line[C_MAX];
    int cust=0;
    FILE *fp=fopen("customer_info.csv","r");
    
    if(fp==NULL){
        printf("Error Adding User Info. Please try again later.\n");
        return -1;    
    }
    rewind(fp);
    fgets(line,sizeof(line),fp);
    while(fgets(line,sizeof(line),fp)){    
        char *id=strtok(line,",");
        char *name=strtok(NULL,",");
        char *age=strtok(NULL,",");
        char *number=strtok(NULL,",\n");
        char norm_number[20];
        normalize_phone(number, norm_number, sizeof(norm_number));
        if(number && (strcmp(norm_number,cust_number)==0)){
            cust=1;
            break;
        }
    }
    fclose(fp);
    return cust;
}

int add_cust(){
    FILE *f= fopen("customer_info.csv","r");
    if(f==NULL){
       FILE *fp=fopen("customer_info.csv","a");
       fprintf(fp,"Customer ID,Customer Name,Customer Age,Customer Number,Loyalty Points\n");
       fclose(fp);
    } fclose(f);
    FILE *fp=fopen("customer_info.csv","a+");
    if(fp==NULL){
        printf("Error Adding User Info. Please try again later.\n");
        return 1;
        
    }
    
    int cust_id=assign_cust_id();
    char cust_number[12];
    int cust_age;
    char cust_name[50];

    printf("\nEnter Customer Name: ");
    while(getchar()!='\n');
    fgets(cust_name,sizeof(cust_name),stdin);
    cust_name[strcspn(cust_name, "\n")] = '\0';

    printf("\nEnter Customer Age: ");
    if(scanf(" %d",&cust_age)!=1){
        printf("Invalid Age Entry");
        fclose(fp);
    }

    printf("\nEnter Customer Mobile Number: ");
    if(scanf(" %s",cust_number)!=1){
        printf("Invalid Contact Number Entry");
        fclose(fp);
    }
    int exist=check_exist(cust_number);
    if(exist==1){
        printf("Contact Number Already Exists.Please Try With A Different Number\n");
    }
    else if(exist==0){
        fprintf(fp, "%d,%s,%d,=\"%s\",%.1f\n", cust_id,cust_name,cust_age,cust_number,LP);
        printf("\nUser Data Saved Successfully.\n");
    }
    fclose(fp);
    return 0;
    
}

int check_points(){
    char cust_number[12];
    int count=0;
    char line[C_MAX];
    printf("\nEnter Customer Mobile Number:");
    scanf(" %s",cust_number);
    FILE *fp= fopen("customer_info.csv","r");
    if(fp==NULL){
        printf("Error Checking Points. Please try again later.\n");
        return 1; 
        fclose(fp);
    }
    
    while(fgets(line,sizeof(line),fp)){
        char *id=strtok(line,",");
        char *name=strtok(NULL,",");
        char *age=strtok(NULL,",");
        char *no=strtok(NULL,",");
        char *point=strtok(NULL,",");
        char norm_no[20];
        normalize_phone(no, norm_no, sizeof(norm_no));
        if(age && (strcmp(norm_no,cust_number)==0)){
            printf("Customer's Loyalty Points Are: %s\n",point);
            count=1;
            break;
        }
    }
    if(count==0)
        printf("Customer Not Registered.\n");
    
    fclose(fp);
    return 0;
}

float add_med(char id[],int n){
    char line[M_MAX];
    float cost=0;
    FILE *fp= fopen("medicine.csv","r");
    if(fp==NULL){
        printf("Error Checking Medicine. Please Try Again\n");
        return 1;
        fclose(fp);
    }

    while(fgets(line,sizeof(line),fp)){
        char *m_id=strtok(line,",");
        char *m_name=strtok(NULL,",");
        char *tc=strtok(NULL,",");
        char *c=strtok(NULL,",");
        if(id && strcmp(id,m_id)==0){
            cost=atof(c); }
    }
    fclose(fp);
    return cost*n;
}

int display(char number[],float sum,float f_sum){
    char line[C_MAX];
    FILE *fp=fopen("customer_info.csv","r");
    if(fp==NULL){
        printf("Error Processing The Bill.");
        return 1;
        fclose(fp);
    }
    while(fgets(line,sizeof(line),fp)){
        char *c_id=strtok(line,",");
        char *c_name=strtok(NULL,",");
        char *c_age=strtok(NULL,",");
        char *c_no=strtok(NULL,",");
        char *c_point=strtok(NULL,",");
        char norm_no[20];
        normalize_phone(c_no, norm_no, sizeof(norm_no));
        if(c_age && strcmp(norm_no,number)==0){
            printf("\n-------------Customer Details-------------\n");
            printf("Name:- %s\n",c_name);
            printf("Age:- %s\n", c_age);
            printf("Contact Number:- %s\n",c_no);
            printf("\n-------------Bill Details-------------\n");
            printf("Total Cost:- %.2f\n",sum);
            printf("Final Bill Amount:- %.2f\n",f_sum);
            printf("\n--------------Thank You!!---------------\n");
            break;
        }
    }
    fclose(fp);
    return 0;
}


int bill(){
    char cust_no[12];
    //Enter customer detail
    printf("\nEnter Customer Number: ");
    scanf(" %s",cust_no);
    //enter the medicine details
    char id[5];
    int quantity;
    int i=1,addup;
    float sum=0;
    do{
        printf("\nEnter the Medicine ID: ");
        scanf(" %s",id);
        printf("\nEnter the Quantity of the Medicine Purchased: ");
        scanf(" %d",&quantity);
        sum+=add_med(id,quantity);
        
        printf("\nDo You Wish To Add Another Medicine:\n1.Yes\n2.No\n");
        scanf(" %d",&addup);
        if (addup == 2)
            break;
        else
            continue;
        i++;
    }while(i<=MAX);
    //checking for discounts using loyalty points
    char line[C_MAX];
    float points;
    int redeem=1;
    float f_sum=sum;
    FILE *fp=fopen("customer_info.csv","r");
    FILE *f=fopen("temp.csv","w");

    if(fp==NULL){
        printf("Error Processing User Data");
        return 1;
        fclose(fp);
    }
    char *c_id = NULL, *c_name = NULL, *c_age = NULL, *c_no = NULL, *c_point = NULL;
    while(fgets(line,sizeof(line),fp)){
        char *c_id=strtok(line,",");
        char *c_name=strtok(NULL,",");
        char *c_age=strtok(NULL,",");
        char *c_no=strtok(NULL,",");
        char *c_point=strtok(NULL,",");
        char norm_no[20];
        normalize_phone(c_no, norm_no, sizeof(norm_no));
        if(c_age && strcmp(norm_no,cust_no)==0){
            points=atof(c_point);
            if((points) && points>0){
                printf("Available Points:%2.f\n",points);
                printf("Do You Want To Use Your Loyalty Points For Disount:-\n1.Yes\n2.No\n");
                scanf("%d",&redeem);
            }
            if(redeem==1){
                if(points==0){
                    printf("\n\nNo Points Available :(\n");
                    sprintf(c_point, "%.2f", points);
                }
                else if(points<sum){
                    f_sum=sum-points;
                    points=0.03*f_sum;
                    sprintf(c_point, "%.2f", points);
                }
                else if(points>sum){
                    f_sum=0; 
                    points=points-sum;
                    sprintf(c_point, "%.2f", points);
                }
                else{
                    f_sum=0;
                    points=0;
                    sprintf(c_point, "%.2f", points);
                }
            }
            else{
                points+=0.03*f_sum;
                sprintf(c_point, "%.2f", points);
            }
            fprintf(f,"%s,%s,%s,%s,%s\n",c_id,c_name,c_age,c_no,c_point);
        } 
        else
            fprintf(f,"%s,%s,%s,%s,%s",c_id,c_name,c_age,c_no,c_point);
    }
    display(cust_no,sum,f_sum);
    fclose(fp);
    fclose(f);
    remove("customer_info.csv");
    rename("temp.csv","customer_info.csv");
    return 0;
}


int main(){
    int choice;

    printf("\n----------------MENU-------------------\n"); //User Display with all features
    printf("Features Available For User's Choices:-\n");
    printf("1. Add New Customer\n");
    printf("2. Check Customer Points\n");
    printf("3. Bill The Purchased Items\n");
    printf("4. Exit\n"); 
    
    printf("Enter Your Choice: ");
    scanf(" %d",&choice);

    printf("--------------X--X--X--X---------------");

    switch(choice){
        case 1: //Adds a new customer
            add_cust();
            break;
        case 2: //Checks customer points
            check_points();
            break;
        case 3: //Shows the bill of present customer with some additonal features
            bill();
            break;
        case 4:
            exit(0); //exits out of the program
        default:
            printf("Please Enter Appropriate Choice\n");   
    }
    return 0;
 }