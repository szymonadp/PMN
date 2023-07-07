#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>

int main(int argc, char* argv[]){

    std::string brackets = argv[1];
    std::stack<char> s;
    s.push('s');
    bool isBalanced = true;

    for(size_t i = 0; i<brackets.size(); i++){

        if(brackets.at(i) == '}'){
            if(s.top() != '{'){
                isBalanced = false;
                break;
            }
            s.pop();
        }
        else if(brackets.at(i) == ']'){
            if(s.top() != '['){
                isBalanced = false;
                break;
            }
            s.pop();
        }
        else if(brackets.at(i) == ')'){
            if(s.top() != '('){
                isBalanced = false;
                break;
            }
            s.pop();
        }
        else{
            s.push(brackets.at(i));
        }

    }

    if(isBalanced && s.size() == 1){
        std::cout << "Ciag zbalansowany." << std::endl;
    }
    else{
        std::cout << "Ciag niezbalansowany." << std::endl;
    }

    return 0;

}
