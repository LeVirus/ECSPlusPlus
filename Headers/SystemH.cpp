export module M_System;


import <vector>;
import <concepts>;
import <cstdint>;

// import M_SystemMan;

class SystemManager;

export
{
    namespace ECS
    {

    using VectUI_t = std::vector<uint32_t>;

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
    protected:
        System();
        void getEntities();
    private:
    private:
        const SystemManager *m_systemManager = nullptr;
        //Definition of needed components
        std::array<uint32_t, T> m_arrEntities;
        VectUI_t m_usedEntities;
    };

    }
}
