#ifndef SERIES_H
#define SERIES_H

#include <string>
#include <QtCharts/QtCharts>


template<typename T>
class Series
{
private:
    std::string title;
    T x1;
    T y1;
    T x2;
    T y2;
    QChart* chrt;
public:
    Series(std::string name, T x1, T y1, T x2, T y2);
protected:
};

#endif // SERIES_H
