#include <ComponentsManager.hpp>
#include <Component.hpp>
#include <iostream>

namespace ECS
{

//====================================================================
template <uint32_t T, Component_C... C>
ComponentsManager<T, C...>::ComponentsManager()
{
    // addNewComponentType(Test());
    addNewComponentType<Test>();
    // m_contComponents.push_back(std::vector<Test>());
    m_contComponents[0].push_back(Test());
    m_contComponents[0][0].m_b = 25;
    std::cerr << m_contComponents[0][0].m_b << "\n";
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

//====================================================================
template <uint32_t T, Component_C... C>
void ComponentsManager<T, C...>::addNewComponentType()
{
    m_contComponents.push_back(std::vector<C...>());
}

}
