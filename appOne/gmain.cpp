#include"libOne.h"
struct DATA {
    int TITLE = 0;
    int PLAY = 1;
    int RESULT = 2;
    int state = TITLE;

    int img;
    float px;
    float py;
    float vx;
    float vy;

};
void loading(struct DATA* d) {
    d->img = loadImage("assets\\buta1.png");
}
void init(struct DATA* d) {
    d->px = 400;
    d->py = 400;
    d->vx = 10;
    d->vy = 5;
}
void title(struct DATA *d){
    clear(0);
    textSize(200);
    text("タイトル", 400, 300);
    if (isTrigger(KEY_SPACE)) {
        init(d);        //＆をつけるとポインタの数値になる
        d->state = d->PLAY;
    }
}
void play(struct DATA* d) {
    d->px += d->vx;
    clear(0);
    image(d->img, d->px, d->py);
    if (d->px > 1400) {
        d->state = d->RESULT;
    }
}
void result(struct DATA* d) {
    d->py += d->vy;
    clear(0);
    textSize(200);
    text("ゲームオーバー", 100, 300);
    image(d->img, d->px, d->py);
    if (isTrigger(KEY_SPACE)) {
        d->state = d->TITLE;
    }
}



void gmain() {
    window(1600, 900,full);
  
   float px = 400, py = 300, angle = 0, scale = 1;
   struct DATA d;
   loading(&d);
   while (notQuit) {
       if (d.state == d.TITLE) { title(&d); }
       else if (d.state == d.PLAY) { play(&d); }
       else if (d.state == d.RESULT) { result(&d); }


   }
}