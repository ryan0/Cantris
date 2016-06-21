//
// Created by Ryan on 5/2/2016.
//

#ifndef RAINSFORD_DEBUGDRAW_HPP
#define RAINSFORD_DEBUGDRAW_HPP

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class DebugDraw : public b2Draw {
public:
    void setRenderTarget(sf::RenderTarget& renderTarget);
    void setAsTargetOf(b2World& physicsSpace);
    void drawDebug();

    /// Convert Box2D's OpenGL style color definition[0-1] to SFML's color definition[0-255], with optional alpha byte[Default - opaque]
    static sf::Color GLColorToSFML(const b2Color &color, sf::Uint8 alpha = 255)
    {
        return sf::Color(static_cast<sf::Uint8>(color.r * 255), static_cast<sf::Uint8>(color.g * 255), static_cast<sf::Uint8>(color.b * 255), alpha);
    }

    /// Convert Box2D's vector to SFML vector [Default - scales the vector up by SCALE constants amount]
    static sf::Vector2f B2VecToSFVec(const b2Vec2 &vector);

    /// Draw a closed polygon provided in CCW order.
    virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;

    /// Draw a solid closed polygon provided in CCW order.
    virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;

    /// Draw a circle.
    virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) override;

    /// Draw a solid circle.
    virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) override;

    /// Draw a line segment.
    virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;

    /// Draw a transform. Choose your own length scale.
    /// @param xf a transform.
    virtual void DrawTransform(const b2Transform& xf) override;

	virtual void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {}
	
private:
    sf::RenderTarget* renderTargetRef;
    b2World* physicsSpaceRef;
};


#endif //RAINSFORD_DEBUGDRAW_HPP
