#include <SystemManager.hpp>

namespace ECS
{
//====================================================================
template <uint32_t T>
SystemManager<T>::SystemManager(EntitiesManager<T> *entitiesMan) : m_entitiesMan(entitiesMan)
{

}


//====================================================================
template<uint32_t T>
bool SystemManager<T>::addNewSystem(std::unique_ptr<System<T>> system)
{
    if(m_numComponents == 0)
    {
        return false;
    }
    m_vectSystem.emplace_back(std::move(system));
    m_vectSystem.back().linkSystemManager(this);
    return true;
}
}

template ECS::SystemManager<4>::SystemManager(ECS::EntitiesManager<4>*); // OK: explicit instantiation

// template class ECS::EntitiesManager<4u>;

// template class ECS::SystemManager<4u>;
