#include <iostream>
#include <vector>
#include <random>
#include <tuple>
#include "../gnuplot-iostream/gnuplot-iostream.h"

std::mt19937_64 rng;

//zad1
struct Point{
    constexpr explicit Point(int x = 0, int y = 0): x(x), y(y)
    {}
    int x;
    int y;
};

auto zad1(int N = 100, int NN = 10000){
    Gnuplot gp;
    Point point;
    std::vector<std::vector<std::tuple<int, int, int, int> > > pts(NN,
                                                                   std::vector<std::tuple<int, int, int, int>>(N));
    auto wzerozero {0};
    std::uniform_int_distribution<int> zero_one(-2, 1);
    for (auto i{0}; i < pts.size(); i++) {
        for (auto j{0}; j < pts.at(i).size(); j++) {
            pts.at(i).at(j) = std::make_tuple(point.x, point.y, 1, 1);
            auto rand {zero_one(rng)};
            switch (rand)
            {
                case -2:
                    point.x--;
                    break;
                case -1:
                    point.x++;
                    break;
                case -0:
                    point.y--;
                    break;
                case 1:
                    point.y++;
                    break;
                default:
                    break;
            }
            if(point.x == 0 && point.y == 0)
                wzerozero++;
        }
    }
    std::cout << "ile wrocilo do srodka : " << wzerozero << std::endl;
    std::string plot{"plot "};
    for (auto i{0}; i < NN; i++)
        plot += " '-' with lines title '', ";
    plot += "\n";
    gp << "set autoscale\n";
    gp << plot;
    for (const auto &i : pts)
        gp.send1d(i);
}

//zad2
auto zad2(){

}

int main() {
    rng.seed(static_cast<unsigned long>(time(nullptr)));
    zad1();

    return 0;
}