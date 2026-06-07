#pragma once

#define LAYER_DEMO      0
// #define LAYER_DOTA      1
#define LAYER_RASPBERRY 1
#define LAYER_ANDROID   2
#define LAYER_SCRIPTS   3
#define LAYER_HOVER     4

#define LAYER_COUNT 4 // functional layers in the LYR cycle (excludes LAYER_HOVER)

#define LAYER_NEXT(current) (((current) + 1) % LAYER_COUNT)
