#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

std::vector<double> DiffForwardP(const std::vector<double> &x, const std::vector<double> &y){
    std::vector<double> results;

    for(int i=0; i<x.size()-1; i++){
        results.push_back( (y.at(i+1) - y.at(i)) / (x.at(i+1) - x.at(i)));
    }

    return results;
}

std::vector<double> DiffCentralP(const std::vector<double> &x, const std::vector<double> &y){
    std::vector<double> results;

    for(int i=1; i<x.size()-1; i++){
        results.push_back( (y.at(i+1) - y.at(i-1)) / (x.at(i+1) - x.at(i-1)));
    }

    return results;
}

int main(int argc, char* argv[]){

    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> results;
    std::string type = argv[1];
    double in;

    while(std::cin >> in){
        x.push_back(in);
    }

    std::cin.clear();

    while(std::cin >> in){
        y.push_back(in);
    }

    std::cout << x.size() << std::endl;

    if(type == "forward"){
        results = DiffForwardP(x, y);
        std::cout << "x:  f'(x):" << std::endl;
        for(int i = 0; i<x.size()-1; i++){
            std::cout << x.at(i) << "  " << results.at(i) << std::endl;
        }
    }
    else if(type == "central"){
        results = DiffCentralP(x, y);
        std::cout << "x:  f'(x):" << std::endl;
        for(int i = 1; i<x.size()-1; i++){
            std::cout << x.at(i) << "  " << results.at(i-1) << std::endl;
        }
    }
    else{
        std::cout << "Zla komenda." << std::endl;
        return 1;
    }


    return 0;
}