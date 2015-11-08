#include <iostream>

class Monoalphabetic
{
public:
    Monoalphabetic(std::string);
    void get_key(std::string input){
        antikey = "abcdefghijklmnopqrstuvwxyz";
        int mark[26] = {0};
        std::string get ="";
        for(int i = 0 ; i < input.length() ; i++){
            if( mark[input.at(i) - 'A'] == 0 ){
                get += input.at(i);
                antikey.at(input.at(i) - 'A') = i + 'A';
                mark[input.at(i) - 'A'] = 1;
            }
        }
        input = get;
        if(input.length() != 26){
            std::string change="";
            printf("key is been set to 26 length automatically(extend key with alphabet in order or get first differ 26 alphabet)");
            for(int i = 0 ; i < 26 ; i++){
                if(i < input.length()){
                    change += input.at(i);
                }else{
                    for(int j = 0 ; j < 26 ; j++){
                        if( mark[j] == 0){
                            change += j + 'A';
                            antikey.at(j) = i +'A' ;
                            mark[j] = 1;
                        }
                    }
                }
            }
            input = change ;
        }
        key = input;
    };
    void get_key(){
        std::string temp ="";
        char get = getchar();
        if(islower(get))get = toupper(get);
        while(get!='\n'){
            temp += get;
            get = getchar();
            if(islower(get))get = toupper(get);
        }
        get_key(temp);
    }
    std::string encrypt();
    std::string decrypt();
private:
    std::string origin;
    std::string afterCi;
    std::string afterDe;
    std::string key;
    std::string antikey;
};
