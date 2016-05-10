//
//  Asteroid.cpp
//  GameEngine
//
//  Created by David Lively on 2/22/16.
//  Copyright © 2016 David Lively. All rights reserved.

#include "Asteroid.h"
#include "Common.h"
#include "Mesh.h"
#include "Game.h"
#include "Camera.h"
#include "GeometryProvider.h"

#include <vector>
#include <cmath>
#include <time.h>

using namespace std;

bool Asteroid::OnInitialize()
{
    auto& mesh = Create<Mesh>("asteroid-mesh");
    
    
    /// narrow triangle pointed along the positive Y axis
    vector<Vector3> vertices = {};
    
    vector<GLushort> indices = {};
    
    GeometryProvider::Icosahedron(vertices, indices);
    
    Transform.Scale = .3;
    
    
    mesh.Initialize(vertices, indices);

    m_mesh = &mesh;
    
//    srand(time(NULL));
    speed_y = rand() % 100 * 0.0005;
    speed_x = rand() % 100 * 0.0005;
    
    
//    float x_pos = (rand() % 20 + -10);
//    float y_pos = (rand() % 15 + -5);
//    
//    Transform.Translation.X = x_pos;
//    Transform.Translation.Y = y_pos;

    
    auto& material = Create<class Material>("asteroid-material");
    m_material = &material;
    
    mesh.Material = &material;
    material.FillType = PolygonMode::Line;
    
    Transform.Translation = Vector3(speed_x, speed_y, 0);
//    Transform.Translation += Vector3(speed_x, speed_y, 0);
    
    return material.Build("Shaders/primitive");
}

void Asteroid::OnUpdate(const GameTime& time)
{
//    Transform.Translation += Vector3(speed_x, speed_y, 0);
    
    velocity = Transform.Translation - previousTranslation;
    
    previousTranslation = Transform.Translation;

    Transform.Rotation.X += 0.01f;
    Transform.Rotation.Y += 0.01f;
    Transform.Rotation.Z += 0.01f;
//
    Transform.Translation += velocity;
}




void Asteroid::OnRender(const GameTime& time)
{
    auto& cam = Game::Camera;
    
    m_material->Bind();
    
    m_material->SetUniform("World", Transform.GetMatrix());
    m_material->SetUniform("View",cam.GetViewMatrix());
    m_material->SetUniform("Projection",cam.GetProjectionMatrix());
    
}
