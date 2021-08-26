#include "raylib.h"

int main()
{
    int width{800};
    int height{450};
    InitWindow(width, height, "Circle Versus Square");

    //circle details
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    int square_x{300};
    int square_y{0};
    int square_length{50};
    int l_square_x{square_x};
    int r_square_x{square_x + square_length};
    int u_square_y{square_y};
    int b_square_y{square_y + square_length};

    int direction{10};

     bool collision_with_square = 
                        (b_square_y >= u_circle_y) && 
                        (u_square_y <= b_circle_y) && 
                        (r_square_x >= l_circle_x) &&
                        (l_square_x <= r_circle_x);


    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //game logic
        if (collision_with_square) {
            DrawText("GAME OVER!", 400, 200, 20, RED);
        }
        else {
            DrawText("W: UP // X: DOWN", 400, 375, 20, GREEN);
            DrawText("A: LEFT // D: RIGHT", 400, 350, 20, GREEN);
            DrawText("Don't get hit by the square!", 400, 400, 20, GREEN);

            //update circle coordinates
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_square_x = square_x;
            r_square_x = square_x + square_length;
            u_square_y = square_y;
            b_square_y = square_y + square_length;

            //update collision status
             collision_with_square = 
                    (b_square_y >= u_circle_y) && 
                    (u_square_y <= b_circle_y) && 
                    (r_square_x >= l_circle_x) &&
                    (l_square_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius,RED);
            DrawRectangle(square_x, square_y, square_length, square_length,BLACK);
            
            square_y += direction;
            if (square_y > height || square_y < 0)
            {
                direction = -direction;
            }
            
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }   
            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y -= 10;
            }     
            if (IsKeyDown(KEY_X) && circle_y < height)
            {
                circle_y += 10;
            }
        }
        EndDrawing();
    }
}