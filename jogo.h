void instructions ( );

void highscores ( );

void pos_jogo(objeto obj);

void chose_diff (bool *back_to_menu);

void menu_principal () {
     int menu_pos = 0;
     int lvl_pos = 0;
     game_over = false;
     BITMAP *buff = create_bitmap(800,600);
     BITMAP *menu = load_bitmap("fundomenu.bmp",NULL);
     BITMAP *menu2 = load_bitmap("fundomenu.bmp",NULL); 
     FONT *fontemenu = load_font("freeway.pcx",NULL,NULL);
     FONT *developers = load_font("developers.pcx",NULL,NULL);
     int menu_theme = play_sample(temamenu, 120, 0, 1000, 0); 
     while(!quit) {      
          if( key[KEY_DOWN] || key[KEY_S]) { menu_pos++; 
                       int menu_toggle = play_sample(togglemenu, 255, 0, 1000, 0);
          }         
          else if( key[KEY_UP] || key[KEY_W]) { menu_pos--;
               int menu_toggle = play_sample(togglemenu, 255, 0, 1000, 0);
          }
          rest(75);
          if(menu_pos < 0) menu_pos = 3;
          else if(menu_pos >3) menu_pos = 0;
          if(key[KEY_ENTER]) SAMPLE *changemenu = load_sample("misc_menu.wav"); 
          if(menu_pos == 0 && key[KEY_ENTER]) {
                      int menu_theme = play_sample(changemenu, 255, 0, 1000, 0); 
                      bool back_to_menu = false;
                      rest(50);
                      chose_diff (&back_to_menu); 
                      if(back_to_menu == false) break;
          }
          if(menu_pos == 1 && key[KEY_ENTER]) {
                      int menu_theme = play_sample(changemenu, 255, 0, 1000, 0); 
                      rest(50);
                      instructions();
          }
          if(menu_pos == 2 && key[KEY_ENTER]) { 
                      int menu_theme = play_sample(changemenu, 255, 0, 1000, 0); 
                      rest(50);
                      highscores();
          }
          if(menu_pos == 3 && key[KEY_ENTER]) {
                      int menu_theme = play_sample(changemenu, 255, 0, 1000, 0);   
                      quit = true;
          }
     
          if(menu_pos == 0) {
                      textprintf_ex(menu,fontemenu,370,200,makecol(255,0,0),-1,"JOGAR");
                      textprintf_ex(menu,fontemenu,370,300,makecol(0,0,0),-1,"INSTRUCOES");
                      textprintf_ex(menu,fontemenu,370,400,makecol(0,0,0),-1,"HIGHSCORES");
                      textprintf_ex(menu,fontemenu,370,500,makecol(0,0,0),-1,"SAIR");

                 }
          else if (menu_pos == 1) {
                      textprintf_ex(menu,fontemenu,370,200,makecol(0,0,0),-1,"JOGAR");
                      textprintf_ex(menu,fontemenu,370,300,makecol(255,0,0),-1,"INSTRUCOES");
                      textprintf_ex(menu,fontemenu,370,400,makecol(0,0,0),-1,"HIGHSCORES");
                      textprintf_ex(menu,fontemenu,370,500,makecol(0,0,0),-1,"SAIR");
                 }
          else if (menu_pos == 2) {
                      textprintf_ex(menu,fontemenu,370,200,makecol(0,0,0),-1,"JOGAR");
                      textprintf_ex(menu,fontemenu,370,300,makecol(0,0,0),-1,"INSTRUCOES");
                      textprintf_ex(menu,fontemenu,370,400,makecol(255,0,0),-1,"HIGHSCORES");
                      textprintf_ex(menu,fontemenu,370,500,makecol(0,0,0),-1,"SAIR");
                 }
          else if (menu_pos == 3) {
                      textprintf_ex(menu,fontemenu,370,200,makecol(0,0,0),-1,"JOGAR");
                      textprintf_ex(menu,fontemenu,370,300,makecol(0,0,0),-1,"INSTRUCOES");
                      textprintf_ex(menu,fontemenu,370,400,makecol(0,0,0),-1,"HIGHSCORES");
                      textprintf_ex(menu,fontemenu,370,500,makecol(255,0,0),-1,"SAIR");
                 }
                       
                 
          textprintf_ex(menu,developers,600,510,makecol(255,255,255),-1,"DESENVOLVIDO POR:");
          textprintf_ex(menu,developers,600,530,makecol(255,255,255),-1,"CARLO SGANZERLA");
          textprintf_ex(menu,developers,600,550,makecol(255,255,255),-1,"JOAO DOS REIS NETO");     
          stretch_blit(menu,buff,0,0,menu->w,menu->h,0,0,SCREEN_W,SCREEN_H);
          blit(buff,screen,0,0,0,0,SCREEN_W,SCREEN_H);                 

          
     }                 
     destroy_bitmap(buff);
     destroy_bitmap(menu);
     destroy_font(fontemenu);
     destroy_font(developers);
     destroy_bitmap(menu2);
}


