#ifndef STATISTIC_HPP
#define STATISTIC_HPP

#include <stdint.h>

#include <vector>
#include <numeric>

using std::vector;

class TStatistics
{
private:
    uint32_t times;
    double sum;
    double avg;
    double variance;
public:
    TStatistics();
    TStatistics(int cap);
    ~TStatistics();
    
    double add(double val);
    static double getAvg(vector<double> &begin, vector<double> &end, int counts);
    static double getVar(vector<double> &begin, vector<double> &end, int counts);
};


double TStatistics::getAvg(vector<double> &begin, vector<double> &end, int counts)
{
    double sum = std::accumulate(begin, end, 0.0);
    double mean = sum / counts;
    return mean;
}

double TStatistics::getVar(vector<double> &begin, vector<double> &end, int counts)
{
    double sum = std::accumulate(begin, end, 0.0);
    double mean = sum / counts;

    double var = 0;
    double d = 0;
    for (size_t i = 0; i < counts; i++)
    {
        var += (d-mean)*(d-mean);
    }
    
}

template<typename _Tp>
int meanStdDev(const std::vector<std::vector<_Tp>>& mat, double* mean, double* variance, double* stddev)
{
	int h = mat.size(), w = mat[0].size();
	double sum{ 0. }, sqsum{ 0. };
 
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			double v = static_cast<double>(mat[y][x]);
			sum += v;
			sqsum += v * v;
		}
	}
 
	double scale = 1. / (h * w);
	*mean = sum * scale;
	*variance = std::max(sqsum*scale - (*mean)*(*mean), 0.);
	*stddev = std::sqrt(*variance);
 
	return 0;
}



#endif