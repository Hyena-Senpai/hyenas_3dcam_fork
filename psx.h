#pragma once

#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>
#include <libcd.h>

#include "defines.h"

// PSX setup

void init(DISPENV disp[2], DRAWENV draw[2], short db, MATRIX * cmat, CVECTOR * BG, VECTOR * BK );

void display(DISPENV * disp, DRAWENV * draw, u_long * otdisc, char * primbuff, char ** nextprim, char * db);

// Utils

void LoadLevel(const char*const LevelName, u_long * LoadAddress);

void LoadTexture(u_long * tim, TIM_IMAGE * tparam);
