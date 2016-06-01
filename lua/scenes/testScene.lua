--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/3/2016
-- Time: 6:47 AM
--
--


Camera = {
    size = {32, 18},
    center = {10.0, 50.0 },
    target = "player"
}

b2World = {
    gravity = {0.0, 20.0 }
}

package.path = package.path .. ';../lua/entities/?.lua;'

local Player = require("Player")
local Wolf = require("Wolf")
local Image = require("Image")
local Box = require("Box")
local StaticBox = require("StaticBox")
local StaticPolygon = require("StaticPolygon")

entities = {
    player = Player.new(),
    background = Image.new("testLevel.png", 1, -50),

    collider1 = StaticBox.new({8, 1}),
    collider2 = StaticBox.new({4, 1}),
    collider3 = StaticBox.new({4, 1}),
    collider4 = StaticBox.new({1, 30}),
    collider5 = StaticBox.new({1, 15}),
    collider6 = StaticBox.new({4, .45}),
    collider7 = StaticBox.new({6, .45}),
    collider8 = StaticBox.new({1, 1}),
    collider9 = StaticBox.new({8, 1}),
    collider10 = StaticBox.new({8, 1}),
    collider11 = StaticBox.new({1, 3.45}),
    collider12 = StaticBox.new({6.5, 1.4}),
    collider13 = StaticBox.new({1, 3}),
    collider14 = StaticBox.new({1, 10}),
    collider15 = StaticBox.new({1, 15}),
    collider16 = StaticBox.new({.8, .4}),
    collider17 = StaticBox.new({2, .4}),
    collider18 = StaticBox.new({2.7, .4}),

    trinagle = StaticPolygon.new({{7.3, 47.4}, {10.9, 45.4}, {10.9, 47.4}}),
    trinagle2 = StaticPolygon.new({{0, 0}, {12, -6}, {4, 0}}),

    dynamicBox1 = Box.new(),
    dynamicBox2 = Box.new(),
    dynamicBox3 = Box.new(),
    dynamicBox4 = Box.new()
}

dofile("../lua/Scenes/testSceneEditorConfig.lua")

