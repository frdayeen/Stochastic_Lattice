#include "rectangle.h"



//V1=random
//v2=mersentwister
//v3=pseudorandom differentway
//v4=box
//v5=cout fixed
//v6=rect
//v7= boost random



void Rect_Print() {
    ofstream rectangleOut;
    rectangleOut.open ("Rectangle.txt");


    double TotalArea = 0.0;
    cout<<endl;

    cout<<"In counter-clockwise fashion"<<endl;
    cout<<"#Rectangle    (    x0,    y0)    (    x1,    y1)      Area"<<endl;
    for (int b=0; b<Rect_Count; b++) {
        double Area = (Rect[b].x0 - Rect[b].x1) * (Rect[b].y0 - Rect[b].y1);

        cout<<fixed<<setprecision(4)<< (b+1)<<"             ("<<Rect[b].x0<<","<<Rect[b].y0<<")    ("<<Rect[b].x1<<","<<Rect[b].y1<<")    "<<Area<<endl;
        rectangleOut<< (b+1)<<"             ("<<Rect[b].x0<<","<<Rect[b].y0<<")    ("<<Rect[b].x1<<","<<Rect[b].y1<<")    "<<Area<<endl;

        TotalArea += Area;


    }
    rectangleOut.close();
    cout<<"Number of divisions (N = 3j-2) = "<<Rect_Count << ",    Total Area = "<<TotalArea<<endl;
}

int main(int argc, char *argv[]) {
    Rect_Init();
    for (int rcount = 0; rcount < 10; rcount++) {
        Rect_Print();
        double x = rnd();
        double y = rnd();
        int b = Rect_Find(x, y);
        Rect_Divide(b, x, y);
    }
    Rect_Print();
    return 0;
}