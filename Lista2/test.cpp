#include <vector>
//#include "gnuplot-iostream.h"

#include "../gnuplot-iostream/gnuplot-iostream.h"

struct Data {
    std::string datestr;  // x axis value
    float f1;             // y axis series 1
    float f2;             // y axis series 2
    float f3;             // y axis series 3
};

typedef std::vector<Data> Dataset;

namespace gnuplotio {
    template<>
    struct TextSender<Data> {
        static void send(std::ostream &stream, const Data &v) {
            TextSender<std::string>::send(stream, v.datestr);
            stream << " ";
            TextSender<float>::send(stream, v.f1);
            stream << " ";
            TextSender<float>::send(stream, v.f2);
            stream << " ";
            TextSender<float>::send(stream, v.f3);

            // This works too, but the longer version above gives
            // gnuplot-iostream a chance to format the numbers itself (such as
            // using a platform-independent 'nan' string).
            //stream << v.datestr << " " << v.f1 << " " << v.f2 << " " << v.f3;
        }
    };
}

int main() {
    Dataset x(2);
    // The http://www.gnuplot.info/demo/timedat.html example uses a tab between
    // date and time, but this doesn't seem to work (gnuplot interprets it as
    // two columns).  So I use a comma.
    x[0].datestr = "01/02/2003,12:34";
    x[0].f1 = 1;
    x[0].f2 = 2;
    x[0].f3 = 3;
    x[1].datestr = "02/04/2003,07:11";
    x[1].f1 = 10;
    x[1].f2 = 20;
    x[1].f3 = 30;

    /*Gnuplot gp;
    gp << "set timefmt \"%d/%m/%y,%H:%M\"\n";
    gp << "set xdata time\n";
    gp << "plot '-' using 1:2 with lines\n";
    gp.send1d(x);*/

    Gnuplot gp;

    gp << "set terminal png\n";

    std::vector<double> y_pts;
    for(int i=0; i<1000; i++) {
        double y = (i/500.0-1) * (i/500.0-1);
        y_pts.push_back(y);
    }

    gp << "set output 'my_graph_1.png'\n";
    gp << "set style histogram\n";
    gp << "plot with boxes\n";
    gp.send(y_pts);

    return 0;
}