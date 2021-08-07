#include "level0.h"

CVECTOR level0_BGc = { 135, 232, 230, 0 };

VECTOR level0_BKc = { 174, 174, 174, 0 };

CAMPOS level0_camPos_Camera = {
    { -770,459,623 },
    { 301,531,0 }
};

CAMPATH level0_camPath = {
    0,
    0,
    0
};

MATRIX level0_lgtmat = {
    -2486,  3254,   -22,
    0,0,0,
    0,0,0,

    };

MATRIX level0_cmat = {
    4096,0,0,
    4096,0,0,
    4096,0,0
    };

SVECTOR level0_modelCube_mesh[] = {
    { -32,32,32 },
    { 32,32,32 },
    { 32,32,-33 },
    { -33,32,-32 },
    { -32,-32,33 },
    { 33,-32,32 },
    { 32,-32,-33 },
    { -33,-32,-32 }
};

SVECTOR level0_modelCube_normal[] = {
    2365,-2365,-2365, 0,
    -2365,-2365,-2365, 0,
    -2365,-2365,2365, 0,
    2365,-2365,2365, 0,
    2365,2365,-2365, 0,
    -2365,2365,-2365, 0,
    -2365,2365,2365, 0,
    2365,2365,2365, 0
};

CVECTOR level0_modelCube_color[] = {
    255,236,0, 0,
    255,237,0, 0,
    255,237,0, 0,
    255,235,0, 0,
    255,8,0, 0,
    255,2,0, 0,
    255,6,2, 0,
    254,3,0, 0,
    229,0,255, 0,
    229,0,255, 0,
    232,21,232, 0,
    229,0,255, 0,
    0,12,255, 0,
    5,16,250, 0,
    2,13,253, 0,
    0,12,255, 0,
    0,255,26, 0,
    4,251,25, 0,
    0,255,26, 0,
    0,255,26, 0,
    0,248,255, 0,
    0,248,255, 0,
    0,248,255, 0,
    0,248,255, 0
};

PRIM level0_modelCube_index[] = {
    0,1,2,3,8,
    4,7,6,5,8,
    0,4,5,1,8,
    1,5,6,2,8,
    2,6,7,3,8,
    4,0,3,7,8
};

BODY level0_modelCube_body = {
    {0, 0, 0, 0},
    0,-236,23, 0,
    0,-1024,0, 0,
    5,
    ONE/5,
    -33,-32,-33, 0,
    33,32,33, 0,
    0,
    };

TMESH level0_modelCube = {
    level0_modelCube_mesh,
    level0_modelCube_normal,
    0,
    level0_modelCube_color, 
    6
};

MESH level0_meshCube = {
    24,
    &level0_modelCube,
    level0_modelCube_index,
    0,
    0,
    {0},
    {0,-236,23, 0},
    {0,-1024,0, 0},
    1, // isProp
    1, // isRigidBody
    0, // isStaticBody
    0, // isRound 
    0, // isPrism
    0, // isAnim
    1, // isActor
    0, // isLevel
    0, // isWall
    0, // isBG
    0,// isSprite
    0,
    0,
    &level0_modelCube_body,
    0,
    &level0_nodePlane,
    0,
};

