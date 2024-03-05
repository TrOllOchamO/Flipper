#include "Randomizer.h"
#include "Physics.h"
#include "Ball.h"
#include "Game.h"

#include <SFML/Graphics/Color.hpp>
#include <iostream>

Randomizer::Randomizer(std::unique_ptr<Shape> shape, const std::string& texturePath) : shape(std::move(shape)) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file: " << texturePath << std::endl;
    }
    texture.setRepeated(true);
    
    if (!bufferS.loadFromFile("../resources/poker.wav")) {
        std::cerr << "Error loading sound from file: ../resources/poker.wav" << std::endl;
    }

    props.should_be_affected_by_others = false;
    props.should_affect_others = false;
    props.mass = 10000000000;
    props.velocity = Vector2D::zero();
    props.acceleration = Vector2D::zero();
    props.bounciness = 0;
}

void Randomizer::update([[maybe_unused]] const Inputs &player_inputs, [[maybe_unused]] float dt) {
    auto ball = game->get_ball_handle();
    if(ball == nullptr) return;

    if(Collision::are_colliding(ball->get_shape(), shape.get())){
        keep = true;
        if(c==0) c=1;
    } else {
        c=0;
    }

    if(keep && c>0){
        if(c==1000) {
            new_velocity_for_ball();
            c++;
        } 
        if(c>1000) return;
        c++;
        ball->set_posiion(shape->get_center() - Vector2D(8,8));
        ball->set_velocity(Vector2D(0,0));
    }
}

void Randomizer::new_velocity_for_ball(){
    double new_direction_x = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
    double new_direction_y = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0;
    Vector2D n(new_direction_x, new_direction_y);
    game->get_ball_handle()->set_velocity(n.normalize() * 500);
    play_audioS();    
}


void Randomizer::render(sf::RenderWindow &window, sf::Color color) const {
    this->shape->render(window, color);
}

void Randomizer::render(sf::RenderWindow &window) const {
    this->shape->render(window, texture);
}

void Randomizer::play_audioS(){
    soundS.setBuffer(bufferS);
    if(bufferS.getDuration().asSeconds()>0){
      soundS.play();
    }
};