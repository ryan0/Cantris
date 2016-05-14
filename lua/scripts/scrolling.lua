--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/9/2016
-- Time: 7:06 PM
-- To change this template use File | Settings | File Templates.
--

local scrolling = {}
scrolling.__index = scrolling


function scrolling.new(scrollRate)
    local self = setmetatable({}, scrolling)
    self.rate = tonumber(scrollRate)
    self.playerRef = 0
    self.startPosition = 0
    self.playerStartPosition = 0
    return self
end

function scrolling:start(entity, scene)
    print("scrolling.lua Started")
    self.playerRef = getEntityById(scene, "Player")
    self.playerStartPosition = getPosition(self.playerRef):x()
    self.startPosition = getPosition(entity):x()
end

function scrolling:update(tpf, entity, scene)
    local playerPos = getPosition(self.playerRef):x()
    local position = Vector:new()
    position:set_y(getPosition(entity):y())
    position:set_x(self.startPosition - (self.rate * (self.playerStartPosition - playerPos)))
    setPosition(entity, position)
end

function scrolling:finish(entity)

end

return scrolling