#include "Reservior.h"

int main() {
    Reservior r;
    Reservior r1(12,12,12,"lake");
    Reservior r2(82,13,126,"lake");
    Reservior r3(82,13,126,"lake");
    Reservior r4(86,16,122,"lake");
    r.setLength(10);
    r.setWidth(10);
    r.setMax_depth(10);
    r.setType("sea");
    cout << r.getLength() << " " << r.getWidth() << " " << r.getMax_depth() << " " << r.getType() << '\n';
    cout << r.approximate_volume() << " " << r.calc_area() << endl;
    cout << r.isTheSameType(r1) << " ";
    cout << r1.isTheSameType(r2) << " " << endl;
    cout << r.area_comparison(r1) << " " << r2.area_comparison(r3) << " " << r3.area_comparison(r4) << r4.area_comparison(r3) << endl;
    Reservior p;
    p.copyObj(r4);
    cout << p.getLength() << " " << p.getWidth() << " " << p.getMax_depth() << " " << p.getType() << '\n';
    p.writeToFile();
    return 0;
}