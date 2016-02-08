#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    
struct sy_tab
{
    char a[20];
    char b[20];

};

char arr[5][40]={"int","char","double","float","long"};

char key[32][10]={"break","auto","case","const","char","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

char c;

int i,count=0,k,d;

char s[20],id[25],u[10];

ifstream fin("test.cpp", ios::app);

int index = 0,break_index = 0 , chunk_index = 0 ;

char temp[10000];

int memory = 10245;

while(fin)
{
    fin.get(c);
    
    
    temp[break_index] = c;
    //cout<<strlen(temp)<<"\t";

    if(c==' ' || c == '\n' || c == ',' || c == '}') {

        



        //Clear the space
        char newtemp[10000];
        int newIndex = 0;
        
        for(int _i = 0 ; _i <  strlen(temp) ; _i++){
            if(temp[_i] != ' '){
                newtemp[newIndex] = temp[_i];
                newIndex++;
                
            }
        }

        //cout<<newtemp;
        for(int __i = 0 ; __i <  strlen(newtemp) ; __i++){
            if(newtemp[__i] == ','  ||newtemp[__i] == ' ' || newtemp[__i] == ';' || newtemp[__i] == '('){
                newtemp[__i] = '\0'; 
                break;
            }
        }

        char lastDataType[10];

        

        if(strcmp(newtemp,"int")==0){
            //cout<<"Keyword [ int ] : " << newtemp << "\n";
            strcpy(lastDataType,"int");
            memory += 2 ;
        }else if(strcmp(newtemp,"char")==0){
            //cout<<"Keyword [ char ] : " << newtemp << "\n";
            strcpy(lastDataType,"char");
            memory += 1 ;
        }else if(strcmp(newtemp,"float")==0){
            //cout<<"Keyword [ float ] : " << newtemp << "\n";   
            strcpy(lastDataType,"float");
            memory += 4 ;
        }else if(newtemp[0] == '#'){

        }else if(strcmp(newtemp,"main")==0 || strcmp(newtemp,"return")==0){

        }
        else if(newtemp[0] == ' '){
        }
        else if(newtemp[0] == '<' || newtemp[0] == '}' || newtemp[0] == '{'){
        }
        else if(newtemp[0] == '\n'){
        }
        else{
            cout<<"Variable  : " << newtemp << " : DataType : " << lastDataType << " : Memory : " << memory << "\n";
        }
        

       
        
        break_index = 0 ;

        //Clear the variable temp and new temp
        for ( int i = 0 ; i< 40; i++){
            newtemp[i] = ' ';
            temp[i] = ' ';
        }
            

    }else{
        
        
    }

    break_index++; 

}

  

}
 
