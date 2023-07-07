#include<iostream>
#include<random>
#include<numeric>
#include<cmath>

template <typename RNG>
void DeMere(double & pA, double & pB, size_t N){

    std::random_device seed;
    RNG rng(seed());
    std::uniform_int_distribution<int> uni(1, 6);

    int counterA = 0;
    int counterB = 0;

    for(size_t i = 0; i<N; i++){

        for(size_t j = 0; j<4; j++){
            if(uni(rng) == 6){
                counterA ++;
                break;
            }
        }

        for(size_t j = 0; j<24; j++){
            if(uni(rng) == 6 && uni(rng) == 6){
                counterB ++;
                break;
            }
        }    
    }

    pA = static_cast<double>(counterA) / N;
    pA = static_cast<double>(counterB) / N;

    std::cout << "Oszacowane prawdopodobienstwo A: " << static_cast<double>(counterA)/N << std::endl;
    std::cout << "Oszacowane prawdopodobienstwo B: " << static_cast<double>(counterB)/N << std::endl;

}

int main(){

    double pA = 0.0;
    double pB = 0.0;
    int N = 1000000;

    DeMere<std::mt19937>(pA, pB, N);

    double acc_pA = 1 - pow(5./6., 4);
    double acc_pB = 1 - pow(35./36., 24);

    std::cout << "Faktyczne prawdopodobienstwo A: " << acc_pA << std::endl;
    std::cout << "Faktyczne prawdopodobienstwo B: " << acc_pB << std::endl;

    return 0;
}