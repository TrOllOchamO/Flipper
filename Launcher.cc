#include "Launcher.h"
#include "Polygone.h"
#include "Vector2D.h"
#include "Ball.h"
#include "Game.h"
#include <memory>
#include <SFML/Graphics/Color.hpp>


Launcher::Launcher(const std::string& texturePath) : shape(Polygone()) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);

    props.should_react_with_other = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 0.5;

    shape.add_points( {Vector2D(360, 750), Vector2D(380, 750), Vector2D(380, 790), Vector2D(360, 790)} );
};

// TODO BVERIFIER NB VIE
void Launcher::use_inputs(const Inputs &player_inputs) {
    if(player_inputs.space_launcher && ball == nullptr){
        add_ball();
    }
    if(player_inputs.up_launcher && can_move_up){
        can_move_up = false;
        update_value(1);
    }
    if(player_inputs.down_launcher && can_move_down){
        can_move_down = false;
        update_value(-1);
    }
    if(player_inputs.enter_launcher && can_launch){
        can_launch = false;
        launch();
    }
    if(!player_inputs.up_launcher){
        can_move_up = true;
    }
    if(!player_inputs.down_launcher){
        can_move_down = true;
    }
    if(!player_inputs.enter_launcher){
        can_launch = true;
    }
}

void Launcher::update_value(int value) {
    if (force+value*3>30 || force+value*3<0) return;
    if(ball_ok() && value < 0) ball->set_posiion(ball->get_position() - Vector2D(0, 4));
    force += value*3;
    shape.clear();
    shape.add_points( {Vector2D(360, 750+force), Vector2D(380, 750+force), Vector2D(380, 790), Vector2D(360, 790)} );
}

void Launcher::launch() {
    if(ball_ok()) {
        ball->set_posiion(Vector2D(362, 732));
        ball->set_velocity(Vector2D(0, -force*50));
    }
    force = 0;
    shape.clear();
    shape.add_points( {Vector2D(360, 750), Vector2D(380, 750), Vector2D(380, 790), Vector2D(360, 790)} );
}

void Launcher::render(sf::RenderWindow &window, sf::Color color) const {
    shape.render(window, color);
}

void Launcher::render(sf::RenderWindow &window) const {
    shape.render(window, texture);
}

void Launcher::add_ball() {
    std::unique_ptr<Ball> new_ball = std::make_unique<Ball>(Vector2D(362, 732), 8, "./resources/ballTest.png");
    this->ball = new_ball.get();
    game->make_entity(std::move(new_ball));
}

bool Launcher::ball_ok(){
    return ball != nullptr && ball->get_position().x > 350;
}