#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "SunEngine/Core/Log.h"
#include "SunEngine/Debug/Instrumentor.h"
#ifdef SUN_PLATFORM_WINDOWS
	#include <Windows.h>
#endif