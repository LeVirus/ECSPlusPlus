export module M_ECSMain;

import <cstdint>;

import M_EntitiesMan;
import M_SystemMan;

export
{
    namespace ECS
    {

    template<uint32_t T>
    class ESCManager
    {
    public:
        ESCManager(uint32_t numComponents);
        ~ESCManager() = default;
        inline const VectVectUI_t &getVectEntities()const
        {
            return m_entitiesManager.getVectEntities();
        }
    private:
        EntitiesManager m_entitiesManager;
        SystemManager<T> m_systemsManager;
        uint32_t m_numComponents = 0;
    };

    }
}
