#include "shapes.h"

//function prototypes for shape
char intersect_ray_shape(Ray r, Shape *shape, float *t) //ray shape intersection test
{
    switch(shape->type){
    case Sphere:
        return intersect_ray_sphere(r, shape, t);
    case Cube:
        return intersect_ray_cube(r, shape , t);
    case Plane:
        return intersect_ray_plane(r,shape,t);
    case Circle:
        return intersect_ray_plane(r,shape,t);
    case Square:
        return intersect_ray_plane(r,shape,t);
        default:
            return 0;
    }

}

char intersect_ray_sphere(Ray r, Shape *shape, float *t) //ray shape intersection test
{

}

char intersect_ray_cube(Ray r, Shape *shape, float *t) //ray shape intersection test
{

}

char intersect_ray_plane(Ray r, Shape *shape, float *t) //ray shape intersection test
{

}

char intersect_ray_circle(Ray r, Shape *shape, float *t) //ray shape intersection test
{
    Vector3D f = vector_subtract(r.origin, shape->circle.center); //f = r.start - sphere.center
    float disc =  discriminant(r.direction, f, shape->circle.radius);
    
    if(disc > 0)
    {
        // coefficients for the quadratic equation
        float a = dot_product(r.direction, r.direction); 
        float b = 2.0f * dot_product(f, r.direction);    
        
        // solve for t using the quadratic formula
        float sqrt_disc = sqrt(disc);
        
        // first and second solutions using the quadratic formula
        float t1 = (-b - sqrt_disc) / (2.0f * a); 
        float t2 = (-b + sqrt_disc) / (2.0f * a);  

        // Use ternary to choose the smallest positive t
        *t = (t1 >= 0) ? t1 : (t2 >= 0 ? t2 : -1);  //if t1 >= 0, otherwise t2, else -1 for invalid

        // if t is negative (no valid intersection), return 0
        return (*t >= 0) ? 1 : 0; 
        
    }
    return 0;
}
