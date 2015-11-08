#include <iostream>
#include "Playfair.h"
#include <ctype.h>
#include <string.h>

#include <conio.h>

Playfair::Playfair(std::string str){
    origin = str;
}
int search(char from[5][5] ,char target){
    if(isupper(target))
        target = tolower(target);
    for(int i = 0 ; i < 5 ; i++)
        for(int j = 0 ; j < 5 ; j++)
            if(from[i][j]==target)
                return 5*i+j;
    return -1;
}
void Playfair::get_key(){

    printf("\n enter the key\n ");

    bool mark[26] = {false};
    mark['j'-'a'] = true;
    char temp = getchar();
    if(isupper(temp))
        temp = tolower(temp);
    if(temp == 'i')temp = 'j';
    int i = 0 ;
    do{
        if(search(keyArray,temp) == -1 && temp!=' '){
            keyArray[(int)(i/5)][i%5] = temp;
            i++;
            mark[temp-'a'] = true;
        }
        temp = getchar();
        if(isupper(temp))
            temp = tolower(temp);
        if(temp == 'j')temp = 'i';
    }while(temp!='\n'&& i < 25 );

    for(;i < 25 ; i++){
        for(int j = 0 ; j < 26 ; j ++)
            if(mark[j]==false){
                keyArray[(int)(i/5)][i%5] = (char)('a'+j);
                mark[j] =true;
                break;
            }
    }
    for(int k = 0 ; k < 5 ; k++){
        for(int j = 0 ; j < 5 ; j++)
            printf("%c ",keyArray[k][j]);
        printf("\n");
    }

}
void Playfair::get_key(std::string input){

    bool mark[26] = {false};
    mark['j'-'a'] = true;
    int i = 0 ;
    int count = 0 ;
    do{
        if(isupper(input.at(i))) input.at(i) = tolower(input.at(i));
        if(input.at(i) == 'j') input.at(i) = 'i' ;
        if(search(keyArray,input.at(i)) == -1 && input.at(i)!=' '){
            keyArray[(int)(count/5)][count%5] = input.at(i);
            count++ ;
            mark[input.at(i)-'a'] = true;
        }
        i++ ;
    }while(i < input.length() && count < 25 );

    for(;count < 25 ; count++){
        for(int j = 0 ; j < 26 ; j ++)
            if(mark[j]==false){
                keyArray[(int)(count/5)][count%5] = (char)('a'+j);
                mark[j] =true;
                break;
            }
    }
    for(int k = 0 ; k < 5 ; k++){
        for(int j = 0 ; j < 5 ; j++)
            printf("%c ",keyArray[k][j]);
        printf("\n");
    }
}
std::string Playfair::encrypt(){
    /*bool table[26] = { false };
    table[9] = true;//j©Mi³]¬°¦P¤@®æ

    for (int i = 0; i < key.length(); i++){
        if (isupper(key.at(i))){
            key.at(i) = tolower(key.at(i));
        }

        if (key.at(i) == 'j'){
            key.at(i) = 'i';
        }

        if (!table[key.at(i) - 'a']){
            table[key.at(i) - 'a'] = true;
        }
        else{
            key.erase(i--, 1);
        }
    }

    //std::cout << key << std::endl;

    char matrix[5][5];

    int i = 0;//keyªº¦ì¸m
    int j = 0;//tableªº¦ì¸m

    for (int k = 0; k < 5; k++){
        for (int l = 0; l < 5; l++){
            if (i < key.length()){
                matrix[k][l] = key.at(i++);
            }
            else{
                while (table[j]){
                    j++;
                }
                matrix[k][l] = static_cast<char>('a' + j);
                j++;
            }
        }
    }

    /*
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    std::string _str = origin;
    int *ptr = new int[_str.length()];
    afterCi = "";
    for (int i = 0; i < _str.length(); i++){
        if (islower(_str.at(i))){
            afterCi += _str.at(i);
            ptr[i] = 0;
        }
        if (isupper(_str.at(i))){
            afterCi += tolower(_str.at(i));
            ptr[i] = 1;
        }
        if (_str.at(i) == ' '){
            ptr[i] = 2;
        }
    }

    for (int i = 0; i < afterCi.length() - 1; i += 2){
        if (afterCi.length() == i + 1 ){
            afterCi.insert(i , "x");
        }

        if (afterCi.at(i) == 'j'){
            afterCi.at(i) = 'i';
        }

        if (afterCi.at(i + 1) == 'j'){
            afterCi.at(i + 1) = 'i';
        }

        if (afterCi.at(i) == afterCi.at(i + 1)){
            afterCi.insert(i , "x");
        }


        int row1 = 0;
        int col1 = 0;
        int row2 = 0;
        int col2 = 0;

        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                if (afterCi.at(i) == keyArray[j][k]){
                    row1 = j;
                    col1 = k;
                }
                if (afterCi.at(i + 1) == keyArray[j][k]){
                    row2 = j;
                    col2 = k;
                }
            }
        }
        if (row1 == row2){
            afterCi.at(i) = keyArray[row1][(col1 + 1) % 5];
            afterCi.at(i + 1) = keyArray[row2][(col2 + 1) % 5];
        }
        else if (col1 == col2){
            afterCi.at(i) = keyArray[(row1 + 1) % 5][col1];
            afterCi.at(i + 1) = keyArray[(row2 + 1) % 5][col2];
        }
        else{
            afterCi.at(i) = keyArray[row1][col2];
            afterCi.at(i + 1) = keyArray[row2][col1];
        }
    }

    //printf("here  %s %d" , afterCi.c_str() , afterCi);
    //getchar();
    return afterCi;
}

std::string Playfair::decrypt(){
    std::string _str = origin;
    if(!_str.empty()){
        int* mark = new int[_str.length()];
                // 0 = lowwer ,1 = upper , 2 = blank
        afterDe ="";
        std::string temp ="";
        for(int i = 0 ; i < _str.length() ; i++){
            char tmp = _str.at(i);
            if(isupper(tmp)){
                tmp = tolower(tmp);
                mark[i] = 1;
            }
            if(tmp == ' ')mark[i] = 2;
            if(tmp>='a' && tmp<='z')
                temp += tmp;
            else return "illigal ciphertext";
        }
        if(temp.length()%2!=0)return "illigal ciphertext";

        for(int i = 0 ; i < temp.length()-1 ; i = i+2){
            char first = temp.at(i);
            char second = temp.at(i+1);
            int firstNumber = search(keyArray,first);
            int secondNumber = search(keyArray,second);
            if(firstNumber == secondNumber)return "illigal ciphertext";
            if((int)(firstNumber/5) == (int)(secondNumber/5)){
                //printf("\n%c %c",keyArray[(int)(firstNumber/5)][(firstNumber+4)%5],keyArray[(int)(secondNumber/5)][(secondNumber+4)%5]);
                afterDe+=(char)keyArray[(int)(firstNumber/5)][(firstNumber+4)%5];
                afterDe+=(char)keyArray[(int)(secondNumber/5)][(secondNumber+4)%5];
            }else if((firstNumber%5) == (secondNumber%5)){
                //printf("\n%c %c",keyArray[((firstNumber+20)%25)/5][firstNumber%5],keyArray[((secondNumber+20)%25)/5][secondNumber%5]);
                afterDe+=(char)keyArray[((firstNumber+20)%25)/5][firstNumber%5];
                afterDe+=(char)keyArray[((secondNumber+20)%25)/5][secondNumber%5];
            }else{
                //printf("\n%c %c",keyArray[firstNumber/5][secondNumber%5],keyArray[secondNumber/5][firstNumber%5]);
                afterDe+=(char)keyArray[firstNumber/5][secondNumber%5];
                afterDe+=(char)keyArray[secondNumber/5][firstNumber%5];
            }
        }
        for(int i = 0 ; i < _str.length() ; i ++){
            switch( mark[i] ){
                case 0 :
                    break;
                case 1 :
                    afterDe.at(i)=afterDe.at(i);
                    break;
                case 2 :
                    afterDe.insert(i," ");
                    break;
            }
        }
        return afterDe;
    }
    return "(target is empty)";
}
