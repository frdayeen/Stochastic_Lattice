//
// Created by Fazle R Dayeen on 4/19/16.
//

#ifndef STOCHASTIC_LATTICE_RECTANGLE_H
#define STOCHASTIC_LATTICE_RECTANGLE_H

#endif //STOCHASTIC_LATTICE_RECTANGLE_H

#include <cctype>
#include <cstdlib>
#include <iostream> // std cout
#include <memory.h>
#include <iomanip> // setpresion(4) for the fixed 4 values after decimal
#include <ctime> // seed time
#include <boost/random.hpp> // boost
#include <fstream> //file i/o


using namespace std;
using namespace boost;

double rnd(void)
{
    mt19937 rng(time(0));
    static uniform_01<mt19937> myrand(rng);
    return myrand();
}


typedef struct Rect_s {
    double x0, y0, x1, y1;
} Rect_t;

#define Rect_N (303) //Need to Change if we need more than 303 boxes
int Rect_Count = 0;
Rect_t Rect[Rect_N];

// Initial value of rectangle
void Rect_Init() {
    memset(Rect, 0, sizeof(Rect));
    Rect[0].x0 = 0.0; //initial value x0
    Rect[0].y0 = 0.0; //initial value y0
    Rect[0].x1 = 1.0; //initial value x1
    Rect[0].y1 = 1.0; //initial value y1
    Rect_Count = 1;
}
//search where the random numbers are
int Rect_Find(double x, double y) {
    for (int b=0; b<Rect_Count; b++) {
        if ((Rect[b].x0 < x) && (x < Rect[b].x1) && (Rect[b].y0 < y) && (y < Rect[b].y1)) {
            return b; // return the number of box if the point is not overlapped
        }
    }

    cout<<fixed<<setprecision(4)<< "Rectangle not found"<<x <<" "<< y<<endl;
    exit(1);
}


//Divide the rectangles
void Rect_Divide(int b, double x, double y) {
    if ((Rect[b].x0 < x) && (x < Rect[b].x1) && (Rect[b].y0 < y) && (y < Rect[b].y1)) {
        // Make 3 more Rectes
        if ((Rect_Count + 3) >= Rect_N) {

            cout<< "Not enough rectangles"<<endl;
            exit(1);
        }
        Rect[Rect_Count].x0 = x;
        Rect[Rect_Count].x1 = Rect[b].x1;
        Rect[Rect_Count].y0 = Rect[b].y0;
        Rect[Rect_Count].y1 = y;
        Rect_Count++;
        Rect[Rect_Count].x0 = x;
        Rect[Rect_Count].x1 = Rect[b].x1;
        Rect[Rect_Count].y0 = y;
        Rect[Rect_Count].y1 = Rect[b].y1;
        Rect_Count++;

        Rect[Rect_Count].x0 = Rect[b].x0;
        Rect[Rect_Count].x1 = x;
        Rect[Rect_Count].y0 = y;
        Rect[Rect_Count].y1 = Rect[b].y1;
        Rect_Count++;
        // Update original rectangle
        Rect[b].x1 = x;
        Rect[b].y1 = y;
        return;
    }

    cout<<fixed<<setprecision(4)<<"x y not in rectangle-"<<b<< " "<<x<< " "<<y<<endl;
    exit(1);
}
