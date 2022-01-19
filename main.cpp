#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_opengl.h>
#include <cmath>
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <audiere.h>

using namespace std;
using namespace audiere;




string intToStr(int n)
{
     string tmp;
     if(n < 0) {
      tmp = "-";
      n = -n;
     }
     if(n > 9)
      tmp += intToStr(n / 10);
     tmp += n % 10 + 48;
     return tmp;
}



class Object
{

public:
    Object();
    bool display;
    bool solid;
    int texture;
    int x, y;
    int type;
    bool exist;
    int fuse;
    int power;
    int direction;
    int ax, ay;

    void load(int a, int b, int c, int d, int e, int f, int g, int h, int i)
    {
        display=a;
        solid=b;
        texture=c;
        x=d;
        y=e;
        type=f;
        exist=g;
        fuse=h;
        power=i;
        direction=0;
        ax=0;
        ay=0;
    }

    void destroy()
    {
        display=0;
        solid=0;
        texture=0;
        x=0;
        y=0;
        type=0;
        exist=0;
        fuse=0;
        power=0;
        direction=0;
        ax=0;
        ay=0;
    }

};

Object::Object()
{
    display=0;
    solid=0;
    texture=0;
    x=0;
    y=0;
    type=0;
    exist=0;
    fuse=0;
    power=0;
    direction=0;
};

int lvl=1;
int chapter=1;

int screen_w=0;
int screen_h=0;

int points_count=0;
int level_count=0;
int chapter_count=0;
float poziom_dzwieku=0.5;

int stop_samouczek=0;
int kolejka_1=0;
int animacja=0;
int w=16;
int h=9;

float music_volume=0;
float effects_volume=0;
float przesun_vol=0;
float przesun_vol_01=0;

 bool restartowanie=0;

 bool toturial=0;
 bool show_fps=0;

 int sterowanie_1=1;
 int sterowanie_2=4;
 int sterowanie_3=23;
 int sterowanie_4=19;
 int sterowanie_plant=15;

   string klawisz_1="";
   string klawisz_2="";
   string klawisz_3="";
   string klawisz_4="";

   string klawisz_plant="";




bool samouczek(ALLEGRO_DISPLAY *okno, int jaki_level, int jaki_chapter)
{
    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_MOUSE_STATE myszka;
    al_set_target_bitmap(al_get_backbuffer(okno));

   // ALLEGRO_FONT * font  = al_load_ttf_font("Font.otf",72,0 );
     ALLEGRO_FONT * menu_font  = al_load_ttf_font("menu_text.otf",72,0 );
    ALLEGRO_FONT * menu_font_36  = al_load_ttf_font("menu_text.otf",36,0 );
    al_get_keyboard_state(&klawiatura);
    al_get_mouse_state(&myszka);
    ALLEGRO_BITMAP *button_x = al_load_bitmap("button_X.png");
    ALLEGRO_BITMAP *button_ok = al_load_bitmap("button_OK.png");
    ALLEGRO_BITMAP *gold_bomb = al_load_bitmap("texture_26.png");
    ALLEGRO_BITMAP *red_bomb = al_load_bitmap("texture_10.png");
     ALLEGRO_BITMAP *fire_up = al_load_bitmap("texture_04.png");
      ALLEGRO_BITMAP *fire_left = al_load_bitmap("texture_05.png");
    ALLEGRO_BITMAP *fire_01 = al_load_bitmap("texture_06.png");
    ALLEGRO_BITMAP *fire_02 = al_load_bitmap("texture_07.png");
    ALLEGRO_BITMAP *fire_03 = al_load_bitmap("texture_08.png");
    ALLEGRO_BITMAP *fire_04 = al_load_bitmap("texture_09.png");
    ALLEGRO_BITMAP *fire_05 = al_load_bitmap("texture_03.png");
    ALLEGRO_BITMAP *black_bomb = al_load_bitmap("texture_02.png");
    ALLEGRO_BITMAP *red_block = al_load_bitmap("texture_01.png");
    ALLEGRO_BITMAP *blue_bomb = al_load_bitmap("texture_20.png");
     ALLEGRO_BITMAP *yellow_bomb = al_load_bitmap("texture_21.png");
       ALLEGRO_BITMAP *orange_bomb = al_load_bitmap("texture_22.png");
    ALLEGRO_BITMAP *floor = al_load_bitmap("floor.png");



    bool k=0;

 //al_clear_to_color(al_map_rgba_f(0,0,0,0.9));
   al_draw_filled_rectangle(0, 0, screen_w, screen_h, al_map_rgba_f(0,0,0,0.8));
    double czas = al_get_time();


    while( !al_key_down( &klawiatura, ALLEGRO_KEY_F10) && !al_key_down( &klawiatura, ALLEGRO_KEY_ESCAPE))
    {
        if ( al_get_time() > czas + 0.02)
        {
           if(kolejka_1==1) animacja++;
        czas = al_get_time();
        }
          al_get_mouse_state(&myszka);
        al_get_keyboard_state(&klawiatura);

        al_draw_filled_rounded_rectangle(screen_w/2-400,screen_h/2-105,screen_w/2+400,screen_h/2-45, 20, 20 ,al_map_rgb(125,120,20));
        al_draw_textf(menu_font,al_map_rgb(255,255,255), screen_w/2, screen_h/2-300, ALLEGRO_ALIGN_CENTRE,"Tutorial");
         //al_draw_textf(font_small,al_map_rgb(255,255,255), screen_w/2+300, screen_h/2+150, ALLEGRO_ALIGN_CENTRE,"kolejka%d", kolejka_1);


       al_draw_bitmap(button_x, screen_w/2+400, screen_h/2-200,0);
       al_draw_bitmap(button_ok, screen_w/2+300, screen_h/2+150,0);

       al_draw_bitmap(floor, screen_w/2-150, screen_h/2+100,0);
        al_draw_bitmap(floor, screen_w/2+50, screen_h/2+100,0);
        al_draw_bitmap(floor, screen_w/2-50, screen_h/2,0);
        al_draw_bitmap(floor, screen_w/2-50, screen_h/2+200,0);
        al_draw_bitmap(floor, screen_w/2-50, screen_h/2+100,0);





 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^>>>>>>>>>>>>>>SAMUCZEK>>>>>>LVL1>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
if(jaki_level==1 && jaki_chapter==1)
      {

    if(kolejka_1==0)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1){k=1;kolejka_1=1; }

        }

       al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "Your goal is to collect all the gold bombs");

        al_draw_bitmap(gold_bomb, screen_w/2-50, screen_h/2+100,0);

    }

    if(kolejka_1==1)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1 && kolejka_1==1 && k==0){kolejka_1=0;stop_samouczek=1;myszka.buttons=0; return 0; }
        }

         if(animacja<50){al_draw_bitmap(red_bomb, screen_w/2-50, screen_h/2+100,0);}

          if(animacja>50)
          {
                al_draw_bitmap(fire_01, screen_w/2-50, screen_h/2,0);
                al_draw_bitmap(fire_02, screen_w/2-150, screen_h/2+100,0);
                al_draw_bitmap(fire_03, screen_w/2-50, screen_h/2+200,0);
                al_draw_bitmap(fire_04, screen_w/2+50, screen_h/2+100,0);
                al_draw_bitmap(fire_05, screen_w/2-50, screen_h/2+100,0);
          }
          if(animacja>125)animacja=0;
          al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "This is a red bomb, don't get close to it!");
    }
    }

  //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^>>>>>>>>>>>>>>SAMUCZEK>>>>>>LVL4>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


if(jaki_level==4 && jaki_chapter==1)
      {

        if(kolejka_1==0)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1){k=1;kolejka_1=1; }

        }
       al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "To jest czarna bomba, możesz ją zebrać");
        al_draw_bitmap(black_bomb, screen_w/2-50, screen_h/2+100,0);
    }
      if(kolejka_1==1)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1 && kolejka_1==1 && k==0){kolejka_1=0;stop_samouczek=1;myszka.buttons=0; return 0; }
        }

         if(animacja<50){al_draw_bitmap(black_bomb, screen_w/2-50, screen_h/2+100,0);   al_draw_bitmap(red_block, screen_w/2+50, screen_h/2+100,0);}
          if(animacja>50)
          {
                al_draw_bitmap(fire_01, screen_w/2-50, screen_h/2,0);
                al_draw_bitmap(fire_02, screen_w/2-150, screen_h/2+100,0);
                al_draw_bitmap(fire_03, screen_w/2-50, screen_h/2+200,0);
                al_draw_bitmap(fire_04, screen_w/2+50, screen_h/2+100,0);
                al_draw_bitmap(fire_05, screen_w/2-50, screen_h/2+100,0);
          }
          if(animacja>125)animacja=0;
          al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "Mozesz podłożyc bombe na klawiszu SPACE, mozesz zniszczyc tym ten blok");
    }

      }

   //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^>>>>>>>>>>>>>>SAMUCZEK>>>>>>LVL5>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

      if(jaki_level==5 && jaki_chapter==1)
      {
           kolejka_1=1;
    if(kolejka_1==1)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1 && kolejka_1==1 && k==0){kolejka_1=0;stop_samouczek=1;myszka.buttons=0; return 0; }
        }

         if(animacja<50){al_draw_bitmap(black_bomb, screen_w/2-50, screen_h/2+100,0);}al_draw_bitmap(gold_bomb, screen_w/2+50, screen_h/2+100,0);

          if(animacja>50)
          {
                al_draw_bitmap(fire_01, screen_w/2-50, screen_h/2,0);
                al_draw_bitmap(fire_02, screen_w/2-150, screen_h/2+100,0);
                al_draw_bitmap(fire_03, screen_w/2-50, screen_h/2+200,0);
                al_draw_bitmap(fire_04, screen_w/2+50, screen_h/2+100,0);
                al_draw_bitmap(fire_05, screen_w/2-50, screen_h/2+100,0);
          }
          if(animacja>125)animacja=0;
          al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "Musisz uwazac aby nie zniszczyc zlotej bomby, wtedy przegrasz");
    }
    }

     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^>>>>>>>>>>>>>>SAMUCZEK>>>>>>LVL7>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

      if(jaki_level==7 && jaki_chapter==1)
      {
          kolejka_1=1;
    if(kolejka_1==1)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1 && kolejka_1==1 && k==0){kolejka_1=0;stop_samouczek=1;myszka.buttons=0; return 0; }
        }

         if(animacja<100){al_draw_bitmap(blue_bomb, screen_w/2-50, screen_h/2+100,0);}

          if(animacja>100)
          {
                al_draw_bitmap(fire_01, screen_w/2-50, screen_h/2,0);
                al_draw_bitmap(fire_02, screen_w/2-150, screen_h/2+100,0);
                al_draw_bitmap(fire_03, screen_w/2-50, screen_h/2+200,0);
                al_draw_bitmap(fire_04, screen_w/2+50, screen_h/2+100,0);
                al_draw_bitmap(fire_05, screen_w/2-50, screen_h/2+100,0);
          }
          if(animacja>170)animacja=0;
          al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "To jest niebieska bomba, jest to zwykla stala bomba");
    }

    }

 //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^>>>>>>>>>>>>>>SAMUCZEK>>>>>>LVL10>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(jaki_level==10 && jaki_chapter==1)
      {
          kolejka_1=1;
    if(kolejka_1==1)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1 && kolejka_1==1 && k==0){kolejka_1=0;stop_samouczek=1;myszka.buttons=0; return 0; }
        }

         if(animacja<100){al_draw_bitmap(yellow_bomb, screen_w/2-50, screen_h/2+100,0);}

          if(animacja>100)
          {
                al_draw_bitmap(fire_01, screen_w/2-50, screen_h/2,0);
                al_draw_bitmap(fire_02, screen_w/2-150, screen_h/2+100,0);
                al_draw_bitmap(fire_03, screen_w/2-50, screen_h/2+200,0);
                al_draw_bitmap(fire_04, screen_w/2+50, screen_h/2+100,0);
                al_draw_bitmap(fire_05, screen_w/2-50, screen_h/2+100,0);
          }
          if(animacja>170)animacja=0;
          al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "Żółta bomba aktywuje się wtedt gdy do niej podejdziesz");
    }

    }

     //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^>>>>>>>>>>>>>>SAMUCZEK>>>>>>LVL20>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(jaki_level==20 && jaki_chapter==1)
      {
          kolejka_1=1;
    if(kolejka_1==1)
    {
         if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+370 && myszka.y>screen_h/2+150 && myszka.y<screen_h/2+220)
        {
            al_draw_circle( screen_w/2+335, screen_h/2+185, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1 && kolejka_1==1 && k==0){kolejka_1=0;stop_samouczek=1;myszka.buttons=0; return 0; }
        }
         al_draw_bitmap(floor, screen_w/2-150, screen_h/2+100,0);
          al_draw_bitmap(floor, screen_w/2-250, screen_h/2+100,0);
           al_draw_bitmap(floor, screen_w/2-350, screen_h/2+100,0);
            al_draw_bitmap(floor, screen_w/2-450, screen_h/2+100,0);
              al_draw_bitmap(floor, screen_w/2-550, screen_h/2+100,0);
              al_draw_bitmap(floor, screen_w/2-650, screen_h/2+100,0);

         if(animacja<50){al_draw_bitmap(orange_bomb, screen_w/2-50, screen_h/2+100,0);}

          if(animacja>50)
          {
                al_draw_bitmap(fire_up, screen_w/2-50, screen_h/2,0);
                al_draw_bitmap(fire_left, screen_w/2-150, screen_h/2+100,0);
                al_draw_bitmap(fire_up, screen_w/2-50, screen_h/2+200,0);
                al_draw_bitmap(fire_left, screen_w/2+50, screen_h/2+100,0);
                al_draw_bitmap(fire_05, screen_w/2-50, screen_h/2+100,0);
                al_draw_bitmap(fire_left, screen_w/2-150, screen_h/2+100,0);
                al_draw_bitmap(fire_left, screen_w/2-250, screen_h/2+100,0);
                  al_draw_bitmap(fire_left, screen_w/2-350, screen_h/2+100,0);
                    al_draw_bitmap(fire_left, screen_w/2-450, screen_h/2+100,0);
                      al_draw_bitmap(fire_left, screen_w/2-550, screen_h/2+100,0);
                      al_draw_bitmap(fire_02, screen_w/2-650, screen_h/2+100,0);
          }
          if(animacja>125)animacja=0;
          al_draw_textf(menu_font_36,al_map_rgb(255,255,255), screen_w/2, screen_h/2-100, ALLEGRO_ALIGN_CENTRE, "UWAZAJ, pomaranczowa bomba ma duzy zasieg");
    }

    }




    if(myszka.buttons==1)k=1;else k=0;


   if(myszka.x>screen_w/2+400 && myszka.x<screen_w/2+470 && myszka.y>screen_h/2-200 && myszka.y<screen_h/2-130)
        {
            al_draw_circle( screen_w/2+435, screen_h/2-165, 33,al_map_rgb(150,150,240), 5);
            if(myszka.buttons==1){kolejka_1=0;stop_samouczek=1;myszka.buttons=0; return 0;}
        }





        al_flip_display();
    }
}

bool load_info(int &w, int &h)
{
    ifstream plik;
    string dane;

    plik.open("data_02.dat");

        if(!plik.good())
            {
            return 1;
            }

        else
        {

        getline(plik,dane);
        w=atoi(dane.c_str());
        getline(plik,dane);
        h=atoi(dane.c_str());

            plik.close();
            return 1;

        }
}
bool load_info_settings(float &music , float &sounds, bool &fps, bool &toturial)
{
    ifstream plik;
    string dane;

    plik.open("data_03.dat");

        if(!plik.good())
            {
            return 1;
            }

        else
        {
        getline(plik,dane);
        music=atoi(dane.c_str());
        getline(plik,dane);
        sounds=atoi(dane.c_str());
        getline(plik,dane);
        fps=atoi(dane.c_str());
        getline(plik,dane);
        toturial=atoi(dane.c_str());

        music=music/1000;
        sounds=sounds/1000;

            plik.close();
            return 1;

        }
}
void save_info(int &w, int &h)
{

    ofstream plik;
    string dane;

if(!plik.good())
{
    cout << ":)";
    plik.close();
}

if(plik.good())
        {
                plik.open("data_02.dat");
                plik << w << "\n";
                plik << h << "\n";

                plik.close();
        }

}
void save_info_settings(float &music, float &sounds, bool &fps, bool &toturial)
{

    ofstream plik;
    string dane;

if(!plik.good())
{
    cout << ":)";
    plik.close();
}

if(plik.good())
        {
                plik.open("data_03.dat");
                plik << music*1000 << "\n";
                plik << sounds*1000 << "\n";
                plik << fps << "\n";
                plik << toturial << "\n";
                plik.close();
        }

}

