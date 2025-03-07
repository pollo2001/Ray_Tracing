#include "ray.h"

Ray create_ray(Vector3D origin, Vector3D direction)  // Create a ray
{
    return (Ray){origin, normalize(direction)}; //magnitude 1 to keep it small
}

Vector3D point_at_parameter(Ray r, float t)          // Get the point at parameter t on the ray
{
    return vector_add(
    r.origin,       //add the starting point
    (Vector3D){r.direction.x * t, r.direction.y * t, r.direction.z * t}); //to the point after time t has passed, get the location at time t

}