//
// Created by Ryan on 8/10/2015.
//

#include "Components/Physical.hpp"

b2Body& Physical::getBodyRef() {
    return *b2BodyRef;
}

b2BodyDef Physical::loadLuaBodyDef(sel::Selector &luaData) {
    b2BodyDef bodyDef;

    if(luaData["position"]) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        bodyDef.position = b2Vec2(x, y);
    }
    if(luaData["fixedRotation"]) {
        bodyDef.fixedRotation = luaData["fixedRotation"];
    }
    if(luaData["type"]) {
        if(luaData["type"] == "b2_staticBody") {
            bodyDef.type = b2_staticBody;
        }
        else if(luaData["type"] == "b2_kinematicBody") {
            bodyDef.type = b2_kinematicBody;
        }
        else if(luaData["type"] == "b2_dynamicBody") {
            bodyDef.type = b2_dynamicBody;
        }
    }

    return bodyDef;
}

void Physical::createLuaFixture(sel::Selector &luaData) {
    b2FixtureDef fixtureDef;
    b2PolygonShape polygonShape;

    if(luaData["density"] == true) {
        fixtureDef.density = (float)double(luaData["density"]);
    }
    if(luaData["friction"] == true) {
        fixtureDef.friction = (float)double(luaData["friction"]);
    }
    if(luaData["restitution"] == true) {
        fixtureDef.restitution = (float)double(luaData["restitution"]);
    }
    if(luaData["isSensor"] == true) {
        fixtureDef.isSensor = luaData["isSensor"];
    }
    if(luaData["b2PolygonShape"] == true) {
        sel::Selector polySelector = luaData["b2PolygonShape"];
        if(polySelector["setAsBox"]) {
            float hx = (float)double(polySelector["setAsBox"][1]);
            float hy = (float)double(polySelector["setAsBox"][2]);
            polygonShape.SetAsBox(hx, hy);
        }
        else if(polySelector["vertices"] == true) {
            sel::Selector vertSelector = polySelector["vertices"];
            std::vector<b2Vec2> vertices;
            int count = 1;
            while(vertSelector[count] == true) {
                b2Vec2 vert;
                vert.x = (float)double(vertSelector[count][1]);
                vert.y = (float)double(vertSelector[count][2]);
                vertices.push_back(vert);
                count++;
            }
            polygonShape.Set(vertices.data(), vertices.size());
        }
        if(polySelector["offset"]) {
            float x = (float)double(polySelector["offset"][1]);
            float y = (float)double(polySelector["offset"][2]);
            polygonShape.m_centroid = b2Vec2(x, y);
        }
        fixtureDef.shape = &polygonShape;
    }
    b2Fixture* fix = b2BodyRef->CreateFixture(&fixtureDef);

}
