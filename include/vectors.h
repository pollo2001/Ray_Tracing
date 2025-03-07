// define what vector is 

#ifndef VECTORS_H
#define VECTORS_H

#include <math.h>

// Define a structure for 3D vectors
typedef struct {
    float x, y, z;
} Vector3D;


// Function prototype for vector addition
Vector3D vector_add(Vector3D v1, Vector3D v2); //add retuns another vector
Vector3D vector_subtract(Vector3D v1, Vector3D v2);
float dot_product(Vector3D v1, Vector3D v2);    //dot retuns another scalar
Vector3D cross_product(Vector3D v1, Vector3D v2);   //dot retuns another vectpr(normal vector)
float magnitude(Vector3D v1);    //magnitude retuns a scalaer
Vector3D normalize(Vector3D v1);    //normalize retuns a vector

#endif
