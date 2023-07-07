#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

class Duffing{
  public:

    double x0;
    double v0;
    double tmax;
    double dt;
    double a = 1.;
    double b = -1.;
    double c = 0.3;
    double d = 0.2;
    double omega = 1.;

    std::vector<double> res_t;   
	std::vector<double> res_x;   
	std::vector<double> res_v;

    Duffing(double x0, double v0, double tmax, double dt)
        : x0(x0), v0(v0), tmax(tmax), dt(dt)
    {}

  private:

    double Fx(double, double, double);
	double Fv(double, double, double);

  public:

    void Solve4();

};

double Duffing::Fx(double t, double x, double v){
    return v;
}

double Duffing::Fv(double t, double x, double v){
    return ( c*std::cos(omega*t) - d*v - b*x - a*std::pow(x,3.) );
}

void Duffing::Solve4(){

    res_t.push_back(0.);
	res_x.push_back(x0);
	res_v.push_back(v0);

	double x = x0;
	double v = v0;

    for(double t = dt; t <= tmax; t += dt)
	{
		x = x + dt * ( Fx(t, x, v) + Fx(t+(dt/2), x, v) );
		v = v + dt * Fv(t, x, v);
		
		res_t.push_back(t);
		res_x.push_back(x);
		res_v.push_back(v);
		
	}
}

int main(int argc, char *argv[])
{
	
	double tmax;
    std::istringstream(argv[1]) >> tmax;
	
	double dt;
    std::istringstream(argv[2]) >> dt;

    std::vector<double> x = {0.99, 1., 1.01};
    double v0 = 0.;
	
    for(auto &e : x){
        Duffing osc{e, v0, tmax, dt};
	    osc.Solve4();

        std::ofstream results("oscylator_duffing_" + std::to_string(e) + ".dat");
	
	    /*results << "Oscylator Duffinga: "
            << "$\\omega $ = " << osc.omega << ", "
            << "$x_0$ = " << osc.x0 << ", "
            << "$v_0$ = " << osc.v0 << ", "
            << "$t_\\mathrm{max}$ = " << osc.tmax << ", "
            << "$\\mathrm{d}t$ = " << osc.dt
            << std::endl;*/
        for(size_t i = 0; i < osc.res_x.size(); ++i)
        {
            results << osc.res_t[i] << " " << osc.res_x[i] << " " << osc.res_v[i] << std::endl;
        }		
        
        results.close();
    }

	return 0;
}