void check_keys()
{
    //--------------------------------------------------------------------------------------------------------------KLAWISZ 1
        if(sterowanie_1==1)klawisz_1="A";
        if(sterowanie_1==2)klawisz_1="B";
        if(sterowanie_1==3)klawisz_1="C";
        if(sterowanie_1==4)klawisz_1="D";
        if(sterowanie_1==5)klawisz_1="E";
        if(sterowanie_1==6)klawisz_1="F";
        if(sterowanie_1==7)klawisz_1="G";
        if(sterowanie_1==8)klawisz_1="H";
        if(sterowanie_1==9)klawisz_1="I";
        if(sterowanie_1==10)klawisz_1="J";
        if(sterowanie_1==11)klawisz_1="K";
        if(sterowanie_1==12)klawisz_1="L";
        if(sterowanie_1==13)klawisz_1="M";
        if(sterowanie_1==14)klawisz_1="N";
        if(sterowanie_1==15)klawisz_1="O";
        if(sterowanie_1==16)klawisz_1="P";
        if(sterowanie_1==17)klawisz_1="Q";
        if(sterowanie_1==18)klawisz_1="R";
        if(sterowanie_1==19)klawisz_1="S";
        if(sterowanie_1==20)klawisz_1="T";
        if(sterowanie_1==21)klawisz_1="U";
        if(sterowanie_1==22)klawisz_1="V";
        if(sterowanie_1==23)klawisz_1="W";
        if(sterowanie_1==24)klawisz_1="X";
        if(sterowanie_1==25)klawisz_1="Y";
        if(sterowanie_1==26)klawisz_1="Z";

        if(sterowanie_1==37)klawisz_1="PAD_0";
        if(sterowanie_1==38)klawisz_1="PAD_1";
        if(sterowanie_1==39)klawisz_1="PAD_2";
        if(sterowanie_1==40)klawisz_1="PAD_3";
        if(sterowanie_1==41)klawisz_1="PAD_4";
        if(sterowanie_1==42)klawisz_1="PAD_5";
        if(sterowanie_1==43)klawisz_1="PAD_6";
        if(sterowanie_1==44)klawisz_1="PAD_7";
        if(sterowanie_1==45)klawisz_1="PAD_8";
        if(sterowanie_1==46)klawisz_1="PAD_9";

        if(sterowanie_1==63)klawisz_1="BACKSPACE";
        if(sterowanie_1==64)klawisz_1="TAB";
        if(sterowanie_1==67)klawisz_1="ENTER";
        if(sterowanie_1==75)klawisz_1="SPACE";

        if(sterowanie_1==82)klawisz_1="LEFT";
        if(sterowanie_1==83)klawisz_1="RIGHT";
        if(sterowanie_1==84)klawisz_1="UP";
        if(sterowanie_1==85)klawisz_1="DOWN";

        if(sterowanie_1==215)klawisz_1="LSHIFT";
        if(sterowanie_1==216)klawisz_1="RSHIFT";
        if(sterowanie_1==217)klawisz_1="LCTRL";
        if(sterowanie_1==218)klawisz_1="RCTRL";
        if(sterowanie_1==219)klawisz_1="ALT";
        if(sterowanie_1==220)klawisz_1="ALTGR";

//--------------------------------------------------------------------------------------------------------------KLAWISZ 2

        if(sterowanie_2==1)klawisz_2="A";
        if(sterowanie_2==2)klawisz_2="B";
        if(sterowanie_2==3)klawisz_2="C";
        if(sterowanie_2==4)klawisz_2="D";
        if(sterowanie_2==5)klawisz_2="E";
        if(sterowanie_2==6)klawisz_2="F";
        if(sterowanie_2==7)klawisz_2="G";
        if(sterowanie_2==8)klawisz_2="H";
        if(sterowanie_2==9)klawisz_2="I";
        if(sterowanie_2==10)klawisz_2="J";
        if(sterowanie_2==11)klawisz_2="K";
        if(sterowanie_2==12)klawisz_2="L";
        if(sterowanie_2==13)klawisz_2="M";
        if(sterowanie_2==14)klawisz_2="N";
        if(sterowanie_2==15)klawisz_2="O";
        if(sterowanie_2==16)klawisz_2="P";
        if(sterowanie_2==17)klawisz_2="Q";
        if(sterowanie_2==18)klawisz_2="R";
        if(sterowanie_2==19)klawisz_2="S";
        if(sterowanie_2==20)klawisz_2="T";
        if(sterowanie_2==21)klawisz_2="U";
        if(sterowanie_2==22)klawisz_2="V";
        if(sterowanie_2==23)klawisz_2="W";
        if(sterowanie_2==24)klawisz_2="X";
        if(sterowanie_2==25)klawisz_2="Y";
        if(sterowanie_2==26)klawisz_2="Z";

        if(sterowanie_2==37)klawisz_2="PAD_0";
        if(sterowanie_2==38)klawisz_2="PAD_1";
        if(sterowanie_2==39)klawisz_2="PAD_2";
        if(sterowanie_2==40)klawisz_2="PAD_3";
        if(sterowanie_2==41)klawisz_2="PAD_4";
        if(sterowanie_2==42)klawisz_2="PAD_5";
        if(sterowanie_2==43)klawisz_2="PAD_6";
        if(sterowanie_2==44)klawisz_2="PAD_7";
        if(sterowanie_2==45)klawisz_2="PAD_8";
        if(sterowanie_2==46)klawisz_2="PAD_9";

        if(sterowanie_2==63)klawisz_2="BACKSPACE";
        if(sterowanie_2==64)klawisz_2="TAB";
        if(sterowanie_2==67)klawisz_2="ENTER";
        if(sterowanie_2==75)klawisz_2="SPACE";

        if(sterowanie_2==82)klawisz_2="LEFT";
        if(sterowanie_2==83)klawisz_2="RIGHT";
        if(sterowanie_2==84)klawisz_2="UP";
        if(sterowanie_2==85)klawisz_2="DOWN";

        if(sterowanie_2==215)klawisz_2="LSHIFT";
        if(sterowanie_2==216)klawisz_2="RSHIFT";
        if(sterowanie_2==217)klawisz_2="LCTRL";
        if(sterowanie_2==218)klawisz_2="RCTRL";
        if(sterowanie_2==219)klawisz_2="ALT";
        if(sterowanie_2==220)klawisz_2="ALTGR";

        //--------------------------------------------------------------------------------------------------------------KLAWISZ 3

        if(sterowanie_3==1)klawisz_3="A";
        if(sterowanie_3==2)klawisz_3="B";
        if(sterowanie_3==3)klawisz_3="C";
        if(sterowanie_3==4)klawisz_3="D";
        if(sterowanie_3==5)klawisz_3="E";
        if(sterowanie_3==6)klawisz_3="F";
        if(sterowanie_3==7)klawisz_3="G";
        if(sterowanie_3==8)klawisz_3="H";
        if(sterowanie_3==9)klawisz_3="I";
        if(sterowanie_3==10)klawisz_3="J";
        if(sterowanie_3==11)klawisz_3="K";
        if(sterowanie_3==12)klawisz_3="L";
        if(sterowanie_3==13)klawisz_3="M";
        if(sterowanie_3==14)klawisz_3="N";
        if(sterowanie_3==15)klawisz_3="O";
        if(sterowanie_3==16)klawisz_3="P";
        if(sterowanie_3==17)klawisz_3="Q";
        if(sterowanie_3==18)klawisz_3="R";
        if(sterowanie_3==19)klawisz_3="S";
        if(sterowanie_3==20)klawisz_3="T";
        if(sterowanie_3==21)klawisz_3="U";
        if(sterowanie_3==22)klawisz_3="V";
        if(sterowanie_3==23)klawisz_3="W";
        if(sterowanie_3==24)klawisz_3="X";
        if(sterowanie_3==25)klawisz_3="Y";
        if(sterowanie_3==26)klawisz_3="Z";

        if(sterowanie_3==37)klawisz_3="PAD_0";
        if(sterowanie_3==38)klawisz_3="PAD_1";
        if(sterowanie_3==39)klawisz_3="PAD_2";
        if(sterowanie_3==40)klawisz_3="PAD_3";
        if(sterowanie_3==41)klawisz_3="PAD_4";
        if(sterowanie_3==42)klawisz_3="PAD_5";
        if(sterowanie_3==43)klawisz_3="PAD_6";
        if(sterowanie_3==44)klawisz_3="PAD_7";
        if(sterowanie_3==45)klawisz_3="PAD_8";
        if(sterowanie_3==46)klawisz_3="PAD_9";

        if(sterowanie_3==63)klawisz_3="BACKSPACE";
        if(sterowanie_3==64)klawisz_3="TAB";
        if(sterowanie_3==67)klawisz_3="ENTER";
        if(sterowanie_3==75)klawisz_3="SPACE";

        if(sterowanie_3==82)klawisz_3="LEFT";
        if(sterowanie_3==83)klawisz_3="RIGHT";
        if(sterowanie_3==84)klawisz_3="UP";
        if(sterowanie_3==85)klawisz_3="DOWN";

        if(sterowanie_3==215)klawisz_3="LSHIFT";
        if(sterowanie_3==216)klawisz_3="RSHIFT";
        if(sterowanie_3==217)klawisz_3="LCTRL";
        if(sterowanie_3==218)klawisz_3="RCTRL";
        if(sterowanie_3==219)klawisz_3="ALT";
        if(sterowanie_3==220)klawisz_3="ALTGR";

    //--------------------------------------------------------------------------------------------------------------KLAWISZ 4

        if(sterowanie_4==1)klawisz_4="A";
        if(sterowanie_4==2)klawisz_4="B";
        if(sterowanie_4==3)klawisz_4="C";
        if(sterowanie_4==4)klawisz_4="D";
        if(sterowanie_4==5)klawisz_4="E";
        if(sterowanie_4==6)klawisz_4="F";
        if(sterowanie_4==7)klawisz_4="G";
        if(sterowanie_4==8)klawisz_4="H";
        if(sterowanie_4==9)klawisz_4="I";
        if(sterowanie_4==10)klawisz_4="J";
        if(sterowanie_4==11)klawisz_4="K";
        if(sterowanie_4==12)klawisz_4="L";
        if(sterowanie_4==13)klawisz_4="M";
        if(sterowanie_4==14)klawisz_4="N";
        if(sterowanie_4==15)klawisz_4="O";
        if(sterowanie_4==16)klawisz_4="P";
        if(sterowanie_4==17)klawisz_4="Q";
        if(sterowanie_4==18)klawisz_4="R";
        if(sterowanie_4==19)klawisz_4="S";
        if(sterowanie_4==20)klawisz_4="T";
        if(sterowanie_4==21)klawisz_4="U";
        if(sterowanie_4==22)klawisz_4="V";
        if(sterowanie_4==23)klawisz_4="W";
        if(sterowanie_4==24)klawisz_4="X";
        if(sterowanie_4==25)klawisz_4="Y";
        if(sterowanie_4==26)klawisz_4="Z";

        if(sterowanie_4==37)klawisz_4="PAD_0";
        if(sterowanie_4==38)klawisz_4="PAD_1";
        if(sterowanie_4==39)klawisz_4="PAD_2";
        if(sterowanie_4==40)klawisz_4="PAD_3";
        if(sterowanie_4==41)klawisz_4="PAD_4";
        if(sterowanie_4==42)klawisz_4="PAD_5";
        if(sterowanie_4==43)klawisz_4="PAD_6";
        if(sterowanie_4==44)klawisz_4="PAD_7";
        if(sterowanie_4==45)klawisz_4="PAD_8";
        if(sterowanie_4==46)klawisz_4="PAD_9";

        if(sterowanie_4==63)klawisz_4="BACKSPACE";
        if(sterowanie_4==64)klawisz_4="TAB";
        if(sterowanie_4==67)klawisz_4="ENTER";
        if(sterowanie_4==75)klawisz_4="SPACE";

        if(sterowanie_4==82)klawisz_4="LEFT";
        if(sterowanie_4==83)klawisz_4="RIGHT";
        if(sterowanie_4==84)klawisz_4="UP";
        if(sterowanie_4==85)klawisz_4="DOWN";

        if(sterowanie_4==215)klawisz_4="LSHIFT";
        if(sterowanie_4==216)klawisz_4="RSHIFT";
        if(sterowanie_4==217)klawisz_4="LCTRL";
        if(sterowanie_4==218)klawisz_4="RCTRL";
        if(sterowanie_4==219)klawisz_4="ALT";
        if(sterowanie_4==220)klawisz_4="ALTGR";

              //--------------------------------------------------------------------------------------------------------------KLAWISZ plant

        if(sterowanie_plant==1)klawisz_plant="A";
        if(sterowanie_plant==2)klawisz_plant="B";
        if(sterowanie_plant==3)klawisz_plant="C";
        if(sterowanie_plant==4)klawisz_plant="D";
        if(sterowanie_plant==5)klawisz_plant="E";
        if(sterowanie_plant==6)klawisz_plant="F";
        if(sterowanie_plant==7)klawisz_plant="G";
        if(sterowanie_plant==8)klawisz_plant="H";
        if(sterowanie_plant==9)klawisz_plant="I";
        if(sterowanie_plant==10)klawisz_plant="J";
        if(sterowanie_plant==11)klawisz_plant="K";
        if(sterowanie_plant==12)klawisz_plant="L";
        if(sterowanie_plant==13)klawisz_plant="M";
        if(sterowanie_plant==14)klawisz_plant="N";
        if(sterowanie_plant==15)klawisz_plant="O";
        if(sterowanie_plant==16)klawisz_plant="P";
        if(sterowanie_plant==17)klawisz_plant="Q";
        if(sterowanie_plant==18)klawisz_plant="R";
        if(sterowanie_plant==19)klawisz_plant="S";
        if(sterowanie_plant==20)klawisz_plant="T";
        if(sterowanie_plant==21)klawisz_plant="U";
        if(sterowanie_plant==22)klawisz_plant="V";
        if(sterowanie_plant==23)klawisz_plant="W";
        if(sterowanie_plant==24)klawisz_plant="X";
        if(sterowanie_plant==25)klawisz_plant="Y";
        if(sterowanie_plant==26)klawisz_plant="Z";

        if(sterowanie_plant==37)klawisz_plant="PAD_0";
        if(sterowanie_plant==38)klawisz_plant="PAD_1";
        if(sterowanie_plant==39)klawisz_plant="PAD_2";
        if(sterowanie_plant==40)klawisz_plant="PAD_3";
        if(sterowanie_plant==41)klawisz_plant="PAD_4";
        if(sterowanie_plant==42)klawisz_plant="PAD_5";
        if(sterowanie_plant==43)klawisz_plant="PAD_6";
        if(sterowanie_plant==44)klawisz_plant="PAD_7";
        if(sterowanie_plant==45)klawisz_plant="PAD_8";
        if(sterowanie_plant==46)klawisz_plant="PAD_9";

        if(sterowanie_plant==63)klawisz_plant="BACKSPACE";
        if(sterowanie_plant==64)klawisz_plant="TAB";
        if(sterowanie_plant==67)klawisz_plant="ENTER";
        if(sterowanie_plant==75)klawisz_plant="SPACE";


        if(sterowanie_plant==215)klawisz_plant="LSHIFT";
        if(sterowanie_plant==216)klawisz_plant="RSHIFT";
        if(sterowanie_plant==217)klawisz_plant="LCTRL";
        if(sterowanie_plant==218)klawisz_plant="RCTRL";
        if(sterowanie_plant==219)klawisz_plant="ALT";
        if(sterowanie_plant==220)klawisz_plant="ALTGR";

}



bool check_level(int c, int q)
{
    fstream plik;
    string dane;
    string nazwa;

        nazwa="levels/Chapter ";
        nazwa+=intToStr(c);
        nazwa+="/";
        if(q<100)nazwa+="0";
        if(q<10) nazwa+="0";
        nazwa+=intToStr(q);
        nazwa+=".txt";

        plik.open(nazwa.c_str(), ios::in);

        if(plik.good())
        {
            plik.close();
            cout << "\nOpening file " << nazwa << "\n";
            return true;
        }
        else
        {
            cout << "\nCouldn't open file " << nazwa << "\n";
            return false;
        }
}

bool load_level(int c, int q, Object o[1000], int &w, int &h, int &x, int &y, ALLEGRO_DISPLAY *okno)
{
    al_set_target_bitmap(al_get_backbuffer(okno));
    ALLEGRO_FONT * font8 = al_load_ttf_font("Font.otf",72,0 );
    float progress=0;

    points_count=0;

    al_draw_filled_rectangle(0, 0, screen_w, screen_h, al_map_rgba_f(0,0,0,0.9));

    for(int i=0;i<1000;i++)o[i].destroy();

    fstream plik;
    string dane;
    string nazwa;

        nazwa="levels/Chapter ";
        nazwa+=intToStr(c);
        nazwa+="/";
        if(q<100)nazwa+="0";
        if(q<10) nazwa+="0";
        nazwa+=intToStr(q);
        nazwa+=".txt";
        cout << "\nLoading file " << nazwa << "\n";
        plik.open(nazwa.c_str(), ios::in);

        if(!plik.good())
            {
            cout << "Couldn't load file " << nazwa << "\n\n";
            return 0;
            }

        else {

        getline(plik,dane);
        w=atoi(dane.c_str());
        getline(plik,dane);
        h=atoi(dane.c_str());
        getline(plik,dane);
        x=atoi(dane.c_str())*100;
        getline(plik,dane);
        y=atoi(dane.c_str())*100;
        getline(plik,dane);

        for(int i=0;i<1000;i++)
        {
        int a=0, b=0, c=0, d=0, e=0, f=0, j=0, k=0;

        getline(plik,dane);
        a=atoi(dane.c_str());
        getline(plik,dane);
        b=atoi(dane.c_str());
        getline(plik,dane);
        c=atoi(dane.c_str());
        getline(plik,dane);
        d=atoi(dane.c_str());
        getline(plik,dane);
        e=atoi(dane.c_str());
        getline(plik,dane);
        f=atoi(dane.c_str());
        getline(plik,dane);
        j=atoi(dane.c_str());
        if(j==0)
        {
            progress++;
            al_draw_filled_rectangle(screen_w/2-170,screen_h/2-45,screen_w/2+170, screen_h/2+80, al_map_rgb(255,50,50));
            al_draw_filled_rectangle(screen_w/2-165,screen_h/2+50,screen_w/2+((progress/1000)*330)-165, screen_h/2+70, al_map_rgb(50,255,50));
            al_draw_textf(font8,al_map_rgb(255,255,255), screen_w/2, screen_h/2-30, ALLEGRO_ALIGN_CENTRE, "Loading...");
            continue;
        }
        getline(plik,dane);
        k=atoi(dane.c_str());

        cout << "ID: " << i << " Parameters: " << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << j << " 0 " << k <<"\n";
        o[i].load(a,b,c,d,e,f,j,0,k);

        getline(plik,dane);

        progress++;

        if(f==11)points_count++;

        al_draw_filled_rectangle(screen_w/2-170,screen_h/2-45,screen_w/2+170, screen_h/2+80, al_map_rgb(255,50,50));
        al_draw_filled_rectangle(screen_w/2-165,screen_h/2+50,screen_w/2+((progress/1000)*330)-165, screen_h/2+70, al_map_rgb(50,255,50));
        al_draw_textf(font8,al_map_rgb(255,255,255), screen_w/2, screen_h/2-30, ALLEGRO_ALIGN_CENTRE, "Loading...");

        al_flip_display();

        if(plik.eof())break;

        }

        plik.close();
        return 1;
    }

}

void save_progress(int a)
{
    fstream plik2;
    ofstream plik;
    string dane;

    plik2.open("data.dat");

        if(!plik2.good())
            {
            cout << "Couldn't find file data.dat, creating new one.\n";
            plik.open("data.dat");
            plik << a;
            plik.close();
            }

        else
        {

            getline(plik2,dane);
            if(atoi(dane.c_str())<a)
            {
                plik.open("data.dat");
                plik << a;
                plik.close();
            }
            plik2.close();

        }
}

