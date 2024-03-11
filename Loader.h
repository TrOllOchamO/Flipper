#include "Map.h"
#include "Wall.h"
#include "Rectangle.h"
#include "Flipper.h"
#include "Launcher.h"
#include "Bumper.h"
#include "Vector2D.h"
#include "Circle.h"
#include "Multiplicateur.h"
#include "GameInfo.h"
#include "Door.h"
#include "Brick.h"
#include "Randomizer.h"
#include "BallExpander.h"
#include "Background.h"
#include <memory>


#ifndef LOADER_H_
#define LOADER_H_

#define BUMPER "resources/Bumper.png"
#define MULTIPLICATEUR "resources/Multiplicateur.png"
#define BACKGROUND_MARIO "resources/Background.png"
#define WOOD "resources/wood.png"
#define BLUE "resources/jeton_bleu.png"
#define RED "resources/jeton_rouge.png"
#define ROULETTE "resources/roulette.png"
#define FEUTRINE "resources/feutrine.jpg"
#define CHAMPIGNON "resources/champignon.png"
#define TUYAU "resources/toyô.png"
#define LEFTTRIANGLEBUMPER "resources/left_triangle_bumper.png"
#define RIGHTTRIANGLEBUMPER "resources/right_triangle_bumper.png"
#define LEFTFLIPPER "resources/Left_Flipper.png"
#define RIGHTFLIPPER "resources/Right_Flipper.png"
#define TEST "resources/Test.jpg"
#define MARIOBALL "resources/Mario_ball.png"
#define BACKGROUNDBLEU "resources/Bleu.png"
#define BACKGROUNDNOIR "resources/Noir.png"


