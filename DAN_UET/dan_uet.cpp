#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<string>
#include<console.h>
#include<time.h>
#include<cmath>
#include<SDL.h>
#include"image.h"
#include<vector>
#define consolewidth 100
#define consoleheight 100
using namespace std;
void ShowCur(bool CursorVisibility)// ham xoa con tro
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);}
enum trang_thai{RIGHT,LEFT,UP,DOWN};
struct toa_do{
    int x,y;
};
struct snake2 {
vector<toa_do> dot;
int n;// con ran co n dot
trang_thai tt;
};
struct snake1{
 vector<toa_do> dot;
 int n;// con ran co n dot
 trang_thai tt;
};
struct hoa_qua{
toa_do td;
};

void ve(SDL_Texture *in_hinh_ngang,SDL_Texture *in_hinh_doc,SDL_Window *windown,SDL_Renderer *renderer,SDL_Texture *con_ran_1, SDL_Texture *con_ran_2,SDL_Texture *fruit,snake1 &con_ran, snake2 &con_ran_may,hoa_qua &hq){

for(int i=0;i<con_ran.n;i++) renderTexture(con_ran_1,renderer,5*con_ran.dot[i].x,5*con_ran.dot[i].y,5,5);
for(int i=0;i<con_ran_may.n;i++) renderTexture(con_ran_2,renderer,5*con_ran_may.dot[i].x,5*con_ran_may.dot[i].y,5,5);
renderTexture(fruit,renderer,5*hq.td.x,5*hq.td.y,5,5);
for(int i=0;i<consoleheight;i++) renderTexture(in_hinh_doc,renderer,5*consolewidth,5*i,5,5);
for(int i=0;i<=consolewidth;i++) renderTexture(in_hinh_doc,renderer,5*i,5*consoleheight,5,5);
}
void check_con_ran_may(snake2 &con_ran_may,hoa_qua &hq){ int a[2][4],i,_max;
for(int i =0; i<4;i++) {a[0][i]=1;a[1][i]=0;}
 for(i=1;i<con_ran_may.n;i++){
        if(con_ran_may.dot[0].x+1==con_ran_may.dot[i].x&&con_ran_may.dot[0].y==con_ran_may.dot[i].y) {a[0][0]=0;}
        if(con_ran_may.dot[0].x-1==con_ran_may.dot[i].x&&con_ran_may.dot[0].y==con_ran_may.dot[i].y) {a[0][1]=0;}
        if(con_ran_may.dot[0].x==con_ran_may.dot[i].x&&con_ran_may.dot[0].y-1==con_ran_may.dot[i].y) {a[0][2]=0;}
        if(con_ran_may.dot[0].x==con_ran_may.dot[i].x&&con_ran_may.dot[0].y+1==con_ran_may.dot[i].y) {a[0][3]=0;}
}
a[1][0]=pow(((con_ran_may.dot[0].x+1)-hq.td.x),2)+pow((con_ran_may.dot[0].y-hq.td.y),2);//130
a[1][1]=pow(((con_ran_may.dot[0].x-1)-hq.td.x),2)+pow((con_ran_may.dot[0].y-hq.td.y),2);//20
a[1][2]=pow((con_ran_may.dot[0].x-hq.td.x),2)+pow(((con_ran_may.dot[0].y-1)-hq.td.y),2);//50
a[1][3]=pow((con_ran_may.dot[0].x-hq.td.x),2)+pow(((con_ran_may.dot[0].y+1)-hq.td.y),2);//200
for(i=0; i < 4; i++) if(a[0][i] == 1) _max=i;
for(i=0;i<4;i++){
    if(a[0][i] == 1&&a[1][i]< a[1][_max]) _max=i;
}
con_ran_may.tt=trang_thai(_max);
 }
//khoi tao
void Khoi_tao(snake1 &con_ran,snake2 &con_ran_may,hoa_qua &hq){
    con_ran.n=2;
    con_ran_may.n=1;
   /* con_ran.dot[0].x=2;
    con_ran.dot[0].y=0;
    con_ran.dot[1].x=1;
    con_ran.dot[1].y=0;
    con_ran.dot[2].x=0;
   con_ran.dot[2].y=0;
   con_ran_may.dot[0].x=2;
   con_ran_may.dot[0].y=1;
    con_ran_may.dot[1].x=1;
    con_ran_may.dot[1].y=1;
    con_ran_may.dot[2].x=0;
   con_ran_may.dot[2].y=1;*/
   toa_do a;
   a.x=0; a.y=0;
   con_ran.dot.push_back(a);
   a.x=1;a.y=0;
   con_ran.dot.insert(con_ran.dot.begin(),a);
   a.x=0;a.y=1;
  con_ran_may.dot.push_back(a);
  con_ran_may.tt=RIGHT;
   con_ran.tt=RIGHT;
hq.td.x=10;
  hq.td.y=10;
    }
    //hien thi