int check_progress()
{
    ifstream plik;
    string dane;

    plik.open("data.dat");

        if(!plik.good())
            {
            return 1;
            }

        else
        {

            getline(plik,dane);
            plik.close();
            return atoi(dane.c_str());

        }
}


bool k=0;
bool m=0;

int minimenu(ALLEGRO_DISPLAY *okno, int type)
{
    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_MOUSE_STATE myszka;
    al_set_target_bitmap(al_get_backbuffer(okno));

    ALLEGRO_FONT * font8 = al_create_builtin_font();
    int rozmiar_czcionki=screen_w/15;
    int f=screen_w/20;
    ALLEGRO_FONT * font  = al_load_ttf_font("menu_text.otf",rozmiar_czcionki,0 );
    al_get_keyboard_state(&klawiatura);
    al_get_mouse_state(&myszka);

    ALLEGRO_BITMAP *button1 = al_load_bitmap("button1.png");
    ALLEGRO_BITMAP *button2 = al_load_bitmap("button2.png");
    ALLEGRO_BITMAP *button3 = al_load_bitmap("button3.png");
    ALLEGRO_BITMAP *button4 = al_load_bitmap("button4.png");



    double czas = al_get_time();

    if(type==1)save_progress((chapter-1)*30+lvl+1);

    int choose=0;
    al_draw_filled_rectangle(0, 0, screen_w, screen_h, al_map_rgba_f(0,0,0,0.75));

    while(  !al_key_down( &klawiatura, ALLEGRO_KEY_F12))
    {
        if ( al_get_time() > czas + 0.005)
        {
            al_get_keyboard_state(&klawiatura);
            al_get_mouse_state(&myszka);

            if( al_key_down( &klawiatura, ALLEGRO_KEY_ENTER && type==0)){return 3;}


            if(type!=2 && type!=3){  al_draw_scaled_bitmap(button3,0,0,200,200, screen_w/2-(f*7), screen_h/2+(f/2),f*2,f*2,0);}

       // al_draw_bitmap(button2, screen_w/2-300, screen_h/2+50,0);

        al_draw_scaled_bitmap(button2,0,0,200,200,screen_w/2-(f*3) , screen_h/2+(f/2),  f*2,f*2,0);

        al_draw_scaled_bitmap(button1,0,0,200,200, screen_w/2+f , screen_h/2+(f/2),f*2,f*2,0);
         al_draw_scaled_bitmap(button4,0,0,200,200, screen_w/2+(f*5), screen_h/2+(f/2),f*2,f*2,0);





            if(myszka.y>screen_h/2+(f/2) && myszka.y<screen_h/2+(f*2.9))
            {
                if(myszka.x>screen_w/2-(f*7) && myszka.x<screen_w/2-(f*5) && type!=2 && type!=3 )
                {
                    al_draw_circle( screen_w/2-(f*6), screen_h/2+(f*1.5),  f/1.1,al_map_rgb(150,150,240), f/10);
                  // al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
                    choose=1;
                }

           else if(myszka.x>screen_w/2-(f*3) && myszka.x<screen_w/2-f)
                {
                     //  al_draw_circle( screen_w/2-200, screen_h/2+150,93,al_map_rgb(150,150,240), 10);
                        al_draw_circle( screen_w/2-(f*2), screen_h/2+(f*1.5),  f/1.1,al_map_rgb(150,150,240), f/10);
                //    al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
                    choose=2;
                }

           else if(myszka.x>screen_w/2+f && myszka.x<screen_w/2+(f*3))
                {
                     //al_draw_circle( screen_w/2+200, screen_h/2+150,  93,al_map_rgb(150,150,240), 10);
                      al_draw_circle( screen_w/2+(f*2), screen_h/2+(f*1.5),  f/1.1,al_map_rgb(150,150,240), f/10);
               //     al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
                    choose=3;
                }

         else if(myszka.x>screen_w/2+(f*5) && myszka.x<screen_w/2+(f*7))
                {
                   // al_draw_circle( screen_w/2+600, screen_h/2+150, 93,al_map_rgb(150,150,240), 10);
                     al_draw_circle( screen_w/2+(f*6), screen_h/2+(f*1.5),  f/1.1,al_map_rgb(150,150,240), f/10);
                 //   al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
                      choose =4;
                }

            }

            else
            {
              //  al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
                choose=0;
            }





            if(al_key_down( &klawiatura, ALLEGRO_KEY_ENTER))
            {
                if(type==1 || type==0)return 1;
                if(type==2 || type==3)return 2;
            }

            if(al_key_down( &klawiatura, ALLEGRO_KEY_ESCAPE) && !k)
            {
                k=1;
                if(type==0)return 1;
            }
            if(!al_key_down( &klawiatura, ALLEGRO_KEY_ESCAPE)) k=0;

            if(myszka.buttons==1 && choose!=0 && !m)
            {
                m=1;
                return choose;
            }

            if(myszka.buttons!=1)m=0;

            czas = al_get_time();
        }



        if(type==0)al_draw_textf(font,al_map_rgb(235,235,235), screen_w/2, screen_h/2-260, ALLEGRO_ALIGN_CENTER, "PAUSED");
        if(type==1)al_draw_textf(font,al_map_rgb(235,235,235), screen_w/2, screen_h/2-260, ALLEGRO_ALIGN_CENTER, "You have completed the level");
        if(type==2)al_draw_textf(font,al_map_rgb(235,235,235), screen_w/2, screen_h/2-260, ALLEGRO_ALIGN_CENTER, "You died");
        if(type==3)al_draw_textf(font,al_map_rgb(235,235,235), screen_w/2, screen_h/2-260, ALLEGRO_ALIGN_CENTER, "You have lost a point");


        al_flip_display();
        }


    return 0;
}

ALLEGRO_COLOR read_chapter_color1(int c)
{
    fstream plik;
    string dane;
    string nazwa;

    int r=0, g=0, b=0;

        nazwa="levels/Chapter ";
        nazwa+=intToStr(c);
        nazwa+="/000.txt";
        cout << "\nOpening file " << nazwa << "\n";
        plik.open(nazwa.c_str(), ios::in);

        if(!plik.good())
            {
            cout << "Couldn't open file " << nazwa << "\n\n";
            return al_map_rgb(0,0,0);
            }

        getline(plik,dane);
        r=atoi(dane.c_str());
        getline(plik,dane);
        g=atoi(dane.c_str());
        getline(plik,dane);
        b=atoi(dane.c_str());

        plik.close();

        return al_map_rgb(r,g,b);

}

ALLEGRO_COLOR read_chapter_color2(int c)
{
    fstream plik;
    string dane;
    string nazwa;

    int r=0, g=0, b=0;

        nazwa="levels/Chapter ";
        nazwa+=intToStr(c);
        nazwa+="/000.txt";
        cout << "\nOpening file " << nazwa << "\n";
        plik.open(nazwa.c_str(), ios::in);

        if(!plik.good())
            {
            cout << "Couldn't open file " << nazwa << "\n\n";
            return al_map_rgb(0,0,0);
            }

        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        r=atoi(dane.c_str());
        getline(plik,dane);
        g=atoi(dane.c_str());
        getline(plik,dane);
        b=atoi(dane.c_str());

        plik.close();

        return al_map_rgb(r,g,b);

}

ALLEGRO_COLOR read_chapter_color3(int c)
{
    fstream plik;
    string dane;
    string nazwa;

    int r=0, g=0, b=0;

        nazwa="levels/Chapter ";
        nazwa+=intToStr(c);
        nazwa+="/000.txt";
        cout << "\nOpening file " << nazwa << "\n";
        plik.open(nazwa.c_str(), ios::in);

        if(!plik.good())
            {
            cout << "Couldn't open file " << nazwa << "\n\n";
            return al_map_rgb(0,0,0);
            }


        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        getline(plik,dane);
        r=atoi(dane.c_str());
        getline(plik,dane);
        g=atoi(dane.c_str());
        getline(plik,dane);
        b=atoi(dane.c_str());

        plik.close();

        return al_map_rgb(r,g,b);

}

bool intro(ALLEGRO_DISPLAY *okno)
{
AudioDevicePtr device = OpenDevice();

 OutputStreamPtr boom(OpenSound(device, "bomb_01.wav", false));

  if (!boom)
{
     cout << "nie zaladowano pliku dzwiekowego.\n";
     return 1;
}


int f_lvl=screen_w/20;
ALLEGRO_KEYBOARD_STATE klawiatura;
    al_set_target_bitmap(al_get_backbuffer(okno));
     ALLEGRO_FONT * font_menu_1 = al_load_ttf_font("menu_text.otf",f_lvl,0 );
      ALLEGRO_FONT * font_menu_3 = al_load_ttf_font("menu_sett.ttf",f_lvl*3,0 );
     ALLEGRO_FONT * font_menu_2 = al_load_ttf_font("menu_text.otf",f_lvl/2,0 );
    al_clear_to_color(al_map_rgb(0,0,0));

    al_set_new_bitmap_flags ( ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

     ALLEGRO_BITMAP *tlo_intro = al_load_bitmap("tlo_intro.png");
     ALLEGRO_BITMAP *b_1 = al_load_bitmap("texture_10.png");
     ALLEGRO_BITMAP *b_2 = al_load_bitmap("texture_20.png");
     ALLEGRO_BITMAP *b_3 = al_load_bitmap("texture_21.png");
     ALLEGRO_BITMAP *b_4 = al_load_bitmap("texture_22.png");
     ALLEGRO_BITMAP *b_5 = al_load_bitmap("texture_23.png");

     //  ALLEGRO_BITMAP *set_sett = al_load_bitmap("set_sett.png");
       //  ALLEGRO_BITMAP *acc = al_load_bitmap("acc.png");

        al_get_keyboard_state(&klawiatura);

int size_gra=0;
float przyciemnienie=0.97;
float przyciemnienie_2=0.97;
    bool mozna_przyciemniac=0;
      bool mozna_przyciemniac_2=0;
    int window=0;
    int timer=0;
    int timer_2=0;
    int timer_intro=-100;
    bool stop=0;

    double czas = al_get_time();


    while( !al_key_down( &klawiatura, ALLEGRO_KEY_F12))
    {
        size_gra=screen_w/20;
        boom->setVolume(0.08);

        if ( al_get_time() > czas + 0.005)
        {
             al_get_keyboard_state(&klawiatura);
                 al_clear_to_color(al_map_rgb(0,0,0));
             if(window==0)
                {
                timer++;
                if(mozna_przyciemniac==1 && przyciemnienie<1.5)przyciemnienie+=0.01;if(przyciemnienie>=0.99){window=1;return 0;}
                if(mozna_przyciemniac==0 && przyciemnienie<0.98 && przyciemnienie>0 && timer>100)przyciemnienie-=0.01;
                al_draw_text(font_menu_1,al_map_rgb(255,244,255), screen_w/2, screen_h/2-(size_gra*2), ALLEGRO_ALIGN_CENTER,"MriV Studio   and   Vyrto");
                al_draw_text(font_menu_2,al_map_rgb(255,244,255), screen_w/2, screen_h/2-(size_gra*0.5), ALLEGRO_ALIGN_CENTER,"present");
                if(timer>300 && al_key_down( &klawiatura, ALLEGRO_KEY_ESCAPE))window=1;
                if(timer>600)mozna_przyciemniac=1;

                 al_draw_filled_rectangle(0, 0, screen_w, screen_h, al_map_rgba_f(0,0,0,przyciemnienie));

                }
              /*  if(window==1)
                {
                    timer_2++;
                    if(timer_2>300 && stop==0)timer_intro+=5;
                    if(timer_intro>screen_h/2){stop=1;}
                    al_draw_scaled_bitmap(tlo_intro,0,0,1920,1080,0 , 0,  size_gra*20,size_gra*12,0);

                    if(timer_2<620)
                    {
                    al_draw_scaled_bitmap(b_1,0,0,100,100,screen_w/2-size_gra , timer_intro,  size_gra,size_gra,0);
                    al_draw_scaled_bitmap(b_2,0,0,100,100,screen_w/2+size_gra , timer_intro,  size_gra,size_gra,0);
                    al_draw_scaled_bitmap(b_3,0,0,100,100,screen_w/2-(size_gra*3) , timer_intro,  size_gra,size_gra,0);
                    al_draw_scaled_bitmap(b_4,0,0,100,100,screen_w/2+(size_gra*3), timer_intro,  size_gra,size_gra,0);
                    }
                    if(timer_2>600)
                        {
                           boom->play();
                         if(timer_2<620)al_draw_filled_rectangle(0, 0, screen_w, screen_h, al_map_rgb(255,255,255));
                          al_draw_text(font_menu_3,al_map_rgb(10,10,225), screen_w/2, screen_h/2-(size_gra*4), ALLEGRO_ALIGN_CENTER,"B   BMER");
                          al_draw_scaled_bitmap(b_2,0,0,100,100,screen_w/2-(size_gra*3.5) , screen_h/2-(size_gra*3.9),  size_gra*2.9,size_gra*2.9,0);
                           al_draw_scaled_bitmap(b_2,0,0,100,100,screen_w/2-(size_gra*5.8) , screen_h/2-(size_gra*3.9),  size_gra*2.9,size_gra*2.9,0);
                        }


                    if(timer_2>500 && al_key_down( &klawiatura, ALLEGRO_KEY_ESCAPE))return 0;
                    if(timer_2>800)return 0;
                }*/



            czas = al_get_time();
        }




         al_flip_display();
    }
}





bool menu(ALLEGRO_DISPLAY *okno, int window)
{

    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_MOUSE_STATE myszka;

 AudioDevicePtr device = OpenDevice();

 OutputStreamPtr sounds_menu(OpenSound(device, "sounds_menu.wav", false));
 OutputStreamPtr s_mouse_click(OpenSound(device, "mouse_click_01.wav", false));

  if (!sounds_menu || !s_mouse_click)
{
     cout << "nie zaladowano pliku dzwiekowego.\n";
     return 1;
}


int f=screen_w/100;
int f_lvl=screen_w/20;

    al_set_target_bitmap(al_get_backbuffer(okno));
    ALLEGRO_FONT * font8 = al_create_builtin_font();
    ALLEGRO_FONT * font_lvl = al_load_ttf_font("menu_lvl.ttf",f_lvl/2,0 );
     ALLEGRO_FONT * font_menu_1 = al_load_ttf_font("menu_sett.ttf",f_lvl/2,0 );
      ALLEGRO_FONT * font_key = al_load_ttf_font("menu_sett.ttf",f_lvl*1.5,0 );
    ALLEGRO_FONT * font_small = al_load_ttf_font("font_small.ttf",f,0 );
    al_clear_to_color(al_map_rgb(0,0,0));
    al_get_keyboard_state(&klawiatura);
    al_get_mouse_state(&myszka);

    al_set_new_bitmap_flags ( ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_BITMAP *button_play = al_load_bitmap("button_play.png");
    ALLEGRO_BITMAP *button_levels = al_load_bitmap("button_levels.png");
    ALLEGRO_BITMAP *button_quit = al_load_bitmap("button_quit.png");
    ALLEGRO_BITMAP *button_settings = al_load_bitmap("button_settings.png");
    ALLEGRO_BITMAP *back1 = al_load_bitmap("back.png");
    ALLEGRO_BITMAP *back1_sel = al_load_bitmap("back_sel.png");

    ALLEGRO_BITMAP *backgroud_ch1 = al_load_bitmap("backgroud_ch1.png");
    ALLEGRO_BITMAP *backgroud_ch2 = al_load_bitmap("backgroud_ch2.png");
    ALLEGRO_BITMAP *backgroud_ch3 = al_load_bitmap("backgroud_ch3.png");
    ALLEGRO_BITMAP *backgroud_ch4 = al_load_bitmap("backgroud_ch4.png");

        ALLEGRO_BITMAP *tlo_menu = al_load_bitmap("tlo_intro.png");
        ALLEGRO_BITMAP *tlo_menu_rainbow = al_load_bitmap("tlo_rainbow.png");


    ALLEGRO_BITMAP *buttonback = al_load_bitmap("button_back.png");
    ALLEGRO_BITMAP *buttonleft = al_load_bitmap("button_left.png");
    ALLEGRO_BITMAP *buttonup = al_load_bitmap("button_up.png");
    ALLEGRO_BITMAP *buttonright = al_load_bitmap("button_right.png");
    ALLEGRO_BITMAP *buttonRL_sel = al_load_bitmap("button_L_R_sel.png");


    ALLEGRO_BITMAP *logo_fb = al_load_bitmap("logo_facebook.png");
    ALLEGRO_BITMAP *logo_yt = al_load_bitmap("logo_youtube.png");
    ALLEGRO_BITMAP *logo_st = al_load_bitmap("logo_steam.png");

    ALLEGRO_BITMAP *butt1 = al_load_bitmap("butt1.png");
    ALLEGRO_BITMAP *butt1_s = al_load_bitmap("butt1_s.png");
    ALLEGRO_BITMAP *butt2 = al_load_bitmap("butt2.png");
    ALLEGRO_BITMAP *butt2_s = al_load_bitmap("butt2_s.png");
    ALLEGRO_BITMAP *butt3 = al_load_bitmap("butt3.png");
    ALLEGRO_BITMAP *butt3_s = al_load_bitmap("butt3_s.png");

     ALLEGRO_BITMAP *set_volume = al_load_bitmap("set_volume.png");

       ALLEGRO_BITMAP *set_sett = al_load_bitmap("set_sett.png");
         ALLEGRO_BITMAP *acc = al_load_bitmap("acc.png");






    int ruch=0;
    bool stop=0;

    int x_play=0;
    int x_levels=0;
    int x_settings=0;
    int x_quit=0;
    int graj=0;


    float menu_ruch=0;

    float przyciemnienie=0;
    bool mozna_przyciemniac=0;


    level_count=0;
    chapter_count=0;
    int progress=0;

    progress=check_progress();


    for(int j=1; j<=4; j++)
    {
    for(int i=1; i<=30; i++)
    {
        if(check_level(j,i))level_count++;
        else break;
    }
    if(check_level(j,0))chapter_count++;
    }

    int choose=0;
    int choose_1=0;
     int choose_2=0;
    int choose_settings=0;

    int b[14];
    bool show_display=0;

    int stoper=0;
    int size_gra=0;


    bool display_press_the_key=0;
    int typ_key=0;


    double czas = al_get_time();
    music_volume=0;
    effects_volume=0;
load_info_settings(music_volume,effects_volume,show_fps,toturial);
if(przesun_vol!=0)przesun_vol=music_volume*1000;else music_volume=0;
if(przesun_vol_01!=0)przesun_vol_01=effects_volume*1000; else effects_volume=0;

    while( !al_key_down( &klawiatura, ALLEGRO_KEY_F10))
    {
        size_gra=screen_w/20;

  // for(int i=0; i++; i<221)
  // {
        check_keys();


  // }

        if ( al_get_time() > czas + 0.005)
        {
            al_get_keyboard_state(&klawiatura);
            al_get_mouse_state(&myszka);

            sounds_menu->setVolume(music_volume);
            s_mouse_click->setVolume(effects_volume);
          if(!sounds_menu->isPlaying())sounds_menu->play();
           //if(wybuch_01->isPlaying()){wybuch_01->reset();}

            if(mozna_przyciemniac==1 && przyciemnienie<1)przyciemnienie+=0.01;if(przyciemnienie>=0.99)mozna_przyciemniac=false;
            if(mozna_przyciemniac==0 && przyciemnienie>0)przyciemnienie-=0.01;

            if(stop==0)ruch-=40;
        if(stop==1)ruch+=40;
        if(ruch<-2000)stop=1;
        if(ruch>2000)stop=0;

         if(choose_1==0){x_play=(ruch/100);}else x_play=0;
            if(choose_1==1){x_play=(ruch/100);}else x_play=0;
            if(choose_1==2){x_levels=(ruch/100);}else x_levels=0;
            if(choose_1==3){x_settings=(ruch/100);}else x_settings=0;
            if(choose_1==4){x_quit=(ruch/100);}else x_quit=0;

            if(al_key_down( &klawiatura, ALLEGRO_KEY_ENTER)){return true;}
            if(al_key_down( &klawiatura, ALLEGRO_KEY_F10)){return false;}

            if(menu_ruch>0)menu_ruch-=30;
            if(menu_ruch<0)menu_ruch+=30;

            czas = al_get_time();
        }


       // al_play_sample(dzwiek_01, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);



        if(window==0){al_clear_to_color(al_map_rgb(70,70,70));  al_draw_scaled_bitmap(tlo_menu_rainbow,0,0,7680,4320,0 , 0,  size_gra*20,size_gra*12,0);}
  //al_draw_rectangle(0,0,screen_w,screen_h,al_map_rgb(0,0,0),5);

 /*  al_draw_textf(font8,al_map_rgb(1,1,1), 10, 10, ALLEGRO_ALIGN_LEFT,"screen_w %d",screen_w);
   al_draw_textf(font8,al_map_rgb(1,1,1), 10, 30, ALLEGRO_ALIGN_LEFT,"screen_h %d",screen_h);
   al_draw_textf(font8,al_map_rgb(1,1,1), screen_w-120, screen_h-40, ALLEGRO_ALIGN_LEFT,"mouse_x %d",myszka.x);
   al_draw_textf(font8,al_map_rgb(1,1,1), screen_w-120, screen_h-20, ALLEGRO_ALIGN_LEFT,"myszka.y %d",myszka.y);*/


if(window==3)
{
    choose=0;

     if(przyciemnienie>=0.95){window=0;}

        if(al_key_down( &klawiatura, ALLEGRO_KEY_ESCAPE)){choose_2=0;mozna_przyciemniac=true;}
      //  al_draw_filled_rectangle(0,0,screen_w,screen_h,al_map_rgb(24,125,123));
        al_draw_scaled_bitmap(tlo_menu,0,0,screen_w,screen_h,0 , 0, size_gra*20,size_gra*12,0);

 //al_draw_textf(font8,al_map_rgb(1,1,1), 10, 50, ALLEGRO_ALIGN_LEFT,"myszkabutton %d",myszka.buttons);
 //al_draw_textf(font8,al_map_rgb(1,1,1), screen_w-120, screen_h-60, ALLEGRO_ALIGN_LEFT,"choose1 %d",choose_settings);


        al_draw_scaled_bitmap(back1,0,0,120,120,screen_w-200 , screen_h-200,  size_gra,size_gra,0);
        if(myszka.x>screen_w-200 && myszka.x<screen_w-200+size_gra && myszka.y>screen_h-200 && myszka.y<screen_h-200+size_gra)
        {
        al_draw_scaled_bitmap(back1_sel,0,0,120,120,screen_w-200 , screen_h-200,  size_gra,size_gra,0);
        if(myszka.buttons==1){s_mouse_click->play();choose_2=0;display_press_the_key=false;mozna_przyciemniac=true; }
        }

        if(choose_settings==0){al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2, 100, ALLEGRO_ALIGN_CENTRE,"General options");}

        if(choose_settings==2){al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2, 100, ALLEGRO_ALIGN_CENTRE,"Control");}
        if(choose_settings==3){al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2, 100, ALLEGRO_ALIGN_CENTRE,"Audio");}



            al_draw_scaled_bitmap(buttonleft,0,0,120,120,screen_w/2-300-size_gra , 100,  size_gra,size_gra,0);
            al_draw_scaled_bitmap(buttonright,0,0,120,120,screen_w/2+300 , 100,  size_gra,size_gra,0);
if(choose_settings==0)
{
   al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2-(size_gra*3),  size_gra,size_gra,0);
   if(toturial==1){al_draw_scaled_bitmap(acc,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2-(size_gra*3),  size_gra,size_gra,0);}
   al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8), 0,"Tutorial");

    al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2-(size_gra*1.5),  size_gra,size_gra,0);
    if(show_fps==1){al_draw_scaled_bitmap(acc,0,0,200,200,screen_w/2+(size_gra*2) ,screen_h/2-(size_gra*1.5),  size_gra,size_gra,0);}
    al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8)+(size_gra*1.5), 0,"Show FPS");

    al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2,  size_gra,size_gra,0);
     al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8)+(size_gra*3), 0,"Coming soon");

    if(myszka.x>screen_w/2+(size_gra*2) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2-(size_gra*3) && myszka.y<screen_h/2-(size_gra*2))
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
       if(myszka.buttons==1 && toturial==1 && m==0){m=1;toturial=0;save_info_settings(music_volume,effects_volume,show_fps,toturial);}
        if(myszka.buttons==1 && toturial==0 && m==0){m=1;toturial=1;save_info_settings(music_volume,effects_volume,show_fps,toturial);}
   }
   else if(myszka.x>screen_w/2+(size_gra*2) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2-(size_gra*1.5) && myszka.y<screen_h/2-(size_gra*0.5))
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
       if(myszka.buttons==1 && show_fps==1 && m==0){m=1;show_fps=0;save_info_settings(music_volume,effects_volume,show_fps,toturial);}
        if(myszka.buttons==1 && show_fps==0 && m==0){m=1;show_fps=1;save_info_settings(music_volume,effects_volume,show_fps,toturial);}
   }else al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);


}


