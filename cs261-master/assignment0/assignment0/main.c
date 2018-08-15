//
//  main.c
//  cs261
//
//  Created by Alex Cheng on 2018/6/29.
//  Copyright © 2018 Alex Cheng. All rights reserved.
//

#include <math.h>
#include <stdio.h>

double calcAreaTriangle(double a, double b, double c) {
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
int main() {
    printf("%f\n", calcAreaTriangle(4, 9, 10));
    return 0;
}
