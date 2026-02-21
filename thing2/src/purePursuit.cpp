#include "main.h"

// https://wiki.purduesigbots.com/software/odometry
void odometry(pros::Motor_Group left, pros::Motor_Group right){
    /*robotx = 0;
    roboty = 0;
    rotation = 0;

    float width = 12;
    float wheelDiameter = 4;

    float prevL = 0;
    float prevR = 0;

    while(true){
        float currL = left.get_positions()[0];
        float currR = right.get_positions()[0];

        float dL = (currL - prevL) * 3.14 * pow((wheelDiameter / 2.0), 2);
        float dR = (currR - prevR) * 3.14 * pow((wheelDiameter / 2.0), 2);

        prevL = currL;
        prevR = currR;

        float dTheta = (dL - dR) / width;
        float rotationNew = rotation + dTheta;

        float dx = 2 * sin(dTheta / 2) * 
    }*/
}

// https://wiki.purduesigbots.com/software/control-algorithms/basic-pure-pursuit
int sgn(float x){
    if(x < 0){
        return -1;
    }
    return 1;
}

void purePursuit(float** points, float radius){
    // points: [[x1, y1], [x2, y2], ...]
    // pos: chassis->getState();
    /*int lastIndex = 0;
    
    while(true){

        for(int i = lastIndex; i < sizeof(points)/sizeof(float*) - 1; i++){
            float posx = robotx; //chassis->getState().x;
            float posy = roboty; //chassis->getState().y;

            float dx = points[i + 1][0] - points[i][0];
            float dy = points[i + 1][1] - points[i][1];
            float dr = sqrt(pow(dx, 2) + pow(dy, 2));
            float D = (points[i][0] - posx) * (points[i + 1][1] - posy) - (points[i + 1][0] - posx) * (points[i][1] - posy);

            float discriminant = pow(radius, 2) * pow(dr, 2) - pow(D, 2);

            if(discriminant < 0){
                // no intersection
                continue;
            }

            // x and y coords for the two intersections
            float x1 = (D * dy + sgn(dy) * dx * sqrt(discriminant)) / pow(dr, 2) + posx;
            float x2 = (D * dy - sgn(dy) * dx * sqrt(discriminant)) / pow(dr, 2) + posx;

            float y1 = (-1 * D * dx + abs(dy) * sqrt(discriminant)) / pow(dr, 2) + posy;
            float y2 = (-1 * D * dx - abs(dy) * sqrt(discriminant)) / pow(dr, 2) + posy;

            if((x1 < min(points[i][0], points[i + 1][0]) || x1 > max(points[i][0], points[i + 1][0])) ||
            (x2 < min(points[i][0], points[i + 1][0]) || x2 > max(points[i][0], points[i + 1][0])) ||
            (y1 < min(points[i][1], points[i + 1][1]) || y1 > max(points[i][1], points[i + 1][1])) ||
            (y2 < min(points[i][1], points[i + 1][1]) || y2 > max(points[i][1], points[i + 1][1]))) {
                // intersection out of bounds
                continue;
            }

            // intersection has been found
            lastIndex = i;

            // check which point is closest to destination
            float dist1 = sqrt(pow(points[i + 1][0] - x1, 2) + pow(points[i + 1][1] - y1, 2));
            float dist2 = sqrt(pow(points[i + 1][0] - x2, 2) + pow(points[i + 1][1] - y2, 2));

            float pointx;
            float pointy;
            if(dist1 < dist2){
                
            }
        }
    }*/
}