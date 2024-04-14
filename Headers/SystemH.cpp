export module M_ECSMain:M_System;


import <array>;
import <vector>;
import <concepts>;
import <cstdint>;
import <cassert>;
import <set>;

// import M_SystemMan;

// class SystemManager;
// export import :M_SystemMan;

export
{
    namespace ECS
    {

    template <uint32_t T>
    class SystemManager;

    using VectUI_t = std::vector<uint32_t>;
    using VectVectUI_t = std::vector<VectUI_t>;

    template <uint32_t T>
    class System
    {
    public:
        ~System() = default;
        virtual void execSystem() = 0;
        inline void linkSystemManager(const SystemManager<T> *systemManager)
        {
            m_systemManager = systemManager;
        }
        void addComponentsToSystem(uint32_t typeComponent, uint32_t numberOfComponent);
    protected:
        System();
        void updateEntities();
    private:
        const SystemManager<T> *m_systemManager = nullptr;
        //Definition of needed components
        std::array<uint32_t, T> m_arrEntities;
        std::set<uint32_t> m_usedEntities, m_cacheUsedComponent;
    };

    template <typename S, uint32_t T>
    concept System_C = std::derived_from<S, System<T>>;

    //====================================================================
    template <uint32_t T>
    System<T>::System() : m_arrEntities(T)
    {

    }

    //====================================================================
    template<uint32_t T>
    void System<T>::updateEntities()
    {
        const VectVectUI_t &vect = m_systemManager->getVectEntities();
        bool ok;
        for(uint32_t i = 0; i < vect.size(); ++i)
        {
            ok = true;
            for(uint32_t j : m_cacheUsedComponent)
            {
                if(m_arrEntities[j] != vect[i][j])
                {
                    ok = false;
                    break;
                }
            }
            m_usedEntities.insert(i);
        }
    }

    //====================================================================
    template<uint32_t T>
    void System<T>::addComponentsToSystem(uint32_t typeComponent, uint32_t numberOfComponent)
    {
        assert(m_arrEntities.size() < typeComponent);
        m_arrEntities[typeComponent] = numberOfComponent;
        m_cacheUsedComponent.insert(typeComponent);
    }

    }
}
