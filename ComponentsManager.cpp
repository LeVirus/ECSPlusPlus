#include <ComponentsManager.hpp>
#include <Component.hpp>

namespace ECS
{

//====================================================================
template <uint32_t T, Component_C... C>
ComponentsManager<T, C...>::ComponentsManager()
{
    addNewComponentType(Test());
    m_contComponents.push_back(std::vector<Test>());
    // m_contComponents.push_back(std::vector<TestB>());
}

//====================================================================
template <uint32_t T, Component_C... C>
void ComponentsManager<T, C...>::addEntity(const std::array<bool, T> &vect)
{

}

//====================================================================
template <uint32_t T, Component_C... C>
void ComponentsManager<T, C...>::addNewComponentType(C...)
{
    m_contComponents.push_back(std::vector<C...>());
}

}
