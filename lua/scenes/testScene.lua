--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/3/2016
-- Time: 6:47 AM
--
--


Camera = {
    size = {64, 36 },
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
local Box = require("Box")
local StaticBox = require("StaticBox")

entities = {
    Player.new({20, 54}),
    Wolf.new({75, 54}),
    Image.new("refrence.png", {-23, 20}),
    Box.new({5, 50}),
    Box.new({6, 48}),
    StaticBox.new({20, 57}, {100, 1}),
    StaticBox.new({58.4, 44}, {5, 13}),
    StaticBox.new({49.6, 51.3}, {8, .8})
}

