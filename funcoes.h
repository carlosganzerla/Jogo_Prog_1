#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
     

void CriaPlayer (player *p, char *nomearqv, int x, int y) {
     p->sprt = load_bitmap(nomearqv,NULL);
     if(p->sprt == NULL) {
                allegro_message("%s faltando! Encerrando o programa",nomearqv);
                exit(1);
     } //carrega a imagem da galinha
     p->x = x; //configura as cordenadas iniciais
     p->y = y;
}



void CriaCarro (carro *car, int level) {
     int rand_gen_1 = 0;
     int rand_gen_2 = 0;
     if(level == easy) {
               for(int i = 0; i < car_nmbr; i++){
             
                     if(i < car_nmbr/2)  car[i].sprt = load_bitmap(carname_vector[rand()%4],NULL);
                     else {
                           car[i].sprt = load_bitmap(carname_vector[rand()%4+5],NULL);
                     }
                           if(car[i].sprt == NULL) {
                            allegro_message("Erro: BITMAP carro faltando! Encerrando o programa...");
                            exit(1);
                            } 
                       if(i<5) car[i].x = -50;
                       else if(i>=5 && i<10) car[i].x = 800; //configura as cordenadas iniciais
                       car[i].y = 460 - lanewidth*i;
                       car[i].veloc = (rand()%4+1);
                       }
             }
             
     else if(level == medium) {
              for(int i = 0; i<10; i++) {
                      rand_gen_1 = (rand()%4+1);
                      rand_gen_2 = (rand()%20)*20+100;
                      for(int j = 0; j <2; j++) {
                              if(i < 5)  car[i*2+j].sprt = load_bitmap(carname_vector[rand()%4],NULL);
                             else {
                             car[i*2+j].sprt = load_bitmap(carname_vector[rand()%4+5],NULL);
                             }     
                            if(car[i*2+j].sprt == NULL) {
                            allegro_message("Erro: BITMAP carro faltando! Encerrando o programa...");
                            exit(1);
                            } 
                            if(i<5) car[i*2+j].x = -80 - rand_gen_2*j; //configura as cordenadas iniciais
                            else if(i>=5 && i<10) car[i*2+j].x = 800 + rand_gen_2*j;
                            car[i*2+j].y = 460 - lanewidth*i;
                            car[i*2+j].veloc = rand_gen_1;
              }
        }
     }
     else if(level == hard) {
              for(int i = 0; i<10; i++) {
                      rand_gen_1 = (rand()%4+1);
                       rand_gen_2 = rand()%240+100;
                      for(int j = 0; j <3; j++) {
                              if(i < 5)  car[i*3+j].sprt = load_bitmap(carname_vector[rand()%4],NULL);
                             else {
                             car[i*3+j].sprt = load_bitmap(carname_vector[rand()%4+5],NULL);
                             }  
                            if(car[i*3+j].sprt == NULL) {
                            allegro_message("Erro: BITMAP carro faltando! Encerrando o programa...");
                            exit(1);
                            }
                            if(i<5) car[i*3+j].x = -80 - rand_gen_2*j;
                            else if(i>=5 && i<10) car[i*3+j].x = 800 + rand_gen_2*j; //configura as cordenadas iniciais
                            car[i*3+j].y = 460 - lanewidth*i;
                            car[i*3+j].veloc = rand_gen_1;
                       }
              }
              
              
     }
                              
                              
                      
             
             

}



void ImprimeCarro(objeto obj, BITMAP *buff);
void ImprimePlayer (objeto obj, BITMAP *buff);
     
