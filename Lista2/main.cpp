#include <iostream>
#include <random>
#include <ctime>
#include "gnuplot-iostream/gnuplot-iostream.h"

std::mt19937_64 rng;

//zad1
auto zad1(int N = 100, int NN = 10000) {

    Gnuplot gp;
    std::vector<std::vector<boost::tuple<int, int, int, int> > > pts(NN, std::vector<boost::tuple<int, int, int, int>>(N));
    int polozenie {0};
    std::uniform_int_distribution<int> zero_one(-1, 0);
    for(auto i {0}; i < pts.size(); i++)
    {
        for(auto j {0}; j < pts.at(i).size(); j++)
        {
            pts.at(i).at(j) = boost::make_tuple(j,polozenie,1,1);
            polozenie += zero_one(rng)*2+1;
        }
        polozenie = 0;
    }
    std::string plot {"plot "};
    for(auto i {0}; i < NN; i++)
        plot += " '-' with lines title '', ";
    plot += "\n";
    gp << "set xrange [-1:101]\nset yrange [-40:40]\n";
    gp << plot;
    for(const auto& i : pts)
        gp.send1d(i);

}

auto zad2(double p = 1.3, int N = 100, int NN = 100) {

    Gnuplot gp;
    std::vector<std::vector<boost::tuple<double, double, double, double> > > pts(NN, std::vector<boost::tuple<double, double, double, double>>(N));
    double polozenie {0.00};
    std::uniform_int_distribution<int> zero_one(-1, 0);
    for(auto i {0}; i < pts.size(); i++)
    {
        for(auto j {0}; j < pts.at(i).size(); j++)
        {
            pts.at(i).at(j) = boost::make_tuple(j,polozenie,1,1);
            polozenie += (zero_one(rng)*2+1)*p;
        }
        polozenie = 0;
    }
    std::string plot {"plot "};
    for(auto i {0}; i < NN; i++)
        plot += " '-' with lines title '', ";
    plot += "\n";
    gp << "set xrange [-1:101]\nset yrange [-40:40]\n";
    gp << plot;
    for(const auto& i : pts)
        gp.send1d(i);

}
int main() {
    rng.seed(static_cast<unsigned long>(time(nullptr)));
    //zad1();
    zad2();
    zad2(0.7);
    return 0;
}