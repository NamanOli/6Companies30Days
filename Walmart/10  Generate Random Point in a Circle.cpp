class Solution {
public:
    double RAD, XC, YC;
    Solution(double radius, double x_center, double y_center) {
        RAD = radius;
        XC = x_center;
        YC = y_center;
    }   
    vector<double> randPoint() {
        double ang = (double)rand() / RAND_MAX * 2 * M_PI,
            hyp = sqrt((double)rand() / RAND_MAX) * RAD,
            adj = cos(ang) * hyp,
            opp = sin(ang) * hyp;
        return vector<double>{XC + adj, YC + opp};
    }
};