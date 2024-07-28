#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include<stdarg.h>
#include<math.h>

int KEY_UP =  72;
int KEY_DOWN = 80;
int  KEY_LEFT = 75;
int KEY_RIGHT  = 7;
int ENTER = 13;
int r = 3;
int textsize = 10;

void convertToInt(char string[],int *converted){
    for(int i=0;i<strlen(string);i++){
        if(string[i]>='A' && string[i]<='Z')
            converted[i]=(int)string[i]-65;
        else if(string[i]>='a'&& string[i]<='z')
            converted[i]=(int)string[i]-97;
        else
            converted[i]=-1;
    }
}

void cipherConversion(int plaintextConverted[], int *ciphertextConverted,int key[r][r],int len){
    int i=0;
    while(i<len){
        int paired[r],cipherIndex = 0;
        for(int j=0;j<r;j++)
            paired[j]=plaintextConverted[i++];

        for(int z=0;z<1;z++){
            for(int j=0;j<r;j++){
                ciphertextConverted[j]=0;
                for(int k=0;k<r;k++){
                    ciphertextConverted[j]+=paired[k]*key[j][k];
                    /*Hill Cypher can be done in 1*3 or 3*1 method depending on orientation of matrix */
                    /*Another method is 
                    ciphertextConverted[j]+=paired[k]*key[j][k];
                    Both will give different encryption output
                    */
                }

            }
        }

    }
}
void cipherToString(int ciphertextConverted[],char *ciphertext,int len){
    char c[len];
    
    for(int i=0;i<len;i++){
        char *ch = (char *)malloc(sizeof(char));
        *ch = (char)((ciphertextConverted[i]%26)+65);
        strcpy(&c[i],ch);
              
    }
    strcpy(&c[len],"\0");   
    strcpy(ciphertext,c);
}
void menu(int choice){
    switch (choice)
    {
        case 1:
            printf("Encryption\n");
            break;
        case 2:
            printf("Decryption\n");
            break;
        case 3:
            exit(0);
    }
    printf("Press Any Key ....");
    getch();

}

int main(int argc,char *argv[]){
    /*int r=3,c=3,i=0;
    int key[][3]={{6,24,1},{13,16,10},{20,17,15}};
    printf("Key Matrix : \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++)
            printf("%2d ",key[i][j]);
        printf("\n");
    }

    char plaintext[textsize];
    char ciphertext[textsize];

    strcpy(plaintext,"ACT");

    int plaintextConverted[textsize];
    int ciphertextConverted[textsize];

    while(strlen(plaintext)%r!=0)
        strcat(plaintext,"x");
    convertToInt(plaintext,plaintextConverted);
    
    printf("Converted plain text \n");
    for(int j=0;j<strlen(plaintext);j++)
        printf("%d ",plaintextConverted[j]);
    
    printf("\n");

    cipherConversion(plaintextConverted,ciphertextConverted,key,strlen(plaintext));
    printf("Cipher text converted \n");
    for(int j=0;j<strlen(plaintext);j++)
        printf("%d ",ciphertextConverted[j]);
    printf("\n");

    cipherToString(ciphertextConverted,ciphertext,strlen(plaintext));

    printf("Cipher Text : %s ",ciphertext);*/

    unsigned int choice = 1;
    char highlight[3];
    highlight[choice-1]='-';
    highlight[choice%3]='.';
    highlight[(choice+1)%3]='.';
    while(1) {
        system("cls");
        printf("%c Encrypt\n",highlight[0]);
        printf("%c Decrypt\n",highlight[1]);
        printf("%c Exit\n",highlight[2]);
        char keypress = getch();
        int key = keypress;
        
        if(key==KEY_UP){
            choice = (choice+4)%3+1;
        }
        else if(key==KEY_DOWN){
            choice = ((choice)%3)+1;
        }
        else if(key==ENTER){
            menu(choice);
        }
        highlight[choice-1]='-';
        highlight[choice%3]='.';
        highlight[(choice+1)%3]='.';

        fflush(stdin);



    }


    
}