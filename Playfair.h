#ifndef PLAYFAIR
#define PLAYFAIR

#include <iostream>

class Playfair
{
public:
    Playfair(std::string str);
    void get_key();
    void get_key(std::string);
    void change_string(){
        char temp = getchar();
        std::string out="";
        while(temp != '\n'){
            out+=temp;
            temp=getchar();
        }
        origin = out;
    }
    std::string encrypt();
    std::string decrypt();
private:
    std::string origin;
    std::string afterCi;
    std::string afterDe;
    char keyArray[5][5];
};

#endif // PLAYFAIR

