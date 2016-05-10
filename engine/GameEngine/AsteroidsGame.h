//
//  SimpleGame.hpp
//  GameEngine
//
//  Created by David Lively on 2/3/16.
//  Copyright © 2016 David Lively. All rights reserved.
//

#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include "Game.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Missile.hpp"

class AsteroidsGame : public Game
{
public:
	AsteroidsGame() : ShaderFolder("Shaders/")
    {

    }

    
    bool OnCreateScene() override;
    

    /// location of shaders in the file system.
	std::string ShaderFolder;
    
    Ship& CreateShip();
//    vector<Asteroid>& CreateAsteroid();
    Asteroid& CreateAsteroid();
    Missile& CreateMissile();
    void Wrapping();
    void AsteroidWrapping();
    void OnUpdate(const GameTime& time);

    void FireMissile();
    void ResetMissile();
    
    bool checkBounds(float, float);
    bool checkCollisions(Asteroid& asteroid);

    
private:
    Ship* ship;
    Asteroid* asteroid;
    vector<Asteroid*> asteroids;
    Missile* missile;
    bool enabled;
};


#endif /* SimpleGame_hpp */
