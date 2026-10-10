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

    void update_p1_pos(){
        y = y - speed_y;
        if(y>=460){
            speed_y = speed_y * (-1);
        }
        if(y<=430){
            speed_y = speed_y * (-1);
        }
    }

    void update_p2_pos(){
        x = x + speed_x;
        if(x<=880){
            speed_x = speed_x * (-1);
        }
        if(x>=910){
            speed_x = speed_x * (-1);
        }
    }

    void update_p3_pos(){
        y = y + speed_y;
        if(y>=490){
            speed_y = speed_y * (-1);
        }
        if(y<=460){
            speed_y = speed_y * (-1);
        }
    }

    void update_p4_pos(){
        x = x - speed_x;
        if(x<=850){
            speed_x = speed_x * (-1);
        }
        if(x>=880){
            speed_x = speed_x * (-1);
        }
    }


};

class BOX_3_PADDLE : public PADDLE{
    public:

    void update_p1_pos(){
        y = y + speed_y;
        if(y>=440){
            speed_y = speed_y * (-1);
        }
        if(y<=410){
            speed_y = speed_y * (-1);
        }
    }

    void update_p2_pos(){
        x = x - speed_x;
        if(x<=800){
            speed_x = speed_x * (-1);
        }
        if(x>=830){
            speed_x = speed_x * (-1);
        }
    }

    void update_p3_pos(){
        y = y - speed_y;
        if(y>=410){
            speed_y = speed_y * (-1);
        }
        if(y<=380){
            speed_y = speed_y * (-1);
        }
    }

    void update_p4_pos(){
        x = x + speed_x;
        if(x<=830){
            speed_x = speed_x * (-1);
        }
        if(x>=860){
            speed_x = speed_x * (-1);
        }
    }
};

class BOX_4_PADDLE : public PADDLE{
    public:
    
    void update_p1_pos(){
       y = y - speed_y;
        if(y>=360){
            speed_y = speed_y * (-1);
        }
        if(y<=330){
            speed_y = speed_y * (-1);
        }
    }
    void update_p2_pos(){
        x = x + speed_x;
        if(x<=780){
            speed_x = speed_x * (-1);
        }
        if(x>=810){
            speed_x = speed_x * (-1);
        }
    }
    void update_p3_pos(){
        y = y + speed_y;
        if(y>=390){
            speed_y = speed_y * (-1);
        }
        if(y<=360){
            speed_y = speed_y * (-1);
        }

    }
    void update_p4_pos(){
        x = x - speed_x;
        if(x<=750){
            speed_x = speed_x * (-1);
        }
        if(x>=780){
            speed_x = speed_x * (-1);
        }
    }
};

class BOX_5_PADDLE : public PADDLE{
    public:

    void update_p1_pos(){
        y = y + speed_y;
        if(y>=340){
            speed_y = speed_y * (-1);
        }
        if(y<=310){
            speed_y = speed_y * (-1);
        }
    }
    void update_p2_pos(){
        x = x - speed_x;
        if(x<=700){
            speed_x = speed_x * (-1);
        }
        if(x>=730){
            speed_x = speed_x * (-1);
        }
    }
    void update_p3_pos(){
        y = y - speed_y;
        if(y>=310){
            speed_y = speed_y * (-1);
        }
        if(y<=280){
            speed_y = speed_y * (-1);
        }
    }
    void update_p4_pos(){
        x = x + speed_x;
        if(x<=730){
            speed_x = speed_x * (-1);
        }
        if(x>=760){
            speed_x = speed_x * (-1);
        }
    }
};

class BOX_6_PADDLE : public PADDLE{
    public:

    void update_p1_pos(){
        y = y - speed_y;
        if(y>=260){
            speed_y = speed_y * (-1);
        }
        if(y<=230){
            speed_y = speed_y * (-1);
        }
    }
    void update_p2_pos(){
        x = x + speed_x;
        if(x<=680){
            speed_x = speed_x * (-1);
        }
        if(x>=710){
            speed_x = speed_x * (-1);
        }
    }
    void update_p3_pos(){
        y = y + speed_y;
        if(y>=290){
            speed_y = speed_y * (-1);
        }
        if(y<=260){
            speed_y = speed_y * (-1);
        }
    }
    void update_p4_pos(){
        x = x - speed_x;
        if(x<=650){
            speed_x = speed_x * (-1);
        }
        if(x>=680){
            speed_x = speed_x * (-1);
        }
    }
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

// =============================================== BOX_1 CONTENTS =======================================================   
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
    p1_box2.speed_y = 0.25;

    p2_box2.x = 880;
    p2_box2.y = 440;
    p2_box2.height = 20;
    p2_box2.width = 160;
    p2_box2.speed_x = 0.25;

