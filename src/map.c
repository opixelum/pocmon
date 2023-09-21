#include "map.h"


int noise2(int x, int y, int seed)
{
    int tmp = HASH[(y + seed) % 256];
    return HASH[(tmp + x) % 256];
}

float lin_inter(float x, float y, float s)
{
    return x + s * (y-x);
}

float smooth_inter(float x, float y, float s)
{
    return lin_inter(x, y, s * s * (3-2*s));
}

float noise2d(float x, float y, int seed)
{
    int x_int = x;
    int y_int = y;
    float x_frac = x - x_int;
    float y_frac = y - y_int;
    int s = noise2(x_int, y_int,seed);
    int t = noise2(x_int+1, y_int,seed);
    int u = noise2(x_int, y_int+1,seed);
    int v = noise2(x_int+1, y_int+1,seed);
    float low = smooth_inter(s, t, x_frac);
    float high = smooth_inter(u, v, x_frac);
    return smooth_inter(low, high, y_frac);
}

float perlin2d(float x, float y, float freq, int depth, int seed)
{
    float xa = x*freq;
    float ya = y*freq;
    float amp = 1.0;
    float fin = 0;
    float div = 0.0;

    int i;
    for(i=0; i<depth; i++)
    {
        div += 256 * amp;
        fin += noise2d(xa, ya, seed) * amp;
        amp /= 2;
        xa *= 2;
        ya *= 2;
    }

    return fin/div;
}

int mapInit()
{
    int x, y;
    FILE * f= fopen("../save/map.map", "w");
    if(f == NULL)
    {
        return -1;
    }
    srand(time(NULL));
    int seed = rand();
    for(y = 0; y < 100; y++)
    {
        float tmp;
        for (x = 0; x < 300; x++)
        {
            tmp= perlin2d(x, y, 0.05, 8, seed);
            if(tmp > 0.4 && tmp < 0.65)
            {
                fputc('H', f);
            }else if(tmp <= 0.4)
            {
                fputc('C', f);
            }else
            {
                fputc('0', f);
            }
        }
        fputc('\n', f);
    }
    fclose(f);
    return 0;
}