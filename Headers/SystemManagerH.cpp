export module M_ECSMain:M_SystemMan;

import <vector>;
import <cstdint>;
import <memory>;

// export import :M_System;
// import M_System;
// import M_EntitiesMan;
export import :M_System;


using VectUI_t = std::vector<uint32_t>;
using VectVectUI_t = std::vector<VectUI_t>;

export
{
    namespace ECS
    {

    //FORWARD DECL
    // template <uint32_t T>
    // class System;

    template <uint32_t T>
    class EntitiesManager;

    template <uint32_t T>
    class SystemManager
    {
    public:
        SystemManager(const EntitiesManager<T> *entitiesMan);
        ~SystemManager() = default;
        bool addNewSystem(std::unique_ptr<System<T>> system);
        inline const VectVectUI_t &getVectEntities()const
        {
            return m_entitiesMan->getVectEntities();
        }
    private:
        const EntitiesManager<T> *m_entitiesMan = nullptr;
        uint32_t m_numComponents = 0;
        std::vector<std::unique_ptr<System<T>>> m_vectSystem;
    };

    //====================================================================
    template <uint32_t T>
    SystemManager<T>::SystemManager(const EntitiesManager<T> *entitiesMan) : m_entitiesMan(entitiesMan)
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
}
