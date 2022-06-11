#include "bezier_curve.hpp"

using namespace std;

int main(){
    float d = 3.5;
    Point p0(0, -d/2);
    Point p1(20, -d/2);
    Point p2(20, d/2);
    Point p3(40, -d/2);
    
    vector<Point> control_points = { p0, p1, p2, p3 };
    vector<Point> path;
    path = generateBezierCurve(control_points);
    
    const string file_name_ = "b.txt";
    const string file_path_ = "/home/ros/star/Bezier_curve/";

    FILE *fp;
    fp = fopen((file_path_+file_name_).c_str(),"w");

    if(fp == NULL){
        printf("open file %s failed!", (file_path_+file_name_).c_str());
    }

    for(int i = 0; i < path.size(); i++){
        fprintf(fp,"%0.3f\t%.3f\n",path[i].x,path[i].y);
    }
    fflush(fp);
    return 0;
}