    p3_box2.x = 1040;
    p3_box2.y = 460;
    p3_box2.height = 160;
    p3_box2.width = 20;
    p3_box2.speed_y = 0.25;

    p4_box2.x = 880;
    p4_box2.y = 620;
    p4_box2.height = 20;
    p4_box2.width = 160;
    p4_box2.speed_x = 0.25;



//=====================================================================================================================

    
// =============================================== BOX_3 CONTENTS =====================================================
    BOX_3_PADDLE p1_box3,p2_box3,p3_box3,p4_box3;

    p1_box3.x = 810;
    p1_box3.y = 410;
    p1_box3.height = 260;
    p1_box3.width = 20;
    p1_box3.speed_y = 0.25;
    
    p2_box3.x = 830;
    p2_box3.y = 390;
    p2_box3.height = 20;
    p2_box3.width = 260;
    p2_box3.speed_x = 0.25;

    p3_box3.x = 1090;
    p3_box3.y = 410;
    p3_box3.height = 260;
    p3_box3.width = 20;
    p3_box3.speed_y = 0.25;

    p4_box3.x = 830;
    p4_box3.y = 670;
    p4_box3.height = 20;
    p4_box3.width = 260;
    p4_box3.speed_x = 0.25;
//=====================================================================================================================

// =============================================== BOX_4 CONTENTS =====================================================
    BOX_4_PADDLE p1_box4,p2_box4,p3_box4,p4_box4;

    p1_box4.x = 760;
    p1_box4.y = 360;
    p1_box4.height = 360;
    p1_box4.width = 20;
    p1_box4.speed_y = 0.25;
    
    p2_box4.x = 780;
    p2_box4.y = 340;
    p2_box4.height = 20;
    p2_box4.width = 360;
    p2_box4.speed_x = 0.25;

    p3_box4.x = 1140;
    p3_box4.y = 360;
    p3_box4.height = 360;
    p3_box4.width = 20;
    p3_box4.speed_y = 0.25;

    p4_box4.x = 780;
    p4_box4.y = 720;
    p4_box4.height = 20;
    p4_box4.width = 360;
    p4_box4.speed_x = 0.25;

//=====================================================================================================================


// =============================================== BOX_5 CONTENTS =====================================================
    BOX_5_PADDLE p1_box5,p2_box5,p3_box5,p4_box5;

    p1_box5.x = 710;
    p1_box5.y = 310;
    p1_box5.height = 460;
    p1_box5.width = 20;
    p1_box5.speed_y = 0.25;
    
    p2_box5.x = 730;
    p2_box5.y = 290;
    p2_box5.height = 20;
    p2_box5.width = 460;
    p2_box5.speed_x = 0.25;

    p3_box5.x = 1190;
    p3_box5.y = 310;
    p3_box5.height = 460;
    p3_box5.width = 20;
    p3_box5.speed_y = 0.25;

    p4_box5.x = 730;
    p4_box5.y = 770;
    p4_box5.height = 20;
    p4_box5.width = 460;
    p4_box5.speed_x = 0.25; 

//=====================================================================================================================

// =============================================== BOX_6 CONTENTS =====================================================
    BOX_6_PADDLE p1_box6,p2_box6,p3_box6,p4_box6;

    p1_box6.x = 660;
    p1_box6.y = 260;
    p1_box6.height = 560;
    p1_box6.width = 20;
    p1_box6.speed_y = 0.25;
    
    p2_box6.x = 680;
    p2_box6.y = 240;
    p2_box6.height = 20;
    p2_box6.width = 560;
    p2_box6.speed_x = 0.25;

    p3_box6.x = 1240;
    p3_box6.y = 260;
    p3_box6.height = 560;
    p3_box6.width = 20;
    p3_box6.speed_y = 0.25;

    p4_box6.x = 680;
    p4_box6.y = 820;
    p4_box6.height = 20;
    p4_box6.width = 560;
    p4_box6.speed_x = 0.25; 

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

        p1_box2.update_p1_pos();
        p2_box2.update_p2_pos();
        p3_box2.update_p3_pos();
        p4_box2.update_p4_pos();

        p1_box3.update_p1_pos();
        p2_box3.update_p2_pos();
        p3_box3.update_p3_pos();
        p4_box3.update_p4_pos();

        p1_box4.update_p1_pos();
        p2_box4.update_p2_pos();
        p3_box4.update_p3_pos();
        p4_box4.update_p4_pos();

        p1_box5.update_p1_pos();
        p2_box5.update_p2_pos();
        p3_box5.update_p3_pos();
        p4_box5.update_p4_pos();

        p1_box6.update_p1_pos();
        p2_box6.update_p2_pos();
        p3_box6.update_p3_pos();
        p4_box6.update_p4_pos();

        Vector2 ball_pos = {ball.x,ball.y};

