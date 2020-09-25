#ifndef CONFIG_H_
#define CONFIG_H_

#include "color.h"

static const int image_height = 1080 * 0.5;
static const int image_width = 1080 * 0.5 / 2 * 3.5; // image_height / 2 * 3.5

static int max_iterations = 2048;
static int bailout = (1 << 8);

// static long double r = 0;
// static long double i = 0;
// static long double zoom = 0.85;

// static long double r = -1.25066;
// static long double i = 0.02012;
// static long double zoom = 1.7e-4;

static long double r = -0.2037744329113252697935390126704115764;
static long double i = +0.6742645126014726141729118013015240509;
static long double zoom = 0.0000917431192660550458715596330275e-7;

// 0 = greeny
// 1 = spectral
static int color_theme = 1;

#endif