SVECTOR level0_modelPlane_mesh[] = {
    { -520,0,-520 },
    { 520,0,-520 },
    { -520,0,520 },
    { 520,0,520 },
    { -520,0,312 },
    { -520,0,104 },
    { -520,0,-104 },
    { -520,0,-312 },
    { -312,0,-520 },
    { -104,0,-520 },
    { 104,0,-520 },
    { 312,0,-520 },
    { 520,0,-312 },
    { 520,0,-104 },
    { 520,0,104 },
    { 520,0,312 },
    { 312,0,520 },
    { 104,0,520 },
    { -104,0,520 },
    { -312,0,520 },
    { -312,0,-312 },
    { -312,0,-104 },
    { -312,0,104 },
    { -312,0,312 },
    { -104,0,-312 },
    { -104,0,-104 },
    { -104,0,104 },
    { -104,0,312 },
    { 104,0,-312 },
    { 104,0,-104 },
    { 104,0,104 },
    { 104,0,312 },
    { 312,0,-312 },
    { 312,0,-104 },
    { 312,0,104 },
    { 312,0,312 },
    { -520,0,-416 },
    { 416,0,-520 },
    { 520,0,416 },
    { -416,0,520 },
    { -520,0,416 },
    { -520,0,208 },
    { -520,0,0 },
    { -520,0,-208 },
    { -416,0,-520 },
    { -208,0,-520 },
    { 0,0,-520 },
    { 208,0,-520 },
    { 520,0,-416 },
    { 520,0,-208 },
    { 520,0,0 },
    { 520,0,208 },
    { 416,0,520 },
    { 208,0,520 },
    { 0,0,520 },
    { -208,0,520 },
    { -312,0,416 },
    { -312,0,-416 },
    { -312,0,-208 },
    { -312,0,0 },
    { -312,0,208 },
    { -104,0,416 },
    { -104,0,-416 },
    { -104,0,-208 },
    { -104,0,0 },
    { -104,0,208 },
    { 104,0,416 },
    { 104,0,-416 },
    { 104,0,-208 },
    { 104,0,0 },
    { 104,0,208 },
    { 312,0,416 },
    { 312,0,-416 },
    { 312,0,-208 },
    { 312,0,0 },
    { 312,0,208 },
    { -416,0,-312 },
    { -416,0,-104 },
    { -416,0,104 },
    { -416,0,312 },
    { -208,0,-312 },
    { -208,0,-104 },
    { -208,0,104 },
    { -208,0,312 },
    { 0,0,-312 },
    { 0,0,-104 },
    { 0,0,104 },
    { 0,0,312 },
    { 208,0,-312 },
    { 208,0,-104 },
    { 208,0,104 },
    { 208,0,312 },
    { 416,0,-312 },
    { 416,0,-104 },
    { 416,0,104 },
    { 416,0,312 },
    { 416,0,208 },
    { 416,0,0 },
    { 416,0,-208 },
    { 416,0,-416 },
    { 208,0,208 },
    { 208,0,0 },
    { 208,0,-208 },
    { 208,0,-416 },
    { 0,0,208 },
    { 0,0,0 },
    { 0,0,-208 },
    { 0,0,-416 },
    { -208,0,208 },
    { -208,0,0 },
    { -208,0,-208 },
    { -208,0,-416 },
    { -416,0,208 },
    { -416,0,0 },
    { -416,0,-208 },
    { -416,0,-416 },
    { 208,0,416 },
    { 0,0,416 },
    { -208,0,416 },
    { -416,0,416 },
    { 416,0,416 }
};

SVECTOR level0_modelPlane_normal[] = {
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0,
    0,4096,0, 0
};

