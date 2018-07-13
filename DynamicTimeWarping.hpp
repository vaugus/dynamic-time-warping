#ifndef _INC_DYNAMICTIMEWARPING_H
#define _INC_DYNAMICTIMEWARPING_H

#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <cstring>
#include <array>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, vector<double>> TimeSeries;
typedef vector<TimeSeries> TimeSeriesArray;

// Struct for a 3D coordinate object.
struct TimeSeries3D {
    int klass;
    TimeSeries x;
    TimeSeries y;
    TimeSeries z;
}; 

typedef struct TimeSeries3D TimeSeries3D;
typedef vector<TimeSeries3D> TimeSeries3DArray;

class DynamicTimeWarping {

    public:

        DynamicTimeWarping(double bandSize);
        ~DynamicTimeWarping();

        TimeSeriesArray loadTimeSeries(string filename);
        TimeSeries3DArray loadTimeSeries3D(string filename);

        double DTWDistance(TimeSeries s, TimeSeries t);
        double DTW_D_Distance(TimeSeries3D s, TimeSeries3D t);
        double DTWDistance3D(TimeSeries3D s, TimeSeries3D t);
        
        void classify(TimeSeriesArray trainingSet, TimeSeriesArray testSet);
        void classify3D(TimeSeries3DArray trainingSet, TimeSeries3DArray testSet);

    private:

        double bandSize;

        double euclideanDistance_D(double xa, double ya, double za, double xb, double yb, double zb);
        double euclideanDistance(double xa, double xb);
        double minimum(double a, double b, double c);


};

#endif