/*void hien_thi(snake1 con_ran,snake2 con_ran_may,hoa_qua &hq,int &diem,int &diem_may){


gotoxy(60,14);
cout<<"DIEM CUA BAN: "<<diem;
gotoxy(60,15);
cout<<"DIEM CUA MAY: "<<diem_may;
// in soc soc
for (int i = 0; i < consoleheight; i++)
	{setcolor(14);
		gotoxy (consolewidth, i);
		putchar (179);
	}
	// in con ran nguoi choi
        for(int i=0;i<con_ran.n;i++){
            gotoxy(con_ran.dot[i].x,con_ran.dot[i].y);
            setcolor(9);
          putchar('*');
        }
        // in con ran may
        for(int i=0;i<con_ran_may.n;i++){
            gotoxy(con_ran_may.dot[i].x,con_ran_may.dot[i].y);
            setcolor(11);
           putchar('*');
        }
        gotoxy(hq.td.x,hq.td.y);
        setcolor(13);
        putchar('*');
        }*/
        // dieu khien con ran
     void dieu_khien(snake1 &con_ran,snake2 &con_ran_may,SDL_Event bam,bool &running) {
         // dieu khien con ran nguoi choi

         for(int i=con_ran.n-1;i>0;i--){
            con_ran.dot[i].x=con_ran.dot[i-1].x;
            con_ran.dot[i].y=con_ran.dot[i-1].y;
         }
     while (SDL_PollEvent(&bam)) {
        	if (bam.type == SDL_QUIT) running = false;
            if (bam.type == SDL_KEYDOWN){
        switch(bam.key.keysym.sym){
        case SDLK_LEFT: {if(con_ran.tt!=RIGHT) con_ran.tt=LEFT; break;}
        case SDLK_DOWN: {if(con_ran.tt!=UP)
            con_ran.tt=DOWN; break;}
    case SDLK_RIGHT: {if(con_ran.tt!=LEFT)
        con_ran.tt=RIGHT;break;}
        case SDLK_UP: {if(con_ran.tt!=DOWN) con_ran.tt=UP; break;}
        }
     }}
     if(con_ran.tt==LEFT) {con_ran.dot[0].x--; if(con_ran.dot[0].x<0) con_ran.dot[0].x=consolewidth-1;}
     else if(con_ran.tt==RIGHT) {con_ran.dot[0].x++;if(con_ran.dot[0].x==consolewidth) con_ran.dot[0].x=0;}
    else if(con_ran.tt==UP) {con_ran.dot[0].y--;if(con_ran.dot[0].y<0) con_ran.dot[0].y=consoleheight-1;}
    else if(con_ran.tt==DOWN) {con_ran.dot[0].y++;if(con_ran.dot[0].y==consoleheight) con_ran.dot[0].y=0;}
    // dieu khien con ran may
     for(int i=con_ran_may.n-1;i>0;i--){
            con_ran_may.dot[i].x=con_ran_may.dot[i-1].x;
            con_ran_may.dot[i].y=con_ran_may.dot[i-1].y;
         }
         if(con_ran_may.tt==LEFT) {con_ran_may.dot[0].x--; if(con_ran_may.dot[0].x<0) con_ran_may.dot[0].x=consolewidth-1;}
     else if(con_ran_may.tt==RIGHT) {con_ran_may.dot[0].x++;if(con_ran_may.dot[0].x>=consolewidth) con_ran_may.dot[0].x=0;}
    else if(con_ran_may.tt==UP) {con_ran_may.dot[0].y--;if(con_ran_may.dot[0].y<0) con_ran_may.dot[0].y=consoleheight-1;}
    else if(con_ran_may.tt==DOWN) {con_ran_may.dot[0].y++;if(con_ran_may.dot[0].y>=consoleheight) con_ran_may.dot[0].y=0;}
     }
     // xu li
     int xu_li(snake1 &con_ran,snake2 &con_ran_may,hoa_qua &hq,int &thoi_gian,int &diem,int &diem_may){
     // xu li con ran nguoi choi
         if(con_ran.dot[0].x==hq.td.x&&con_ran.dot[0].y==hq.td.y){
                    if(thoi_gian>40){
    thoi_gian-=30;}
                con_ran.n++;
                toa_do a;
                a.x=con_ran.dot[0].x;
                a.y=con_ran.dot[0].y;
                con_ran.dot.insert(con_ran.dot.begin(),a);
     for(int i=con_ran.n-1;i>0;i--) {con_ran.dot[i].x=con_ran.dot[i-1].x;con_ran.dot[i].y=con_ran.dot[i-1].y;}
     if(con_ran.tt==LEFT) {con_ran.dot[0].x--; if(con_ran.dot[0].x<0) con_ran.dot[0].x=consolewidth-1;}
     else if(con_ran.tt==RIGHT) {con_ran.dot[0].x++;if(con_ran.dot[0].x>=consolewidth) con_ran.dot[0].x=0;}
    else if(con_ran.tt==UP) {con_ran.dot[0].y--;if(con_ran.dot[0].y<0) con_ran.dot[0].y=consoleheight-1;}
    else if(con_ran.tt==DOWN) {con_ran.dot[0].y++;if(con_ran.dot[0].y>=consoleheight) con_ran.dot[0].y=0;}
    hq.td.x=rand()%consolewidth;
    hq.td.y=rand()%consoleheight;
    for(int i=1;i<con_ran_may.n;i++){
        if(hq.td.x==con_ran.dot[i].x&&hq.td.y==con_ran.dot[i].y){
            hq.td.x=rand()%consolewidth;
    hq.td.y=rand()%consoleheight;
        }
    }
    diem+=50;
     }
     // xu li con ran tu dong
   check_con_ran_may(con_ran_may,hq);
        // xu li con ran tu dong an hoa qua
     if(con_ran_may.dot[0].x==hq.td.x&&con_ran_may.dot[0].y==hq.td.y){
                if(thoi_gian>40){
    thoi_gian-=30;}
             con_ran_may.n++;
             toa_do b;
             b.x=con_ran_may.dot[0].x;
             b.y=con_ran_may.dot[0].y;
             con_ran_may.dot.insert(con_ran_may.dot.begin(),b);
         for(int i=con_ran_may.n-1;i>0;i--)
        con_ran_may.dot[i]=con_ran_may.dot[i-1];
     if(con_ran_may.tt==LEFT) {con_ran_may.dot[0].x--; if(con_ran_may.dot[0].x<0) con_ran_may.dot[0].x=consolewidth-1;}
     else if(con_ran_may.tt==RIGHT) {con_ran_may.dot[0].x++;if(con_ran_may.dot[0].x>=consolewidth) con_ran_may.dot[0].x=0;}
    else if(con_ran_may.tt==UP) {con_ran_may.dot[0].y--;if(con_ran_may.dot[0].y<0) con_ran_may.dot[0].y=consoleheight-1;}
    else if(con_ran_may.tt==DOWN) {con_ran_may.dot[0].y++;if(con_ran_may.dot[0].y>=consoleheight) con_ran_may.dot[0].y=0;}
    hq.td.x=rand()%consolewidth;
    hq.td.y=rand()%consoleheight;
    for(int i=1;i<con_ran_may.n;i++){
        if(hq.td.x==con_ran_may.dot[i].x&&hq.td.y==con_ran_may.dot[i].y){
            hq.td.x=rand()%consolewidth;
    hq.td.y=rand()%consoleheight;
        }
    }
    diem_may+=10;
     }
     for(int i=1;i<con_ran.n;i++){
        if(con_ran.dot[0].x==con_ran.dot[i].x&&con_ran.dot[0].y==con_ran.dot[i].y) return 0;
     }
      for(int i=1;i<con_ran_may.n;i++){
        if(con_ran_may.dot[0].x==con_ran_may.dot[i].x&&con_ran_may.dot[0].y==con_ran_may.dot[i].y) return 0;
     }
     }
