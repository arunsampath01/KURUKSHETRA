#include <iostream>
#include <raylib.h>
using namespace std;

int screen_width; //1920 - 960
int screen_height; //1080 - 540

void grid(){
    int x=0,y=0;
    for(x=0;x<=screen_width;x+=10){
        DrawLine(x,0,x,screen_height,GRAY);
    }
    for(y=0;y<=screen_height;y+=10){
        DrawLine(0,y,screen_width,y,GRAY);
    }

}

class BALL{
    public:
    float x,y;
    float radius;
    float speed_x,speed_y;

    void draw(){
        DrawCircle(x,y,radius,WHITE);
    }

    void update(){
        if(IsKeyDown(KEY_UP)) y = y - speed_y;
        if(IsKeyDown(KEY_DOWN)) y = y + speed_y;
        if(IsKeyDown(KEY_RIGHT)) x = x + speed_x;
        if(IsKeyDown(KEY_LEFT)) x = x - speed_x;   
    }

};

class PADDLE{
    public:
    float x,y;
    float height, width;
    float speed_x,speed_y;

    void draw(){
        DrawRectangle(x,y,width,height,WHITE);
    }


    
};

class BOX_1_PADDLE : public PADDLE{
    public:

    void update_p1_pos(){
        y = y + speed_y;
        if(y>=540){
            speed_y = speed_y * (-1);
        }
        if(y<=510){
            speed_y = speed_y * (-1);
        }
        

    }

    void update_p2_pos(){
        x = x - speed_x;
        if(x<=900){
            speed_x = speed_x * (-1);
        }
        if(x>=930){
            speed_x = speed_x * (-1);
        }
    }

    void update_p3_pos(){
        y = y - speed_y;
        if(y>=510){
            speed_y = speed_y * (-1);
        }
        if(y<=480){
            speed_y = speed_y * (-1);
        }

    }

    void update_p4_pos(){
        x = x + speed_x;
        if(x<=930){
            speed_x = speed_x * (-1);
        }
        if(x>=960){
            speed_x = speed_x * (-1);
        }

    }

};

class BOX_2_PADDLE : public PADDLE{
    public:


};


int main(){

    InitWindow(screen_width,screen_height,"KURUKSHETRA");
    SetTargetFPS(120);
    screen_height = GetScreenHeight();
    screen_width = GetScreenWidth();

   
    
    
    BALL ball;
    ball.x = GetScreenWidth()/2;
    ball.y = GetScreenHeight()/2;
    ball.radius = 10;
    ball.speed_x = 1;
    ball.speed_y = 1;

// =============================================== BOX_1 CONTENTS =====================================================    
    BOX_1_PADDLE p1_box1,p2_box1,p3_box1,p4_box1;

    //p1_b1 - LEFT PADDLE
    p1_box1.x = screen_width/2 - 50;
    p1_box1.y = screen_height/2 - 30;
    p1_box1.height = 60;
    p1_box1.width = 20;
    p1_box1.speed_y = 0.25;


    //p2_b1 - TOP PADDLE
    p2_box1.x = screen_width/2 - 30;
    p2_box1.y = screen_height/2 - 50;
    p2_box1.height = 20;
    p2_box1.width = 60;
    p2_box1.speed_x = 0.25;
    
    
    //p3_b1 - RIGHT PADDLE
    p3_box1.x = screen_width/2 + 30;
    p3_box1.y = screen_height/2 - 30;
    p3_box1.width = 20;
    p3_box1.height = 60;
    p3_box1.speed_y = 0.25;
    

    //p4_b1 - BOTTOM PADDLE
    p4_box1.x = screen_width/2 - 30;
    p4_box1.y = screen_height/2 + 30;
    p4_box1.height = 20;
    p4_box1.width = 60;
    p4_box1.speed_x = 0.25;
// ====================================================================================================================

// =============================================== BOX_2 CONTENTS =====================================================    

    BOX_2_PADDLE p1_box2,p2_box2,p3_box2,p4_box2;

    p1_box2.x = 860;
    p1_box2.y = 460;
    p1_box2.height = 160;
    p1_box2.width = 20;

    p2_box2.x = 880;
    p2_box2.y = 440;
    p2_box2.height = 20;
    p2_box2.width = 160;

    p3_box2.x = 1040;
    p3_box2.y = 460;
    p3_box2.height = 160;
    p3_box2.width = 20;

    p4_box2.x = 880;
    p4_box2.y = 620;
    p4_box2.height = 20;
    p4_box2.width = 160;



//=====================================================================================================================

    


    
    while (WindowShouldClose()==false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        //grid();
        
        ball.draw();
        ball.update();
        
        p1_box1.update_p1_pos();
        p2_box1.update_p2_pos();
        p3_box1.update_p3_pos();
        p4_box1.update_p4_pos();

        Vector2 ball_pos = {ball.x,ball.y};

        Rectangle paddle_1 = {p1_box1.x,p1_box1.y,p1_box1.width,p1_box1.height};
        Rectangle paddle_2 = {p2_box1.x,p2_box1.y,p2_box1.width,p2_box1.height};
        Rectangle paddle_3 = {p3_box1.x,p3_box1.y,p3_box1.width,p3_box1.height};
        Rectangle paddle_4 = {p4_box1.x,p4_box1.y,p4_box1.width,p4_box1.height};
        
//===================================== CHECK COLLISION - BOX 1 ===========================        

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_1)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_3)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_4)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
//=======================================================================================
        

        p1_box1.draw();
        p2_box1.draw();
        p3_box1.draw();
        p4_box1.draw();

        p1_box2.draw();
        p2_box2.draw();
        p3_box2.draw();
        p4_box2.draw();
        

    
        
        

        

        
        EndDrawing();
    }
    


    return 0;
}
