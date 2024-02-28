#pragma once

class vertex
{
public:
    float x,y,z,r,g,b;  // position and color
    vertex(float x, float y, float z, float r, float g, float b)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
        this->g = g;
        this->b = b;
    }
};