void chose_diff (bool *back_to_menu) {
     
     BITMAP *buff = create_bitmap(800,600);
     BITMAP *menu2 = load_bitmap("fundomenu.bmp",NULL); 
     FONT *fontemenu = load_font("freeway.pcx",NULL,NULL);
     int lvl_pos = 0;
     
                          while(!(*back_to_menu)) {
                                                 
                                                       
   
                                                  
                                             if( key[KEY_DOWN] || key[KEY_S]) {
                                                 int menu_theme = play_sample(togglemenu, 255, 0, 1000, 0);   
                                                 lvl_pos++;
                                                 }      
                                             else if( key[KEY_UP] || key[KEY_W]){
                                                   lvl_pos--;
                                                   int menu_theme = play_sample(togglemenu, 255, 0, 1000, 0);   
                                                   }
                                             rest(75);
                                             if(lvl_pos < 0) lvl_pos = 3;
                                             else if(lvl_pos >3) lvl_pos = 0;
                                             if(lvl_pos == 0 && key[KEY_ENTER]) {
                                                        int menu_theme = play_sample(changemenu, 255, 0, 1000, 0); 
                                                        car_nmbr = 10;
                                                        dificuldade = easy;
                                                        break;
                                             }
                                             if(lvl_pos == 1 && key[KEY_ENTER]) {
                                                        int menu_theme = play_sample(changemenu, 255, 0, 1000, 0);  
                                                        car_nmbr = 20;
                                                        dificuldade = medium;
                                                        break;
                                             }
                                             if(lvl_pos == 2 && key[KEY_ENTER]) {
                                                        int menu_theme = play_sample(changemenu, 255, 0, 1000, 0); 
                                                        car_nmbr = 30;
                                                        dificuldade = hard;
                                                        break;
                                             }
                                             
                                             
                                             if(lvl_pos == 3 && key[KEY_ENTER])  {
                                                        int menu_theme = play_sample(changemenu, 255, 0, 1000, 0); 
                                                        *back_to_menu = true;
                                             }
                                             if(lvl_pos == easy) {
                                                         textprintf_ex(menu2,fontemenu,370,200,makecol(255,0,0),-1,"EASY");
                                                         textprintf_ex(menu2,fontemenu,370,300,makecol(0,0,0),-1,"MEDIUM");
                                                         textprintf_ex(menu2,fontemenu,370,400,makecol(0,0,0),-1,"HARD");
                                                         textprintf_ex(menu2,fontemenu,370,500,makecol(0,0,0),-1,"VOLTAR");
                                                         
                                             }
                                             else if(lvl_pos == medium) {
                                                         textprintf_ex(menu2,fontemenu,370,200,makecol(0,0,0),-1,"EASY");
                                                         textprintf_ex(menu2,fontemenu,370,300,makecol(255,0,0),-1,"MEDIUM");
                                                         textprintf_ex(menu2,fontemenu,370,400,makecol(0,0,0),-1,"HARD");
                                                         textprintf_ex(menu2,fontemenu,370,500,makecol(0,0,0),-1,"VOLTAR");
                                                         
                                             }
                                             else if(lvl_pos == hard) {
                                                         textprintf_ex(menu2,fontemenu,370,200,makecol(0,0,0),-1,"EASY");
                                                         textprintf_ex(menu2,fontemenu,370,300,makecol(0,0,0),-1,"MEDIUM");
                                                         textprintf_ex(menu2,fontemenu,370,400,makecol(255,0,0),-1,"HARD");
                                                         textprintf_ex(menu2,fontemenu,370,500,makecol(0,0,0),-1,"VOLTAR");
                                                         
                                             }
                                             else if(lvl_pos == 3) {
                                                         textprintf_ex(menu2,fontemenu,370,200,makecol(0,0,0),-1,"EASY");
                                                         textprintf_ex(menu2,fontemenu,370,300,makecol(0,0,0),-1,"MEDIUM");
                                                         textprintf_ex(menu2,fontemenu,370,400,makecol(0,0,0),-1,"HARD");
                                                         textprintf_ex(menu2,fontemenu,370,500,makecol(255,0,0),-1,"VOLTAR");
                                                         
                                             }
                                             stretch_blit(menu2,buff,0,0,menu2->w,menu2->h,0,0,SCREEN_W,SCREEN_H);
                                             blit(buff,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                             
                      }
   destroy_bitmap(menu2);
   destroy_bitmap(buff);
   destroy_font(fontemenu);
                                             

     
}          

void instructions ( )
{
          FONT *fontemenu = load_font("freeway.pcx",NULL,NULL);        
          BITMAP *buff = create_bitmap(800,600);
          BITMAP *instructions = load_bitmap("instructions.bmp",NULL);
          while(!key[KEY_ESC]) {
                               
                               stretch_blit(instructions,buff,0,0,instructions->w,instructions->h,0,0,SCREEN_W,SCREEN_H);
                               textprintf_ex(buff, fontemenu, 250, 550, makecol(255, 255, 255),-1, "Pressione ESC para sair");
                               blit(buff,screen,0,0,0,0,SCREEN_W,SCREEN_H);    
          }
          destroy_font(fontemenu);
          destroy_bitmap(buff);
          destroy_bitmap(instructions);
}

void pre_jogo (player *p, short int p_num) {
        
   BITMAP* buff = create_bitmap(800,600);
   int pos_nome  = 0;
   BITMAP *pregame = load_bitmap("fundomenu.bmp",NULL); 
   FONT *fontemenu = load_font("freeway.pcx",NULL,NULL);
   p->nome[0] = '\0';

   clear_keybuf();
   do
   {      
      if(keypressed())
      {
         int  newkey   = readkey();
         char ASCII    = newkey & 0xff; //codigo ASCII
         char scancode = newkey >> 8; //codigo scancode
 

         if(ASCII >= 65 && ASCII <= 122 || ASCII == 32)
         {
            int keyboard_input = play_sample(kbdinput, 255, 0, 1000, 0);  
            if(pos_nome < 14)
            {
               p->nome[pos_nome] = ASCII;
               pos_nome++;
               p->nome[pos_nome] = '\0';
            }
         }
         else if(scancode == KEY_BACKSPACE)
         {
            int keyboard_input = play_sample(kbdinput, 255, 0, 1000, 0); 
            if (pos_nome > 0) pos_nome--;
            p->nome[pos_nome] = '\0';
         }
      }
 

      stretch_blit(pregame,buff,0,0,pregame->w,pregame->h,0,0,SCREEN_W,SCREEN_H);
      textprintf_ex(buff, fontemenu, 300, 300, makecol(255, 0, 0),-1, "%s", p->nome);
      textprintf_ex(buff, fontemenu, 250, 100, makecol(0, 0, 0),-1, "Insira o nome do player %d",p_num);
      textprintf_ex(buff, fontemenu, 150, 500, makecol(0, 0, 0),-1, "Pressione ENTER quando estiver pronto");
      vline(buff, 300 + pos_nome * 18, 300, 340, makecol(255, 0, 0));
      blit(buff,screen,0,0,0,0,SCREEN_W,SCREEN_H);  
 
   }
   while(!key[KEY_ENTER]);
   int change_menu = play_sample(changemenu, 255, 0, 1000, 0); 
   destroy_bitmap(buff);
   destroy_bitmap(pregame);
   destroy_font(fontemenu);
     
                  
}

void pause_menu (bool *back_to_menu ) {
     
     int pausemenu_pos = 0;
     int count = 0;
     BITMAP *buff = create_bitmap(800,600);
     BITMAP *pausemenu = load_bitmap("fundo.bmp",NULL); 
     FONT *fontemenu = load_font("freeway.pcx",NULL,NULL);
     bool back_to_game = false;
     
                          while(!back_to_game) {
                                                 
                                                       
   
                                                  
                                             if( key[KEY_DOWN] || key[KEY_S]) {
                                                 int menu_theme = play_sample(togglemenu, 255, 0, 1000, 0);  
                                                 pausemenu_pos++;
                                                 }      
                                             else if( key[KEY_UP] || key[KEY_W]){
                                                  int menu_theme = play_sample(togglemenu, 255, 0, 1000, 0);   
                                                  pausemenu_pos--;
                                                  }
                                             rest(75);
                                             if(pausemenu_pos < 0) pausemenu_pos = 1;
                                             else if(pausemenu_pos > 1) pausemenu_pos = 0;
                                             if(key[KEY_ESC]) back_to_game = true;
                                             if(pausemenu_pos == 0 && key[KEY_ENTER]) {
                                                              int menu_theme = play_sample(changemenu, 255, 0, 1000, 0);
                                                              back_to_game = true;

                                             }
                                             if(pausemenu_pos == 1 && key[KEY_ENTER]) {
                                                              int menu_theme = play_sample(changemenu, 255, 0, 1000, 0);
                                                              *back_to_menu = true;
                                                              break;
                                                              
                                             }
                                             if(pausemenu_pos == 0) {
                                                         textprintf_ex(pausemenu,fontemenu,370,200,makecol(255,0,0),-1,"VOLTAR");
                                                         textprintf_ex(pausemenu,fontemenu,370,300,makecol(0,0,0),-1,"SAIR");
                                                         
                                             }
                                             else if(pausemenu_pos == 1) {
                                                         textprintf_ex(pausemenu,fontemenu,370,200,makecol(0,0,0),-1,"VOLTAR");
                                                         textprintf_ex(pausemenu,fontemenu,370,300,makecol(255,0,0),-1,"SAIR");
                                                         
                                             }
                                             textprintf_ex(pausemenu,fontemenu,50,50,makecol(255,255,255),-1,"O JOGO ESTA PAUSADO");
                                             stretch_blit(pausemenu,buff,0,0,pausemenu->w,pausemenu->h,0,0,SCREEN_W,SCREEN_H);
                                             blit(buff,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                                             
                      }
                      
       destroy_bitmap(pausemenu);
       destroy_bitmap(buff);
       destroy_font(fontemenu);
                                         
                                             

}
     
             
     
void jogo ( ) {
      
    objeto obj;
    if(!quit) {
    rest(500);
     pre_jogo(&obj.p[0],1);
     rest(500);
     pre_jogo(&obj.p[1],2);     
    }
    stop_sample(temamenu);
    if(!quit) {
                   int gogo = play_sample(go, 255, 0, 1000, 0);
                   rest(1000); 
    }
     int sprite = 0;
     FONT *score = load_font("freeway.pcx",NULL,NULL);
     if(score == NULL) {
              allegro_message("Erro: FONT freeway.pcx faltando! Encerrando o programa...");
             exit(1);
    }
     bool back_to_menu = false;
     obj.car = (carro *) malloc(car_nmbr*sizeof(carro));
     if(obj.car == NULL) {
                allegro_message("ERRO na inicialização");
                exit(2);
     }
     srand (time(NULL)); 
    CriaPlayer(&obj.p[0],"galinha.bmp",200,520); //cria galinha
    CriaPlayer(&obj.p[1],"galinha.bmp",550,520); //cria galinha
    CriaCarro(obj.car,dificuldade);
    obj.p[0].score = 0;
    obj.p[1].score = 0;
    bool VerifP1Stun = false;
    bool VerifP2Stun = false;
    secs = 0;
    int aux;
    install_int_ex(game_time, BPS_TO_TIMER(1));
    install_int_ex(music_time, BPS_TO_TIMER(1));
    int game_theme = play_sample(temajogo, 255, 0, 1000, 0); 
    while(!back_to_menu && secs <= 120 && !(quit)) {
                         
                        
                          ImprimeTela(obj,score);
                           MoveCarro(obj.car);
                           
                           
                             if(key[KEY_ESC]) {
                                              aux = secs;
                                              pause_menu(&back_to_menu);
                                              rest(50);
                                              secs = aux;
                             }
                             
                             if( (key[KEY_W]) || (key[KEY_S]) || (key[KEY_UP]) || (key[KEY_DOWN]) || VerifP1Stun || VerifP2Stun) {
                                 if(obj.p[0].y > 50) {
                                               install_int_ex(timer, BPS_TO_TIMER(10));
                                               if(VerifP1Stun && ticks <= 10){
                                                              if(ticks <= 5) MovePlayer1 (&obj.p[0],'c',&sprite);
                                                              else if(ticks >5 && ticks <= 10);
                                                               
                                               }
                                               else if(key[KEY_W]) MovePlayer1 (&obj.p[0],'u',&sprite);
                                               else if(key[KEY_S]) MovePlayer1 (&obj.p[0],'d',&sprite);
                                               if(ticks > 10) {
                                                        VerifP1Stun = false; 
                                                        ticks = 0;
                                               }
                                           

                                           
                              }
                               else  {
                                   int pointt = play_sample(point, 255, 0, 1000, 0);  
                                   MovePlayer1(&obj.p[0],'r',&sprite);
                                   obj.p[0].score++;
                              }
                               if(obj.p[1].y > 50) {
                                             
                                             install_int_ex(timer2, BPS_TO_TIMER(10));
                                               if(VerifP2Stun && ticks2 <= 10){
                                                              if(ticks2 <= 5) MovePlayer2 (&obj.p[1],'c',&sprite);
                                                              else if(ticks2 >5 && ticks2 <= 10);
                                                               
                                               }
                                             else if(key[KEY_UP]) MovePlayer2 (&obj.p[1],'u',&sprite);
                                             else if(key[KEY_DOWN]) MovePlayer2 (&obj.p[1],'d',&sprite);
                                             if(ticks2 > 10) {
                                                        VerifP2Stun = false; 
                                                        ticks2 = 0;
                                               }
                               
                               }
                               else {
                                    int pointt = play_sample(point, 255, 0, 1000, 0);
                                    MovePlayer2 (&obj.p[1],'r',&sprite);
                                    obj.p[1].score++;
                               }
                              MoveCarro(obj.car); 
                              ImprimeTela(obj,score);
                             
                          }    
                              
                        if(VerifColisao(obj.car,obj.p[0])) {
                              stop_sample(chickenfx_p1);                           
                              int galinha = play_sample(chickenfx_p1, 255, 0, 1000, 0);                              
                              ticks = 0;
                              VerifP1Stun = true;

                                           
                               
                        }
                        if(VerifColisao(obj.car,obj.p[1])) {
                              stop_sample(chickenfx_p2);                           
                              int galinha = play_sample(chickenfx_p2, 255, 0, 1000, 0);  
                              ticks2 = 0;
                              VerifP2Stun = true;

                                           
                               
                        }
                        if(msecs >= 120) {
                                      msecs = 0;
                                      stop_sample(temajogo);
                                      int game_theme = play_sample(temajogo, 255, 0, 1000, 0);
                                      
                        }
             
            
    }
    pos_jogo(obj);      
    if(game_over) rest(1500);
    free(obj.car);
    stop_sample(temajogo);
    destroy_font(score);
    
}

void pos_jogo (objeto obj) {
     
            FILE *fp;
            char quebra[2];
            int qtd, i, j;
            switch (dificuldade) {
                   
                   case easy:
                        fp = fopen("highscores_easy.txt","r+");
                        break;
                   case medium:
                        fp = fopen("highscores_medium.txt","r+");
                        break;
                   case hard:
                        fp = fopen("highscores_hard.txt","r+");
                        break;
            }
            if(fp == NULL) {
                  allegro_message("ERRO!!");
                  exit(1);
            }
            fscanf(fp,"%d",&qtd);
            player_aux *paux, var_aux;
            paux = (player_aux *)malloc((qtd+1) * sizeof(player_aux));
            fgets(quebra,2,fp);
            for(i =0; i < qtd; i++) {
                    fgets(paux[i].nome,20,fp);
                    fscanf(fp,"%d",&paux[i].score);             
                    paux[i].nome[strlen(paux[i].nome)-1] = '\0';   
                    fgets(quebra,2,fp);
        
                    
            }
            fflush(stdin);
            for(int k = 0; k < 2; k++) {
                strcpy(paux[qtd].nome,obj.p[k].nome);
                paux[qtd].score = obj.p[k].score;
                for(i = qtd; i >=1; i--) {
                      for(j = 0; j < i; j++) {
                            
                            if(paux[j+1].score >= paux[j].score) {
                                          var_aux = paux[j];
                                          paux[j] = paux[j+1];
                                          paux[j+1] = var_aux;
                            }
                      }
                }
            }
            fseek(fp,0,SEEK_SET);
            if(qtd < 5) {
                   qtd++;
            }
            else {
                 qtd = 5;
            }
            fprintf(fp,"%d\n",qtd);
            for(i = 0; i < qtd; i++) {
                  fprintf(fp,"%s\n%d\n",paux[i].nome,paux[i].score);
            }
            fclose(fp);
            free(paux);
          
          
}


void highscores ( ) {
            
            FILE *fp;
            BITMAP* buff = create_bitmap(800,600);;
            BITMAP *postgame = load_bitmap("fundomenu.bmp",NULL); 
            FONT *fontemenu = load_font("freeway.pcx",NULL,NULL);
            char quebra[2];
            int qtd, i, j;
            bool back_to_menu = false;
            chose_diff (&back_to_menu); 
            switch (dificuldade) {
                   
                   case easy:
                        fp = fopen("highscores_easy.txt","r+");
                        break;
                   case medium:
                        fp = fopen("highscores_medium.txt","r+");
                        break;
                   case hard:
                        fp = fopen("highscores_hard.txt","r+");
                        break;
            }                                          
            
            if(fp == NULL) {
                  allegro_message("ERRO!!");
                  exit(1);
            }
            fscanf(fp,"%d",&qtd);
            player_aux *paux, var_aux;
            paux = (player_aux *)malloc((qtd+1) * sizeof(player_aux));
            fgets(quebra,2,fp);
            for(i =0; i < qtd; i++) {
                    fgets(paux[i].nome,20,fp);
                    fscanf(fp,"%d",&paux[i].score);             
                    paux[i].nome[strlen(paux[i].nome)-1] = '\0';   
                    fgets(quebra,2,fp);
                
                    
        
                    
            }
            fclose(fp);
            rest(150);
            while(!key[KEY_ENTER] && !back_to_menu) {  
            stretch_blit(postgame,buff,0,0,postgame->w,postgame->h,0,0,SCREEN_W,SCREEN_H);
                for(i =0; i < qtd; i++) {     
                        textprintf_ex(buff, fontemenu, 100, 100+50*i, makecol(255, 0, 0),-1, "%s",paux[i].nome);
                        textprintf_ex(buff, fontemenu, 600, 100+50*i, makecol(255, 0, 0),-1, "%d",paux[i].score); 
                }  
              textprintf_ex(buff, fontemenu, 200, 500, makecol(0, 0, 0),-1, "Pressione ENTER quando estiver pronto");  
            
              blit(buff,screen,0,0,0,0,SCREEN_W,SCREEN_H); 
              }
              rest(50); 
            destroy_font(fontemenu);
            destroy_bitmap(buff);
            destroy_bitmap(postgame);
            free(paux); 
                
                
            
}
