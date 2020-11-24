#pragma once

#include <functional>
#include <cstdint>

class WorkInfo
{
public:
    using Callback_t = void(*)(void*);
    void* m_userdata = nullptr;

private:
   Callback_t m_callback;

public:
    WorkInfo() = default;

    WorkInfo(Callback_t cb, void* ud = nullptr) : m_callback(cb), m_userdata(ud) {};

    ~WorkInfo() = default;

    void Execute();
};

enum class JobPriority : uint8_t
{
    High,		// Jobs are executed ASAP
    Normal,
    Low
};