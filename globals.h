#define lanewidth 40
#define player_nmbr 2

int car_nmbr = 0;



typedef struct {
        BITMAP *sprt;
        int x, y;
        int score;
        char nome[15];
}player;

typedef struct {
        BITMAP *sprt;
        int x, y;
        int veloc;
}carro;

typedef struct {
        player p[player_nmbr];
        carro *car;
}objeto;

typedef struct {
        char nome[15];
        int score;
}player_aux;

enum difficulty {
     easy = 0, medium, hard
};


int dificuldade = 0;

bool quit = false;
volatile int ticks = 0;
volatile int ticks2 = 0;
volatile int secs = 0;
volatile int msecs = 0;
bool game_over;

char carname_vector [10] [15] = {"carro0..bmp","carro2..bmp","carro3..bmp","carro4..bmp","carro5..bmp","carro6..bmp",
                                    "carro7..bmp","carro8..bmp","carro9..bmp"};                                                                                       


SAMPLE *temamenu = load_sample("temamenu.wav");
SAMPLE *temajogo = load_sample("temajogo.wav");
SAMPLE *togglemenu = load_sample("misc_menu.wav");
SAMPLE *changemenu = load_sample("misc2_menu.wav");
SAMPLE *kbdinput = load_sample("click.wav");
SAMPLE *chickenfx_p1 = load_sample("galinha_soundfx.wav");
SAMPLE *chickenfx_p2 = load_sample("galinha_soundfx.wav");
SAMPLE *go = load_sample("go.wav");
SAMPLE *point = load_sample("point.wav");


   

void iniciar ( ) {
     allegro_init ( ); //Inicializa allegro
     int depth, resolucao;
     if ((depth = desktop_color_depth()) != 0) { //Descobre a profundidade da cor do desktop
	 set_color_depth(depth);
      }
      else { //Caso de falha em descobrir, padroniza-se 32
           depth = 32;
      }
      set_color_depth(depth); //Seta a cor para o aplicativo
      if((resolucao = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0)) != 0 ) { //seta a resolução, sintaxe:(driver,largura,altura,minimalaguravirtual,minimaalturavirtual
    		allegro_message("Erro na inicializacao");
		    exit(-1);
      }
      install_keyboard ( ); //inicializa dispositivos
      install_mouse ( );
      install_timer ( );
      install_sound (DIGI_AUTODETECT,MIDI_AUTODETECT,0);
      
}
   

void terminar ( ) {
     destroy_sample(temamenu);
     destroy_sample(kbdinput);
     destroy_sample(temajogo);
     destroy_sample(chickenfx_p1);
     destroy_sample(chickenfx_p2);
     destroy_sample(togglemenu);
     destroy_sample(changemenu);
     destroy_sample(go);
     remove_keyboard();
     remove_timer();
     remove_sound();
     clear_keybuf(); //limpa buffer
     allegro_exit();   //fecha allegro
}

void timer()
{
	ticks++;
}
END_OF_FUNCTION(timer);

LOCK_VARIABLE(ticks);
LOCK_FUNCTION(timer);

void timer2()
{
	ticks2++;
}
END_OF_FUNCTION(timer2);

LOCK_VARIABLE(ticks2);
LOCK_FUNCTION(timer2);

void game_time( )
{
     secs++;
}
END_OF_FUNCTION(game_time);

LOCK_VARIABLE(secs);
LOCK_FUNCTION(game_time);

void music_time( )
{
     msecs++;
}
END_OF_FUNCTION(music_time);

LOCK_VARIABLE(msecs);
LOCK_FUNCTION(music_time);


