module;

// import <iostream>;

module M_SystemMan;

namespace ECS
{

//====================================================================
template <uint32_t T>
SystemManager<T>::SystemManager(const EntitiesManager *entitiesMan) : m_entitiesMan(entitiesMan)
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
    return true;
}

}
