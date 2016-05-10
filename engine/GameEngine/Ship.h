//
//  Ship.hpp
//  GameEngine
//
//  Created by David Lively on 2/22/16.
//  Copyright © 2016 David Lively. All rights reserved.
//

#ifndef SHIP_H
#define SHIP_H

#include "Common.h"
#include "WorldEntity.h"
#include "Mesh.h"
#include "Missile.hpp"

class Ship : public WorldEntity
{
public:
    
    Ship()
    {
        
    }
    
    bool OnInitialize() override;
    
    void OnUpdate(const GameTime& time) override;
    void OnRender(const GameTime& time) override;
    Vector3 velocity = Vector3(0,0,0);
    
    Vector3 previousTranslation;
    Missile* missile;
private:
    Mesh* m_mesh;
    Material* m_material;
    
    
};


#endif /* Ship_hpp */
