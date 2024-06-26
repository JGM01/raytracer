# Ray Tracing in a Weekend

Ray tracer current status: Renders sphere colored by it's normal vectors, and multiple spheres can be added somewhat easily. 

In an attempt to become more familiar with the math involved in ray tracing, I am following ray tracing in a weekend. 

Produce an image by following the instructions:

First build:

While in the root directory, run `cmake -S . -B build`.

Every consecutive build afterwards will be in the `build/` directory using the `make` command.

Render the image

Go back to the project's root directory, and run `./build/raytracer > image.ppm`

You should now be able to view the generated image.