if(choose_settings==1)
{
al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2, 100, ALLEGRO_ALIGN_CENTRE,"Display");
al_draw_scaled_bitmap(buttonup,0,0,120,120,screen_w/2+300 , screen_h/2-150,  size_gra,size_gra,0);

if(show_display==1)
{
    al_draw_filled_rectangle(screen_w/2+250,screen_h/2-140+size_gra,screen_w/2+450,screen_h/2+150+size_gra,al_map_rgb(240,245,235));
    al_draw_rectangle(screen_w/2+250,screen_h/2-140+size_gra,screen_w/2+450,screen_h/2+150+size_gra,al_map_rgb(0,0,0),5);
    al_draw_text(font_small,al_map_rgb(1,1,b[0]), screen_w/2+250+size_gra, screen_h/2-140+size_gra, ALLEGRO_ALIGN_CENTRE,"800 : 600");
    al_draw_text(font_small,al_map_rgb(1,1,b[1]), screen_w/2+250+size_gra, screen_h/2-120+size_gra, ALLEGRO_ALIGN_CENTRE,"1024 : 768");
    al_draw_text(font_small,al_map_rgb(1,1,b[2]), screen_w/2+250+size_gra, screen_h/2-100+size_gra, ALLEGRO_ALIGN_CENTRE,"1024 : 600");
    al_draw_text(font_small,al_map_rgb(1,1,b[3]), screen_w/2+250+size_gra, screen_h/2-80+size_gra , ALLEGRO_ALIGN_CENTRE,"1280 : 720");
    al_draw_text(font_small,al_map_rgb(1,1,b[4]), screen_w/2+250+size_gra, screen_h/2-60+size_gra , ALLEGRO_ALIGN_CENTRE,"1280 : 800");
    al_draw_text(font_small,al_map_rgb(1,1,b[5]), screen_w/2+250+size_gra, screen_h/2-40+size_gra , ALLEGRO_ALIGN_CENTRE,"1280 : 1024");
    al_draw_text(font_small,al_map_rgb(1,1,b[6]), screen_w/2+250+size_gra, screen_h/2-20+size_gra , ALLEGRO_ALIGN_CENTRE,"1366 : 768");
    al_draw_text(font_small,al_map_rgb(1,1,b[7]), screen_w/2+250+size_gra, screen_h/2+size_gra    , ALLEGRO_ALIGN_CENTRE,"1400 : 1050");
    al_draw_text(font_small,al_map_rgb(1,1,b[8]), screen_w/2+250+size_gra, screen_h/2+20+size_gra , ALLEGRO_ALIGN_CENTRE,"1440 : 900");
    al_draw_text(font_small,al_map_rgb(1,1,b[9]), screen_w/2+250+size_gra, screen_h/2+40+size_gra , ALLEGRO_ALIGN_CENTRE,"1600 : 900");
    al_draw_text(font_small,al_map_rgb(1,1,b[10]), screen_w/2+250+size_gra, screen_h/2+60+size_gra, ALLEGRO_ALIGN_CENTRE,"1680 : 1050");
    al_draw_text(font_small,al_map_rgb(1,1,b[11]), screen_w/2+250+size_gra, screen_h/2+80+size_gra, ALLEGRO_ALIGN_CENTRE,"1920 : 1080");
    al_draw_text(font_small,al_map_rgb(1,1,b[12]), screen_w/2+250+size_gra, screen_h/2+100+size_gra, ALLEGRO_ALIGN_CENTRE,"1920 : 1200");
    al_draw_text(font_small,al_map_rgb(1,1,b[13]), screen_w/2+250+size_gra, screen_h/2+120+size_gra, ALLEGRO_ALIGN_CENTRE,"2048 : 1152");
    stoper++;

}

al_draw_textf(font_menu_1,al_map_rgb(233,233,233), screen_w/2, 400, ALLEGRO_ALIGN_CENTRE,"%d : %d", screen_w , screen_h);

}

if(choose_settings==2)
{
    al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2-(size_gra*3),  size_gra,size_gra,0);
   al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8), 0,"LEFT");

    al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2-(size_gra*1.5),  size_gra,size_gra,0);
    al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8)+(size_gra*1.5), 0,"RIGHT");

    al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2,  size_gra,size_gra,0);
    al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8)+(size_gra*3), 0,"UP");

    al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2+(size_gra*1.5),  size_gra,size_gra,0);
    al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8)+(size_gra*4.5), 0,"DOWN");

     al_draw_scaled_bitmap(set_sett,0,0,200,200,screen_w/2+(size_gra*2) , screen_h/2+(size_gra*3),  size_gra,size_gra,0);
    al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2-(size_gra*2), screen_h/2-(size_gra*2.8)+(size_gra*6), 0,"BOMB");





        al_draw_textf(font_menu_1,al_map_rgb(45,45,45), screen_w/2+(size_gra*2.3), screen_h/2-(size_gra*2.8), 0, "%s", klawisz_1.c_str());
        al_draw_textf(font_menu_1,al_map_rgb(45,45,45), screen_w/2+(size_gra*2.3), screen_h/2-(size_gra*1.3), 0, "%s", klawisz_2.c_str());

        al_draw_textf(font_menu_1,al_map_rgb(45,45,45), screen_w/2+(size_gra*2.3), screen_h/2+(size_gra*0.2), 0, "%s", klawisz_3.c_str());
        al_draw_textf(font_menu_1,al_map_rgb(45,45,45), screen_w/2+(size_gra*2.3), screen_h/2+(size_gra*1.7), 0, "%s", klawisz_4.c_str());
        al_draw_textf(font_menu_1,al_map_rgb(45,45,45), screen_w/2+(size_gra*2.3), screen_h/2+(size_gra*3.2), 0, "%s", klawisz_plant.c_str());


    if(myszka.x>screen_w/2+(size_gra*2) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2-(size_gra*3) && myszka.y<screen_h/2-(size_gra*2) && display_press_the_key==false)
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);

       if(myszka.buttons==1 && m==0 ){ m=0;al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);typ_key=1;display_press_the_key=true;}

   }
   else if(myszka.x>screen_w/2+(size_gra*2) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2-(size_gra*1.5) && myszka.y<screen_h/2-(size_gra*0.5) && display_press_the_key==false)
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
       if(myszka.buttons==1 && m==0){m=0;myszka.buttons=0;al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);typ_key=2;display_press_the_key=true;}

   }
   else if(myszka.x>screen_w/2+(size_gra*2) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2 && myszka.y<screen_h/2+(size_gra))
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
       if(myszka.buttons==1 && m==0){{m=0;myszka.buttons=0;al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);typ_key=3;display_press_the_key=true;}}

   }
   else if(myszka.x>screen_w/2+(size_gra*2) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2+(size_gra*1.5) && myszka.y<screen_h/2+(size_gra*2.5))
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
       if(myszka.buttons==1 && m==0){{m=0;myszka.buttons=0;al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);typ_key=4;display_press_the_key=true;}}

   }
   else if(myszka.x>screen_w/2+(size_gra*2) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2+(size_gra*3) && myszka.y<screen_h/2+(size_gra*4))
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);

        if(myszka.buttons==1 && m==0){m=0;myszka.buttons=0;al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);typ_key=5;display_press_the_key=true;}
   }else al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

   if(display_press_the_key==true){
        al_draw_text(font_key,al_map_rgb(155,31,31), screen_w/2, screen_h/2, ALLEGRO_ALIGN_CENTER, "Press the key ");

        if(al_key_down( &klawiatura, ALLEGRO_KEY_BACKSPACE)){if(typ_key==1){sterowanie_1=63;}if(typ_key==2){sterowanie_2=63;}if(typ_key==3){sterowanie_3=63;}if(typ_key==4){sterowanie_4=63;}if(typ_key==5){sterowanie_plant=63;}typ_key=0;display_press_the_key=false;}
        if(al_key_down( &klawiatura, ALLEGRO_KEY_TAB)){if(typ_key==1){sterowanie_1=64;}if(typ_key==2){sterowanie_2=64;}if(typ_key==3){sterowanie_3=64;}if(typ_key==4){sterowanie_4=64;}if(typ_key==5){sterowanie_plant=64;}typ_key=0;display_press_the_key=false;}
        if(al_key_down( &klawiatura, ALLEGRO_KEY_ENTER)){if(typ_key==1){sterowanie_1=67;}if(typ_key==2){sterowanie_2=67;}if(typ_key==3){sterowanie_3=67;}if(typ_key==4){sterowanie_4=67;}if(typ_key==5){sterowanie_plant=67;}typ_key=0;display_press_the_key=false;}
        if(al_key_down( &klawiatura, ALLEGRO_KEY_SPACE)){if(typ_key==1){sterowanie_1=75;}if(typ_key==2){sterowanie_2=75;}if(typ_key==3){sterowanie_3=75;}if(typ_key==4){sterowanie_4=75;}if(typ_key==5){sterowanie_plant=75;}typ_key=0;display_press_the_key=false;}
        for(int i=1;i<=27;i++)
        {
         if(al_key_down( &klawiatura, i)){if(typ_key==1){sterowanie_1=i;}if(typ_key==2){sterowanie_2=i;}if(typ_key==3){sterowanie_3=i;}if(typ_key==4){sterowanie_4=i;}if(typ_key==5){sterowanie_plant=i;}typ_key=0;display_press_the_key=false;}
        }
         for(int i=37;i<=46;i++)
        {
         if(al_key_down( &klawiatura, i)){if(typ_key==1){sterowanie_1=i;}if(typ_key==2){sterowanie_2=i;}if(typ_key==3){sterowanie_3=i;}if(typ_key==4){sterowanie_4=i;}if(typ_key==5){sterowanie_plant=i;}typ_key=0;display_press_the_key=false;}
        }
          for(int i=82;i<=85;i++)
        {
         if(al_key_down( &klawiatura, i)){if(typ_key==1){sterowanie_1=i;}if(typ_key==2){sterowanie_2=i;}if(typ_key==3){sterowanie_3=i;}if(typ_key==4){sterowanie_4=i;}if(typ_key==5){typ_key=0;display_press_the_key=false;}typ_key=0;display_press_the_key=false;}
        }
           for(int i=215;i<=220;i++)
        {
         if(al_key_down( &klawiatura, i)){if(typ_key==1){sterowanie_1=i;}if(typ_key==2){sterowanie_2=i;}if(typ_key==3){sterowanie_3=i;}if(typ_key==4){sterowanie_4=i;}if(typ_key==5){sterowanie_plant=i;}typ_key=0;display_press_the_key=false;}
        }

   }

}




