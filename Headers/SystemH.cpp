export module M_System;


import <vector>;
import <concepts>;
import <cstdint>;
import <cassert>;

// import M_SystemMan;

class SystemManager;

export
{
    namespace ECS
    {
    using VectUI_t = std::vector<uint32_t>;
    using VectVectUI_t = std::vector<VectUI_t>;

    template <uint32_t T>
    class System
    {
    public:
        ~System() = default;
        virtual void execSystem() = 0;
        inline void linkSystemManager(const SystemManager *systemManager)
        {
            m_systemManager = systemManager;
        }
        inline void addComponentsToSystem(uint32_t typeComponent, uint32_t numberOfComponent)
        {
            assert(m_arrEntities.size() < typeComponent);
            m_arrEntities[typeComponent] = numberOfComponent;
            m_cacheUsedComponent.emplace_back(typeComponent);
        }
    protected:
        System();
        void updateEntities();
    private:
        const SystemManager *m_systemManager = nullptr;
        //Definition of needed components
        std::array<uint32_t, T> m_arrEntities;
        VectUI_t m_usedEntities, m_cacheUsedComponent;
    };

    }
}
