#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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

int main(){
    int r=3,c=3,i=0;
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

    printf("Cipher Text : %s ",ciphertext);


    
}