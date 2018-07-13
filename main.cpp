#include <iostream>

#include "DynamicTimeWarping.hpp"

using namespace std;

main(int argc, char **argv) {

    if (argc < 2) {
        cout << "You must choose between 1D (1) or 3D (3) DTW and set a band value..." << endl;
        exit(1);
    }

    int method = atoi(argv[1]);

    double bandSize = strtof(argv[2], 0);

    DynamicTimeWarping *dtw = new DynamicTimeWarping(bandSize);

    clock_t begin = clock();

    if (method == 1) {
        TimeSeriesArray trainingSet = dtw->loadTimeSeries("input/treino.txt");
        TimeSeriesArray testSet = dtw->loadTimeSeries("input/teste.txt");

        dtw->classify(trainingSet, testSet);

    }

    if (method == 3) {
        TimeSeries3DArray trainingSet3D = dtw->loadTimeSeries3D("input/treino3D.txt");
        TimeSeries3DArray testSet3D = dtw->loadTimeSeries3D("input/teste3D.txt");

        dtw->classify3D(trainingSet3D, testSet3D);
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Elapsed Time: " << elapsed_secs << endl;
}