void ImprimeTela (objeto obj, FONT *score) {
     BITMAP *fundo;
     fundo = load_bitmap("fundo.bmp",NULL); 
     if(fundo == NULL) {
              allegro_message("Erro: BITMAP fundo.bmp faltando! Encerrando o programa...");
              exit(1);
     }
     BITMAP *buff;
     buff = create_bitmap(SCREEN_W, SCREEN_H); //Cria a memoria para a imagem
     BITMAP *buff2;
     buff2 = create_bitmap(SCREEN_W, SCREEN_H);
     stretch_blit(fundo,buff,0,0,fundo->w,fundo->h,0,0,SCREEN_W,SCREEN_H); //Copia dimensionando para a tela
     ImprimePlayer(obj,buff);
     blit(buff,buff2,0,0,0,0,SCREEN_W,SCREEN_H);
     ImprimeCarro(obj,buff2);
     textprintf_ex(buff2,score, 0, 10, makecol(255,255,255), -1, "%s", obj.p[0].nome);
     textprintf_ex(buff2,score, 200, 10, makecol(255,255,255), -1, "%d", obj.p[0].score);
     textprintf_ex(buff2,score, 550 ,10, makecol(255,255,255), -1, "%d", obj.p[1].score);
     textprintf_ex(buff2,score, 600, 10, makecol(255,255,255), -1, "%s", obj.p[1].nome);
     if(secs < 120) {
             textprintf_ex(buff2,score, 350, 10, makecol(255,255,255), -1, "%d", 120-secs);
     }
     else {
          game_over = true;
          if(obj.p[0].score > obj.p[1].score) {
                textprintf_ex(buff2,score, 250, 250,  makecol(0,0,0), -1, "Player 1 ganhou com %d pontos",obj.p[0].score);
                }
          else if (obj.p[0].score < obj.p[1].score) {
                textprintf_ex(buff2,score, 250, 250,  makecol(0,0,0), -1, "Player 2 ganhou com %d pontos",obj.p[1].score);
                } 
          else {
               textprintf_ex(buff2,score, 250, 250, makecol(0,0,0), -1, "EMPATE!");
               }
              
     }     
     blit(buff2,screen,0,0,0,0,buff2->w,buff2->h); //Copia a imagem buff para a tela          
     
     destroy_bitmap(buff); //Remove a memoria alocada para a imagem auxiliar buff
     destroy_bitmap(buff2);
     destroy_bitmap(fundo);

}

void ImprimeCarro (objeto obj, BITMAP *buff) {
 
     for(int i = 0; i <car_nmbr; i++) {           
             draw_sprite(buff, obj.car[i].sprt, obj.car[i].x, obj.car[i].y); 
     }
}

void ImprimePlayer (objeto obj, BITMAP *buff) {
     draw_sprite(buff, obj.p[0].sprt, obj.p[0].x, obj.p[0].y);
     draw_sprite(buff, obj.p[1].sprt, obj.p[1].x, obj.p[1].y);
     
}

     


void MovePlayer1(player *p, char c, int *sprite){

    if(*sprite < 4) {
          p->sprt = load_bitmap("galinha.bmp",NULL);
          *sprite = *sprite + 1;

                     
     }
     else if(*sprite >=  4) {
          p->sprt = load_bitmap("galinha2.bmp",NULL);
          *sprite = *sprite + 1;
          if(*sprite == 7) {
                     *sprite = 0;
          }
          
      }
      
          
     switch (c){
            case 'u':
            if(p->y <= 520) {
                  p->y=p->y-5;
            }
              else {
                 p->y=520;
            }//move 5 unidades para baixo
                 break;       
            case 'd':
            if(p->y <= 520) {
                 p->y=p->y+5;//move 5 para cima
            }
            else {
                 p->y=520;
            }
                 break;
            case 'r':
                 p->y=p->y=500;
                 break;
            case 'c':
                 if(p->y < 520)
                           p->y=p->y+3;
                 break;
     }     
}

void MovePlayer2(player *p, char c, int *sprite){

    if(*sprite < 4) {
          p->sprt = load_bitmap("galinha.bmp",NULL);
          *sprite = *sprite + 1;

                     
     }
     else if(*sprite >=  4) {
          p->sprt = load_bitmap("galinha2.bmp",NULL);
          *sprite = *sprite + 1;
          if(*sprite == 7) {
                     *sprite = 0;
          }
          
      }
      
      
          
     switch (c){
           case 'u':
            if(p->y <= 520) {
                  p->y=p->y-5;
            }
              else {
                 p->y=520;
            }
                 break;       
            case 'd':
            if(p->y <= 520) {
                 p->y=p->y+5;
            }
            else {
                 p->y=520;
            }
                 break;
            case 'r':
                 p->y=p->y=500;
                 break;
            case 'c':
                 if(p->y < 520)
                           p->y=p->y+3;
                 break;
     }     
}


