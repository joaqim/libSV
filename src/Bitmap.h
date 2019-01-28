#pragma once

#include <vector>
#include <string>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <memory>
#include <limits.h> // for INT_MAX


#define RGB(r,g,b)          ((DWORD)((BYTE)(r) | ((BYTE)(g) << 8) | ((BYTE)(b) << 16)))

#define GetRValue(rgb)      ((BYTE)  (rgb) )
#define GetGValue(rgb)      ((BYTE) ((rgb) >> 8))
#define GetBValue(rgb)      ((BYTE) ((rgb) >> 16))

