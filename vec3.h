#ifndef VEC3_H
#define VEC3_H
#define SPACE ' '


class vec3 {
    public:
        double e[3];

        // Constructors
        vec3() : e{0,0,0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        // Getters
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        // Vector operators

        // Flip trend 
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        // Get specific coordinate i, by value and by reference (overloading)
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        // Vector addition
        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[3];
            return *this;
        }
        
        // Scalar multipication by factor t
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // Scalar division by factor t
        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        // Getter - Length of vector 
        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

// Alias for vec3, will be used later for clarity in geometry functions
using point3 = vec3;

// Vector Utility Functions

// Printing a vector given an output stream
inline std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out << v.e[0] << SPACE << v.e[1] << SPACE << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v){
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v){
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Element-wise product
inline vec3 operator*(const vec3& u, const vec3& v){
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Scalar multipication
inline vec3 operator*(double t, const vec3& v){
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t){
    return t * v;
}

// Scalar division 
inline vec3 operator/(const vec3& v, double t){
    return (1/t) * v;
}


// Dot product
inline double dot(const vec3& u, const vec3& v){
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// Cross product
inline vec3 cross(const vec3& u, const vec3& v){
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v){
    return v / v.length();
}

#endif