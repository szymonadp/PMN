#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

template <typename F>
bool ExNewton (double &x , F f , double x0 , double eps , int N = 1000){
    bool success = false;
    x = x0;
    auto devf = [f](double arg){
        double sm = 0.00001;
        return (f(arg+sm) - f(arg))/sm;
    };

    for(int i = 0; i < N; i++){
        double next = x - devf(x)*devf(x)/(devf(x+devf(x))-devf(x));
        if(std::abs(next - x)<eps){
            success = true;
            x = (x + next)/2;
            break;
        }
        x = next;
    }

    return success;
}

int main(int argc, char* argv[]){
    double x0 = atof(argv[1]);
    double eps = atof(argv[2]);
    int max_it = atoi(argv[3]);
    double x;
    bool success;
    
    std::vector<double> poli;
    double in;
    while(std::cin >> in){
        poli.push_back(in);
    }

    auto f = [&poli](double x){
        double result = 0;
        for(int i = 0; i<poli.size(); i++){
            result = result + poli.at(i)*pow(x,i);
        }
        return result;
    };

    success = ExNewton(x, f, x0, eps, max_it);

    if(success){
        std::cout << "Najblizsze ekstremum: " << x << " Wartosc funkcji: " << f(x) << std::endl;
        return 0;
    }
    else{
        std::cout << "Przekroczono limit iteracji." << std::endl;
        return 1;
    }

}