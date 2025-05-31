#pragma once

#include <chrono>
#include <memory>
#include <atomic>

using Clock = std::chrono::steady_clock;

template <typename T>
class timedSharedPtr {
private:
    struct controlBlock {
        T* ptr;
        std::chrono::time_point<Clock> startTime;
        std::chrono::milliseconds duration;
        std::atomic<size_t> refCount;

        controlBlock(T* p, std::chrono::milliseconds d)
            : ptr(p), startTime(Clock::now()), duration(d), refCount(1) {}

        ~controlBlock() {
            delete ptr;
        }
    };

    controlBlock* ctrl;

public:
    timedSharedPtr() : ctrl(nullptr) {}

    timedSharedPtr(T* rawPtr, int durationMs = 1000) {
        ctrl = new controlBlock(rawPtr, std::chrono::milliseconds(durationMs));
    }

    timedSharedPtr(const timedSharedPtr& other) {
        ctrl = other.ctrl;
        if (ctrl) ++ctrl->refCount;
    }

    timedSharedPtr& operator=(const timedSharedPtr& other) {
        if (this != &other) {
            if (ctrl && --ctrl->refCount == 0) {
                delete ctrl;
            }
            ctrl = other.ctrl;
            if (ctrl) ++ctrl->refCount;
        }
        return *this;
    }

    timedSharedPtr(timedSharedPtr&& other) noexcept {
        ctrl = other.ctrl;
        other.ctrl = nullptr;
    }

    timedSharedPtr& operator=(timedSharedPtr&& other) noexcept {
        if (this != &other) {
            if (ctrl && --ctrl->refCount == 0) {
                delete ctrl;
            }
            ctrl = other.ctrl;
            other.ctrl = nullptr;
        }
        return *this;
    }

    ~timedSharedPtr() {
        if (ctrl && --ctrl->refCount == 0) {
            delete ctrl;
        }
    }

    T* get() const {
        if (!ctrl) return nullptr;
        auto now = Clock::now();
        if (now - ctrl->startTime > ctrl->duration) {
            return nullptr;
        }
        return ctrl->ptr;
    }

    size_t use_count() const {
        return ctrl ? ctrl->refCount.load() : 0;
    }
};