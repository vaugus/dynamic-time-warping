#include "DynamicTimeWarping.hpp"

const double infinity = numeric_limits<double>::infinity();

using namespace std;

/**
 * Constructor.
 */
DynamicTimeWarping::DynamicTimeWarping(double bandSize) {
    this->bandSize = bandSize;
}

/**
 * Destructor.
 */ 
DynamicTimeWarping::~DynamicTimeWarping() {
    delete this;
}

/**
 * =========================================================================================================================
 * =========================================================================================================================
 * ONE-DIMENSIONAL CASE METHODS
 * =========================================================================================================================
 * =========================================================================================================================
 */ 

double DynamicTimeWarping::DTWDistance(TimeSeries s, TimeSeries t) {
    int m = s.second.size();
    int n = t.second.size();

    if (bandSize == -1) {
        double DTW[m][n];

        for (int i = 0; i < m; i++) {
            DTW[i][0] = infinity;
        }

        for (int i = 0; i < n; i++) {
            DTW[0][i] = infinity;
        }

        DTW[0][0] = 0;
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                double cost = euclideanDistance(s.second[i], t.second[j]);
                DTW[i][j] = cost +  minimum(DTW[i-1][j],        // insertion
                                            DTW[i][j-1],        // deletion
                                            DTW[i-1][j-1]);     // match
            }
        }

        return DTW[m-1][n-1];

    } else {

        int w = static_cast<int>(bandSize * (max(m, n)));
        int constraint = abs(m-n);
        w = max(w, constraint);

        double DTW[m][n];

        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		DTW[i][j] = infinity;
            }
        }

        DTW[0][0] = 0;

        for (int i = 1; i < m; i++) {
            for (int j = max(1, i - w); j < min(n, i + w); j++) {
                double cost = euclideanDistance(s.second[i], t.second[j]);
                DTW[i][j] = cost +  minimum(DTW[i-1][j],        // insertion
                                            DTW[i][j-1],        // deletion
                                            DTW[i-1][j-1]);     // match
            }
        }
    
        return DTW[m-1][n-1];
    }
}

TimeSeriesArray DynamicTimeWarping::loadTimeSeries(string filename) {
    string str;
    string delim = " ";
    ifstream file (filename);

    int klass = 0;

    TimeSeriesArray timeSeriesArray;
    vector<double> values;

    if (file.is_open()) {
        while (getline (file, str, '\n')) {

            auto start = 0;
            auto end = str.find(delim);
            while (end != string::npos) {

                double val = strtof(str.substr(start, end - start).c_str(), 0);

                if (start == 0) {
                    klass = int(val);
                } else {
                    values.push_back(val);
                }

                start = end + delim.length();
                end = str.find(delim, start);
            }

            timeSeriesArray.push_back(make_pair(klass, values));
            values.clear();
        }
        file.close();
    }

    return timeSeriesArray;
}

double DynamicTimeWarping::minimum(double a, double b, double c) {
    if ((a < b) && (a < c)) {
        return a;
    }

    if ((b < a) && (b < c)) {
        return b;
    }

    if ((c < a) && (c < b)) {
        return c;
    }
}

double DynamicTimeWarping::euclideanDistance(double xa, double xb) {
    return abs(xa - xb);
}

void DynamicTimeWarping::classify(TimeSeriesArray trainingSet, TimeSeriesArray testSet) {

    double acc = 0;

    for (int i = 0; i < testSet.size(); i++) {
        double smaller = infinity;
        int nearestNeighbourClass = 0;
  
        for (int j = 0; j < trainingSet.size(); j++) {

            double dtwDistance = DTWDistance(testSet[i], trainingSet[j]);

            if (dtwDistance < smaller) {
                smaller = dtwDistance;
                nearestNeighbourClass = trainingSet[j].first;
            }
        }

        if (nearestNeighbourClass == testSet[i].first) {
            acc++;
        }
    }

    cout << "Total: " << testSet.size() << endl;
    cout << "Correct Ones: " << (int) acc << endl;
    cout << "Accuracy: " << acc / testSet.size() * 100 << char(37) << endl;
}

/**
 * =========================================================================================================================
 * =========================================================================================================================
 * THREE-DIMENSIONAL CASE METHODS
 * =========================================================================================================================
 * =========================================================================================================================
 */ 

TimeSeries3DArray DynamicTimeWarping::loadTimeSeries3D(string filename) {
    string str;
    string delim = " ";
    ifstream file (filename);

    int klass = 0;

    TimeSeries3DArray timeSeries3DArray;
    vector<double> x;
    vector<double> y;
    vector<double> z;

    if (file.is_open()) {
        while (getline (file, str, '\n')) {

            auto start = 0;
            auto end = str.find(delim);
            int i = 0;
            TimeSeries3D timeSeries3D;
            while (end != string::npos) {

                double val = strtof(str.substr(start, end - start).c_str(), 0);

                if (start == 0) {
                    klass = int(val);
                } 

                if (i == 1) {
                    x.push_back(val);
                }
                
                if (i == 2) {
                    y.push_back(val);
                }
                
                if (i == 3) {
                    z.push_back(val);
                    i = 0; 
                }

                i++;
                
                start = end + delim.length();
                end = str.find(delim, start);
            }

            timeSeries3D.x = make_pair(klass, x);
            timeSeries3D.y = make_pair(klass, y);
            timeSeries3D.z = make_pair(klass, z);
            timeSeries3D.klass = klass;

            timeSeries3DArray.push_back(timeSeries3D);

            x.clear();
            y.clear();
            z.clear();
        }
        file.close();
    }

    return timeSeries3DArray;
}

double DynamicTimeWarping::DTWDistance3D(TimeSeries3D s, TimeSeries3D t) {
    double dtw = DTW_D_Distance(s, t);
    return dtw;
}

double DynamicTimeWarping::euclideanDistance_D(double xa, double ya, double za, double xb, double yb, double zb) {
    return abs(xa - xb) + abs(ya - yb) + abs(za - zb);
}

double DynamicTimeWarping::DTW_D_Distance(TimeSeries3D s, TimeSeries3D t) {
    const int n = s.x.second.size();
    const int m = t.x.second.size();

    double DTW[n][m];

    for (int i = 0; i < n; i++) {
        DTW[i][0] = infinity;
    }

    for (int i = 0; i < m; i++) {
        DTW[0][i] = infinity;
    }

    DTW[0][0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            double cost = euclideanDistance_D(s.x.second[i], s.y.second[i], s.z.second[i],
                                              t.x.second[j], t.y.second[j], t.z.second[j]);

            DTW[i][j] = cost +  minimum(DTW[i-1][j],        // insertion
                                        DTW[i][j-1],        // deletion
                                        DTW[i-1][j-1]);     // match
        }
    }

    return DTW[n-1][m-1];
}

void DynamicTimeWarping::classify3D(TimeSeries3DArray trainingSet, TimeSeries3DArray testSet) {
    double acc = 0;

    for (int i = 0; i < testSet.size(); i++) {
        double smaller = infinity;
        int nearestNeighbourClass = 0;
  
        for (int j = 0; j < trainingSet.size(); j++) {

            double dtwDistance = DTWDistance3D(testSet[i], trainingSet[j]);

            if (dtwDistance < smaller) {
                smaller = dtwDistance;
                nearestNeighbourClass = trainingSet[j].klass;
            }
        }

        if (nearestNeighbourClass == testSet[i].klass) {
            acc++;
        }
    }

    cout << "Total: " << testSet.size() << endl;
    cout << "Correct Ones: " << (int) acc << endl;
    cout << "Accuracy: " << acc / testSet.size() * 100 << char(37) << endl;
}