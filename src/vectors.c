#include "vectors.h"

// Function prototype for vector addition
Vector3D vector_add(Vector3D v1, Vector3D v2)   //add retuns another vector
{
      return (Vector3D){ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z }; //inline def
}

Vector3D vector_subtract(Vector3D v1, Vector3D v2) {
    return (Vector3D){
        v1.x - v2.x,
        v1.y - v2.y,
        v1.z - v2.z
    };
}

float dot_product(Vector3D v1, Vector3D v2) //dot retuns another scalar
{
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

Vector3D cross_product(Vector3D v1, Vector3D v2)  //dot retuns another vectpr(normal vector)
{
    return (Vector3D){ 
    (v1.y * v2.z) - (v1.z * v2.y), //x
    (v1.z * v2.x) - (v1.x * v2.z), //y
    (v1.x * v2.y) - (v1.y * v2.x)  //z
     }; 
}

float magnitude(Vector3D v1)    //magnitude retuns a scalaer
{
    return (sqrt(pow(v1.x,2) + pow(v1.y,2) + pow(v1.z,2)));
}

Vector3D normalize(Vector3D v1)    //normalize retuns a vector
{
    float MAG = magnitude(v1);

    if (MAG ==0)
        return (Vector3D){0,0,0}; //default

    return (Vector3D){
        v1.x / MAG,
        v1.y / MAG,
        v1.z / MAG
    };
}