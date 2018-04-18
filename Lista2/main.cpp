#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

std::mt19937_64 rng;

//zad1
auto zad1(unsigned N = 100, int NN = 1000)
{
    std::ofstream myExcelFile;
    myExcelFile.open("zad1a.csv");

    auto polozenie{0.0};
    std::uniform_int_distribution<int> zero_one(-1, 0);

    for (auto j{0}; j < NN; j++)
    {
        polozenie += zero_one(rng) * 2 + 1;
        myExcelFile << 1 << "\t" << polozenie << "\t" << std::endl;
    }
    myExcelFile.close();

    polozenie = 0; 

    std::ofstream myExcelFile2;
    myExcelFile2.open("zad1b.csv");

    for (auto i{0}; i < N; i++)
    {
        for (auto j{0}; j < NN; j++)
	{
            polozenie += zero_one(rng) * 2 + 1;
	}
        myExcelFile2 << i << "\t" << polozenie << std::endl;
        polozenie = 0;
    }
    myExcelFile2.close();
}
/*
auto zad2(double p = 1.3, int N = 100, int NN = 1000) {

    std::vector<std::vector<std::tuple<double, double, double, double> > > pts(NN, std::vector<std::tuple<double, double, double, double>>(N));
    double polozenie{0.00};
    double suma{0.00};
    double srednia{0.00};
    double odchylenie{0.00};
    std::uniform_int_distribution<int> zero_one(-1, 0);
    for (auto i{0}; i < pts.size(); i++) {
        for (auto j{0}; j < pts.at(i).size(); j++)
        {
            pts.at(i).at(j) = std::make_tuple(j, polozenie, 1, 1);
            polozenie += (zero_one(rng) * 2 + 1) * p;
        }
        suma += polozenie;
        polozenie = 0;
    }

    srednia = suma / NN;
    suma = 0;

    for (auto i{0}; i < pts.size(); i++) {
        for (auto j{0}; j < pts.at(i).size(); j++) {
            suma = suma + pow((std::get<1>(pts.at(i).at(j)) - srednia), 2);
        }
    }
    odchylenie = sqrt(suma / NN);
    std::cout << "odchylenie standardowe : " << odchylenie << std::endl;

}

//zad3
auto zad3Obliczenia(int poczatkowePolozenie = 0, int a = 5, int N = 100, int NN = 10000){
    Gnuplot gp;
    double suma {0.00};
    std::vector<std::vector<std::tuple<int, int, int, int> > > pts(N,
                                                                     std::vector<std::tuple<int, int, int, int>>(NN));
    int polozenie{poczatkowePolozenie};
    int polozeniej{0};
    std::uniform_int_distribution<int> zero_one(-1, 0);
    for (auto i{0}; i < pts.size(); i++) {
        for (auto j{0}; j < pts.at(i).size(); j++) {
            if(polozenie <= 0)
                pts.at(i).at(j) = std::make_tuple(polozeniej, polozenie+1, 1, 1);
            else if(polozenie >= 2*a)
                pts.at(i).at(j) = std::make_tuple(polozeniej, polozenie-1, 1, 1);
            else
            {
                suma++;
                pts.at(i).at(j) = std::make_tuple(j, polozenie, 1, 1);
                polozenie += zero_one(rng) * 2 + 1;
                polozeniej = j;
            }
        }
        polozenie = poczatkowePolozenie;
    }
    std::cout << "poczatkowe polozenie : " << poczatkowePolozenie << " srednie suma/N : " << suma/N << std::endl;
    std::string plot{"plot "};
    for (auto i{0}; i < N; i++)
        plot += " '-' with lines title '', ";
    plot += "\n";
    gp << "set xrange [-1:101]\nset yrange [-1:11]\n";
    gp << plot;
    for (const auto &i : pts)
        gp.send1d(i);
    return suma/N;
}

auto zad3()
{
    Gnuplot gp;
    std::vector<std::tuple<int, int, int, int> >  pts;
    for( auto i {1}; i < 2*5; i++)
        pts.push_back(std::make_tuple(i, zad3Obliczenia(i), 1, 1));
    gp << "set xrange [0:11]\nset yrange [0:30]\n";
    gp << "plot '-' with lines title ''\n";
    gp.send1d(pts);
}
*/
int main() {
    rng.seed(static_cast<unsigned long>(time(nullptr)));
    zad1();
    //zad2();
    //zad2(0.7);
    //zad3();

    return 0;
}
