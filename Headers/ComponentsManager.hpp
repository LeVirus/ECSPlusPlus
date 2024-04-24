#pragma once

#include <vector>
#include <cstdint>
#include <memory>
#include <Component.hpp>

struct Component;


namespace ECS
{

// template <typename S>
// concept Component_C = std::derived_from<S, Component>;

// using VectComp_t = std::vector<T>;

struct Test : private Component
{

};

struct TestB : private Component
{

};

template <uint32_t T, Component_C... C>
class ComponentsManager
{
public:
    ComponentsManager();
    ~ComponentsManager() = default;
    void addEntity(const std::array<bool, T> &vect);
private:
    // template <Component_C... C>
    std::array<std::vector<C...>, T> m_contComponents;
    //cache index of entities's component
    std::vector<std::array<uint32_t, T>> m_refComponents;
};
}
