//
//  Ship.cpp
//  GameEngine
//
//  Created by David Lively on 2/22/16.
//  Copyright © 2016 David Lively. All rights reserved.
//

#include "Common.h"
#include "Ship.h"
#include "Mesh.h"
#include "Game.h"
#include "Camera.h"

#include <vector>
#include <cmath>

using namespace std;

bool Ship::OnInitialize()
{
    auto& mesh = Create<Mesh>("ship-mesh");
    
    
    /// narrow triangle pointed along the positive Y axis
    vector<float> vertices =
    {
        0, 0.5f, 0
        ,
        1/3.f, -0.5f, 0
        ,
        -1/3.f, -0.5f, 0
    };
    
    previousTranslation = Transform.Translation;
    
    vector<GLushort> indices = {0,1,2};
    
    Transform.Scale = 0.3;
    
    mesh.Initialize(vertices, indices);
    
    m_mesh = &mesh;
    
    

    auto& material = Create<class Material>("ship-material");
    m_material = &material;
    
    mesh.Material = &material;
    material.FillType = PolygonMode::Line;
    
    
    return material.Build("Shaders/primitive");
}

void Ship::OnUpdate(const GameTime& time)
{
    
    Game new_game = Game::Instance();
    GLFWwindow* window = new_game.Window();
    float drag = 0.03f;
    
    velocity = Transform.Translation - previousTranslation;
    previousTranslation = Transform.Translation;
    
    if (glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window,true);
    }
    
    if (glfwGetKey(window,GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        Transform.Rotation.Z -= 0.1f;
    }
    
    if (glfwGetKey(window,GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
       Transform.Rotation.Z += 0.1f;
    }

    if (glfwGetKey(window,GLFW_KEY_UP) == GLFW_PRESS)
    {
        velocity += Transform.Up() * 0.05f;
        
        Transform.Translation += Transform.Up() + velocity;
    }

    Transform.Translation += velocity * (1.f - drag);
    
}




void Ship::OnRender(const GameTime& time)
{
    auto& cam = Game::Camera;
    
    m_material->Bind();

    m_material->SetUniform("World", Transform.GetMatrix());
    m_material->SetUniform("View",cam.GetViewMatrix());
    m_material->SetUniform("Projection",cam.GetProjectionMatrix());
    
    
    
    

}


