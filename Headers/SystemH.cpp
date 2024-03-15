export module System;

export
{
    namespace ECS
    {
        class System
        {
        public:
            ~System() = default;
        protected:
            System();
        };
    }
}
