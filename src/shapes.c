#include "shapes.h"

Shape new_sphere(Vector3D center, float radius) {
    Shape s;
    s.type = Sphere;           // mark the type
    s.sphere.center = center;  // fill the union member
    s.sphere.radius = radius;  // set radius
    return s;                  // return the Shape
}

Shape new_circle(Vector3D center, float radius){
    Shape ci;
    ci.type = Circle;           // mark the type
    ci.circle.center = center;  // fill the union member
    ci.circle.radius = radius;  // set radius
    return ci;                  // return the Shape
}

Shape new_cube(Vector3D center, float side_length){
    Shape c;
    c.type = Cube;           // mark the type
    c.square.center = center;  // fill the union member
    c.square.side_length = side_length;  // set radius
    return c;                  // return the Shape
}

Shape new_square(Vector3D center, float side_length){
    Shape sq;
    sq.type = Square;           // mark the type
    sq.square.center = center;  // fill the union member
    sq.square.side_length = side_length;  // set radius
    return sq;                  // return the Shape
}

Shape new_plane(Vector3D point, Vector3D normal){
    Shape p;
    p.type = Plane;           // mark the type
    p.plane.point = point;  
    p.plane.normal = normal;  
    return p;                  // return the Shape
}

char intersect_ray_shape(Ray r, Shape *shape, float *t) //ray shape intersection test
{
    switch(shape->type){
    case Sphere:
        return intersect_ray_spherical(r, shape, t);
    case Cube:
        return intersect_ray_cartesian(r, shape , t);
    case Plane:
        return intersect_ray_plane(r,shape,t);
    case Circle:
        return intersect_ray_spherical(r,shape,t);
    case Square:
        return intersect_ray_cartesian(r,shape,t);
        default:
            return 0;
    }
}


char intersect_ray_spherical(Ray r, Shape *shape, float *t) //ray shape intersection test
{

    Vector3D f = vector_subtract(r.origin, shape->sphere.center);  //vector f is (ray origin - center of sphere)
    float disc = discriminant(r.direction, f, shape->sphere.radius);
    
    if(disc > 0){
      // coefficients for the quadratic equation
      float a = dot_product(r.direction, r.direction);
      float b = 2.0f * dot_product(f, r.direction);

      // solve for t using the quadratic formula
      float sqrt_disc = sqrt(disc);

      // first and second solutions using the quadratic formula
      float t1 = (-b - sqrt_disc) / (2.0f * a);
      float t2 = (-b + sqrt_disc) / (2.0f * a);

      // Use ternary to choose the smallest positive t
      *t = (t1 >= 0) ? t1 : (t2 >= 0 ? t2 : -1); 
      //if t1 >= 0, otherwise t2, else -1 for invalid

      // if t is negative (no valid intersection), return 0
      return (*t >= 0) ? 1 : 0;
    }
    
    return 0;
}   

char intersect_ray_cartesian(Ray r, Shape *shape, float *t) //ray shape intersection test
{
    //define min/max bounds
    Vector3D min = { c->center.x - c->side_length/2, c->center.y - c->side_length/2, c->center.z - c->side_length/2 };
    Vector3D max = { c->center.x + c->side_length/2, c->center.y + c->side_length/2, c->center.z + c->side_length/2 };

    //compute intersection t values
    float t1 = (min.x - r.origin.x) / r.direction.x; //x
    float t2 = (max.x - r.origin.x) / r.direction.x;
    if(t1 > t2) { float tmp = t1; t1 = t2; t2 = tmp; }

    float ty1 = (min.y - r.origin.y) / r.direction.y; //y
    float ty2 = (max.y - r.origin.y) / r.direction.y;
    if(ty1 > ty2) { float tmp = ty1; ty1 = ty2; ty2 = tmp; }

    t1 = fmaxf(t1, ty1); t2 = fminf(t2, ty2);

    float tz1 = (min.z - r.origin.z) / r.direction.z; //z
    float tz2 = (max.z - r.origin.z) / r.direction.z;
    if(tz1 > tz2) { float tmp = tz1; tz1 = tz2; tz2 = tmp; }

    t1 = fmaxf(t1, tz1); t2 = fminf(t2, tz2);

    //check intersection
    if(t1 <= t2 && t2 >= 0) { *t = t1 >= 0 ? t1 : t2; return 1; }
    return 0;
}

char intersect_ray_plane(Ray r, Shape *shape, float *t) //ray shape intersection test
{

}
