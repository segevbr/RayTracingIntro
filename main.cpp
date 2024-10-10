#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>

// Return black
color ray_color(const ray& r){
    return color(0,0,0);
}

int main() {
    
    // Image 
    
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = point3(0, 0 ,0);

    /* Calculate the vectors across the horizontal and down the vertical
       viewport edges. */
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                    - vec3(0,0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left 
                    + 0.5 * (pixel_delta_u + pixel_delta_v);

    // Render

    std::cout << "P3\n" << image_width << SPACE << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++){
        std::clog << "\rScanlines remaining: " << (image_height - i) << SPACE 
        << std::flush;
        for (int j = 0; j < image_width; j++){
            
            // Calculate current pixel center on grid.
            auto pixel_center = pixel00_loc + (i * pixel_delta_v) 
                                            + (j * pixel_delta_u);

            // Calculate direction vector from camera to current pixel
            auto ray_direction = pixel_center - camera_center;

            // "Shoot" ray to the pixel from camera.
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
            
        }
    }

    std::clog << "\rDone. \n";

    return 0;
}