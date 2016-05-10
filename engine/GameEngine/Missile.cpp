//
//  Missile.cpp
//  GameEngine
//
//  Created by Ashley Isles on 4/25/16.
//  Copyright © 2016 David Lively. All rights reserved.
//


#include "Game.h"
#include "Camera.h"
#include "Missile.hpp"
#include "Common.h"
#include "Mesh.h"

#include <cmath>

bool Missile::OnInitialize()
{
    auto& mesh = Create<Mesh>("missile-mesh");
    
    vector<float> vertices =
    {
        0, 0, 0,
        0, 0.06f, 0,
        0, 0.06f, 0
    };
    
    previousTranslation = Transform.Translation;
    
    vector<GLushort> indices = {0,1,2};
    
    mesh.Initialize(vertices, indices);
    
    m_mesh = &mesh;
    
    auto& material = Create<class Material>("missile-material");
    m_material = &material;
    
    mesh.Material = &material;
    material.FillType = PolygonMode::Line;
    
//    Transform.Translation.Y = 0.12f;
    
//    Disable();
    previousTranslation = Transform.Translation;
    
    return material.Build("Shaders/primitive");
}

void Missile::OnUpdate(const GameTime& time)
{
//    cout << "X: " << Transform.Translation.X << "\nY: " << Transform.Translation.Y << endl;
    
    if(enabled)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    previousTranslation = Transform.Translation;
    
    
}


void Missile::OnRender(const GameTime& time)
{
    auto& cam = Game::Camera;
    
    m_material->Bind();
    
    m_material->SetUniform("World", Transform.GetMatrix());
    m_material->SetUniform("View",cam.GetViewMatrix());
    m_material->SetUniform("Projection",cam.GetProjectionMatrix());
        
}