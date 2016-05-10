//
//  SimpleGame.cpp
//  GameEngine
//
//  Created by David Lively on 2/3/16.
//  Copyright © 2016 David Lively. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

#include "AsteroidsGame.h"
#include "Mesh.h"
#include "Material.h"
#include "Files.h"

#include <cmath>


bool AsteroidsGame::OnCreateScene()
{
//    missile->Enable();
    CreateShip();
    for(int i = 0; i < 4; i++)
    {
        asteroid = &CreateAsteroid();
        asteroids.push_back(asteroid);
        
        cout << "VEC SIZE: " << asteroids.size() << endl;
        srand(time(NULL));
    }
    
    CreateMissile();
    missile->Disable();
    
    
    auto& cam = Game::Camera;
    
    cam.Transform.Translation.Z = 5;

    return true;
    
}

void AsteroidsGame::FireMissile()
{
    missile->previousTranslation = ship->Transform.Translation;
//    missile->previousTranslation = ship->Transform.Translation;
    missile->Transform.Rotation = ship->Transform.Rotation;
    missile->Transform.Translation = ship->Transform.Translation;
    
    cout << "MISSILE\nX: " << missile->Transform.Translation.X << " Y: " << missile->Transform.Translation.Y << endl;
    
    cout << "SHIP\nX: " << ship->Transform.Translation.X << " Y: " << ship->Transform.Translation.Y << endl;
    
    
    
    
//    missile->Transform.Translation += ship->Transform.Up() * 3;
//
//    if(!checkBounds(missile->Transform.Translation.X, missile->Transform.Translation.Y))
//    {

//        missile->Disable();
//    }
//    else
//    {
// 
//    }
    
//    missile->Transform.Translation = ship->previousTranslation;
}


Ship& AsteroidsGame::CreateShip()
{
    ship = &Create<Ship>("ship");
    
    return *ship;
}


bool AsteroidsGame::checkCollisions(Asteroid& asteroid)
{
    float ship_width = 1.f;
    float ship_height = 1.f;
    
    float roid_width;
    float roid_height;
    
    float asteroid_x = asteroid.Transform.Translation.X;
    float asteroid_y = asteroid.Transform.Translation.Y;
    
    if ((abs(0.0 - asteroid_x) < (ship_width + roid_width) / 2) && (abs(0.0 - asteroid_y) < (ship_height + roid_height) / 2))
    {
        return true;
    }
    else
        return false;
}


Asteroid& AsteroidsGame::CreateAsteroid()
{

    asteroid = &Create<Asteroid>("asteroid");
    asteroid->Initialize();

    return *asteroid;
}

Missile& AsteroidsGame::CreateMissile()
{
    missile = &Create<Missile>("missile");
    
    return *missile;
    
}

bool AsteroidsGame::checkBounds(float x, float y)
{
    auto& cam = Game::Camera;
    
    Matrix projMatrix = cam.GetProjectionMatrix();
    Matrix viewMatrix = cam.GetViewMatrix();
    
    if((abs(x*ship->Transform.Scale.X) >= abs(viewMatrix.m32/projMatrix.m00)) && (abs(y*ship->Transform.Scale.Y) >= abs(viewMatrix.m32/projMatrix.m11)))
    {
        return false;
    }
    else
        return true;
}


void AsteroidsGame::Wrapping()
{
    auto& cam = Game::Camera;
    
    Matrix projMatrix = cam.GetProjectionMatrix();
    Matrix viewMatrix = cam.GetViewMatrix();
    Vector3& shipVec = ship->Transform.Translation;
    
    if(abs(shipVec.X*ship->Transform.Scale.X) >= abs(viewMatrix.m32/projMatrix.m00))
    {
        shipVec.X *= -0.98;
        ship->previousTranslation.X = shipVec.X - ship->velocity.X;

    }
    
    if(abs(shipVec.Y*ship->Transform.Scale.Y) >= abs(viewMatrix.m32/projMatrix.m11))
    {
        
        shipVec.Y *= -0.98;
        ship->previousTranslation.Y = shipVec.Y - ship->velocity.Y;
    }
}


void AsteroidsGame::AsteroidWrapping()
{
    auto& cam = Game::Camera;
    
    Matrix projMatrix = cam.GetProjectionMatrix();
    Matrix viewMatrix = cam.GetViewMatrix();
    
    for(int i = 0; i < asteroids.size(); i++)
    {
        
//        cout << "X[ " << i << "]: " << asteroids[i]->Transform.Translation.X << " Y[ " << i << "]: " << asteroids[i]->Transform.Translation.Y << endl;

        if(abs(asteroids[i]->Transform.Translation.X*asteroids[i]->Transform.Scale.X) >= abs(viewMatrix.m32/projMatrix.m00))
        {
            asteroids[i]->Transform.Translation.X *= -0.98;
            asteroids[i]->previousTranslation.X = asteroids[i]->Transform.Translation.X - asteroids[i]->velocity.X;
        }
        
        if(abs(asteroids[i]->Transform.Translation.Y*asteroids[i]->Transform.Scale.Y) >= abs(viewMatrix.m32/projMatrix.m11))
        {
            asteroids[i]->Transform.Translation.Y *= -0.98;
            asteroids[i]->previousTranslation.Y = asteroids[i]->Transform.Translation.Y - asteroids[i]->velocity.Y;
        }
    }

}

void AsteroidsGame::OnUpdate(const GameTime& time)
{
    
    Game new_game = Game::Instance();
    GLFWwindow* window = new_game.Window();
    
//    Vector3& shipTranslation = ship->Transform.Translation;
    
//    missile->Disable();
    if(glfwGetKey(window,GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        
        FireMissile();
    }
    missile->Enable();
    
    
    Wrapping();
    AsteroidWrapping();

}



