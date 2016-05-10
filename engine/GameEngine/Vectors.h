//
//  Vectors.hpp
//  GameEngine
//
//  Created by David Lively on 2/10/16.
//  Copyright © 2016 David Lively. All rights reserved.
//

#ifndef VECTORS_H
#define VECTORS_H


struct Vector2
{
    float X;
    float Y;
    
    Vector2() : X(0), Y(0)
    {
    }
    
    Vector2(float x, float y) : X(x), Y(y)
    {
        
    }
    
};

struct Vector3 : public Vector2
{
    float Z;
    
    Vector3() : Vector2(), Z(0)
    {
        
    }
    
    Vector3(float x, float y, float z) : Vector2(x,y), Z(z)
    {
        
    }
    
    template<typename T>
    inline Vector3 operator* (const T& multiplier) const
    {
        return Vector3(X * multiplier, Y * multiplier, Z * multiplier);
    }
    
    template<typename T>
    inline Vector3& operator*=(const T& rval)
    {
        X *= rval;
        Y *= rval;
        Z *= rval;
        
        return *this;
    }
    
    template<typename T>
    inline Vector3& operator+=(const T& rval)
    {
        X += rval.X;
        Y += rval.Y;
        Z += rval.Z;
        
        return *this;
    }
    
    inline Vector3& operator+=(const float rval)
    {
        X += rval;
        Y += rval;
        Z += rval;
        
        return *this;
    }
    
    inline Vector3 operator*(Vector3 a)
    {
        Vector3 v;
        v.X = a.X * X;
        v.Y = a.Y * Y;
        v.Z = a.Z * Z;
        
        return v;
    }
    
    inline Vector3 operator-(const float rval)
    {
        Vector3 v;
        v.X = X - rval;
        v.Y = Y - rval;
        v.Z = Z - rval;
        
        return v;
    }
    
    inline Vector3 operator+(const float rval)
    {
        Vector3 v;
        v.X = X + rval;
        v.Y = Y + rval;
        v.Z = Z + rval;
        
        return v;
    }
    
    template<typename T>
    inline Vector3& operator-=(const T& rval)
    {
        X -= rval.X;
        Y -= rval.Y;
        Z -= rval.Z;
        
        return *this;
    }
    
    template<typename T>
    inline Vector3& operator=(const T& rval)
    {
        X = rval;
        Y = rval;
        Z = rval;
      
        return *this;
    }
    
    
    template<typename T>
    inline Vector3 operator-(const T& rval)
    {
        Vector3 v;
        v.X = X - rval.X;
        v.Y = Y - rval.Y;
        v.Z = Z - rval.Z;
        
        return v;
        
    }
    
    template<typename T>
    inline Vector3 operator+(const T& rval)
    {
        Vector3 v;
        v.X + rval.X;
        v.Y + rval.Y;
        v.Z + rval.Z;
        
        return v;
        
    }
    
};

struct Vector4 : public Vector3
{
    float W;
    
    Vector4() : Vector3(), W(0)
    {
        
    }
    
    Vector4(float x, float y, float z, float w) : Vector3(x,y,z)
    {
        
    }
};


#endif /* Vectors_hpp */
