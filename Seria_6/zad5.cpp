#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

std::string Caesar(int n, const std::string &str){
    std::string out;

    for(int i = 0; i < str.length(); i++){

        int ascii = (int)str.at(i);

        if(ascii>='A' && ascii<='Z'){
            out.push_back((char)('A' + ((ascii - 'A' + n) % 26)));
        }
        else if(ascii>='a' && ascii<='z'){
            out.push_back((char)('a' + ((ascii - 'a' + n) % 26)));
        }
        else{
            out.push_back(str.at(i));
        }
    }
    return out;
}

int main(int argc, char *argv[]){

    std::string command = argv[1];
    int count = atoi(argv[2]);
    std::string input_file = argv[3];
    std::string output_file = argv[4];

    std::ifstream in(input_file);
    std::ofstream out(output_file);
    std::string line;

    if(command == "-e"){
        while(std::getline(in, line)){
            out << Caesar(count, line) << std::endl;
        }
    }
    else if(command == "-d"){
        while(std::getline(in, line)){
            out << Caesar(26-count, line) << std::endl;
        }
    }
    else{
        std::cout << "u kill me" << std::endl;
        in.close();
        out.close();
        return 1;
    }

    in.close();
    out.close();

    return 0;

}