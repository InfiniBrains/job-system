#pragma once

#include <thread>
#include <cstdint>

class LoopManager {
    unsigned int numCores = std::max(1u, std::thread::hardware_concurrency());
};

