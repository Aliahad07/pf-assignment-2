#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generate_matrix(int matrix[10][10]){
    for(int y=0;y<10;y++){
        for(int x=0;x<10;x++){
            matrix[y][x]=rand()%8;
        }
    }

}
void print_matrix(int matrix[10][10]){
    printf(" ");
    for(int x=0;x<10;x++){
        printf("x%-2d",x);
    }
    printf("\n");
    printf(" ");
    for (int x = 0; x < 10; x++)
    {
        printf("----");
    }
    printf("\n");
    for (int y = 0; y < 10; y++)
    {
        printf("y%-2d|",y);
        for (int x = 0; x < 10; x++)
        {
            printf(" %d ",matrix[y][x]);

        }
        printf("\n");
        
    }
    
}

void append(int mat[][10]){
    int x;
    int y;
    printf("\n enter coordinate you want to append: \n");
    printf("X coordinates: \n");
    scanf("%d",&x);
    printf("enter Y coordinates you want to append: \n");
    scanf("%d",&y);

    if (x >= 10 || y>=10)
    {
        printf("invalid coordinates!");
        return;
    }
    int  bit0,bit1,bit2;
    do
    {
        printf("\n 1. update power status (0/1): \n");
        scanf("%d",&bit0);
        if(bit0!=1 && bit1!=0){
            printf("invalid input!");
        }
    } while (bit0 !=1 && bit0 != 0);

    do
    {
        printf("2. update overload warning status (0/1): \n");
        scanf("%d",&bit1);
        if(bit1 !=1 && bit1 != 0){
            printf("invalid input!\n");
        }
    } while (bit1 !=1 && bit1!=0);
    
    do
    {
        printf("3. update maintenaince required (0/1): \n");
        scanf("%d",&bit2);
        if(bit2!=1 && bit2!=0){
            printf("invalid input\n");
        }
    } while (bit2!=0 && bit2!=1);

    int temp= (bit2 << 2)| (bit1 << 1)| (bit0);
    mat[y][x]=temp;
    printf("\n new grid \n");
    print_matrix(mat);
}

void query(int grid[][10]){
   int x;
    int y;
    printf("\n enter coordinate you want to append: \n");
    printf("X coordinates: \n");
    scanf("%d",&x);
    printf("enter Y coordinates you want to append: \n");
    scanf("%d",&y);

    if (x >= 10 || y>=10)
    {
        printf("invalid coordinates!");
        return;
    }
    int first_flag=grid[y][x]&1;
    int sec_flag=(grid[y][x]>>1)&1;
    int third_flag=(grid[y][x]>>2)&1;

    printf("\nquery report\n");
    printf("power status\n");

    if(first_flag){
        printf("on\n");
    }
    else{
        printf("\noff\n");
    }
    printf("overload warniing status: \n");
    if(sec_flag){
        printf("overloaded\n");
    }
    else{
        printf("normal status");
    }
    printf("maintenance required\n");
    if (third_flag){
        printf("maintenance required\n");
    }
    else{
        printf("matenance not required\n");
    }

}

void report(int mat[][10]){
    int count1=0,count2=0,count3=0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <10; j++)
        {
            int flag2=(mat[i][j]>>1)&1;
            int flag3=(mat[i][j]>>2)&1;
            if(flag2 && flag3){
                count1 ++;
            }
            if(flag2){
                count2 ++;
            }
            if(flag3){
                count3++;
            }
        }
        
    }
    printf("\n report of grid\n\nthe number that overload and required maintenance is : %d\n",count1);
    printf("the number of overload sections: %d\n",count2);
    printf("the number of section reqiure maintenance is: %d",count3);
}

int main(){
    int grid[10][10];
    srand(time(NULL));
    generate_matrix(grid);
    printf("original matrix :\n");
    print_matrix(grid);
    int opt;
    do
    {
        printf("\nmain menue\n");
        printf("1. update sector status\n");
        printf("2. query status\n");
        printf("3. run system checking\n");
        printf("4. exit system\nenter option");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            append(grid);
            break;
        case 2:
            query(grid);
            break;
        case 3:
            report(grid);
            break;
        case 4:
        printf("exiting system ...\n");
        break;

        default:
        printf("invalid option\n");
            break;
        }
    } while (opt!=4);

 return 0;   
}