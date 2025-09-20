#include "helpers.h"

float discriminant(Vector3D dir, Vector3D center, float r){
    float a = dot_product(dir, dir); //magnitude squared
    float b =  2.0f * dot_product(center, dir); // dot product of (origin - center) and direction
    float c = dot_product(center, center) - (r*r);  //distance squared from origin to center minus radius squared

    return b*b - (4.0f * a * c); //discriminant = b^2 - 4ac
}
