module;

// import <iostream>;
// import <cassert>;
// import <algorithm>;

module M_ECSMain;

namespace ECS
{

//====================================================================
template <uint32_t T>
ESCManager<T>::ESCManager(uint32_t numComponents) : m_systemsManager(m_entitiesManager),  m_numComponents(numComponents)
{

}

}