if(choose_settings==3)
{

   al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2, 100, ALLEGRO_ALIGN_CENTRE,"Audio");

   al_draw_filled_rectangle(screen_w/2-(size_gra*2),screen_h/2-size_gra,screen_w/2-(size_gra*2)+250,screen_h/2-size_gra+(size_gra/10),al_map_rgb(45,45,35));
   al_draw_scaled_bitmap(set_volume,0,0,50,50,screen_w/2-(size_gra*2)+przesun_vol_01,  screen_h/2-size_gra*1.2,  size_gra/2,size_gra/2,0);

   al_draw_filled_rectangle(screen_w/2-(size_gra*2),screen_h/2,screen_w/2-(size_gra*2)+250,screen_h/2+(size_gra/10),al_map_rgb(45,45,35));
   al_draw_scaled_bitmap(set_volume,0,0,50,50,screen_w/2-(size_gra*2)+przesun_vol,  screen_h/2-size_gra/6.5,  size_gra/2,size_gra/2,0);

 if(myszka.x>screen_w/2-(size_gra*4) && myszka.x<screen_w/2+(size_gra*2) && myszka.y>screen_h/2-(size_gra*1.5) && myszka.y<screen_h/2-size_gra/2)
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
       if(myszka.buttons==1){s_mouse_click->play();przesun_vol_01=myszka.x-(size_gra*8);effects_volume=przesun_vol_01/1000;save_info_settings(music_volume,effects_volume,show_fps,toturial);}
       if(effects_volume<0.001)effects_volume=0;
       if(myszka.buttons==1 && myszka.x<myszka.x-(size_gra*8)+20)przesun_vol_01=0;
   }
  else if(myszka.x>screen_w/2-(size_gra*4) && myszka.x<screen_w/2+(size_gra*2) && myszka.y>screen_h/2-size_gra/4 && myszka.y<screen_h/2+size_gra/2)\
   {
       al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
       if(myszka.buttons==1){przesun_vol=myszka.x-(size_gra*8);music_volume=przesun_vol/1000;save_info_settings(music_volume,effects_volume,show_fps,toturial);}
       if(music_volume<0.001)music_volume=0;
       if(myszka.buttons==1 && myszka.x<myszka.x-(size_gra*8)+20)przesun_vol=0;
   } else al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

if(przesun_vol_01>0 && przesun_vol_01<250){al_draw_textf(font_menu_1,al_map_rgb(223,56,56), screen_w/2+size_gra+50, screen_h/2-size_gra*1.2, 0,"%g", przesun_vol_01/2.5);}
else if(przesun_vol_01<1)al_draw_text(font_menu_1,al_map_rgb(223,56,56), screen_w/2+size_gra+50, screen_h/2-size_gra*1.2, 0,"0");
else if(przesun_vol_01>249)al_draw_text(font_menu_1,al_map_rgb(223,56,56), screen_w/2+size_gra+50, screen_h/2-size_gra*1.2, 0,"100");
if(przesun_vol_01>250)przesun_vol_01=250;
if(przesun_vol_01<0)przesun_vol_01=0;


if(przesun_vol>0 && przesun_vol<250){al_draw_textf(font_menu_1,al_map_rgb(123,56,56), screen_w/2+size_gra+50, screen_h/2-size_gra/5, 0,"%g", przesun_vol/2.5);}
else if(przesun_vol<1)al_draw_text(font_menu_1,al_map_rgb(123,56,56), screen_w/2+size_gra+50, screen_h/2-size_gra/5, 0,"0");
else if(przesun_vol>249)al_draw_text(font_menu_1,al_map_rgb(123,56,56), screen_w/2+size_gra+50, screen_h/2-size_gra/5, 0,"100");
if(przesun_vol>250)przesun_vol=250;
if(przesun_vol<0)przesun_vol=0;


}
//al_draw_textf(font8,al_map_rgb(1,1,1), 20, 300, 0,"%d : %d", myszka.x , myszka.y);
//al_draw_textf(font8,al_map_rgb(1,1,1), 20, 320, 0,"%d", przesun_vol );


   // 1280×720 1366×768 1024×600 1600×900 1920×1080 2048×1152



al_draw_text(font_menu_1,al_map_rgb(233,233,233), screen_w/2, 20, ALLEGRO_ALIGN_CENTRE,"Settings" );

            if(!m)
    {
//------------------------------------------------------------------------------------------------OPCJE WYBORU---------------------------
if(myszka.x>screen_w/2-300-size_gra && myszka.x<screen_w/2-300+size_gra && myszka.y>100 && myszka.y<100+size_gra && choose_settings>0)
{
al_draw_scaled_bitmap(buttonRL_sel,0,0,120,120,screen_w/2-300-size_gra , 100,  size_gra,size_gra,0);
if(myszka.buttons==1){m=1;s_mouse_click->play();display_press_the_key=false;choose_settings-=1;}
}
else if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+300+size_gra && myszka.y>100 && myszka.y<100+size_gra && choose_settings<3)
{
al_draw_scaled_bitmap(buttonRL_sel,0,0,120,120,screen_w/2+300 , 100,  size_gra,size_gra,0);
if(myszka.buttons==1 ){m=1;s_mouse_click->play();display_press_the_key=false;choose_settings+=1;}
}



if(choose_settings==1)
{
 if(myszka.x>screen_w/2+300 && myszka.x<screen_w/2+300+size_gra && myszka.y>screen_h/2-150 && myszka.y< screen_h/2-150+size_gra )
{
al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
al_draw_scaled_bitmap(buttonRL_sel,0,0,120,120,screen_w/2+300 ,  screen_h/2-150,  size_gra,size_gra,0);
if(myszka.buttons==1){m=1;s_mouse_click->play();show_display=1;}
if(myszka.buttons==1 && show_display==1 && stoper>500){show_display=0;stoper=0;}
}else al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);