void MoveCarro (carro *car) {
     
     for(int i = 0; i<car_nmbr/2; i++) {             
             
             if(car[i].x > 800) {
                         
                         car[i].x = -50;
               }
               else {
                    
                 car[i].x = car[i].x + car[i].veloc;
                 
               }
     
        
     }
     for(int i = car_nmbr/2; i<car_nmbr; i++) {
            if(car[i].x < -50) {
                         
                         car[i].x = 800;
               }
               else {
                    
                 car[i].x = car[i].x - car[i].veloc;
                 
                 }
  
     }

}


int *CarCount (carro *car) {
     int *car_p_faixa = (int *) malloc(10*sizeof(int));
     if(car_p_faixa == NULL) exit(2);
     for(int i = 0; i<10; i++) car_p_faixa[i] = 0;
     for(int i = 0; i < car_nmbr; i++) {
             for(int j = 0; j < 10; j++) {
                     if(car[i].y == 460-j*lanewidth) car_p_faixa[j] = car_p_faixa[j] + 1;
             }
     }
     return car_p_faixa;
}

int WhereIsPlayer (player p) {
    short int faixa = 0;
    int lw = lanewidth;
    if(p.y > 460) {faixa = 0;}
    if(p.y <= 460 && p.y> 460-lw) {faixa = 1;}
    if(p.y <= 460-lw && p.y> 460-2*lw) {faixa = 2;}
    if(p.y <= 460-2*lw && p.y> 460-3*lw) {faixa = 3;}
    if(p.y <= 460-3*lw && p.y> 460-4*lw) {faixa = 4;}
    if(p.y <= 460-4*lw && p.y> 460-5*lw) {faixa = 5;}
    if(p.y <= 460-5*lw && p.y> 460-6*lw) {faixa = 6;}
    if(p.y <= 460-6*lw && p.y> 460-7*lw) {faixa = 7;}
    if(p.y <= 460-7*lw && p.y> 460-8*lw) {faixa = 8;}
    if(p.y <= 460-8*lw) {faixa = 9;}
    return faixa;

}

int Somador (int n, carro *car) {
    int soma = 0;
    int *pointer = CarCount(car);
    for(int i = 0; i<n; i++) {
            soma += pointer[i];
    }
    free(pointer);
    return soma;
}


bool VerifColisao(carro *car, player p) {
     
     int nextlane;
     int cont = 0;
     int currlane = WhereIsPlayer(p);
     int prevlane;
     int maskplayer = bitmap_mask_color(p.sprt);
     int player_max_x = p.x + p.sprt->w, player_max_y = p.y + p.sprt->h;
    
     if(currlane == 0) {prevlane = 0; nextlane = 1;}
     else { prevlane = currlane - 1; nextlane = currlane + 1; }
     int prevcars = Somador(prevlane,car) - 1;
     int nextcars = Somador(nextlane,car);
     if(prevcars < 0) prevcars =0;
 
  
          for(int i = prevcars; i < nextcars; i++) {
            
          
           int carro_max_x = car[i].x + car[i].sprt->w, carro_max_y = car[i].y + car[i].sprt->h; 
 
           int xmin = max(p.x, car[i].x);
           int ymin = max(p.y, car[i].y);
    
           int xmax = min(player_max_x, carro_max_x);
           int ymax = min(player_max_y, carro_max_y);
 
              
              int maskcarro = bitmap_mask_color(car[i].sprt);
 
              for (int y = ymin; y < ymax; y++) {
                  for (int x = xmin; x < xmax; x++) {
                      int x1 = x - p.x, y1 = y - p.y;
                      int x2 = x - car[i].x, y2 = y - car[i].y;
 
                      int playercolor = getpixel(p.sprt, x1, y1);
                      int carrocolor = getpixel(car[i].sprt, x2, y2);
 
                if (playercolor != maskplayer && carrocolor  != maskcarro) {           
                   return true;
                   }
                }
         }
    
 
    
    }
    return false;
}