        Rectangle paddle_1_box1 = {p1_box1.x,p1_box1.y,p1_box1.width,p1_box1.height};
        Rectangle paddle_2_box1 = {p2_box1.x,p2_box1.y,p2_box1.width,p2_box1.height};
        Rectangle paddle_3_box1 = {p3_box1.x,p3_box1.y,p3_box1.width,p3_box1.height};
        Rectangle paddle_4_box1 = {p4_box1.x,p4_box1.y,p4_box1.width,p4_box1.height};

        Rectangle paddle_1_box2 = {p1_box2.x,p1_box2.y,p1_box2.width,p1_box2.height};
        Rectangle paddle_2_box2 = {p2_box2.x,p2_box2.y,p2_box2.width,p2_box2.height};
        Rectangle paddle_3_box2 = {p3_box2.x,p3_box2.y,p3_box2.width,p3_box2.height};
        Rectangle paddle_4_box2 = {p4_box2.x,p4_box2.y,p4_box2.width,p4_box2.height};

        Rectangle paddle_1_box3 = {p1_box3.x,p1_box3.y,p1_box3.width,p1_box3.height};
        Rectangle paddle_2_box3 = {p2_box3.x,p2_box3.y,p2_box3.width,p2_box3.height};
        Rectangle paddle_3_box3 = {p3_box3.x,p3_box3.y,p3_box3.width,p3_box3.height};
        Rectangle paddle_4_box3 = {p4_box3.x,p4_box3.y,p4_box3.width,p4_box3.height};
        
        Rectangle paddle_1_box4 = {p1_box4.x,p1_box4.y,p1_box4.width,p1_box4.height};
        Rectangle paddle_2_box4 = {p2_box4.x,p2_box4.y,p2_box4.width,p2_box4.height};
        Rectangle paddle_3_box4 = {p3_box4.x,p3_box4.y,p3_box4.width,p3_box4.height};
        Rectangle paddle_4_box4 = {p4_box4.x,p4_box4.y,p4_box4.width,p4_box4.height};
        
        Rectangle paddle_1_box5 = {p1_box5.x,p1_box5.y,p1_box5.width,p1_box5.height};
        Rectangle paddle_2_box5 = {p2_box5.x,p2_box5.y,p2_box5.width,p2_box5.height};
        Rectangle paddle_3_box5 = {p3_box5.x,p3_box5.y,p3_box5.width,p3_box5.height};
        Rectangle paddle_4_box5 = {p4_box5.x,p4_box5.y,p4_box5.width,p4_box5.height};
        
        Rectangle paddle_1_box6 = {p1_box6.x,p1_box6.y,p1_box6.width,p1_box6.height};
        Rectangle paddle_2_box6 = {p2_box6.x,p2_box6.y,p2_box6.width,p2_box6.height};
        Rectangle paddle_3_box6 = {p3_box6.x,p3_box6.y,p3_box6.width,p3_box6.height};
        Rectangle paddle_4_box6 = {p4_box6.x,p4_box6.y,p4_box6.width,p4_box6.height};



        
//===================================== CHECK COLLISION - BOX 1 ===========================9        

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_1_box1)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2_box1)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_3_box1)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_4_box1)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
//=======================================================================================
        

//===================================== CHECK COLLISION - BOX 2 ===========================        

        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_1_box2)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2_box2)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_3_box2)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_4_box2)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
            
//=======================================================================================

//===================================== CHECK COLLISION - BOX 3 ===========================        

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_1_box3)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2_box3)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_3_box3)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_4_box3)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

//=======================================================================================
        


//===================================== CHECK COLLISION - BOX 4 ===========================        

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_1_box4)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2_box4)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_3_box4)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_4_box4)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

//=======================================================================================



//===================================== CHECK COLLISION - BOX 5 ===========================        

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_1_box5)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2_box5)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_3_box5)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_4_box5)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

//=======================================================================================

//===================================== CHECK COLLISION - BOX 6 ===========================        

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_1_box6)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }
        
        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_2_box6)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_3_box6)==true){
            ball.x = screen_width/2;
            ball.y = screen_height/2;
        }

        if(CheckCollisionCircleRec(ball_pos,ball.radius,paddle_4_box6)==true){
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

        p1_box3.draw();
        p2_box3.draw();
        p3_box3.draw();
        p4_box3.draw();
        
        p1_box4.draw();
        p2_box4.draw();
        p3_box4.draw();
        p4_box4.draw();

        p1_box5.draw();
        p2_box5.draw();
        p3_box5.draw();
        p4_box5.draw();

        p1_box6.draw();
        p2_box6.draw();
        p3_box6.draw();
        p4_box6.draw();

        
        

        

        
        EndDrawing();
    }
    


    return 0;
}

