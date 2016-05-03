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
    if(luaData["b2PolygonShape"]) {
        sel::Selector polySelector = luaData["b2PolygonShape"];

        if(polySelector["setAsBox"]) {
            if(polySelector["setAsBox"][3] == false) {
                float hx = (float)double(polySelector["setAsBox"][1]);
                float hy = (float)double(polySelector["setAsBox"][2]);
                polygonShape.SetAsBox(hx, hy);
            }
            else {

            }
        }
        fixtureDef.shape = &polygonShape;
    }
    b2BodyRef->CreateFixture(&fixtureDef);
}
