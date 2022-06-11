#pragma once

#include<iostream>
#include<vector>
#include<cmath>

/* @brief 点的例子
 */
class Point
{
public:
	double x,y,z;
	Point(){}
	Point(double _x, double _y, double _z=0.0):
		x(_x), y(_y), z(_z){}
	
	float disTo(const Point& point) const 
	{
		float dx = point.x - x;
		float dy = point.y - y;
		return sqrt(dx*dx + dy*dy);
	}

    float disTo(Point* const point) const
    {
        float dx = point->x - x;
        float dy = point->y - y;
        return sqrt(dx*dx + dy*dy);
    }
};

/* @brief 阶乘函数
 */
float factorial(int n)
{
    int i;
    float s=1.0;
    for(i=1;i<=n;i++){
        s=s*i;
    }
    return s;
}

/* @brief 贝塞尔曲线插值
 * @P:控制点,三阶贝塞尔曲线才能得到平滑的路径
 * @kc,kt,过程系数
 * @path:返回值
 */
std::vector<Point> generateBezierCurve(std::vector<Point>& P){
    int n = P.size() - 1;
    std::cout << "n: " << n << std::endl;
    std::vector<Point> path;
//    此处的t应该为floatl类型,因为若为int类型导致t的值大小一直为0
    for(float t = 0; t <= 1; t = t + 0.01){
        Point pt(0,0);
        for(int i = 0; i <= n; i++){
            double kc = factorial(n) / (factorial(i) * factorial(n-i));
            double kt = pow((1.0-t), (n-i)) * pow(t, i);
//            std::cout << "kc: " << kc << "  "<< "kt: " << kt << std::endl;
            pt.x = pt.x + kc * kt * P[i].x;
            pt.y = pt.y + kc * kt * P[i].y;
        }
//        std::cout << t << std::endl;
//        std::cout << pt.x << "  "<< pt.y << std::endl;
        path.push_back(pt);
    }
    std::cout << "[path size]:  " <<path.size() <<std::endl;
    return path;
}
