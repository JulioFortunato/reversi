/*
 * -----------------------------------------------------------------------------
 * Universidade Federal de São Carlos - Campus de Sorocaba
 * Bacharelado em Ciência da Computação
 *
 * Programa: reversi_fase1_JuliaFerruzzi_JulioFortunato
 *
 * Descrição: Este programa representa a interface do jogo 'Reversi' que será
 *            desenvolvido como trabalho final para a disciplina de Algoritmos II
 *
 * Autores: Julia E. Ferruzzi Penha (RA: 552283)
 * 	        Júlio C. Fortunato Filho (RA: 552577)
 *
 * Data da ultima modificacao: 30/10/2013
 *
 * -----------------------------------------------------------------------------
 */

#include <allegro5/allegro.h> //Biblioteca-base do Allegro
#include <allegro5/allegro_image.h> //Bibliteca de imagens
#include <allegro5/allegro_primitives.h> //Biblioteca de primitivas gráficas
#include <allegro5/allegro_font.h> //Biblioteca para o uso de texto
#include <allegro5/allegro_ttf.h> //Biblioteca para o uso de fontes 'True-Type'

int main(void)
{
    //Variáveis auxiliares
    int i;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

    //Variável representado o tabuleiro
    ALLEGRO_DISPLAY *tabuleiro = NULL;
    ALLEGRO_FONT *fonte = NULL;
    ALLEGRO_FONT *fonte2 = NULL;

    //Inicialização das bibliotecas
    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    //Criamos a janela do tabuleiro e especificamos suas dimensões
    tabuleiro = al_create_display(800, 600);
    al_set_window_title(tabuleiro, "Reversi - Julia Ferruzzi e Júlio Fortunato");

    //Pintamos o tabuleiro de verde
    al_clear_to_color(al_map_rgb(0, 102, 51));

    //Carregando o arquivo de fonte
    fonte = al_load_font("UBUNTU.ttf", 38, 0);
    fonte2 = al_load_font("UBUNTU.ttf", 14, 0);

    //Textura do tabuleiro
    ALLEGRO_BITMAP *textura = NULL;
    textura = al_load_bitmap("texturaTabuleiro.fw.png");
    al_draw_bitmap(textura, 0, 0, 0);

    //Desenha as pedras iniciais no tabuleiro
    ALLEGRO_BITMAP *pedraBranca = NULL;
    pedraBranca = al_load_bitmap("pedraBranca.fw.png");
    al_draw_bitmap(pedraBranca, 230, 230, 0);
    al_draw_bitmap(pedraBranca, 300, 300, 0);

    ALLEGRO_BITMAP *pedraPreta = NULL;
    pedraPreta = al_load_bitmap("pedraPreta.fw.png");
    al_draw_bitmap(pedraPreta, 300, 230, 0);
    al_draw_bitmap(pedraPreta, 230, 300, 0);

    //Retangulo interno
    al_draw_rectangle(20.0, 20.0, 580.0, 580.0, al_map_rgb(255, 255, 255), 3.0);

    //Linhas Verticais
    for(i = 90; i <= 510; i = i + 70)
    {
        al_draw_line(i, 20.0, i, 580.0, al_map_rgb(255, 255, 255), 1.0);
    }

    //Linhas Horizontais
    for(i = 90; i <= 510; i = i + 70)
    {
        al_draw_line(20.0, i, 580.0, i, al_map_rgb(255, 255, 255), 1.0);
    }

    // Textos da barra lateral
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 610, 10, ALLEGRO_ALIGN_LEFT, "PLACAR");
    al_draw_text(fonte2, al_map_rgb(255, 255, 255), 610, 60, ALLEGRO_ALIGN_LEFT, "Jogador 1: 0 pontos");
    al_draw_text(fonte2, al_map_rgb(255, 255, 255), 610, 80, ALLEGRO_ALIGN_LEFT, "Jogador 2: 0 pontos");

    //Fila de Eventos
    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_display_event_source(tabuleiro));

    //Atualiza a tela
    al_flip_display();

    //Fechar janela
    while(1)
    {
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);

        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);

        if(tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
    }

    return 0;
}
