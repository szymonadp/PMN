#include<iostream>
#include<vector>

double Lagrange(const std::vector<double> & px, const std::vector<double> & py, double x){
    double wx = 0;
    double wi;

    for(int i = 0; i < px.size(); i++){
        wi = 1;
        for(int j = 0; j < px.size(); j++){
            if(j != i){
                wi = (x-px.at(j))/(px.at(i)-px.at(j))*wi;
            }
        }
        wx = wx + wi*py.at(i);
    }

    return wx;
}

int main(){
    std::vector<double> input;
    double in;

    while(std::cin >> in){
        input.push_back(in);
    }

    double x = input.at(0);

    std::vector<double> px;
    for(int i = 1; i < input.size(); i+=2){
        px.push_back(input.at(i));
    }

    std::vector<double> py;
    for(int i = 2; i < input.size(); i+=2){
        py.push_back(input.at(i));
    }

    std::cout << Lagrange(px, py, x) << std::endl;
 
    return 0;
}