#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    point3 orig;
    vec3 dir;
    
    public:
        ray() {}
        
        // Ray constructor given origin point and direction vector 
        ray(const point3& origin, const vec3& direction) : orig(origin), 
                                                           dir(direction) {}
        
        // Ray getters - return immutable references (read-only references)
        const point3& origin() const { return orig; }
        const vec3& direction() const { return dir; }

        // Point(t) = Origin_point + t*Direction_vector
        point3 at(double t) const {
            return orig + t*dir;
        }
};

#endif