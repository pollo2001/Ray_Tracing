//SHAPES holds all the different geometries we can play with

#ifndef SHAPES_H
#define SHAPES_H

#include "ray.h"
#include "vectors.h"
#include "helpers.h"

//enum struct for shape types
typedef enum {
    Sphere,
    Plane,
    Cube,
    Circle,
    Square
} ShapeType;

//base struct for any shape
typedef struct {
    ShapeType type; //type of shape (sphere, cube,etc)
    union {
        struct { Vector3D center; float radius; } sphere;
        struct { Vector3D center; float side_length; } cube;
        struct { Vector3D point; Vector3D normal; } plane;
        struct { Vector3D center; float radius; } circle;
        struct { Vector3D center; float side_length; } square;
    };
} Shape;

//function prototypes for shape, returns 0 or 1 if intersection occurs
char intersect_ray_shape(Ray r, Shape *shape, float *t); //ray shape intersection test for any shape, will forward
char intersect_ray_spherical(Ray r, Shape *shape, float *t); //ray shape intersection test
char intersect_ray_cartesian(Ray r, Shape *shape, float *t); //ray shape intersection test
char intersect_ray_plane(Ray r, Shape *shape, float *t); //ray shape intersection test

Shape new_sphere(Vector3D center, float radius);
Shape new_cube(Vector3D center, float side_length);
Shape new_plane(Vector3D point, Vector3D normal);
Shape new_circle(Vector3D center, float radius);
Shape new_square(Vector3D center, float side_length);

#endif