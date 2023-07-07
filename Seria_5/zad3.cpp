#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>

template<typename F>
double NormalEst(F f, int n, double sigma, double mu, bool &proper){
    double results = 0;

    if(n==2){
        std::vector <double> w = {0.8862269254527580136491, 0.886226925452758013649};
        std::vector <double> x = {-0.7071067811865475244008, 0.7071067811865475244008};
        for(int i = 0; i<n; i++){
            results = results + w.at(i)*f(std::sqrt(2)*sigma*x.at(i) + mu);
        }
        proper = true;
    }
    else if(n==3){
        std::vector <double> w = {0.295408975150919337883, 1.181635900603677351532, 0.295408975150919337883};
        std::vector <double> x = {-1.224744871391589049099, 0, 1.224744871391589049099};
        for(int i = 0; i<n; i++){
            results = results + w.at(i)*f(std::sqrt(2)*sigma*x.at(i) + mu);
        }
        proper = true;
    }
    else if(n==4){
        std::vector <double> w = {0.081312835447245177143, 0.8049140900055128365061, 0.8049140900055128365061, 0.08131283544724517714303};
        std::vector <double> x = {-1.650680123885784555883, -0.5246476232752903178841, 0.5246476232752903178841, 1.650680123885784555883};
        for(int i = 0; i<n; i++){
            results = results + w.at(i)*f(std::sqrt(2)*sigma*x.at(i) + mu);
        }
        proper = true;
    }
    else if(n==5){
        std::vector <double> w = {0.01995324205904591320774, 0.3936193231522411598285,0.9453087204829418812257, 0.393619323152241159828, 0.01995324205904591320774};
        std::vector <double> x = {-2.020182870456085632929, -0.9585724646138185071128, 0, 0.9585724646138185071128, 2.020182870456085632929};
        for(int i = 0; i<n; i++){
            results = results + w.at(i)*f(std::sqrt(2)*sigma*x.at(i) + mu);
        }
        proper = true;
    }
    else{
        std::cout << "Dla tego n nie umiem :(" << std::endl;
    }

    double pi = 3.14159265358979323846;
    return results/std::sqrt(pi);

}

int main(int argc, char* argv[]){
    int n = std::atoi(argv[1]);

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

    double result;
    bool proper = false;
    double sigma = 1;
    double mu = 0;
    result = NormalEst(f, n, sigma, mu, proper);

    if(proper){
        std::cout << "Wynik: " << result << std::endl;
        return 0;
    }
    else{
        std::cout << "Cos poszlo nie tak." << std::endl;
        return 1;
    }
    
}