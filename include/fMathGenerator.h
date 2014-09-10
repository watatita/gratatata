#ifndef FMATHGENERATOR_H
#define FMATHGENERATOR_H

#include <irrlicht.h>

#define POISSON_CELL_SIZE   8
#define __NO_POISSON_DISK_SAMPLING__

using namespace irr;
using namespace core;
class fMathGenerator
{
    public:
        fMathGenerator();
        virtual ~fMathGenerator();
        position2df gradien(s32 x,s32 y);
        f32 PerlinNoise(f32 x,f32 y,f32 scale);

    //unused Poisson disk sampling
    #ifndef __NO_POISSON_DISK_SAMPLING__
        f32 check_distance(core::vector2df a, core::vector2df b);
        bool check_empty_neighbour(core::vector2df a,f32 min_radius);
        core::vector2df new_random_point(core::vector2df previous_point,f32 min_radius);
        void createPoisson(u32 width, u32 height, u32 new_points_count);

        core::array<vector2df> sample_poisson;
    #endif // __NO_POISSON_DISK_SAMPLING__
    protected:
    private:
        position2df static_grad[128][128];
    #ifndef __NO_POISSON_DISK_SAMPLING__
        core::array<vector2df> process_poisson;
        core::array<vector2df> grid_handler[128][128];
    #endif // __NO_POISSON_DISK_SAMPLING__

};

#endif // FMATHGENERATOR_H
