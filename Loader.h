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

#ifndef LOADER_H_
#define LOADER_H_

class Loader {
public:
    static void load_map_1(Map& map) {
        // shape
        std::unique_ptr<Circle> bumper_1_shape = std::make_unique<Circle>(Vector2D(40, 300), 16);
        std::unique_ptr<Circle> bumper_2_shape = std::make_unique<Circle>(Vector2D(150, 300), 16);
        std::unique_ptr<Circle> bumper_3_shape = std::make_unique<Circle>(Vector2D(260, 300), 16);

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
        std::unique_ptr<Bumper> bumper_1 = std::make_unique<Bumper>(std::move(bumper_1_shape), "resources/star.png");
        std::unique_ptr<Bumper> bumper_2 = std::make_unique<Bumper>(std::move(bumper_2_shape), "resources/star.png");
        std::unique_ptr<Bumper> bumper_3 = std::make_unique<Bumper>(std::move(bumper_3_shape), "resources/star.png");
        std::unique_ptr<Bumper> bumper_4 = std::make_unique<Bumper>(std::move(bumper_4_shape), "resources/star.png");
        std::unique_ptr<Bumper> bumper_5 = std::make_unique<Bumper>(std::move(bumper_5_shape), "resources/star.png");
        std::unique_ptr<Bumper> bumper_6 = std::make_unique<Bumper>(std::move(bumper_6_shape), "resources/star.png");
        std::unique_ptr<Multiplicateur> bumper_7 = std::make_unique<Multiplicateur>(std::move(bumper_7_shape), "resources/keur.png");
        std::unique_ptr<Multiplicateur> bumper_8 = std::make_unique<Multiplicateur>(std::move(bumper_8_shape), "resources/keur.png");

        std::unique_ptr<Wall> bottom_wall = std::make_unique<Wall>(std::move(bottom_wall_shape), "resources/Test.jpg");
        std::unique_ptr<Wall> top_wall = std::make_unique<Wall>(std::move(top_wall_shape), "resources/Test.jpg");
        std::unique_ptr<Wall> left_wall = std::make_unique<Wall>(std::move(left_wall_shape), "resources/Test.jpg");
        std::unique_ptr<Wall> right_wall = std::make_unique<Wall>(std::move(right_wall_shape), "resources/Test.jpg");

        std::unique_ptr<Wall> separation_wall = std::make_unique<Wall>(std::move(separation_wall_shape), "resources/Test.jpg");

        std::unique_ptr<Wall> left_angle = std::make_unique<Wall>(std::move(left_angle_shape), "resources/Test.jpg");
        std::unique_ptr<Wall> right_angle = std::make_unique<Wall>(std::move(right_angle_shape), "resources/Test.jpg");

        std::unique_ptr<Wall> bot_left_angle = std::make_unique<Wall>(std::move(bot_left_angle_shape), "resources/Test.jpg");
        std::unique_ptr<Wall> bot_right_angle = std::make_unique<Wall>(std::move(bot_right_angle_shape), "resources/Test.jpg");

        std::unique_ptr<Launcher> launcher = std::make_unique<Launcher>("");
        std::unique_ptr<Flipper> left_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::LEFT);
        std::unique_ptr<Flipper> right_flipper = std::make_unique<Flipper>("", FLIPPER_ORIENTATION::RIGHT);
        std::unique_ptr<GameInfo> game_info = std::make_unique<GameInfo>();

        // make entity
        map.make_entity(std::move(game_info));
        map.make_entity(std::move(launcher));
        map.make_entity(std::move(left_flipper));
        map.make_entity(std::move(right_flipper));
        
        map.make_entity(std::move(bumper_1));
        map.make_entity(std::move(bumper_2));
        map.make_entity(std::move(bumper_3));
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

        map.set_name("Niveau_1");
    }

    static void test_ball_clipping_in_bumper(Map& map) {
        std::unique_ptr<Circle> bumper_shape = std::make_unique<Circle>(Vector2D(150, 350), 50);
        std::unique_ptr<Bumper> bumper = std::make_unique<Bumper>(std::move(bumper_shape), "");
        map.make_entity(std::move(bumper));

        std::unique_ptr<Ball> ball = std::make_unique<Ball>(Vector2D(200, 370), 8, "");
        ball->set_acceleration(Vector2D::zero());
        ball->set_velocity(Vector2D(0, 100));
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