CVECTOR level0_modelPlane_color[] = {
    0,8,255, 0,
    0,8,255, 0,
    243,255,0, 0,
    240,252,3, 0,
    0,8,255, 0,
    0,8,255, 0,
    243,255,0, 0,
    240,252,3, 0,
    0,14,255, 0,
    0,9,255, 0,
    225,236,19, 0,
    243,255,0, 0,
    0,8,255, 0,
    0,8,255, 0,
    226,238,18, 0,
    225,237,19, 0,
    0,10,255, 0,
    0,8,255, 0,
    223,235,20, 0,
    243,255,0, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,8,255, 0,
    251,1,14, 0,
    250,0,14, 0,
    76,6,181, 0,
    78,6,181, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,13,255, 0,
    0,8,255, 0,
    251,1,13, 0,
    251,1,13, 0,
    75,5,182, 0,
    77,5,180, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,12,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,16,255, 0,
    254,0,11, 0,
    254,0,11, 0,
    0,8,255, 0,
    4,9,251, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,10, 0,
    255,0,10, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,9,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,12,255, 0,
    0,8,255, 0,
    255,0,10, 0,
    255,0,10, 0,
    0,9,255, 0,
    0,8,255, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,9,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,9,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,9,255, 0,
    255,0,227, 0,
    255,0,227, 0,
    255,0,10, 0,
    255,0,10, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,10, 0,
    255,0,10, 0,
    0,8,255, 0,
    0,12,255, 0,
    255,0,10, 0,
    255,0,10, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,27,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,9,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,227, 0,
    255,0,227, 0,
    254,0,11, 0,
    255,0,10, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,10, 0,
    254,0,11, 0,
    0,8,255, 0,
    0,8,255, 0,
    255,0,10, 0,
    255,0,10, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,10,255, 0,
    0,8,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    75,5,182, 0,
    4,9,251, 0,
    255,0,227, 0,
    255,0,227, 0,
    4,9,251, 0,
    0,8,255, 0,
    255,0,227, 0,
    255,0,227, 0,
    251,1,13, 0,
    254,0,11, 0,
    4,9,251, 0,
    75,5,182, 0,
    0,13,255, 0,
    0,16,255, 0,
    254,0,11, 0,
    251,1,13, 0,
    0,16,255, 0,
    0,8,255, 0,
    254,0,11, 0,
    254,0,11, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,16,255, 0,
    0,13,255, 0,
    0,31,255, 0,
    0,31,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,31,255, 0,
    0,10,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,12,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    76,6,181, 0,
    77,5,180, 0,
    255,0,227, 0,
    255,0,227, 0,
    77,5,180, 0,
    75,5,182, 0,
    255,0,227, 0,
    255,0,227, 0,
    250,0,14, 0,
    251,1,13, 0,
    77,5,180, 0,
    76,6,181, 0,
    0,8,255, 0,
    0,8,255, 0,
    251,1,13, 0,
    250,0,14, 0,
    0,8,255, 0,
    0,13,255, 0,
    251,1,13, 0,
    251,1,13, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,9,255, 0,
    0,12,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,12,255, 0,
    0,31,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,255,6, 0,
    0,255,6, 0,
    255,0,227, 0,
    255,0,227, 0,
    0,8,255, 0,
    0,8,255, 0,
    74,5,184, 0,
    78,6,181, 0,
    255,0,227, 0,
    255,0,227, 0,
    78,6,181, 0,
    76,6,181, 0,
    255,0,227, 0,
    255,0,227, 0,
    238,1,26, 0,
    251,1,14, 0,
    78,6,181, 0,
    74,5,184, 0,
    0,8,255, 0,
    0,8,255, 0,
    251,1,14, 0,
    238,1,26, 0,
    0,8,255, 0,
    0,8,255, 0,
    250,0,14, 0,
    251,1,14, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,25,255, 0,
    0,17,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,17,255, 0,
    0,9,255, 0,
    0,255,248, 0,
    0,255,248, 0,
    0,8,255, 0,
    0,10,255, 0,
    243,255,0, 0,
    226,238,18, 0,
    0,8,255, 0,
    0,9,255, 0,
    0,10,255, 0,
    0,8,255, 0,
    0,9,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,10,255, 0,
    0,9,255, 0,
    0,8,255, 0,
    225,237,19, 0,
    225,236,19, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,9,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,14,255, 0,
    243,255,0, 0,
    243,255,0, 0,
    0,8,255, 0,
    0,12,255, 0,
    0,14,255, 0,
    0,8,255, 0,
    0,12,255, 0,
    0,8,255, 0,
    0,9,255, 0,
    0,14,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    240,252,3, 0,
    243,255,0, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    240,252,3, 0,
    223,235,20, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0,
    0,8,255, 0
};

