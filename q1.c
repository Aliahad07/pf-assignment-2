#include<stdio.h>
#include<string.h>
#define maxbooks 100
#define title_len 50
#define threshold 5
void display_menue(){
    printf("liberty book inventory\n");
    printf("\n=======================\n");
    printf("enter choice to perform below tasks\n");
    printf("1. add new book\n");
    printf("2. process a sale\n");
    printf("3. view low stock report\n");
    printf("4. exit system\n");
    printf("---------------------------\n");
}

void enter_new_book(int isbn[],char titles[100][50],float prices[],int quantities[],int *count){

    int new_isbn;
    printf("enter isbn of new book\n");
    scanf("%d",&new_isbn);

    if (new_isbn<=0)
    {
        printf("enter valid isbn!\n");
        return;
    }
    for (int i = 0; i <*count; i++)
    {
        if (isbn[i]==new_isbn)
        {
            printf("this isbn already exist new isbn!\n");
            return;
        }
        
    }
    
    char entered_book[50];
    printf("Enter the book title: ");
    scanf(" %[^\n]", entered_book);
    
    for(int i = 0; i < *count; i++) {
        if(strcasecmp(titles[i], entered_book) == 0) {
            printf("Book title Repeated Invalid Input\n");
            return;
        }
    }

    float new_prices;
    printf("enter new price for book:\n");
    scanf("%f",&new_prices);
    if(new_prices<=0){
        printf("invalid price! \n");
        return;
    }
    int new_quantity;
    printf("enter quantity of new book: \n");
    scanf("%d",&new_quantity);
    
    if (new_quantity<=0)
    {
        printf("invalid quantity \n");
        return;
    }
    isbn[*count]=new_isbn;
    strcpy(titles[*count],entered_book);
    prices[*count]=new_prices;
    quantities[*count]=new_quantity;

    (*count)++;
    printf("new book entered successfully!\n");
    printf("isbn   title   price   quantity\n");
    for(int i=0;i<*count;i++){
    printf("%-10d %-20s %-11.2f %-10d\n",isbn[i],titles[i],prices[i],quantities[i]);
    }
    
}
void process_sale(int isbn[],char title[][50],float price[],int quantities[],int*count){
        int sale_isbn;
        int sale_quantity;

        printf("enter isbn of salling book: \n");
        scanf("%d",&sale_isbn);
        
        for (int i = 0; i < *count; i++)
        {
            if(isbn[i]==sale_isbn){
                printf("enter quanity of sold books:\n");
                scanf("%d",&sale_quantity);
                if (sale_quantity>quantities[i])
                {
                    printf("no book left,invalid input\n");
                    return;
                }
                else{
                    quantities[i]-=sale_quantity;
                    for (int i = 0; i < *count; i++)
                    {
                        printf("\n%-10s %-20s %-12s %-10s\n","sales isbn","title","sales price","sales quantity");
                        printf("\n%-10d %-20d %-12f %-10d\n",isbn[i],title[i],price[i],quantities[i]);
                    }
                    
                }
                
            }
            else{
                printf("invalid isbn!\n");
            }
        }
        
    }

    void low_report(int isbn[],char title[][50],float price[],int quantity[],int *count){
        printf("low stock report\n");
        char status[100];
                    printf("\n%-10s %-25s %-10s %-10s %-10s\n","isbn","title","price","quantity","status");

        for (int i = 0; i < *count; i++)
        {
            if (quantity[i]>5)
            {
                strcpy(status,"HIGH\n");
            }
            else{
                strcpy(status,"LOW");
            }
printf("%-10d %-25s $%-8.2f %-10d %-10s\n", 
               isbn[i], title[i], price[i], quantity[i], status);
        }
        
    }
    int main(){
        int isbn[100]={123456,234567,345678,1111111};
        char titles[100][50]={"c programing","arrays","OOP"};
        float prices[100]={50.6,17.5,43.6};
        int quantity[100]={12,23,2};
        int choice;
        int isbn_count=3;
       
        do
        {
            display_menue();
        printf("enetr your choice:\n");
        scanf("%d",&choice);
        if(choice<=0){
            printf("invalid choice!\n");
        }
         
            switch (choice)
        {
        case 1:
            printf("adding new books\n");
            enter_new_book(isbn,titles,prices,quantity,&isbn_count);
            break;
            case 2:
             printf("processing sale!\n");
              process_sale(isbn,titles,prices,quantity,&isbn_count);
               break;
                 case 3:
                 printf("generating low stock report!\n");
                 low_report(isbn,titles,prices,quantity,&isbn_count);
                 break;
                     case 4: 
                     printf("exting the program!!\n");
                     break;                     
        
        default:
        printf("invalid option selected!\n");
            break;
            
        }
    }while(choice!=4);
               return 0;   
    }
        