class Loader {
public:
    static void load_map_1(Map& map) {
        // shape
        std::unique_ptr<Rectangle> bottom_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(300, 790), 100, 10));
        std::unique_ptr<Rectangle> top_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 400, 10));
        std::unique_ptr<Rectangle> left_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 10, 700));
        std::unique_ptr<Rectangle> right_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(390, 100), 10, 700));
        
        std::unique_ptr<Polygone> bot_left_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_left_angle_shape->add_points({Vector2D(50,800), Vector2D(10,800), Vector2D(10,690), Vector2D(55,730)});
        std::unique_ptr<Polygone> bot_right_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_right_angle_shape->add_points({Vector2D(340,800), Vector2D(300,800), Vector2D(295,730), Vector2D(340,690)});

        std::unique_ptr<Rectangle> separation_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(340, 250), 10, 650));

        std::unique_ptr<Polygone> left_angle_shape = std::make_unique<Polygone>(Polygone());
        left_angle_shape->add_points({Vector2D(0,100), Vector2D(100,100), Vector2D(0,200)});
        std::unique_ptr<Polygone> right_angle_shape = std::make_unique<Polygone>(Polygone());
        right_angle_shape->add_points({Vector2D(300,100), Vector2D(400,100), Vector2D(400,200)});

        std::unique_ptr<Rectangle> left_middle_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(10, 440), 110, 10));
        std::unique_ptr<Rectangle> right_middle_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(230, 440), 110, 10));

        std::unique_ptr<Circle> roulette_shape = std::make_unique<Circle>(Circle(Vector2D(143, 413), 32));

        std::unique_ptr<Circle> point_bumper_1_shape = std::make_unique<Circle>(Circle(Vector2D(10, 392), 24));
        std::unique_ptr<Circle> point_bumper_2_shape = std::make_unique<Circle>(Circle(Vector2D(292, 392), 24));
        std::unique_ptr<Circle> point_bumper_3_shape = std::make_unique<Circle>(Circle(Vector2D(10, 450), 24));
        std::unique_ptr<Circle> point_bumper_4_shape = std::make_unique<Circle>(Circle(Vector2D(292, 450), 24));

        std::unique_ptr<Circle> mult_bumper_1_shape = std::make_unique<Circle>(Circle(Vector2D(113, 200), 16));
        std::unique_ptr<Circle> mult_bumper_2_shape = std::make_unique<Circle>(Circle(Vector2D(205, 200), 16));
        std::unique_ptr<Circle> mult_bumper_3_shape = std::make_unique<Circle>(Circle(Vector2D(68, 600), 16));
        std::unique_ptr<Circle> mult_bumper_4_shape = std::make_unique<Circle>(Circle(Vector2D(250, 600), 16));

        std::unique_ptr<Rectangle> bg_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 400, 700));


        // entity
        std::unique_ptr<Wall> bottom_wall = std::make_unique<Wall>(std::move(bottom_wall_shape), WOOD);
        std::unique_ptr<Wall> top_wall = std::make_unique<Wall>(std::move(top_wall_shape), WOOD);
        std::unique_ptr<Wall> left_wall = std::make_unique<Wall>(std::move(left_wall_shape), WOOD);
        std::unique_ptr<Wall> right_wall = std::make_unique<Wall>(std::move(right_wall_shape), WOOD);

        std::unique_ptr<Wall> separation_wall = std::make_unique<Wall>(std::move(separation_wall_shape), WOOD);

        std::unique_ptr<Wall> left_angle = std::make_unique<Wall>(std::move(left_angle_shape), WOOD);
        std::unique_ptr<Wall> right_angle = std::make_unique<Wall>(std::move(right_angle_shape), WOOD);

        std::unique_ptr<Wall> bot_left_angle = std::make_unique<Wall>(std::move(bot_left_angle_shape), WOOD);
        std::unique_ptr<Wall> bot_right_angle = std::make_unique<Wall>(std::move(bot_right_angle_shape), WOOD);

        std::unique_ptr<Wall> left_middle_wall = std::make_unique<Wall>(std::move(left_middle_wall_shape), WOOD);
        std::unique_ptr<Wall> right_middle_wall = std::make_unique<Wall>(std::move(right_middle_wall_shape), WOOD);

        std::unique_ptr<Randomizer> roulette = std::make_unique<Randomizer>(std::move(roulette_shape), ROULETTE);

        std::unique_ptr<Bumper> point_bumper_1 = std::make_unique<Bumper>(std::move(point_bumper_1_shape), RED);
        std::unique_ptr<Bumper> point_bumper_2 = std::make_unique<Bumper>(std::move(point_bumper_2_shape), RED);
        std::unique_ptr<Bumper> point_bumper_3 = std::make_unique<Bumper>(std::move(point_bumper_3_shape), RED);
        std::unique_ptr<Bumper> point_bumper_4 = std::make_unique<Bumper>(std::move(point_bumper_4_shape), RED);

        std::unique_ptr<Multiplicateur> mult_bumper_1 = std::make_unique<Multiplicateur>(std::move(mult_bumper_1_shape), BLUE);
        std::unique_ptr<Multiplicateur> mult_bumper_2 = std::make_unique<Multiplicateur>(std::move(mult_bumper_2_shape), BLUE);
        std::unique_ptr<Multiplicateur> mult_bumper_3 = std::make_unique<Multiplicateur>(std::move(mult_bumper_3_shape), BLUE);
        std::unique_ptr<Multiplicateur> mult_bumper_4 = std::make_unique<Multiplicateur>(std::move(mult_bumper_4_shape), BLUE);

        std::unique_ptr<Launcher> launcher = std::make_unique<Launcher>("");
        std::unique_ptr<Flipper> left_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::LEFT);
        std::unique_ptr<Flipper> right_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::RIGHT);
        std::unique_ptr<Door> door = std::make_unique<Door>(WOOD);
        std::unique_ptr<GameInfo> game_info = std::make_unique<GameInfo>();

        std::unique_ptr<Background> bg = std::make_unique<Background>(std::move(bg_shape), FEUTRINE);



        // make entity
        map.make_entity(std::move(bg));

        map.make_entity(std::move(game_info));
        map.make_entity(std::move(launcher));
        map.make_entity(std::move(left_flipper));
        map.make_entity(std::move(right_flipper));
        map.make_entity(std::move(door));
        
        map.make_entity(std::move(bottom_wall));
        map.make_entity(std::move(top_wall));
        map.make_entity(std::move(left_wall));
        map.make_entity(std::move(right_wall));

        map.make_entity(std::move(separation_wall));

        map.make_entity(std::move(left_angle));
        map.make_entity(std::move(right_angle));

        map.make_entity(std::move(bot_left_angle));
        map.make_entity(std::move(bot_right_angle));

        map.make_entity(std::move(left_middle_wall));
        map.make_entity(std::move(right_middle_wall));

        map.make_entity(std::move(roulette));

        map.make_entity(std::move(point_bumper_1));
        map.make_entity(std::move(point_bumper_2));
        map.make_entity(std::move(point_bumper_3));
        map.make_entity(std::move(point_bumper_4));

        map.make_entity(std::move(mult_bumper_1));
        map.make_entity(std::move(mult_bumper_2));
        map.make_entity(std::move(mult_bumper_3));
        map.make_entity(std::move(mult_bumper_4));

        map.set_name("Casino");
    }






    static void load_map_2(Map& map) {
        // shape
        std::unique_ptr<Rectangle> bottom_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(300, 790), 100, 10));
        std::unique_ptr<Rectangle> top_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 400, 10));
        std::unique_ptr<Rectangle> left_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 10, 700));
        std::unique_ptr<Rectangle> right_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(390, 100), 10, 700));
        
        std::unique_ptr<Polygone> bot_left_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_left_angle_shape->add_points({Vector2D(50,800), Vector2D(10,800), Vector2D(10,690), Vector2D(55,730)});
        std::unique_ptr<Polygone> bot_right_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_right_angle_shape->add_points({Vector2D(340,800), Vector2D(300,800), Vector2D(295,730), Vector2D(340,690)});

        std::unique_ptr<Rectangle> separation_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(340, 250), 10, 650));

        std::unique_ptr<Polygone> left_angle_shape = std::make_unique<Polygone>(Polygone());
        left_angle_shape->add_points({Vector2D(0,100), Vector2D(100,100), Vector2D(0,200)});
        std::unique_ptr<Polygone> right_angle_shape = std::make_unique<Polygone>(Polygone());
        right_angle_shape->add_points({Vector2D(300,100), Vector2D(400,100), Vector2D(400,200)});

        // entity
        
        std::unique_ptr<Wall> bottom_wall = std::make_unique<Wall>(std::move(bottom_wall_shape), WOOD);
        std::unique_ptr<Wall> top_wall = std::make_unique<Wall>(std::move(top_wall_shape), WOOD);
        std::unique_ptr<Wall> left_wall = std::make_unique<Wall>(std::move(left_wall_shape), WOOD);
        std::unique_ptr<Wall> right_wall = std::make_unique<Wall>(std::move(right_wall_shape), WOOD);

        std::unique_ptr<Wall> separation_wall = std::make_unique<Wall>(std::move(separation_wall_shape), WOOD);

        std::unique_ptr<Wall> left_angle = std::make_unique<Wall>(std::move(left_angle_shape), WOOD);
        std::unique_ptr<Wall> right_angle = std::make_unique<Wall>(std::move(right_angle_shape), WOOD);

        std::unique_ptr<Wall> bot_left_angle = std::make_unique<Wall>(std::move(bot_left_angle_shape), WOOD);
        std::unique_ptr<Wall> bot_right_angle = std::make_unique<Wall>(std::move(bot_right_angle_shape), WOOD);

        std::unique_ptr<Launcher> launcher = std::make_unique<Launcher>(TUYAU);
        std::unique_ptr<Flipper> left_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::LEFT);
        std::unique_ptr<Flipper> right_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::RIGHT);
        std::unique_ptr<Door> door = std::make_unique<Door>(WOOD);
        std::unique_ptr<GameInfo> game_info = std::make_unique<GameInfo>();
        std::unique_ptr<BallExpander> ball_expander = std::make_unique<BallExpander>(Vector2D(170, 180), 20, CHAMPIGNON);

        constexpr float BRICK_WIDTH = 20; 
        constexpr float BRICK_HEIGTH = 10; 
        constexpr size_t NB_LIGNES = 8;
        constexpr size_t NB_COLS = 14;
        constexpr float LINE_START_X = 20;
        constexpr float LINE_START_Y = 250;
        constexpr float X_SPACE_BETWEEN_BRICKS = 2;
        constexpr float Y_SPACE_BETWEEN_BRICKS = 2;
        for (size_t line = 0; line < NB_LIGNES; ++line) {
            const size_t line_offset = BRICK_WIDTH/2 * (line % 2);
            for (size_t col = 0; col< NB_COLS; ++col) {
                const float brick_x = LINE_START_X + line_offset + (BRICK_WIDTH + X_SPACE_BETWEEN_BRICKS) * col;
                const float brick_y = LINE_START_Y + (BRICK_HEIGTH + Y_SPACE_BETWEEN_BRICKS) * line;
                const Vector2D brick_pos = Vector2D(brick_x, brick_y);
                std::unique_ptr<Brick> brick = std::make_unique<Brick>(brick_pos,  BRICK_WIDTH, BRICK_HEIGTH);
                map.make_entity(std::move(brick));
            }
        }
      

        // make entity
        

        map.make_entity(std::move(game_info));
        map.make_entity(std::move(launcher));
        map.make_entity(std::move(left_flipper));
        map.make_entity(std::move(right_flipper));
        map.make_entity(std::move(door));
        
        map.make_entity(std::move(bottom_wall));
        map.make_entity(std::move(top_wall));
        map.make_entity(std::move(left_wall));
        map.make_entity(std::move(right_wall));

        map.make_entity(std::move(separation_wall));

        map.make_entity(std::move(left_angle));
        map.make_entity(std::move(right_angle));

        map.make_entity(std::move(bot_left_angle));
        map.make_entity(std::move(bot_right_angle));

        map.make_entity(std::move(ball_expander));


        map.set_name("BrickWall");
    }

    static void load_map_3(Map& map) {
        // shape
        std::unique_ptr<Rectangle> bg_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 400, 700));
        std::unique_ptr<Circle> bumper_2_shape = std::make_unique<Circle>(Vector2D(50, 520), 16);
        std::unique_ptr<Circle> bumper_3_shape = std::make_unique<Circle>(Vector2D(274, 520), 16);
        std::unique_ptr<Circle> bumper_4_shape = std::make_unique<Circle>(Vector2D(105, 270), 22);
        std::unique_ptr<Circle> bumper_5_shape = std::make_unique<Circle>(Vector2D(220, 315), 22);
        std::unique_ptr<Circle> bumper_6_shape = std::make_unique<Circle>(Vector2D(130, 390), 22);

        std::unique_ptr<Circle> bumper_7_shape = std::make_unique<Circle>(Vector2D(180, 260), 16);
        std::unique_ptr<Circle> bumper_8_shape = std::make_unique<Circle>(Vector2D(85, 340), 16);
        std::unique_ptr<Circle> bumper_9_shape = std::make_unique<Circle>(Vector2D(210, 390), 16);

        std::unique_ptr<Polygone> left_triangle_bumper_shape =std::make_unique<Polygone>(Polygone());
        left_triangle_bumper_shape->add_points({Vector2D(35,705), Vector2D(38,650), Vector2D(60,720)});
        std::unique_ptr<Polygone> right_triangle_bumper_shape = std::make_unique<Polygone>(Polygone());
        right_triangle_bumper_shape->add_points({Vector2D(315,705), Vector2D(290,720), Vector2D(312,650)});
        
        std::unique_ptr<Rectangle> bottom_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(300, 790), 100, 10));
        std::unique_ptr<Rectangle> top_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 400, 10));
        std::unique_ptr<Rectangle> left_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 10, 700));
        std::unique_ptr<Rectangle> right_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(390, 100), 10, 700));
        
        std::unique_ptr<Polygone> bot_left_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_left_angle_shape->add_points({Vector2D(55,750), Vector2D(35,735), Vector2D(35,715), Vector2D(60,730)});
        std::unique_ptr<Polygone> bot_right_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_right_angle_shape->add_points({Vector2D(295,750), Vector2D(290,730), Vector2D(315,715), Vector2D(315,735)});
        
        std::unique_ptr<Polygone> bot_left_gutter_shape = std::make_unique<Polygone>(Polygone());
        bot_left_gutter_shape->add_points({Vector2D(70,800), Vector2D(10,800),Vector2D(10,760), Vector2D(25,775),Vector2D(40,780), Vector2D(70,790)});
        std::unique_ptr<Polygone> bot_right_gutter_shape = std::make_unique<Polygone>(Polygone());
        bot_right_gutter_shape->add_points({Vector2D(340,800), Vector2D(280,800), Vector2D(280,790),Vector2D(310,780),Vector2D(325,775),Vector2D(340,760)}); 

        std::unique_ptr<Rectangle> separation_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(340, 250), 10, 650));

        std::unique_ptr<Polygone> left_angle_shape = std::make_unique<Polygone>(Polygone());
        left_angle_shape->add_points({Vector2D(0,100), Vector2D(100,100), Vector2D(0,200)});
        std::unique_ptr<Polygone> right_angle_shape = std::make_unique<Polygone>(Polygone());
        right_angle_shape->add_points({Vector2D(300,100), Vector2D(400,100), Vector2D(400,200)});


        // entity
        std::unique_ptr<Background> bg = std::make_unique<Background>(std::move(bg_shape), BACKGROUNDBLEU);
        std::unique_ptr<Bumper> bumper_4 = std::make_unique<Bumper>(std::move(bumper_4_shape), BUMPER);
        std::unique_ptr<Bumper> bumper_5 = std::make_unique<Bumper>(std::move(bumper_5_shape), BUMPER);
        std::unique_ptr<Bumper> bumper_6 = std::make_unique<Bumper>(std::move(bumper_6_shape), BUMPER);
        std::unique_ptr<Multiplicateur> bumper_2 = std::make_unique<Multiplicateur>(std::move(bumper_2_shape), MULTIPLICATEUR);
        std::unique_ptr<Multiplicateur> bumper_3 = std::make_unique<Multiplicateur>(std::move(bumper_3_shape), MULTIPLICATEUR);
        std::unique_ptr<Multiplicateur> bumper_7 = std::make_unique<Multiplicateur>(std::move(bumper_7_shape), MULTIPLICATEUR);
        std::unique_ptr<Multiplicateur> bumper_8 = std::make_unique<Multiplicateur>(std::move(bumper_8_shape), MULTIPLICATEUR);
        std::unique_ptr<Multiplicateur> bumper_9 = std::make_unique<Multiplicateur>(std::move(bumper_9_shape), MULTIPLICATEUR);

        std::unique_ptr<Multiplicateur> right_triangle_bumper = std::make_unique<Multiplicateur>(std::move(right_triangle_bumper_shape), RIGHTTRIANGLEBUMPER);
        std::unique_ptr<Multiplicateur> left_triangle_bumper = std::make_unique<Multiplicateur>(std::move(left_triangle_bumper_shape), LEFTTRIANGLEBUMPER);

        std::unique_ptr<Wall> bottom_wall = std::make_unique<Wall>(std::move(bottom_wall_shape), BACKGROUNDNOIR);
        std::unique_ptr<Wall> top_wall = std::make_unique<Wall>(std::move(top_wall_shape), BACKGROUNDNOIR);
        std::unique_ptr<Wall> left_wall = std::make_unique<Wall>(std::move(left_wall_shape), BACKGROUNDNOIR);
        std::unique_ptr<Wall> right_wall = std::make_unique<Wall>(std::move(right_wall_shape), BACKGROUNDNOIR);

        std::unique_ptr<Wall> separation_wall = std::make_unique<Wall>(std::move(separation_wall_shape), BACKGROUNDNOIR);

        std::unique_ptr<Wall> left_angle = std::make_unique<Wall>(std::move(left_angle_shape), BACKGROUNDNOIR);
        std::unique_ptr<Wall> right_angle = std::make_unique<Wall>(std::move(right_angle_shape), BACKGROUNDNOIR);

        std::unique_ptr<Wall> bot_left_angle = std::make_unique<Wall>(std::move(bot_left_angle_shape), BACKGROUNDNOIR);
        std::unique_ptr<Wall> bot_right_angle = std::make_unique<Wall>(std::move(bot_right_angle_shape), BACKGROUNDNOIR);
        std::unique_ptr<Wall> bot_left_gutter = std::make_unique<Wall>(std::move(bot_left_gutter_shape), BACKGROUNDNOIR);
        std::unique_ptr<Wall> bot_right_gutter = std::make_unique<Wall>(std::move(bot_right_gutter_shape), BACKGROUNDNOIR);

        std::unique_ptr<Launcher> launcher = std::make_unique<Launcher>("");
        std::unique_ptr<Flipper> left_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::LEFT);
        std::unique_ptr<Flipper> right_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::RIGHT);
        std::unique_ptr<Door> door = std::make_unique<Door>(BACKGROUNDNOIR);
        std::unique_ptr<GameInfo> game_info = std::make_unique<GameInfo>();
    

        // make entity
        map.make_entity(std::move(bg));
        map.make_entity(std::move(game_info));
        map.make_entity(std::move(launcher));
        map.make_entity(std::move(left_flipper));
        map.make_entity(std::move(right_flipper));
        map.make_entity(std::move(door));
        
        map.make_entity(std::move(bumper_2));
        map.make_entity(std::move(bumper_3));
        map.make_entity(std::move(bumper_4));
        map.make_entity(std::move(bumper_5));
        map.make_entity(std::move(bumper_6));
        map.make_entity(std::move(bumper_7));
        map.make_entity(std::move(bumper_8));
        map.make_entity(std::move(bumper_9));
        map.make_entity(std::move(right_triangle_bumper));
        map.make_entity(std::move(left_triangle_bumper));

        map.make_entity(std::move(bottom_wall));
        map.make_entity(std::move(top_wall));
        map.make_entity(std::move(left_wall));
        map.make_entity(std::move(right_wall));

        map.make_entity(std::move(separation_wall));

        map.make_entity(std::move(left_angle));
        map.make_entity(std::move(right_angle));
        map.make_entity(std::move(bot_left_gutter));
        map.make_entity(std::move(bot_right_gutter));

        map.make_entity(std::move(bot_left_angle));
        map.make_entity(std::move(bot_right_angle));

        map.set_name("Classique");
    }

    static void map_historique(Map& map) {
        // shape
        std::unique_ptr<Circle> bumper_4_shape = std::make_unique<Circle>(Vector2D(40, 500), 16);
        std::unique_ptr<Circle> bumper_5_shape = std::make_unique<Circle>(Vector2D(150, 500), 16);
        std::unique_ptr<Circle> bumper_6_shape = std::make_unique<Circle>(Vector2D(260, 500), 16);

        std::unique_ptr<Circle> bumper_7_shape = std::make_unique<Circle>(Vector2D(80, 400), 16);
        std::unique_ptr<Circle> bumper_8_shape = std::make_unique<Circle>(Vector2D(215, 400), 16);
        
        std::unique_ptr<Rectangle> bottom_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(300, 790), 100, 10));
        std::unique_ptr<Rectangle> top_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 400, 10));
        std::unique_ptr<Rectangle> left_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(0, 100), 10, 700));
        std::unique_ptr<Rectangle> right_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(390, 100), 10, 700));
        
        std::unique_ptr<Polygone> bot_left_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_left_angle_shape->add_points({Vector2D(50,800), Vector2D(10,800), Vector2D(10,690), Vector2D(50,730)});
        std::unique_ptr<Polygone> bot_right_angle_shape = std::make_unique<Polygone>(Polygone());
        bot_right_angle_shape->add_points({Vector2D(340,800), Vector2D(300,800), Vector2D(300,730), Vector2D(340,690)});

        std::unique_ptr<Rectangle> separation_wall_shape = std::make_unique<Rectangle>(Rectangle(Vector2D(340, 250), 10, 650));

        std::unique_ptr<Polygone> left_angle_shape = std::make_unique<Polygone>(Polygone());
        left_angle_shape->add_points({Vector2D(0,100), Vector2D(100,100), Vector2D(0,200)});
        std::unique_ptr<Polygone> right_angle_shape = std::make_unique<Polygone>(Polygone());
        right_angle_shape->add_points({Vector2D(300,100), Vector2D(400,100), Vector2D(400,200)});


        // entity
        std::unique_ptr<Bumper> bumper_4 = std::make_unique<Bumper>(std::move(bumper_4_shape), BUMPER);
        std::unique_ptr<Bumper> bumper_5 = std::make_unique<Bumper>(std::move(bumper_5_shape), BUMPER);
        std::unique_ptr<Bumper> bumper_6 = std::make_unique<Bumper>(std::move(bumper_6_shape), BUMPER);
        std::unique_ptr<Multiplicateur> bumper_7 = std::make_unique<Multiplicateur>(std::move(bumper_7_shape), MULTIPLICATEUR);
        std::unique_ptr<Multiplicateur> bumper_8 = std::make_unique<Multiplicateur>(std::move(bumper_8_shape), MULTIPLICATEUR);

        std::unique_ptr<Wall> bottom_wall = std::make_unique<Wall>(std::move(bottom_wall_shape), TEST);
        std::unique_ptr<Wall> top_wall = std::make_unique<Wall>(std::move(top_wall_shape), TEST);
        std::unique_ptr<Wall> left_wall = std::make_unique<Wall>(std::move(left_wall_shape), TEST);
        std::unique_ptr<Wall> right_wall = std::make_unique<Wall>(std::move(right_wall_shape), TEST);

        std::unique_ptr<Wall> separation_wall = std::make_unique<Wall>(std::move(separation_wall_shape), TEST);

        std::unique_ptr<Wall> left_angle = std::make_unique<Wall>(std::move(left_angle_shape), TEST);
        std::unique_ptr<Wall> right_angle = std::make_unique<Wall>(std::move(right_angle_shape), TEST);

        std::unique_ptr<Wall> bot_left_angle = std::make_unique<Wall>(std::move(bot_left_angle_shape), TEST);
        std::unique_ptr<Wall> bot_right_angle = std::make_unique<Wall>(std::move(bot_right_angle_shape), TEST);

        std::unique_ptr<Launcher> launcher = std::make_unique<Launcher>("");
        std::unique_ptr<Flipper> left_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::LEFT);
        std::unique_ptr<Flipper> right_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::RIGHT);
        std::unique_ptr<Door> door = std::make_unique<Door>(TEST);
        std::unique_ptr<GameInfo> game_info = std::make_unique<GameInfo>();

        // make entity
        map.make_entity(std::move(game_info));
        map.make_entity(std::move(launcher));
        map.make_entity(std::move(left_flipper));
        map.make_entity(std::move(right_flipper));
        map.make_entity(std::move(door));
        
        map.make_entity(std::move(bumper_4));
        map.make_entity(std::move(bumper_5));
        map.make_entity(std::move(bumper_6));
        map.make_entity(std::move(bumper_7));
        map.make_entity(std::move(bumper_8));

        map.make_entity(std::move(bottom_wall));
        map.make_entity(std::move(top_wall));
        map.make_entity(std::move(left_wall));
        map.make_entity(std::move(right_wall));

        map.make_entity(std::move(separation_wall));

        map.make_entity(std::move(left_angle));
        map.make_entity(std::move(right_angle));

        map.make_entity(std::move(bot_left_angle));
        map.make_entity(std::move(bot_right_angle));

        map.set_name("Map_historique");
    }

    static void test_ball_clipping_in_bumper(Map& map) {
        std::unique_ptr<Circle> bumper_shape = std::make_unique<Circle>(Vector2D(150, 350), 50);
        std::unique_ptr<Bumper> bumper = std::make_unique<Bumper>(std::move(bumper_shape), "");
        map.make_entity(std::move(bumper));

        std::unique_ptr<Ball> ball = std::make_unique<Ball>(Vector2D(200, 370), 8, "");
        ball->set_acceleration(Vector2D::zero());
        ball->set_velocity(Vector2D(0, 10));
        map.make_entity(std::move(ball));

        map.set_name("Test");
    }

    static void test_flipper(Map& map) {
        std::unique_ptr<Circle> bumper_shape = std::make_unique<Circle>(Vector2D(150, 350), 50);
        std::unique_ptr<Bumper> bumper = std::make_unique<Bumper>(std::move(bumper_shape), "");
        map.make_entity(std::move(bumper));

        std::unique_ptr<Ball> ball = std::make_unique<Ball>(Vector2D(200, 370), 8, "");
        ball->set_acceleration(Vector2D::zero());
        ball->set_velocity(Vector2D(0, 100));
        map.make_entity(std::move(ball));

        map.set_name("Test");
    }
    
private:

};

#endif /* !LOADER_H_ */
