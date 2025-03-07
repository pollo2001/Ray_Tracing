//define what a ray is 
#ifndef RAY_H
#define RAY_H

#include "vectors.h"

typedef struct {
    Vector3D origin;   //where does ray start
    Vector3D direction; //where does ray go
} Ray;

//function proto
Ray create_ray(Vector3D origin, Vector3D direction);  // Create a ray
Vector3D point_at_parameter(Ray r, float t);          // Get the point at parameter t on the ray

#endif