PRIM level0_modelPlane_index[] = {
    120,38,3,52,8,
    119,56,19,39,8,
    118,61,18,55,8,
    117,66,17,54,8,
    116,71,16,53,8,
    115,57,20,76,8,
    114,58,21,77,8,
    113,59,22,78,8,
    112,60,23,79,8,
    111,62,24,80,8,
    110,63,25,81,8,
    109,64,26,82,8,
    108,65,27,83,8,
    107,67,28,84,8,
    106,68,29,85,8,
    105,69,30,86,8,
    104,70,31,87,8,
    103,72,32,88,8,
    102,73,33,89,8,
    101,74,34,90,8,
    100,75,35,91,8,
    99,48,12,92,8,
    98,49,13,93,8,
    97,50,14,94,8,
    96,51,15,95,8,
    75,96,95,35,8,
    34,94,96,75,8,
    94,14,51,96,8,
    74,97,94,34,8,
    33,93,97,74,8,
    93,13,50,97,8,
    73,98,93,33,8,
    32,92,98,73,8,
    92,12,49,98,8,
    72,99,92,32,8,
    11,37,99,72,8,
    37,1,48,99,8,
    70,100,91,31,8,
    30,90,100,70,8,
    90,34,75,100,8,
    69,101,90,30,8,
    29,89,101,69,8,
    89,33,74,101,8,
    68,102,89,29,8,
    28,88,102,68,8,
    88,32,73,102,8,
    67,103,88,28,8,
    10,47,103,67,8,
    47,11,72,103,8,
    65,104,87,27,8,
    26,86,104,65,8,
    86,30,70,104,8,
    64,105,86,26,8,
    25,85,105,64,8,
    85,29,69,105,8,
    63,106,85,25,8,
    24,84,106,63,8,
    84,28,68,106,8,
    62,107,84,24,8,
    9,46,107,62,8,
    46,10,67,107,8,
    60,108,83,23,8,
    22,82,108,60,8,
    82,26,65,108,8,
    59,109,82,22,8,
    21,81,109,59,8,
    81,25,64,109,8,
    58,110,81,21,8,
    20,80,110,58,8,
    80,24,63,110,8,
    57,111,80,20,8,
    8,45,111,57,8,
    45,9,62,111,8,
    41,112,79,4,8,
    5,78,112,41,8,
    78,22,60,112,8,
    42,113,78,5,8,
    6,77,113,42,8,
    77,21,59,113,8,
    43,114,77,6,8,
    7,76,114,43,8,
    76,20,58,114,8,
    36,115,76,7,8,
    0,44,115,36,8,
    44,8,57,115,8,
    66,116,53,17,8,
    31,91,116,66,8,
    91,35,71,116,8,
    61,117,54,18,8,
    27,87,117,61,8,
    87,31,66,117,8,
    56,118,55,19,8,
    23,83,118,56,8,
    83,27,61,118,8,
    40,119,39,2,8,
    4,79,119,40,8,
    79,23,56,119,8,
    71,120,52,16,8,
    35,95,120,71,8,
    95,15,38,120,8
};

BODY level0_modelPlane_body = {
    {0, 0, 0, 0},
    0,0,0, 0,
    0,0,0, 0,
    100,
    ONE/100,
    -520,0,-520, 0,
    520,0,520, 0,
    0,
    };

TMESH level0_modelPlane = {
    level0_modelPlane_mesh,
    level0_modelPlane_normal,
    0,
    level0_modelPlane_color, 
    100
};

MESH level0_meshPlane = {
    400,
    &level0_modelPlane,
    level0_modelPlane_index,
    0,
    0,
    {0},
    {0,0,0, 0},
    {0,0,0, 0},
    0, // isWall
    0, // isProp
    0, // isRigidBody
    0, // isStaticBody
    0, // isRound 
    0, // isPrism
    0, // isAnim
    0, // isActor
    1, // isLevel
    0, // isBG
    0,// isSprite
    0,
    0,
    &level0_modelPlane_body,
    0,
    0,
    0,
};

MESH * level0_meshes[2] = {
    &level0_meshCube,
    &level0_meshPlane
}; 

int level0_meshes_length = 2;

CAMANGLE level0_camAngle_Camera = {
    &level0_camPos_Camera,
    0,
     0,
     { 0 },
     { 0 },
     0,
     0
};

CAMANGLE * level0_camAngles[0] = {
};

SIBLINGS level0_nodePlane_siblings = {
    0,
    {
        0
    }
};

CHILDREN level0_nodePlane_objects = {
    0,
    {
        0
    }
};

CHILDREN level0_nodePlane_rigidbodies = {
    1,
    {
        &level0_meshCube
    }
};

NODE level0_nodePlane = {
    &level0_meshPlane,
    &level0_nodePlane_siblings,
    &level0_nodePlane_objects,
    &level0_nodePlane_rigidbodies
};

MESH * level0_actorPtr = &level0_meshCube;
MESH * level0_levelPtr = &level0_meshPlane;
MESH * level0_propPtr  = &level0_meshCube;

CAMANGLE * level0_camPtr =  &level0_camAngle_Camera;

NODE * level0_curNode =  &level0_nodePlane;

LEVEL level0 = {
    &level0_BGc,
    &level0_BKc,
    &level0_cmat,
    &level0_lgtmat,
    (MESH **)&level0_meshes,
    &level0_meshes_length,
    &level0_meshCube,
    &level0_meshPlane,
    &level0_meshCube,
    &level0_camAngle_Camera,
    &level0_camPath,
    (CAMANGLE **)&level0_camAngles,
    &level0_nodePlane,
};
