#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

static std::mt19937_64 rng;

//zad1
struct Point {
    constexpr explicit Point(double x = 0.00, double y = 0.00, double z = 0.00) : x(x), y(y), z(z) {}

    double x;
    double y;
    double z;
};

constexpr auto distance(Point point) {
    return sqrt(pow((point.x - 0.00), 2) + pow((point.y - 0.00), 2) + pow(point.z - 0.00, 2));
}

auto makePoint(double range1 = -1.00, double range2 = 1.00) {
    std::uniform_real_distribution<> zero_one(range1, range2);
    return Point((zero_one(rng)), (zero_one(rng)), (zero_one(rng)));
}

double symulaion(int N, double P, int &S) {
    for (auto i{0}; i < N; i++)
    {
        if (distance(makePoint()) <= 1)
        {
            S++;
        }
    }
    return (S / static_cast<double>(N)) * pow(P, 3);
}

auto resultZad1() {
    constexpr auto bok{2};
    constexpr auto N_1{100};
    constexpr auto N_2{10000};
    constexpr auto N_3{1000000};
    int S1 = 0;
    int S2 = 0;
    int S3 = 0;

    constexpr auto rightVolumeofBall{(4.00 / 3.00) * M_PI * pow((bok / 2.00), 3)};

    std::cout << " Right Volume of Ball : " << rightVolumeofBall
              << std::endl << " Calculated Volume of Ball : " << symulaion(N_1, bok, S1)
              << std::endl << "number of throws : " << N_1;
    std::cout << " number of hits : " << S1 << std::endl;
    std::cout << std::endl << " Calculated Volume of Ball : " << symulaion(N_2, bok, S2)
              << std::endl << "number of throws : " << N_2;
    std::cout << " number of hits : " << S2 << std::endl;
    std::cout << std::endl << " Calculated Volume of Ball : " << symulaion(N_3, bok, S3)
              << std::endl << "number of throws : " << N_3 ;
    std::cout << " number of hits : " << S3 << std::endl;
}

//zad2
auto distanceZad2(std::vector<double> points) {
    double result {0};
    for(const auto& i : points)
        result += pow((i - 0.00), 2);
    return sqrt(result);
}

auto makePointZad2(double range1 = -1.00, double range2 = 1.00) {
    std::uniform_real_distribution<> zero_one(range1, range2);
    std::vector<double> result;
    for(auto i {0}; i < 15; i++)
        result.push_back(zero_one(rng));
    return std::move(result);
}

double symulaionZad2(int N, double P, int &S) {
    for (auto i{0}; i < N; i++)
        if (distanceZad2(makePointZad2()) <= 1)
            S++;
    return (static_cast<double>(S) / static_cast<double>(N)) * pow(P, 15);
}

auto resultZad2() {
    constexpr auto bok{2};
    constexpr auto N_1{100};
    constexpr auto N_2{10000};
    constexpr auto N_3{1000000};
    auto S1{0};
    auto S2{0};
    auto S3{0};

    constexpr auto rightVolumeofFigure{ (pow( M_PI, (15.00 / 2.00)) / tgamma((15.00 / 2.00) + 1.00)) * pow((bok / 2.00), 15.00) };

    std::cout << " Right Volume of Figure : " << rightVolumeofFigure
              << std::endl << " Calculated Volume of Figure : " << symulaion(N_1, bok, S1)
              << std::endl << "number of throws : " << N_1;
    std::cout << " number of hits : " << S1 << std::endl;
    std::cout << std::endl << " Calculated Volume of Figure : " << symulaion(N_2, bok, S2)
              << std::endl << "number of throws : " << N_2;
    std::cout << " number of hits : " << S2 << std::endl;
    std::cout << std::endl << " Calculated Volume of Figure : " << symulaion(N_3, bok, S3)
              << std::endl << "number of throws : " << N_3 ;
    std::cout << " number of hits : " << S3 << std::endl;
}

//zad3
auto resultZad3()
{
    constexpr auto xmin {-2.00};
    constexpr auto xmax {2.00};
    constexpr auto N {100000};
    auto result {0.00};

    std::uniform_real_distribution<double> zero_one(xmin, xmax);
    for(auto i {0}; i < N; i++) {
        double point {zero_one(rng)};
        result += 1 / sqrt(2 * M_PI) * exp((-point*point)/2);
    }
    std::cout << result / N * 4 << std::endl;
}

//zad4
auto symulation(auto N)
{
    double success {0.00};
    std::vector<int> cards(N);

    for(auto i {0}; i < cards.size(); i++)
        cards.at(i) = i;

    std::shuffle(cards.begin(),cards.end(),rng);

    for(auto i {0}; i < cards.size(); i++)
        if (cards.at(i) == i)
            success++;
    return success;
}

auto resultZad4()
{
    double n100 {0};
    double n10000 {0};
    double n1000000 {0};
    for(auto i {0}; i < 100; i++)
        n100 += symulation(100);

    for(auto i {0}; i < 10000; i++)
        n10000 += symulation(100);

    for(auto i {0}; i < 1000000; i++)
        n1000000 += symulation(100);

    std::cout << "success when N = 100 : " << n100/100.00 << std::endl;
    std::cout << "success when N = 10000 : " << n10000/10000.00 << std::endl;
    std::cout << "success when N = 1000000 : " << n1000000/1000000.00 << std::endl;
}

int main() {
    rng.seed(static_cast<unsigned long long int>(time(nullptr)));
    //resultZad1();
    //resultZad2();
    //resultZad3();
    //resultZad4();

    return 0;
}