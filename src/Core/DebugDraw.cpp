//
// Created by Ryan on 5/2/2016.
//

#include "Core/DebugDraw.hpp"
#include <iostream>

void DebugDraw::setRenderTarget(sf::RenderTarget& renderTarget) {
    renderTargetRef = &renderTarget;
}

void DebugDraw::setAsTargetOf(b2World& physicsSpace) {
    physicsSpaceRef = &physicsSpace;
    physicsSpaceRef->SetDebugDraw(this);
    SetFlags((b2Draw::e_shapeBit));
}

void DebugDraw::drawDebug() {
    if(physicsSpaceRef != NULL && renderTargetRef != NULL) {
        physicsSpaceRef->DrawDebugData();
    }
}

sf::Vector2f DebugDraw::B2VecToSFVec(const b2Vec2 &vector)
{
    return sf::Vector2f(vector.x, vector.y);
}

void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    sf::ConvexShape polygon(vertexCount);
    sf::Vector2f center;
    for(int i = 0; i < vertexCount; i++)
    {
        polygon.setPoint(i, B2VecToSFVec(vertices[i]));
    }
    polygon.setOutlineThickness(-0.1f);
    polygon.setFillColor(sf::Color::Transparent);
    polygon.setOutlineColor(DebugDraw::GLColorToSFML(color));

    renderTargetRef->draw(polygon);
}
void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
    sf::ConvexShape polygon(vertexCount);
    for(int i = 0; i < vertexCount; i++)
    {
        polygon.setPoint(i, B2VecToSFVec(vertices[i]));
    }
    polygon.setOutlineThickness(-0.1f);
    polygon.setFillColor(DebugDraw::GLColorToSFML(color, 60));
    polygon.setOutlineColor(DebugDraw::GLColorToSFML(color));

    renderTargetRef->draw(polygon);
}
void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(DebugDraw::B2VecToSFVec(center));
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(-0.1f);
    circle.setOutlineColor(DebugDraw::GLColorToSFML(color));

    renderTargetRef->draw(circle);
}
void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(DebugDraw::B2VecToSFVec(center));
    circle.setFillColor(DebugDraw::GLColorToSFML(color, 60));
    circle.setOutlineThickness(-0.1f);
    circle.setOutlineColor(DebugDraw::GLColorToSFML(color));

    b2Vec2 endPoint = center + radius * axis;
    sf::Vertex line[2] =
            {
                    sf::Vertex(DebugDraw::B2VecToSFVec(center), DebugDraw::GLColorToSFML(color)),
                    sf::Vertex(DebugDraw::B2VecToSFVec(endPoint), DebugDraw::GLColorToSFML(color)),
            };

    renderTargetRef->draw(circle);
    renderTargetRef->draw(line, 2, sf::Lines);
}
void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
    sf::Vertex line[] =
            {
                    sf::Vertex(DebugDraw::B2VecToSFVec(p1), DebugDraw::GLColorToSFML(color)),
                    sf::Vertex(DebugDraw::B2VecToSFVec(p2), DebugDraw::GLColorToSFML(color))
            };

    renderTargetRef->draw(line, 2, sf::Lines);
}
void DebugDraw::DrawTransform(const b2Transform& xf)
{
    float lineLength = 0.4;

    /*b2Vec2 xAxis(b2Vec2(xf.p.x + (lineLength * xf.q.c), xf.p.y + (lineLength * xf.q.s)));*/
    b2Vec2 xAxis = xf.p + lineLength * xf.q.GetXAxis();
    sf::Vertex redLine[] =
            {
                    sf::Vertex(DebugDraw::B2VecToSFVec(xf.p), sf::Color::Red),
                    sf::Vertex(DebugDraw::B2VecToSFVec(xAxis), sf::Color::Red)
            };

    // You might notice that the ordinate(Y axis) points downward unlike the one in Box2D testbed
    // That's because the ordinate in SFML coordinate system points downward while the OpenGL(testbed) points upward
    /*b2Vec2 yAxis(b2Vec2(xf.p.x + (lineLength * -xf.q.s), xf.p.y + (lineLength * xf.q.c)));*/
    b2Vec2 yAxis = xf.p + lineLength * xf.q.GetYAxis();
    sf::Vertex greenLine[] =
            {
                    sf::Vertex(DebugDraw::B2VecToSFVec(xf.p), sf::Color::Green),
                    sf::Vertex(DebugDraw::B2VecToSFVec(yAxis), sf::Color::Green)
            };

    renderTargetRef->draw(redLine, 2, sf::Lines);
    renderTargetRef->draw(greenLine, 2, sf::Lines);
}