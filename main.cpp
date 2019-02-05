#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "globals.h"
#include "funcoes.h"
#include "jogo.h"


int main ()
{
    iniciar();   
    while(!quit) {               
        menu_principal();
        jogo();
    }
    
    allegro_message("GAME OVER BITCH!!!");
    
    terminar();
    return 0;
    
      
}
END_OF_MAIN( );
