#include<stdio.h>
#include<string.h>

void swap(char str[],int len){
    char temp;
    for (int i = 0; i < len/2; i++)
    {
       temp=str[i];
       str[i]=str[len-1-i];
       str[len-i-1]=temp;
    }
}
void bit_converter(char str[],int length){
    int a;
    for (int i = 0; i <length; i++)
    {
        a=(int)str[i];
       a=a^(1<<1);
       a=a^(1<<4);
       str[i]=(char)a; 
    }
}
void encode(char str[]){
    getchar();
    printf("\n enter sentece to encode: \n");
    scanf("%[^\n]",str);
    int lenght_of_str=strlen(str);
    swap(str,lenght_of_str);
    bit_converter(str,lenght_of_str);
    printf("encoded sentence: %s",str);
}

void decode(char str[]){
    getchar();
    printf("enter sentence to decode: \n");
    scanf("%[^\n]",str);
    int length_of_str=strlen(str);
    swap(str,length_of_str);
    bit_converter(str,length_of_str);
    printf("decoded sentense is : \n%s",str);

}
int main(){
    char sen[100];
    char encoded_sentence[100];
    printf("\n main menue\n");
    int opt;
    do
    {
        printf("1.encode sentence\n");
        printf("2.decode sentence\n");
        printf("3. exit system\n");
        printf("enter opt to perform action");
            scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            encode(sen);
            break;
            case 2:
            decode(sen);
            break;
            case 3:
            printf("exiting system.....\n");
            break;
        
        default:
        printf("invalid input\n");
            break;
        }
    } while (opt!=3);
    return 0;
}