//screen_w/2+250+size_gra, screen_h/2-140+size_gra
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-155+size_gra && myszka.y<screen_h/2-155+f+size_gra){b[0]=220;if(myszka.buttons==1){screen_w=800;screen_h=600;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[0]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-135+size_gra && myszka.y<screen_h/2-135+f+size_gra){b[1]=220;if(myszka.buttons==1){screen_w=1024;screen_h=768;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[1]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-115+size_gra && myszka.y<screen_h/2-115+f+size_gra){b[2]=220;if(myszka.buttons==1){screen_w=1024;screen_h=600;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[2]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-95+size_gra && myszka.y<screen_h/2-95+f+size_gra){b[3]=220;if(myszka.buttons==1){screen_w=1280;screen_h=720;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[3]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-75+size_gra && myszka.y<screen_h/2-75+f+size_gra){b[4]=220;if(myszka.buttons==1){screen_w=1280;screen_h=800;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[4]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-55+size_gra && myszka.y<screen_h/2-55+f+size_gra){b[5]=220;if(myszka.buttons==1){screen_w=1280;screen_h=1024;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[5]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-35+size_gra && myszka.y<screen_h/2-35+f+size_gra){b[6]=220;if(myszka.buttons==1){screen_w=1366;screen_h=768;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[6]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2-15+size_gra && myszka.y<screen_h/2-15+f+size_gra){b[7]=220;if(myszka.buttons==1){screen_w=1400;screen_h=1050;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[7]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2+5+size_gra && myszka.y<screen_h/2+5+f+size_gra){b[8]=220;if(myszka.buttons==1){screen_w=1440;screen_h=900;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[8]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2+25+size_gra && myszka.y<screen_h/2+25+f+size_gra){b[9]=220;if(myszka.buttons==1){screen_w=1600;screen_h=900;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[9]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2+45+size_gra && myszka.y<screen_h/2+45+f+size_gra){b[10]=220;if(myszka.buttons==1){screen_w=1680;screen_h=1050;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[10]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2+65+size_gra && myszka.y<screen_h/2+65+f+size_gra){b[11]=220;if(myszka.buttons==1){screen_w=1920;screen_h=1080;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[11]=1;
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2+85+size_gra && myszka.y<screen_h/2+85+f+size_gra){b[12]=220;if(myszka.buttons==1){screen_w=1920;screen_h=1200;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else{b[12]=1;}
    if(myszka.x>screen_w/2+250 && myszka.x<screen_w/2+450 && myszka.y>screen_h/2+105+size_gra && myszka.y<screen_h/2+105+f+size_gra){b[13]=220;if(myszka.buttons==1){screen_w=2048;screen_h=1152;window=0;restartowanie=1;save_info(screen_w,screen_h);return 1;}}else b[13]=1;
    m=1;
}
}
   if(myszka.buttons!=1)m=0;
}





    if(window==2)
    {
        choose=0;
         if(przyciemnienie>=0.95){show_display=0;stoper=0;choose=0;window=0;}

         if(chapter==1){al_draw_bitmap(backgroud_ch1, 0, 0,0);}
        if(chapter==2){al_draw_bitmap(backgroud_ch2, 0, 0,0);}
        if(chapter==3){al_draw_bitmap(backgroud_ch3, 0, 0,0);}
        if(chapter==4){al_draw_bitmap(backgroud_ch4, 0, 0,0);}
       // al_draw_textf(font8,al_map_rgb(1,1,1), 10, 50, ALLEGRO_ALIGN_LEFT,"restartowanie %d",restartowanie);

        if(al_key_down( &klawiatura, ALLEGRO_KEY_ESCAPE)){choose_2=0;mozna_przyciemniac=true;}


        if(chapter>1) al_draw_scaled_bitmap(buttonleft,0,0,120,120,30 , 30,  size_gra,size_gra,0);
        al_draw_scaled_bitmap(buttonright,0,0,120,120,screen_w-150 , 30,  size_gra,size_gra,0);


        al_draw_scaled_bitmap(back1,0,0,120,120,screen_w-200 , screen_h-200,  size_gra,size_gra,0);
        if(myszka.x>screen_w-200 && myszka.x<screen_w-200+size_gra && myszka.y>screen_h-200 && myszka.y<screen_h-200+size_gra)
        {
        al_draw_scaled_bitmap(back1_sel,0,0,120,120,screen_w-200 , screen_h-200,  size_gra,size_gra,0);
         if(myszka.buttons==1){s_mouse_click->play();choose_2=0;mozna_przyciemniac=true;}
        }


        al_draw_filled_rounded_rectangle(screen_w/2-220, 20,screen_w/2+220,120, screen_w/100, screen_w/100 ,al_map_rgb(125,120,20));
        al_draw_textf(font_menu_1,al_map_rgb(1,1,1), screen_w/2, 30, ALLEGRO_ALIGN_CENTRE,"Chapter %d", chapter);



       for(int i=1;i<=level_count;i++)
        {
        if(!check_level(chapter, i))break;
        int px=i*(screen_w/11)%(screen_w-screen_w/11)+menu_ruch;
        int py=(screen_h/4)+ceil((i*(screen_w/11))/(screen_w-screen_w/11))*(screen_w/11);





        if(i+(chapter-1)*30> progress)al_draw_scaled_bitmap(butt1,0,0,100,100,px , py,  size_gra,size_gra,0);
        else if(i+(chapter-1)*30==progress)al_draw_scaled_bitmap(butt2,0,0,100,100,px , py,  size_gra,size_gra,0);
        else al_draw_scaled_bitmap(butt3,0,0,100,100,px , py,  size_gra,size_gra,0);


  if(myszka.x>px && myszka.x<px+size_gra && myszka.y>py && myszka.y<py+size_gra)
        {
       if(i+(chapter-1)*30> progress) al_draw_scaled_bitmap(butt1_s,0,0,100,100,px , py,  size_gra,size_gra,0);  //al_draw_rounded_rectangle( px,py,px+100,py+100,12,12,al_map_rgb(45,45,250),5);
   else if(i+(chapter-1)*30==progress)al_draw_scaled_bitmap(butt2_s,0,0,100,100,px , py,  size_gra,size_gra,0);  //al_draw_rounded_rectangle( px,py,px+100,py+100,12,12,al_map_rgb(150,100,15),5);
   else       al_draw_scaled_bitmap(butt3_s,0,0,100,100,px , py,  size_gra,size_gra,0);            //            al_draw_rounded_rectangle( px,py,px+100,py+100,12,12,al_map_rgb(50,115,5),5);
        choose=i;
        }

        al_draw_textf(font_lvl,al_map_rgb(55,55,55), px+(size_gra/2), py+(size_gra/8), ALLEGRO_ALIGN_CENTRE,"%d", i);

        }




        //##############################################################################################################################

        if(!m)
        {

        if(myszka.buttons==1 && choose>0  )
            {
                m=1;

                if(choose+(chapter-1)*30<=progress)
                {
                    s_mouse_click->play();
                    lvl=choose;
                    choose=0;
                    return true;
                }
            }


   else
   {
      if(myszka.x>screen_w-150 && myszka.x<screen_w-150+size_gra && myszka.y>30 && myszka.y<30+size_gra)
{
al_draw_scaled_bitmap(buttonRL_sel,0,0,120,120,screen_w-150 , 30,  size_gra,size_gra,0);
if(myszka.buttons==1 && chapter<chapter_count){s_mouse_click->play();menu_ruch=screen_w;chapter++;}
}


if(chapter>1 && myszka.x>30 && myszka.x<30+size_gra && myszka.y>30 && myszka.y<30+size_gra)
{
    al_draw_scaled_bitmap(buttonRL_sel,0,0,120,120,30 , 30,  size_gra,size_gra,0);
    if(myszka.buttons==1){s_mouse_click->play();menu_ruch=-screen_w;chapter--;}
}
         //  if(myszka.x>30 && myszka.x<150 && chapter>1 ){al_play_sample(s_mouse_click_01, poziom_dzwieku, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);menu_ruch=-screen_w;chapter--;}
         //  if( myszka.x>screen_w-150 && myszka.x<screen_w-30 && chapter<chapter_count){al_play_sample(s_mouse_click_01, poziom_dzwieku, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);menu_ruch=screen_w;chapter++;}
       m=1;
}
    }
   if(myszka.buttons!=1)m=0;
    }

    if(window==0)
    {
        choose=0;
        if(myszka.x>screen_w/2-(size_gra*3) && myszka.x<screen_w/2+(size_gra*3) && myszka.y>screen_h/2-(size_gra*3) && myszka.y<screen_h/2+(size_gra*3) )
        {
            if(myszka.y>screen_h/2-(size_gra*3) && myszka.y<screen_h/2-(size_gra*2) )
            {
            al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
             choose_1=1;
            if(myszka.buttons==1)
            {
                choose_2=1;
               s_mouse_click->play();
                mozna_przyciemniac=true;
            }
            }

        if(myszka.y>screen_h/2-(size_gra*1.5) && myszka.y<screen_h/2-(size_gra/2) )
            {
                al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
                choose_1=2;
                if(myszka.buttons==1)
            {
               s_mouse_click->play();
                choose_2=2;
                mozna_przyciemniac=true;
            }
            }

        if(myszka.y>screen_h/2 && myszka.y<screen_h/2+size_gra )
            {
                al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
                 choose_1=3;
                if(myszka.buttons==1)
            {
               s_mouse_click->play();
                choose_2=3;
                mozna_przyciemniac=true;
            }
            }

        if(myszka.y>screen_h/2+(size_gra*1.5) && myszka.y<screen_h/2+(size_gra*3) )
            {
                al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_LINK);
                 choose_1=4;
                if(myszka.buttons==1)
            {
               s_mouse_click->play();
                choose_2=4;
                mozna_przyciemniac=true;
            }
            }
        } else al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);

        //al_draw_bitmap(backgroud_menu,      0, 0,0);

        al_draw_bitmap(logo_fb,   30, screen_h-80,0);
        al_draw_bitmap(logo_yt,   100, screen_h-75,0);
        al_draw_bitmap(logo_st,   190, screen_h-80,0);

        al_draw_scaled_bitmap(button_play,0,0,800,300,screen_w/2-(size_gra*4)+x_play , screen_h/2-(size_gra*4),  size_gra*8,size_gra*3,0);

        al_draw_scaled_bitmap(button_levels,0,0,800,300,screen_w/2-(size_gra*4)+x_levels , screen_h/2-(size_gra*2.5),  size_gra*8,size_gra*3,0);

        al_draw_scaled_bitmap(button_settings,0,0,800,300,screen_w/2-(size_gra*4)+x_settings , screen_h/2-size_gra,  size_gra*8,size_gra*3,0);

        al_draw_scaled_bitmap(button_quit,0,0,800,300,screen_w/2-(size_gra*4)+x_quit , screen_h/2+(size_gra/2),  size_gra*8,size_gra*3,0);

        if(choose_2==4 && przyciemnienie>=0.95){ al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);return 0;}
        if(choose_2==3 && przyciemnienie>=0.95){ al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);window=3;choose_1=0;}
        if(choose_2==2 && przyciemnienie>=0.95){ al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);window=2;choose_1=0;}
        if(choose_2==1 && przyciemnienie>=0.95){ al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);choose_1=0;return 1;}
    }
    if(choose_2==0 && przyciemnienie>=0.95){ al_set_system_mouse_cursor(okno, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);choose_1=0;window=0;}
    al_draw_filled_rectangle(0, 0, screen_w, screen_h, al_map_rgba_f(0,0,0,przyciemnienie));
   // al_draw_textf(font_lvl,al_map_rgb(1,1,1), screen_w/2, 50, ALLEGRO_ALIGN_CENTRE,"size gra %d", size_gra);
    al_flip_display();

    }
    return false;
}

int main()
{

    al_init();
    al_install_keyboard();
    al_install_mouse();
    al_init_font_addon();
    al_init_font_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_init_acodec_addon();

    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_MOUSE_STATE myszka;




al_set_new_display_flags(ALLEGRO_OPENGL);


al_set_new_display_flags(ALLEGRO_RESIZABLE | ALLEGRO_WINDOWED);





load_info(screen_w,screen_h);
if(screen_w==0 && screen_h==0)
{
     ALLEGRO_MONITOR_INFO aminfo;
    al_get_monitor_info(0 , &aminfo);
    screen_w = aminfo.x2 - aminfo.x1 ;
    screen_h = aminfo.y2 - aminfo.y1 ;
    save_info(screen_w,screen_h);
}


    ALLEGRO_DISPLAY *okno = al_create_display( screen_w, screen_h);
    ALLEGRO_BITMAP *icon = al_load_bitmap("icon.png");

    al_set_display_icon(okno, icon);
    al_set_window_title( okno,"Boomber");





        intro(okno);
        if(!menu(okno,0))return 0;
if(restartowanie==1)
{
        al_destroy_display(okno);
        load_info(screen_w,screen_h);
        restartowanie=0;
        main();
        return 0;
}

    ALLEGRO_BITMAP *player = al_load_bitmap("player.png");
    ALLEGRO_BITMAP *player_left = al_load_bitmap("player_left.png");
    ALLEGRO_BITMAP *player_right = al_load_bitmap("player_right.png");


    ALLEGRO_BITMAP *floor = al_load_bitmap("floor.png");
    ALLEGRO_BITMAP *solid1 = al_load_bitmap("solid1.png");
    ALLEGRO_BITMAP *solid2 = al_load_bitmap("solid2.png");

 AudioDevicePtr device = OpenDevice();

   if (!device)
   {
     cout << "Could not open audiere device.\n";
     return 1;
   }

OutputStreamPtr wybuch_01(OpenSound(device, "bomb_01.wav", false));
OutputStreamPtr wybuch_atom(OpenSound(device, "bomb_01.wav", false));
OutputStreamPtr syczenie(OpenSound(device, "atom_bomb.wav", false));
OutputStreamPtr freeze_01(OpenSound(device, "freeze.wav", false));
OutputStreamPtr collect(OpenSound(device, "collect.wav", false));
OutputStreamPtr wall_d(OpenSound(device, "wall.wav", false));
OutputStreamPtr close(OpenSound(device, "close.wav", false));
OutputStreamPtr tykanie(OpenSound(device, "tykanie_1.wav", false));

OutputStreamPtr music_game_01(OpenSound(device, "musicgame_pulse.wav", false));
OutputStreamPtr music_game_02(OpenSound(device, "musicgame_drive.wav", false));

  if (!wybuch_01  || !wybuch_atom || !syczenie || !freeze_01 || !collect || !wall_d || !close || !tykanie || !music_game_01 || !music_game_02)
{
     cout << "nie zaladowano pliku dzwiekowego.\n";
     return 1;
  }

    ALLEGRO_BITMAP *txt[45];

    std::string buffer="";

    for(int i=0;i<45;i++)
    {
        if(i<9)buffer="texture_0";
        else buffer="texture_";
        buffer+=intToStr(i+1);
        buffer+=".png";

        txt[i] = al_load_bitmap(buffer.c_str());
        if(!txt[i])cout << "Couldn't load file \"" << buffer << "\"\n";
    }


    ALLEGRO_FONT * font8 = al_create_builtin_font();
    ALLEGRO_FONT * font  = al_load_ttf_font("Font.otf",36,0 );

     al_set_target_bitmap(al_get_backbuffer(okno));

    double czas = al_get_time();
     double old_czas=al_get_time();

    int w=0;
    int h=0;
    int  x=0,  y=0;
    int ax=0, ay=0;

    Object o[1000];





    load_level(chapter, lvl, o, w, h, x, y, okno);

    bool left = 1;
    bool right= 1;
    bool up   = 1;
    bool down = 1;

    bool plant=0;
    bool plant2=0;
    bool reload=0;
    int game_over=0;
    int win=0;

    int bomb_left=-1;
    int bomb_right=-1;
    int bomb_up=-1;
    int bomb_down=-1;

    int ide_w=1;
    int boost_left=0;
    int boost_right=0;
    int boost_up=0;
    int boost_down=0;

    int bombs=0;
    int points=0;
    int control_points=0;

    int play_sounds=0;
    bool play_sounds_2=0;
     bool play_sounds_3=0;
     bool play_sounds_4=0;
     bool play_sounds_5=0;

    int play_tykanie=0;

    bool mozna_play_laser=1;




    int px=0, py=0;

    int id=0;
    int fps=0;

    float control=0;

    int ogranicznik=0;
    int ogranicznik_2=0;
    int losowanie_muzyki=(rand() % 50 ) + 7;;




losowanie_muzyki =( rand() % 50 ) + 7;

    for(int i=0;i<1000;i++)
    {
        if( !o[i].exist ){id=i; break;}
    }

    while( !al_key_down( &klawiatura, ALLEGRO_KEY_F10))
    {
            wybuch_01->setVolume(effects_volume);
            wybuch_atom->setVolume(effects_volume);
            syczenie->setVolume(effects_volume);
            freeze_01->setVolume(effects_volume);
            collect->setVolume(effects_volume);
            wall_d->setVolume(effects_volume);
            close->setVolume(effects_volume);
            tykanie->setVolume(effects_volume);



            music_game_01->setVolume(music_volume);
            music_game_02->setVolume(music_volume);

if(losowanie_muzyki>30)
{
            if(!music_game_01->isPlaying() && !music_game_02->isPlaying())music_game_01->play();
            if(music_game_01->isPlaying())losowanie_muzyki=0;
}
if(losowanie_muzyki<30)
{
            if(!music_game_01->isPlaying())music_game_02->play();
            if(music_game_02->isPlaying())losowanie_muzyki=60;
}


        if ( al_get_time() > czas + 0.005)//+ 0.005
        {
            al_get_keyboard_state(&klawiatura);

            if(x%100>50)px=(x+100)/100;
            else px=x/100;
            if(y%100>50)py=(y+100)/100;
            else py=y/100;



     //**********************************************************************************************************************DZWIĘKI**************************************************
              for(int i=0;i<1000;i++)
            {
                if( o[i].fuse==2 && o[i].type==6) {play_sounds=1;}//zolta
                if( o[i].solid==true && o[i].fuse==2  && o[i].type==2){play_sounds=1;}//niebieska i czarna
              //  if(o[i].solid==false && o[i].type==2 && ogranicznik==0 && o[i].fuse==140) {play_sounds=1;ogranicznik=20;}//czerwona NIZEJ
                if( o[i].fuse==1 && o[i].type==7 && ogranicznik==0) {play_sounds=1;ogranicznik=10;}//pomarn}  NIZEJ
                if( o[i].fuse==2 && o[i].type==8) play_sounds=1;//fioletowa
             //   if( o[i].fuse==2 && o[i].type==10) play_sounds=1;//brazowa
                if( o[i].fuse==2 && o[i].type==16) play_sounds=1;//rozowa
                if( o[i].fuse==2 && o[i].type==14) play_sounds=1;//mina zolta

                if( o[i].texture==32 || o[i].texture==33 || o[i].texture==34 || o[i].texture==35|| o[i].texture==36|| o[i].texture==37 || o[i].texture==38 && mozna_play_laser==1){freeze_01->play();ogranicznik_2++;mozna_play_laser=0;}
                if(ogranicznik_2>20)mozna_play_laser=1;ogranicznik_2=0;
                if( o[i].fuse==2 && o[i].type==4 && !o[i].texture==32 || !o[i].texture==33 || !o[i].texture==34 || !o[i].texture==35|| !o[i].texture==36|| !o[i].texture==37 || !o[i].texture==38) play_sounds_2=1;//mrozaca
                if( o[i].fuse==2 && o[i].type==9) play_sounds=1;//atom
                if( o[i].texture==44) {syczenie->play();}else if(syczenie-> isPlaying())play_sounds=0;
            }








if(play_sounds_2==1)
{
   freeze_01->reset();
   freeze_01->play();
   play_sounds_2=0;
}

if(play_sounds_3==1)
{
    collect->reset();
   collect->play();
   play_sounds_3=0;
}

if(play_sounds_4==1)
{
    wall_d->reset();
   wall_d->play();
   play_sounds_4=0;
}
if(play_sounds_5==1)
{
    close->reset();
    close->play();
    play_sounds_5=0;
}

if(play_tykanie==1)
{
   tykanie->reset();
   tykanie->play();
   play_tykanie=0;
}

if(play_sounds==1 && !syczenie-> isPlaying())
{
    if(wybuch_01->isPlaying()){wybuch_01->reset();}
    wybuch_01->play();
    play_sounds=0;
}



            for(int i=0;i<1000;i++)
            {

                if(o[i].type==8)
                {
                if(o[i].ax>0)o[i].ax+=4;
                if(o[i].ax<0)o[i].ax-=4;
                if(o[i].ay>0)o[i].ay+=4;
                if(o[i].ay<0)o[i].ay-=4;

                if(o[i].ax> 100){o[i].x+=1;o[i].ax-=100;}
                if(o[i].ax<-100){o[i].x-=1;o[i].ax+=100;}
                if(o[i].ay> 100){o[i].y+=1;o[i].ay-=100;}
                if(o[i].ay<-100){o[i].y-=1;o[i].ay+=100;}

                }

                if(o[i].type==16)
                {
                if(o[i].ax>0)o[i].ax+=2;
                if(o[i].ax<0)o[i].ax-=2;
                if(o[i].ay>0)o[i].ay+=2;
                if(o[i].ay<0)o[i].ay-=2;

                if(o[i].ax> 100){o[i].ax=0; o[i].x++;}
                if(o[i].ax<-100){o[i].ax=0; o[i].x--;}
                if(o[i].ay> 100){o[i].ay=0; o[i].y++;}
                if(o[i].ay<-100){o[i].ay=0; o[i].y--;}

                }

                if(o[i].type==16 || o[i].type==8)
                {

                if(o[i].x==w && o[i].ax>0)o[i].ax=0;
                if(o[i].x==0 && o[i].ax<0)o[i].ax=0;
                if(o[i].y==h && o[i].ay>0)o[i].ay=0;
                if(o[i].y==0 && o[i].ay<0)o[i].ay=0;

                if(o[i].fuse>0){o[i].ax=0; o[i].ay=0;}

                }

                if(o[i].type==12)
                {
                    if(o[i].x==px && o[i].y==py)o[i].fuse=100;
               else if(o[i].x!=px && o[i].y!=py && o[i].fuse>1)o[i].fuse--;
                }

                if(o[i].type==8 || o[i].type==16)
                for(int j=0;j<1000;j++)
                {
                    if(o[i].ax>0)
                    {
                        if(o[i].x+1==o[j].x && o[i].y==o[j].y && o[j].solid)o[i].ax=0;
                    }

                    if(o[i].ax<0)
                    {
                        if(o[i].x-1==o[j].x && o[i].y==o[j].y && o[j].solid)o[i].ax=0;
                    }

                    if(o[i].ay>0)
                    {
                        if(o[i].x==o[j].x && o[i].y+1==o[j].y && o[j].solid)o[i].ay=0;
                    }

                    if(o[i].ay<0)
                    {
                        if(o[i].x==o[j].x && o[i].y-1==o[j].y && o[j].solid)o[i].ay=0;
                    }

                    if(o[i].fuse>0 && o[i].type==8)
                    {
                        if(o[i].ax==1 || o[i].ax==-1)o[i].ax=0;
                        if(o[i].ay==1 || o[i].ay==-1)o[i].ay=0;
                    }
                }

                if( o[i].x  == px && o[i].y   == py ||
                    o[i].x-1== px && o[i].y   == py ||
                    o[i].x+1== px && o[i].y   == py ||
                    o[i].x  == px && o[i].y-1 == py ||
                    o[i].x  == px && o[i].y+1 == py  )
                {

                    if(o[i].solid && o[i].exist && o[i].type==3)
                    {

                  ///////////
                        o[i].fuse=1;
                        game_over=1;
                    }

                    if(o[i].solid && o[i].exist && o[i].fuse==0 && o[i].type==10)
                    {

                        o[i].fuse=300;
                    }

                    if(o[i].solid && o[i].exist && o[i].type==6 && o[i].fuse==0)
                    {
                        o[i].fuse=300;
                    }
                }

                if(o[i].type==13 && !o[i].solid)
                {
                    if(o[i].x==px && o[i].y==py && o[i].fuse==0){o[i].fuse=1;play_sounds=1;}
                    else for(int j=0;j<1000;j++)
                    {
                        if(o[i].x==o[j].x && o[i].y==o[j].y && o[j].solid && o[j].exist && o[i].fuse==0)
                            {
                                o[i].fuse=1;
                                if(o[j].type==8){o[j].ax=0; o[j].ay=0; o[j].fuse=300;}
                            }
                    }
                }

                if(o[i].type==14 && !o[i].solid)
                {
                    if(o[i].x==px && o[i].y==py && o[i].fuse==0){o[i].fuse=300;play_tykanie=1;}
                    else for(int j=0;j<1000;j++)
                    {
                        if(o[i].x==o[j].x && o[i].y==o[j].y && o[j].solid && o[j].exist && o[i].fuse==0)o[i].fuse=300;
                    }
                }

                if(o[i].type==15 && !o[i].solid)
                {
                    if(o[i].x==px && o[i].y==py && o[i].fuse==0){o[i].fuse=300;}
                    else for(int j=0;j<1000;j++)
                    {
                        if(o[i].x==o[j].x && o[i].y==o[j].y && o[j].solid && o[j].exist && o[i].fuse==0)o[i].fuse=300;
                    }
                }

                if(o[i].type==17 && !o[i].solid)
                {
                    if(o[i].x==px && o[i].y==py && o[i].fuse==0){o[i].fuse=300;}
                    else for(int j=0;j<1000;j++)
                    {
                        if(o[i].x==o[j].x && o[i].y==o[j].y && o[j].solid && o[j].exist && o[i].fuse==0)o[i].fuse=300;
                    }
                }

                if( o[i].fuse >1 ) o[i].fuse--;
                if( o[i].fuse==1 )
                        {

                        if( !o[i].solid && o[i].type==12)
                        {
                            play_sounds_5=1;
                            o[i].load(1,1,0,o[i].x,o[i].y,0,1,0,0);
                            o[i].direction=0;
                        }

                        if( !o[i].solid && o[i].type==13)
                        {
                        o[i].load(1,0,3,o[i].x,o[i].y,2,1,150,o[i].power-1);
                        o[i].direction=0;
                        //cout << "Replacing object " << i << " with parameters: 1 0 3 " << o[i].x << " " << o[i].y << " 3 " << 2 << " 150 " << o[i].power-1 <<"\n";
                        }

                        if( !o[i].solid && o[i].type==14)
                        {
                        o[i].load(1,0,3,o[i].x,o[i].y,2,1,150,o[i].power-1);
                        o[i].direction=0;
                        //cout << "Replacing object " << i << " with parameters: 1 0 3 " << o[i].x << " " << o[i].y << " 3 " << 2 << " 150 " << o[i].power-1 <<"\n";
                        }

                        if( !o[i].solid && o[i].type==17)
                        {

                        if(o[i].power==1)
                        {
                            o[i].load(1,0,33,o[i].x,o[i].y,4,1,150,o[i].power);
                            o[i].direction=o[i].power;
                        }

                        if(o[i].power==2)
                        {
                            o[i].load(1,0,34,o[i].x,o[i].y,4,1,150,o[i].power);
                            o[i].direction=o[i].power;
                        }

                        if(o[i].power==3)
                        {
                            o[i].load(1,0,33,o[i].x,o[i].y,4,1,150,o[i].power);
                            o[i].direction=o[i].power;
                        }

                        if(o[i].power==4)
                        {
                            o[i].load(1,0,34,o[i].x,o[i].y,4,1,150,o[i].power);
                            o[i].direction=o[i].power;
                        }

                        }

                        if( !o[i].solid && o[i].type==15)
                        {
                        o[i].load(1,0,12,o[i].x,o[i].y,3,1,150,o[i].power-1);
                        o[i].direction=0;
                        //cout << "Replacing object " << i << " with parameters: 1 0 3 " << o[i].x << " " << o[i].y << " 3 " << 2 << " 150 " << o[i].power-1 <<"\n";
                        }

                        if( o[i].solid==true)
                        {

                        if(o[i].type==2 || o[i].type==3 || o[i].type==6 || o[i].type==7 || o[i].type==8 || o[i].type==16)
                        {
                        o[i].load(1,0,3,o[i].x,o[i].y,2,1,150,o[i].power-1);
                        o[i].direction=0;
                        //cout << "Replacing object " << i << " with parameters: 1 0 3 " << o[i].x << " " << o[i].y << " 3 " << 2 << " 150 " << o[i].power-1 <<"\n";
                        }

                        if(o[i].type==10)
                        {
                            o[i].fuse=320;
                            for(int j=0;j<1000;j++)
                            {
                            if( !o[j].exist && j>i ){id=j; break;}
                            }
                            o[id].load(1,0,3,o[i].x,o[i].y,2,1,150,o[i].power-1);
                            o[id].direction=0;

                        }

                        if(o[i].type==9)
                        {
                            o[i].load(1,0,44,o[i].x,o[i].y,6,1,150,0);
                            o[i].direction=0;
                        }

                        if(o[i].type==4)
                        {
                        o[i].load(1,0,12,o[i].x,o[i].y,3,1,150,o[i].power-1);
                        o[i].direction=0;
                        //cout << "Replacing object " << i << " with parameters: 1 0 3 " << o[i].x << " " << o[i].y << " 3 " << 3 << " 150 " << o[i].power-1 <<"\n";
                        }

                        }

                        else if( !o[i].solid && o[i].fuse==1)
                        if( o[i].type==2 ||  o[i].type==3 ||  o[i].type==4 || o[i].type==6)
                        {
                        o[i].destroy();
                        //cout << "Deleting object " << i << "\n";
                        }

                        }

                if(!o[i].solid && o[i].fuse<=149 && o[i].fuse>1)
                {
                    for(int j=0;j<1000;j++)
                    {

                    if(o[i].y==o[j].y && o[i].x==o[j].x )
                    if(o[i].type==2 || o[i].type==4 || o[i].type==6)
                    if(o[j].type==8)
                    if(o[j].ax!=0 || o[j].ay!=0)
                            {
                                if(o[j].fuse==0){o[j].fuse=300;}
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }
                                if(o[i].direction!=0)o[i].power=0;
                            }
                    }
                }

                if(!o[i].solid && o[i].fuse==149)
                {
                if(o[i].type==2 || o[i].type==3 || o[i].type==4 || o[i].type==6)
                {

                  //////////////////////  play_sounds=1;


                if( o[i].x>w || o[i].x<0 ||
                    o[i].y>h || o[i].y<0 ) o[i].destroy();

                    for(int j=0;j<1000;j++)
                    {

                        /*if(o[i].x==o[j].x && o[i].y==o[j].y && i!=j && !o[i].solid && !o[j].solid)
                        {
                            if(o[i].type==2 || o[i].type==3 || o[i].type==4)
                            if(o[j].type==2 || o[j].type==3 || o[j].type==4)
                            if(o[i].display && o[j].display)o[j].display=0;
                        }*/

                        if(o[j].x==o[i].x && o[j].y==o[i].y && o[j].exist && o[j].solid)
                        {

                            if(o[i].type==6)
                            {
                                if(o[j].type>=2)o[j].destroy();
                                else if(o[j].type==1) {o[i].destroy(); o[j].destroy();}
                                else o[i].destroy();
                            }

                            if(o[i].type==2 || o[i].type==4)
                            {

                            if(o[j].type==0)o[i].destroy();
                            if(o[j].type==1 && o[i].type!=6)
                            {
                                if(o[i].direction!=0)o[i].power=0;
                                play_sounds_4=1;
                                o[j].destroy();
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }

                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                            }

                            if(o[j].type==2 || o[j].type==4 || o[j].type==6 || o[j].type==16)
                                {
                                if(o[j].fuse==0){o[j].fuse=300;}
                                else if(o[j].fuse>0){o[j].fuse=1;}
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }
                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                                if(o[i].type!=6)o[i].power=0;
                                }

                            if(o[j].type==10)
                                {
                                if(o[j].fuse==0){o[j].fuse=300;}
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }
                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                                if(o[i].type!=6)if(o[i].direction!=0)o[i].power=0;
                                }

                            if(o[j].type==8)
                            if( o[j].ax==0 && o[j].ay==0)
                            {
                                if(o[j].fuse==0){o[j].fuse=300;}
                                else if(o[j].fuse>0){o[j].fuse=1;}
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }
                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                                if(o[i].type!=6)if(o[i].direction!=0)o[i].power=0;
                            }

                            if(o[j].type==3 || o[j].type==7)
                            {
                                o[j].fuse=1;


                                if(o[i].type!=6)o[i].power=0;
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }
                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                            }
                            if(o[j].type==9 && o[j].fuse==0)
                            {
                                o[j].fuse=2000; //default:2000
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }
                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                                if(o[i].type!=6)if(o[i].direction!=0)o[i].power=0;
                            }
                            if(o[j].type==9 && o[j].fuse>0)
                            {
                                if(o[i].texture==4 || o[i].texture==5)
                                {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                }
                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                                if(o[i].type!=6)if(o[i].direction!=0)o[i].power=0;
                            }

                            }

                            if(o[i].type==3)
                            {
                            if(o[j].type==0)o[i].destroy();
                            if(o[j].type==1)
                            {
                                if(o[i].direction!=0)o[i].power=0;
                                if(o[i].texture==14 || o[i].texture==13)
                                {
                                    if(o[i].direction==1)o[i].texture=18;
                                    if(o[i].direction==2)o[i].texture=17;
                                    if(o[i].direction==3)o[i].texture=16;
                                    if(o[i].direction==4)o[i].texture=15;
                                }

                            }
                            if(o[j].type==2 || o[j].type==3 || o[j].type==6 || o[j].type==7 || o[j].type==8 || o[j].type==9 || o[j].type==10 || o[j].type==16)
                            {
                                o[j].load( 1, 1, 19, o[i].x, o[i].y, 1, 1, 0, 0);



                                if(o[i].direction!=0)o[i].power=0;
                                if(o[i].texture==14 || o[i].texture==13)
                                {
                                    if(o[i].direction==1)o[i].texture=18;
                                    if(o[i].direction==2)o[i].texture=17;
                                    if(o[i].direction==3)o[i].texture=16;
                                    if(o[i].direction==4)o[i].texture=15;
                                }
                                }

                            if(o[j].type==8 || o[j].type==16)
                            if( o[j].ax==0 && o[j].ay==0)
                            {
                                o[j].load( 1, 1, 19, o[i].x, o[i].y, 1, 1, 0, 0);
                                if(o[i].direction!=0)o[i].power=0;
                                if(o[i].texture==14 || o[i].texture==13)
                                {
                                    if(o[i].direction==1)o[i].texture=18;
                                    if(o[i].direction==2)o[i].texture=17;
                                    if(o[i].direction==3)o[i].texture=16;
                                    if(o[i].direction==4)o[i].texture=15;
                                }
                                if(o[i].direction!=0)o[i].power=0;
                            }

                            if(o[j].type==4)
                            {
                                o[j].fuse=300;
                                if(o[i].direction!=0)o[i].power=0;
                                if(o[i].texture==14 || o[i].texture==13)
                                {
                                    if(o[i].direction==1)o[i].texture=18;
                                    if(o[i].direction==2)o[i].texture=17;
                                    if(o[i].direction==3)o[i].texture=16;
                                    if(o[i].direction==4)o[i].texture=15;
                                }
                            }

                            }

                        }
                        if(o[j].x==o[i].x && o[j].y==o[i].y && o[j].exist && !o[j].solid)
                        {
                            if(o[i].type==6 && o[j].type==6 && i!=j)o[i].destroy();

                            if(o[j].type==5 || o[j].type==11)
                            {
                            if(o[i].type==2 || o[i].type==6)
                                {
                                    if(o[i].texture==4 || o[i].texture==5)
                                    {
                                    if(o[i].direction==1)o[i].texture=9;
                                    if(o[i].direction==2)o[i].texture=8;
                                    if(o[i].direction==3)o[i].texture=7;
                                    if(o[i].direction==4)o[i].texture=6;
                                    }
                                    if(o[i].texture==33 || o[i].texture==34)
                                    {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                    }
                                    o[i].power=0;
                                    o[j].destroy();
                            }

                            if(o[i].type==3)
                            {
                            o[j].load( 1, 1, 19, o[i].x, o[i].y, 1, 1, 0, 0);
                            o[i].power=0;
                                if(o[i].texture==14 || o[i].texture==13)
                                {
                                    if(o[i].direction==1)o[i].texture=18;
                                    if(o[i].direction==2)o[i].texture=17;
                                    if(o[i].direction==3)o[i].texture=16;
                                    if(o[i].direction==4)o[i].texture=15;
                                }
                                if(o[i].texture==33 || o[i].texture==34)
                                {
                                    if(o[i].direction==1)o[i].texture=37;
                                    if(o[i].direction==2)o[i].texture=36;
                                    if(o[i].direction==3)o[i].texture=35;
                                    if(o[i].direction==4)o[i].texture=38;
                                }
                                }

                            }
                        }

                    }
                }
                }

                if(!o[i].solid && o[i].type==6 && o[i].fuse==130) // ZIELONY WYBUCH
                {

                    //if(o[i].power==0)
                    //{
                        for(int j=0;j<1000;j++)if( !o[j].exist ){id=j; break;}
                        o[id].load(1,0,44,o[i].x-1,o[i].y  ,6,1,150,1);//left

                        for(int j=0;j<1000;j++)if( !o[j].exist ){id=j; break;}
                        o[id].load(1,0,44,o[i].x  ,o[i].y-1,6,1,150,2);//top

                        for(int j=0;j<1000;j++)if( !o[j].exist ){id=j; break;}
                        o[id].load(1,0,44,o[i].x+1,o[i].y  ,6,1,150,3);//right

                        for(int j=0;j<1000;j++)if( !o[j].exist ){id=j; break;}
                        o[id].load(1,0,44,o[i].x  ,o[i].y+1,6,1,150,4);//bottom
                    //}

                }

                if(!o[i].solid && o[i].type==4 && o[i].fuse==130 && o[i].power>0) // CZERWONY WYBUCH
                {
                    for(int j=0;j<1000;j++)
                    {
                    if( !o[j].exist ){id=j; break;}
                    }

                    bool  right_clear=1;
                    bool   left_clear=1;
                    bool    top_clear=1;
                    bool bottom_clear=1;

                    for(int j=0;j<1000;j++)
                    {
                        if(o[j].solid && o[j].exist && o[j].type==0)
                        {
                            if(o[i].x  ==o[j].x && o[i].y-1==o[j].y)   top_clear=0;
                            else if(o[i].y==0)top_clear=0;
                            if(o[i].x  ==o[j].x && o[i].y+1==o[j].y)bottom_clear=0;
                            else if(o[i].y==h)bottom_clear=0;
                            if(o[i].x-1==o[j].x && o[i].y  ==o[j].y)  left_clear=0;
                            else if(o[i].x==0)left_clear=0;
                            if(o[i].x+1==o[j].x && o[i].y  ==o[j].y) right_clear=0;
                            else if(o[i].x==w)right_clear=0;
                        }
                    }

                    if(o[i].power==1)
                    {

                        if(bottom_clear)
                        {
                            o[id].load(1,0,33,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power);
                            o[id].direction=o[i].power;
                        }
                   else if(left_clear)
                        {
                            o[id].load(1,0,34,o[i].x-1,o[i].y,o[i].type,1,150,2);
                            o[id].direction=2;
                            o[i].texture=40;
                        }
                   else if(right_clear)
                        {
                            o[id].load(1,0,34,o[i].x+1,o[i].y,o[i].type,1,150,4);
                            o[id].direction=4;
                            o[i].texture=41;
                        }
                   else o[i].power=0;

                    }

                    if(o[i].power==2)
                    {

                        if(left_clear)
                        {
                            o[id].load(1,0,34,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power);
                            o[id].direction=o[i].power;
                        }
                   else if(top_clear)
                        {
                            o[id].load(1,0,33,o[i].x,o[i].y-1,o[i].type,1,150,3);
                            o[id].direction=3;
                            o[i].texture=41;
                        }
                   else if(bottom_clear)
                        {
                            o[id].load(1,0,33,o[i].x,o[i].y+1,o[i].type,1,150,1);
                            o[id].direction=1;
                            o[i].texture=42;
                        }
                   else o[i].power=0;

                    }

                    if(o[i].power==3)
                    {

                        if(top_clear)
                        {
                            o[id].load(1,0,33,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power);
                            o[id].direction=o[i].power;
                        }

                   else if(right_clear)
                        {
                            o[id].load(1,0,34,o[i].x+1,o[i].y,o[i].type,1,150,4);
                            o[id].direction=4;
                            o[i].texture=42;
                        }

                   else if(left_clear)
                        {
                            o[id].load(1,0,34,o[i].x-1,o[i].y,o[i].type,1,150,2);
                            o[id].direction=2;
                            o[i].texture=43;
                        }

                   else o[i].power=0;

                    }

                    if(o[i].power==4)
                    {

                        if(right_clear)
                        {
                            o[id].load(1,0,34,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power);
                            o[id].direction=o[i].power;
                        }
                   else if(bottom_clear)
                        {
                            o[id].load(1,0,33,o[i].x,o[i].y+1,o[i].type,1,150,1);
                            o[id].direction=1;
                            o[i].texture=43;
                        }
                   else if(top_clear)
                        {
                            o[id].load(1,0,33,o[i].x,o[i].y-1,o[i].type,1,150,3);
                            o[id].direction=3;
                            o[i].texture=40;
                        }
                   else o[i].power=0;

                    }

                }

                if(!o[i].solid && o[i].type==2 && o[i].fuse==140 && o[i].power>0) // ZWYK£Y WYBUCH
                {

                    for(int j=0;j<1000;j++)
                    {
                    if( !o[j].exist ){id=j; break;}
                    }

                    if(o[i].power>1)
                    switch(o[i].direction)
                    {
                    case 0:

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,5,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=1;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,5,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,4,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,4,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;

                        break;
                    case 1:
                        if(o[i].x<w){
                        o[id].load(1,0,5,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=1;
                        }
                        break;
                    case 2:
                        o[id].load(1,0,4,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;
                        break;
                    case 3:
                        o[id].load(1,0,5,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;
                        break;
                    case 4:
                        o[id].load(1,0,4,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;
                        break;
                    }

                    if(o[i].power<=1)
                    switch(o[i].direction)
                    {
                    case 0:

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                            o[id].load(1,0,9,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                            o[id].direction=1;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,7,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,8,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,6,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;

                        break;
                    case 1:
                        o[id].load(1,0,9,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=1;
                        break;
                    case 2:
                        o[id].load(1,0,8,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;
                        break;
                    case 3:
                        o[id].load(1,0,7,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;
                        break;
                    case 4:
                        o[id].load(1,0,6,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;
                        break;
                    }

                }

                if(!o[i].solid && o[i].type==3 && o[i].fuse==140 && o[i].power>0) //MRO¯ACY WYBUCH
                {

                    for(int j=0;j<1000;j++)
                    {
                    if( !o[j].exist ){id=j; break;}
                    }

                    if(o[i].power>1)
                    switch(o[i].direction)
                    {
                    case 0:

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,14,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=1;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,14,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,13,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,13,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;

                        break;
                    case 1:
                        if(o[i].x<w){
                        o[id].load(1,0,14,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=1;
                        }
                        break;
                    case 2:
                        o[id].load(1,0,13,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;
                        break;
                    case 3:
                        o[id].load(1,0,14,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;
                        break;
                    case 4:
                        o[id].load(1,0,13,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;
                        break;
                    }

                    if(o[i].power==1)
                    switch(o[i].direction)
                    {
                    case 0:

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                            o[id].load(1,0,18,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                            o[id].direction=1;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,16,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,17,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;

                        for(int j=0;j<1000;j++)
                        {
                        if( !o[j].exist ){id=j; break;}
                        }
                        o[id].load(1,0,15,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;

                        break;
                    case 1:
                        o[id].load(1,0,18,o[i].x+1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=1;
                        break;
                    case 2:
                        o[id].load(1,0,17,o[i].x,o[i].y+1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=2;
                        break;
                    case 3:
                        o[id].load(1,0,16,o[i].x-1,o[i].y,o[i].type,1,150,o[i].power-1);
                        o[id].direction=3;
                        break;
                    case 4:
                        o[id].load(1,0,15,o[i].x,o[i].y-1,o[i].type,1,150,o[i].power-1);
                        o[id].direction=4;
                        break;
                    }

                }


            }

                 // if( o[i].fuse==1 && o[i].type==4) al_play_sample_instance(boom); //mrozaca
                 //  if(  o[i].type==2 && o[i].fuse==140) al_play_sample_instance(boom);
                //  if( o[i].fuse==1 && o[i].type==6) al_play_sample_instance(boom);
                //  if( o[i].fuse==1 && o[i].type==7) al_play_sample_instance(boom);
                //  if( o[i].fuse>0 && o[i].fuse<10 && o[i].type==8) al_play_sample_instance(boom);
                //  if( o[i].fuse>0 && o[i].fuse<10 && o[i].type==10) al_play_sample_instance(boom);
                //  if( o[i].fuse>0 && o[i].fuse<10 && o[i].type==16) al_play_sample_instance(boom);
                   //if( o[i].type==2 && o[i].fuse==140 ) al_play_sample_instance(boom);







            for(int i=0;i<1000;i++)
            {
                if(o[i].solid && o[i].type!=8 && o[i].type!=16)
                {
                if(o[i].x+1==x/100 && o[i].y==y/100){left=false; break;}
                if(ay>0 && o[i].x+1==x/100 && o[i].y-1==y/100){left=false; break;}
                if(ay<0 && o[i].x+1==x/100 && o[i].y-1==y/100){left=false; break;}
                }
                else left=true;
            }

            for(int i=0;i<1000;i++)
            {
                if(o[i].solid && o[i].type!=8 && o[i].type!=16)
                {
                if(o[i].x-1==x/100 && o[i].y==y/100){right=false; break;}
                if(ay>0 && o[i].x-1==x/100 && o[i].y-1==y/100){right=false; break;}
                if(ay<0 && o[i].x-1==x/100 && o[i].y-1==y/100){right=false; break;}
                }
                else right=true;
            }

            for(int i=0;i<1000;i++)
            {
                if(o[i].solid && o[i].type!=8 && o[i].type!=16)
                {
                if(o[i].y+1==y/100 && o[i].x==x/100){up=false; break;}
                if(ax>0 && o[i].y+1==y/100 && o[i].x-1==x/100){up=false; break;}
                if(ax<0 && o[i].y+1==y/100 && o[i].x-1==x/100){up=false; break;}
                }
                else up=true;
            }

            for(int i=0;i<1000;i++)
            {
                if(o[i].solid && o[i].type!=8 && o[i].type!=16)
                {
                if(o[i].y-1==y/100 && o[i].x==x/100){down=false; break;}
                if(ax>0 && o[i].y-1==y/100 && o[i].x-1==x/100){down=false; break;}
                if(ax<0 && o[i].y-1==y/100 && o[i].x-1==x/100){down=false; break;}
                }
                else down=true;
            }

            control_points=0;

            for(int i=0;i<1000;i++)
            {
                if(!o[i].exist)continue;
                if(!o[i].solid && o[i].type==19 && o[i].x==px && o[i].y==py)
                {
                    if(o[i].power==4)boost_right=50;
                    if(o[i].power==1)boost_down =50;
                    if(o[i].power==2)boost_left =50;
                    if(o[i].power==3)boost_up   =50;
                    break;
                }
            }

            if(ax>0)boost_left =0;
            if(ax<0)boost_right=0;
            if(ay>0)boost_up   =0;
            if(ay<0)boost_down =0;

            for(int i=0;i<1000;i++)
            {

                if(!o[i].solid && o[i].type==2 && o[i].x==px && o[i].y==py && !game_over){
                    game_over=true;
                    cout << "You were killed by object " << i << "\n";
                    break;
                    }

                if(!o[i].solid && o[i].type==3 && o[i].x==px && o[i].y==py && !game_over){
                    game_over=true;
                    cout << "You were killed by object " << i << "\n";
                    break;
                    }

                if(!o[i].solid && o[i].type==4 && o[i].x==px && o[i].y==py && !game_over){
                    game_over=true;
                    cout << "You were killed by object " << i << "\n";
                    break;
                    }

                if(!o[i].solid && o[i].type==6 && o[i].x==px && o[i].y==py && !game_over){
                    game_over=true;
                    cout << "You were killed by object " << i << "\n";
                    break;
                    }

                if(!o[i].solid && o[i].type==5 && o[i].x==px && o[i].y==py && !game_over)
                {
                    bombs++;
                    o[i].destroy();
                }

                if(!o[i].solid && o[i].type==11)control_points++;


                if(!o[i].solid && o[i].type==11 && o[i].x==px && o[i].y==py && !game_over)
                {
                    points++;
                   play_sounds_3=1;
                    o[i].destroy();
                }

            }

            if(control_points<points_count-points && !game_over)game_over=1;

            for(int i=0;i<1000;i++)
                    {

                        if(o[i].solid && o[i].type==8 && o[i].x==(x+ax)/100 && o[i].y==(y+ay)/100+1 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_down=i;
                            break;
                        }
                        if(o[i].solid && o[i].type==16 && o[i].x==(x+ax)/100 && o[i].y==(y+ay)/100+1 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_down=i;
                            break;
                        }
                        else bomb_down=-1;
                    }

            for(int i=0;i<1000;i++)
                    {

                        if(o[i].solid && o[i].type==8 && o[i].x==(x+ax)/100 && o[i].y==(y+ay)/100-1 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_up=i;
                            break;
                        }
                        if(o[i].solid && o[i].type==16 && o[i].x==(x+ax)/100 && o[i].y==(y+ay)/100-1 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_up=i;
                            break;
                        }
                        else bomb_up=-1;

                    }


            for(int i=0;i<1000;i++)
                {

                        if(o[i].solid && o[i].type==8 && o[i].x==(x+ax)/100+1 && o[i].y==(y+ay)/100 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_right=i;
                            break;
                        }
                        if(o[i].solid && o[i].type==16 && o[i].x==(x+ax)/100+1 && o[i].y==(y+ay)/100 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_right=i;
                            break;
                        }
                        else bomb_right=-1;

                }


            for(int i=0;i<1000;i++)
                {

                        if(o[i].solid && o[i].type==8  && o[i].x==(x+ax)/100-1 && o[i].y==(y+ay)/100 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_left=i;
                            break;
                        }
                   else if(o[i].solid && o[i].type==16 && o[i].x==(x+ax)/100-1 && o[i].y==(y+ay)/100 && o[i].ay==0 && o[i].ax==0)
                        {
                            bomb_left=i;
                            break;
                        }
                        else bomb_left=-1;

                }


            if(!game_over && !win )
            {

                 if ( al_key_down(&klawiatura, sterowanie_2 ) && ax==0 && x<w*100 && right)//SYNEK TU MOSZ ROBOTE
                    {
                    if(bomb_right>=0)o[bomb_right].ax=1;
                    else ax+=100;
                    }
            else if ( al_key_down(&klawiatura, sterowanie_1 ) && ax==0 && x>0     && left )
                {
                    if(bomb_left>=0)o[bomb_left].ax=-1;
                    else ax-=100;
                }
            else if ( al_key_down(&klawiatura, sterowanie_4 ) && ay==0 && y<h*100 && down )
                {
                    if(bomb_down>=0)o[bomb_down].ay=1;
                    else ay+=100;
                }
            else if ( al_key_down(&klawiatura, sterowanie_3 ) && ay==0 && y>0     && up   )
                {
                    if(bomb_up>=0)o[bomb_up].ay=-1;
                    else ay-=100;
                }

            }

            if(points>=points_count)win++;


            if ( al_key_down(&klawiatura, sterowanie_plant ) && !plant && !game_over && bombs>0 )
            {
                plant=1;
                bombs--;


                for(int j=0;j<1000;j++)
                {
                    if( !o[j].exist ){id=j; break;}
                }

                o[id].load(1,1,2,px,py,2,1,300,2);
                //cout << "Creating object, ID: " << id << ", parameters: 1 1 2 " << x/100 << " " << y/100 << " 2 2 300 2\n";

                for(int i=0;i<1000;i++)
                {
                if( !o[i].exist ){id=i; break;}
                }

            }

            if ( !al_key_down(&klawiatura, sterowanie_plant ) )plant=0;

            if ( al_key_down(&klawiatura, ALLEGRO_KEY_P ) && !plant2 && !game_over )
            {
                al_set_target_bitmap(al_get_backbuffer(okno));
                plant2=1;

                for(int j=0;j<1000;j++)
                {
                    if( !o[j].exist ){id=j; break;}
                }

                o[id].load(1,1,2,px,py,2,1,300,6);
                //cout << "Creating object, ID: " << id << ", parameters: 1 1 2 " << x/100 << " " << y/100 << " 2 2 300 2\n";

                for(int i=0;i<1000;i++)
                {
                if( !o[i].exist ){id=i; break;}
                }

            }

            if ( !al_key_down(&klawiatura, ALLEGRO_KEY_P ) )plant2=0;

            if(game_over==0)
            {

            if(ax>0){x+=2; ax-=2;};
            if(ax<0){x-=2; ax+=2;};
            if(ay>0){y+=2; ay-=2;};
            if(ay<0){y-=2; ay+=2;};

            if(boost_right)if(ax>0){x+=2; ax-=2; boost_right--;}
            if(boost_left)if(ax<0){x-=2; ax+=2; boost_left--;}
            if(boost_down)if(ay>0){y+=2; ay-=2; boost_down--;}
            if(boost_up)if(ay<0){y-=2; ay+=2; boost_up--;}

            }

            if ( al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE ) && !k )
            {



                k=1;
                int choose=0;

                while(true)
                {

                int choose=minimenu(okno,0);

                if(choose==1)
                {
                    break;
                }

                if(choose==2)
                {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                    win=0;
                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                    break;
                }

                else if(choose==3)
                {
                      music_game_01->setVolume(0);
                        music_game_02->setVolume(0);
                    if(menu(okno,2))
                    {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                    stop_samouczek=0;
                    win=0;
                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;

                    break;
                    }
                    else return 0;
                }

                else if(choose==4)
                {
                    music_game_01->setVolume(0);
                    music_game_02->setVolume(0);
                    if(menu(okno,0))
                    {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                    stop_samouczek=0;
                    win=0;
                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                    break;
                    }
                    else return 0;

                }
                }
            }

            if( !al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE ) )k=0;

            if(game_over>0)game_over++;

            if(game_over>200)
            {
                int choose=0;
                if(control_points<points_count-points)choose=minimenu(okno,3);
                else                                  choose=minimenu(okno,2);

                if(choose==2)
                {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;

                    win=0;

                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                }

                else if(choose==3)
                {
                        music_game_01->setVolume(0);
                        music_game_02->setVolume(0);
                    if(menu(okno,2))
                    {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                    stop_samouczek=0;
                    win=0;

                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                    }
                    else return 0;
                }

                else if(choose==4)
                {
                      music_game_01->setVolume(0);
                      music_game_02->setVolume(0);
                    if(menu(okno,0))
                    {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                     stop_samouczek=0;
                    win=0;

                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                    }
                    else return 0;
                }
            }

            if(win>200)
            {
                int choose=minimenu(okno,1);

                if(choose==1)
                {
                    lvl++;
                    if(load_level(chapter, lvl, o, w, h, x, y, okno))
                    {
                    game_over=0;
                    stop_samouczek=0;
                    win=0;

                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                    }
                    else
                    {
                    if(menu(okno,2))
                        {
                        load_level(chapter, lvl, o, w, h, x, y, okno);
                        game_over=0;
                        win=0;

                        bombs=0;
                        points=0;
                        ax=0;
                        ay=0;
                        ide_w=1;
                        }
                    else return 0;
                    }
                }

                if(choose==2)
                {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                    win=0;

                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                }

                else if(choose==3)
                {
                      music_game_01->setVolume(0);
                 music_game_02->setVolume(0);
                    if(menu(okno,2))
                    {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                      stop_samouczek=0;

                    win=0;
                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;
                    }
                    else return 0;
                }

                else if(choose==4)
                {
                      music_game_01->setVolume(0);
                 music_game_02->setVolume(0);
                    if(menu(okno,0))
                    {
                    load_level(chapter, lvl, o, w, h, x, y, okno);
                    game_over=0;
                      stop_samouczek=0;

                    win=0;
                    bombs=0;
                    points=0;
                    ax=0;
                    ay=0;
                    ide_w=1;

                    }
                    else return 0;
                }
            }
            if(ogranicznik>0)ogranicznik--;
            czas = al_get_time();
        }


         fps=int(1/(al_get_time()-old_czas));
        old_czas = al_get_time();

        al_clear_to_color(al_map_rgb(0,0,0));



       for(int j=-1;j<screen_w/100+2;j++)
        for(int i=-1;i<screen_h/100+2;i++)
        {
           // al_draw_bitmap( solid1, j*100-50+ax+(screen_w/2)%100, i*100-50+ay+(screen_h/2)%100, 0 );
        //    al_draw_scaled_bitmap(solid2,j*100-50+ax+(screen_w/2)%100,i*100-50+ay+(screen_h/2)%100,100,100,j*100-50+ax+(screen_w/2)%100,i*100-50+ay+(screen_h/2)%100,100,100,0);
         al_draw_scaled_bitmap(solid1,0,0,500,500,j*100-50+ax+(screen_w/2)%100,i*100-50+ay+(screen_h/2)%100 ,   100,100,0);

        }



        for(int j=0;j<w+1;j++)
        for(int i=0;i<h+1;i++)
        {
            al_draw_bitmap( floor, j*100-x+screen_w/2-50, i*100-y+screen_h/2-50, 0 );
        }

        for(int i=0;i<1000;i++)
        {
            if( pow( o[i].x-px , 2) + pow (o[i].y-py , 2 ) < pow( 14, 2 ) )
            if(o[i].display)
            {
                if(o[i].texture ==0)al_draw_scaled_bitmap(solid1,0,0,500,500,o[i].x*100-x+screen_w/2-50,o[i].y*100-y+screen_h/2-50 ,  100,100,0);   //al_draw_bitmap( solid1, o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
           else if(o[i].texture > 0 && o[i].texture!=39)
           {
               if(o[i].texture==2 || o[i].texture==10 || o[i].texture==11 || o[i].texture==20 || o[i].texture==19 || o[i].texture==21 || o[i].texture==22 || o[i].texture==25)
               {
                   if(o[i].fuse==0)al_draw_scaled_bitmap( txt[ o[i].texture-1 ], 0, 0, 100, 100, o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 100, 100, 0 );
                   if(o[i].fuse>0 )al_draw_scaled_bitmap( txt[ o[i].texture-1 ], 0, 0, 100, 100, o[i].x*100-x+screen_w/2-50+(-20+o[i].fuse/15)/2, o[i].y*100-y+screen_h/2-50+(-20+o[i].fuse/15)/2, 120-(o[i].fuse/15), 120-(o[i].fuse/15), 0 );
               }
               else if(o[i].texture==23 || o[i].texture==31)
               {
                   if(o[i].fuse>0 )
                   {
                   if(o[i].ax!=0 || o[i].ay!=0)al_draw_scaled_bitmap( txt[ o[i].texture-1 ], 0, 0, 100, 100, o[i].x*100-x+screen_w/2-50+o[i].ax, o[i].y*100-y+screen_h/2-50+o[i].ay, 100, 100, 0 );
                   else al_draw_scaled_bitmap( txt[ o[i].texture-1 ], 0, 0, 100, 100, o[i].x*100-x+screen_w/2-50+(-20+o[i].fuse/15)/2, o[i].y*100-y+screen_h/2-50+(-20+o[i].fuse/15)/2, 120-(o[i].fuse/15), 120-(o[i].fuse/15), 0 );
                   }

                   if(o[i].fuse==0)
                   {
                   if(o[i].ax!=0 || o[i].ay!=0)al_draw_scaled_bitmap( txt[ o[i].texture-1 ], 0, 0, 100, 100, o[i].x*100-x+screen_w/2-50+o[i].ax, o[i].y*100-y+screen_h/2-50+o[i].ay, 100, 100, 0 );
                   else al_draw_scaled_bitmap( txt[ o[i].texture-1 ], 0, 0, 100, 100, o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 100, 100, 0 );
                   }
               }
               else if(o[i].texture==3 || o[i].texture==12 || o[i].texture==44)
               {
                   if(o[i].fuse>140)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, float(150-o[i].fuse)/10, float(150-o[i].fuse)/10, 0, 0 );
                   else if(o[i].fuse<10 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, float(o[i].fuse)/10, float(o[i].fuse)/10, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }
               else if(o[i].texture==32 || o[i].texture==40 || o[i].texture==41 || o[i].texture==42 || o[i].texture==43)
               {
                   if(o[i].fuse>130)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, float(150-o[i].fuse)/20, float(150-o[i].fuse)/20, 0, 0 );
                   else if(o[i].fuse<20 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, float(o[i].fuse)/20, float(o[i].fuse)/20, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }
               else if(o[i].type==2 || o[i].type==3)
               {
               if(o[i].direction==1)
               {
                   if(o[i].fuse>140)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 0, 50, o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2, float(150-o[i].fuse)/10, 1, 0, 0 );
                   else if(o[i].fuse<10 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 100, 50, o[i].x*100-x+screen_w/2+50, o[i].y*100-y+screen_h/2, float(o[i].fuse)/10, 1, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }

               else if(o[i].direction==3)
               {
                   if(o[i].fuse>140)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 100, 50, o[i].x*100-x+screen_w/2+50, o[i].y*100-y+screen_h/2, float(150-o[i].fuse)/10, 1, 0, 0 );
                   else if(o[i].fuse<10 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 0, 50, o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2, float(o[i].fuse)/10, 1, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }

               else if(o[i].direction==2)
               {
                   if(o[i].fuse>140)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 0, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2-50, 1, float(150-o[i].fuse)/10, 0, 0 );
                   else if(o[i].fuse<10 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 100, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2+50, 1, float(o[i].fuse)/10, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }

               else if(o[i].direction==4)
               {
                   if(o[i].fuse>140)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 100, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2+50, 1, float(150-o[i].fuse)/10, 0, 0 );
                   else if(o[i].fuse<10 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 0, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2-50, 1, float(o[i].fuse)/10, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }
               }

               else if(o[i].type==4)
               {
               if(o[i].direction==4)
               {
                   if(o[i].fuse>130)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 0, 50, o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2, float(150-o[i].fuse)/20, 1, 0, 0 );
                   else if(o[i].fuse<20 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 100, 50, o[i].x*100-x+screen_w/2+50, o[i].y*100-y+screen_h/2, float(o[i].fuse)/20, 1, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }

               else if(o[i].direction==2)
               {
                   if(o[i].fuse>130)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 100, 50, o[i].x*100-x+screen_w/2+50, o[i].y*100-y+screen_h/2, float(150-o[i].fuse)/20, 1, 0, 0 );
                   else if(o[i].fuse<20 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 0, 50, o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2, float(o[i].fuse)/20, 1, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }

               else if(o[i].direction==1)
               {
                   if(o[i].fuse>130)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 0, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2-50, 1, float(150-o[i].fuse)/20, 0, 0 );
                   else if(o[i].fuse<20 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 100, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2+50, 1, float(o[i].fuse)/20, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }

               else if(o[i].direction==3)
               {
                   if(o[i].fuse>130)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 100, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2+50, 1, float(150-o[i].fuse)/20, 0, 0 );
                   else if(o[i].fuse<20 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 0, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2-50, 1, float(o[i].fuse)/20, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }
               }

               /*else if(o[i].texture==5 || o[i].texture==7 || o[i].texture==9 || o[i].texture==14 || o[i].texture==16 || o[i].texture==18 || o[i].texture==34 || o[i].texture==36 || o[i].texture==38)
               {
                   if(o[i].fuse>140)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, 1, float(150-o[i].fuse)/10, 0, 0 );
                   else if(o[i].fuse<10 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, 1, float(o[i].fuse)/10, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }*/
               else if(o[i].texture==4 || o[i].texture==6 || o[i].texture==8 || o[i].texture==13 || o[i].texture==15 || o[i].texture==17 || o[i].texture==33 || o[i].texture==35 || o[i].texture==37)
               {
                   if(o[i].fuse>140)al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, float(150-o[i].fuse)/10, 1, 0, 0 );
                   else if(o[i].fuse<10 )al_draw_scaled_rotated_bitmap( txt[ o[i].texture-1 ], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, float(o[i].fuse)/10, 1, 0, 0 );
                   else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
               }
               else if(o[i].texture==45)al_draw_rotated_bitmap( txt[44], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, o[i].power*ALLEGRO_PI/2, 0 );
               else al_draw_bitmap( txt[ o[i].texture-1 ], o[i].x*100-x+screen_w/2-50, o[i].y*100-y+screen_h/2-50, 0 );
           }
           else if(o[i].texture==39)al_draw_rotated_bitmap( txt[38], 50, 50, o[i].x*100-x+screen_w/2, o[i].y*100-y+screen_h/2, o[i].power*ALLEGRO_PI/4, 0 );
            }
        }




        //al_draw_rectangle(px*100-x+screen_w/2-50, py*100-y+screen_h/2-50, px*100+100-x+screen_w/2-50,py*100+100-y+screen_h/2-50, al_map_rgb(255,0,0), 5);



        if(al_key_down( &klawiatura, sterowanie_2) && !game_over){ide_w=1;}
         if(al_key_down( &klawiatura, sterowanie_1) && !game_over){ide_w=0;}
         if(ide_w==1){al_draw_bitmap(player_right, screen_w/2-50, screen_h/2-50, 0);}
            if(ide_w==0){al_draw_bitmap(player_left, screen_w/2-50, screen_h/2-50, 0);}
            if(al_key_down( &klawiatura, sterowanie_2) && al_key_down( &klawiatura, sterowanie_1)){}


al_draw_textf(font,al_map_rgb(255,255,0), 50, 50, 0,"LVL: %d", lvl);
al_draw_textf(font,al_map_rgb(255,255,0), 50, 100, 0,"Bombs: %d", bombs);
al_draw_textf(font,al_map_rgb(255,255,0), 50, 150 , 0,"Points %d/%d", points,points_count);

  /*      al_draw_textf(font8,al_map_rgb(255,255,0), 50, 10 , 0,"ax=%d", ax);
        al_draw_textf(font8,al_map_rgb(255,255,0), 50, 30 , 0,"ay=%d", ay);
        al_draw_textf(font8,al_map_rgb(255,255,0), 50, 50 , 0,"x=%d", x);
        al_draw_textf(font8,al_map_rgb(255,255,0), 50, 70 , 0,"y=%d", y);



             al_draw_textf(font8,al_map_rgb(255,255,0), 50, 650, 0,"screen_w: %d", screen_w);
                  al_draw_textf(font8,al_map_rgb(255,255,0), 50, 670, 0,"screen_h: %d", screen_h);*/



        //   al_draw_textf(font8,al_map_rgb(255,255,0), 50, 220, 0,"   play_sounds: %d",    play_sounds);
         //   al_draw_textf(font8,al_map_rgb(255,255,0), 50, 230, 0,"   play_sounds: %d",    ogranicznik);
          if(show_fps==1) al_draw_textf(font8,al_map_rgb(255,0  ,0), screen_w-100, 50 , 0,"fps: %d", fps);

     //   al_draw_textf(font8,al_map_rgb(255,255,0), 50, 130, 0,"Control: %f", float(control));


if(stop_samouczek==0 && toturial==1)
{
if(chapter==1 && lvl==1 )samouczek(okno,lvl,chapter);
if(chapter==1 && lvl==4)samouczek(okno,lvl,chapter);
if(chapter==1 && lvl==5)samouczek(okno,lvl,chapter);
if(chapter==1 && lvl==7)samouczek(okno,lvl,chapter);
if(chapter==1 && lvl==10)samouczek(okno,lvl,chapter);
if(chapter==1 && lvl==20)samouczek(okno,lvl,chapter);
}





        al_flip_display();
    }

    al_destroy_display(okno);
    return 0;
}