int main(int argc, char* args[]){


    bool running=true;
    SDL_Event bam;
    SDL_Window *windown;
    SDL_Renderer *renderer;
    initSDL(windown,renderer);
    SDL_Texture *con_ran_1= loadTexture("con_ran_1.bmp",renderer);
    SDL_Texture *con_ran_2= loadTexture("con_ran_2.bmp",renderer);
    SDL_Texture *fruit=loadTexture("fruit.bmp",renderer);
    SDL_Texture *in_hinh_doc=loadTexture("in_hinh_doc.bmp",renderer);
    SDL_Texture *in_hinh_ngang=loadTexture("in_hinh_doc.bmp",renderer);
    int thoi_gian=100;
    srand(time(NULL));
    int diem=0, diem_may=0;
    snake1 con_ran ;
    snake2 con_ran_may;
    hoa_qua hq;
    Khoi_tao(con_ran,con_ran_may,hq);
while(running){
        //ham hien thi
//hien_thi(con_ran,con_ran_may,hq,diem,diem_may);
SDL_RenderClear(renderer);
ve(in_hinh_ngang,in_hinh_doc,windown,renderer,con_ran_1,con_ran_2,fruit,con_ran,con_ran_may,hq);
SDL_UpdateWindowSurface(windown);
SDL_RenderPresent(renderer);

//dieu khien
dieu_khien(con_ran,con_ran_may,bam,running);
// xu li qua trinh choi game
int thua=xu_li(con_ran,con_ran_may,hq,thoi_gian,diem,diem_may);
if(thua==0) {
    gotoxy(60,16);
    setcolor(10);
    if(diem<diem_may) cout<<"YOU LOSE";
    else if(diem==diem_may) cout<<"BAN HOA";
    else cout<<"YOU WIN";
    setcolor(0);
    break;
}
SDL_Delay(10);
ShowCur(false);// ham xoa con tro
}
SDL_DestroyTexture(con_ran_1);
SDL_DestroyTexture(con_ran_2);
SDL_DestroyTexture(fruit);
quitSDL(windown,renderer);
return 0;
}
