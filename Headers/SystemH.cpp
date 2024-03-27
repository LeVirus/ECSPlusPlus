export module M_System;


import <vector>;
import <concepts>;
import <cstdint>;
import <cassert>;
import <set>;

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
        void addComponentsToSystem(uint32_t typeComponent, uint32_t numberOfComponent);
    protected:
        System();
        void updateEntities();
    private:
        const SystemManager *m_systemManager = nullptr;
        //Definition of needed components
        std::array<uint32_t, T> m_arrEntities;
        std::set<uint32_t> m_usedEntities, m_cacheUsedComponent;
    };

    template <typename S, uint32_t T>
    concept System_C = std::derived_from<S, System<T>>;
    }
}
