#pragma once

#include <vector>
#include <cstdint>
#include <memory>

struct Component;

using VectComp_t = std::vector<std::unique_ptr<Component>>;
namespace ECS
{
template <uint32_t T>
class ComponentsManager
{
public:
    ComponentsManager();
    ~ComponentsManager() = default;
private:
    std::array<VectComp_t, T> m_contComponents;
};
}
