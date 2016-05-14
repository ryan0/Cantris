--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/3/2016
-- Time: 6:47 AM
--
--


Camera = {
    --64 36
    size = {64, 36},
    center = {10.0, 38.0 },
    target = "Player"
}

b2World = {
    gravity = {0.0, 20.0 }
}

package.path = package.path .. ';../lua/entities/?.lua;'

local Player = require("Player")
local Wolf = require("Wolf")
local Image = require("Image")
local ScrollingImage = require("ScrollingImage")
local Box = require("Box")
local StaticBox = require("StaticBox")
local Portal = require("Portal")

entities = {
    Player.new({40, 54}),
    Wolf.new({150, 54}),
    ScrollingImage.new("1", "sky.png", {5, 13}, .12, -5),
    ScrollingImage.new(".9", "mountains.png", {-35, 21}, .1, -4),
    ScrollingImage.new(".8", "background.png", {-35, 21}, .1, -3),
    Image.new("near.png", {-60, 20}, .1, -2),
    Image.new("foreground.png", {-60, 20}, .1, 2),
    Portal.new("Portal1", "Portal2", {63, 51.8}),
    Portal.new("Portal2", "Portal1", {98, 51.8}),
    Box.new({25, 50}),
    Box.new({26, 48}),
    StaticBox.new({100, 57}, {150, 1}),
    StaticBox.new({7, 50}, {1, 30}),
    StaticBox.new({83, 48}, {14, 10})
}

