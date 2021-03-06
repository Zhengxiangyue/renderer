//
// Created by Zheng XiangYue on 20/3/2018.
//

#include "illumination.h"

int ammbiant_term(double ka, double Ia) {

}

int diffuse_term(double kd, double I_light, vector3d &normal, vector3d light, int power) {

    double gradient = pow((normal.dot(light)),power);

    return gradient > 0 ? gradient * kd * I_light : 0;
}

int specular_term(double ks, double I, vector3d &normal,  vector3d &light,  vector3d &view, const int n) {

    vector3d h = light + view;

    h = h / h.mold();

    return ks * I * pow((normal.dot(h)),n);

}