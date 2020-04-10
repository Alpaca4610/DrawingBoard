#pragma once
#include <ege.h>

enum class Color
{
	R = EGERGB(0xA8, 0, 0),
	G = EGERGB(0, 0xA8, 0),
	B = EGERGB(0, 0, 0xA8),
	W = EGERGB(0xFC, 0xFC, 0xFC),
	Default = 0,
};