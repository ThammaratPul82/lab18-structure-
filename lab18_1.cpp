#include<iostream>
#include<algorithm> 
using namespace std;

struct Rect {
    double x, y, w, h;
};

double overlap(Rect R1, Rect R2) {
    
    double left1 = R1.x;
    double right1 = R1.x + R1.w;
    double bottom1 = R1.y - R1.h; 
    double top1 = R1.y;

    double left2 = R2.x;
    double right2 = R2.x + R2.w;
    double bottom2 = R2.y - R2.h;
    double top2 = R2.y;

    double overlap_left = max(left1, left2);
    double overlap_right = min(right1, right2);
    double overlap_top = min(top1, top2);
    double overlap_bottom = max(bottom1, bottom2);

    double width = overlap_right - overlap_left;
    double height = overlap_top - overlap_bottom;

    if (width <= 0 || height <= 0) {
        return 0;
    }

    return width * height;
}