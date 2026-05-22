#if defined(USE_MOD1)
    #define main mod1_main
    #include "mod1desafio.c"
    #undef main

    int main(void) {
        return mod1_main();
    }
#elif defined(USE_MOD2)
    #define main mod2_main
    #include "mod2desafio.c"
    #undef main

    int main(void) {
        return mod2_main();
    }
#else
    #define main mod3_main
    #include "mod3desafio.c"
    #undef main

    int main(void) {
        return mod3_main();
    }
#endif