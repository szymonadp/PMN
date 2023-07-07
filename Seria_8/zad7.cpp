
// PROGRAM NIE DZIALA ZGODNIE Z ZALOZENIEM, ALE NIE WIEM DLACZEGO

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stack>

int priority(std::string e){
    int pri;
    if(e == "^"){
        pri = 3;
    } 
    if(e == "*" || e == "/"){
        pri = 2;
    } 
    if(e == "+" || e == "-" || e == ")"){
        pri = 1;
    } 
    if(e == "("){
        pri = 0;
    } 
    return pri;
}

std::vector<std::string> convert(std::vector<std::string> trad){
    
    std::vector<std::string> rpn;
    std::stack<std::string> s;
    int topPri = 0;

    for(auto &e : trad){
        if(e == "("){
            s.push(e);
        }
        else if(e == "^" || e == "*" || e == "/" || e == "+" || e == "-"){
            while(priority(e) <= topPri){
                rpn.push_back(s.top());
                s.pop();
                if(s.size() > 0){
                    topPri = priority(s.top());
                } else{
                    topPri = 0;
                }
            }
            s.push(e);
        }
        else if(e == ")"){
            while(priority(e) <= topPri){
                rpn.push_back(s.top());
                s.pop();
                if(s.size() > 0){
                    topPri = priority(s.top());
                } else{
                    topPri = 0;
                }
            }
            s.pop();
        }
        else{
            rpn.push_back(e);
        }
        if(s.size() > 0){
            topPri = priority(s.top());
        }

    }

    for(int i = 0; i<s.size(); i++){
        rpn.push_back(s.top());
        s.pop();
    }

    return rpn;
}

int main(){
    
    while(true){
        std::string input;
        std::cout << "> ";
        std::getline(std::cin, input);

        std::vector<std::string> trad;
        std::istringstream iss(input);
        std::string in;
        while(iss >> in){
            trad.push_back(in);
        }

        if(input == "exit"){
            break;
        }
        else{
            std::vector<std::string> rpn = convert(trad);
            std::stack<std::string> calc;
            calc.push("0");
            calc.push("0");
            for(auto &e : rpn){
                std::cout << e << " ";
            }
            std::cout << std::endl;
            for(auto &e : rpn){
                if(e == "+"){
                    double a = std::stod(calc.top());
                    calc.pop();
                    double b = std::stod(calc.top());
                    calc.pop();
                    calc.push(std::to_string(a+b));
                }
                if(e == "-"){
                    double a = std::stod(calc.top());
                    calc.pop();
                    double b = std::stod(calc.top());
                    calc.pop();
                    calc.push(std::to_string(a-b));
                }
                if(e == "*"){
                    double a = std::stod(calc.top());
                    calc.pop();
                    double b = std::stod(calc.top());
                    calc.pop();
                    calc.push(std::to_string(a*b));
                }
                if(e == "/"){
                    double a = std::stod(calc.top());
                    calc.pop();
                    double b = std::stod(calc.top());
                    calc.pop();
                    calc.push(std::to_string(a/b));
                }
                else{
                    calc.push(e);
                }
            }

            std::cout << "Wynik: " << calc.top() << std::endl;
            calc.pop();
        }
    }

    return 0; 
}