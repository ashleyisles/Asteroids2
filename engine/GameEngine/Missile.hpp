//
//  Missile.hpp
//  GameEngine
//
//  Created by Ashley Isles on 4/25/16.
//  Copyright © 2016 David Lively. All rights reserved.
//

#ifndef Missile_hpp
#define Missile_hpp

//#include "Ship.h"
#include "Common.h"
#include "WorldEntity.h"
#include "Mesh.h"


class Missile : public WorldEntity
{
public:
    Missile()
    {
        
    }
    
    bool OnInitialize() override;
    void OnUpdate(const GameTime& time) override;
    void OnRender(const GameTime& time) override;
    
//    bool enabled;
    Vector3 previousTranslation;
    Vector3 velocity;
private:
    Mesh* m_mesh;
    Material* m_material;

    
//    Ship* ship;

};


#endif /* Missile_hpp */
