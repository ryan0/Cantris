//
// Created by Ryan on 5/26/2016.
//

//
// Created by Ryan on 8/6/2015.
//

#include "Engine/LuaSceneLoader.hpp"
#include "Components/Spatial.hpp"
#include "Components/Physical.hpp"
#include "Engine/SceneEditor.hpp"

#include <iostream>
#include <fstream>

void SceneEditor::update(double timeStep) {
    graphicsSystem.update(timeStep, scene->getEntities());

    Entity* entityRef = scene->getEntity(entitySelector.getCurrentSelection());
    if(entityRef->hasComponent<Spatial>()) {
        Spatial* spatial = entityRef->getComponent<Spatial>();
        selectedIndicator.setPosition(spatial->getPosition());
    }
    else if(entityRef->hasComponent<Physical>()) {
        Physical* physical = entityRef->getComponent<Physical>();
        selectedIndicator.setPosition(physical->getBodyRef().GetLocalCenter().x, physical->getBodyRef().GetLocalCenter().y);
    }
}

void SceneEditor::render(double alpha, sf::RenderTarget &renderTarget) {
    gameWindowRef->makeLetterBox(scene->getCamera());
    scene->getCamera().updatePosition(alpha);
    renderTarget.setView(scene->getCamera());
    graphicsSystem.render(alpha, renderTarget, scene->getSceneGraph());
    graphicsSystem.renderDebug();
    renderTarget.draw(selectedIndicator);


    sf::View guiView(sf::FloatRect(0, 0, gameWindowRef->getSize().x, gameWindowRef->getSize().y));
    renderTarget.setView(guiView);
    renderTarget.draw(entitySelector);
}

void SceneEditor::handleEvents(sf::Event &event) {
    static bool mouseLeftPressed = false;
    static bool mouseRightPressed = false;
    static sf::Vector2i previousMousePosition;

    if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Button::Left) {
            mouseLeftPressed = true;
            previousMousePosition = sf::Mouse::getPosition();
        }
        else if(event.mouseButton.button == sf::Mouse::Button::Right) {
            mouseRightPressed = true;
            previousMousePosition = sf::Mouse::getPosition();
        }
    }
    else if(event.type == sf::Event::MouseButtonReleased) {
        mouseLeftPressed = false;
        mouseRightPressed = false;
    }
    else if(event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePosition= sf::Mouse::getPosition();
        if(mouseRightPressed) {
            mouseDragDelta.x -= float(mousePosition.x - previousMousePosition.x) * cameraSpeed;
            mouseDragDelta.y -= float(mousePosition.y - previousMousePosition.y) * cameraSpeed;
            scene->getCamera().offset.x = mouseDragDelta.x;
            scene->getCamera().offset.y = mouseDragDelta.y;
        }
        else if(mouseLeftPressed) {
            Entity* entityRef = scene->getEntity(entitySelector.getCurrentSelection());
            if(entityRef->hasComponent<Spatial>()) {
                Spatial* spatial = entityRef->getComponent<Spatial>();
                spatial->move(
                        float(mousePosition.x - previousMousePosition.x) * cameraSpeed,
                        float(mousePosition.y - previousMousePosition.y) * cameraSpeed
                );
            }
            if(entityRef->hasComponent<Physical>()) {
                Physical* physical = entityRef->getComponent<Physical>();
                b2Vec2 newPosition = b2Vec2(
                        physical->getBodyRef().GetPosition().x + float(mousePosition.x - previousMousePosition.x) * cameraSpeed,
                        physical->getBodyRef().GetPosition().y + float(mousePosition.y - previousMousePosition.y) * cameraSpeed
                );
                physical->getBodyRef().SetTransform(newPosition, physical->getBodyRef().GetAngle());
            }
        }
        previousMousePosition = mousePosition;
    }
    else if(event.type == sf::Event::MouseWheelMoved) {
        if(event.mouseWheel.delta > 0) {
            scene->getCamera().zoom(.9f);
            cameraSpeed *= .9f;
        }
        else {
            scene->getCamera().zoom(1.1f);
            cameraSpeed *= 1.1f;
        }
    }
    else if(event.type == sf::Event::KeyPressed) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            saveSceneData();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            gameWindowRef->setState(windowState_ptr(new SceneEditor()));
        }
        else if(event.key.code == sf::Keyboard::W) {
            entitySelector.selectedUp();
        }
        else if(event.key.code == sf::Keyboard::S) {
            entitySelector.selectedDown();
        }
    }
}

void SceneEditor::initialize(GameWindow &gameWindow, AssetManager &assetManager) {
    static int count = 0;
    std::cout<<"Reloads"<< count<<std::endl;
    count++;

    gameWindowRef = &gameWindow;
    assetManagerRef = &assetManager;
    LuaSceneLoader sceneLoader(assetManager);
    scene = (sceneLoader.loadScene("testScene.lua"));
    scene->getCamera().stopFollow();
    graphicsSystem.setDebugDraw(gameWindow, scene->getPhysicsSpace());

    std::vector<std::string> entitieNames;
    auto& entityList = scene->getEntities();
    for(auto& e : entityList) {
        entitieNames.push_back(e->getId());
    }
    entitySelector.setStringList(entitieNames);
    openSans.loadFromFile("../assets/fonts/OpenSans-Regular.ttf");
    entitySelector.setFont(openSans);

    selectedIndicator = sf::CircleShape(.1f);
}

void SceneEditor::cleanup() {

}

void SceneEditor::saveSceneData() {
    std::cout<< "Saved Scene Data" <<std::endl;
    auto& entityList = scene->getEntities();

    std::ofstream editorFile;
    editorFile.open("../lua/scenes/testSceneEditorConfig.lua");
    for (auto& e : entityList) {
        if(e->hasComponent<Spatial>()) {
            Spatial* spatial = e->getComponent<Spatial>();
            float x = spatial->getPosition().x;
            float y = spatial->getPosition().y;

            editorFile<<"entities[\""<<e->getId()<<"\"].Spatial.position = {"<<x<<", "<<y<<"}\n";
        }
        if(e->hasComponent<Physical>()) {
            Physical* physical = e->getComponent<Physical>();
            float x = physical->getBodyRef().GetPosition().x;
            float y = physical->getBodyRef().GetPosition().y;
            editorFile<<"entities[\""<<e->getId()<<"\"].Physical.b2BodyDef.position = {"<<x<<", "<<y<<"}\n";
        }
    }
    editorFile.close();
}
